package br.eti.fml.android.sigame.services;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.*;
import android.location.Location;
import android.location.LocationListener;
import android.location.LocationManager;
import android.os.*;
import br.eti.fml.android.sigame.R;
import br.eti.fml.android.sigame.bean.SharedInfo;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.ui.activities.MainActivity;
import br.eti.fml.android.sigame.util.Log;
import com.google.gson.Gson;

public class UpdatingPositionService extends Service {

    public static final int MIN_INTERVAL = 100;
    public static final int MAX_INTERVAL = 1000;

    private static final int TIME_TO_OLD = 1000 * 2 * 60; // 2 min

    private AsyncTask mainTask;
    private String session;
    private Float battery = 1f;
    private Integer temperature = 0;
    private Float lat, lon, accur;
    private String lastProvider = "?";
    private LocationListener locationListenerGps;
    private LocationListener locationListenerNetwork;
    private Location currentBestLocation;

    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    // This is the old onStart method that will be called on the pre-2.0
    // platform.  On 2.0 or later we override onStartCommand() so this
    // method will not be called.
    @Override
    public void onStart(Intent intent, int startId) {
        handleCommand();
    }

    @Override
    public void onDestroy() {
        ((NotificationManager) getSystemService(
                Context.NOTIFICATION_SERVICE)).cancel(MainActivity.NOTIFICATION_FOLLOW_ID);

        stopGettingLocation(); // just to ensure
        Log.debug(this, "Service destroyed!");

        super.onDestroy();
    }

    @Override
    public int onStartCommand(Intent intent, int flags, int startId) {
        handleCommand();
        // We want this service to continue running until it is explicitly
        // stopped, so return sticky.
        return START_STICKY;
    }

    private void handleCommand() {
        Log.debug(this, "Updating position service running...");

        SharedPreferences settings = getSharedPreferences(MainActivity.PACKAGE, 0);
        final Long updateSoFar = settings.getLong("updateSoFar", System.currentTimeMillis());
        session = settings.getString("updateSession", "");

        registerBattery();
        registerLocation();
        showNotificationWhenFollowed();

        if (session == null || "".equals(session)) {
            Log.error(this, "session is null!");
            System.exit(56);
        } else {
            //noinspection unchecked
            mainTask = new AsyncTask() {
                @Override
                protected Object doInBackground(Object... objects) {
                    SharedInfo sharedInfo = null;
                    String key = getKey(session);
                    Gson gson = new Gson();

                    PowerManager pm = (PowerManager) getSystemService(Context.POWER_SERVICE);
                    PowerManager.WakeLock wl = pm.newWakeLock(PowerManager.PARTIAL_WAKE_LOCK, "SIGAME Service");

                    try {
                        wl.acquire();

                        while (!isCancelled()) {
                            try {
                                SharedInfo newSharedInfo = new SharedInfo();

                                newSharedInfo.setLast_update(System.currentTimeMillis());
                                newSharedInfo.setLat(lat);
                                newSharedInfo.setLon(lon);
                                newSharedInfo.setLast_provider(lastProvider);
                                newSharedInfo.setAccur(accur);
                                newSharedInfo.setBattery(battery);
                                newSharedInfo.setTemperature(temperature);

                                long sleepTime;

                                if (newSharedInfo.almostEqual(sharedInfo)) {
                                    Log.debug(this, "newSharedInfo=" + newSharedInfo
                                            + " is almost the same of newSharedInfo=" + sharedInfo);

                                    sleepTime = MAX_INTERVAL;
                                } else {
                                    sharedInfo = newSharedInfo;

                                    long startTime = System.currentTimeMillis();

                                    if (!isCancelled()) {
                                        Storage.put(key, gson.toJson(sharedInfo));
                                        Log.debug(this, "Updated position: " + sharedInfo);
                                    }

                                    sleepTime = Math.max(MIN_INTERVAL, MAX_INTERVAL - (System.currentTimeMillis() - startTime));
                                }

                                Thread.sleep(sleepTime);
                                Log.debug(this, "Sleeping for " + sleepTime + " ms...");
                            } catch (InterruptedException e) {
                                Log.debug(this, "" + e);
                            }

                            if (System.currentTimeMillis() > updateSoFar
                                || "true".equals(Storage.get(MainActivity.PACKAGE + "." + session + ".need_stop"))) {

                                stopToBeFollowed(session);
                            }
                        }
                    } finally {
                        wl.release();
                    }

                    return null;
                }
            }.execute();
        }
    }

    private void stopGettingLocation() {
        Log.debug(this, "Stopping to get location...");

        if (mainTask != null && !mainTask.isCancelled()) {
            mainTask.cancel(true);
        }

        LocationManager locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);

        if (locationListenerNetwork != null) {
            locationManager.removeUpdates(locationListenerNetwork);
            locationListenerNetwork = null;
        }

        if (locationListenerGps != null) {
            locationManager.removeUpdates(locationListenerGps);
            locationListenerGps = null;
        }
    }

    private void registerLocation() {
        Log.debug(this, "Start to get location...");

        // Acquire a reference to the system Location Manager
        LocationManager locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);

        if (lat == null || lon == null) {
            Location lastKnownLocation = locationManager.getLastKnownLocation(LocationManager.NETWORK_PROVIDER);
            makeUseOfNewLocation(lastKnownLocation);
        }

        // Define a listener that responds to location updates
        locationListenerNetwork = new LocationListener() {
            public void onLocationChanged(Location location) {
                // Called when a new location is found by the network location provider.
                makeUseOfNewLocation(location);
            }

            public void onStatusChanged(String provider, int status, Bundle extras) {}
            public void onProviderEnabled(String provider) {}
            public void onProviderDisabled(String provider) {}
        };

        locationListenerGps = new LocationListener() {
            public void onLocationChanged(Location location) {
                // Called when a new location is found by the network location provider.
                makeUseOfNewLocation(location);
            }

            public void onStatusChanged(String provider, int status, Bundle extras) {}
            public void onProviderEnabled(String provider) {}
            public void onProviderDisabled(String provider) {}
        };

        // Register the listener with the Location Manager to receive location updates
        locationManager.requestLocationUpdates(LocationManager.NETWORK_PROVIDER, 0, 0, locationListenerNetwork);
        locationManager.requestLocationUpdates(LocationManager.GPS_PROVIDER, 0, 0, locationListenerGps);
    }

    /** Determines whether one Location reading is better than the current Location fix
     * @param newLocation  The new Location that you want to evaluate
     * @param currentBestLocation  The current Location fix, to which you want to compare the new one
     * @return if the new is better
     */
    protected boolean isBetterLocation(Location newLocation, Location currentBestLocation) {
        if (currentBestLocation == null) {
            // A new location is always better than no location
            return true;
        }

        // Check whether the new location fix is newer or older
        long timeDelta = newLocation.getTime() - currentBestLocation.getTime();
        boolean isSignificantlyNewer = timeDelta > TIME_TO_OLD;
        boolean isSignificantlyOlder = timeDelta < -TIME_TO_OLD;
        boolean isNewer = timeDelta > 0;

        // If it's been more than two minutes since the current location, use the new location
        // because the user has likely moved
        if (isSignificantlyNewer) {
            return true;
            // If the new location is more than two minutes older, it must be worse
        } else if (isSignificantlyOlder) {
            return false;
        }

        // Check whether the new location fix is more or less accurate
        int accuracyDelta = (int) (newLocation.getAccuracy() - currentBestLocation.getAccuracy());
        boolean isLessAccurate = accuracyDelta > 0;
        boolean isMoreAccurate = accuracyDelta < 0;
        boolean isSignificantlyLessAccurate = accuracyDelta > 200;

        // Check if the old and new location are from the same provider
        boolean isFromSameProvider = isSameProvider(newLocation.getProvider(),
                currentBestLocation.getProvider());

        // Determine location quality using a combination of timeliness and accuracy
        if (isMoreAccurate) {
            return true;
        } else if (isNewer && !isLessAccurate) {
            return true;
        } else if (isNewer && !isSignificantlyLessAccurate && isFromSameProvider) {
            return true;
        }
        return false;
    }

    /** Checks whether two providers are the same
     * @param provider1 provider1
     * @param provider2 provider2
     * @return if is the same
     */
    private boolean isSameProvider(String provider1, String provider2) {
        if (provider1 == null) {
            return provider2 == null;
        }

        return provider1.equals(provider2);
    }

    private void makeUseOfNewLocation(Location location) {
        if (isBetterLocation(location, currentBestLocation)) {
            currentBestLocation = location;
            Log.debug(this, "New best location: " + currentBestLocation);
        }

        lastProvider = currentBestLocation.getProvider();
        lat = (float) currentBestLocation.getLatitude();
        lon = (float) currentBestLocation.getLongitude();
        accur = currentBestLocation.getAccuracy();
    }

    private void registerBattery() {
        BroadcastReceiver batteryLevelReceiver = new BroadcastReceiver() {
            public void onReceive(Context context, Intent intent) {
                context.unregisterReceiver(this);
                int rawlevel = intent.getIntExtra("level", 0);
                int scale = intent.getIntExtra("scale", 1);
                int level = 0;
                if (rawlevel >= 0 && scale > 0) {
                    level = (rawlevel * 100) / scale;
                }

                battery = level / 100f;

                if (Integer.valueOf(android.os.Build.VERSION.SDK) >= 5) {
                    temperature = intent.getIntExtra(BatteryManager.EXTRA_TEMPERATURE, 0);
                }
            }
        };

        IntentFilter batteryLevelFilter = new IntentFilter(Intent.ACTION_BATTERY_CHANGED);
        registerReceiver(batteryLevelReceiver, batteryLevelFilter);
    }

    public static String getKey(String session) {
        return MainActivity.PACKAGE + "." + session + ".shared_info";
    }

    private void stopToBeFollowed(final String session) {
        Log.debug(this, "Stopping updating service...");

        Log.debug(this, "Before getting location");
        stopGettingLocation();

        Log.debug(this, "Before show notification");
        showNotificationWhenStopToBeFollowed();

        //noinspection unchecked
        new AsyncTask() {
            @Override
            protected Object doInBackground(Object... objects) {
                Storage.delete(getKey(session));
                Storage.delete(MainActivity.PACKAGE + "." + session + ".need_stop");
                return null;
            }

            @Override
            protected void onPostExecute(Object o) {
                stopSelf();
                Log.debug(this, "Stopped updating service!");
            }
        }.execute();
    }

    private void showNotificationWhenStopToBeFollowed() {
        NotificationManager notificationManager
                = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

        notificationManager.cancel(MainActivity.NOTIFICATION_FOLLOW_ID);

        Notification notification = new Notification(
                R.drawable.stop, getString(R.string.you_are_not_being_followed_anymore), System.currentTimeMillis());

        notification.flags |= Notification.FLAG_AUTO_CANCEL;
        notification.defaults |= Notification.DEFAULT_VIBRATE;

        PendingIntent arrivedPI = PendingIntent.getActivity(this, 0, null, PendingIntent.FLAG_ONE_SHOT);
        notification.setLatestEventInfo(this, getString(R.string.title_you_are_not_being_followed_anymore),
                getString(R.string.body_you_are_not_being_followed_anymore), arrivedPI);

        notificationManager.notify(MainActivity.NOTIFICATION_STOP_ID, notification);
    }

    private void showNotificationWhenFollowed() {
        NotificationManager notificationManager
                = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

        notificationManager.cancel(MainActivity.NOTIFICATION_STOP_ID);

        Notification notification = new Notification(
                R.drawable.followed, getString(R.string.you_are_being_followed), System.currentTimeMillis());

        notification.flags |= Notification.FLAG_AUTO_CANCEL;
        notification.flags |= Notification.FLAG_ONGOING_EVENT;
        notification.defaults |= Notification.DEFAULT_VIBRATE;

        Intent intent = new Intent(MainActivity.PACKAGE + ".ARRIVED");
        intent.putExtra("session", session);
        PendingIntent arrivedPI = PendingIntent.getBroadcast(this, 0, intent, 0);

        notification.setLatestEventInfo(this, getString(R.string.title_arrived_notification),
                getString(R.string.body_arrived_notification), arrivedPI);

        notificationManager.notify(MainActivity.NOTIFICATION_FOLLOW_ID, notification);
    }
}

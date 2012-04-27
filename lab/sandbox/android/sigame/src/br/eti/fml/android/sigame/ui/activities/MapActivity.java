package br.eti.fml.android.sigame.ui.activities;

import android.content.Context;
import android.content.DialogInterface;
import android.content.SharedPreferences;
import android.location.Location;
import android.location.LocationManager;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import android.widget.Toast;
import br.eti.fml.android.sigame.R;
import br.eti.fml.android.sigame.bean.SharedInfo;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.ui.UiHelper;
import br.eti.fml.android.sigame.util.Log;
import com.google.android.maps.GeoPoint;
import com.google.android.maps.MapView;
import com.google.android.maps.OverlayItem;
import com.google.gson.Gson;
import com.google.gson.JsonParseException;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;
import java.util.concurrent.atomic.AtomicReference;

public class MapActivity extends com.google.android.maps.MapActivity {
    public static final float BATTERY = .3f;
    public static final int START_ZOOM = 17;
    public static final SimpleDateFormat simpleDateFormat = new SimpleDateFormat("HH'h'mm''ss");

    private AsyncTask gettingInfoInThread;
    private AsyncTask updateScreenInThread;

    private String lastSession;
    private int minutes;
    private long startTime;
    private SharedInfo lastSharedInfo;
    private AtomicBoolean needToUpdateScreen;
    private AtomicBoolean noAnswer;
    private AtomicBoolean running;
    private AtomicInteger notFoundMessageLevel;
    private AtomicInteger batteryMessageLevel;
    private OverlayItem theOtherGuy;
    private OverlayItem myPosition;

    private MapOverlaySet theOtherGuyOverlaySet;
    private MapOverlaySet myPositionOverlaySet;

    enum Reason {
        TIME_IS_UP,
        USER_BACK,
        ARRIVED,
        NOT_FOUND,
        USER_BUTTON
    }

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        
        startTime = System.currentTimeMillis();
        batteryMessageLevel = new AtomicInteger(0);
        notFoundMessageLevel = new AtomicInteger(0);
        needToUpdateScreen = new AtomicBoolean(false);
        noAnswer = new AtomicBoolean(true);
        running = new AtomicBoolean(true);

        setContentView(R.layout.map);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        final Button buttonMyPosition = (Button) findViewById(R.id.my_position);

        SharedPreferences settings = getSharedPreferences(MainActivity.PACKAGE, 0);
        lastSession = settings.getString("lastSession", "");
        minutes = settings.getInt("minutes", 0);

        if (lastSession == null || "".equals(lastSession)) {
            Log.error(this, "lastSession cannot be empty here!");
            finish();
        }

        final MapView mapView = (MapView) findViewById(R.id.mapview);

        theOtherGuyOverlaySet = new MapOverlaySet(
                this.getResources().getDrawable(R.drawable.marker), MapOverlaySet.Position.CENTER_BOTTOM);

        myPositionOverlaySet = new MapOverlaySet(
                this.getResources().getDrawable(R.drawable.me), MapOverlaySet.Position.CENTER);

        mapView.getOverlays().add(myPositionOverlaySet);
        mapView.getOverlays().add(theOtherGuyOverlaySet);
        mapView.setBuiltInZoomControls(true);
        mapView.setSatellite(false);

        defineMainButtonBehavior(true);

        buttonMyPosition.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                goToUserPosition(mapView);
            }
        });

        final TextView lastUpdate = (TextView) findViewById(R.id.last_update);
        final TextView battery = (TextView) findViewById(R.id.battery);
        final TextView provider = (TextView) findViewById(R.id.provider);
        
        final UiHelper uiHelper = new UiHelper(this);
        goToUserPosition(mapView);

        //noinspection unchecked
        updateScreenInThread = new AsyncTask() {
            @Override
            protected Object doInBackground(Object... objects) {
                final AtomicReference<GeoPoint> lastPoint = new AtomicReference<GeoPoint>();

                while (!isCancelled()) {
                    Log.debug(this, "Starting loop of update screen...");
                    final SharedInfo sharedInfo = lastSharedInfo;
                    
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            if (mapView.getZoomLevel() > START_ZOOM) {
                                mapView.setSatellite(true);
                            } else {
                                mapView.setSatellite(false);
                            }
                            
                            String batteryField = getString(R.string.battery) + " ?";

                            if (sharedInfo != null) {
                                if (needToUpdateScreen.compareAndSet(true, false)) {

                                    // Updating point:
                                    if (sharedInfo.getLat() != null && sharedInfo.getLon() != null) {
                                        GeoPoint point = new GeoPoint(
                                                (int) (sharedInfo.getLat().doubleValue() * 1000000),
                                                (int) (sharedInfo.getLon().doubleValue() * 1000000));

                                        if (lastPoint.get() != null) {
                                            LineMapOverlay lineMapOverlay = new LineMapOverlay(lastPoint.get(), point);
                                            mapView.getOverlays().add(0, lineMapOverlay);
                                        }

                                        lastPoint.set(point);
    
                                        if (theOtherGuy != null) {
                                            theOtherGuyOverlaySet.removeOverlay(theOtherGuy);
                                        }
    
                                        theOtherGuy = new OverlayItem(point, "", "");
                                        theOtherGuyOverlaySet.addOverlay(theOtherGuy);
                                        mapView.getController().animateTo(point);
                                    }

                                    // Updating last update:
                                    if (sharedInfo.getLast_update() != null) {

                                        lastUpdate.setText(getString(R.string.last_update)
                                                + " " + simpleDateFormat.format(
                                                new Date(sharedInfo.getLast_update())));
                                    }

                                    // Updating provider and accuracy:
                                    float accur = sharedInfo.getAccur() == null ? 0f : sharedInfo.getAccur();

                                    if (sharedInfo.getLast_provider() != null) {
                                        provider.setText(getString(R.string.accuracy)
                                                + " " + Math.round(accur) + " m - "
                                                + sharedInfo.getLast_provider());
                                    }
                                }

                                if (sharedInfo.getBattery() != null) {
                                    batteryField = getString(R.string.battery) + " "
                                            + Math.round(sharedInfo.getBattery() * 100f) + "% "
                                            + (sharedInfo.getTemperature() / 10f) + " ºC";

                                    if (sharedInfo.getBattery() < BATTERY
                                            && batteryMessageLevel.get() <= 1) {

                                        uiHelper.showToast(getString(R.string.low_battery), Toast.LENGTH_LONG);
                                        batteryMessageLevel.incrementAndGet();
                                    }
                                }

                                // verify if has been arrived
                                if (getTimeLeftInSeconds() == 0 || Boolean.TRUE.equals(sharedInfo.getArrived())) {
                                    Log.debug(this, "Stop follow due to timeout or arrived!");
                                    stopFollow(Boolean.TRUE.equals(sharedInfo.getArrived())
                                            ? Reason.ARRIVED : Reason.TIME_IS_UP);
                                }
                            }

                            // append time left on battery field
                            batteryField += " - "
                                    + getString(R.string.time_left)
                                    + " " + getTimeLeftInSeconds() + "s";

                            battery.setText(batteryField);
                        }
                    });
                    
                    try {
                        Thread.sleep(1000);
                    } catch (InterruptedException e) {
                        // ignores
                    }
                }
                
                return null;
            }
        }.execute();

        //noinspection unchecked
        gettingInfoInThread = new AsyncTask() {
            @Override
            protected Object doInBackground(Object... objects) {
                noAnswer.set(true);

                while (!isCancelled()) {
                    Log.debug(this, "Starting loop of update geolocation...");
                    
                    try {
                        long startTime = System.currentTimeMillis();
                        Gson gson = new Gson();
                        String key = MainActivity.PACKAGE + "." + lastSession + ".shared_info";
                        String json = Storage.get(key);

                        if (json == null) {
                            Log.debug(this, "json of key " + key + " is null yet!");
                        } else {
                            noAnswer.set(false);
                            SharedInfo newSharedInfo = gson.fromJson(json, SharedInfo.class);
                            
                            if (lastSharedInfo == null || newSharedInfo.getLast_update() > lastSharedInfo.getLast_update()) {
                                lastSharedInfo = newSharedInfo;
                                needToUpdateScreen.set(true);
                            }
                        }

                        long timeToSleep = Math.max(0, 1000 - (System.currentTimeMillis() - startTime));
                        Log.debug(this, "Sleeping for " + timeToSleep + " ms");
                        Thread.sleep(timeToSleep);

                        checkIfNeedToStopDueToNotFound();

                    } catch (InterruptedException e) {
                        Log.debug(this, "" + e);
                    } catch (JsonParseException e) {
                        Log.error(this, "Invalid Json! " + e, e);

                        try {
                            Thread.sleep(5000);
                        } catch (InterruptedException ee) {
                            // ignores
                        }
                    }
                }

                return null;
            }
        }.execute();
    }

    private void goToUserPosition(MapView mapView) {
        // put the user position:
        LocationManager locationManager = (LocationManager) this.getSystemService(Context.LOCATION_SERVICE);
        Location lastKnownLocation = locationManager.getLastKnownLocation(LocationManager.NETWORK_PROVIDER);
        mapView.getController().setZoom(START_ZOOM);

        if (lastKnownLocation != null) {
            GeoPoint point = new GeoPoint((int) (lastKnownLocation.getLatitude() * 1000000),
                    (int) (lastKnownLocation.getLongitude() * 1000000));

            if (myPosition != null) {
                myPositionOverlaySet.removeOverlay(myPosition);
            }
            
            myPosition = new OverlayItem(point, "", "");
            myPositionOverlaySet.addOverlay(myPosition);
            mapView.getController().animateTo(point);
        }
    }

    private void checkIfNeedToStopDueToNotFound() {
        UiHelper uiHelper = new UiHelper(this);

        if (noAnswer.get()) {
            if ((System.currentTimeMillis() - startTime) > 1000 * 10
                    && notFoundMessageLevel.get() == 0) {

                uiHelper.showToast(getString(R.string.no_answer), Toast.LENGTH_LONG);
                notFoundMessageLevel.incrementAndGet();
            } else if ((System.currentTimeMillis() - startTime) > 1000 * 20
                    && notFoundMessageLevel.get() == 1) {

                uiHelper.showToast(getString(R.string.no_answer_2), Toast.LENGTH_LONG);
                notFoundMessageLevel.incrementAndGet();
            } if ((System.currentTimeMillis() - startTime) > 1000 * 40
                    && notFoundMessageLevel.get() == 2) {

                uiHelper.showToast(getString(R.string.no_answer_3), Toast.LENGTH_LONG);
                notFoundMessageLevel.incrementAndGet();

                Log.debug(this, "Stop follow because the other does not answer!");
                stopFollow(Reason.NOT_FOUND);
            }
        }
    }

    @Override
    protected boolean isRouteDisplayed() {
        return false;
    }

    private int getTimeLeftInSeconds() {
        int secondsElapsed = (int) ((System.currentTimeMillis() - startTime) / 1000);
        int secondsTotal = minutes * 60;
        return Math.max(0, secondsTotal - secondsElapsed);
    }

    private void stopFollow(final Reason reason) {
        if (running.compareAndSet(true, false)) {
            UiHelper uiHelper = new UiHelper(MapActivity.this);
            uiHelper.showToast(getString(R.string.closing), Toast.LENGTH_SHORT);

            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    if (gettingInfoInThread != null) {
                        gettingInfoInThread.cancel(true);
                    }

                    if (updateScreenInThread != null) {
                        updateScreenInThread.cancel(true);
                    }

                    final TextView lastUpdate = (TextView) findViewById(R.id.last_update);
                    lastUpdate.setText(R.string.last_update_stop);
                    defineMainButtonBehavior(false);
                }
            });

            DialogInterface.OnClickListener closeSelf = new DialogInterface.OnClickListener() {
                @Override
                public void onClick(final DialogInterface dialogInterface, int i) {
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            dialogInterface.dismiss();
                        }
                    });
                }
            };

            if (reason.equals(Reason.ARRIVED)) {
                uiHelper.showAlert(getString(R.string.arrived_title),
                        R.drawable.icon32, getString(R.string.arrived_body), closeSelf);
            } else if (reason.equals(Reason.TIME_IS_UP)) {
                uiHelper.showAlert(getString(R.string.finish_title),
                        R.drawable.icon32, getString(R.string.finish_body), closeSelf);
            } else if (reason.equals(Reason.NOT_FOUND)) {
                uiHelper.showAlert(getString(R.string.not_found_title),
                        R.drawable.icon32, getString(R.string.not_found_body), closeSelf);
            }  // ignores the Reason.USER_BACK and Reason.USER_BUTTON

            //noinspection unchecked
            new AsyncTask() {
                @Override
                protected Object doInBackground(Object... objects) {
                    if (!reason.equals(Reason.USER_BUTTON)) {
                        Storage.delete(MainActivity.PACKAGE + "." + lastSession + ".need_stop");
                    } else {
                        if (!Storage.put(MainActivity.PACKAGE + "." + lastSession + ".need_stop", "true")) {
                            Log.error(this, "Unable to stop!");
                        }
                    }

                    Storage.delete(MainActivity.PACKAGE + "." + lastSession + ".shared_info");

                    return null;
                }

            }.execute();
        } else {
            runOnUiThread(new Runnable() {
                @Override
                public void run() {
                    finish();
                }
            });
        }
    }

    private void defineMainButtonBehavior(boolean stopFollow) {
        final Button buttonStopFollow = (Button) findViewById(R.id.stop_follow);

        if (stopFollow) {
            buttonStopFollow.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    stopFollow(Reason.USER_BUTTON);
                }
            });

            buttonStopFollow.setText(getString(R.string.stop_follow));
        } else {
            buttonStopFollow.setOnClickListener(new View.OnClickListener() {
                @Override
                public void onClick(View view) {
                    finish();
                }
            });

            buttonStopFollow.setText(R.string.close_window);
        }
    }

    @Override
    public void onBackPressed() {
        UiHelper uiHelper = new UiHelper(this);

        if (running.get()) {
            uiHelper.showToast(getString(R.string.stop_before), Toast.LENGTH_LONG);
        } else {
            stopFollow(Reason.USER_BACK);
        }
    }
}
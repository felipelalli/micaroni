package br.eti.fml.android.sigame.services;

import android.app.Notification;
import android.app.NotificationManager;
import android.app.PendingIntent;
import android.app.Service;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.IBinder;
import br.eti.fml.android.sigame.R;
import br.eti.fml.android.sigame.bean.SharedInfo;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.ui.activities.MainActivity;
import br.eti.fml.android.sigame.util.Log;
import com.google.gson.Gson;

public class UpdatingPositionService extends Service {

    private AsyncTask mainTask;
    private String session;

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
        if (mainTask != null) {
            mainTask.cancel(true);
        }

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

        showNotificationWhenFollowed();

        if (session == null || "".equals(session)) {
            Log.error(this, "session is null!");
            System.exit(56);
        } else {
            //noinspection unchecked
            mainTask = new AsyncTask() {
                @Override
                protected Object doInBackground(Object... objects) {
                    SharedInfo sharedInfo = new SharedInfo();
                    String key = getKey(session);
                    Gson gson = new Gson();

                    while (!isCancelled()) {
                        try {
                            float lat = (float) Math.random();
                            float lon = (float) Math.random();                            

                            sharedInfo.setLast_update(System.currentTimeMillis());
                            sharedInfo.setLat(lat);
                            sharedInfo.setLon(lon);

                            Storage.put(key, gson.toJson(sharedInfo));

                            Log.debug(this, "Updated position: " + sharedInfo);

                            Thread.sleep(5000); // TODO: CONFIGURE THIS UPDATE INTERVAL
                        } catch (InterruptedException e) {
                            Log.debug(this, "" + e);
                        }

                        if (System.currentTimeMillis() > updateSoFar
                            || "true".equals(Storage.get(MainActivity.PACKAGE + "." + session + ".need_stop"))) {

                            showNotificationWhenStopToBeFollowed();
                            stopToBeFollowed();
                        }
                    }

                    sharedInfo.setArrived(true);
                    Storage.put(key, gson.toJson(sharedInfo));

                    return null;
                }
            }.execute();
        }
    }

    public static String getKey(String session) {
        return MainActivity.PACKAGE + "." + session + ".shared_info";
    }

    private void stopToBeFollowed() {
        Log.debug(this, "Stop updating service!");

        // TODO: stop update location

        if (mainTask != null) {
            mainTask.cancel(true);
        }

        stopSelf();
    }

    private void showNotificationWhenStopToBeFollowed() {
        NotificationManager notificationManager
                = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

        Notification notification = new Notification(
                R.drawable.stop, getString(R.string.you_are_not_being_followed_anymore), System.currentTimeMillis());

        notification.flags |= Notification.FLAG_AUTO_CANCEL;
        notification.defaults |= Notification.DEFAULT_SOUND;
        notification.defaults |= Notification.DEFAULT_LIGHTS;
        
        PendingIntent arrivedPI = PendingIntent.getActivity(this, 0, null, PendingIntent.FLAG_ONE_SHOT);
        notification.setLatestEventInfo(this, getString(R.string.title_you_are_not_being_followed_anymore),
                getString(R.string.body_you_are_not_being_followed_anymore), arrivedPI);

        notificationManager.notify(MainActivity.NOTIFICATION_ID, notification);
    }

    private void showNotificationWhenFollowed() {
        NotificationManager notificationManager
                = (NotificationManager) getSystemService(Context.NOTIFICATION_SERVICE);

        Notification notification = new Notification(
                R.drawable.followed, getString(R.string.you_are_being_followed), System.currentTimeMillis());

        notification.flags |= Notification.FLAG_AUTO_CANCEL;
        notification.defaults |= Notification.DEFAULT_SOUND;
        notification.defaults |= Notification.DEFAULT_LIGHTS;

        Intent intent = new Intent(MainActivity.PACKAGE + ".ARRIVED");
        intent.putExtra("session", session);
        PendingIntent arrivedPI = PendingIntent.getBroadcast(this, 0, intent, 0);

        notification.setLatestEventInfo(this, getString(R.string.title_arrived_notification),
                getString(R.string.body_arrived_notification), arrivedPI);

        notificationManager.notify(MainActivity.NOTIFICATION_ID, notification);
    }
}

package br.eti.fml.android.sigame.services;

import android.app.Service;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.IBinder;
import br.eti.fml.android.sigame.io.http.PairParam;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.ui.activities.MainActivity;
import br.eti.fml.android.sigame.util.Log;

import java.util.concurrent.atomic.AtomicInteger;

public class UpdatingPositionService extends Service {
    
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
        final String session = settings.getString("updateSession", "");
        final AtomicInteger counter = new AtomicInteger(0);

        if (session == null || "".equals(session)) {
            Log.error(this, "session is null!");
            System.exit(56);
        } else {
            //noinspection unchecked
            new AsyncTask() {
                @Override
                protected Object doInBackground(Object... objects) {
                    while (!isCancelled()) {
                        try {
                            float lat = (float) Math.random();
                            float lon = (float) Math.random();
                            String prefix = MainActivity.PACKAGE + "." + session + "." + counter.get();
                            Storage.put(
                                    new PairParam(prefix + ".lat", lat + ""),
                                    new PairParam(prefix + ".lon", lon + ""),
                                    new PairParam(prefix + ".timestamp", System.currentTimeMillis() + ""));

                            Log.debug(this, "Updated position at " + counter.get());

                            counter.incrementAndGet();

                            Thread.sleep(2000);
                        } catch (InterruptedException e) {
                            Log.debug(this, "" + e);
                        }

                        if (System.currentTimeMillis() > updateSoFar
                            || "true".equals(Storage.get(MainActivity.PACKAGE + "." + session + ".need_stop"))) {

                            Log.debug(this, "Stop updating service!");

                            // TODO: stop update location

                            cancel(true);
                            stopSelf();
                        }
                    }

                    return null;
                }
            }.execute();
        }
    }
}

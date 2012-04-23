package br.eti.fml.android.sigame.ui.activities;

import android.app.Activity;
import android.content.SharedPreferences;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.widget.Button;
import android.widget.TextView;
import br.eti.fml.android.sigame.R;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.util.Log;

import java.util.concurrent.atomic.AtomicInteger;

public class MapActivity extends Activity {
    private AsyncTask updatingScreen;
    
    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.map);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        final Button buttonStopFollow = (Button) findViewById(R.id.stop_follow);

        SharedPreferences settings = getSharedPreferences(MainActivity.PACKAGE, 0);
        final String lastSession = settings.getString("lastSession", "");

        if (lastSession == null || "".equals(lastSession)) {
            Log.error(this, "lastSession cannot be empty here!");
            System.exit(56);
        }

        buttonStopFollow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                if (!Storage.put(MainActivity.PACKAGE + "." + lastSession + ".need_stop", "true")) {
                    Log.error(this, "Unable to stop!");
                }

                buttonStopFollow.setEnabled(false);
                finish();
            }
        });
        
        final TextView position = (TextView) findViewById(R.id.position);
        final TextView lastUpdate = (TextView) findViewById(R.id.last_update);
        final AtomicInteger counter = new AtomicInteger(0);
        
        //noinspection unchecked
        updatingScreen = new AsyncTask() {
            @Override
            protected Object doInBackground(Object... objects) {
                while (!isCancelled()) {
                    try {
                        final String lat = Storage.get(MainActivity.PACKAGE + "."
                                + lastSession + "." + counter.get() + ".lat");

                        final String lon = Storage.get(MainActivity.PACKAGE + "."
                                + lastSession + "." + counter.get() + ".lon");

                        final String timestamp = Storage.get(MainActivity.PACKAGE + "."
                                + lastSession + "." + counter.get() + ".timestamp");

                        if (lat != null && !"".equals(lat)) {
                            counter.incrementAndGet();

                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    position.setText(getString(R.string.position)
                                            + " lat: " + lat + "; lon: " + lon);

                                    lastUpdate.setText(getString(R.string.last_update)
                                            + " lastUpdate: " + timestamp);
                                }
                            });
                        }

                        Thread.sleep(1000);

                        // TODO: after X minutes stop everything

                    } catch (InterruptedException e) {
                        Log.debug(this, "" + e);
                    }
                }

                return null;
            }
        }.execute();
    }

    @Override
    public void onBackPressed() {
        if (updatingScreen != null) {
            updatingScreen.cancel(true);
        }
        
        super.onBackPressed();
    }
}
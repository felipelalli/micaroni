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
import br.eti.fml.android.sigame.bean.SharedInfo;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.ui.UiHelper;
import br.eti.fml.android.sigame.util.Log;
import com.google.gson.Gson;
import com.google.gson.JsonParseException;

import java.text.SimpleDateFormat;
import java.util.Date;

public class MapActivity extends Activity {
    private AsyncTask updatingScreen;
    private String lastSession;
    private int minutes;
    private long startTime;
    private SharedInfo lastSharedInfo = new SharedInfo();

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        startTime = System.currentTimeMillis();

        setContentView(R.layout.map);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        final Button buttonStopFollow = (Button) findViewById(R.id.stop_follow);

        SharedPreferences settings = getSharedPreferences(MainActivity.PACKAGE, 0);
        lastSession = settings.getString("lastSession", "");
        minutes = settings.getInt("minutes", 0);

        if (lastSession == null || "".equals(lastSession)) {
            Log.error(this, "lastSession cannot be empty here!");
            System.exit(56);
        }

        buttonStopFollow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                stopFollow();
            }
        });
        
        final TextView position = (TextView) findViewById(R.id.position);
        final TextView lastUpdate = (TextView) findViewById(R.id.last_update);
        final TextView battery = (TextView) findViewById(R.id.battery);
        final TextView provider = (TextView) findViewById(R.id.provider);
        
        //noinspection unchecked
        updatingScreen = new AsyncTask() {
            @Override
            protected Object doInBackground(Object... objects) {
                while (!isCancelled()) {
                    Log.debug(this, "Starting loop of update...");

                    try {
                        Gson gson = new Gson();
                        String key = MainActivity.PACKAGE + "." + lastSession + ".shared_info";
                        String json = Storage.get(key);
                        
                        if (json == null) {
                            Log.debug(this, "json of key " + key + " is null yet!");

                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    // clear the battery field (to append time left after)
                                    battery.setText(getString(R.string.battery) + " ?");
                                }
                            });
                        } else {
                            lastSharedInfo = gson.fromJson(json, SharedInfo.class);

                            runOnUiThread(new Runnable() {
                                @Override
                                public void run() {
                                    if (lastSharedInfo.getLat() != null && lastSharedInfo.getLon() != null) {
                                        position.setText(getString(R.string.position)
                                                + " lat: " + lastSharedInfo.getLat()
                                                + "; lon: " + lastSharedInfo.getLon()
                                                + "; acc: " + lastSharedInfo.getAccur());
                                    }

                                    if (lastSharedInfo.getLast_update() != null) {
                                        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("HH'h'mm''ss");

                                        lastUpdate.setText(getString(R.string.last_update)
                                                 + " " + simpleDateFormat.format(
                                                    new Date(lastSharedInfo.getLast_update())));
                                    }

                                    if (lastSharedInfo.getBattery() != null) {
                                        battery.setText(getString(R.string.battery) + " "
                                                + Math.round(lastSharedInfo.getBattery() * 100f) + "% "
                                                + (lastSharedInfo.getTemperature() / 10f) + " ºC");
                                    }
                                    
                                    if (lastSharedInfo.getLast_provider() != null) {
                                        provider.setText(getString(R.string.provider)
                                                + " " + lastSharedInfo.getLast_provider());
                                    }
                                }
                            });
                        }

                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                // append time left on battery field
                                battery.setText(battery.getText()
                                        + " - "
                                        + getString(R.string.time_left)
                                        + " " + getTimeLeftInSeconds() + "s");
                            }
                        });

                        Thread.sleep(1000);

                        if (getTimeLeftInSeconds() == 0 || Boolean.TRUE.equals(lastSharedInfo.getArrived())) {
                            Log.debug(this, "Stop follow due to timeout or arrived!");
                            
                            if (Boolean.TRUE.equals(lastSharedInfo.getArrived())) {
                                showNotificationWhenArrived();
                            }
                            
                            stopFollow();
                        }

                    } catch (InterruptedException e) {
                        Log.debug(this, "" + e);
                    } catch (JsonParseException e) {
                        Log.error(this, "Invalid Json! " + e);

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

    private void showNotificationWhenArrived() {
        UiHelper uiHelper = new UiHelper(this);
        uiHelper.showAlert(getString(R.string.arrived_title), R.drawable.icon32, getString(R.string.arrived_body));
    }

    private int getTimeLeftInSeconds() {
        int secondsElapsed = (int) ((System.currentTimeMillis() - startTime) / 1000);
        int secondsTotal = minutes * 60;
        return Math.max(0, secondsTotal - secondsElapsed);
    }

    private void stopFollow() {
        if (updatingScreen != null) {
            updatingScreen.cancel(true);
        }

        if (!Storage.put(MainActivity.PACKAGE + "." + lastSession + ".need_stop", "true")) {
            Log.error(this, "Unable to stop!");
        }

        final Button buttonStopFollow = (Button) findViewById(R.id.stop_follow);
        buttonStopFollow.setEnabled(false);
    }

    @Override
    public void onBackPressed() {
        stopFollow();
        super.onBackPressed();
    }

}
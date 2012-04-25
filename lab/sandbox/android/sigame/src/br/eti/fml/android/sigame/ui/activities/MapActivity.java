package br.eti.fml.android.sigame.ui.activities;

import android.app.Activity;
import android.content.DialogInterface;
import android.content.SharedPreferences;
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
import com.google.gson.Gson;
import com.google.gson.JsonParseException;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

public class MapActivity extends Activity {
    private AsyncTask updatingScreen;
    private String lastSession;
    private int minutes;
    private long startTime;
    private SharedInfo lastSharedInfo = new SharedInfo();
    private AtomicBoolean noAnswer = new AtomicBoolean(true);
    private AtomicInteger messageLevel = new AtomicInteger(0);

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
            finish();
        }

        buttonStopFollow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                stopFollow(Reason.USER_BACK);
            }
        });
        
        final TextView position = (TextView) findViewById(R.id.position);
        final TextView lastUpdate = (TextView) findViewById(R.id.last_update);
        final TextView battery = (TextView) findViewById(R.id.battery);
        final TextView provider = (TextView) findViewById(R.id.provider);
        
        final UiHelper uiHelper = new UiHelper(this);
        
        //noinspection unchecked
        updatingScreen = new AsyncTask() {
            @Override
            protected Object doInBackground(Object... objects) {
                noAnswer.set(true);
                
                while (!isCancelled()) {
                    Log.debug(this, "Starting loop of update...");
                    
                    if (noAnswer.get()) {
                        if ((System.currentTimeMillis() - startTime) > 1000 * 10
                                && messageLevel.get() == 0) {

                            uiHelper.showToast(getString(R.string.no_answer), Toast.LENGTH_LONG);
                            messageLevel.incrementAndGet();
                        } else if ((System.currentTimeMillis() - startTime) > 1000 * 20
                                && messageLevel.get() == 1) {

                            uiHelper.showToast(getString(R.string.no_answer_2), Toast.LENGTH_LONG);
                            messageLevel.incrementAndGet();
                        } if ((System.currentTimeMillis() - startTime) > 1000 * 40
                                && messageLevel.get() == 2) {

                            uiHelper.showToast(getString(R.string.no_answer_3), Toast.LENGTH_LONG);
                            messageLevel.incrementAndGet();

                            Log.debug(this, "Stop follow because the other does not answer!");
                            stopFollow(Reason.NOT_FOUND);
                        }
                    }
                    
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
                            noAnswer.set(false);
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
                            stopFollow(
                                    Boolean.TRUE.equals(lastSharedInfo.getArrived())
                                            ? Reason.ARRIVED : Reason.TIME_IS_UP);
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

    private int getTimeLeftInSeconds() {
        int secondsElapsed = (int) ((System.currentTimeMillis() - startTime) / 1000);
        int secondsTotal = minutes * 60;
        return Math.max(0, secondsTotal - secondsElapsed);
    }
    
    enum Reason {
        TIME_IS_UP,
        USER_BACK,
        ARRIVED,
        NOT_FOUND
    }

    private void stopFollow(final Reason reason) {
        //noinspection unchecked
        new AsyncTask() {
            @Override
            protected void onPreExecute() {
                UiHelper uiHelper = new UiHelper(MapActivity.this);
                uiHelper.showToast(getString(R.string.closing), Toast.LENGTH_SHORT);
            }

            @Override
            protected Object doInBackground(Object... objects) {
                if (updatingScreen != null) {
                    updatingScreen.cancel(true);
                }

                if (!Storage.put(MainActivity.PACKAGE + "." + lastSession + ".need_stop", "true")) {
                    Log.error(this, "Unable to stop!");
                }

                return null;
            }

            @Override
            protected void onPostExecute(Object o) {
                final Button buttonStopFollow = (Button) findViewById(R.id.stop_follow);
                buttonStopFollow.setEnabled(false);
                
                UiHelper uiHelper = new UiHelper(MapActivity.this);

                DialogInterface.OnClickListener closeSelf = new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialogInterface, int i) {
                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                finish();
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
                } else if (reason.equals(Reason.USER_BACK)) {
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            finish();
                        }
                    });
                }
            }
        }.execute();
    }

    @Override
    public void onBackPressed() {
        UiHelper uiHelper = new UiHelper(this);
        final Button buttonStopFollow = (Button) findViewById(R.id.stop_follow);
        
        if (buttonStopFollow.isEnabled()) {
            uiHelper.showToast(getString(R.string.stop_before), Toast.LENGTH_LONG);
        } else {
            stopFollow(Reason.USER_BACK);
        }
    }
}
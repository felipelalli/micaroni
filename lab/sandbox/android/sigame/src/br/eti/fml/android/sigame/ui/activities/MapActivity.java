package br.eti.fml.android.sigame.ui.activities;

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
import com.google.android.maps.GeoPoint;
import com.google.android.maps.MapView;
import com.google.android.maps.OverlayItem;
import com.google.gson.Gson;
import com.google.gson.JsonParseException;

import java.text.SimpleDateFormat;
import java.util.Date;
import java.util.concurrent.atomic.AtomicBoolean;
import java.util.concurrent.atomic.AtomicInteger;

public class MapActivity extends com.google.android.maps.MapActivity {
    public static final float BATTERY = .3f;
    private AsyncTask updatingScreen;
    private String lastSession;
    private int minutes;
    private long startTime;
    private SharedInfo lastSharedInfo = new SharedInfo();
    private AtomicBoolean noAnswer = new AtomicBoolean(true);
    private AtomicInteger notFoundMessageLevel = new AtomicInteger(0);
    private AtomicInteger batteryMessageLevel = new AtomicInteger(0);
    private OverlayItem theGuy;

    private ItemsMap itemizedOverlay;

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

        final MapView mapView = (MapView) findViewById(R.id.mapview);

        itemizedOverlay = new ItemsMap(this.getResources().getDrawable(R.drawable.marker));
        mapView.getOverlays().add(itemizedOverlay);
        mapView.getController().setZoom(16);
        mapView.setBuiltInZoomControls(true);
        mapView.setSatellite(true);
        mapView.setTraffic(true);

        buttonStopFollow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                stopFollow(Reason.USER_BUTTON);
            }
        });

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
                                        runOnUiThread(new Runnable() {
                                            @Override
                                            public void run() {
                                                GeoPoint point = new GeoPoint(
                                                        (int) (lastSharedInfo.getLat().doubleValue() * 1000000),
                                                        (int) (lastSharedInfo.getLon().doubleValue() * 1000000));

                                                if (theGuy != null) {
                                                    itemizedOverlay.removeOverlay(theGuy);
                                                }

                                                theGuy = new OverlayItem(point, "", "");                                                                                                
                                                itemizedOverlay.addOverlay(theGuy);
                                                mapView.getController().animateTo(point);
                                            }
                                        });
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

                                        if (lastSharedInfo.getBattery() < BATTERY
                                                && batteryMessageLevel.get() <= 1) {

                                            uiHelper.showToast(getString(R.string.low_battery), Toast.LENGTH_LONG);
                                            batteryMessageLevel.incrementAndGet();
                                        }
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

    @Override
    protected boolean isRouteDisplayed() {
        return false;
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
        NOT_FOUND,
        USER_BUTTON
    }

    private void stopFollow(final Reason reason) {
        //noinspection unchecked
        new AsyncTask() {
            @Override
            protected void onPreExecute() {
                if (!reason.equals(Reason.USER_BACK)) {
                    UiHelper uiHelper = new UiHelper(MapActivity.this);
                    uiHelper.showToast(getString(R.string.closing), Toast.LENGTH_SHORT);
                }
            }

            @Override
            protected Object doInBackground(Object... objects) {
                if (updatingScreen != null) {
                    updatingScreen.cancel(false);
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
                } else if (reason.equals(Reason.USER_BACK)) {
                    runOnUiThread(new Runnable() {
                        @Override
                        public void run() {
                            finish();
                        }
                    });
                } else if (reason.equals(Reason.USER_BUTTON)) {

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
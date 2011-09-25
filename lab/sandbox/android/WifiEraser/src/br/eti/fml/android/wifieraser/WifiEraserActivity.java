package br.eti.fml.android.wifieraser;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.Context;
import android.content.DialogInterface;
import android.net.wifi.WifiConfiguration;
import android.net.wifi.WifiManager;
import android.os.AsyncTask;
import android.os.Bundle;
import android.view.View;
import android.view.WindowManager;
import android.webkit.WebView;
import android.widget.Button;

import java.util.List;
import java.util.concurrent.atomic.AtomicInteger;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class WifiEraserActivity extends Activity {
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        setContentView(R.layout.main);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        WebView webView = (WebView) findViewById(R.id.label);
        webView.setVerticalScrollBarEnabled(false);
    
        webView.loadData(
                "<html><body style=\"text-align:justify;font-size:14pt;\">"
                + getString(R.string.be_warned) + " " + getString(R.string.description)
                + "</body></html>"
                , "text/html", "utf-8");

        Button button = (Button) findViewById(R.id.go);

        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                //noinspection unchecked
                new AsyncTask<Void, Void, Void>() {

                    @Override
                    protected Void doInBackground(Void... voids) {
                        final WifiManager wifiManager
                                = (WifiManager) getSystemService
                                    (Context.WIFI_SERVICE);

                        final List<WifiConfiguration> configurations
                                = wifiManager.getConfiguredNetworks();

                        runOnUiThread(new Runnable() {
                            @Override
                            public void run() {
                                if (configurations.size() == 0) {
                                    AlertDialog.Builder builder = new AlertDialog
                                            .Builder(WifiEraserActivity.this);

                                    builder.setMessage(getString(R.string
                                            .zero_configuration))
                                           .setCancelable(true)
                                           .setPositiveButton(getString(R
                                                   .string.OK),
                                                   new DialogInterface.OnClickListener() {
                                               @Override
                                               public void onClick(DialogInterface dialogInterface, int i) {
                                                   WifiEraserActivity.this.finish();
                                               }
                                           });

                                    AlertDialog alert = builder.create();
                                    alert.show();

                                } else {
                                    AlertDialog.Builder builder = new AlertDialog
                                            .Builder(WifiEraserActivity.this);

                                    builder.setMessage(getString(R.string
                                            .are_you_sure, configurations.size()))
                                           .setCancelable(true)
                                           .setPositiveButton(getString(R
                                                   .string.Yes),
                                                   new DialogInterface.OnClickListener() {

                                               public void onClick(DialogInterface dialog, int id) {
                                                   //noinspection unchecked
                                                   new AsyncTask<Void, Void,
                                                           Void>() {

                                                       @Override
                                                       protected Void doInBackground(Void... voids) {
                                                           final AtomicInteger removed = new AtomicInteger(0);
                                                           final int size = configurations.size();

                                                           for (WifiConfiguration wifiConfiguration : configurations) {
                                                               if (wifiManager.removeNetwork(wifiConfiguration.networkId)) {
                                                                   removed.getAndIncrement();
                                                               }
                                                           }

                                                           runOnUiThread(new Runnable() {
                                                               @Override
                                                               public void run() {
                                                                    AlertDialog.Builder builder = new AlertDialog
                                                                            .Builder(WifiEraserActivity.this);

                                                                    builder.setMessage(getString(R.string
                                                                            .done, removed.get(), size))
                                                                           .setCancelable(true)
                                                                           .setPositiveButton(getString(R
                                                                                   .string.OK),
                                                                                   new DialogInterface.OnClickListener() {
                                                                               @Override
                                                                               public void onClick(DialogInterface dialogInterface, int i) {
                                                                                   WifiEraserActivity.this.finish();
                                                                               }
                                                                           });

                                                                    AlertDialog alert = builder.create();
                                                                    alert.show();
                                                               }
                                                           });

                                                           return null;
                                                       }
                                                   }.execute();
                                               }
                                           })
                                           .setNegativeButton(getString(R
                                                   .string.No),
                                                   new DialogInterface.OnClickListener() {
                                               public void onClick(DialogInterface dialog, int id) {
                                                   dialog.cancel();
                                               }
                                           });

                                    AlertDialog alert = builder.create();
                                    alert.show();
                                }
                            }
                        });

                        return null;
                    }
                }.execute();
            }
        });
    }
}

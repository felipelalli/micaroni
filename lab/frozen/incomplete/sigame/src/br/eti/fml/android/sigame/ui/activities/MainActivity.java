package br.eti.fml.android.sigame.ui.activities;

import android.app.Activity;
import android.app.PendingIntent;
import android.app.ProgressDialog;
import android.content.*;
import android.os.AsyncTask;
import android.os.Bundle;
import android.telephony.SmsManager;
import android.view.KeyEvent;
import android.view.View;
import android.view.WindowManager;
import android.view.inputmethod.EditorInfo;
import android.view.inputmethod.InputMethodManager;
import android.widget.*;
import br.eti.fml.android.sigame.R;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.receivers.SmsReceived;
import br.eti.fml.android.sigame.ui.UiHelper;

public class MainActivity extends Activity {
    public final static String PACKAGE = "br.eti.fml.android.sigame";
    public final static int NOTIFICATION_STOP_ID = 948249821;
    public final static int NOTIFICATION_FOLLOW_ID = 348728712;

    public static MainActivity instance;
    private ProgressDialog progressDialog;

    public void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        instance = this;

        setContentView(R.layout.main);
        getWindow().addFlags(WindowManager.LayoutParams.FLAG_KEEP_SCREEN_ON);

        final Button buttonFollow = (Button) findViewById(R.id.button_follow);
        final EditText number = (EditText) findViewById(R.id.number_to_follow);

        SharedPreferences settings = getSharedPreferences(PACKAGE, 0);
        String lastNumber = settings.getString("lastNumber", "");
        number.setText(lastNumber);
        number.setSelection(number.getText().length());

        number.setOnEditorActionListener(new TextView.OnEditorActionListener() {
            @Override
            public boolean onEditorAction(TextView v, int actionId, KeyEvent event) {
                if (actionId == EditorInfo.IME_ACTION_DONE
                        || actionId == EditorInfo.IME_ACTION_SEND
                        || actionId == EditorInfo.IME_ACTION_GO) {

                    hideKeyboard(v);
                    buttonFollow.requestFocus();
                    buttonFollow.performClick();
                }

                return true;
            }
        });

        buttonFollow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                String realNumber = number.getText().toString();

                if (realNumber == null || "".equals(realNumber)) {
                    UiHelper uiHelper = new UiHelper(MainActivity.this);
                    uiHelper.showAlert(getString(R.string.error), R.drawable.icon32, getString(R.string.error_number));
                } else {
                    sendTheSMSInThread(realNumber);
                    hideKeyboard(number);
                }
            }
        });
    }

    private void hideKeyboard(TextView v) {
        InputMethodManager imm = (InputMethodManager) getSystemService(Context.INPUT_METHOD_SERVICE);
        imm.hideSoftInputFromWindow(v.getWindowToken(), 0);
    }
    
    private void sendTheSMSInThread(final String realNumber) {
        final UiHelper uiHelper = new UiHelper(this);
        progressDialog = ProgressDialog.show(this, "",
                getString(R.string.sending_sms), true);

        progressDialog.show();
        progressDialog.setCancelable(false);

        long random = (long) (Math.random() * Long.MAX_VALUE);
        final String session = Long.toString(random, Character.MAX_RADIX);

        final Spinner spinner = (Spinner) findViewById(R.id.minutes);
        final int minutes = spinner.getSelectedItemPosition() == 0 ? 5
                          : spinner.getSelectedItemPosition() == 1 ? 10
                          : spinner.getSelectedItemPosition() == 2 ? 15 : 1;

        final String message =
                getString(R.string.sms_message) +
                session + "," + minutes + "," + SmsReceived.CONSTANT_ID;

        //noinspection unchecked
        new AsyncTask() {
            @Override
            protected Object doInBackground(Object... objects) {
                if (!Storage.put(PACKAGE + "." + session + ".need_stop", "false")) {
                    uiHelper.showAlert(getString(R.string.error), R.drawable.icon32,
                            getString(R.string.internet_error), new DialogInterface.OnClickListener() {

                        @Override
                        public void onClick(DialogInterface dialogInterface, int i) {
                            //System.exit(56);
                            dialogInterface.dismiss();

                            if (progressDialog != null) {
                                progressDialog.dismiss();
                            }
                        }
                    });
                } else {
                    SharedPreferences settings = getSharedPreferences(MainActivity.PACKAGE, 0);
                    SharedPreferences.Editor editor = settings.edit();
                    editor.putString("lastNumber", realNumber);
                    editor.putString("lastSession", session);
                    editor.putInt("minutes", minutes);
                    editor.commit();

                    PendingIntent sentPI = PendingIntent.getBroadcast(
                            MainActivity.this, 0, new Intent(PACKAGE + ".SMS_SENT"), 0);

                    SmsManager sm = SmsManager.getDefault();
                    sm.sendTextMessage(realNumber, null, message, sentPI, null);
                }

                return null;
            }
        }.execute();
    }

    public void dismissDialog() {
        if (progressDialog != null) {
            progressDialog.dismiss();
        }
    }
}
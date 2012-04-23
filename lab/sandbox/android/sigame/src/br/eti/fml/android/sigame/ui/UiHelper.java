package br.eti.fml.android.sigame.ui;

import android.app.Activity;
import android.app.AlertDialog;
import android.content.DialogInterface;
import android.view.View;
import android.view.WindowManager;
import android.widget.EditText;
import android.widget.Toast;
import br.eti.fml.android.sigame.R;
import br.eti.fml.android.sigame.util.DefaultCallback;
import br.eti.fml.android.sigame.util.Log;

import java.util.HashMap;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 * @author Danny Caldas de Almeida Araújo (danny.caldas@movile.com / dannycaa@gmail.com)
 */
@SuppressWarnings("UnusedDeclaration")
public class UiHelper {
    private Activity activity;

    // Used by our itemList every time we call showItemList() method!
    private HashMap<Integer, Boolean> itemListHashMap = new HashMap<Integer, Boolean>();
    private AlertDialog itemListDialog = null;

    // ItemList types
    public enum ItemListType {
        CHECK_BUTTON_LIST,
        RADIO_BUTTON_LIST
    }

    public UiHelper(Activity activity) {
        this.activity = activity;
    }

    public void showToast(final String text, final int length) {
        showToast(text, length, -1, -1, -1);
    }

    public void showToast(final String text, final int length, final int gravity, final int xOffset, final int yOffset) {
        Runnable runnable = new Runnable() {
            @Override
            public void run() {
                Toast toast;
                toast = Toast.makeText(activity, text, length);

                if (gravity != -1) {
                    toast.setGravity(gravity, xOffset, yOffset);
                }

                if (!activity.isFinishing()) {
                    toast.show();
                } else {
                    Log.error(UiHelper.class, "[UiHelper] showToast - toast.show() not EXECUTED!");
                }
            }
        };

        activity.runOnUiThread(runnable);
    }

    public void showTextInput(String title, String defaultText, final DefaultCallback<String> callback) {
        final AlertDialog.Builder builder = new AlertDialog.Builder(activity);
        builder.setTitle(title);
        final EditText et = new EditText(activity);
        et.setText(defaultText);
        et.selectAll();

        builder.setView(et);
        builder.setOnCancelListener(new DialogInterface.OnCancelListener() {
            @Override
            public void onCancel(DialogInterface dialog) {
                callback.success("");
            }
        });

        builder.setPositiveButton("OK", new DialogInterface.OnClickListener() { // TODO hardcoded
            @Override
            public void onClick(DialogInterface dialog, int which) {
                callback.success(et.getText().toString());
            }
        });

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                final AlertDialog alert = builder.create();

                et.setOnFocusChangeListener(new View.OnFocusChangeListener() {
                    @Override
                    public void onFocusChange(View v, boolean hasFocus) {
                        if (hasFocus) {
                            alert.getWindow().setSoftInputMode(
                                    WindowManager.LayoutParams.SOFT_INPUT_STATE_ALWAYS_VISIBLE);
                        }
                    }
                });

                if (!activity.isFinishing()) {
                    alert.show();
                } else {
                    Log.error(UiHelper.class, "[UiHelper] showTextInput - alert.show() not EXECUTED!");
                }
            }
        });
    }

    public void showAlert(final String title, final String message,
                          final DialogInterface.OnClickListener... callback) {

        //noinspection NullableProblems
        showAlert(title, null, message, callback);
    }

    public void showAlert(final String title, final Integer icon, final String message,
                          final DialogInterface.OnClickListener... callback) {

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder = new AlertDialog.Builder(activity);

                builder.setTitle(title)
                        .setMessage(message)
                        .setCancelable(true)
                        .setPositiveButton("OK", callback.length == 0 ? null : callback[0]);

                if (icon != null) {
                    builder.setIcon(icon);
                } else {
                    builder.setIcon(R.drawable.icon32);
                }

                final AlertDialog alert = builder.create();

                alert.setOnCancelListener(new DialogInterface.OnCancelListener() {
                    @Override
                    public void onCancel(DialogInterface dialog) {
                        if (callback.length > 0) {
                            callback[0].onClick(alert, -1);
                        }
                    }
                });

                if (!activity.isFinishing()) {
                    alert.show();
                } else {
                    Log.error(UiHelper.class, "[UiHelper] showAlert - alert.show() not EXECUTED!");
                }
            }
        });
    }

    public void showQuestion(final String title, final String message,
                             final String option1, final String option2,
                             final DialogInterface.OnClickListener listener) {

        //noinspection NullableProblems
        showQuestion(title, null, message, option1, option2, listener);
    }

    public void showQuestion(final String title, final Integer icon, final String message,
                             final String option1, final String option2,
                             final DialogInterface.OnClickListener listener,
                             final DialogInterface.OnCancelListener... onCancelListener) {

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder = new AlertDialog.Builder(activity);

                builder.setMessage(message)
                        .setCancelable(true)
                        .setTitle(title)
                        .setPositiveButton(option1, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                listener.onClick(dialog, 0);
                            }
                        })
                        .setNeutralButton(option2, new DialogInterface.OnClickListener() {
                            @Override
                            public void onClick(DialogInterface dialog, int which) {
                                listener.onClick(dialog, 1);
                            }
                        });

                if (onCancelListener.length > 0) {
                    builder.setOnCancelListener(onCancelListener[0]);
                }

                if (icon != null) {
                    builder.setIcon(icon);
                }

                AlertDialog alert = builder.create();
                if (!activity.isFinishing()) {
                    alert.show();
                } else {
                    Log.error(UiHelper.class, "[UiHelper] showQuestion - alert.show() not EXECUTED!");
                }
            }
        });
    }

    public void showActionList(final String title, final CharSequence[] actionList,
                               final DialogInterface.OnClickListener listener) {

        activity.runOnUiThread(new Runnable() {
            @Override
            public void run() {
                AlertDialog.Builder builder = new AlertDialog.Builder(activity);

                builder.setCancelable(true)
                        .setTitle(title)
                        .setItems(actionList, listener);

                AlertDialog alert = builder.create();
                if (!activity.isFinishing()) {
                    alert.show();
                } else {
                    Log.error(UiHelper.class, "[UiHelper] showActionList - alert.show() not EXECUTED!");
                }
            }
        });
    }
}
package br.eti.fml.android.sigame.receivers;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.telephony.SmsManager;
import android.widget.Toast;
import br.eti.fml.android.sigame.R;
import br.eti.fml.android.sigame.ui.UiHelper;
import br.eti.fml.android.sigame.ui.activities.MainActivity;
import br.eti.fml.android.sigame.ui.activities.MapActivity;

public class SmsSentReceiver {
    public void onReceive(Context context, Intent intent, int resultCode) {
        if (MainActivity.instance != null) {
            UiHelper uiHelper = new UiHelper(MainActivity.instance);
            MainActivity.instance.dismissDialog();

            switch (resultCode) {
                case Activity.RESULT_OK:
                    uiHelper.showToast(MainActivity.instance.getString(R.string.sms_sent), Toast.LENGTH_SHORT);
                    MainActivity.instance.startActivity(new Intent(MainActivity.instance, MapActivity.class));
                    break;
                case SmsManager.RESULT_ERROR_GENERIC_FAILURE:
                    uiHelper.showToast(MainActivity.instance.getString(R.string.sms_generic_error), Toast.LENGTH_LONG);
                    break;
                case SmsManager.RESULT_ERROR_NO_SERVICE:
                    uiHelper.showToast(MainActivity.instance.getString(R.string.sms_no_service_error), Toast.LENGTH_SHORT);
                    break;
                case SmsManager.RESULT_ERROR_NULL_PDU:
                    uiHelper.showToast(MainActivity.instance.getString(R.string.sms_generic_error), Toast.LENGTH_LONG);
                    break;
                case SmsManager.RESULT_ERROR_RADIO_OFF:
                    uiHelper.showToast(MainActivity.instance.getString(R.string.sms_no_service_error), Toast.LENGTH_SHORT);
                    break;
            }
        }
    }
}

package br.eti.fml.android.sigame.receivers;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import br.eti.fml.android.sigame.util.Log;

@SuppressWarnings("UnusedDeclaration")
public class CustomReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, Intent intent) {
        if (intent != null && intent.getAction() != null) {
            if ("br.eti.fml.android.sigame.SMS_SENT".equals(intent.getAction())) {
                SmsSentReceiver smsSentReceiver = new SmsSentReceiver();
                smsSentReceiver.onReceive(context, intent, getResultCode());

            } else if ("android.provider.Telephony.SMS_RECEIVED".equals(intent.getAction())) {
                SmsReceived smsReceived = new SmsReceived();

                if (smsReceived.process(context, intent)) {
                    abortBroadcast(); // prevent Android and other apps intercept the SMS
                }
            }
        }
    }
}

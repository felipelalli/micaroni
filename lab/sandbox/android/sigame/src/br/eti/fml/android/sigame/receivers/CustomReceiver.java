package br.eti.fml.android.sigame.receivers;

import android.content.BroadcastReceiver;
import android.content.Context;
import android.content.Intent;
import android.os.AsyncTask;
import br.eti.fml.android.sigame.bean.SharedInfo;
import br.eti.fml.android.sigame.io.storage.Storage;
import br.eti.fml.android.sigame.services.UpdatingPositionService;
import br.eti.fml.android.sigame.util.Log;
import com.google.gson.Gson;

@SuppressWarnings("UnusedDeclaration")
public class CustomReceiver extends BroadcastReceiver {
    @Override
    public void onReceive(Context context, final Intent intent) {
        if (intent != null && intent.getAction() != null) {
            if ("br.eti.fml.android.sigame.SMS_SENT".equals(intent.getAction())) {
                SmsSentReceiver smsSentReceiver = new SmsSentReceiver();
                smsSentReceiver.onReceive(context, intent, getResultCode());

            } else if ("br.eti.fml.android.sigame.ARRIVED".equals(intent.getAction())) {
                Log.debug(this, "I have been arrived! Stop the service...");
                context.stopService(new Intent(context, UpdatingPositionService.class));

                //noinspection unchecked
                new AsyncTask() {
                    @Override
                    protected Object doInBackground(Object... objects) {
                        try {
                            if (intent.getExtras() != null) {
                                String session = intent.getExtras().getString("session");
                                Gson gson = new Gson();
    
                                if (session != null) {
                                    Log.debug(this, "Saying to other that I arrived. Session: " + session);

                                    String key = UpdatingPositionService.getKey(session);

                                    String lastSharedInfo = Storage.get(key);
                                    SharedInfo sharedInfo;

                                    if (lastSharedInfo == null) {
                                        sharedInfo = new SharedInfo();
                                    } else {
                                        sharedInfo = gson.fromJson(lastSharedInfo, SharedInfo.class);
                                    }

                                    sharedInfo.setLast_update(System.currentTimeMillis());
                                    sharedInfo.setArrived(true);
                                    Storage.put(key, gson.toJson(sharedInfo));
                                }
                            }
                        } catch (Exception e) {
                            Log.error(this, "Error when trying to say arrived: " + e);
                            // TODO: need to try again
                        }

                        return null;
                    }
                }.execute();

            } else if ("android.provider.Telephony.SMS_RECEIVED".equals(intent.getAction())) {
                SmsReceived smsReceived = new SmsReceived();

                if (smsReceived.process(context, intent)) {
                    abortBroadcast(); // prevent Android and other apps intercept the SMS
                }
            }
        }
    }
}

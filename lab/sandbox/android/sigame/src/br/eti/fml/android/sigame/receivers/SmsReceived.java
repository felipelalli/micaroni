package br.eti.fml.android.sigame.receivers;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.SharedPreferences;
import android.os.Bundle;
import android.telephony.SmsMessage;
import br.eti.fml.android.sigame.services.UpdatingPositionService;
import br.eti.fml.android.sigame.ui.activities.MainActivity;
import br.eti.fml.android.sigame.util.Log;

import java.util.NoSuchElementException;
import java.util.StringTokenizer;


/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public class SmsReceived {

    public boolean process(Context context, Intent intent) {
        boolean internal = false;
        Bundle bundle = intent.getExtras();
        String body = null;

        if (bundle != null) {
            Object[] smsExtra = (Object[]) bundle.get("pdus");

            for (Object aSmsExtra : smsExtra) {
                SmsMessage sms = SmsMessage.createFromPdu((byte[]) aSmsExtra);
                body = sms.getMessageBody();

                if (body != null && body.contains("http://bit.ly/siga_me")) {
                    internal = true;
                }
            }
        }

        if (body != null && internal) {
            try {
                StringTokenizer st = new StringTokenizer(body, "~");
                st.nextToken();
                String lastPart = st.nextToken();

                StringTokenizer st2 = new StringTokenizer(lastPart.trim(), ",");
                String session = st2.nextToken().trim();
                Log.debug(this, "Session: " + session);
                int minutes = Integer.valueOf(st2.nextToken().trim());
                Log.debug(this, "Minutes " + minutes);

                SharedPreferences settings
                        = MainActivity.instance.getSharedPreferences(MainActivity.PACKAGE, 0);

                long updateSoFar = System.currentTimeMillis() + (minutes * 60 * 1000);

                SharedPreferences.Editor editor = settings.edit();
                editor.putLong("updateSoFar", updateSoFar);
                editor.putString("updateSession", session);
                editor.commit();

                context.stopService(new Intent(context, UpdatingPositionService.class));
                context.startService(new Intent(context, UpdatingPositionService.class));
                Log.debug(this, "Should service start?");

            } catch (NullPointerException e) {
                Log.error(this, "Error: " + e + "; body = '" + body + "'");
            } catch (NumberFormatException e) {
                Log.error(this, "Error: " + e + "; body = '" + body + "'");
            } catch (NoSuchElementException e) {
                Log.error(this, "Error: " + e + "; body = '" + body + "'");
            }
        }

        return internal;
    }
}

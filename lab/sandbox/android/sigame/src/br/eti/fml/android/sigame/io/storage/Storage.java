package br.eti.fml.android.sigame.io.storage;

import br.eti.fml.android.sigame.io.http.ConnectionException;
import br.eti.fml.android.sigame.io.http.HttpHelper;
import br.eti.fml.android.sigame.io.http.PairParam;
import br.eti.fml.android.sigame.util.Log;

import java.util.Arrays;

public class Storage {
    public static boolean put(PairParam ... values) {
        for (PairParam pp : values) {
            pp.name = pp.name.replaceAll("\\.", "\\_");
        }

        boolean ok;

        try {
            String result = HttpHelper.makeAnHttpCallToString("http://api.openkeyval.org/store/",
                    10000, 2, true, values);

            if (result != null && result.contains("\"status\"")) {
                ok = true;
                Log.debug(Storage.class, "PUT: " + Arrays.toString(values));
            } else {
                ok = false;
                Log.error(Storage.class, "Result not expected: " + result + "; Error to put " + Arrays.toString(values));
            }

        } catch (ConnectionException e) {
            Log.error(Storage.class, "Connection error! Error to put " + Arrays.toString(values));
            ok = false;
        }

        return ok;
    }

    public static boolean put(String key, String value) {
        return put(new PairParam(key, value));
    }

    public static String get(String key) {
        key = key.replaceAll("\\.", "\\_");
        String res = null;

        try {
            res = HttpHelper.makeAnHttpCallToString("http://api.openkeyval.org/" + key,
                    10000, 2, true);

            if (res == null) {
                Log.error(Storage.class, "the result is null");
            } else {
                res = res.trim();

                if (res.contains("\"error\"")) {
                    Log.error(Storage.class, "Error on GET " + key + ": " + res);
                    res = null;
                } else {
                    Log.debug(Storage.class, "GET " + key + "=" + res);
                }
            }

        } catch (ConnectionException e) {
            Log.error(Storage.class, "Connection error! Error to get " + key);
        }

        return res;
    }
}

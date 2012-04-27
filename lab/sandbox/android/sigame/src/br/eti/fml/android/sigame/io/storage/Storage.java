package br.eti.fml.android.sigame.io.storage;

import br.eti.fml.android.sigame.util.Log;
import com.amazonaws.auth.BasicAWSCredentials;
import com.amazonaws.services.simpledb.AmazonSimpleDB;
import com.amazonaws.services.simpledb.AmazonSimpleDBClient;
import com.amazonaws.services.simpledb.model.*;

import java.util.ArrayList;
import java.util.List;

public class Storage {
    private static AmazonSimpleDB db;
    private static final String DOMAIN_NAME = "sigame";

    static {
        BasicAWSCredentials credentials
                = new BasicAWSCredentials("AKIAJYI2SX2FFBG55S5A", "glWMRea6pCTsvCkYB2ESPgw8L8QSpG4/XQ4qfoOI");

        db = new AmazonSimpleDBClient(credentials);
    }

    public static boolean put(String key, String value) {
        boolean ok;
        long startTime = System.currentTimeMillis();

        try {
            List<ReplaceableAttribute> attributes = new ArrayList<ReplaceableAttribute>();
            ReplaceableAttribute attr = new ReplaceableAttribute("v", value, true);
            attributes.add(attr);
            PutAttributesRequest putAttributesRequest = new PutAttributesRequest(DOMAIN_NAME, key, attributes);
            db.putAttributes(putAttributesRequest);
            ok = true;
        } catch (Exception e) {
            ok = false;
            Log.warn(Storage.class, "Error on PUT " + key + ": " + e);
        }

        Log.debug(Storage.class, "[PUT] " + key + "=" + value + " - ok? " + ok + " - " + (System.currentTimeMillis() - startTime) + " ms");
        return ok;
    }

    public static boolean delete(String key) {
        boolean ok;
        long startTime = System.currentTimeMillis();

        try {
            DeleteAttributesRequest deleteAttributesRequest = new DeleteAttributesRequest(DOMAIN_NAME, key);
            db.deleteAttributes(deleteAttributesRequest);
            ok = true;
        } catch (Exception e) {
            ok = false;
            Log.warn(Storage.class, "Error on DELETE " + key + ": " + e);
        }

        Log.debug(Storage.class, "[DELETE] " + key + "=" + key + " - ok? "
                + ok + " - " + (System.currentTimeMillis() - startTime) + " ms");

        return ok;
    }

    public static String get(String key) {
        long startTime = System.currentTimeMillis();
        String res = null;

        try {
            GetAttributesRequest getAttributesRequest = new GetAttributesRequest(DOMAIN_NAME, key);
            GetAttributesResult getAttributesResult = db.getAttributes(getAttributesRequest);

            @SuppressWarnings("unchecked")
            List<Attribute> attributes = getAttributesResult.getAttributes();
    
            if (attributes.size() > 0) {
                res = attributes.get(0).getValue();
            }
        } catch (Exception e) {
            Log.warn(Storage.class, "Error on GET " + key + ": " + e);
        }

        Log.debug(Storage.class, "[GET] " + key + "=" + res + " - " + (System.currentTimeMillis() - startTime) + " ms");
        return res;
    }
}

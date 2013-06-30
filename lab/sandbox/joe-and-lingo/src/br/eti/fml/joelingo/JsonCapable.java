package br.eti.fml.joelingo;

import com.google.gson.FieldNamingPolicy;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

/**
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class JsonCapable {
    private final static Gson GSON;

    static {
        GSON = new GsonBuilder()
                .setFieldNamingPolicy(FieldNamingPolicy.LOWER_CASE_WITH_UNDERSCORES)
                .create();
    }

    public String getJsonRepresentation() {
        return GSON.toJson(this);
    }
}

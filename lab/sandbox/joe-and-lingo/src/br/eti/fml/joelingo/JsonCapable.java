package br.eti.fml.joelingo;

import com.google.gson.FieldNamingPolicy;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.google.gson.reflect.TypeToken;

import java.lang.reflect.Type;

/**
 * Capable to be transformed in JSON.
 *
 * @author Felipe Micaroni Lalli (micaroni@gmail.com)
 */
public abstract class JsonCapable<T> implements Cloneable {
    private final static Gson GSON;

    static {
        GSON = new GsonBuilder()
                .setFieldNamingPolicy(FieldNamingPolicy.LOWER_CASE_WITH_UNDERSCORES)
                .create();
    }

    public String getJsonRepresentation() {
        return GSON.toJson(this);
    }

    @SuppressWarnings({"CloneDoesntDeclareCloneNotSupportedException", "CloneDoesntCallSuperClone"})
    @Override
    public T clone() {
        Type typeOfT = new TypeToken<JsonCapable<T>>(){}.getType();
        return GSON.fromJson(GSON.toJson(this), typeOfT);
    }
}

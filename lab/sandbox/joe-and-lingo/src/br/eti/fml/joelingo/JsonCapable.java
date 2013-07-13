package br.eti.fml.joelingo;

import com.google.gson.FieldNamingPolicy;
import com.google.gson.Gson;
import com.google.gson.GsonBuilder;

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

    @SuppressWarnings({"CloneDoesntCallSuperClone", "unchecked", "CloneDoesntDeclareCloneNotSupportedException"})
    @Override
    public T clone() {
        return (T) GSON.fromJson(GSON.toJson(this), getClass());
    }

    public String toString() {
        return this.getJsonRepresentation();
    }
}

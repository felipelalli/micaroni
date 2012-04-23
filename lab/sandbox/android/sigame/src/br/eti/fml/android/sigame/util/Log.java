package br.eti.fml.android.sigame.util;

import java.util.concurrent.atomic.AtomicBoolean;

/**
 * Util for debug / log.
 *
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
public final class Log {
    private static AtomicBoolean verboseOn = new AtomicBoolean(true);

    private Log() {
        super();
    }

    public static void turnOffVerbose() {
        verboseOn.set(false);
    }

    private static String getMessage(String message, boolean withZg) {
        return (!withZg ? "" : "[SIGAME] ") + (message == null ? "" : message);
    }

    private static String getName(Object origin) {
        return origin instanceof String ? origin.toString()
                : origin instanceof Class ? ((Class) origin).getSimpleName()
                : origin.getClass().getSimpleName();
    }

    @SuppressWarnings("unused")
    public static void debug(Object origin, String message, Throwable... e) {
        android.util.Log.d(getName(origin), getMessage(message, true), e.length == 0 ? null : e[0]);
    }

    @SuppressWarnings("unused")
    public static void error(Object origin, String message, Throwable... e) {
        android.util.Log.e(getName(origin), getMessage(message, true), e.length == 0 ? null : e[0]);
    }

    @SuppressWarnings("unused")
    public static void error(Object origin, Throwable e) {
        android.util.Log.e(getName(origin), getMessage(e + "", true), e);
    }

    @SuppressWarnings("unused")
    public static void warn(Object origin, String message, Throwable... e) {
        android.util.Log.w(getName(origin), getMessage(message, true), e.length == 0 ? null : e[0]);
    }

    @SuppressWarnings("unused")
    public static void info(Object origin, String message, Throwable... e) {
        android.util.Log.i(getName(origin), getMessage(message, true), e.length == 0 ? null : e[0]);
    }

    @SuppressWarnings("unused")
    public static void verbose(Object origin, String message, Throwable... e) {
        if (verboseOn.get()) {
            android.util.Log.v(getName(origin), getMessage(message, true), e.length == 0 ? null : e[0]);
        }
    }

    @SuppressWarnings("unused")
    public static void wtf(Object origin, String message, Throwable... e) {
        if (Integer.valueOf(android.os.Build.VERSION.SDK) >= 8) {
            android.util.Log.wtf(getName(origin), getMessage(message, true), e.length == 0 ? null : e[0]);
        } else {
            android.util.Log.e(getName(origin), getMessage(message, true), e.length == 0 ? null : e[0]);
        }
    }
}

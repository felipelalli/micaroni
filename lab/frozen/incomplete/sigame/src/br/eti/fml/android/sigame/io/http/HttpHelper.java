package br.eti.fml.android.sigame.io.http;

import android.net.Uri;
import br.eti.fml.android.sigame.util.Pair;
import br.eti.fml.android.sigame.util.Log;
import org.apache.commons.io.IOUtils;
import org.apache.http.Header;
import org.apache.http.HttpEntity;
import org.apache.http.HttpResponse;
import org.apache.http.client.methods.HttpGet;
import org.apache.http.client.methods.HttpPost;
import org.apache.http.client.methods.HttpRequestBase;
import org.apache.http.entity.BasicHttpEntity;
import org.apache.http.impl.client.DefaultHttpClient;
import org.apache.http.params.BasicHttpParams;
import org.apache.http.params.HttpConnectionParams;
import org.apache.http.params.HttpParams;

import java.io.ByteArrayInputStream;
import java.io.ByteArrayOutputStream;
import java.io.IOException;
import java.util.Arrays;

/**
 * @author Felipe Micaroni Lalli (felipe.micaroni@movile.com / micaroni@gmail.com)
 */
@SuppressWarnings("UnusedDeclaration")
public final class HttpHelper {
    private HttpHelper() {}

    public static String makeUrlWithParameters(String urlBase, PairParam... params) {
        urlBase = urlBase.replaceFirst("http:", "");

        Uri.Builder uri = new Uri.Builder();
        uri.scheme("http");
        uri.encodedPath(urlBase);

        if (params != null && params.length > 0) {
            for (PairParam param : params) {
                if (param != null) {
                    uri.appendQueryParameter(param.name, param.value);
                }
            }
        }

        //uri.appendQueryParameter("apk", Core.getInstance().getApkVersion().first);

        return uri.build().toString();
    }

    /**
     * Use like this:
     * <pre>
        HttpHelper.makeAnHttpCall("http://api-url/, 3000, new String[][] {
                {"key1", "value1"}, {"key2", "value2"}, ...
        });
     </pre>
     *
     * @param getMethod true to GET and false to POST
     * @param params request parameters
     * @param urlBase the url base
     * @param maxAttempts the max attempts
     * @param timeoutInMillis 0 to infinite
     * @return a pair with the result in ByteArrayOutputStream and the encoding
     * @throws ConnectionException if something wrong happens with the connection
     */
    public static Pair<ByteArrayInputStream, String> makeAnHttpCall(
            String urlBase, int timeoutInMillis, int maxAttempts, boolean getMethod,
            PairParam... params) throws ConnectionException {

        long now = System.currentTimeMillis();
        ByteArrayOutputStream result = new ByteArrayOutputStream();
        String encoding = "UTF-8";
        int attemptsLeft = Math.max(0, maxAttempts - 1);
        boolean success;
        Exception lastException = null;

        do {
            HttpParams httpParameters = new BasicHttpParams();
            HttpConnectionParams.setConnectionTimeout(httpParameters, timeoutInMillis);

            DefaultHttpClient httpClient = new DefaultHttpClient(httpParameters);

            HttpRequestBase call;
            String completeUrl = makeUrlWithParameters(urlBase, params);

            if (getMethod) {
                call = new HttpGet(completeUrl);
                Log.verbose(HttpHelper.class, "[HTTP_CALL] HTTP GET: " + completeUrl);
            } else {
                HttpPost post = new HttpPost(urlBase);
                HttpParams httpParams = new BasicHttpParams();

                httpParams.setParameter("Content-Type", "application/x-www-form-urlencoded");

                String[] datas = completeUrl.split("\\?");

                if (datas.length < 2) {
                    Log.error(HttpHelper.class, "[HTTP_CALL] Invalid HTTP POST URL: " + completeUrl);
                    throw new ConnectionException("Error to call " + urlBase
                            + " with parameters: " + paramsToString(params));
                } else {
                    String data = datas[1];

                    httpParams.setParameter("Content-Length", data.length());
                    BasicHttpEntity httpEntity = new BasicHttpEntity();
                    try {
                        httpEntity.setContent(IOUtils.toInputStream(data, "UTF-8"));
                        httpEntity.setContentLength(data.length());
                    } catch (IOException e) {
                        Log.error(HttpHelper.class, e + "", e);
                        throw new ConnectionException("Error to call " + urlBase
                                + " with parameters: " + paramsToString(params), e);
                    }

                    post.setEntity(httpEntity);

                    post.setParams(httpParams);
                    call = post;

                    Log.debug(HttpHelper.class, "[HTTP_CALL] HTTP POST: "
                            + urlBase + "; params: " + Arrays.toString(params));
                }
            }

            HttpEntity entity = null;

            try {
                HttpResponse response = httpClient.execute(call);

                entity = response.getEntity();
                Header encodingHeader = entity.getContentEncoding();
                if (encodingHeader != null && encodingHeader.getValue() != null) {
                    encoding = encodingHeader.getValue();
                }

                IOUtils.copy(entity.getContent(), result);

                Log.verbose(HttpHelper.class, "[HTTP_CALL] Response: " + response.getStatusLine()
                        + " in " + (System.currentTimeMillis() - now) + " millis");

                success = true;
            } catch (Exception e) {
                success = false;
                lastException = e;
            } finally {
                if (entity != null) {
                    try {
                        entity.consumeContent();
                    } catch (IOException e) {
                        Log.error(HttpHelper.class, "" + e, e);
                    }
                }
            }

            if (!success && attemptsLeft > 0) {
                attemptsLeft--;

                try {
                    Log.debug(HttpHelper.class, "[HTTP_CALL] Trying again after 1 sec...");
                    Thread.sleep(1000);
                } catch (InterruptedException e1) {
                    Log.error(HttpHelper.class, "" + e1, e1);
                }
            }
        } while (attemptsLeft > 0 && !success);

        ByteArrayInputStream realResult = new ByteArrayInputStream(result.toByteArray());

        try {
            result.close();
        } catch (IOException e) {
            success = false;
            lastException = e;
        }

        if (!success) {
            throw new ConnectionException("Error to call " + urlBase
                    + " with parameters: " + paramsToString(params), lastException);
        }

        return new Pair<ByteArrayInputStream, String>(realResult, encoding);
    }

    /**
     * Use like this:
     * <pre>
        HttpHelper.makeAnHttpCall("http://api-url/, 3000, new String[][] {
                {"key1", "value1"}, {"key2", "value2"}, ...
        });
     </pre>
     *
     * @param maxAttempts the max attempts
     * @param getMethod true to GET and false to POST
     * @param params request parameters
     * @param urlBase the url base
     * @param timeoutInMillis 0 to infinite
     * @return the result in String format
     * @throws ConnectionException if something wrong happens with the connection
     */
    public static String makeAnHttpCallToString(
            String urlBase, int timeoutInMillis, int maxAttempts, boolean getMethod,
            PairParam... params) throws ConnectionException {

        Pair<ByteArrayInputStream, String> result = makeAnHttpCall(
                urlBase, timeoutInMillis, maxAttempts, getMethod, params);

        String string;

        try {
            string = IOUtils.toString(result.first, result.second);
            result.first.close();
        } catch (IOException e) {
            throw new ConnectionException("Error to call " + urlBase
                    + " with parameters: " + paramsToString(params), e);
        }

        return string;
    }

    /**
     * Used only for debug.
     *
     * @param params the params
     * @return the result
     */
    private static String paramsToString(PairParam... params) {
        StringBuilder result = new StringBuilder();

        if (params == null || params.length <= 0) {
            result.append("<empty>");
        } else {
            for (PairParam param : params) {
                result.append("(").append(param.name).append(",").append(param.value).append(")");
                result.append(";");
            }
        }

        return result.toString();
    }
}

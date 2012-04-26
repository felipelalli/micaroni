package br.eti.fml.android.sigame.ui.activities;

import android.graphics.Canvas;
import android.graphics.Color;
import android.graphics.Paint;
import android.graphics.Point;
import com.google.android.maps.GeoPoint;
import com.google.android.maps.MapView;
import com.google.android.maps.Projection;

public class LineMapOverlay extends com.google.android.maps.Overlay {
    private GeoPoint mGpt1;
    private GeoPoint mGpt2;

    protected LineMapOverlay(GeoPoint gp1, GeoPoint gp2 ) {
        mGpt1 = gp1;
        mGpt2 = gp2;
    }

    @Override
    public boolean draw(Canvas canvas, MapView mapView, boolean shadow,
                        long when) {

        super.draw(canvas, mapView, shadow);
        Paint paint;
        paint = new Paint();
        paint.setColor(Color.RED);
        paint.setAntiAlias(true);
        paint.setStyle(Paint.Style.STROKE);
        paint.setStrokeWidth(2);
        Point pt1 = new Point();
        Point pt2 = new Point();
        Projection projection = mapView.getProjection();
        projection.toPixels(mGpt1, pt1);
        projection.toPixels(mGpt2, pt2);
        canvas.drawLine(pt1.x, pt1.y, pt2.x, pt2.y, paint);
        return true;
    }
}

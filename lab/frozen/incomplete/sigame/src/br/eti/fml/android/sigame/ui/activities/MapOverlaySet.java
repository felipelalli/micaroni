package br.eti.fml.android.sigame.ui.activities;

import android.graphics.Canvas;
import android.graphics.drawable.Drawable;
import com.google.android.maps.MapView;
import com.google.android.maps.OverlayItem;

import java.util.ArrayList;

public class MapOverlaySet extends com.google.android.maps.ItemizedOverlay {
    private ArrayList<OverlayItem> overlays = new ArrayList<OverlayItem>();
    enum Position {
        CENTER,
        CENTER_BOTTOM
    }

    public MapOverlaySet(Drawable defaultMarker, Position position) {
        super(position.equals(Position.CENTER_BOTTOM) ? boundCenterBottom(defaultMarker) : boundCenter(defaultMarker));
        populate();
    }

    public void addOverlay(OverlayItem overlay) {
        overlays.add(overlay);
        populate();
    }

    public void removeOverlay(OverlayItem overlay) {
        overlays.remove(overlay);
        populate();
    }

    @Override
    protected OverlayItem createItem(int i) {
        return overlays.get(i);
    }

    @Override
    public int size() {
        return overlays.size();
    }

    @Override
    public void draw(Canvas canvas, MapView mapView, boolean b) {
        super.draw(canvas, mapView, b);

        if (mapView.getZoomLevel() < 5) {
            mapView.getController().setZoom(5);
        } else if (mapView.getZoomLevel() > 20) {
            mapView.getController().setZoom(20);
        }
    }
}

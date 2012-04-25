package br.eti.fml.android.sigame.ui.activities;

import android.graphics.drawable.Drawable;
import com.google.android.maps.OverlayItem;

import java.util.ArrayList;

public class ItemsMap extends com.google.android.maps.ItemizedOverlay {
    private ArrayList<OverlayItem> overlays = new ArrayList<OverlayItem>();

    public ItemsMap(Drawable defaultMarker) {
        super(boundCenterBottom(defaultMarker));
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
}

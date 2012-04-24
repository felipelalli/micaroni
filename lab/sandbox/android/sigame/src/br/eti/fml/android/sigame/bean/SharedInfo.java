package br.eti.fml.android.sigame.bean;

public class SharedInfo {
    private Float lat;
    private Float lon;
    private Float accur;
    private Float battery;
    private Long last_update;
    private Boolean arrived = false;

    public Float getLat() {
        return lat;
    }

    public void setLat(Float lat) {
        this.lat = lat;
    }

    public Float getLon() {
        return lon;
    }

    public void setLon(Float lon) {
        this.lon = lon;
    }

    public Float getAccur() {
        return accur;
    }

    public void setAccur(Float accur) {
        this.accur = accur;
    }

    public Float getBattery() {
        return battery;
    }

    public void setBattery(Float battery) {
        this.battery = battery;
    }

    public Long getLast_update() {
        return last_update;
    }

    public void setLast_update(Long last_update) {
        this.last_update = last_update;
    }

    public Boolean getArrived() {
        return arrived;
    }

    public void setArrived(Boolean arrived) {
        this.arrived = arrived;
    }

    @Override
    public String toString() {
        return "SharedInfo{" +
                "lat=" + lat +
                ", lon=" + lon +
                ", accur=" + accur +
                ", battery=" + battery +
                ", last_update=" + last_update +
                ", arrived=" + arrived +
                '}';
    }
}

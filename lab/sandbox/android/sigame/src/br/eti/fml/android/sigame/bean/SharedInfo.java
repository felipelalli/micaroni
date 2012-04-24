package br.eti.fml.android.sigame.bean;

public class SharedInfo {
    private Float lat;
    private Float lon;
    private Float accur;
    private String last_provider;
    private Float battery;
    private Integer temperature = 0;
    private Long last_update;
    private Boolean arrived = false;

    public String getLast_provider() {
        return last_provider;
    }

    public void setLast_provider(String last_provider) {
        this.last_provider = last_provider;
    }

    public Integer getTemperature() {
        return temperature;
    }

    public void setTemperature(Integer temperature) {
        this.temperature = temperature;
    }

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
                "arrived=" + arrived +
                ", last_update=" + last_update +
                ", temperature=" + temperature +
                ", battery=" + battery +
                ", last_provider='" + last_provider + '\'' +
                ", accur=" + accur +
                ", lon=" + lon +
                ", lat=" + lat +
                '}';
    }
}

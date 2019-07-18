package model;

import java.io.Serializable;

public class Appliance implements Serializable {
    private String name;
    private String applianceId;
    private String deviceId;
    private Boolean state;

    public void setPower(int power) {
        this.power = power;
    }

    private int power;
    private int thumbnail;


    public Appliance() {
    }

    public Appliance(String name, String loadId, String deviceId, Boolean state, int power, int thumbnail) {
        this.name = name;
        this.state = state;
        this.power = power;
        this.thumbnail = thumbnail;
        this.applianceId = loadId;
        this.deviceId = deviceId;
    }
    public String getApplianceId() {
        return applianceId;
    }

    public void setApplianceId(String applianceId) {
        this.applianceId = applianceId;
    }

    public String getDeviceId() {
        return deviceId;
    }

    public void setDeviceId(String deviceId) {
        this.deviceId = deviceId;
    }

    public boolean getState() {
        return state;
    }

    public void setState(Boolean state) {
        this.state = state;
    }

    public int getPower() {
        return power;
    }

    public int getThumbnail() {
        return thumbnail;
    }

    public void setThumbnail(int thumbnail) {
        this.thumbnail = thumbnail;
    }

    public String getName() {
        return name;
    }

    public void setName(String name) {
        this.name = name;
    }
}

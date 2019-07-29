package model;

import java.io.Serializable;

public class Dsm implements Serializable {
    private float loadLimit;
    private boolean dsmEnable;
    private boolean updateIds;

    public Dsm(float loadLimit, boolean dsmEnable, boolean updateIds) {
        this.loadLimit = loadLimit;
        this.dsmEnable = dsmEnable;
        this.updateIds = updateIds;
    }

    public boolean isUpdateIds() {
        return updateIds;
    }

    public void setUpdateIds(boolean updateIds) {
        this.updateIds = updateIds;
    }

    public float getLoadLimit() {
        return loadLimit;
    }

    public void setLoadLimit(float loadLimit) {
        this.loadLimit = loadLimit;
    }

    public boolean isDsmEnable() {
        return dsmEnable;
    }

    public void setDsmEnable(boolean dsmEnable) {
        this.dsmEnable = dsmEnable;
    }
}

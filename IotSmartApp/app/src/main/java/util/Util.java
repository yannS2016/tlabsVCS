package util;

import com.example.iotsmartapp.R;
import com.parse.livequery.ParseLiveQueryClient;

public class Util {
    public static final int[] LOADCOVERS = new int[]{
            R.drawable.water_heater,
            R.drawable.toaster,
            R.drawable.oven_cooking,
            R.drawable.stove,
            R.drawable.electric_kettle,
            R.drawable.room_heater
    };
    public static final String DeviceID = "55560000-4644-4000-63cc-0000fdcc0000";
    // Init Live Query Client
    public static ParseLiveQueryClient parseLiveQueryClient = null;
    public static final String EXTRA_APPLIANCES = "com.example.iotsmartapp.appliances";
}

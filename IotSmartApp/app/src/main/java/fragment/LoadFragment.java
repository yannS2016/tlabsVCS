package fragment;

import android.graphics.Color;
import android.graphics.drawable.Drawable;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v4.content.ContextCompat;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;

import com.github.mikephil.charting.charts.LineChart;
import com.github.mikephil.charting.charts.PieChart;
import com.github.mikephil.charting.components.Legend;
import com.github.mikephil.charting.components.XAxis;
import com.github.mikephil.charting.components.YAxis;
import com.github.mikephil.charting.data.Entry;
import com.github.mikephil.charting.data.LineData;
import com.github.mikephil.charting.data.LineDataSet;
import com.github.mikephil.charting.data.PieData;
import com.github.mikephil.charting.data.PieDataSet;
import com.github.mikephil.charting.data.PieEntry;
import com.github.mikephil.charting.formatter.IFillFormatter;
import com.github.mikephil.charting.highlight.Highlight;
import com.github.mikephil.charting.interfaces.dataprovider.LineDataProvider;
import com.github.mikephil.charting.interfaces.datasets.ILineDataSet;
import com.github.mikephil.charting.listener.OnChartValueSelectedListener;
import com.github.mikephil.charting.utils.ColorTemplate;
import com.example.iotsmartapp.R;
import com.parse.ParseObject;
import com.parse.ParseQuery;
import com.parse.livequery.SubscriptionHandling;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import model.Appliance;
import util.Util;

import static java.lang.Thread.sleep;

public class LoadFragment extends Fragment {
    public static final String EXTRA_LOAD = "com.example.iotsmartapp.load";
    public static final String TAG = "LoadFragment";
    private ImageView athumbnail;
    private TextView  apower, aname;
    private Switch    aState;

    private Appliance load;
    private List<Appliance> appliances;
    ParseQuery<ParseObject> parseQuery;
    float samples = 0;

    // Graphics
    PieChart loadsChart;
    LineChart loadHistory;
    private Thread thread;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        load = (Appliance) getArguments().getSerializable(EXTRA_LOAD);
        appliances =  (List<Appliance>) getArguments().getSerializable(Util.EXTRA_APPLIANCES);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.appliance_details, container, false);
        if(load != null) {
            Log.i(TAG, "Got detail load " + load.getApplianceId());
        }
        athumbnail = (ImageView)v.findViewById(R.id.athumbnail);
        aState = (Switch)v.findViewById(R.id.astate);
        apower = (TextView)v.findViewById(R.id.apower);
        aname = (TextView)v.findViewById(R.id.aname);
        athumbnail.setImageResource(load.getThumbnail());
        aState.setChecked(load.getState());
        apower.setText("Power: " + load.getPower() / 10000.0f + " KW");
        aname.setText(load.getName());
        return v;
    }

    @Override
    public void onActivityCreated(@Nullable Bundle savedInstanceState) {
        super.onActivityCreated(savedInstanceState);
        // Message - Live Query

    }

    public static LoadFragment newInstance(Appliance load, List<Appliance> loads) {
        Bundle args = new Bundle();
        args.putSerializable(EXTRA_LOAD, load);
        args.putSerializable(Util.EXTRA_APPLIANCES, (Serializable) loads);
        LoadFragment fragment = new LoadFragment();
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onPause() {
        super.onPause();
        /*if (thread != null) {
            thread.interrupt();
        }*/
        Util.parseLiveQueryClient.unsubscribe(parseQuery);
    }

    @Override
    public void onDestroy() {
        //thread.interrupt();
        super.onDestroy();
    }

    @Override
    public void onStart() {
        super.onStart();
        if (Util.parseLiveQueryClient != null) {
            parseQuery = new ParseQuery("Appliances");
            parseQuery.whereEqualTo("applianceId", load.getApplianceId());
            SubscriptionHandling<ParseObject> subscriptionHandling = Util.parseLiveQueryClient.subscribe(parseQuery);
            subscriptionHandling.handleEvent(SubscriptionHandling.Event.CREATE, new SubscriptionHandling.HandleEventCallback<ParseObject>() {
                @Override
                public void onEvent(ParseQuery<ParseObject> query, final ParseObject load) {
                    Handler handler = new Handler(Looper.getMainLooper());
                    handler.post(new Runnable() {
                        public void run() {
                            Log.i("CREATE EVENT", load.getString("name"));
                        }
                    });
                }
            });
            // Update Event
            subscriptionHandling.handleEvent(SubscriptionHandling.Event.UPDATE, new SubscriptionHandling.HandleEventCallback<ParseObject>() {
                @Override
                public void onEvent(ParseQuery<ParseObject> query, final ParseObject load) {
                    Handler handler = new Handler(Looper.getMainLooper());
                    handler.post(new Runnable() {
                        public void run() {

                            aState.setChecked(load.getBoolean("state"));
                            apower.setText("Power: " + load.getInt("power") / 10000.0f + " KW");
                            samples = load.getInt("power") / 10000.0f;

                            /*for (int i = 0; i < appliances.size(); i++) {
                                Appliance  appliance = appliances.get(i);
                                if (appliance.getApplianceId().equals(load.getString("applianceId"))) {
                                    appliance.setPower(load.getInt("power"));
                                }
                            }
                            Util.adapter.notifyDataSetChanged();
                           // updatePie();*/
                        }
                    });
                }
            });
        }
    }
}

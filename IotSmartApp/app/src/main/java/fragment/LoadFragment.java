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
import android.widget.CompoundButton;
import android.widget.ImageView;
import android.widget.Switch;
import android.widget.TextView;

import com.github.mikephil.charting.charts.LineChart;
import com.github.mikephil.charting.charts.PieChart;
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
import com.parse.FindCallback;
import com.parse.GetCallback;
import com.parse.ParseException;
import com.parse.ParseObject;
import com.parse.ParseQuery;
import com.parse.livequery.SubscriptionHandling;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.List;

import it.beppi.knoblibrary.Knob;
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
    private volatile float loadPower = 0;

    // Graphics
    PieChart loadsChart = null;
    LineChart loadHistory = null;
    PieDataSet pieDataSet = null;
    PieData pieData = null;
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
        float power = load.getPower() / 1000.0f;
        apower.setText("Power: " + power + " KW");
        aname.setText(load.getName());
        // listens to priority changed events
        Knob apriority = (Knob) v.findViewById(R.id.priority);
        apriority.setState(1, true);
        apriority.setOnStateChanged(new Knob.OnStateChanged() {
            @Override
            public void onState(final int state) {
                // update local object object
                // update parse object: use cloud functions
                Log.i(TAG, "Priority value " + state);
                // Get appliances from parse
                ParseQuery<ParseObject> loadQuery = ParseQuery.getQuery("Appliances");
                loadQuery.whereEqualTo("applianceId", load.getApplianceId());
                loadQuery.getFirstInBackground(new GetCallback<ParseObject>() {
                    @Override
                    public void done(ParseObject object, ParseException e) {
                        if(e == null) {
                            object.put("priority", state);
                            object.saveInBackground();
                        } else {
                            Log.e("FindInBackground", e.toString());
                        }
                    }
                });
            }
        });
        aState.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, final boolean isChecked) {
                // Get appliances from parse
                ParseQuery<ParseObject> loadQuery = ParseQuery.getQuery("Appliances");
                loadQuery.whereEqualTo("applianceId", load.getApplianceId());
                loadQuery.getFirstInBackground(new GetCallback<ParseObject>() {
                    @Override
                    public void done(ParseObject object, ParseException e) {
                        if(e == null) {
                            object.put("state", isChecked);
                            object.saveInBackground();
                        } else {
                            Log.e("FindInBackground", e.toString());
                        }
                    }
                });
            }
        });
        // handle Pie chart of appliances consumption
        loadsChart = (PieChart)v.findViewById(R.id.loadsChart);
        loadsChart.setUsePercentValues(true);

        loadsChart.getDescription().setEnabled(false);
        loadsChart.setExtraOffsets(1, 5, 1,1);
        loadsChart.setDragDecelerationFrictionCoef(0.95f);
        loadsChart.setDrawHoleEnabled(true);
        loadsChart.setHoleColor(Color.WHITE);
        loadsChart.setHoleRadius(25f);
        loadsChart.setTransparentCircleRadius(30f);
        initPie();
        ///////////////////////////////////////////////
        // Line chart for historical data
        loadHistory = (LineChart) v.findViewById(R.id.loadHistory);
        loadHistory.setOnChartValueSelectedListener(new OnChartValueSelectedListener() {
            @Override
            public void onValueSelected(Entry e, Highlight h) {

            }

            @Override
            public void onNothingSelected() {

            }
        });
        // enable description text
        loadHistory.getDescription().setEnabled(false);

        // enable touch gestures
        loadHistory.setTouchEnabled(true);

        // enable scaling and dragging

        loadHistory.setScaleEnabled(true);

        // if disabled, scaling can be done on x- and y-axis separately
        loadHistory.setPinchZoom(true);

        // set an alternative background color
        loadHistory.setBackgroundColor(Color.WHITE);


        XAxis xl = loadHistory.getXAxis();
        {
            // vertical grid lines
            xl.enableGridDashedLine(10f, 10f, 0f);
            xl.setTextColor(Color.WHITE);
            xl.setDrawGridLines(true);
            xl.setAvoidFirstLastClipping(true);
            xl.setEnabled(true);
        }
        YAxis leftAxis = loadHistory.getAxisLeft();
        {
            // horizontal grid lines
            leftAxis.enableGridDashedLine(10f, 10f, 0f);

            // disable dual axis (only use LEFT axis)
            loadHistory.getAxisRight().setEnabled(false);
            // horizontal grid lines
            leftAxis.enableGridDashedLine(10f, 10f, 0f);
            leftAxis.setTextColor(Color.BLACK);
            leftAxis.setAxisMaximum(5f);
            leftAxis.setAxisMinimum(0f);
            leftAxis.setDrawGridLines(true);
        }
        LineData ldata = new LineData();
        // add empty data
        loadHistory.setData(ldata);
        // int historigram
        loadPower = power;
        addEntry();
        return v;
    }
    private void addEntry() {

        LineData data = loadHistory.getData();

        if (data != null) {

            ILineDataSet set = data.getDataSetByIndex(0);
            // set.addEntry(...); // can be called as well

            if (set == null) {
                set = createSet();
                data.addDataSet(set);
            }

            data.addEntry(new Entry(set.getEntryCount(), loadPower), 0);
            data.notifyDataChanged();

            // let the chart know it's data has changed
            loadHistory.notifyDataSetChanged();

            // limit the number of visible entries
            loadHistory.setVisibleXRangeMaximum(120);
            // chart.setVisibleYRange(30, AxisDependency.LEFT);

            // move to the latest entry
            loadHistory.moveViewToX(data.getEntryCount());

            // this automatically refreshes the chart (calls invalidate())
            // chart.moveViewTo(data.getXValCount()-7, 55f,
            // AxisDependency.LEFT);
        }
    }
    private LineDataSet createSet() {

        LineDataSet set = new LineDataSet(null, load.getName() + " consumption");
        set.setAxisDependency(YAxis.AxisDependency.LEFT);
        set.setColor(ColorTemplate.getHoloBlue());

        set.setLineWidth(2f);
        set.setFillAlpha(65);
        set.setFillColor(ColorTemplate.getHoloBlue());
        set.setHighLightColor(Color.rgb(244, 117, 117));
        //set.setValueTextColor(Color.WHITE);
        set.setValueTextSize(9f);
        set.setDrawValues(false);
        set.setDrawCircles(false);

        // set the filled area
        set.setDrawFilled(true);
        set.setFillFormatter(new IFillFormatter() {
            @Override
            public float getFillLinePosition(ILineDataSet dataSet, LineDataProvider dataProvider) {
                return loadHistory.getAxisLeft().getAxisMinimum();
            }
        });
        // drawables only supported on api level 18 and above
        Drawable drawable = ContextCompat.getDrawable(getActivity(), R.drawable.fade_red);
        set.setFillDrawable(drawable);
        return set;
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

        if (thread != null) {
            thread.interrupt();
            Log.i(TAG, "onPause: interrupting thread object");
        }
        Util.parseLiveQueryClient.unsubscribe(parseQuery);
        // stop history thread
        Util.LOADHISTORY = false;
        super.onPause();
    }

    @Override
    public void onDestroy() {
        thread.interrupt();
        // stop history thread
        Util.LOADHISTORY = false;
        Log.i(TAG, "onDetroy: interrupting thread object");
        super.onDestroy();
    }

    @Override
    public void onStart() {
        super.onStart();
        // stop history thread
        Util.LOADHISTORY = true;
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
                            Boolean state = load.getBoolean("state");
                            int power = load.getInt("power");
                            String applianceId = load.getString("applianceId");
                            aState.setChecked(state);
                            apower.setText("Power: " + load.getInt("power") / 1000.0f + " KW");
                            loadPower = load.getInt("power") / 1000.0f;

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
        feedMultiple();
    }

    private void initPie(){

        ArrayList<PieEntry> yValues = new ArrayList<>();
        for(int i =0; i < appliances.size(); i++){
            Appliance load = appliances.get(i);
            if(load != null) {
                yValues.add(new PieEntry(load.getPower(), load.getName()));
            }
        }
        pieDataSet = new PieDataSet(yValues, "");
        pieDataSet.setSliceSpace(2f);
        pieDataSet.setSelectionShift(2f);
        pieDataSet.setColors(ColorTemplate.MATERIAL_COLORS);


        pieData = new PieData(pieDataSet);
        pieData.setValueTextSize(10f);
        pieData.setValueTextColor(Color.YELLOW);
        loadsChart.setData(pieData);

    }

    private void feedMultiple() {

        if (thread != null)
            thread.interrupt();

        final Runnable runnable = new Runnable() {

            @Override
            public void run() {
                addEntry();
            }
        };

        thread = new Thread(new Runnable() {

            @Override
            public void run() {
                while(true) {

                    // Don't generate garbage runnables inside the loop.

                    Log.i(TAG, "Running load thread");
                    if(!Util.LOADHISTORY) {
                        Log.i(TAG, "Exiting load thread");
                        return;
                    }
                    getActivity().runOnUiThread(runnable);
                    try {
                        Thread.sleep(100);
                    } catch (InterruptedException e) {
                        e.printStackTrace();
                    }
                }
            }
        });
        thread.start();
    }
}

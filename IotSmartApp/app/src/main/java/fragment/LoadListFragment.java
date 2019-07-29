package fragment;

import android.app.Activity;
import android.content.Context;
import android.content.Intent;
import android.content.res.Resources;
import android.graphics.Color;
import android.graphics.Rect;
import android.graphics.drawable.Drawable;
import android.net.Uri;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.design.widget.Snackbar;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v4.content.ContextCompat;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.GridLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.Menu;
import android.view.MenuInflater;
import android.view.MenuItem;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Toast;

import com.example.iotsmartapp.R;
import com.github.mikephil.charting.charts.LineChart;
import com.github.mikephil.charting.components.Legend;
import com.github.mikephil.charting.components.XAxis;
import com.github.mikephil.charting.components.YAxis;
import com.github.mikephil.charting.data.Entry;
import com.github.mikephil.charting.data.LineData;
import com.github.mikephil.charting.data.LineDataSet;
import com.github.mikephil.charting.formatter.IFillFormatter;
import com.github.mikephil.charting.formatter.ValueFormatter;
import com.github.mikephil.charting.highlight.Highlight;
import com.github.mikephil.charting.interfaces.dataprovider.LineDataProvider;
import com.github.mikephil.charting.interfaces.datasets.ILineDataSet;
import com.github.mikephil.charting.listener.OnChartValueSelectedListener;
import com.github.mikephil.charting.utils.ColorTemplate;
import com.parse.FindCallback;
import com.parse.FunctionCallback;
import com.parse.GetCallback;
import com.parse.Parse;
import com.parse.ParseCloud;
import com.parse.ParseException;
import com.parse.ParseObject;
import com.parse.ParseQuery;
import com.parse.ParseUser;
import com.parse.livequery.ParseLiveQueryClient;
import com.parse.livequery.SubscriptionHandling;

import java.net.URI;
import java.net.URISyntaxException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Date;
import java.util.HashMap;
import java.util.List;
import java.util.Locale;
import java.util.Map;
import java.util.concurrent.TimeUnit;

import data.ApplianceAdapter;
import model.Appliance;
import model.Dsm;
import util.Util;

import static com.parse.Parse.getApplicationContext;


public class LoadListFragment extends Fragment {
    private RecyclerView recyclerView;
    private ApplianceAdapter adapter;
    private LineChart loadConsumption;

    private static final String TAG = "LoadListFragment";
    private static  final int REQUEST_DSM = 0;
    public static final String DIALOG_DSM = "dsm";
    private List<Appliance> appliances = new ArrayList<>();
    private Callbacks mCallbacks;
    ParseQuery<ParseObject> parseQuery = null;
    private Thread thread;
    private Dsm dsm;
    /*
     * Require interface for hosting activities
     * */
    public interface Callbacks {
        void onApplianceSelected(Appliance appliance, List<Appliance> loads);
    }
    // because the main activity will implement the interface its
    // reference can be store within an instance of the interface
    // by casting it to that of the interface
    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        mCallbacks = (Callbacks) context;

    }
    // release the parent activity reference as the
    // fragment object no longer needs it at this point
    @Override
    public void onDetach() {
        super.onDetach();
        mCallbacks = null;
    }

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        // let the fragment manager know that this fragment needs to receive menu
        // creation callback
        setHasOptionsMenu(true);

        adapter = new ApplianceAdapter(getActivity(), appliances);

        try {
            Util.parseLiveQueryClient = ParseLiveQueryClient.Factory.getClient(new URI(getString(R.string.back4app_livequery_url)));
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }
        Log.i("LoadListFragment", "onCreate running");
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.appliances_fragment, container, false);
        recyclerView = (RecyclerView)v.findViewById(R.id.recycler_view);
        RecyclerView.LayoutManager mLayoutManager = new GridLayoutManager(getActivity(), 2);
        recyclerView.setLayoutManager(mLayoutManager);
        recyclerView.addItemDecoration(new Util.GridSpacingItemDecoration(2, Util.dpToPx(10, getActivity()), true));
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        recyclerView.setAdapter(adapter);

        prepareAppliances();
        loadConsumption = v.findViewById(R.id.totalConsumption);
        ///////////////////////////////////////////////
        // Line chart for historical data

        loadConsumption.setOnChartValueSelectedListener(new OnChartValueSelectedListener() {
            @Override
            public void onValueSelected(Entry e, Highlight h) {

            }

            @Override
            public void onNothingSelected() {

            }
        });
        // enable description text
        loadConsumption.getDescription().setEnabled(false);

        // enable touch gestures
        loadConsumption.setTouchEnabled(true);

        // enable scaling and dragging

        loadConsumption.setScaleEnabled(true);

        // if disabled, scaling can be done on x- and y-axis separately
        loadConsumption.setPinchZoom(true);

        // set an alternative background color
        loadConsumption.setBackgroundColor(Color.WHITE);


        XAxis xAxis = loadConsumption.getXAxis();
        {
            xAxis.setPosition(XAxis.XAxisPosition.TOP);
            // vertical grid lines
            xAxis.enableGridDashedLine(10f, 10f, 0f);
            xAxis.setTextColor(Color.rgb(255, 192, 56));
            xAxis.setCenterAxisLabels(true);
            xAxis.setTextSize(8f);
            xAxis.setDrawGridLines(true);
            xAxis.setAvoidFirstLastClipping(true);
            xAxis.setEnabled(true);
            xAxis.setValueFormatter(new ValueFormatter() {

                private final SimpleDateFormat mFormat = new SimpleDateFormat("dd MMM HH:mm", Locale.ENGLISH);

                @Override
                public String getFormattedValue(float value) {

                    long millis = TimeUnit.SECONDS.toMillis((long) value);
                    return mFormat.format(new Date());
                }
            });
        }
        YAxis leftAxis = loadConsumption.getAxisLeft();
        {
            // horizontal grid lines
            leftAxis.enableGridDashedLine(10f, 10f, 0f);

            // disable dual axis (only use LEFT axis)
            loadConsumption.getAxisRight().setEnabled(false);
            // horizontal grid lines
            leftAxis.enableGridDashedLine(10f, 10f, 0f);
            leftAxis.setTextColor(Color.rgb(255, 192, 56));
            leftAxis.setAxisMaximum(5f);
            leftAxis.setAxisMinimum(0f);
            leftAxis.setDrawGridLines(true);
        }
        LineData ldata = new LineData();
        // add empty data
        loadConsumption.setData(ldata);
        // int historigram
        Log.i("onViewCreate", String.valueOf(appliances.size()));

        return v;
    }
    @Override
    public void onViewCreated(@NonNull View view, @Nullable Bundle savedInstanceState) {
        super.onViewCreated(view, savedInstanceState);
        Log.i("OnViewCreated", String.valueOf(appliances.size()));
        // Get appliances from parse
        ParseQuery<ParseObject> appliancesQuery = ParseQuery.getQuery("Appliances");
        appliancesQuery.findInBackground(new FindCallback<ParseObject>() {
            @Override
            public void done(List<ParseObject> loads, ParseException e) {
                if(e == null) {
                    Log.i("FindInBackground", "Retrieved " + loads.size() + " appliances");
                    if(loads.size() > 0){
                        for(ParseObject appliance: loads) {
                            for(int i = 0; i < appliances.size(); i++){
                                Appliance load = appliances.get(i);
                                //Log.i("FindInBackground", "Appliance id " + load.getApplianceId());
                                if((appliance.getString("applianceId").equals(load.getApplianceId()))) {
                                    load.setDeviceId(appliance.getString("deviceId"));
                                    load.setState(appliance.getBoolean("state"));
                                    load.setPower(appliance.getInt("power"));
                                }
                            }
                        }
                        Log.i("List size is: ", String.valueOf(appliances.size()));
                        adapter.notifyDataSetChanged();
                    }
                }
                else {
                    Log.e("FindInBackground", e.toString());
                }
            }
        });
    }

    @Override
    public void onStart() {
        super.onStart();
        if(adapter != null) {
            Log.i(TAG, "Getting the interface");
            adapter.setInterface(mCallbacks);
        }
        Util.CONSUMPTIONHISTORY = true;
        // Message - Live Query
        if (Util.parseLiveQueryClient != null) {
            parseQuery = new ParseQuery("Appliances");
            SubscriptionHandling<ParseObject> subscriptionHandling = Util.parseLiveQueryClient.subscribe(parseQuery);
            subscriptionHandling.handleEvent(SubscriptionHandling.Event.UPDATE, new SubscriptionHandling.HandleEventCallback<ParseObject>() {
                @Override
                public void onEvent(ParseQuery<ParseObject> query, final ParseObject load) {
                    Handler handler = new Handler(Looper.getMainLooper());
                    handler.post(new Runnable() {
                        public void run() {
                            Log.i("CREATE EVENT", load.getString("name"));
                            for(int i = 0; i < appliances.size(); i++){
                                Appliance app = appliances.get(i);
                                if(app.getApplianceId().equals(load.getString("applianceId"))){
                                    app.setState(load.getBoolean("state"));
                                    app.setPower(load.getInt("power"));
                                    adapter.notifyDataSetChanged();
                                }
                            }
                        }
                    });
                }
            });
        }
        // Run parse cloud code to create a dsm object
        HashMap<String, Object> params = new HashMap<String, Object>();
        params.put("ids", "updateId");
        params.put("dsm", "dsmState");
        params.put("threshold", "threshold");
        ParseCloud.callFunctionInBackground("dsm_configs", params, new FunctionCallback<Map<String, Object>>() {
            public void done(Map<String, Object> dsmConfigs, ParseException e) {
                if (e == null) {
                    dsm = new Dsm((int) dsmConfigs.get("threshold"), (boolean)dsmConfigs.get("dsmState"), (boolean)dsmConfigs.get("updateId"));
                    Toast.makeText(getActivity(), "DSM Enable: " + dsm.isDsmEnable(), Toast.LENGTH_LONG).show();
                } else {
                    Toast.makeText(getActivity(), e.toString(), Toast.LENGTH_LONG).show();
                }
            }
        });
        feedMultiple();
    }
    @Override
    public void onCreateOptionsMenu(Menu menu, MenuInflater inflater) {
        // Inflate the menu; this adds items to the action bar if it is present.
        inflater.inflate(R.menu.main, menu);

    }

    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        // Handle action bar item clicks here. The action bar will
        // automatically handle clicks on the Home/Up button, so long
        // as you specify a parent activity in AndroidManifest.xml.

        switch(item.getItemId()){
            case R.id.action_settings:
                // create a dialog fragment here( DatePickerFragment)
                FragmentManager fm = getActivity().getSupportFragmentManager();
                SettingFragment settingFragment = SettingFragment.newInstance(dsm);
                // contact back the calling fragment( CrimeFragment when done)
                settingFragment.setTargetFragment(LoadListFragment.this, REQUEST_DSM);
                settingFragment.show(fm, DIALOG_DSM);
                return true;
            case R.id.action_add:
                return true;
            default:
                return super.onOptionsItemSelected(item);
        }
    }
    @Override
    public void onActivityResult(int requestCode, int resultCode, Intent data) {
        // make sure the child fragment did not return an error msg
        if(resultCode != Activity.RESULT_OK) return;
        // this how the child activity that sent the result is identified
        // we know we are ending the com with the DatePickerFragment
        if(requestCode == REQUEST_DSM) {
            final Dsm dsm =  (Dsm)(data.getSerializableExtra(SettingFragment.EXTRA_DSM));
            Log.i(TAG, "Settings: Load " + dsm.getLoadLimit() +" updateIds " + dsm.isUpdateIds() + " dsm " + dsm.isDsmEnable());
            // Get appliances from parse
            ParseQuery<ParseObject> smartControlsQuery = ParseQuery.getQuery("smartControls");
            smartControlsQuery.findInBackground(new FindCallback<ParseObject>() {
                @Override
                public void done(List<ParseObject> objects, ParseException e) {
                    if (e == null) {
                        for(ParseObject control : objects)
                            if (control.getString("name").equals("updateId")) {
                                Log.i(TAG, "Control " + control.getString("name") + " " + dsm.isUpdateIds());
                                control.put("state", dsm.isUpdateIds());
                                control.saveInBackground();
                            } else {
                                control.put("state", dsm.isDsmEnable());
                                Log.i(TAG, "Control " + control.getString("name") + " " + dsm.isDsmEnable());
                                control.saveInBackground();
                            }
                    } else {
                        Log.d("score", "Error: " + e.getMessage());
                    }
                }
            });

            // Get appliances from parse
            ParseQuery<ParseObject> loadQuery = ParseQuery.getQuery("DsmConfigs");
            loadQuery.whereEqualTo("name", "threshold");
            loadQuery.getFirstInBackground(new GetCallback<ParseObject>() {
                @Override
                public void done(ParseObject object, ParseException e) {
                    if(e == null) {
                        object.put("value", dsm.getLoadLimit());
                        object.saveInBackground();
                    } else {
                        Toast.makeText(getActivity(), "Power limit set to: ", Toast.LENGTH_LONG).show();
                    }
                }
            });
        }
    }

    private void prepareAppliances() {

        if(ParseUser.getCurrentUser() != null){
            appliances.clear();
            Appliance a = new Appliance("Geyser","btr1-geyser",
                    Util.DeviceID, false, 0, Util.LOADCOVERS[0]);
            appliances.add(a);

            a = new Appliance("Toaster","ktn-toaster",
                    Util.DeviceID, false, 0, Util.LOADCOVERS[1]);
            appliances.add(a);

            a = new Appliance("Oven","ktn-oven",
                    Util.DeviceID, false, 0, Util.LOADCOVERS[2]);
            appliances.add(a);

            a = new Appliance("stove","ktn-stove",
                    Util.DeviceID, false, 0, Util.LOADCOVERS[3]);
            appliances.add(a);

            a = new Appliance("Kettle","ktn-kettle",
                    Util.DeviceID, false, 0, Util.LOADCOVERS[4]);
            appliances.add(a);

            a = new Appliance("heater","bdr1-heater",
                    Util.DeviceID, false, 0, Util.LOADCOVERS[5]);
            appliances.add(a);

            adapter.notifyDataSetChanged();
        }

    }
    public static LoadListFragment newInstance() {
        Bundle args = new Bundle();
        LoadListFragment fragment = new LoadListFragment();
        fragment.setArguments(args);
        return fragment;
    }

    @Override
    public void onPause() {
        super.onPause();
        if (thread != null) {
            thread.interrupt();
            Util.CONSUMPTIONHISTORY = false;
            Log.i(TAG, "onPause: interrupting thread object");
        }
        Util.parseLiveQueryClient.unsubscribe(parseQuery);
    }

    @Override
    public void onDestroy() {
        if (thread != null) {
            thread.interrupt();
            Util.CONSUMPTIONHISTORY = false;
            Log.i(TAG, "onDestroy: interrupting thread object");
        }
        super.onDestroy();
    }

    private void addEntry() {

        LineData data = loadConsumption.getData();

        if (data != null) {

            ILineDataSet set = data.getDataSetByIndex(0);
            // set.addEntry(...); // can be called as well

            if (set == null) {
                set = createSet();
                data.addDataSet(set);
            }
            // calculate total consumption
            float totalLoad = 0.0f;
            for(int i = 0 ; i < appliances.size(); i++){
                totalLoad+=(float)appliances.get(i).getPower() / 1000.0f;
            }
            data.addEntry(new Entry(set.getEntryCount(), totalLoad), 0);
            data.notifyDataChanged();

            // let the chart know it's data has changed
            loadConsumption.notifyDataSetChanged();

            // limit the number of visible entries
            loadConsumption.setVisibleXRangeMaximum(120);
            // chart.setVisibleYRange(30, AxisDependency.LEFT);

            // move to the latest entry
            loadConsumption.moveViewToX(data.getEntryCount());

            // this automatically refreshes the chart (calls invalidate())
            // chart.moveViewTo(data.getXValCount()-7, 55f,
            // AxisDependency.LEFT);
        }
    }
    private LineDataSet createSet() {

        LineDataSet set = new LineDataSet(null, "consumption");
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
                return loadConsumption.getAxisLeft().getAxisMinimum();
            }
        });
        // drawables only supported on api level 18 and above
        Drawable drawable = ContextCompat.getDrawable(getActivity(), R.drawable.fade_red);
        set.setFillDrawable(drawable);
        return set;
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
                    //Log.i(TAG, "Running load thread");
                    if(!Util.CONSUMPTIONHISTORY) {
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

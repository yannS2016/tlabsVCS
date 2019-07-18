package fragment;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Rect;
import android.os.Bundle;
import android.os.Handler;
import android.os.Looper;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.support.v7.widget.DefaultItemAnimator;
import android.support.v7.widget.GridLayoutManager;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.util.TypedValue;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;

import com.example.iotsmartapp.R;
import com.parse.FindCallback;
import com.parse.ParseException;
import com.parse.ParseObject;
import com.parse.ParseQuery;
import com.parse.ParseUser;
import com.parse.livequery.ParseLiveQueryClient;
import com.parse.livequery.SubscriptionHandling;

import java.net.URI;
import java.net.URISyntaxException;
import java.util.ArrayList;
import java.util.List;

import data.ApplianceAdapter;
import model.Appliance;
import util.Util;


public class LoadListFragment extends Fragment {
    private RecyclerView recyclerView;
    private ApplianceAdapter adapter;

    private static final String TAG = "LoadListFragment";
    private List<Appliance> appliances = new ArrayList<>();
    private Callbacks mCallbacks;
    ParseQuery<ParseObject> parseQuery = null;

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

        adapter = new ApplianceAdapter(getActivity(), appliances);

        try {
            Util.parseLiveQueryClient = ParseLiveQueryClient.Factory.getClient(new URI(getString(R.string.back4app_livequery_url)));
        } catch (URISyntaxException e) {
            e.printStackTrace();
        }
        Log.i("LoadListFragment", "onCreate running");
    }


    @Override
    public void onStart() {
        super.onStart();
        if(adapter != null) {
            Log.i(TAG, "Getting the interface");
            adapter.setInterface(mCallbacks);
        }
        Util.parseLiveQueryClient.subscribe(parseQuery);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {
        View v = inflater.inflate(R.layout.appliances_fragment, container, false);
        recyclerView = (RecyclerView) v.findViewById(R.id.recycler_view);
        RecyclerView.LayoutManager mLayoutManager = new GridLayoutManager(getActivity(), 2);
        recyclerView.setLayoutManager(mLayoutManager);
        recyclerView.addItemDecoration(new GridSpacingItemDecoration(2, dpToPx(10), true));
        recyclerView.setItemAnimator(new DefaultItemAnimator());
        recyclerView.setAdapter(adapter);

        prepareAppliances();

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
    }

    /**
     * RecyclerView item decoration - give equal margin around grid item
     */
    public class GridSpacingItemDecoration extends RecyclerView.ItemDecoration {

        private int spanCount;
        private int spacing;
        private boolean includeEdge;

        public GridSpacingItemDecoration(int spanCount, int spacing, boolean includeEdge) {
            this.spanCount = spanCount;
            this.spacing = spacing;
            this.includeEdge = includeEdge;
        }

        @Override
        public void getItemOffsets(Rect outRect, View view, RecyclerView parent, RecyclerView.State state) {
            int position = parent.getChildAdapterPosition(view); // item position
            int column = position % spanCount; // item column

            if (includeEdge) {
                outRect.left = spacing - column * spacing / spanCount; // spacing - column * ((1f / spanCount) * spacing)
                outRect.right = (column + 1) * spacing / spanCount; // (column + 1) * ((1f / spanCount) * spacing)

                if (position < spanCount) { // top edge
                    outRect.top = spacing;
                }
                outRect.bottom = spacing; // item bottom
            } else {
                outRect.left = column * spacing / spanCount; // column * ((1f / spanCount) * spacing)
                outRect.right = spacing - (column + 1) * spacing / spanCount; // spacing - (column + 1) * ((1f /    spanCount) * spacing)
                if (position >= spanCount) {
                    outRect.top = spacing; // item top
                }
            }
        }
    }

    /**
     * Converting dp to pixel
     */
    private int dpToPx(int dp) {
        Resources r = getResources();
        return Math.round(TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp, r.getDisplayMetrics()));
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
        Util.parseLiveQueryClient.unsubscribe(parseQuery);
    }
}

package fragment;

import android.app.Activity;
import android.app.AlertDialog;
import android.app.Dialog;
import android.content.DialogInterface;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.design.widget.Snackbar;
import android.support.v4.app.DialogFragment;
import android.support.v4.app.Fragment;
import android.util.Log;
import android.view.View;
import android.widget.CompoundButton;
import android.widget.DatePicker;
import android.widget.Switch;

import com.example.iotsmartapp.R;
import com.parse.GetCallback;
import com.parse.ParseException;
import com.parse.ParseObject;
import com.parse.ParseQuery;

import java.util.Calendar;
import java.util.Date;
import java.util.GregorianCalendar;

import it.beppi.knoblibrary.Knob;
import model.Dsm;

public class SettingFragment extends DialogFragment {
    public static final String EXTRA_DSM = "com.example.iotsmartapp.dsm";
    private String TAG = "SettingFragment";
    private Dsm mDsm;
    // this used to start this fragment from another context( fragment or activity)
    // and pass data from that context to the fragment
    @NonNull
    public Dialog onCreateDialog(@Nullable Bundle savedInstanceState) {
        mDsm = (Dsm)getArguments().getSerializable(EXTRA_DSM);

        // Create the Calendar to get the Year, month, and  day

        final View v = getActivity().getLayoutInflater()
                .inflate(R.layout.appliance_settings, null); // build the fragment view out of XML
        Switch dsmState = (Switch)v.findViewById(R.id.dsm);
        dsmState.setChecked(mDsm.isDsmEnable());
        dsmState.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked){
                    Snackbar.make(v, "Demand side management activated", Snackbar.LENGTH_LONG)
                            .setAction("Action", null).show();
                }else {
                    Snackbar.make(v, "Demand side management deactivated", Snackbar.LENGTH_LONG)
                            .setAction("Action", null).show();
                }
                mDsm.setDsmEnable(isChecked);
            }
        });
        Switch updateIds = (Switch)v.findViewById(R.id.updateIds);
        updateIds.setChecked(mDsm.isUpdateIds());
        updateIds.setOnCheckedChangeListener(new CompoundButton.OnCheckedChangeListener() {
            @Override
            public void onCheckedChanged(CompoundButton buttonView, boolean isChecked) {
                if(isChecked) {
                    Snackbar.make(v, "Reset appliance Ids", Snackbar.LENGTH_LONG)
                            .setAction("Action", null).show();
                }
                mDsm.setUpdateIds(isChecked);
            }
        });
        // listens to priority changed events
        Knob threshold = (Knob) v.findViewById(R.id.threshold);
        threshold.setState((int) (mDsm.getLoadLimit() / 1000.0), true);
        threshold.setOnStateChanged(new Knob.OnStateChanged() {
            @Override
            public void onState(final int state) {
                // update local object object
                // update parse object: use cloud functions
                Snackbar.make(v, "Power limit set to: " + (state * 1000.0f) + " Watts", Snackbar.LENGTH_LONG)
                        .setAction("Action", null).show();
                mDsm.setLoadLimit(state * 1000.0f);
            }
        });
        // intent and argument communication is ahdled by OS, thus
        // there nopt lost with activity lifecycle or device configuration change(rotating
        // the screen) but they need to be updated in case any of the above occurrs
        getArguments().putSerializable(EXTRA_DSM, mDsm);
        // when user is done updating the date we need to send the result to the parent fragment
        return new AlertDialog.Builder(getActivity())
                .setView(v)
                .setTitle(R.string.setting_name)
                .setPositiveButton(android.R.string.ok, new DialogInterface.OnClickListener() {
                    @Override
                    public void onClick(DialogInterface dialog, int which) {
                        sendResult(Activity.RESULT_OK); // the result code let the calling f how it all went
                    }
                })
                .create();
    }
    public static SettingFragment newInstance(Dsm dsm) {

        Bundle args = new Bundle();
        args.putSerializable(EXTRA_DSM, dsm);
        SettingFragment fragment = new SettingFragment();
        fragment.setArguments(args);
        return fragment;
    }

    private void sendResult(int resultCode){
        if(getTargetFragment() == null)
            return;
        Intent i = new Intent();
        i.putExtra(EXTRA_DSM, mDsm);
        // call the targeted fragment onActivityResult method to catch the return fragment results
        // the corresponding target fragment is identified by the target request code
        // which thus identifies the parent fragment: we need to override the onActivityResult
        // of the target fragment to catch this result
        getTargetFragment().onActivityResult(getTargetRequestCode(), resultCode, i);
    }
}

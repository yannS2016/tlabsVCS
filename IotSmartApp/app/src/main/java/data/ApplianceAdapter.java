package data;

import android.content.Context;
import android.support.annotation.NonNull;
import android.support.v7.widget.RecyclerView;
import android.util.Log;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.ImageView;
import android.widget.TextView;

import com.bumptech.glide.Glide;
import com.example.iotsmartapp.R;

import java.util.List;

import fragment.LoadListFragment;
import model.Appliance;

public class ApplianceAdapter extends  RecyclerView.Adapter<ApplianceAdapter.AppliancesHolder>{

    private Context mContext;
    private List<Appliance> applianceList;
    private LoadListFragment.Callbacks mCallbacks;

    public ApplianceAdapter(Context context, List<Appliance> appliances){
        this.mContext = context;
        this.applianceList = appliances;
    }

    public void setInterface(LoadListFragment.Callbacks callbacks){
        this.mCallbacks = callbacks;
    }

    @NonNull
    @Override
    public AppliancesHolder onCreateViewHolder(@NonNull ViewGroup viewGroup, int i) {
        View view = LayoutInflater.from(viewGroup.getContext()).inflate(R.layout.appliance_card, viewGroup, false);

        return new AppliancesHolder(view);
    }

    @Override
    public void onBindViewHolder(@NonNull AppliancesHolder appliancesHolder, int position) {
        Appliance appliance = applianceList.get(position);
        appliancesHolder.name.setText(appliance.getName());
        appliancesHolder.state.setText("State: " + appliance.getState());
        appliancesHolder.power.setText("Power: " + appliance.getPower() + "W");

        // loading album cover using Glide library
        Glide.with(mContext).load(appliance.getThumbnail()).into(appliancesHolder.thumbnail);
        appliancesHolder.overflow.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View view) {
                Log.i("Adapter", "Hello from overflow");
            }
        });

    }

    @Override
    public int getItemCount() {
        return applianceList.size();
    }

    public class  AppliancesHolder extends RecyclerView.ViewHolder implements View.OnClickListener {

        public TextView name, power, state;
        public ImageView thumbnail, overflow;

        public AppliancesHolder(@NonNull View itemView) {

            super(itemView);
            itemView.setOnClickListener(this);
            name = (TextView)itemView.findViewById(R.id.name);
            power = (TextView) itemView.findViewById(R.id.power);
            state = (TextView) itemView.findViewById(R.id.state);
            thumbnail = (ImageView) itemView.findViewById(R.id.thumbnail);
            overflow = (ImageView) itemView.findViewById(R.id.overflow);

        }

        @Override
        public void onClick(View v) {
            int position = getAdapterPosition();
            mCallbacks.onApplianceSelected(applianceList.get(position), applianceList);
        }
    }
}

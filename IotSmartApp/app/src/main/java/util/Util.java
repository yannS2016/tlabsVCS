package util;

import android.content.Context;
import android.content.res.Resources;
import android.graphics.Rect;
import android.support.v7.widget.RecyclerView;
import android.util.TypedValue;
import android.view.View;

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
    public static volatile boolean LOADHISTORY = true;
    public static volatile boolean CONSUMPTIONHISTORY= true;
    public static int LOADLIMIT = 0;
    public static boolean DSMSTATE = false;

    /**
     * RecyclerView item decoration - give equal margin around grid item
     */
    public static class GridSpacingItemDecoration extends RecyclerView.ItemDecoration {

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
    public static int dpToPx(int dp, Context context) {
        Resources r = context.getResources();
        return Math.round(TypedValue.applyDimension(TypedValue.COMPLEX_UNIT_DIP, dp, r.getDisplayMetrics()));
    }
}

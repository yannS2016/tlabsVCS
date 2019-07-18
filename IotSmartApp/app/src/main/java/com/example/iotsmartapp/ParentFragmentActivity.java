package com.example.iotsmartapp;

import android.os.Bundle;
import android.support.v4.app.Fragment;
import android.support.v4.app.FragmentManager;
import android.support.v7.app.AppCompatActivity;

public abstract class ParentFragmentActivity extends AppCompatActivity {
    // an abstract method that return a fragment need
    // to be implemented by subclass of singleFragmentActivity;
    protected abstract Fragment createFragment();
    protected  abstract int getFragment();

    /*This enable us to make this activity flexible by passing
     * any type of layout for its screen depending on the amount of fragment
     * and how the want to display them*/
    protected int getLayoutResId(){
        return R.layout.credential_activity;
    }
    /*called when the activity is first created*/
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(getLayoutResId());

        FragmentManager fm =  getSupportFragmentManager();
        // give a fragment to the activity
        Fragment fragment = fm.findFragmentById(getFragment());
        if(fragment == null){
            fragment = createFragment();
            fm.beginTransaction()
                    .add(getFragment(), fragment)
                    .commit();
        }
    }
}

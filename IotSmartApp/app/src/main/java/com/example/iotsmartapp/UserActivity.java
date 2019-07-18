package com.example.iotsmartapp;

import android.support.v4.app.Fragment;

import fragment.LoginFragment;


public class UserActivity extends ParentFragmentActivity {
    @Override
    protected Fragment createFragment() {
        return new LoginFragment();
    }

    @Override
    protected int getFragment() {
        return R.id.credentail_container;
    }
}

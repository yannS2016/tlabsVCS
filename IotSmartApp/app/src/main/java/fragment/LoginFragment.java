package fragment;

import android.app.Activity;
import android.app.ProgressDialog;
import android.content.Context;
import android.content.Intent;
import android.os.Bundle;
import android.support.annotation.NonNull;
import android.support.annotation.Nullable;
import android.support.v4.app.Fragment;
import android.text.TextUtils;
import android.view.LayoutInflater;
import android.view.View;
import android.view.ViewGroup;
import android.widget.Button;
import android.widget.EditText;
import android.widget.TextView;
import android.widget.Toast;

import com.example.iotsmartapp.MainActivity;
import com.example.iotsmartapp.R;
import com.parse.LogInCallback;
import com.parse.ParseException;
import com.parse.ParseUser;

public class LoginFragment extends Fragment {

    EditText edEmail, edPassword;
    Button eLogin;
    TextView rgUser, rsPassword;

    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View v =  inflater.inflate(R.layout.fragment_login, container,false);
        edEmail = (EditText)v.findViewById(R.id.edEmail);
        edPassword = (EditText)v.findViewById(R.id.edPassword);
        eLogin = (Button)v.findViewById(R.id.login);

        rgUser = (TextView)v.findViewById(R.id.rguser);
        rsPassword = (TextView) v.findViewById(R.id.rspassword);

        rsPassword.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // start password change fragment
                Fragment password = new PasswordFragment();
                getActivity().getSupportFragmentManager().beginTransaction()
                        .replace(R.id.credentail_container, password, "passwordFragment")
                        .addToBackStack(null)
                        .commit();

            }
        });

        eLogin.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // start the appliances activity
                if( TextUtils.isEmpty(edEmail.getText())){
                    edEmail.setError( "Email is required!" );
                }else if( TextUtils.isEmpty(edPassword.getText())){
                    edPassword.setError( "Password is required!" );
                }else{
                    final ProgressDialog progress = new ProgressDialog(getActivity());
                    progress.setMessage("Loading ...");
                    progress.show();
                    ParseUser.logInInBackground(edEmail.getText().toString(), edPassword.getText().toString() , new LogInCallback() {
                        @Override
                        public void done(ParseUser parseUser, ParseException e) {
                            progress.dismiss();
                            if (parseUser != null) {
                                Toast.makeText(getActivity(), "Welcome back!", Toast.LENGTH_LONG).show();
                                Intent intent = new Intent(getActivity(), MainActivity.class);
                                startActivity(intent);
                                getActivity().finish();
                            } else {
                                ParseUser.logOut();
                                Toast.makeText(getActivity(), e.getMessage(), Toast.LENGTH_LONG).show();
                            }
                        }
                    });
                }
            }
        });

        rgUser.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                // start the signup fragment
                // start password change fragment
                Fragment signup = new SignupFragment();
                getActivity().getSupportFragmentManager().beginTransaction()
                        .replace(R.id.credentail_container, signup, "passwordFragment")
                        .addToBackStack(null)
                        .commit();
            }
        });
        return v;
    }

    @Override
    public void onAttach(Context context) {
        super.onAttach(context);
        // if the user is already logged in get directly to appliances screen
        if(ParseUser.getCurrentUser()!=null){
            Intent intent = new Intent(context, MainActivity.class);
            startActivity(intent);
            ((Activity)context).finish();
        }
    }

}

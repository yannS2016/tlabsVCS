package fragment;

import android.app.ProgressDialog;
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
import android.widget.Toast;

import com.example.iotsmartapp.MainActivity;
import com.example.iotsmartapp.R;
import com.parse.ParseException;
import com.parse.ParseUser;
import com.parse.SignUpCallback;

public class SignupFragment extends Fragment {
    EditText edName, edEmail, edPassword, edConfirmPassword;
    Button signup;
    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View v = inflater.inflate(R.layout.fragment_signup, container, false);
        edName = v.findViewById(R.id.edName);
        edEmail = v.findViewById(R.id.edEmail);
        edPassword = v.findViewById(R.id.edPassword);
        edConfirmPassword = v.findViewById(R.id.edConfirmPassword);
        signup = v.findViewById(R.id.signup_but);

        signup.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if( TextUtils.isEmpty(edName.getText())){
                    edName.setError( "Name is required!" );
                }else if( TextUtils.isEmpty(edEmail.getText())){
                    edEmail.setError( "Email is required!" );
                }else if( TextUtils.isEmpty(edPassword.getText())){
                    edPassword.setError( "Password is required!" );
                }else if( TextUtils.isEmpty(edConfirmPassword.getText())){
                    edConfirmPassword.setError( "Confirm password is required!" );
                }else if(!edPassword.getText().toString().equals(edConfirmPassword.getText().toString())){
                    Toast.makeText(getActivity(), "Passwords are not the same!", Toast.LENGTH_LONG).show();
                }else{

                    final ProgressDialog progress = new ProgressDialog(getActivity());
                    progress.setMessage("Loading ...");
                    progress.show();
                    ParseUser user = new ParseUser();
                    user.setUsername(edEmail.getText().toString().trim());
                    user.setEmail(edEmail.getText().toString().trim());
                    user.setPassword(edPassword.getText().toString());
                    user.put("name", edName.getText().toString().trim());
                    user.signUpInBackground(new SignUpCallback() {
                        @Override
                        public void done(ParseException e) {
                            progress.dismiss();
                            if (e == null) {
                                Toast.makeText(getActivity(), "Welcome!", Toast.LENGTH_LONG).show();
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
        return v;
    }
}

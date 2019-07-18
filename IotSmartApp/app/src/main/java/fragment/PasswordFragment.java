package fragment;

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

import com.example.iotsmartapp.R;
import com.parse.ParseException;
import com.parse.ParseUser;
import com.parse.RequestPasswordResetCallback;

public class PasswordFragment extends Fragment {

    EditText edEmail;
    Button rsPassword;
    @Override
    public void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
    }

    @Nullable
    @Override
    public View onCreateView(@NonNull LayoutInflater inflater, @Nullable ViewGroup container, @Nullable Bundle savedInstanceState) {

        View  v = inflater.inflate(R.layout.fragment_reset_password, container, false);
        edEmail = v.findViewById(R.id.edEmail);
        rsPassword = v.findViewById(R.id.rs_user_password);

        rsPassword.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                if( TextUtils.isEmpty(edEmail.getText())){
                    edEmail.setError( "Email is required!" );
                }else {
                    ParseUser.requestPasswordResetInBackground(edEmail.getText().toString(), new RequestPasswordResetCallback() {
                        public void done(ParseException e) {
                            if (e == null) {
                                // An email was successfully sent with reset instructions.
                                Toast.makeText(getActivity(), "An email was successfully sent with reset instructions.", Toast.LENGTH_LONG).show();
                            } else {
                                // Something went wrong. Look at the ParseException to see what's up.
                                Toast.makeText(getActivity(), "Something went wrong. Look at the ParseException to see what's up.", Toast.LENGTH_LONG).show();
                            }
                        }
                    });
                }
            }
        });
        return v;
    }
}

package ndk.wangyang.com.ndkproject;

/**
 * Created by david on 2017/9/6.
 */

public class Wathcer {
    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("native-lib");
    }

    public native void createWatcher(int userId);
}

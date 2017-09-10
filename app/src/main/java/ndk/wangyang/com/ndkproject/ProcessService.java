package ndk.wangyang.com.ndkproject;

import android.app.Service;
import android.content.Intent;
import android.os.IBinder;
import android.os.Process;
import android.support.annotation.Nullable;

import java.util.Timer;
import java.util.TimerTask;

/**
 * Created by wangyang on 2017/9/8.
 * qq:1440214507
 * des: 双进程守护
 */

public class ProcessService extends Service {

    @Nullable
    @Override
    public IBinder onBind(Intent intent) {
        return null;
    }

    @Override
    public void onCreate() {
        super.onCreate();
        Wathcer wathcer = new Wathcer();
        wathcer.createWatcher(Process.myUid()+"");
        Timer timer = new Timer();
        timer.scheduleAtFixedRate(new TimerTask() {
            @Override
            public void run() {
                System.out.println("我是service回掉");
            }
        },0,3000);
    }
}

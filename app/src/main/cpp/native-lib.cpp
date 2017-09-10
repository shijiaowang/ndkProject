#include <jni.h>
#include <string>
#include "unistd.h"
#include "native-lib.h"

const char* uid;

void create_child();

extern "C"
JNIEXPORT void JNICALL Java_ndk_wangyang_com_ndkproject_Wathcer_createWatcher
        (JNIEnv *env, jobject jobj, jstring user_id) {
    uid = env->GetStringUTFChars(user_id,NULL);
    //创建子进程
    create_child();


}

void *thread_rt(void *data) {
    pid_t pid;
    //父进程如果等于1 就代表父进程被杀死，子进程被init进程托管
    while ((pid = getpid()) != 1) {

        //休眠10秒
        sleep(10);
    }
    //到这里代表被杀死 am命令重启父亲进程
    execlp("am", "am", "startservice", "--user", uid,
           "ndk.wangyang.com.ndkproject/ndk.wangyang.com.ndkproject.ProcessService", (char *) NULL);
}

void create_child() {
    //fork一个进程 0 代表成功，小于0代表失败 大于代表是父进程
    pid_t pid = fork();
    if (pid == 0) {
        LOGE("子进程开启成功");
        child_start_monitor();
    }
}

void child_start_monitor() {
    pthread_t pthread;
    //开启线程去论循环
    pthread_create(&pthread, NULL, thread_rt, NULL);
}

#include <stdio.h>

int main(){

    // 发送指定信号
    // int kill(pid_t pid,int signo)    // 发送给指定进程
    // int raise(int signo)             // 发送给自己
    // 这两个函数都是成功返回0,错误返回-1
   

    // abort函数使当前进程接收到信号而异常终止
    // void abort(void)


    // alarm函数可以通知内核在seconds后发送SIGALRM信号,该信号的默认动作是终止当前的进程,返回值是0或者是以前设定的闹钟时间还余下的秒数,seconds为0是,表示取消以前设定的闹钟,函数的返回值依然是之前设置的闹钟剩下的秒数
    // unsigned int alarm(unsigned int seconds)



    // 实际执行信号的处理动作叫做信号递达,信号从产生到递达之间的状态叫做信号未决,进程可以选择阻塞某个信号,被阻塞的信号将保持在未决状态,直到进程解除对此信号的阻塞,才执行递达的动作
    //

    return 0;
}

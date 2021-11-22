#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

    /* fork 根据一个现有的进程复制出一个新的进程,原来的进程作为父进程,新进程称为子进程 */

    /* Shell 下输入命令可以运行程序,以ls命令为例,过程如下:
     * fork复制新的Shell进程
     * 新的进程调用exec执行新的程序
     */

    /* 
     * 每次调用system 都是创建了子进程,彼此之间互不影响
     */
    system("cd ..");
    system("ls");

    system("cd ..;ls");


    /* printf PATH */
    /* libc 中定义的全局变量environ指向环境变量表,environ没有包含在任何头文件中,因此使用时要用extern声明 */
    extern char **environ;
    for(int i = 0;environ[i] != NULL; ++i){
        printf("%s\n",environ[i]);
    }

    /* 查看指定PATH的value */
    /* 找到时返回指向value的指针,否则返回NULL */
    printf("Getenv SHELL:%s\n",getenv("SHELL"));


    /* 修改指定PATH */

    /* 成功返回0,否则返回非0
     * 作用:将$name 设置为value
     * 如果name存在,rewrite为非0,覆盖原来的定义
     * 如果name存在,rewrite为0,不覆盖原来的定义,也不报错
     * int setenv(const char* name,const char *value,int rewrite) 
     *
     * 作用:删除name的定义,即使name没有定义,也不返回错误
     * void unsetnev(const char *name)
     */
    /* 通过setenv等函数的修改作用于当前程序的进程,当前程序的父进程不受影响,而不是像system一样作用于当前程序的子进程 */
    setenv("PATH", "NO...", 1);
    printf("Set PATH:%s\n",getenv("PATH"));


    return 0;
}

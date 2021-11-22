#include <stdio.h>

#define MA 10

#if !MA == 10
    int Mc = 10;
#endif


// 如果MA宏定义不存在,那么变成 #if 0 || TEMP || 2 < 3
// 如果MA 和 TEMP都不存在,那么变成 #if 0 || 0 || 2 < 3
// 因为 2 < 3 成立,所以 #if 0 || 0 || 1   ,即成立
// 条件编译查找的是宏定义,即便存在同名的变量定义,也不考虑
#if MA || TEMP || 2 < 3
    long long Mc = 100; 
#else 
    double Mc = 10.10;
#endif
int main(){


    return 0;
}

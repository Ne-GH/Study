#include<iostream>
using namespace std;
int main() {
#define a 1;
#ifdef a//如果使用预处理宏定义a,就编译中间内容
#define a 1;
	cout << "ifdef部分" << endl;
#endif//选择性编译的结束标志

#define b 0
#if b//如果预处理定义的b的值为0就编译第一部分
	cout << "b为真时,#if部分" << endl;
#else//否则编译下面
	cout << "b不为0时,#else部分" << endl;
#endif//结束标志


#ifndef c//如果没有使用预处理宏定义定义c,就编译
#define c 1//这种写法属于没有定义c
	cout << "#ifndef,没有编译" << endl;
#endif
	return 0;
}

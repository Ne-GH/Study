#include<stdio.h>
int main() {
	char str[30];
	fgets(str, 30, stdin);//stdin标准输入流,在stdio.h中定义
	fputs(str, stdout);//stdout标准输出,在stdio.h中定义
	while (fgets(str, 30, stdin) != NULL && str[0] != '\n')
		fputs(str, stdout);//可以用这种形式打印数量超过30的字符串
		//fputs()会输出换行

	return 0;
}
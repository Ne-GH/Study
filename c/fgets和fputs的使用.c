#include<stdio.h>
int main() {
	char str[30];
	fgets(str, 30, stdin);//stdin��׼������,��stdio.h�ж���
	fputs(str, stdout);//stdout��׼���,��stdio.h�ж���
	while (fgets(str, 30, stdin) != NULL && str[0] != '\n')
		fputs(str, stdout);//������������ʽ��ӡ��������30���ַ���
		//fputs()���������

	return 0;
}
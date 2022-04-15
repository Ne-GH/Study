/*
д����,�����ʽ�������Ż���,�������ø���= =
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char* NEW(void);//��ʼ��ֽ��
void shuffle(char(*)[4]);//ϴ��
void poker_deal(char(*)[4], _Bool*);//����
void print(char(*)[4], const _Bool*);//��ӡʣ�µ�ֽ��


int main() {
	char(*poker)[4];
	_Bool Flag[52] = { 0 };//ȡFlag��ǵ���˼,������¼ֽ���Ƿ񱻷���,��ʼ��Ϊ0
	srand((time(NULL)));//��ʼ�������������

	poker = NEW();//��ʼ��ֽ��

	printf("һ��������ֽ����: ");
	for (int i = 0; i < 52; i++)
		printf("%s\t", *(poker + i));

	shuffle(poker);//ϴ��

	putchar(10);

	poker_deal(poker, Flag);//����
	putchar(10);
	putchar(10);
	putchar(10);
	putchar(10);
	print(poker, Flag);//��ӡʣ�µ�ֽ��



	return 0;
}

char* NEW(void) {


	/*54��3��,ÿ�б�ʾһ����,���һ������'\0'*/
	char(*poker)[4] = (char*)malloc(sizeof(char[52][4]));//һ��ָ��3���ַ������ָ��

	for (int n = 0; n < 52; n++) {//��ʼΪ1,����<=�ж�,�����ʼ���ƵĴ�С
		if (n < 13)//��0��ʼ,��13����
			*(*(poker + n) + 0) = 'S';
		else if (n < 26)
			*(*(poker + n) + 0) = 'H';
		else if (n < 39)
			*(*(poker + n) + 0) = 'D';
		else//����for����������n<54,���Դ˴���elseʡ��
			*(*(poker + n) + 0) = 'C';
		/*����Ĳ���������ʼ���Ƶ�����*/



		switch (n % 13) {
		case 0:
			*(*(poker + n) + 1) = 'A';
			break;
		case 12://���������ֵ,�˴��Ͳ���''��
			/*��ֵΪ13�����*/
			*(*(poker + n) + 1) = 'K';
			break;
		case 9:
			/*��ֵΪ10�����*/
			*(*(poker + n) + 1) = '1';
			*(*(poker + n) + 2) = '0';
			break;
		case 10:
			/*��ֵΪ11�����*/
			*(*(poker + n) + 1) = 'J';
			break;
		case 11:
			/*��ֵΪ12�����*/
			*(*(poker + n) + 1) = 'Q';
			break;

		default:
			*(*(poker + n) + 1) = n % 13 + '0' + 1;
			break;
		}
		/*�������Գ�ʼ���ƵĴ�С*/
		if (n % 13 == 9)
			*(*(poker + n) + 3) = '\0';
		else
			*(*(poker + n) + 2) = '\0';

	}

	return poker;
}

void shuffle(char(*poker)[4]) {
	for (int i = 0; i < 52; i++) {
		int f = rand() % 52;//�����������f����λ��
		char temp[4];
		strcpy(temp, *(poker + i));
		strcpy(*(poker + i), *(poker + f));
		strcpy(*(poker + f), temp);
	}
	putchar(10);


	puts("���ϴ��");
	return;
}

void poker_deal(char(*poker)[4], _Bool* pFlag) {
	for (int i = 0, j = 1; i < 15; i++, j++) {
		printf("%s	", *(poker + i));
		*(pFlag + i) = 1;//���ı�־,��ʾ�����Ѿ�����
		if (j % 5 == 0)//j���ƻ���,ÿ5����һ����,��ʾ��ͬ�˵�ֽ��
			putchar(10);

	}

	return;
}

void print(char(*poker)[4], const _Bool* pFlag) {
	/*
	  �����ڷ��Ƶ�ʱ���ǰ�˳�򷢷ŵ�,��˴�ӡֻ���ӡƫ����Ϊ15��֮���
	  �������Ǿ�����ͷ������ӡ~,��Ȼ�������Flagûɶ�þͺ�������
	  (��˵���øо�˼·��������)= =,������const�޶�Flag�����е�ֵ����ı�
	*/
	printf("ʣ�µ�ֽ��Ϊ: ");
	for (int i = 0; i < 52; i++) {
		if (*(pFlag + i) == 0)//==0˵������δ����
			printf("%s	", *(poker + i));
	}
	putchar(10);


	return;
}

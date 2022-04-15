/*
写完了,输出格式还可以优化下,但是懒得改了= =
*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>


char* NEW(void);//初始化纸牌
void shuffle(char(*)[4]);//洗牌
void poker_deal(char(*)[4], _Bool*);//发牌
void print(char(*)[4], const _Bool*);//打印剩下的纸牌


int main() {
	char(*poker)[4];
	_Bool Flag[52] = { 0 };//取Flag标记的意思,用来记录纸牌是否被发放,初始化为0
	srand((time(NULL)));//初始化随机数的种子

	poker = NEW();//初始化纸牌

	printf("一副完整的纸牌有: ");
	for (int i = 0; i < 52; i++)
		printf("%s\t", *(poker + i));

	shuffle(poker);//洗牌

	putchar(10);

	poker_deal(poker, Flag);//发牌
	putchar(10);
	putchar(10);
	putchar(10);
	putchar(10);
	print(poker, Flag);//打印剩下的纸牌



	return 0;
}

char* NEW(void) {


	/*54行3列,每行表示一张牌,多出一个储存'\0'*/
	char(*poker)[4] = (char*)malloc(sizeof(char[52][4]));//一个指向3列字符数组的指针

	for (int n = 0; n < 52; n++) {//初始为1,并用<=判定,方便初始化牌的大小
		if (n < 13)//从0开始,共13张牌
			*(*(poker + n) + 0) = 'S';
		else if (n < 26)
			*(*(poker + n) + 0) = 'H';
		else if (n < 39)
			*(*(poker + n) + 0) = 'D';
		else//进入for的条件就是n<54,所以此处用else省略
			*(*(poker + n) + 0) = 'C';
		/*上面的部分用来初始化牌的类型*/



		switch (n % 13) {
		case 0:
			*(*(poker + n) + 1) = 'A';
			break;
		case 12://计算的是数值,此处就不用''了
			/*数值为13的情况*/
			*(*(poker + n) + 1) = 'K';
			break;
		case 9:
			/*数值为10的情况*/
			*(*(poker + n) + 1) = '1';
			*(*(poker + n) + 2) = '0';
			break;
		case 10:
			/*数值为11的情况*/
			*(*(poker + n) + 1) = 'J';
			break;
		case 11:
			/*数值为12的情况*/
			*(*(poker + n) + 1) = 'Q';
			break;

		default:
			*(*(poker + n) + 1) = n % 13 + '0' + 1;
			break;
		}
		/*上面用以初始化牌的大小*/
		if (n % 13 == 9)
			*(*(poker + n) + 3) = '\0';
		else
			*(*(poker + n) + 2) = '\0';

	}

	return poker;
}

void shuffle(char(*poker)[4]) {
	for (int i = 0; i < 52; i++) {
		int f = rand() % 52;//依次与随机的f互换位置
		char temp[4];
		strcpy(temp, *(poker + i));
		strcpy(*(poker + i), *(poker + f));
		strcpy(*(poker + f), temp);
	}
	putchar(10);


	puts("完成洗牌");
	return;
}

void poker_deal(char(*poker)[4], _Bool* pFlag) {
	for (int i = 0, j = 1; i < 15; i++, j++) {
		printf("%s	", *(poker + i));
		*(pFlag + i) = 1;//更改标志,表示该牌已经发放
		if (j % 5 == 0)//j控制换行,每5个换一次行,表示不同人的纸牌
			putchar(10);

	}

	return;
}

void print(char(*poker)[4], const _Bool* pFlag) {
	/*
	  我们在发牌的时候是按顺序发放的,因此打印只需打印偏移量为15及之后的
	  但是我们决定从头遍历打印~,不然标记数组Flag没啥用就很尴尬了
	  (虽说不用感觉思路更清晰了)= =,我们用const限定Flag数组中的值不会改变
	*/
	printf("剩下的纸牌为: ");
	for (int i = 0; i < 52; i++) {
		if (*(pFlag + i) == 0)//==0说明该牌未发放
			printf("%s	", *(poker + i));
	}
	putchar(10);


	return;
}

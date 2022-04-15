#include<stdio.h>
inline static void emmm() {
	char ch;
	while ((ch = getchar()) != '\n')
		putchar(ch);
	putchar(10);
}
int main() {
	int n = 3;
	while (n--)
		emmm();
	void (*ph)(void);
	ph = emmm;
	ph();
	return 0;
}
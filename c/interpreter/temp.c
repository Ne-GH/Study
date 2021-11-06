#include <stdio.h>
#include <stdint.h>

int main(){

    /* int ax = 10; */
    /* int *p = &ax; */
    /* *p = 100; */
    /* printf("%d\n",ax); */

    /* long long num = 10; */
    /* long long ax = (long long )&num; */
    /* long long *sp = &ax; */
    /* ax = *(long long *)*sp++ = ax; */
    int num = 10;
    intptr_t ax = (intptr_t)&num;
    intptr_t *sp = &ax;

    ax = *(intptr_t *)sp++ = ax;
    printf("%ld\n",ax);


    return 0;
}

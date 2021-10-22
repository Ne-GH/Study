#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define NUL '\0'
typedef char CHAR[32];
typedef char line[255];

struct Word{
    int id;
    CHAR Chinese;
    CHAR English;
};

struct Words{
    int num;
    struct Word word[255];
};

struct Words words;

// 将文件中的单词分割进words.word
void LoadFile(FILE *file){

    int num = 0;

    char temp[255] = {0};
    srand(time(NULL));
    while(fscanf(file,"%[^\n]%*c",temp) != EOF){
        /* printf("%s",temp); */

        for(int i = 0;temp[i] != NUL; ++i){
            if(temp[i] == ' '){

                temp[i] = NUL;
                strcpy(words.word[num].English, temp);
                strcpy(words.word[num].Chinese, temp+i+1);
                /* printf("%s\n%s\n",words.word[num].English,words.word[num].Chinese); */

                words.word[num].id = rand();
                break;
            }
        }

        num ++;
    }
    words.num = num;

    fseek(file, 0, SEEK_SET);
    return;
}

int cmp(const void *a,const void *b){
    int aa = *(int *)a;
    int bb = *(int *)b;
    if(aa < bb)
        return -1;
    else if(aa > bb)
        return 1;
    else
        return 0;
}

int main(){

    FILE *file;
    char filename[255];
REOPEN:
    printf("请选择文件:");
    scanf("%s%*c",filename);

    file = fopen(filename, "r");
    if(file == NULL){
        printf("打开文件失败\n");
        goto REOPEN;
    }
    
    LoadFile(file);


    qsort(words.word, words.num,sizeof(struct Word), cmp);

    /* printf("num:%d\n",words.num); */
    /* for(int i = 0;i < words.num; ++i){ */
        /* printf("%d:",words.word[i].id); */
        /* printf("%s\n%s\n",words.word[i].English,words.word[i].Chinese); */
    /* } */
/*  */
    fclose(file);

    return 0;
}

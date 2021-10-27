#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define COUT(f,data) printf("%"#f,data);
#define CIN(f,data) scanf("%"#f,data);

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

void ReadFile(FILE *file){
    LoadFile(file);


    qsort(words.word, words.num,sizeof(struct Word), cmp);

    for(int i = 0;i < words.num; ++i){
        COUT(s:,words.word[i].Chinese);

        line temp;
        CIN(s,temp);

        if(strcmp(temp, words.word[i].English) == 0){
            printf("Yes\n");
        }
        else{
            printf("English error\n");
            i--;
        }
    }
    printf("File End");

    fseek(file, 0, SEEK_SET);
    return;
}

void InsertWord(FILE *file){
    char ch;

    do{

        CHAR english,chinese;
        printf("English:");
        scanf("%[^\n]%*c",english);
        fprintf(file, "%s ",english);
        printf("Chinese:");
        scanf("%[^\n]%*c",chinese);
        fprintf(file, "%s\n",chinese);
        fflush(file);

        printf("按回车继续添加,按其余按键退出添加......");
        ch = getchar();
    }while(ch != 'q');

    
    


    fseek(file, 0, SEEK_SET);
    return;
}

int main(){

    FILE *file;
    char filename[255];
REOPEN:
    printf("请选择文件:");
    scanf("%s%*c",filename);

    file = fopen(filename, "ab+");
    if(file == NULL){
        printf("打开文件失败\n");
        goto REOPEN;
    }
    
    LoadFile(file);
    printf("1:读取文件\n"
           "2:补充单词\n");
    int choose = 0;
    scanf("%d%*c",&choose);
    switch (choose) {
        case 1:
            ReadFile(file);
            break;
        case 2:
            InsertWord(file);
            break;
        default:
            break;
    }

    fclose(file);

    return 0;
}

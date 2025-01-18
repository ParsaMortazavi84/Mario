#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct sign {
    char name[100];
    char gmail[200];
    char password[100];
};

struct game{
    int victory;
    int loss;
    int score;
    int coin;
    struct game *pNext;
};
struct infogame{
    char name[100];
    struct game *pHead;
};

void sign_up(FILE *fp) {
    struct sign *temp = (struct sign*)malloc(sizeof(struct sign));
    printf("Enter your name: ");
    scanf("%s", temp->name);
    printf("Enter your gmail: ");
    scanf("%s", temp->gmail);
    printf("Enter your password: ");
    scanf("%s", temp->password);
    fseek(fp, 0, SEEK_END);
    int n = ftell(fp);
    fseek(fp, n, SEEK_SET); 
    fwrite(temp, sizeof(struct sign), 1, fp);
}
void sign_in(FILE *fp, int *result, char nametmp[]) {
    struct sign temp, temp2;
    printf("Enter your name: ");//رنگی کردن
    scanf("%s", temp.name);
    printf("Enter your password: ");
    scanf("%s", temp.password);
    fseek(fp, 0, SEEK_SET);
    while(fread(&temp2, sizeof(struct sign), 1, fp) == 1 )
    {
        if(strcmp(temp2.name, temp.name) == 0)
        {
            if(temp2.password == temp.password)
            {
                strcpy(nametmp, temp.name);//بعدش در یک فایل دگر به نام گیم میام و این نام را می گردیم پیدا شد می کنیم تا رکوردهاش را جلوش ثبت کنیم
            }
            else{
                result = 0;
            }
        }
        else{
            result = 0;
        }
    }
    //اگر که بولین ما برابر غلط بود بیا و یه خظا پرینت کن
    //
}

int filegame(FILE *fgame, char name[])
{
    struct infogame temp;
    int result = 0;
    fseek(fgame, 0, SEEK_SET);
    while(fread(&temp, sizeof(struct infogame), 1, fgame) == 1)
    {
        if(strcmp(temp.name, name) == 0)
        {
            result = 1;
        }
    }
    if(result == 1)
    {
        int n = ftell(fgame);
        return n-sizeof(struct infogame);
    }
    else{
        fseek(fgame, 0, SEEK_END);
        strcpy(temp.name, name);
        fwrite(&temp, sizeof(struct infogame), 1, fgame);
    }
}

void showinfogame(char name[], FILE *fgame)
{
    struct infogame temp;
    struct game *pTmp;
    while(fread(&temp, sizeof(struct infogame), 1, fgame) == 1)
    {
        if(strcmp(temp.name, name) == 0)
        {
            pTmp = temp.pHead;
            if(pTmp == NULL)
            {
                printf("you haven't history of this game");
            } 
            else{
                int i = 0;//کشیدن جدول
                
                while(pTmp != NULL)//قراره مقادیر داخل جدول را اینجا وارد کنم
                {
                    if(i==0)
                    {
                        printf("game\tvictory\tloss\tscore\tcoin\n");
                        continue;
                    }
                    printf("game %d", i);
                    printf("%d\t%d\t%d\t%d\n", i, pTmp->victory, pTmp->loss, pTmp->score, pTmp->coin); 
                    pTmp = pTmp->pNext;
                    i++;
                }
            }
        }
    }
}


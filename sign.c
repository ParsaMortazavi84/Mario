#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

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

void sign_up(FILE *fp) {                            //number 1
    struct sign *temp = (struct sign*)malloc(sizeof(struct sign));
    int result = 0;
    while(result != 1){
        printf("Enter your name: ");
        scanf("%s", temp->name);
        struct sign temp2;
        fseek(fp, 0, SEEK_SET);

        while(fread(&temp2, sizeof(struct sign), 1, fp) == 1)
        {
            if(strcmp(temp2.name, temp->name) == 0)
            {
                printf("This name is already exist\n");
                result = 0;
                break;
            }
            else{
                result = 1;
            }
        }
    }
    printf("Enter your gmail: ");
    scanf("%s", temp->gmail);
    printf("Enter your password: ");
    scanf("%s", temp->password);
    result = 0;
    while(result != 1){                       //agian enter your password
        printf("Enter your password again: ");
        char password[100];
        scanf("%s", password);
        if(strcmp(password, temp->password) == 0)
        {
            result = 1;
        }
        else{
            printf("The password is not correct\n");
        }
    }
    fseek(fp, 0, SEEK_END);
    fwrite(temp, sizeof(struct sign), 1, fp);
}

forgetpassword(FILE *fp)
{
    struct sign temp, temp2;
    printf("Enter your name: ");
    scanf("%s", temp.name);
    printf("Enter your gmail: ");
    scanf("%s", temp.gmail);
    fseek(fp, 0, SEEK_SET);
    while(fread(&temp2, sizeof(struct sign), 1, fp) == 1)
    {
        if(strcmp(temp2.name, temp.name) == 0)
        {
            if(strcmp(temp2.gmail, temp.gmail) == 0)
            {
                printf("Enter your new password: ");
                scanf("%s", temp2.password);
                fseek(fp, -sizeof(struct sign), SEEK_CUR);
                fwrite(&temp2, sizeof(struct sign), 1, fp);
            }
            else{
                printf("The gmail is not correct\n");
            }
        }
        else{
            printf("The name is not correct\n");
        }
    }
}
void sign_in(FILE *fp, int result, char nametmp[]) {
    struct sign temp, temp2;
    printf("Enter your name: ");//رنگی کردن را یادت نره
    scanf("%s", temp.name);
    printf("Enter your password: ");
    int i = 0;
    char ch; 
    while (1) {
        ch = getch();  // بدون نشان دادن بر روی ص

        if (ch == 13) {  // کد اسبلی انتر است
            break;
        } 
        
        else {                                          // ذخیره کاراکتر در آرایه
            temp.password[i++] = ch;
            printf("*");                               // نمایش ستاره به‌جای رمز
        }
    }

    temp.password[i] = '\0';  // اخر رشته را زیرو بایت می کند 
    printf("\n");
    fseek(fp, 0, SEEK_SET);
    while(fread(&temp2, sizeof(struct sign), 1, fp) == 1 )
    {
        if(strcmp(temp2.name, temp.name) == 0)
        {
            if(strcmp(temp2.password , temp.password) == 0)
            {
                strcpy(nametmp, temp.name);//بعدش در یک فایل دگر به نام گیم میام و این نام را می گردیم پیدا شد می کنیم تا رکوردهاش را جلوش ثبت کنیم
            }
            else{
                result = 0;
                printf("        ")
                forgetpassword(fp);
            }
        }
        else{
            result = 0;
            forgetpassword(fp);
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

void showinfogame(char name[], FILE *fgame) {
    struct infogame temp;

    while (fread(&temp, sizeof(struct infogame), 1, fgame) == 1) {
        if (strcmp(temp.name, name) == 0) {
            struct game *pTmp = temp.pHead;
            
            if (pTmp == NULL) {
                printf("You haven't history of this game.\n");
                return;
            } 

            //  کشیدن خط بالا
            printf("+--------+---------+-------+------+\n");
            printf("| %-6s | %-7s | %-5s | %-4s |\n", "Game", "Victory", "Score", "Coin");//چپ چین کردن عناوین با علامت منفی اینگونه فضای خالی را در سمت راست قرار می دهد
            printf("+--------+---------+-------+------+\n");

            int i = 1;
            while (pTmp != NULL) {
                printf("| %-6d | %-7d | %-5d | %-4d |\n", i, pTmp->victory, pTmp->score, pTmp->coin);
                pTmp = pTmp->pNext;
                i++;
            }

            //  کشیدن خط پایین جدول
            printf("+--------+---------+-------+------+\n");

            return;  
        }
    }

    printf("Game not found!\n"); 
}


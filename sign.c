#include "common.h"

extern char Name[100] = {};
int resultultimate = 0;

void sign_up(FILE *fp, FILE *fgame) {                            //number 1
    struct sign *temp = (struct sign*)malloc(sizeof(struct sign));
    struct infogame *tmp = (struct infogame*)malloc(sizeof(struct infogame)), tmp2;
    int result = 0;
    while(result != 1){
        system("cls");
        printf("\033[32m");
        printf("Enter your name: ");
        printf("\033[0m");
        fgets(temp->name, sizeof(temp->name), stdin);
        temp->name[strcspn(temp->name, "\n")] = '\0';

        struct sign temp2;
        fseek(fp, 0, SEEK_SET);
        fseek(fgame, 0, SEEK_SET);
        result = 2;
        fread(&tmp2, sizeof(struct infogame), 1, fgame);
        while(fread(&temp2, sizeof(struct sign), 1, fp) == 1)
        {
            if(strcmp(temp2.name, temp->name) == 0)
            {
                printf("\033[31m");
                printf("This name is already exist\n");
                result = 0;
                Sleep(800);
                system("cls");
                break;
            }
            fread(&tmp2, sizeof(struct infogame), 1, fgame);
        }
        if(result == 2)
        {
            result = 1;
            break;
        }
    }
    printf("\033[32m");
    printf("Enter your gmail: ");
    printf("\033[0m");
    scanf("%s", temp->gmail);
    getc(stdin);//for inter the gmail
    printf("\033[32m");
    printf("\nEnter your password: ");
    printf("\033[0m");
    scanf("%s", temp->password);
    getc(stdin);
    result = 0;
    while(result != 1){                       //agian enter your password
        printf("\033[32m");
        printf("Enter your password again: ");
        char password[100];
        printf("\033[0m");
        fgets(password, sizeof(password), stdin);
    
        password[strcspn(password, "\n")] = '\0'; // حذف `\n`
        
        if(strcmp(password, temp->password) == 0)
        {
            result = 1;
            strcpy(tmp->name , temp->name);
            
        }
        else{
            printf("\033[31m");
            printf("The password is not correct\n");// یادت نره قرمزش کنی
            Sleep(200);
        }
    }
    fseek(fp, 0, SEEK_END);
    fwrite(temp, sizeof(struct sign), 1, fp);

    fseek(fgame, 0, SEEK_END);
    fwrite(tmp, sizeof(struct infogame), 1, fgame);


    strcpy(Name, temp->name);
    free(temp);
    
}

void forgetpassword(FILE *fp, int *result)
{
    struct sign temp, temp2;
    printf("\033[32m");
    printf("Enter your name: ");
    printf("\033[0m");
    fgets(temp.name, sizeof(temp.name), stdin);
    temp.name[strcspn(temp.name, "\n")] = '\0';
    printf("\033[32m");
    printf("Enter your gmail: ");
    printf("\033[0m");
    scanf("%s", temp.gmail);
    getc(stdin);
    fseek(fp, 0, SEEK_SET);
    int resultn = 0;// that's for name
    while(fread(&temp2, sizeof(struct sign), 1, fp) == 1)
    {
        if(strcmp(temp2.name, temp.name) == 0)
        {
            resultn = 1;
            if(strcmp(temp2.gmail, temp.gmail) == 0)
            {
                printf("\033[32m");
                printf("Enter your new password: ");
                printf("\033[0m");
                scanf("%s", temp2.password);
                int result1 = 0;
                while(result1 != 1){   
                    printf("\033[32m");                    //agian enter your password
                    printf("Enter your password again: ");
                    char password[100];
                    printf("\033[0m");
                    scanf("%s", password);
                    getc(stdin);
                    if(strcmp(password, temp2.password) == 0)
                    {
                        result1 = 1;
                    }
                    else{
                        printf("\033[31m");
                        printf("The password is not correct\n");
                        Sleep(2000);
                    }
                }
                fseek(fp, -(long)sizeof(struct sign), SEEK_CUR);
                fwrite(&temp2, sizeof(struct sign), 1, fp);
                *result = 1;

            }
            else{
                printf("\033[31m");
                printf("The gmail is not correct\n");
                Sleep(2000);
            }
        }
    }
    if(resultn == 0){
        printf("\033[31m");
        printf("The name is not correct\n");     
        Sleep(2000);
        }
}

void sign_in(FILE *fp, int *result) {
    struct sign temp, temp2;
    printf("\033[32m");
    printf("Enter your name: ");//رنگی کردن را یادت نره
    //scanf("%s", temp.name);
    printf("\033[0m");
    fgets(temp.name, sizeof(temp.name), stdin);

    temp.name[strcspn(temp.name, "\n")] = '\0';
    printf("\033[32m");
    printf("Enter your password: ");
    int i = 0;
    char ch; 
    printf("\033[0m");
    while (1) {
        ch = getch();  // بدون نشان دادن بر روی ص

        if (ch == 13) {  // کد اسبلی انتر است
            break;
        } 
        else if(ch == 8)// back space
        {
            if(i > 0)
                i--;
            printf("\b \b");// بازگشت به عقب و جایگزینی با فضای خالی    
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
                strcpy(Name, temp.name);//بعدش در یک فایل دگر به نام گیم میام و این نام را می گردیم پیدا شد می کنیم تا رکوردهاش را جلوش ثبت کنیم
                printf("\033[0m");
                printf("your sign_in is successful");
                Sleep(2000);
                *result = 1;
                return;
            }
            else{
                *result = 0;
                return;
                
            }
        }
        else{
            continue;
        }
    }
    return;
    //اگر که بولین ما برابر غلط بود بیا و یه خظا پرینت کن
    //
}

void change_Data(FILE *fp, FILE *fgame)
{
    struct sign temp, temp2, temp3;
    struct infogame tmp;
    printf("\033[32m");
    printf("Enter your name: ");
    printf("\033[0m");
    fgets(temp.name, sizeof(temp.name), stdin);

    temp.name[strcspn(temp.name, "\n")] = '\0';
    printf("\033[32m");
    printf("Enter your password: ");
    printf("\033[0m");
    scanf("%s", temp.password);
    getc(stdin);
    fseek(fp, 0, SEEK_SET);
    int resultn = 0;// if not find the name
    int result = fread(&temp2, sizeof(struct sign), 1, fp);
    int result2 = fread(&tmp, sizeof(struct infogame), 1, fgame);
    while(result == 1)
    {
        if(strcmp(temp2.name, temp.name) == 0)
        {
            resultn = 1;
            if(strcmp(temp2.password, temp.password) == 0)
            {
                system("cls");
                printf("Enter your new name: ");
                printf("\033[0m");
                fgets(temp2.name, sizeof(temp2.name), stdin);

                temp2.name[strcspn(temp2.name, "\n")] = '\0';
                
                fseek(fp, 0, SEEK_SET);

                while(fread(&temp3, sizeof(struct sign), 1, fp) == 1)
                {
                    if(strcmp(temp2.name, temp3.name) == 0)
                    {
                        printf("\033[31m");
                        printf("This name is already exist\n");
                        printf("\033[32m");
                        printf("Enter your new name: ");
                        printf("\033[0m");
                        fgets(temp2.name, sizeof(temp.name), stdin);

                        temp2.name[strcspn(temp.name, "\n")] = '\0';

                        fseek(fp, 0, SEEK_SET);
                        continue;
                    }

                }
            }   
            else{
                printf("\033[31m");
                printf("the password is not correct\n");
                printf("\033[32m");
                printf("Enter your password again: ");
                printf("\033[0m");
                scanf("%s", temp.password);
                getc(stdin);

                continue;
            }    
            printf("\033[32m");
            printf("Enter your new password: ");
            printf("\033[0m");
            scanf("%s", temp2.password);
            getc(stdin);

            int result3 = 0;
            while(result3 != 1){ 
                printf("\033[32m");                      //agian enter your password
                printf("Enter your password again: ");
                char password[100];
                printf("\033[0m");
                scanf("%s", password);
                getc(stdin);

                if(strcmp(temp2.password, password) == 0)
                {
                    result3 = 1;
                }
                else{
                    printf("\033[31m");
                    printf("The password is not correct\n");

                }
            }
            strcpy(Name, temp2.name); 
            fseek(fp, -(long)sizeof(struct sign), SEEK_CUR);
            fseek(fgame, -(long)sizeof(struct infogame), SEEK_CUR);
            fwrite(&tmp, sizeof(struct infogame), 1, fgame);
            fwrite(&temp2, sizeof(struct sign), 1, fp);
            break;
        }
        
        else{
            result = fread(&temp2, sizeof(struct sign), 1, fp);
            result2 = fread(&tmp, sizeof(struct infogame), 1, fgame);

        }    
    }
    
    if(resultn == 0)
    {
        printf("\033[31m");
        printf("The name is not correct\n");
        Sleep(2000);
        return;
    }
    return;
}    

int SIGN()
{
    int result = 1;
    int resultin = 1;
    FILE *fp = fopen("fname.bin", "r+b");
    if(fp == NULL)
    {
        fp = fopen("fname.bin", "w+b");
    }
    FILE *fgame = fopen("fgame.bin", "r+b");
    if(fgame == NULL)
    {
        fgame = fopen("fgame.bin", "w+b");
    }
    
    while(1)
    {
        system("cls");
        printf("\033[32m");
        printf("if you want to sign in please inter 1\n");
        printf("if you want to sign up please inter 2\n");
        printf("if you want to change your information please inter 3\n");
        printf("if you forget your password inter 4\n");
        printf("if you want to back to the menu inter 5\n");
        int n;
        printf("please inter your number:");
        printf("\033[0m");
        scanf("%d", &n);
        getc(stdin);
        switch (n)
        {
            case 1:
                if(resultultimate == 0){

                    sign_in(fp, &resultin);
                    if(resultin == 0)
                    {
                        printf("\033[31m");
                        printf("your name or your password is wrong");
                        Name[0] = '\0';//clear the value in the name string
                        Sleep(2000);
                    }
                    
                    else{
                        
                        resultultimate = 1;
                        break;
                    }
                }
                else{
                    printf("\033[33m");
                    printf("You now in your account");
                    Sleep(2000);
                    break;
                }
                break;
            case 2:
                if(resultultimate == 0){
                    sign_up(fp, fgame);
                    resultultimate = 1;
                    
                    break;
                }
                else{
                    printf("\033[33m");
                    printf("You now in your account");
                    Sleep(2000);
                    break; 
                }  
                break;     
            case 3:
                if(resultultimate == 1){
                    change_Data(fp, fgame);
                    
                    break; 
                }
                else{
                    printf("\033[31m");
                    printf("you should first sign_up or sign_in");
                    Sleep(2000);
                    break; 
                }
                break;
            case 4:
                if(resultultimate == 0){

                    forgetpassword(fp, &result);
                    if(result == 0)
                    {
                        Name[0] = '\0';
                        Sleep(2000);
                        break; 
                    } 
                    else{
                        
                        resultultimate = 1;
                        break; 
                    }
                }
                else{
                    
                    break; 
                }    
                break;
            case 5:
                printf("\033[0m");
                fclose(fp);
                fclose(fgame);
                return resultultimate;   
            default:
                break;       
        }

    }
}
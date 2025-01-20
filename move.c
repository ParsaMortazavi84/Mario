// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
// #include<conio.h>
// #include<windows.h>

// int main()
// {
//     FILE *map1 = fopen("map1", "r+");
//     char map[14][130];
//     int i = 0;
//     while(i < 14 && fgets(map[i], 130, map1) != NULL)
//     {
//         i++;
//     }
//     while(_kbhit()){
//         char ch = _getch();
//         if(ch == 'a' || ch == 'A')
//         {
//             //move left
//         }
//         else if(ch == 'd' || ch == 'D')
//         {
//             //move right
//         }
//         else if(ch == 'w' || ch == 'W')
//         {
//             mariojump();
//         }
//     }
// }


#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
int coin = 0;
COORD coord;
char valuecoin[14][130];
void map1(FILE *mp1)
{
    char map1[14][130], temp[130];
    int i = 0;
    while(i<14 && fgets(map1[i], 130, mp1) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 130; j++)
        {
            if(map1[i][j] == "8")
            {
                srand(time(0));
                valuecoin[i][j] = (rand() % 5) + 1;
            }
            else{
                valuecoin[i][j] = 0;
            }
        }
    }
    for(i = 0; i < 14; i++)
        printf("%s", map1[i]);

    fclose(mp1);    
    //move

    
}
void setcursorposition(SHORT x, SHORT y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}
int whathappenX(FILE *mp1, char ch)//move in the X way
{
    mp1 = fopen("map1.txt", "r+");
    char map1[14][130];
    int i = 0;
    while(i < 14 && fgets(map1[i], 130, mp1) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    if(ch == 'a' || ch == 'A')
    {
        if(map1[coord.Y][coord.X - 1] == '#')
        {
            return 0;
        }
    }
    else if(ch == 'd' || ch == 'D')
    {
        if(map1[coord.Y][coord.X + 1] == '#')
        {
            return 0;
        }
    }
    else if(ch == 'w' || ch == 'W')
    {
        if(map1[coord.Y - 1][coord.X] == '#' || map1[coord.Y+1][coord.X] == '|')
        {
            return 0;
        }
    }
    else if(ch == 's' || ch == 'S')
    {
        if(map1[coord.Y + 1][coord.X] == '#' || map1[coord.Y+1][coord.X] == '|')
        {
            return 0;
        }
    }
    fclose(mp1);
    return 1;
}

int whathappenY(FILE *mp, int result)
{
    mp = fopen("map1.txt", "r+");
    char map1[14][130];
    int i = 0;
    while(i < 14 && fgets(map1[i], 130, mp) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    if(result == 0)
    {
        if(map1[coord.Y - 1][coord.X] == '#' || map1[coord.Y - 1][coord.X] == '|' || coord.Y <= 0)
        {
            return 0;
        }
        else if(map1[coord.Y - 1][coord.X] = '8')
        {
            if(valuecoin[coord.Y - 1][coord.X] != 0)
            {
                coin +=1;
                valuecoin[coord.Y - 1][coord.X] -= 1;
                return 0;
            }
            else{
                return 1;
            }
        }
    }
    else if(result == 1)
    {
        if((coord.Y + 1) >= 13 || map1[coord.Y + 1][coord.X] == '#' || map1[coord.Y + 1][coord.X] == '|')
        {
            return 0;
        }
        
    }

    fclose(mp);
    return 1;
}
void goleftorright(char ch)
{
    if(ch == 'a' || ch == 'A')
    {
        int i = whathappenX(map1, ch);
        if(i == 0)
        {
            return;
        }
        Sleep(100);
        gotoxy(coord.X - 1, coord.Y);
    }
    else if(ch == 'd' || ch == 'D')
    {
        int i = whathappenX(map1 , ch);
        if(i == 0)
        {
            return;
        }
        Sleep(100);
        gotoxy(coord.X + 1, coord.Y);   
    }
}

void mariojump()
{
    FILE *mp = fopen("map1.txt", "r+");
    char map1[14][130];
    int i = 0;
    while(i < 14 && fgets(map1[i], 130, mp) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    int result = 0;
    for(int i = 0; i < 4; i++)
    {
        int j = whathappenY(mp, result);
        if(j == 0)
        {
            break;
        }
        gotoxy(coord.X, coord.Y - 1);
        Sleep(100);
    }
    result = 1;
    for(int i = 0; i < 4; i++)
    {
        int j = whathappenY(mp, result);
        if(j == 0)
        {
            break;
        }
        gotoxy(coord.X, coord.Y + 1);
        Sleep(100);
    }
}

void gotoxy(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf(" ");
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("M");

}

int main() {

    FILE *mp1 = fopen("map1.txt", "r+");
    system("cls");
    map1(mp1);
    gotoxy(128, 13);
    printf("\n");

    gotoxy(5, 12);    

    // remove cursuer
    CONSOLE_CURSOR_INFO cursurInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursurInfo);
    cursurInfo.bVisible = false;
    SetConsoleCursorInfo (hConsole, &cursurInfo);

    while(1){
        if(_kbhit()){
            char ch = _getch();
            if(ch == 'a' || ch == 'A' || ch == 'd' || ch == 'D')
            {
                goleftorright(ch);
            }
            else if(ch == ' ')
            {
                mariojump();
            }
        }
    }

    // gotoxy(5, 12);
    // printf("M");


    // gotoxy(5, 12);
    // printf(" ");

    // gotoxy(10, 12);
    // printf("M");



    return 0;
}
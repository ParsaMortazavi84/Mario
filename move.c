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
#include <string.h>
#include <pthread.h>
#include "sign.h"
#include "move.h"
time_t t;
int _coin = 0;
COORD coord;
char valuecoin[14][130];
struct game *temp2;
char _map1[14][130];

int life = 3;

void mapone(FILE *mp1)
{

    int i = 0;
    while(i<14 && fgets(_map1[i], 130, mp1) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    for(int j = 0; j < 14; j++)
    {
        for(int k = 0; k < 130; k++)
        {
            if(_map1[j][k] == '8')
            {
                srand(time(0));
                valuecoin[j][k] = (rand() % 5) + 1;
            }
            else{
                valuecoin[j][k] = 0;
            }
        }
    }
    for(i = 0; i < 14; i++)
        printf("%s", _map1[i]);

    fclose(mp1);    
    //move

    
}

// void findinfogame(char *name, FILE *fgame )
// {
//     struct infogame temp;
//     while(fwrite(&temp, sizeof(struct infogame), 1, fgame) == 1)
//     {
//         if(strcmp(temp.name, name) == 0)
//         {
//             temp2 = temp.pHead;
//             struct game *pNew = (struct game*)malloc(sizeof(struct game));
//             while(temp2 != NULL)
//                 temp2 = temp2 -> pNext;
//             temp2->pNext = NULL;
            
//         }

//     } 
// }



// void abilitygame(char *name, FILE *fgame, SHORT X, SHORT Y)
// {
//     time_t t2;
//     if(_map1[X][Y] == '$')
//         temp2->coin += 1;
//     if(_map1[X][Y] == 'S')// 
//     {
//         life += 1;
//     }  
//     if(_map1[X+1][Y] == '(')// simple enemy 
//     {
//         life -= 1;
//         ifalive()
//     }
//     if(_map1[X][Y+1] == '(')// simple enemy
//     {
//         static int i = 100;
//         static int i = 0;
//         if(i == 0){
//             time(&t);
//             temp2->score += 100;

//         }
//         else{
//             time(&t2);
//             if(difftime(t2, t) <= 5)
//             {
//                 i *= 2; 
//                 if(i > 400)
//                     i = 400;
//                 temp2->score += i;
//             }
//             else{
//                 i = 100;
//             }
//         }
//         if(_map1[X][Y] == '!' || _map1[X+1][Y] == '!' )
//         {
//             life -= 1;
//             gotoxy(X-2, Y);
//             printf(" ");
//         }
//     }

// }

void setcursorposition(SHORT x, SHORT y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

int whathappenX(char ch)//move in the X way
{
    // mp1 = fopen("map1.txt", "r+");
    // char _map1[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map1[i], 130, mp1) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR);
    // }
    if(ch == 'a' || ch == 'A')
    {
        if(_map1[coord.Y][coord.X - 1] == '#' || _map1[coord.Y][coord.X - 1] == '|')
        {
            return 0;
        }
    }
    else if(ch == 'd' || ch == 'D')
    {
        if(_map1[coord.Y][coord.X + 1] == '#' || _map1[coord.Y][coord.X + 1] == '|')
        {
            return 0;
        }
    }
    
    // fclose(mp1);
    return 1;
}

int whathappenY(int result)
{
    // mp = fopen("map1.txt", "r+");
    // char _map1[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map1[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR);
    // }
    if(result == 0)
    {
        if(_map1[coord.Y - 1][coord.X] == '#' || _map1[coord.Y - 1][coord.X] == '|' || coord.Y <= 0)
        {
            return 0;
        }
        else if(_map1[coord.Y - 1][coord.X] == '8')
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
        if((coord.Y + 1) >= 13 || _map1[coord.Y + 1][coord.X] == '#' || _map1[coord.Y + 1][coord.X] == '|')
        {
            return 0;
        }
        
    }

    // fclose(mp);
    return 1;
}
void godown()// gravity
{
    // mp = fopen("map1.txt", "r+");
    // char _map1[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map1[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR); 
    // }
    
    while(coord.Y < 13 || _map1[coord.X][coord.Y+1] != '#' && _map1[coord.X][coord.Y+1] != '|' && _map1[coord.X][coord.Y+1] != ' ') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd'; 
            goleftorright('d', 1);
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            goleftorright('a', 1);
        }
        int j = whathappenY(1);
        if(j == 0)
        {
            break;
        }
        gotoxy(coord.X, coord.Y + 1);
        Sleep(100);
    }
}
void goleftorright(char ch, int result)
{
    FILE *mp;
    if(result == 2)// don't going to jump 
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX(ch);
            int j = whathappenY(1);
            if(i == 0 )
            {
                return;
            }
            if(j != 0)
            {
                godown();
            }
            Sleep(100);
            gotoxy(coord.X - 1, coord.Y);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX(ch);
            int j = whathappenY(ch);
            if(i == 0)
            {
                return;
            }
            if(j != 0)
            {
                godown();
            }
            Sleep(100);
            gotoxy(coord.X + 1, coord.Y);   
        }
    }
    else if(result == 0)// that mine mario during a jump
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX(ch);
            int j = whathappenY(0);
            if(i == 0 || j ==0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X - 1, coord.Y);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX(ch);
            int j = whathappenY(0);
            if(i == 0 || j == 0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X + 1, coord.Y);   
        }
    }
    else if(result == 1)// that mine mario going to fall
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX(ch);
            int j = whathappenY(1);
            if(i == 0 || j ==0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X - 1, coord.Y);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX(ch);
            int j = whathappenY(1);
            if(i == 0 || j == 0)
            {
                return;
            }
            Sleep(100);
            gotoxy(coord.X + 1, coord.Y);   
        }
    }
}

void mariojump()
{
    // FILE *mp = fopen("map1.txt", "r+");
    // char _map1[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map1[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR);
    // }
    int result = 0;
    for(int i = 0; i < 4; i++)//going to jump
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // ch = 'd';
            int z = whathappenX('d');
            if(z != 0)
                goleftorright('d', 0);
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX('a');
            if(z != 0)
                goleftorright('a', 1);
        }
        
        int j = whathappenY(result);
        if(j == 0)
        {
            break;
        }
        
        gotoxy(coord.X, coord.Y - 1);
        Sleep(100);
    }
    result = 1;
    while(coord.Y < 13 || _map1[coord.X][coord.Y+1] != '#' || _map1[coord.X][coord.Y+1] != '|' || _map1[coord.X][coord.Y+1] != ' ') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX('a');
            if(z != 0)
                goleftorright('d', 1);
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX('a');
            if(z != 0)
                goleftorright('a', 1);
        }
        int j = whathappenY(result);
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
    mapone(mp1);
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
        char ch;
        if((GetAsyncKeyState('D') & 0x8000))
        {
            ch = 'd';
            goleftorright(ch, 2);
        }
        if((GetAsyncKeyState('A') & 0x8000))
        {   
            ch = 'a';
            goleftorright(ch, 2);
        }
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            mariojump();
        }

    
    }
    return 0;
}
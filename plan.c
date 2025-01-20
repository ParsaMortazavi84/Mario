#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<windows.h>
//map1
//culmn 128
//row 14
//for the block indestructible #
// for the block destructible  %
// for block coin 8
// for block  gharch &
//for coin $
// for wide flower @
// for spout |
// for normal enemy ( or ) that was depends on what's it's direction
// the invicible enemy   D

// for the flag {
// mario M
void map1(FILE *mp1)
{
    char map1[14][130], temp[130];
    int i = 0;
    while(i<14 && fgets(map1[i], 130, mp1) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    for(i = 0; i < 14; i++)
        printf("%s", map1[i]);
    //move

    
}
void setcursorposition(SHORT x, SHORT y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}
void whathappen(FILE *map, SHORT  x, SHORT y)
{
    
}

int main ()
{
    FILE *mp1 = fopen("map1.txt", "r+");
    map1(mp1);

    COORD player = {2, 13};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), player);
    int x = 0, y = 0;
    char ch;
    while(kbhit())
    {
        ch = getch();
        if(ch == "a" || ch == "A")
            player.X--;
        else if(ch == "d" || ch == "D")
            player.X++;
        else if(ch == "s" || ch == "S")
            player.Y++;        
        else if(ch == " ")
            whathappen(map1, player.X, player.Y);    

    }    
    return 0;
}
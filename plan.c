#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<time.h>
#include <string.h>
#include <pthread.h>
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
            if(map1[i][j] == '8')
            {
                srand(time(0));
                valuecoin[i][j] = (rand() % 5) + 1;
            }
            else{
                valuecoin[i][j] = 0;
            }
        }
    }
    for(i = 0; i < 14; i++){
        for(int j = 0; j < 130; j++)
        {
            if(map1[i][j] == '#')
            {
                printf("\xF0\x9F\xA7\xB1");  // UTF-8 encoded bytes for 🧱
            }
            else if(map1[i][j] == '|')
            {
                printf("\xF0\x9F\x8C\xB5");  // UTF-8 encoded bytes for 🌵
            }
            else if(map1[i][j] == '8')
            {
                printf("\xF0\x9F\x92\xB0");  // UTF-8 encoded bytes for 💰
            }
            else{
                printf("%c", map1[i][j]);
            }
        }
    }   

    fclose(mp1);    
    //move

    
}
#include "common.h"

FILE *fgame;
time_t t;
time_t start_time;
time_t t_2;

// because we in line 1 write the effects so all y_logic2 plus 1 coord is a public variable

COORD coord = {7, 10};
COORD effects = {0, 28};
COORD  time1 = {0, 29};

struct infogame temp_2;
char _map2[27][65];
char valuecoin[27][65];

int x_logic2 = 4;
int y_logic2 = 12;

int life = 3;
int score = 0;
int coin = 0;
int lose = 0;
int victory = 0;
int shild = 0;
int second = 0;
int minute = 0;

int t_first2 = 1;

void findinfogame2(FILE *fgame)// if num == 1 mean player want to start new game
{
    struct infogame temp;
    while(fread(&temp, sizeof(struct infogame), 1, fgame) == 1)
    {
        if(strcmp(temp.name, Name) == 0)
        {
            temp_2.count2 = 1;
            
            //temp_2.gameResults2 = (struct result*) realloc(temp_2.gameResults2, sizeof(struct result));

            temp_2.gameResults2[temp_2.count2-1].lose = 0;
            temp_2.gameResults2[temp_2.count2-1].victory = 0;
        }

    } 
}

void reloadgame2(FILE *fgame)// if num == 2 mean player want to egain want to play this part
{
    struct infogame temp;
    while(fread(&temp, sizeof(struct infogame), 1, fgame) == 1)
    {
        if(strcmp(temp.name, Name) == 0)
        {
            temp_2.count2 += 1;
            
            //temp_2.gameResults2 = (struct result*) realloc(temp_2.gameResults2, sizeof(struct result));

            struct result temp2 = temp_2.gameResults2[temp_2.count2-1];

            lose = temp2.lose;
            victory = temp2.victory;
        }
    }
}

int writeinfile2(FILE *fgame)
{
    struct infogame temp;
    
    fseek(fgame, 0, SEEK_SET);
    while(fread(&temp, sizeof(struct infogame), 1, fgame) == 1)
    {
        if(strcmp(temp.name, Name) == 0)
        {
            break;
        }
    }

    fseek(fgame, -(long)sizeof(struct infogame), SEEK_CUR);
    
    fwrite(&temp_2, sizeof(struct infogame), 1, fgame);

}

void showinfogame2(FILE *fgame) {
    struct infogame temp;
    system("cls");
    fseek(fgame, 0, SEEK_SET);
    while (fread(&temp, sizeof(struct infogame), 1, fgame) == 1) {
        if (strcmp(temp.name, Name) == 0) {

            // struct result *pTmp = temp.pHead2;// part2
            // struct distinction *pTmp2;
            

            int i = 1;
            while ( i <= temp_2.count2) {
                //  کشیدن خط بالا
                struct result temp2 = temp_2.gameResults2[0];
                if(temp2.victory > 0){
                    printf("+--------+---------+-------+------+\n");
                    printf("| %-6s | %-7s | %-5s | %-4s |\n","Game", "victory", "score", "coin");//چپ چین کردن عناوین با علامت منفی اینگونه فضای خالی را در سمت راست قرار می دهد
                }
                else{
                    printf("you don't have victory result");
                    Sleep(2000);
                    return;
                }

                int j = 1;
                // pTmp2 = pTmp ->pWin;
                struct distinction temp3;

                while(j <= temp2.victory)
                {
                    temp3 = temp2.pWin[j-1];
                    printf("+--------+---------+-------+------+\n");
                    printf("| %-6d | %-7d | %-5d | %-4d |\n", i, j, temp3.score, temp3.coin);
                    j++;
                }
                if(temp2.lose > 0)
                {
                    printf("+--------+---------+-------+------+\n");
                    printf("| %-6s | %-4s | %-5s | %-4s |\n", "Game", "lose", "score", "coin");

                }
                else{
                    printf("you don't have lose result");
                    Sleep(2000);
                    return;
                }
                j = 1;
                
                while(j <= temp2.lose)
                {
                    temp3 = temp2.plose[j-1];
                    printf("+--------+---------+-------+------+\n");
                    printf("| %-6d | %-4d | %-5d | %-4d |\n", i, j, temp3.score, temp3.coin);
                    j++;
                }
                i++;
            }


            return;  
        }
    }
   
}

void maptwo(FILE *mp2)
{

    int i = 0;
    while(i<27 && fgets(_map2[i], 65, mp2) != NULL)
    {
        i++;
        //fseek(mp2, 1, SEEK_CUR);
    }
    for(int j = 0; j < 27; j++)
    {
        for(int k = 0; k < 65; k++)
        {
            if(_map2[j][k] == '8')
            {
                srand(time(0));
                valuecoin[j][k] = (rand() % 5) + 1;
            }
            else if(_map2[j][k] == '%')
            {
                srand(time(0));
                int q = (rand() % 5) + 1;//because it's percent is 20%
                if(q == 1)
                {
                    valuecoin[j][k] = 1;
                }
            }
            else{
                valuecoin[j][k] = 0;
            }
        }
    }
    
    
    SetConsoleOutputCP(CP_UTF8);
    
    for(i = 0; i < 27; i++)
    {
        for(int j = 0; j < 63; j++)
        {
            
            if(_map2[i][j] == ' ')
            {
                printf("  ");
            }
            else if(_map2[i][j] == '#')
            {
                printf("🧱");
            }
            else if(_map2[i][j] == '$')
            {
                printf("🪙");
            }
            else if(_map2[i][j] == '(')
            {
                printf("🐙");
            }
            else if(_map2[i][j] == '|')
            {
                printf("🟢");
            }
            else if(_map2[i][j] == '%')
            {
                printf("🟧");
            }
            else if(_map2[i][j] == '8')
            {
                printf("🟨");
            }
            else if(_map2[i][j] == '!')
            {
                printf("🦖");
            }
            else if(_map2[i][j] == 'S')
            {
                printf("🛡️");
            }
            else if(_map2[i][j] == '{')
            {
                printf("🚩");
            }
            else if(_map2[i][j] == 'L')
            {
                printf("🟠");
            }
            else{
                printf(" ");
                _map2[i][j] = ' ';
            }
            
        }
        printf("\n");
    }
        
    printf("Name: %s life: %d victory: %d lose: %d score: %d coin: %d\n", Name, life, victory, lose, score, coin);// یادت نره اسم را رنگی کنی
        

    fclose(mp2);    
    //move
    
}

int is_alive2(int life)
{
    if(life == 0)
    {
        lose += 1;
        
        temp_2.gameResults2[temp_2.count2-1].lose += 1;

        lose = temp_2.gameResults2[temp_2.count2-1].lose;

        //temp_2.gameResults2[temp_2.count2-1].plose = (struct distinction*)realloc(temp_2.gameResults2, sizeof(struct distinction));

        temp_2.gameResults2[temp_2.count2-1].plose[lose-1].coin = coin;
        temp_2.gameResults2[temp_2.count2-1].plose[lose-1].score = score;
        

        
        system("cls");
        printf("GAME OVER");
        return 4;// mean you are game over
    }
    else{
        gotoxy2(7, 11);
        x_logic2 = 4;
        y_logic2 = 12;

        return 1;
    }
}

void clear2(int x, int y)// for distroy the coin bloke and the 20 present bloke
{
    COORD bloke;
    bloke.X = x;
    bloke.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bloke);
    printf(" ");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
// movement i should difine for the way of move of enemy
int abilitygame2(SHORT X, SHORT Y, int result)//result mean the mario go up or down or left and right// result 0 up // result 1 down // result 2 left and  right
{
    // the comments in this func is a idea but i don't use them yet
    static time_t t2;
     if(_map2[y_logic2][x_logic2] == '$'){
        coin += 1;
        updateresult2();
        _map2[y_logic2][x_logic2] = ' ';
    }
    else if(_map2[y_logic2][x_logic2] == 'S' )// shild i plus one life1 
    {
        shild = 1;
    }  
    else if(_map2[y_logic2][x_logic2] == '(' && shild == 0)// simple enemy in _map2 becase it is an array X+1 -> X all of them minese 1 (plus -1) Y -> Y-1
    {
        life -= 1;
        updateresult2();
        int d = is_alive2(life);
        if(d == 4)
        {
            return 4;
        }

    }
    else if(_map2[y_logic2][x_logic2] == '(' && shild == 1)
    {
        shild = 0;
        gotoxy2(7, 11);
        x_logic2 = 4;
        y_logic2 = 12;
    }
    else if(_map2[y_logic2+1][x_logic2] == '(' && result == 1)// simple enemy  X->X-1  Y+1 -> Y
    {
        //static int i = 100;
        static int i = 0;
        if(i == 0){
            time(&t_2);
            score += 100;// give score1 
            updateresult2();

            _map2[y_logic2+1][x_logic2] = ' ';
            

        }
        else{
            time(&t2);
            if(difftime(t2, t_2) <= 5)
            {
                i *= 2; 
                if(i > 400)
                    i = 400;
                score += i;
                updateresult2();
                _map2[y_logic2+1][x_logic2] = ' ';
                t_2 = t2;
            }
            else{
                i = 100;
                score += i;
                updateresult2();
                _map2[y_logic2+1][x_logic2] = ' ';
                t_2 = t2;
            }
        }
    }
    else if(result == 2 && _map2[y_logic2][x_logic2+1] == '!' && shild == 0)// X & Y -> X-1 & Y-1  X+1 -> X
    {
        life -= 1;
        updateresult2();
        int d = is_alive2(life);
        if(d == 4)
        {
            exit(0);
        }
        gotoxy2(7, 11);
        x_logic2 = 4;
        y_logic2 = 12;
        
    }
    else if(_map2[y_logic2][x_logic2] == '!' || _map2[y_logic2][x_logic2+1] == '!' && shild == 1)
    {
        shild = 0;
        gotoxy2(7, 11);
        y_logic2 = 4;
        y_logic2 = 12;
    }
    else if(_map2[y_logic2-1][x_logic2] == '8' && result == 0)// X & Y-1 -> X-1 & Y-2
    {
        valuecoin[y_logic2-1][x_logic2] -= 1;// X & Y-1 -> X-1 & Y-2
        coin += 1;
        updateresult2();
        if(valuecoin[y_logic2-1][x_logic2] == 0)// X & Y-1 -> X-1 & Y-2
        {
            clear2(X, y_logic2-1);//that meen the coin1 is over//that's correct it work on map

            _map2[y_logic2][x_logic2 - 1] == ' ';// X & Y -> X-1 & Y-1
        }
    }
    else if(_map2[y_logic2-1][x_logic2] == '%' && result == 0)// X & Y-1 -> X-1 & Y-1
    {
        if(valuecoin[y_logic2-1][x_logic2] == 1)
        {
            coin += 1;
            updateresult2();
            clear2(x_logic2, y_logic2-1);
            _map2[y_logic2-1][x_logic2 - 1] = ' ';
            valuecoin[y_logic2-1][x_logic2] -= 1;
        } 
    }
    else if(_map2[y_logic2][x_logic2] == '{')// when mario catch the flat
    {
        victory += 1;
        //return 5;
        system ("cls");
        printf("you won this part 1");
        Sleep(2000);
        return 5;
        //return 2;// 2 mean you can go to part two or again play this time
    }
    else if(x_logic2 == 27 && y_logic2 == 9)
    {
        gotoxy2(55, 12);
        x_logic2 = 28;
        y_logic2 = 13;
        godown2();
        
    }
    else if(x_logic2 == 23 && y_logic2 == 4)
    {
        gotoxy2(115, 3);
        x_logic2 = 58;
        y_logic2 = 4;
        int d = godown2();
        if(d == 4)
            return 4;
        else if(d == 5)
            return 5;
    }
    else if(x_logic2 == 46 && y_logic2 == 25)
    {
        gotoxy2(91, 10);
        x_logic2 = 46;
        y_logic2 = 12;
        godown2();
        
    }
    return 0;
}

void setcursorposition2(SHORT x, SHORT y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

int whathappenX2(char ch)//move in the X way
{
    // mp2 = fopen("map1.txt", "r+");
    // char _map2[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map2[i], 130, mp2) != NULL)
    // {
    //     i++;
    //     //fseek(mp2, 1, SEEK_CUR);
    // }
    if(ch == 'a' || ch == 'A')
    {
        
        if(_map2[y_logic2][x_logic2 - 1] == '#' || _map2[y_logic2][x_logic2 - 1] == '|' && _map2[y_logic2][x_logic2 - 1] == 'L')
        {
            return 0;
        }
        else if(_map2[y_logic2][x_logic2 - 1] == ')')
        {
            life -= 1;
            int d = is_alive2(life);
            if (d == 4)
            {
                return 4;
            }
            else if (d == 5)
            {
                return 5;
            }
            return 0;
        }
        else if(_map2[y_logic2][x_logic2 - 1] == '!')
        {
            life -= 1;
            int d = is_alive2(life);
            if (d == 4)
            {
                return 4;
            }
            else if (d == 5)
            {
                return 5;
            }
            return 0;
        }
    }
    else if(ch == 'd' || ch == 'D')
    {
        if(_map2[y_logic2][x_logic2 - 1] == '#' || _map2[y_logic2][x_logic2 - 1] == '|' && _map2[y_logic2][x_logic2 - 1] == 'L' )
        {
            return 0;
        }
        else if(_map2[y_logic2][x_logic2 + 1] == ')' && shild == 0)// don't eat the enemy
        {
            life -= 1;
            int d = is_alive2(life);
            if (d == 4)
            {
                return 4;
            }
            return 0;
        }
        else if(_map2[y_logic2][x_logic2 + 1] == '!' && shild == 0)
        {
            life -= 1;
            int d = is_alive2(life);
            if (d == 4)
            {
                return 4;
            }
            return 0;
        }
    }
    
    int d = abilitygame2(x_logic2, y_logic2, 2);
    if(d == 4)
    {
        return 4;
    }
    else if (d == 5){
        return 5;
    }
    return 1;
}

int whathappenY2(int result)
{
    
    if(result == 0)
    {
        if(_map2[y_logic2 - 1][x_logic2] == '#' || _map2[y_logic2 - 1][x_logic2] == '|' || _map2[y_logic2 - 1][x_logic2] == 'L' || y_logic2 <= 0 )
        {
            return 0;
        }
        else if(_map2[y_logic2 - 1][x_logic2] == '8')// coin block
        {
            if(valuecoin[y_logic2 - 1][x_logic2] > 1)
            {
                valuecoin[y_logic2 - 1][x_logic2] -= 1;
                coin += 1;
                updateresult2();
                return 0;
            }
            else if(valuecoin[y_logic2 - 1][x_logic2] == 1)
            {
                coin += 1;
                updateresult2();
                _map2[y_logic2 - 1][x_logic2] = ' ';
            }   
            
            else{
                return 0;
            }
        }
        else if(_map2[y_logic2 - 1][x_logic2] == '%')
        {
            if(valuecoin[y_logic2 - 1][x_logic2] == 1)
            {
                valuecoin[y_logic2 - 1][x_logic2]--;
                coin += 1;
                updateresult2();
                _map2[y_logic2 - 1][x_logic2] = ' ';
            }
            else{
                return 0;
            }
            
        }
        else{
            int d = abilitygame2(x_logic2, y_logic2, 0);
            if(d == 4)
            {
                return 4;
            }
            else if ( d == 5)
                return 5;

            return 1;
        }
        //abilitygame2(name, fgame, )
    }
    else if(result == 1)
    {
        if((y_logic2 + 1) >= 13 || _map2[y_logic2 + 1][x_logic2] == '#' || _map2[y_logic2 + 1][x_logic2] == '|' || _map2[y_logic2 + 1][x_logic2] == 'L' || _map2[y_logic2 + 1][x_logic2] == '8' || _map2[y_logic2 + 1][x_logic2] == '%')
        {
            return 0;
        }
        else{
            int d = abilitygame2(x_logic2, y_logic2, 1);
            if(d == 4)
                return 4;
            else if( d == 5)
                return 5;    
            return 1;
        }
        
    }
    //abilitygame2
    // fclose(mp);

}

int godown2()// gravity
{
    // mp = fopen("map1.txt", "r+");
    // char _map2[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map2[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp2, 1, SEEK_CUR); 
    // }
    
    while(y_logic2 < 13 || _map2[y_logic2+1][x_logic2] != '#' && _map2[y_logic2+1][x_logic2] != '|' && _map2[y_logic2+1][x_logic2] == 'L' && _map2[y_logic2+1][x_logic2] != ' ') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd'; 
            int d = goleftorright2('d', 1);
            if(d == 4)
                return 4;
            else if( d == 5)
                return 5;
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int d = goleftorright2('a', 1);
            if(d == 4)
                return 4;
            else if( d == 5)
                return 5;
        }
        int j = whathappenY2(1);
        if(j == 0)
        {
            break;
        }
        else if( j == 4)
            return 4;
        else if( j == 5)
            return 5;
        //abilitygame2(name, fgame, x_logic2, y_logic2, 1);
        gotoxy2(coord.X, coord.Y + 1);
        y_logic2 += 1;
        Sleep(100);
    }
}

int goleftorright2(char ch, int result)
{
    FILE *mp;
    if(result == 2)// don't going to jump 
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX2(ch);
            int j = whathappenY2(1);
            if(i == 0 )
            {
                return 0;
            }
            else if(i == 4)
                return 4;
            else if( i == 5)// mean you win
                return 5;
            if(j != 0)
            {
                int d = godown2();
                if(d == 4)
                    return 4;
                else if(d == 5)
                    return 5; 
            }
            else if(j == 4)
                return 4;
            else if(j == 5)
                return 5;    
            //abilitygame2(name, fgame, x_logic2, y_logic2, 2);
            Sleep(100);
            gotoxy2(coord.X - 2, coord.Y);
            x_logic2 -= 1;
            Sleep(100);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX2(ch);
            int j = whathappenY2(ch);
            if(i == 0)
            {
                return 0;
            }
            else if(i == 4)
                return 4;
            else if(i == 5)
                return 5;     
            if(j != 0)
            {
                int d = godown2();
                if(d == 4)
                    return 4;
                else if(d == 5)
                    return 5;
            }
            else if(j == 4)
                return 4;
            else if(j == 5)
                return 5;     
            //abilitygame2(name, fgame, x_logic2, y_logic2, 2);
            Sleep(100);
            gotoxy2(coord.X + 2, coord.Y);
            x_logic2 += 1;
            Sleep(100);   
        }
    }
    else if(result == 0)// that mine mario during a jump
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX2(ch);
            int j = whathappenY2(0);
            if(i == 0 || j ==0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5;     
            //abilitygame2(name, fgame, x_logic2, y_logic2, 2);
            Sleep(100);
            gotoxy2(coord.X - 2, coord.Y);
            x_logic2 -= 1;
            Sleep(100);
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX2(ch);
            int j = whathappenY2(0);
            if(i == 0 || j == 0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5; 

            Sleep(100);
            gotoxy2(coord.X + 2, coord.Y);
            x_logic2 += 1;
            Sleep(100);   
        }
    }
    else if(result == 1)// that mine mario going to fall
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX2(ch);
            int j = whathappenY2(1);
            if(i == 0 || j ==0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5; 

            Sleep(100);
            gotoxy2(coord.X - 2, coord.Y);
            x_logic2 -= 1;
            Sleep(100);

        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX2(ch);
            int j = whathappenY2(1);
            if(i == 0 || j == 0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5; 

            Sleep(100);
            gotoxy2(coord.X + 2, coord.Y);
            x_logic2 += 1;
            Sleep(100);   
        }
    }
}

int mariojump2()
{
    // FILE *mp = fopen("map1.txt", "r+");
    // char _map2[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map2[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp2, 1, SEEK_CUR);
    // }
    int result = 0;
    for(int i = 0; i < 4; i++)//going to jump
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // ch = 'd';
            int z = whathappenX2('d');
            if(z != 0)
                goleftorright2('d', 0);
            else if( z == 4)
                return 4;
            else if( z == 5)
                return 5;        
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX2('a');
            if(z != 0)
                goleftorright2('a', 1);
            else if( z == 4)
                return 4;
            else if( z == 5)
                return 5;        
        }
        
        int j = whathappenY2(result);
        if(j == 0)
        {
            break;
        }
        else if( j == 4 )
            return 4;
        else if( j == 5)
            return 5;
        gotoxy2(coord.X, coord.Y - 1);
        y_logic2 -= 1;
        Sleep(100);
    }
    result = 1;
    while(y_logic2 < 13 || _map2[y_logic2+1][x_logic2] != '#' || _map2[y_logic2+1][x_logic2] != '|' || _map2[y_logic2+1][x_logic2] != ' ' ||
          _map2[y_logic2+1][x_logic2] == 'L' ||_map2[y_logic2+1][x_logic2] != '%' || _map2[y_logic2+1][x_logic2] != '8') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX2('a');
            if(z != 0)
                goleftorright2('d', 1);
            else if( z == 4)
                return 4;    
            else if( z == 5)
                return 5;     

        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX2('a');
            if(z != 0)
                goleftorright2('a', 1);
            else if( z == 4)
                return 4;
            else if( z == 5)
                return 5;         
        }
        int j = whathappenY2(result);
        if(j == 0)
        {
            break;
        }
        else if( j == 4)
            return 4;
        else if( j == 5)
            return 5;     
        gotoxy2(coord.X, coord.Y + 1);
        y_logic2 += 1;
        Sleep(100);
    }
    return 0;
}

void gotoxy2(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf(" ");
    x_logic2 = x;
    y_logic2 = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    printf("M");

}

void updateresult2()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), effects);
    char space[100] = {                                                                                                    };
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), effects);
    printf("Name: %s life: %d victory: %d lose1: %d score: %d coin: %d", Name, life, victory, lose, score, coin);

}

void timegame2()
{
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), time1);
    char space[20] = {                    };
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), time1);
    printf("time: %d:%d",minute ,second);
}

int GAME2(int dicision){// we should get a num whitch recognize dicision of player for reload a game or stert a new game
    time_t t3;
    time_t t4;
    time(&start_time);
    FILE *mp2 = fopen("map2.txt", "r+");
    FILE *fgame = fopen("fgame.bin", "r+b");
    if(fgame == NULL)
    {
        fgame = fopen("fgame.bin", "w+b");
    }
    
    if (dicision == 1)// mesan player want to start a new game
    {
        findinfogame2(fgame);
    }
    else if(dicision == 2)
    {
        reloadgame2(fgame);
    }

    findinfogame2(fgame);
    system("cls");
    maptwo(mp2);
    

    gotoxy2(5, 11);    

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
            int d = goleftorright2(ch, 2);
            if( d == 4){// you lose
                writeinfile2(fgame);
                return 4;
            }    
            else if( d == 5){// you win
                writeinfile2(fgame);
                return 5;
            }
            else{
                continue;
            }  
        }
        if((GetAsyncKeyState('A') & 0x8000))
        {   
            ch = 'a';
            int d = goleftorright2(ch, 2);
            if( d == 4){// you lose
                writeinfile2(fgame);
                return 4;
            }    
            else if( d == 5){// you win
                writeinfile2(fgame);
                return 5;
            } 
            else{
                continue;
            }      
        }
        if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            int d = mariojump2();
            if( d == 4){// you lose
                writeinfile2(fgame);
                return 4;
            }    
            else if( d == 5){// you win
                writeinfile2(fgame);
                return 5;
            }   
            else{
                continue;
            }    
        }
        //time
        // if(t_first2 == 0){
        //     time(&t3);
        //     time_t dif = difftime(t3, start_time);
        //     if(dif >= 1)
        //     {
        //         second += 1;
        //         if(second == 60)
        //         {
        //             minute += 1;
        //             second = 0;
        //             timegame2();
        //         }
        //         else{
        //             timegame2();
        //         }
        //         t4 = t3;
        //         t_first2++;
        //     }
        //     else{
        //         continue;
        //     }
        //     t4 = t3;
        //     t_first2++; 
        // }
        // else{
        //     time(&t3);
        //     time_t dif = difftime(t3, t4);
        //     if(dif >= 1)
        //     {

        //         second += 1;
        //         if(second == 60)
        //         {
        //             minute += 1;
        //             second = 0;
        //             timegame2();
        //         }
        //         else{
        //             if(second % 10 == 0)
        //                 timegame2();
        //             t4 = t3;    
        //         }
        //     }
        //     else{
        //         continue;
        //     }
            
        // }
        
    }
    return 0;
}
#include "common.h"

FILE *fgame1;
time_t t_1;
time_t start_time_1;

//COORD spout = {111, 10};// notice for my self :because we in line 1 write the effects_1 so all coord_1.Y plus 1 
COORD coord_1 = {5, 14};
COORD effects_1 = {0, 14};
COORD time1_1 = {124, 14};

int x_logic1 = 4;
int y_logic1 = 12;

struct infogame temp_1;

//struct result *temp2_1;

char _map1[14][67];

char valuecoin1[14][67];
int life1 = 3;
int score1 = 0;
int coin1 = 0;
int lose1 = 0;
int victory1 = 0;
int shild1 = 0;
int second1 = 0;
int minute1 = 0;

void findinfogame1(FILE *fgame1)// if num == 1 mean player want to start new game
{
    
    
    while(fread(&temp_1, sizeof(struct infogame), 1, fgame1) == 1)
    {
        if(strcmp(temp_1.name, Name) == 0)
        {
            temp_1.count1 = 1;
            
            //temp_1.gameResults1 = (struct result*) realloc(temp_1.gameResults1, sizeof(struct result));

            temp_1.gameResults1[temp_1.count1-1].lose = 0;
            temp_1.gameResults1[temp_1.count1-1].victory = 0;

            // struct infogame *pNew = (struct infogame*)malloc(sizeof(struct infogame));
            
            
        }

    } 
}

void reloadgame1(FILE *fgame1)// if num == 2 mean player want to egain want to play this part
{

    while(fread(&temp_1, sizeof(struct infogame), 1, fgame1) == 1)
    {
        if(strcmp(temp_1.name, Name) == 0)
        {
            temp_1.count1 += 1;
            
            //temp_1.gameResults1 = (struct result*) realloc(temp_1.gameResults1, sizeof(struct result));

            struct result temp2 = temp_1.gameResults1[temp_1.count1-1];

            lose1 = temp2.lose;
            victory1 = temp2.victory;
        }
    }
}

int writeinfile1(FILE *fgame1)// use for right information in file by this func
{
    struct infogame temp;
    
    fseek(fgame1, 0, SEEK_SET);
    while(fread(&temp, sizeof(struct infogame), 1, fgame1) == 1)
    {
        if(strcmp(temp.name, Name) == 0)
        {
            break;
        }
    }

    fseek(fgame1, -(long)sizeof(struct infogame), SEEK_CUR);
    
    fwrite(&temp_1, sizeof(struct infogame), 1, fgame1);

}

void showinfogame1(FILE *fgame1) {

    struct infogame temp;
    system("cls");
    fseek(fgame1, 0, SEEK_SET);
    while (fread(&temp, sizeof(struct infogame), 1, fgame1) == 1) {
        if (strcmp(temp.name, Name) == 0) {

            //struct result *pTmp = temp.pHead1;
            
            //struct distinction *pTmp2;
            

            int i = 1;
            while ( i <= temp_1.count1) {
                //  کشیدن خط بالا
                struct result temp2 = temp_1.gameResults1[0];
                if(temp2.victory > 0){
                    printf("+--------+---------+-------+------+\n");
                    printf("| %-6s | %-7s | %-5s | %-4s |\n", "Game", "victory", "score", "coin");//چپ چین کردن عناوین با علامت منفی اینگونه فضای خالی را در سمت راست قرار می دهد
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


void mapone(FILE *mp1)
{

    int i = 0;
    while(i<14 && fgets(_map1[i], 67, mp1) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    
    for(int j = 0; j < 14; j++)
    {
        for(int k = 0; k < 65; k++)
        {
            if(_map1[j][k] == '8')
            {
                srand(time(0));
                valuecoin1[j][k] = (rand() % 5) + 1;
            }
            else{
                valuecoin1[j][k] = 0;
            }
        }
    }
    // for(i = 0; i < 14; i++)
    //     printf("%s", _map1[i]);


    SetConsoleOutputCP(CP_UTF8);
    
    for(i = 0; i < 14; i++)
    {
        for(int j = 0; j < 65; j++)
        {
            
            if(_map1[i][j] == ' ')
            {
                printf("  ");
            }
            else if(_map1[i][j] == '#')
            {
                printf("🧱");
            }
            else if(_map1[i][j] == '$')
            {
                printf("🪙");
            }
            else if(_map1[i][j] == '(')
            {
                printf("🐙");
            }
            else if(_map1[i][j] == '|')
            {
                printf("🟢");
            }
            else if(_map1[i][j] == '%')
            {
                printf("🟧");
            }
            else if(_map1[i][j] == '8')
            {
                printf("🟨");
            }
            else if(_map1[i][j] == '!')
            {
                printf("🦖");
            }
            else if(_map1[i][j] == 'S')
            {
                printf("🛡️");
            }
            else if(_map1[i][j] == '{')
            {
                printf("🚩");
            }
            
        }
        printf("\n");
    }
        
    printf("Name: %s life: %d victory: %d lose: %d score: %d coin: %d", Name, life1, victory1, lose1, score1, coin1);// یادت نره اسم را رنگی کنی
        

    fclose(mp1);
       
    //move

    
}

int is_alive1(int life1)
{
    if(life1 == 0)
    {
        
        
        temp_1.gameResults1[temp_1.count1-1].lose += 1;

        lose1 = temp_1.gameResults1[temp_1.count1-1].lose;
        //temp_1.gameResults1[temp_1.count1-1].plose = (struct distinction*)realloc(temp_1.gameResults1, sizeof(struct distinction));

        temp_1.gameResults1[temp_1.count1-1].plose[lose1-1].coin = coin1;
        temp_1.gameResults1[temp_1.count1-1].plose[lose1-1].score = score1;
        

        
        system("cls");
        printf("GAME OVER");
        return 4;// mean you are game over
    }
    else{
        gotoxy1(7, 12);
        x_logic1 = 4;
        y_logic1 = 12;
        return 1;
    }
}

void clear1(int x, int y)
{
    COORD bloke;
    bloke.X = x;
    bloke.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), bloke);
    printf(" ");
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_1);
}
// movement i should difine for the way of move of enemy
int abilitygame1(SHORT X, SHORT Y, int result)//result mean the mario go up or down or left and right// result 0 up // result 1 down // result 2 left and  right
{
    // the comments in this func is a idea but i don't use them yet
    time_t t2;
    if(_map1[y_logic1][x_logic1] == '$'){
        coin1 += 1;
        updateresult1();
        _map1[y_logic1][x_logic1] = ' ';
    }
    else if(_map1[y_logic1][x_logic1] == 'S' )// shild1 i plus one life1 
    {
        shild1 = 1;
    }  
    else if(_map1[y_logic1][x_logic1] == '(' && shild1 == 0)// simple enemy in _map1 becase it is an array X+1 -> X all of them minese 1 (plus -1) Y -> Y-1
    {
        life1 -= 1;
        updateresult1();
        int d = is_alive1(life1);
        if(d == 4)
        {
            return 4;
        }

    }
    else if(_map1[y_logic1][x_logic1] == '(' && shild1 == 1)
    {
        shild1 = 0;
        gotoxy1(7, 12);
        x_logic1 = 4;
        y_logic1 = 12;
    }
    else if(_map1[y_logic1+1][x_logic1] == '(' && result == 1)// simple enemy  X->X-1  Y+1 -> Y
    {
        //static int i = 100;
        static int i = 0;
        if(i == 0){
            time(&t_1);
            score1 += 100;// give score1 
            updateresult1();

            _map1[y_logic1+1][x_logic1] = ' ';
            

        }
        else{
            time(&t2);
            if(difftime(t2, t_1) <= 5)
            {
                i *= 2; 
                if(i > 400)
                    i = 400;
                score1 += i;
                updateresult1();
                _map1[y_logic1+1][x_logic1] = ' ';
                t_1 = t2;
            }
            else{
                i = 100;
                score1 += i;
                updateresult1();
                _map1[y_logic1+1][x_logic1] = ' ';
                t_1 = t2;
            }
        }
    }
    else if(result == 2 && _map1[y_logic1][x_logic1+1] == '!' && shild1 == 0)// X & Y -> X-1 & Y-1  X+1 -> X
    {
        life1 -= 1;
        updateresult1();
        int d = is_alive1(life1);
        if(d == 4)
        {
            exit(0);
        }
        gotoxy1(7, 12);
        x_logic1 = 4;
        y_logic1 = 12;
        
    }
    else if(_map1[y_logic1][x_logic1] == '!' || _map1[y_logic1][x_logic1+1] == '!' && shild1 == 1)
    {
        shild1 = 0;
        gotoxy1(7, 12);
        x_logic1 = 4;
        y_logic1 = 12;
    }
    else if(_map1[y_logic1-1][x_logic1] == '8' && result == 0)// X & Y-1 -> X-1 & Y-2
    {
        valuecoin1[y_logic1-1][x_logic1] -= 1;// X & Y-1 -> X-1 & Y-2
        coin1 += 1;
        updateresult1();
        if(valuecoin1[y_logic1-1][x_logic1] == 0)// X & Y-1 -> X-1 & Y-2
        {
            clear1(X, y_logic1-1);//that meen the coin1 is over//that's correct it work on map

            _map1[y_logic1][x_logic1 - 1] == ' ';// X & Y -> X-1 & Y-1
        }
    }
    else if(_map1[y_logic1-1][x_logic1] == '%' && result == 0)// X & Y-1 -> X-1 & Y-1
    {
        if(valuecoin1[y_logic1-1][x_logic1] == 1)
        {
            coin1 += 1;
            updateresult1();
            clear1(X, y_logic1-1);
            _map1[y_logic1-1][x_logic1 - 1] = ' ';
            valuecoin1[y_logic1-1][x_logic1] -= 1;
        } 
    }
    else if(_map1[y_logic1][x_logic1] == '{')// when mario catch the flat
    {
        victory1 += 1;
        //return 5;
        temp_1.gameResults1[temp_1.count1-1].victory += 1;

        victory1 = temp_1.gameResults1[temp_1.count1-1].victory;
        //temp_1.gameResults1[temp_1.count1-1].plose = (struct distinction*)realloc(temp_1.gameResults1, sizeof(struct distinction));

        temp_1.gameResults1[temp_1.count1-1].pWin[victory1-1].coin = coin1;
        temp_1.gameResults1[temp_1.count1-1].pWin[victory1-1].score = score1;
        system ("cls");
        printf("you won this part 1");
        Sleep(2000);
        return 5;
        
    }
    else if(x_logic1 == 58 && y_logic1 == 9)
    {
        gotoxy1(49, 5);
        y_logic1 = 5;
        x_logic1 = 25;
        godown1();
        
    }

    //return 0;
    return 0;
}


void setcursorposition1(SHORT x, SHORT y)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD pos = {x, y};
    SetConsoleCursorPosition(hConsole, pos);
}

int whathappenX1(char ch)//move in the X way
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
        if(_map1[y_logic1][x_logic1 - 1] == '#' || _map1[y_logic1][x_logic1 - 1] == '|')
        {
            return 0;
        }
        else if(_map1[y_logic1][x_logic1 - 1] == ')' && shild1 == 0)
        {
            life1 -= 1;
            int d = is_alive1(life1);
            if (d == 4)
            {
                return 4;
            }
            
            return 0;
        }
        else if(_map1[y_logic1][x_logic1 - 1] == '!' && shild1 == 0)
        {
            life1 -= 1;
            int d = is_alive1(life1);
            if (d == 4)
            {
                return 4;
            }
            
            return 0;
        }
    }
    else if(ch == 'd' || ch == 'D')
    {
        if(_map1[y_logic1][x_logic1 + 1] == '#' || _map1[y_logic1][x_logic1 + 1] == '|')
        {
            return 0;
        }
        else if(_map1[y_logic1][x_logic1 + 1] == ')' && shild1 == 0)// don't eat the enemy
        {
            life1 -= 1;
            int d = is_alive1(life1);
            if (d == 4)
            {
                return 4;
            }
            return 0;
        }
        else if(_map1[y_logic1][x_logic1 + 1] == '!' && shild1 == 0)
        {
            life1 -= 1;
            int d = is_alive1(life1);
            if (d == 4)
            {
                return 4;
            }
            return 0;
        }
    }
    int d = abilitygame1(coord_1.X, coord_1.Y, 2);
    if (d == 4)
    {
        return 4;
    }
    if (d == 5)
    {
        return 5;
    }        
    // fclose(mp1);
    return 1;
}

int whathappenY1(int result)
{
    if(result == 0)// it mean go up
    {
        if(_map1[y_logic1 - 1][x_logic1] == '#' || _map1[y_logic1 - 1][x_logic1] == '|' || y_logic1 <= 0 )
        {
            return 0;
        }
        else if(_map1[y_logic1 - 1][x_logic1] == '8')// coin block
        {
            if(valuecoin1[y_logic1 - 1][x_logic1] > 1)
            {
                valuecoin1[y_logic1 - 1][x_logic1] -= 1;
                coin1 += 1;
                updateresult1();
                return 0;
            }
            else if(valuecoin1[y_logic1 - 1][x_logic1] == 1)
            {
                coin1 += 1;
                updateresult1();
                _map1[y_logic1 - 1][x_logic1] = ' ';
            }   
            
            else{
                return 0;
            }
        }
        else if(_map1[y_logic1 - 1][x_logic1] == '%')
        {
            if(valuecoin1[y_logic1 - 1][x_logic1] == 1)
            {
                valuecoin1[y_logic1 - 1][x_logic1]--;
                coin1 += 1;
                updateresult1();
                _map1[y_logic1 - 1][x_logic1] = ' ';
            }
            else{
                return 0;
            }
            
        }
        else{
            int d = abilitygame1(coord_1.X, coord_1.Y, 0);
            if(d == 4)
            {
                return 4;
            }
            else if(d == 5)
                return 5;

            return 1;
        }
        //abilitygame1(name, fgame, )
    }
    else if(result == 1)// fall
    {
        if((y_logic1 + 1) >= 13 || _map1[y_logic1 + 1][x_logic1] == '#' || _map1[y_logic1 + 1][x_logic1] == '|' || _map1[y_logic1 + 1][x_logic1] == '8' || _map1[y_logic1 + 1][x_logic1] == '%')
        {
            return 0;
        }
        else if(_map1[y_logic1 + 1][x_logic1] == '!' && shild1 == 0)
        {
            life1 -= 1;
            int d = is_alive1(life1);
            if (d == 4)
            {
                return 4;
            }
            return 0;
        }
        else{
            int d = abilitygame1(coord_1.X, coord_1.Y, 1);
            if(d == 4)
                return 4;
            else if(d == 5)
                return 5;    
            return 1;
        }
        
    }
    //abilitygame1
    // fclose1(mp);

}

int godown1()// gravity
{
    // mp = fopen("map1.txt", "r+");
    // char _map1[14][130];
    // int i = 0;
    // while(i < 14 && fgets(_map1[i], 130, mp) != NULL)
    // {
    //     i++;
    //     //fseek(mp1, 1, SEEK_CUR); 
    // }
    
    while(y_logic1 < 13 && _map1[x_logic1][y_logic1+1] != '#' && _map1[x_logic1][y_logic1+1] != '|' && _map1[x_logic1][y_logic1+1] != ' ') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd'; 
            int d = goleftorright1('d', 1);
            if(d == 4)
                return 4;
            else if( d == 5)
                return 5;
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int d = goleftorright1('a', 1);
            if(d == 4)
                return 4;
            else if( d == 5)
                return 5;
        }
        int j = whathappenY1(1);
        if(j == 0)
        {
            break;
        }
        else if( j == 4)
            return 4;
        else if( j == 5)
            return 5;
        //abilitygame1(name, fgame, coord_1.X, coord_1.Y, 1);
        gotoxy1(coord_1.X, coord_1.Y + 1);
        y_logic1 += 1;
        Sleep(100);
    }
}

int goleftorright1(char ch, int result)
{
    FILE *mp;
    if(result == 2)// don't going to jump 
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX1(ch);
            int j = whathappenY1(1);
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
                int d = godown1();
                if(d == 4)
                    return 4;
                else if(d == 5)
                    return 5;
            }
            else if(j == 4)
                return 4;
            else if(j == 5)
                return 5;    
            //abilitygame1(name, fgame, coord_1.X, coord_1.Y, 2);
            Sleep(100);
            gotoxy1(coord_1.X - 2, coord_1.Y);
            x_logic1 -= 1;
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX1(ch);
            int j = whathappenY1(ch);
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
                int d = godown1();
                if(d == 4)
                    return 4;
                else if(d == 5)
                    return 5;
            }
            else if(j == 4)
                return 4;
            else if(j == 5)
                return 5;     
            //abilitygame1(name, fgame, coord_1.X, coord_1.Y, 2);
            Sleep(100);
            gotoxy1(coord_1.X + 2, coord_1.Y);  
            x_logic1 += 1; 
        }
    }
    else if(result == 0)// that mine mario during a jump
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX1(ch);
            int j = whathappenY1(0);
            if(i == 0 || j ==0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5;     
            //abilitygame1(name, fgame, coord_1.X, coord_1.Y, 2);
            Sleep(100);
            gotoxy1(coord_1.X - 2, coord_1.Y);
            x_logic1 -= 1;
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX1(ch);
            int j = whathappenY1(0);
            if(i == 0 || j == 0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5; 

            Sleep(100);
            gotoxy1(coord_1.X + 2, coord_1.Y);   
            x_logic1 += 1;
        }
    }
    else if(result == 1)// that mine mario going to fall
    {
        if(ch == 'a' || ch == 'A')
        {
            int i = whathappenX1(ch);
            int j = whathappenY1(1);
            if(i == 0 || j ==0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5; 

            Sleep(100);
            gotoxy1(coord_1.X - 2, coord_1.Y);
            x_logic1 -= 1;
        }
        else if(ch == 'd' || ch == 'D')
        {
            int i = whathappenX1(ch);
            int j = whathappenY1(1);
            if(i == 0 || j == 0)
            {
                return 0;
            }
            else if(i == 4 || j == 4)
                return 4;
            else if(j == 5 || i == 5)
                return 5; 

            Sleep(100);
            gotoxy1(coord_1.X + 2, coord_1.Y);   
            x_logic1 += 1;
        }
    }
    return 0;
}

int mariojump1()
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
            int z = whathappenX1('d');
            if(z != 0)
                goleftorright1('d', 0);

            if( z == 4)
                return 4;
            else if( z == 5)
                return 5;     

        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX1('a');
            if(z != 0)
                goleftorright1('a', 1);
            if( z == 4)
                return 4;
            else if( z == 5)
                return 5;        
        }
        
        int j = whathappenY1(result);
        if(j == 0)
        {
            break;
        }
        else if( j == 4 )
            return 4;
        else if( j == 5)
            return 5;
        gotoxy1(coord_1.X, coord_1.Y - 1);
        y_logic1 -= 1;
        Sleep(100);
    }
    result = 1;
    while(coord_1.Y < 14 || _map1[y_logic1+1][x_logic1] != '#' || _map1[y_logic1+1][x_logic1] != '|' || _map1[y_logic1+1][x_logic1] != ' ' ||
          _map1[y_logic1+1][x_logic1] != '%' || _map1[y_logic1+1][x_logic1] != '8') //going to fall
    {
        if((GetAsyncKeyState('D') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX1('a');
            if(z != 0)
                goleftorright1('d', 1);
            else if( z == 4)
                return 4;    
            else if( z == 5)
                return 5;     

        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {
            // char ch = 'd';
            int z = whathappenX1('a');
            if(z != 0)
                goleftorright1('a', 1);
            else if( z == 4)
                return 4;
            else if( z == 5)
                return 5;         
        }
        int j = whathappenY1(result);
        if(j == 0)
        {
            break;
        }
        else if( j == 4)
            return 4;
        else if( j == 5)
            return 5;     
        gotoxy1(coord_1.X, coord_1.Y + 1);
        y_logic1 += 1;
        Sleep(100);
    }
    return 0;
}

void gotoxy1(int x, int y)
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_1);
    printf(" ");
    coord_1.X = x;
    coord_1.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord_1);
    printf("M");

}

void updateresult1()
{
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), effects_1);
    char space[70] = {                                                                      };
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), effects_1);
    printf("Name: %s life: %d victory: %d lose: %d score: %d coin: %d\n", Name, life1, victory1, lose1, score1, coin1);

}

void timegame1()
{
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), time1_1);
    char space[20] = {                    };
    
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), time1_1);
    printf("time: %d:%d",minute1 ,second1);
}

int GAME1(int dicision){

    //printf("yes");
    time_t t3;
    time_t t4;
    time(&start_time_1);
    FILE *mp1 = fopen("map1.txt", "r+");
    
    fgame1 = fopen("fgame.bin", "r+b");

    

    if (dicision == 1)// mesan player want to start a new game
    {
        findinfogame1(fgame1);
    }
    else if(dicision == 2)
    {
        reloadgame1(fgame1);
    }


    system("cls");
    findinfogame1(fgame1);
    mapone(mp1);
    //gotoxy1(128, 14);
    // printf("\n");

    gotoxy1(7, 12);    

    // remove cursuer
    CONSOLE_CURSOR_INFO cursurInfo;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleCursorInfo(hConsole, &cursurInfo);
    cursurInfo.bVisible = false;
    SetConsoleCursorInfo (hConsole, &cursurInfo);

    int t_first = 1;

    while(1){
        
        char ch;
        if((GetAsyncKeyState('D') & 0x8000))
        {
            
            ch = 'd';
            int d = goleftorright1(ch, 2);
            if( d == 4){// you lose1
                writeinfile1(fgame1);
                fclose(mp1);
                fclose(fgame1);
                return 4;
            }    
            else if( d == 5){// you win
                writeinfile1(fgame1);
                fclose(mp1);
                fclose(fgame1);
                return 5;
            }
            
        }
        else if((GetAsyncKeyState('A') & 0x8000))
        {   
            ch = 'a';
            int d = goleftorright1(ch, 2);
            if( d == 4){// you lose1
                writeinfile1(fgame1);
                fclose(mp1);
                fclose(fgame1);
                return 4;
            }    
            else if( d == 5){// you win
                writeinfile1(fgame1);
                fclose(mp1);
                fclose(fgame1);
                return 5;
            }   
            
        }
        else if(GetAsyncKeyState(VK_SPACE) & 0x8000){
            int d = mariojump1();
            if( d == 4){// you lose1
                writeinfile1(fgame1);
                fclose(mp1);
                fclose(fgame1);
                return 4;
            }    
            else if( d == 5){// you win
                writeinfile1(fgame1);
                fclose(mp1);
                fclose(fgame1);
                return 5;
            } 
              
        }
        //time
        //time
        if(t_first == 0){
            time(&t3);
            time_t dif = difftime(t3, start_time_1);
            if(dif >= 1)
            {
                second1 += 1;
                if(second1 == 60)
                {
                    minute1 += 1;
                    second1 = 0;
                    timegame1();
                }
                else{
                    timegame1();
                }
                t4 = t3;
                t_first++;
            }
            else{
                continue;
            }
            t4 = t3;
            t_first++; 
        }
        else{
            time(&t3);
            time_t dif = difftime(t3, t4);
            if(dif >= 1)
            {

                second1 += 1;
                if(second1 == 60)
                {
                    minute1 += 1;
                    second1 = 0;
                    timegame1();
                }
                else{
                    if(second1 % 10 == 0)
                        timegame1();
                    t4 = t3;    
                }
            }
            else{
                continue;
            }
            
        }
    }
    
}
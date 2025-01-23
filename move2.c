// // #include <stdio.h>
// // #include <windows.h>  // For GetAsyncKeyState()
// // #include <stdbool.h>  // For bool type
// // #include <process.h>  // For _beginthread()

// // bool running = true;

// // void key_listener(void* param) {
// //     while (running) {

// //         if ((GetAsyncKeyState(VK_SPACE) & 0x8000) && (GetAsyncKeyState('D') & 0x8000)) {
// //             printf("Both SPACE and D are pressed together!\n");
// //             // running = false;  // Stop the loop
// //         }
// //         else if((GetAsyncKeyState(VK_SPACE) & 0x8000))
// //             printf("space is pressed!\n");
// //         else if((GetAsyncKeyState('D') & 0x8000))  
// //             printf("D is pressed!\n");
// //         Sleep(50);  // Reduce CPU usage
// //     }
// // }

// // #include <stdio.h>
// // #include <wchar.h>
// // #include <locale.h>

// // int main() {
// //     setlocale(LC_ALL, "");  // Set locale for Unicode support
// //     wprintf(L"🧱\n");  // Wide-character print
// //     return 0;
// // }
// // #include <stdio.h>

// // int main() {
// //     printf("\xF0\x9F\xA7\xB1");  // UTF-8 encoded bytes for 🧱
// //     return 0;
// // }
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <windows.h>

// #define WIDTH 130
// #define HEIGHT 14

// char map1[HEIGHT][WIDTH];
// typedef struct {
//     int X;
//     int Y;
// } Coordinates;

// Coordinates coord = {5, 12};

// void loadMap(const char *filename) {
//     FILE *file = fopen(filename, "r");
//     if (!file) {
//         printf("Error loading map!\n");
//         exit(1);
//     }
//     for (int i = 0; i < HEIGHT; i++) {
//         fgets(map1[i], WIDTH, file);
//     }
//     fclose(file);
// }

// void displayMap() {
//     system("cls");
//     for (int i = 0; i < HEIGHT; i++) {
//         for (int j = 0; j < WIDTH; j++) {
//             if (i == coord.Y && j == coord.X)
//                 printf("M");
//             else
//                 printf("%c", map1[i][j]);
//         }
//         printf("\n");
//     }
// }

// bool isCollision(int x, int y) {
//     return (map1[y][x] == '#' || map1[y][x] == '|' || map1[y][x] == '8');
// }

// void whathappenY() {
//     if (!isCollision(coord.X, coord.Y - 1)) {
//         coord.Y -= 1;
//     }
// }

// void whathappenX(int direction) {
//     int newX = coord.X + direction;
//     if (!isCollision(newX, coord.Y)) {
//         coord.X = newX;
//     }
// }

// void mariojump() {
//     for (int i = 0; i < 4; i++) {
//         if (!isCollision(coord.X, coord.Y - 1)) {
//             coord.Y -= 1;
//             displayMap();
//             Sleep(100);
//         } else {
//             break;
//         }
//     }
// }

// int main() {
//     loadMap("map1.txt");
//     displayMap();
//     while (1) {
//         if (GetAsyncKeyState('D') & 0x8000) {
//             whathappenX(1);
//         }
//         if (GetAsyncKeyState('A') & 0x8000) {
//             whathappenX(-1);
//         }
//         if (GetAsyncKeyState(VK_SPACE) & 0x8000) {
//             mariojump();
//         }
//         displayMap();
//         Sleep(100);
//     }
//     return 0;
// }

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

void opengamenewhame(FILE *mp1, char Name, FILE *fgame, SHORT x, SHORT y)
{
    struct infogame temp;
    while(fwrite(&temp, sizeof(struct infogame), 1, fgame) == 1)
    {
        if(strcmp(temp.name, Name) == 0)
        {
            
        }

    }
    if(map1[coord.X][coord.Y-1] == '8')
    {
        coin++;
        gotoxy(x, y);
        printf(" ");
    }

}

void abilitygame(FILE *mp1, int *result)
{
    mp1 = fopen("map1.txt", "r+");
    char map1[14][130];
    int i = 0;
    while(i < 14 && fgets(map1[i], 130, mp1) != NULL)
    {
        i++;
        //fseek(mp1, 1, SEEK_CUR);
    }
    if(map1[coord.Y][coord.X] == '8')
    {
        coin++;
        gotoxy(coord.X, coord.Y);
        printf(" ");
    }
    if(map1[coord.Y][coord.X] == ' ')
    {
        gotoxy(coord.X, coord.Y);
        printf("M");
    }
    if(map1[coord.Y][coord.X] == '1')
    {
        *result = 1;
    }
    fclose(mp1);
}
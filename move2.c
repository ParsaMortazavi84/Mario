#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>

// تعریف متغیر ماریو به‌صورت عمومی
COORD mario = {6, 13}; // موقعیت اولیه ماریو

// تابع پرش ماریو
void marioJump()
{
    for(int i =0; i < 4; i++)
    {
        mario.Y--; // بالا رفتن
        Sleep(100); // مکث کوتاه
    }
    for(int i =0; i < 4; i++)
    {
        mario.Y++; // پایین آمدن
        Sleep(100); // مکث کوتاه
    }
}
void drawMap(COORD player) {
    system("cls"); // پاک کردن کنسول

    // نقشه بازی
    char map[15][128];
}        
// تابع اصلی
int main()
{
    MSG msg; // تعریف پیام ویندوز

    while (GetMessage(&msg, NULL, 0, 0)) // دریافت پیام‌های ویندوز
    {
        TranslateMessage(&msg);
        DispatchMessage(&msg);

        if (msg.message == WM_KEYDOWN) // اگر دکمه‌ای فشرده شد
        {
            switch (msg.wParam) // بررسی کد کلید فشرده‌شده
            {
            case VK_SPACE: // پرش با Space
                marioJump();
                break;

            case 'A': // حرکت به چپ
                mario.X--;
                break;

            case 'D': // حرکت به راست
                mario.X++;
                break;

            case VK_ESCAPE: // خروج از بازی با ESC
                return 0;
            }

            // موقعیت جدید ماریو را نمایش بده
            printf("Mario Position: X=%d, Y=%d\n", mario.X, mario.Y);
        }
    }

    return 0;
}

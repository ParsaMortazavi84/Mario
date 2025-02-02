#include <stdio.h>
#include <locale.h>
#include <wchar.h>
#include <windows.h>

int main() {
    // Set Windows console to use UTF-8
    SetConsoleOutputCP(CP_UTF8);

    // Enable Unicode locale
    // setlocale(LC_ALL, "");

    // Print emojis
    // printf("Hello, World! 😀 🚀 🔥\n");
    printf("🧱");
    // printf("Rocket: \U0001F680\n");
    // printf("Fire: U+1F419");

    return 0;
}

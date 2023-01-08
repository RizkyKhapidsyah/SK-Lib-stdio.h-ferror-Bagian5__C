#pragma warning(disable:4996)

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <wchar.h>
#include <conio.h>

/*
    Source by CPPReference (https://en.cppreference.com)
    Modified For Learn by RK
    I.D.E : VS2022
*/

int main(void) {
    char* fname = tmpnam(NULL);
    FILE* f = fopen(fname, "wb");
    fputs("\xff\xff\n", f);
    fclose(f);

    setlocale(LC_ALL, "en_US.utf8");
    f = fopen(fname, "rb");
    wint_t ch;
    
    while ((ch = fgetwc(f)) != WEOF) {
        printf("%#x ", ch);
    }
        
    if (feof(f)) {
        puts("EOF indicator set");
    }
        
    if (ferror(f)) {
        puts("Error indicator set");
    }
        
    _getch();
    return 0;
}
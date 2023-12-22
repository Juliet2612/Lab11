#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 15
int main(int argc, char *argv[]) {
system("chcp 1250");
char str1[SIZE];
printf("rozmiar: %d, długość: %llu\n\n", SIZE, strlen(str1));
char str2[SIZE] = "To tekst";
puts(str2);
printf("rozmiar: %d, długość: %llu\n", SIZE, strlen(str2));
putchar(*(str2 + 5));
str2[5] = 'X';
putchar(*(str2 + 5));
printf("\n\n");
strcpy(str1, str2);
printf("%s, długość: %llu\n", str1, strlen(str1));
char str3[SIZE] = {'T', 'o', ' ', 't', 'e', 'k', 's', 't', ' ', '2', '\n', '\0'};
puts(str3);
printf("rozmiar: %d, długość: %llu\n", SIZE, strlen(str3));
printf("\n\n");
char str4[100] = "To tylko tekst";
puts(str4);
printf("rozmiar: %llu, długość: %llu\n",
           sizeof(str4) / sizeof(char), strlen(str4));
    printf("\n\n");
    char *str5 = "To abecadło!";
    puts(str5);
    printf("długość: %llu\n", strlen(str5));
    printf("\n\n");
    str5 = "ABECADŁO";
    puts(str5);
    printf("długość: %llu\n", strlen(str5));
    strcat(str4, str5);
    printf("\n%s, długość: %llu\n", str4, strlen(str4));
    putchar(*(str5 + 6));
    putchar(str5[6]);
    printf("\n\nNaciśnij Enter, aby zakończyć...");
    fflush(stdin);
    getchar();
    return 0;
}
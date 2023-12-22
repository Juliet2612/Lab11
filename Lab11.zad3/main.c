#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void findTwoLargest(int a[], int n, int *largest, int *sec_largest);
void generateRandomArray(int a[], int n, int min, int max);
void printArray(int a[], int n);

int main() {
    srand(time(NULL));
    SetConsoleOutputCP(CP_UTF8);

    int n, min, max;
    printf("Podaj rozmiar tablicy: ");
    scanf("%d", &n);

    printf("Podaj minimalną wartość: ");
    scanf("%d", &min);

    printf("Podaj maksymalną wartość: ");
    scanf("%d", &max);

    int *arr = (int *)malloc(n * sizeof(int));
    generateRandomArray(arr, n, min, max);

    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Wyświetl tablice\n");
        printf("2. Znajdź największy i drugi co do wartości element\n");
        printf("3. Zmień rozmiar tablicy\n");
        printf("4. Zmień zakres liczb (MIN, MAX)\n");
        printf("0. Wyjscie\n");
        printf("Wybierz opcję: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Tablica:\n");
                printArray(arr, n);
                break;
            case 2: {
                int largest, sec_largest;
                findTwoLargest(arr, n, &largest, &sec_largest);
                printf("Największy element: %d\n", largest);
                printf("Drugi co do wartości element: %d\n", sec_largest);
                break;
            }
            case 3:
                printf("Podaj nowy rozmiar tablicy: ");
                scanf("%d", &n);
                free(arr);
                arr = (int *)malloc(n * sizeof(int));
                generateRandomArray(arr, n, min, max);
                break;
            case 4:
                printf("Podaj nowe wartosci MIN i MAX:\n");
                scanf("%d %d", &min, &max);
                generateRandomArray(arr, n, min, max);
                break;
            case 0:
                break;
            default:
                printf("Niepoprawny wybór.Przegrałeś/aś.\n");
        }

    } while (choice != 0);

    free(arr);
    return 0;
}
void findTwoLargest(int a[], int n, int *largest, int *sec_largest) {
    if (n < 2) {
        printf("Za mala tablica.\n");
        return;
    }

    *largest = *sec_largest = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > *largest) {
            *sec_largest = *largest;
            *largest = a[i];
        } else if (a[i] > *sec_largest && a[i] != *largest) {
            *sec_largest = a[i];
        }
    }
}
void generateRandomArray(int a[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        a[i] = rand() % (max - min + 1) + min;
    }
}
void printArray(int a[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

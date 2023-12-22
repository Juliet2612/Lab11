#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

int compare(const void *a, const void *b);
void merge(int *arr1, int *arr2, int *arr3, int n, int m);

int main() {
    int n, m;
    printf("Podaj rozmiar pierwszej tablicy (n): ");
    scanf("%d", &n);
    printf("Podaj rozmiar drugiej tablicy (m): ");
    scanf("%d", &m);

    int arr1[n], arr2[m], arr3[n + m];

    printf("Podaj elementy pierwszej tablicy:\n");
    for (int i = 0; i < n; i++) {
        printf("arr1[%d]: ", i);
        scanf("%d", &arr1[i]);
    }

    printf("Podaj elementy drugiej tablicy:\n");
    for (int i = 0; i < m; i++) {
        printf("arr2[%d]: ", i);
        scanf("%d", &arr2[i]);
    }
    qsort(arr1, n, sizeof(int), compare);
    qsort(arr2, m, sizeof(int), compare);
    merge(arr1, arr2, arr3, n, m);
    strrev((char *)arr3);

    printf("\nPosortowana i odwrócona tablica:\n");
    for (int i = 0; i < n + m; i++) {
        printf("arr3[%d]: %d\n", i, arr3[i]);
    }

    return 0;
}
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
void merge(int *arr1, int *arr2, int *arr3, int n, int m) {
    int i = 0, j = 0, k = 0;

    while (i < n && j < m) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }

    while (i < n) {
        arr3[k++] = arr1[i++];
    }

    while (j < m) {
        arr3[k++] = arr2[j++];
    }
}

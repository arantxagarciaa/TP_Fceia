#include <stdio.h>

void insertion_sort(int arr[], int n) {
    int i, j, key;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Desplaza los elementos mayores que key hacia la derecha
        while (j >= 0 && arr[j] < key) { // Esto deja en orden descendente
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n, i;
    printf("Ingrese la cantidad de elementos: ");
    scanf("%d", &n);
    int arr[n];

    printf("Ingrese %d elementos:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    insertion_sort(arr, n);

    printf("Arreglo ordenado en forma descendente:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

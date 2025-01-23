#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>

typedef int* array;
array T;

// ***** The Key Function *****
int key(int x, int i) {
    int j, r;
    for (j = 0; j <= i; j++) {
        r = x % 10;
        x = x / 10;
    }
    return r;
}

// ***** Auxiliary Sort Function *****
void AuxiliarySort(int *T, int n, int i) {
    int T1[n], count[10] = {0}, j;

    // Calculer les fréquences des clés
    for (j = 0; j < n; j++) {
        T1[j] = key(T[j], i);
        count[T1[j]]++;
    }

    // Calculer les positions cumulatives
    for (j = 1; j < 10; j++) {
        count[j] += count[j - 1];
    }

    // Trier les éléments dans un tableau temporaire
    int T2[n];
    for (j = n - 1; j >= 0; j--) {
        T2[--count[T1[j]]] = T[j];
    }

    // Copier les éléments triés dans le tableau original
    for (j = 0; j < n; j++) {
        T[j] = T2[j];
    }
}

// ***** Radix Sort Function *****
void RadixSort(int *T, int n, int k) {
    int i;
    for (i = 0; i < k; i++) {
        AuxiliarySort(T, n, i);
    }
}

// ***** Main Function *****
int main() {
    int n, i, k;
    clock_t t1, t2;

    printf("\n\t\t\t RADIX SORT ALGORITHM \t\t\t\n");
    printf("-------------------------------------------------\n");

    // Saisie de la taille du tableau et du nombre maximum de chiffres
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    printf("Enter the value of K: ");
    scanf("%d", &k);

    // Allocation de mémoire pour le tableau
    int *T = (int*)malloc(n * sizeof(int));
    if (T == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Initialisation du tableau avec des nombres aléatoires
    printf("\nHere is the array before sorting:\n");
    int max_value = 1;
    for (i = 0; i < k; i++) {
        max_value *= 10;  // Calcul de 10^k pour éviter `pow`
    }
    for (i = 0; i < n; i++) {
        T[i] = rand() % max_value;
        printf("%d ", T[i]);
    }

    // Mesure du temps d'exécution
    t1 = clock();  // Temps avant le tri
    RadixSort(T, n, k);
    t2 = clock();  // Temps après le tri

    
    printf("\nHere is the array after sorting:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", T[i]);
    }

    // Affichage du tableau trié et du temps d'exécution
    double elapsed_time = (double)(t2 - t1) / CLOCKS_PER_SEC;
    printf("\n\nExecution time: %f seconds\n", elapsed_time);
    // Libération de la mémoire
    free(T);

    return 0;
}

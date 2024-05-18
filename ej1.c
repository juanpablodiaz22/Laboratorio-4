#include <stdio.h>

// Se adjuntan los prototipos de funciones
int busquedaLineal(int arr[], int tam, int valor);
int busquedaBinaria(int arr[], int tam, int valor);
int busquedaBinariaRecursiva(int arr[], int inicio, int fin, int valor);

//  La funcion principal, declara un arreglo ordenado y llama a las funciones de busqueda
int main() {
    int arreglo[] = {2, 4, 6, 23, 56, 79};
    int tam = sizeof(arreglo) / sizeof(arreglo[0]);
    int valor;

    printf("Ingrese un valor entero: ");
    scanf("%d", &valor);

    // Busqueda lineal llamada de la funcion 
    int resultadoLineal = busquedaLineal(arreglo, tam, valor);
    if (resultadoLineal != -1) {
        printf("Búsqueda Lineal: El valor %d se encuentra en la posición %d\n", valor, resultadoLineal);
    } else {
        printf("Búsqueda Lineal: El valor %d no fue encontrado\n", valor);
    }

    // Busqueda binaria iterativa llamada de la funcion
    int resultadoBinaria = busquedaBinaria(arreglo, tam, valor);
    if (resultadoBinaria != -1) {
        printf("Búsqueda Binaria Iterativa: El valor %d se encuentra en la posición %d\n", valor, resultadoBinaria);
    } else {
        printf("Búsqueda Binaria Iterativa: El valor %d no fue encontrado\n", valor);
    }

    // Busqueda binaria recursiva llamada de la funcion
    int resultadoBinariaRec = busquedaBinariaRecursiva(arreglo, 0, tam - 1, valor);
    if (resultadoBinariaRec != -1) {
        printf("Búsqueda Binaria Recursiva: El valor %d se encuentra en la posición %d\n", valor, resultadoBinariaRec);
    } else {
        printf("Búsqueda Binaria Recursiva: El valor %d no fue encontrado\n", valor);
    }

    return 0;
}

// Funcion para realizar una busqueda lineal, recorre el arreglo secuencialmente
int busquedaLineal(int arr[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == valor) {
            return i; // Retorna la posición si se encuentra el valor
        }
    }
    return -1; // Retorna -1 si no se encuentra el valor
}

// Funcion para realizar una busqueda binaria iterativa
int busquedaBinaria(int arr[], int tam, int valor) {
    int inicio = 0;
    int fin = tam - 1;

    while (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2; // Calcula el punto medio y ajusta los limites de busqueda 

        // Se verifica si el valor esta en el medio
        if (arr[medio] == valor) {
            return medio;
        }

        // Se verifica si el valor es mayor, ignora la mitad izquierda
        if (arr[medio] < valor) {
            inicio = medio + 1;
        } else {
            // Se verifica si el valor es menor, ignora la mitad derecha
            fin = medio - 1;
        }
    }

    return -1; // Retorna -1 si no se encuentra el valor
}

// Funcion para realizar una busqueda binaria recursiva
int busquedaBinariaRecursiva(int arr[], int inicio, int fin, int valor) {
    if (inicio <= fin) {
        int medio = inicio + (fin - inicio) / 2; // Calcula el punto medio y ajusta los limites de busqueda

        // Se verifica si el valor está en el medio
        if (arr[medio] == valor) {
            return medio;
        }

        // Se verifica si el valor es mayor, busca en la mitad derecha
        if (arr[medio] < valor) {
            return busquedaBinariaRecursiva(arr, medio + 1, fin, valor);
        } else {
            // Se verifica si el valor es menor, busca en la mitad izquierda
            return busquedaBinariaRecursiva(arr, inicio, medio - 1, valor);
        }
    }
 
    return -1; // Retorna -1 si no se encuentra el valor
}
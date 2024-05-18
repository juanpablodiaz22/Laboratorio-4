#include <stdio.h>

// Prototipos de las funciones a trabajar
int encontrarMinimo(int arreglo[], int longitud);
int encontrarMaximo(int arreglo[], int longitud);
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud);

int main() {
    // Se define e inicializa el arreglo
    int arreglo[] = {21, 24, 65, 3, 56, 12, 35, 15};
    // Se calcula la longitud del arreglo
    int longitud = sizeof(arreglo) / sizeof(arreglo[0]);

    // Se busca encontrar el valor minimo utilizando la funcion encontrarMinimo
    int minimo = encontrarMinimo(arreglo, longitud);
    printf("El valor mínimo es: %d\n", minimo);

    // Se busca encontrar el valor maximo utilizando la función encontrarMaximo
    int maximo = encontrarMaximo(arreglo, longitud);
    printf("El valor máximo es: %d\n", maximo);

    // Se declaran las variables para almacenar los valores minimo y maximo usando punteros
    int min, max;
    // Se llama a la funcion encontrarMinMax para encontrar los valores minimo y maximo
    encontrarMinMax(arreglo, &min, &max, longitud);
    printf("Usando punteros, el valor mínimo es: %d y el valor máximo es: %d\n", min, max);

    return 0;
}

// Se crea una funcion para encontrar el valor minimo en el arreglo
int encontrarMinimo(int arreglo[], int longitud) {
    int minimo = arreglo[0]; // Se inicializa el minimo con el primer elemento del arreglo
    for(int i = 1; i < longitud; i++) { // Se recorre el arreglo desde el segundo elemento
        if(arreglo[i] < minimo) { // Si se encuentra un elemento menor que el minimo actual, actualiza el minimo
            minimo = arreglo[i];
        }
    }
    return minimo;
}

// Se crea una funcion para encontrar el valor maximo en el arreglo
int encontrarMaximo(int arreglo[], int longitud) {
    int maximo = arreglo[0]; // Se inicializa el maximo con el primer elemento del arreglo
    for(int i = 1; i < longitud; i++) { //  Se recorre el arreglo desde el segundo elemento
        if(arreglo[i] > maximo) { // Si se encuentra un elemento mayor que el maximo actual, actualiza el maximo
            maximo = arreglo[i];
        }
    }
    return maximo;
}

// Se crea una funcion para encontrar los valores minimo y maximo utilizando punteros
void encontrarMinMax(int *arreglo, int *minimo, int *maximo, int longitud) {
    *minimo = arreglo[0]; // Se inicializa el minimo con el primer elemento del arreglo
    *maximo = arreglo[0]; // Se inicializa el maximo con el primer elemento del arreglo
    for(int i = 1; i < longitud; i++) { // Se recorre el arreglo desde el segundo elemento
        if(arreglo[i] < *minimo) { // Si se encuentra un elemento menor que el minimo actual, actualiza el minimo
            *minimo = arreglo[i];
        }
        if(arreglo[i] > *maximo) { // Si se encuentra un elemento mayor que el maximo actual, actualiza el maximo
            *maximo = arreglo[i];
        }
    }
}
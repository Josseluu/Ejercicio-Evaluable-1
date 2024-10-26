#include <stdio.h>

typedef struct {
    int arrInt[10];
    int arrSize;
    int arrAdd;
} arrayLength_t;

// Función de inicialización (Ejercicio 2)
int initArray(arrayLength_t *array) {
    if (array == NULL) return -1;
    for (int i = 0; i < 10; i++) {
        array->arrInt[i] = -1;
    }
    array->arrSize = 0;
    array->arrAdd = 0;
    return 0;
}

// Función de impresión del array (Ejercicio 2)
void printArr(const arrayLength_t *array) {
    printf("{[");
    for (int i = 0; i < 10; i++) {
        printf("%d", array->arrInt[i]);
        if (i < 9) printf(", ");
    }
    printf("], %d, %d}\n", array->arrSize, array->arrAdd);
}

// Función para añadir un elemento (Ejercicio 3)
int addElement(arrayLength_t *array, int value) {
    if (value < 0 || array->arrSize >= 10) return -1;
    array->arrInt[array->arrSize] = value;
    array->arrSize++;
    array->arrAdd += value;
    return 0;
}

// Función para obtener el tamaño del array (Ejercicio 4)
int getArrSize(const arrayLength_t *array) {
    return array ? array->arrSize : -1;
}

// Función para obtener la suma de los elementos del array (Ejercicio 5)
int getArrAdd(const arrayLength_t *array) {
    return array ? array->arrAdd : -1;
}

// Función para obtener un elemento en una posición específica (Ejercicio 6)
int getElement(const arrayLength_t *array, int position) {
    if (!array || position < 0 || position >= 10 || array->arrInt[position] == -1) return -1;
    return array->arrInt[position];
}

// Función para asignar un valor a una posición específica (Ejercicio 7)
int setElement(arrayLength_t *array, int position, int value) {
    if (!array || position < 0 || position >= 10 || value < 0) return -1;
    if (array->arrInt[position] != -1) array->arrAdd -= array->arrInt[position];
    array->arrInt[position] = value;
    array->arrAdd += value;
    return 0;
}

// Función para reiniciar el array (Ejercicio 8)
int resetArr(arrayLength_t *array) {
    return initArray(array);
}

// main para comprobar las funciones (Ejercicio 10)
int main() {
    arrayLength_t al1, al2;
    initArray(&al1);
    initArray(&al2);

    // Almacenar valores 0, 10, 20, ..., 90 en al1
    for (int i = 0; i < 10; i++) {
        addElement(&al1, i * 10);
    }
    printArr(&al1);

    // Actualizar posiciones impares de al1 con 1, 3, 5, 7, 9
    for (int i = 1; i < 10; i += 2) {
        setElement(&al1, i, i);
    }
    printArr(&al1);

    // Añadir posiciones pares de al1 a al2
    for (int i = 0; i < 10; i += 2) {
        addElement(&al2, al1.arrInt[i]);
    }

    // Actualizar posiciones finales de al2 con valores de 0 a 4
    for (int i = al2.arrSize; i < 10 && i < al2.arrSize + 5; i++) {
        setElement(&al2, i, i - al2.arrSize);
    }
    printArr(&al2);

    return 0;
}

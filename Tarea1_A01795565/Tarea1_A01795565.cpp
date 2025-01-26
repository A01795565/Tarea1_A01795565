// Tarea1_A01795565.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>

#define N 10000                 // Tamaño de los arreglos
#define chunk 1000
#define show 10

void imprimeArreglo(float* d);

int main() 
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;
    int pedazos = chunk;

    // Inicializamos los arreglos A y B
    for (i = 0; i < N; i++) {
        a[i] = i * 10;           // Llenamos A con valores
        b[i] = (i + 3) * 3.7;    // Llenamos B con valores 
    }
    // Usamos OpenMP para paralelizar la suma
    #pragma omp parallel for \
    shared(a,b,c,pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++) {
        c[i] = a[i] + b[i];     // Sumamos los elementos en los mismos índices
    }
    // Imprimimos los resultados
    std::cout << "Imprimiendo los primeros : " << show << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros : " << show << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros : " << show << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);     
}
void imprimeArreglo(float* d) {
    // Funcion para imprimir arreglo que se recibe como parametro
    for (int i = 0; i < show; i++) {
        std::cout << d[i] << " - ";
    }
    std::cout << std::endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

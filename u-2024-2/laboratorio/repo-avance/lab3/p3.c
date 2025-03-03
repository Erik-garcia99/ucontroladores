#include <stdio.h>

int main() {
    // Definimos la variable ecuacion
    int ecuacion;

    // Ciclos anidados para x, y, z
    for (int x = 5; x < 256; x++) {
        for (int y = 8; y < 256; y++) {
            for (int z = 7; z < 256; z++) {
                // Ecuación corregida
                ecuacion = x*(3 + 3*y + 8*y*z) + 10;

                // Condición para verificar si ecuacion es igual a 1648
                if (ecuacion == 160000) {
                    // Imprime los valores de x, y, z cuando la condición se cumple
                    printf("x = %d, y = %d, z = %d\n", x, y, z);
                }
            }
        }
    }

    return 0;
}


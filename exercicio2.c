#include <stdio.h>
#include <math.h>

int calcula_raizes(float a, float b, float c, float *x1, float *x2);

int main() {
    float a, b, c;
    float x1, x2;
    int raizes;

    printf("Digite a, b e c: ");
    scanf("%f %f %f", &a, &b, &c);

    raizes = calcula_raizes(a, b, c, &x1, &x2);

    if (raizes == 2) {
        printf("duas raizes: x1 = %.2f e x2 = %.2f\n", x1, x2);
    } else if (raizes == 1) {
        printf("uma raiz: %.2f\n", x1);
    } else if (raizes == 0) {
        printf("sem raizes reais\n");
    } else {
        printf("O valor de 'a' nao pode ser 0\n");
    }

    return 0;
}

int calcula_raizes(float a, float b, float c, float *x1, float *x2) {
    float delta;
    
    if (a == 0) {
        return -1;
    }

    delta = (b * b) - (4 * a * c);

    if (delta > 0) {
        *x1 = (-b + sqrt(delta)) / (2 * a);
        *x2 = (-b - sqrt(delta)) / (2 * a);
        return 2;
    } 
    
    if (delta == 0) {
        *x1 = -b / (2 * a);
        *x2 = *x1;
        return 1;
    } 
    
    return 0;
}

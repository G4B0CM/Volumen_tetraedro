#include <stdio.h>
#include <math.h>
float calculara(float a, float b, float c, float d, float e, float f, float *area);
float calcularp(float puntos[][3], float *a, float *b, float *c, float *d, float *e, float *f);
float dis(float x1, float y1, float z1, float x2, float y2, float z2);
float calcularV(float areat, float altura);
void varicentro(float puntos[][3], float vari[3]);
float calcularAltura(float puntos[][3], float vari[3]);
int main()
{
    float puntos[4][3] = {{0, 0, 0}, {3, 0, 0}, {0, 0, 3}, {1, 7, 1}};
    float vari[3];
    float per, a, b, c, d, e, f, areat;
    float perimetro = calcularp(puntos, &a, &b, &c, &d, &e, &f);
    float altura = calcularAltura(puntos, vari);
    float area = calculara(a, b, c, d, e, f, &areat);
    float volumen = calcularV(areat, altura);
    printf("La altura es: %.2f\n", altura);
    printf("Area de la base: %f\n", areat);
    printf("El perimetro es: %f\n ", perimetro);
    printf("El area es: %f\n ", area);
    printf("El volumen es: %f\n", volumen);
}
float dis(float x1, float y1, float z1, float x2, float y2, float z2)
{
    float dist = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2) + pow(z1 - z2, 2));
    return dist;
}
void varicentro(float puntos[][3], float vari[3])
{
    vari[0] = (puntos[0][0] + puntos[1][0] + puntos[2][0])/3;
    vari[1] = (puntos[0][1] + puntos[1][1] + puntos[2][1])/3;
    vari[2] = (puntos[0][2] + puntos[1][2] + puntos[2][2])/3;
}
float calcularp(float puntos[][3], float *a, float *b, float *c, float *d, float *e, float *f)
{
    // al hacer esto estamos cambiando el contenido de la direccion de memoria de a, b y c
    *a = dis(puntos[0][0], puntos[0][1], puntos[0][2], puntos[1][0], puntos[1][1], puntos[1][2]); // punto 1 y 2
    *c = dis(puntos[0][0], puntos[0][1], puntos[0][2], puntos[2][0], puntos[2][1], puntos[2][2]); // punto 1 y 3
    *b = dis(puntos[1][0], puntos[1][1], puntos[1][2], puntos[2][0], puntos[2][1], puntos[2][2]); // punto 2 y 3
    *d = dis(puntos[0][0], puntos[0][1], puntos[0][2], puntos[3][0], puntos[3][1], puntos[3][2]); // punto 1 y 4
    *e = dis(puntos[3][0], puntos[3][1], puntos[3][2], puntos[2][0], puntos[2][1], puntos[2][2]); // punto 3 y 4
    *f = dis(puntos[1][0], puntos[1][1], puntos[1][2], puntos[3][0], puntos[3][1], puntos[3][2]); // punto 2 y 4

    float per = *a + *b + *c + *d + *e * +*f;
    return per;
}
float calculara(float a, float b, float c, float d, float e, float f, float *area)
{
    float s[4], ar[4], ars;
    s[0] = (a + b + c) / 2;
    s[1] = (a + d + f) / 2;
    s[2] = (b + e + f) / 2;
    s[3] = (e + d + c) / 2;
    ar[0] = sqrt(s[0] * (s[0] - a) * (s[0] - b) * (s[0] - c));
    *area = ar[0];
    ar[1] = sqrt(s[1] * (s[1] - a) * (s[1] - b) * (s[1] - c));
    ar[2] = sqrt(s[2] * (s[2] - a) * (s[2] - b) * (s[2] - c));
    ar[3] = sqrt(s[3] * (s[3] - a) * (s[3] - b) * (s[3] - c));
    ars = ar[0] + ar[1] + ar[2] + ar[3];
    return ars;
}
float calcularAltura(float puntos[][3], float vari[3])
{
    varicentro(puntos,vari);
    printf("El varicentro esta ubicado en: %.2f,%.2f,%.2f\n", vari[0], vari[1], vari[2]);
    float altura = dis(puntos[3][0], puntos[3][1], puntos[3][2], vari[0], vari[1], vari[2]);
    return altura;
}
float calcularV(float areat, float altura)
{
    float volumen=(areat*altura)/3;
    return volumen;
}
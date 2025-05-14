#include <cstdio>
#include <iostream>
using namespace std;

//Fazer um programa para ler um vetor de ‘N’ números reais. Em seguida
//Mostrar a média aritmética de todos os elementos
//Mostrar todos os elementos abaixo da média.
int main() {
    int n;
    cin >> n;
    double a[n];
    double soma=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++) {
        soma = soma + a[i];

    }
    float media = soma / n;
    printf("%.3f\n", media);
    printf("%.1f\n", a[0]);
    printf("%.1f\n", a[n-1]);
    return 0;
}

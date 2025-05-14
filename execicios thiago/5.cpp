#include <cstdio>
#include <iostream>
using namespace std;
//Fazer um programa para ler um vetor de N números inteiros. Emseguida, mostrar a média aritmética
//somente dos números pares lidos.
int main() {
    int n;
    cin >> n;
    int a[n];
    int soma = 0;
    int quantpares=0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            soma = soma+ a[i];
            quantpares++;

        }
    }
    int media = soma / quantpares;
    printf("%.1d\n", media);
    return 0;
}

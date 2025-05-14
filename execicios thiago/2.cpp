#include <cstdio>
#include <iostream>
using namespace std;
//Faça um programa que leia N números inteiros e armazene-os em um vetor. Em seguida,
//mostre na tela:
int main() {
    int n;
    cin >> n;
    //vetor criado
    int number[n];
    //ler numeros do vetor
    for (int i = 0; i < n; i++) {
        cin >> number[i];
     }
    //variavel da quantidade de pares
    int qtdpares =0;
    //contador de numeros pares
    for (int i = 0; i < n; i++) {
        //if para reconhecer numeros pares
        if (number[i] % 2 == 0) {
            printf("%d ", number[i]);
            qtdpares++;
        }

    }   printf("\n%d ", qtdpares);
    return 0;
}
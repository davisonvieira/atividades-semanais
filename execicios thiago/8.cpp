//Tem-se um conjunto de dados contendo a altura e o sexo (M, F) de N
//pessoas. Fazer um programa que calcule e escreva
//A menor e a maior altura do grupo
//A média de altura das mulheres
//O número de homens
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;
int main() {
    int n;
    printf("quantas alturas e sexo iremos armazenar:\n");
    cin >> n;
    string sexo[n];
    float altura[n];
    for (int i = 0; i < n; i++) {

        cin >> altura[i];
        cin >> sexo[i];
    }
    float maior= altura[0];
    float menor= altura[0];
    float media= 0;
    float soma= 0;
    int qtdmulehres =0;
    int qtdhomens= 0;
    for (int i = 0; i < n; i++) {
        if (altura[i] < menor) {
            menor = altura[i];

        }
        if (altura[i] > maior) {
            maior = altura[i];
        }
        if (sexo[i] == "f"|| sexo[i] == "F") {
            qtdmulehres++;
            soma = soma + altura[i];
            media= soma/qtdmulehres;
        }
    }
    for (int i = 0; i < n; i++) {
        if (sexo[i]=="m"|| sexo[i]=="M") {
            qtdhomens++;
        }
    }
    printf("menor altura %.2f\n",menor);
    printf("maior altura %.2f\n",maior);
    printf("media altura das mulheres %.2f\n",media);
    printf("quantidade de homens %d\n",qtdhomens);
    return 0;
}
//Fazer um programa para ler um conjunto de nomes de pessoas e suas
//respectivas idades. Mostrar na tela o nome da pessoa mais velha
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
    int n;
    cin >> n;
    string nome[n];
    int idade[n];
    for (int i = 0; i < n; i++) {
        cin >> nome[i];
        cin >> idade[i];
    }
    int idademaior = idade[0];
    string maisvelho = nome[0];
    for (int i = 0; i < n; i++) {
        if (idade[i] > idademaior) {
            idademaior = idade[i];
            maisvelho = nome[i];
        }
    }
    printf("a pessoa mais velha e: %s\n", maisvelho.c_str());
    return 0;
}
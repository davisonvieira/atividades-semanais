//Fazer um programa para ler N nomes de alunos e as notas que eles tiraram no 1º e 2º
//semestres. Armazene cada informação em um vetor. Depois, imprimir os nomes dos alunos
//aprovados (média das notas ≥ 6.0)
#include <cstdio>
#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    string nome[n];
    double nota1[n];
    double nota2[n];
    for (int i = 0; i < n; i++) {
        cin >> nome[i];
        cin >> nota1[i];
        cin >> nota2[i];
    }
    string nomeaprovados= nome[0];
    double media;
    for (int i = 0; i < n; i++) {
        media= nota1[i] + nota2[i]/2;
        if (media >= 6) {
            printf("Alunos aprovados:\n%s \n",nome[i].c_str());
        }
    }
return 0;
}

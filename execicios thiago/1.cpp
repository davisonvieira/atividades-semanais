#include <iostream>
#include  <cstdio>
using namespace std;
// um programa que leia N números reais e armazene-os em um vetor. Em seguida,
//mostrar na tela o maior número do vetor (supor que não há empates) e a posição do maior
//elemento.
int main() {
    int N;
    cin >> N;
    //vetor criado
    double numeros[N];
    //ler numeros do vetor
    for (int i = 0; i < N; i++) {
        cin >> numeros[i];
    }
    //variaveis de maior e posiçao
    double maior = numeros[0];
    int posicao = 0;
    //contador para imprimir maior e a posição
    for (int i = 1; i < N; i++) {
    //aqui assumo maior= n[0] onde o contador ira testar o if e atualizar o maior valor
        if (numeros[i] > maior) {
            maior = numeros[i];
            posicao = i;
        }
    }
//printf fora do if para nao imprimir a posição mais que necessario
   printf("%.1f\n%d", maior,posicao);
    return 0;
}

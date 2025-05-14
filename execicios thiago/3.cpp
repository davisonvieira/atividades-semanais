#include <cstdio>
#include <iostream>
using namespace std;
//criar 3 vetores onde o vetor c é a soma a[n]+b[n] e imprimir vetor c
int main() {
    int n;
    cin >> n;
    int a[n];
    int b[n];
    int c[n];
    //ler o vetor A
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    //ler o vetor B
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    //Soma dos vetores e imprimir vetor c
    for (int i = 0; i < n; i++) {
        c[i] = a[i] + b[i];
        printf("%d ", c[i]);
    }
    return 0;

}
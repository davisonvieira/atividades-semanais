#include <cstdio>
#include <iostream>
using namespace std;

int main() {
    char nome[100];
    int b;
    printf("digite seu nome:\n");
    cin>>nome;
    printf("digite sua idade:\n");
    cin>>b;

    printf("seu nome e %s, sua idade e %d\n",nome,b);
}
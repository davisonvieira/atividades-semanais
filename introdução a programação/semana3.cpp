#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    float salario,imposto,luiquido;
    float percentual;
    printf("digite seu salario: \n");
    cin>>salario;
    printf("digite o percentual do imposto: \n");
    cin>>percentual;
    imposto= salario*(percentual/100);
    luiquido= salario - imposto;
    printf("o salario luiquido foi de R$: %.2F \n",luiquido);
}

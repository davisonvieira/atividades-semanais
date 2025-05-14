#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string produto[n];
    float precocompra[n];
    float precovenda[n];

    for(int i = 0; i < n; i++) {
        cin >> produto[i] >> precocompra[i] >> precovenda[i];
    }

    int abaixo10 = 0;
    int entre10e20 = 0;
    int acima20 = 0;
    float totalcompra = 0;
    float totalvenda = 0;

    for(int i = 0; i < n; i++) {
        float lucro = precovenda[i] - precocompra[i];
        float percentual = (lucro / precocompra[i]) * 100;

        if (percentual < 10.0) {
            abaixo10++;
        } else if (percentual <= 20.0) {
            entre10e20++;
        } else {
            acima20++;
        }

        totalcompra = totalcompra + precocompra[i];
        totalvenda = totalvenda + precovenda[i];
    }

    float lucrototal = totalvenda - totalcompra;

    // Saída
    printf("Lucro abaixo de 10%%: %d\n", abaixo10);
    printf("Lucro entre 10%% e 20%%: %d\n", entre10e20);
    printf("Lucro acima de 20%%: %d\n", acima20);
    printf("Valor total de compras: %.2f\n", totalcompra);
    printf("Valor total de vendas: %.2f\n", totalvenda);
    printf("Lucro total: %.2f\n", lucrototal);

    return 0;
}

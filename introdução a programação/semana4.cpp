#include <iostream>
#include <cstdio>

using namespace std;

int main() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if (b > c && d > a && (c + d) > (a + b) && c > 0 && d > 0 && a % 2 == 0) {

        printf("valores aceitos\n");
    }else {
        printf("valores nao aceitos\n");
    }
}

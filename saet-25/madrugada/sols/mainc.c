// solucao em c pra testar o boca
#include <stdio.h>

int main() {

    int n, b, v, sobra;
    scanf("%d %d %d", &n, &b, &v);
    sobra = b-v;
    if (sobra%n == 0)
       printf("%d\n", sobra/n);
    else
        printf("-1\n");

    return 0;
}

// o que um calouro faria se pa
#include <stdio.h>
#include <stdlib.h>

int main() {

    int n, m;
    scanf("%d %d", &n, &m);
    int *v = (int *)malloc(m*sizeof(int));
    for (int i=0;i<m;i++)
        scanf("%d",&v[i]);
    int L;
    scanf("%d",&L);
    int validas=0;
    for (int i=0;i<m;i++)
        if (v[i] > L)
            validas++;
    if (validas >= n)
        printf("SIM\n");
    else
        printf("NAO\n");

    return 0;
}

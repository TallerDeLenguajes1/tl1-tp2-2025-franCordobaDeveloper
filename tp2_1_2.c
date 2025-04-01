#include <stdio.h>
#include <stdlib.h>
#define N 20


int main()
{

   
    int i;
    double vt[N];
    double *p_arreglo;
    p_arreglo = vt;
    for(i = 0;i<N; i++)
    {
        p_arreglo[i] = 1 + rand() % 100;
        printf("%d \n", (int)p_arreglo[i]);
        
    }

    return 0;
}

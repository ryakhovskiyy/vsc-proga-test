#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void fullrand(int*a, int n);
void f (int *a, int n);

int main(void)
{
    double time_spent = 0.0;
    clock_t begin = clock();
 
    FILE *fin, *fout;
    int* a;
    int i, n;

    
    fin=fopen("input2.txt", "r");
    fout=fopen("output2.txt", "w");
    
    if ((fscanf(fin, "%d", &n) != EOF)&&(n>0))
    {
        a = (int*) malloc(n*sizeof(int));
       
        fullrand (a,n);
        f(a, n);
        for (i=0; i<n; i++) fprintf(fout, "%d\n", a[i]);

        free(a);
        
    }

    clock_t end = clock();
    time_spent += (double)(end - begin) / CLOCKS_PER_SEC;
    printf("The elapsed time is %f seconds", time_spent);

    fclose(fin);
    fclose(fout);
    return 0;
}

void fullrand(int*a, int n)
{
    int i;
    for (i=0;i<n;i++) a[i]=rand();
}

void f(int *a, int n)
{
    int i,j,r;

    for (i=0; i<n-1; i++)
    {
        for (j=i+1; j<n; j++)
        {
            if(a[i]>a[j])
            {
                r=a[i];
                a[i]=a[j];
                a[j]=r;
            }
        }
    }
}
    
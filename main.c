#include <stdio.h>
#include <stdlib.h>

void f(int *a, int *b, int *c, int n);

int main(void)
{
    FILE *fin, *fout;
    int* a;
    int* b;
    int* c;
    int i, j, n, q=1;

    fin = fopen("input.txt", "r");
    fout = fopen("output.txt", "w");

    if ((fscanf(fin, "%d", &n) != EOF)&&(n>0))
    {
        a = (int*) malloc(n*sizeof(int));
        b = (int*) malloc(n*sizeof(int)); 
        c = (int*) malloc((n+1)*sizeof(int)); 
        for (i=0; i<n; i++) 
        {
            q=fscanf(fin, "%d", &a[i]);
            if (a[i]<0) return -1;
        }
        
        for (i=0; i<n; i++) 
        {
            q=fscanf(fin, "%d", &b[i]);
            if (b[i]<0) return -1;
        }
 
        if (q==1)
        {
            f(a, b, c, n);
            for (i=0; i<n+1; i++) fprintf(fout, "%d ", c[i]);
        }
        else return -1;
        
        free(a);
        free(b);
        free(c);
    }
    else return -1;
    
    fclose(fin);
    fclose(fout);
    return 0;
}

void f(int *a, int *b, int *c, int n)
{
    int i, r=0;
    
    for (i=0; i<n; i++)
    {
        if (a[i]<b[i])
        {
            c[0]=1;
            break;
        }
        if (a[i]>b[i])
        {
            c[0]=0;
            break;
        }
    }

    for (i=n-1; i>=0; i--)
    {
        if (c[0]==0)
        {
            c[i+1]=(a[i]-b[i]+10-r)%10;
            if (a[i]>=b[i]) r=0;
            else r=1;
        }
        else
        {
            c[i+1]=(b[i]-a[i]+10-r)%10;
            if (b[i]>=a[i]) r=0;
            else r=1; 
        }
    }
}
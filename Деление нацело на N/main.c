#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void f (int *a, int *b, int *c, int n);

int main(void)
{
    FILE *fin, *fout;
    int* a;
    int* b;
    int* c;
    int i, n, q=1;

    
    fin=fopen("input.txt", "r");
    fout=fopen("output.txt", "w");
    
    if ((fscanf(fin, "%d", &n) != EOF)&&(n>0))
    {
        a = (int*) malloc(n*sizeof(int));
        b = (int*) malloc(n*sizeof(int)); 
        c = (int*) malloc((2*n)*sizeof(int)); 
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
            for (i=0; i<n; i++) fprintf(fout, "%d ", a[i]);
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
    int i,j,k, r=0, flag=1;
    int* d;
    int* e;
    d=(int*) malloc(n*sizeof(int));
    e=(int*) malloc(n*sizeof(int));
    
    for (i=0; i<n; i++) d[i]=0; //массив делителей (будет увеличиваться на 1 с помощью массива е)
    for (i=0; i<n; i++) e[i]=0; //массив с единицей
    e[n-1]=1;
    
    while (flag==1) //пока c не превысило d
    {
        r=0;
        for (i=n-1; i>=0; i--)  //увеличиваем на 1 массив d
        {
            d[i]+=(e[i]+r);
            if (d[i]>9) r=1;
            else r=0;
            d[i]%=10;
        } 

        for (i=0; i<2*n; i++) c[i]=0;

        for (i=n-1; i>=0; i--) // умножаем b на d и получаем c
        {
            r=0;
            for (j=n-1; j>=0; j--)
            {
                c[j+i+1]+=(b[j]*d[i]);
                r=c[j+i+1]/10;
                c[j+i+1]%=10;
                c[i+j]+=r;
            }
            
        }
        
        for (k=0; k<2*n; k++) printf("%d", c[k]);
            printf("\n");
        for (k=0; k<n; k++) printf("%d", b[k]);
            printf("\n");
        for (k=0; k<n; k++) printf("%d", d[k]);
            printf("\n");
        
        for (i=0; i<n; i++) //сравниваем a и c, чтобы c не было больше a
        {
            if (a[i]<c[n+i])
            {
                flag=0; //опускаем флаг, если это так
            }
            else if (a[i]>c[n+i]) break;
        }
        printf("flag = %d\n\n", flag);
    }

    r=0;
    for (i=n-1; i>=0; i--) //откатываемся на шаг назад, когда еще все было норм и записываем это в а
    {
        a[i]=(d[i]-e[i]+10-r)%10;
        if (d[i]>=e[i]) r=0;
        else r=1;
    }
    
    free (d);
    free (e);
}
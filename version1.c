#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <stdbool.h>
#include <time.h>

int rs, ps ;
int *re, *ss;
int **al, **mr , **ne;
int np = 0;

bool SafeSequence() 
{
    int a[rs];
    for(int i=0; i<rs; i++) 
		a[i] = re[i];
	bool f[ps];
    for(int i=0; i<ps; i++) 
		f[i] = false;
    int fd=0;
}

int main(int argc, char** argv) 
{
	srand(time(NULL));
	do
	{
        printf("\nNumber of processes : ");
        scanf("%d", &ps);
        printf("\nNumber of resources : ");
        scanf("%d", &rs);
        re = (int *)malloc(rs * sizeof(*re));
        printf("\nCurrently Available resources : \n");
        for(int i=0; i<rs; i++)
        {
            printf("%d : ",i+1);
            scanf("%d", &re[i]);
        }
        al = (int **)malloc(ps * sizeof(*al));
        for(int i=0; i<ps; i++)
        al[i] = (int *)malloc(rs * sizeof(**al));
        mr = (int **)malloc(ps * sizeof(*mr));
        for(int i=0; i<ps; i++)
        mr[i] = (int *)malloc(rs * sizeof(**mr));
        printf("\n");
        for(int i=0; i<ps; i++) 
        {
            printf("\nResource allocated to process %d : \n", i+1);
            for(int j=0; j<rs; j++)
            {
                printf("%d : ", j+1);
                scanf("%d", &al[i][j]);
            }
        }
        printf("\n");
        for(int i=0; i<ps; i++) 
        {
            printf("\nMaximum resource required by process %d : \n", i+1);
            for(int j=0; j<rs; j++)
                {
                    printf("%d : ", j+1);
                    scanf("%d", &mr[i][j]);
                }
        }
        printf("\n");
        ne = (int **)malloc(ps * sizeof(*ne));
        for(int i=0; i<ps; i++)
        ne[i] = (int *)malloc(rs * sizeof(**ne));
        for(int i=0; i<ps; i++)
        for(int j=0; j<rs; j++)
        ne[i][j] = mr[i][j] - al[i][j];
        ss = (int *)malloc(ps * sizeof(*ss));
        for(int i=0; i<ps; i++) ss[i] = -1;
        if(!SafeSequence()) 
        {
            printf("\nSystem is in unsafe state.\n\n");
            exit(-1);
        }
        printf("\n\nSafe Sequence Found : ");
        for(int i=0; i<ps; i++)
        {
            printf("%-3d", ss[i]+1);
        }
        free(re);
        for(int i=0; i<ps; i++) 
        {
            free(al[i]);
            free(mr[i]);
            free(ne[i]);
        }
        free(al);
        free(mr);
        free(ne);
        free(ss);
	}
} 

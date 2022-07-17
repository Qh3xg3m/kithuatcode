#include <stdio.h>

void inmatran(int m, int n, int a[][10])
{
	int i,j;
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("%d\t",a[j][i]);
		}
		printf("\n");
	}
}

void main()
{
	int m,n,i,j;
	int a[10][10];
	
	printf("So hang: "); scanf("%d",&m);
	printf("So cot: "); scanf("%d",&n);
	
	for (i=0; i<m; i++)
	{
		for (j=0;j<n;j++)
		{
			printf("A[%d][%d] = ",i,j);
			scanf("%d",&a[i][j]);
		}
	}
	
	printf("Ma tran chuyen vi la: \n");
	inmatran(n,m,a);
}

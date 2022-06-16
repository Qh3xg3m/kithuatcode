#include <stdio.h>

void tangdan(int a[], int n)
{
	int i, j, temp;
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (a[i]>a[j])
			{
				temp = a[i];
				a[i] = a[j]	;
				a[j] = temp;
			}
		}
	}
}

int xoa(int a[], int b[], int n)
{
	int i,j=0;
	b[j] = a[0];
	for (i=1; i<n;i++)
	{
		if (a[i]!=b[j])
		{
			j++;
			b[j] = a[i];
		}
	}
	return j;
}

void main()
{
	int n,i; 
	int a[100], b[100];
	printf("N = "); scanf("%d", &n);
	for (i=0; i<n;i++)
	{
		printf("A[%d] = ",i+1);
		scanf("%d",&a[i]);
	}
	tangdan(a,n);
	int m = xoa(a,b,n);
	printf("Day da xoa la:\n");
	for (i=0; i<=m;i++)
	{
		printf("%d\t",b[i]);
	}
}


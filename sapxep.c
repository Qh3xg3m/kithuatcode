#include <stdio.h>

void nhap(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("A[%d] = ", i+1);
		scanf("%d", &a[i]);
	}
}

void xuat(int a[], int n)
{
	int i;
	for (i=0; i<n; i++)
	{
		printf("%d ", a[i]);
	}
}

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

void giamdan(int a[], int n)
{
	int i, j, temp;
	for (i=0; i<n; i++)
	{
		for (j=i+1; j<n; j++)
		{
			if (a[i]<a[j])
			{
				temp = a[i];
				a[i] = a[j]	;
				a[j] = temp;
			}
		}
	}
}

int main()
{
	int n;
	printf("n = ");
	scanf("%d", &n);
	int a[n];
	nhap(a,n);
	printf("\nDay ban dau: \n");
	xuat(a,n);
	printf("\nDay tang dan: \n");
	tangdan(a,n);
	xuat(a,n);
	printf("\nDay giam dan: \n");
	giamdan(a,n);
	xuat(a,n);
}






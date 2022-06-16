#include <stdio.h>

// kiem tra 2 so co la hoan vi cua nhau ko


void sort(int arr[], int n)
{
	int i,j,temp;
	for (i=0; i<n; i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (arr[i]>arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int a[] = {1,5,2,3};
	int b[] = {2,1,4,5,3};
	int lena = sizeof(a) / sizeof(int);
	int lenb = sizeof(b) / sizeof(int);
	int i;

	if (lena != lenb)
	{
		printf("Do dai 2 day khac nhau\n");
		return 0;
	} else {
		sort(a,lena);
		sort(b,lenb);
	}

	for (i=0; i<lena; i++)
	{
		if (a[i] != b[i])
		{
			printf("Ko la hoan vi cua nhau\n");
			return 0;
		}
	}
	printf("Hoan vi\n");
	return 0;
}
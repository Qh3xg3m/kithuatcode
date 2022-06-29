#include <stdio.h>

void docfile(int *n, float a[][20])
{
	FILE *f;
	int i,j;
	char file[20];

	printf("Ten file: ");
	scanf("%s",&file);
	f = fopen(file,"r");
	fscanf(f,"%d",n);
	for (i=0;i<(*n);i++)
	{
		for (j=0;j<(*n);j++)
		{
			fscanf(f,"%f",&a[i][j]);
		}
	}
	fclose(f);
}

float tbc(int n, float a[][20])
{
	int i,j;
	float s=0;

	for (i=0;i<n;i++)
	{
		for (j=0;j<n;j++)
		{
			if (i+j>=n) s+= a[i][j];
		}
	}
	return s/(n-1)/n*2;
}

int check(int n, float a[][20])
{
	int i,j;
	for (i=0; i<n;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (a[i][j]!=0) return 0;
		}
	}
	return 1;
}

int main()
{
	float a[20][20];
	int n;
	
	docfile(&n,a);
	printf("TBC cac phan tu nam duoi duong cheo phu: %.1f\n",tbc(n,a));
	if (check(n,a)==0)
	{
		printf("Ko la ma tran tam giac tren\n");
	} else {
		printf("Ma tran A la ma tran tam giac tren\n");
	}
}


// 00 01 02 03 04
// 10 11 12 13 14 
// 20 21 22 23 24
// 30 31 32 33 34
// 40 41 42 43 44



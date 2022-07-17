#include <stdio.h>
#include<stdlib.h>

// viet ham doc file, ghi du lieu vao file (matrix)

void docfile(char file[], int *m, int *n, float *a)
{
	FILE *f;
	int i,j;
	
	f = fopen(file,"r");
	if(f == NULL) {
		printf("Error! \n");
		exit(1);
	}
	fscanf(f,"%d %d",m,n);
	for (i=0;i<(*m);i++)
	{
		for (j=0;j<(*n);j++)
		{
			fscanf(f,"%f",a+i*(*n)+j);
		}
	}
	fclose(f);
}

void ghifile(char file[], int *m, int *n, float *a)
{
	FILE *f;
	int i,j;
	
	f = fopen(file,"w");
	if(f == NULL) {
		printf("Error! \n");
		exit(1);
	}
	for (i=0;i<(*m);i++)
	{
		for (j=0;j<(*n);j++)
		{
			fprintf(f,"%.1f\t",(*(a+i*(*n)+j)));
		}
		fprintf(f,"\n");
	}
	fclose(f);
}

int main()
{
	char tenf[20];
	float a[20][20];
	int n,m;
	
	printf("Input: "); 
	scanf("%s",&tenf);
	docfile(tenf,&m,&n,*a);
	
	printf("Output: "); 
	scanf("%s",&tenf);
	ghifile(tenf,&m,&n,*a);
}


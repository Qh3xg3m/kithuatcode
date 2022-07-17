#include <stdio.h>
#include<stdlib.h>

void doctep(int *m, int *n, float a[][10])
{
	FILE *f;
	int i,j;
	char file[20];
	
	printf("Ten file: ");
	scanf("%s",&file);
	f = fopen(file,"r");
	if(f == NULL) {
		printf("Error! \n");
		exit(1);
	}
	fscanf(f,"%d %d\n",m,n);
	for (i=0;i<*m;i++){
		for (j=0;j<*n;j++){
			fscanf(f,"%f",&a[i][j]);
		}
	}
	fclose(f);
}

float TBC(int m, int n, float a[][10])
{
	int i,j;
	float s=0;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			s += a[i][j];
		}
	}
	return s/m/n;
}

float tong(int m, int n, float a[][10], int *check)
{
	int i,j;
	float tbc = TBC(m,n,a);
	float s=0;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (a[i][j]>tbc){
				s+=a[i][j];
				*check = 1;
			}
		}
	}
	return s;
}

float timmin(int m, int n, float a[][10])
{
	int i,j;
	float min=a[0][0];
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (a[i][j]<min) min=a[i][j];
		}
	}
	return min;
}

float phantuam(int m, int n, float a[][10])
{
	int i,j;
	float ammax=timmin(m,n,a);
	if (ammax>=0) return 1;
	for (i=0;i<m;i++){
		for (j=0;j<n;j++){
			if (a[i][j]>ammax && a[i][j]<0) ammax=a[i][j];
		}
	}
	return ammax;
}

int main()
{
	int m, n, check=0;
	FILE *f;
	float a[10][10];
	
	doctep(&m,&n,a);
	printf("m = %d\tn = %d\n",m,n);
	
	float temp=tong(m,n,a,&check);
	if (check==1){
		printf("Tong cac phan tu > TBC ma tran la: %.1f\n",temp);
	} else {
		printf("Ko co phan tu nao thoa man\n");
	}
	
	temp = phantuam(m,n,a);
	if (temp>0){
		printf("Ko co phan tu am\n");
	} else {
		printf("Phan tu am lon nhat la: %.1f\n",temp);
	}
}


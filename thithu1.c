#include <stdio.h>
#include <math.h>
#include<stdlib.h>

typedef struct {
	float x,y;
} danhsach;

void doctep(FILE *f, int *n, danhsach toado[])
{
	char file[20];
	int i;
	
	printf("Ten file: ");
	gets(file);
	f = fopen(file,"r");
	if(f == NULL) {
		printf("Error! \n");
		exit(1);
	}
	fscanf(f,"%d",n);
	for (i=0;i<*n;i++)
	{
		fscanf(f,"%f%f",&toado[i].x,&toado[i].y);
	}
	fclose(f);
}

void count(int n, danhsach toado[], int *trong, int *ngoai)
{
	int i;
	float temp;
	for (i=0;i<n;i++)
	{
		temp = sqrt(pow(toado[i].x,2)+pow(toado[i].y,2));
		if (temp>5) *ngoai+=1;
		if (temp<5) *trong+=1;
	}
}

int doixung(int n, danhsach toado[], int index[])
{
	int i,j,temp=0;
	for (i=0;i<n-1;i++)
	{
		for (j=i+1; j<n;j++)
		{
			if ((toado[i].x + toado[j].x==0) && (toado[i].y + toado[j].y==0))
			{
				index[temp] = i;
				temp++;
				index[temp] = j;
				temp++;
			}
		}
	}
	return temp;
}

void main()
{
	int n,trong,ngoai,dx,i;
	FILE *f;
	danhsach toado[50];
	int index[50];
	
	doctep(f,&n,toado);
	count(n,toado,&trong,&ngoai);
	dx = doixung(n,toado,index);
	
	printf("So diem nam ngoai: %d\n",ngoai);
	printf("So diem nam trong: %d\n",trong);
	if (dx==0){
		printf("Ko co diem dx qua doc toa do\n");
	} else {
		printf("Cac diem doi xung qua goc toa do la:\n");
		for (i=0;i<dx;i++)
		{
			i++;
			printf("(%.1f; %.1f) va (%.1f; %.1f)\n",toado[index[i-1]].x,toado[index[i-1]].y,toado[index[i]].x,toado[index[i]].y);
		}
	}

}


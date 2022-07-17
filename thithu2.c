#include <stdio.h>
#include <string.h>
#include<stdlib.h>

typedef struct {
	char name[30], tacgia[30];
	int nam;
} danhsach;

void doctep(FILE *f, int *n, danhsach sach[])
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
	fscanf(f,"%d\n",n);
	for (i=0;i<*n;i++)
	{
		fgets(sach[i].name,30,f);
		sach[i].name[strlen(sach[i].name)-1]='\0';
		fgets(sach[i].tacgia,30,f);
		sach[i].tacgia[strlen(sach[i].tacgia)-1]='\0';
		fscanf(f,"%d\n",&sach[i].nam);
	}
	fclose(f);
}

int find(int n, danhsach sach[])
{
	int i;
	char input[30];
	printf("Ten sach can tim: ");
	gets(input);
	for (i=0;i<n;i++)
	{
		if (strcmp(sach[i].name,input)==0) return i;  
	}
	return -1;
}

void sapxep(int n, danhsach sach[])
{
	danhsach temp;
	int i,j;
	for (i=0;i<n-1;i++)
	{
		for (j=i+1;j<n;j++)
		{
			if (sach[i].nam>sach[j].nam)
			{
				temp = sach[i];
				sach[i] = sach[j];
				sach[j] = temp;
			}
		}
	}
}

void ghitep(char tensach[])
{
	FILE *f;
	f = fopen("output.txt","a");
	if(f == NULL) {
		printf("Error! \n");
		exit(1);
	}
	fputs(tensach,f);
	fputs("\n",f);
	fclose(f);
}

void main()
{
	int n,i;
	FILE *f;
	danhsach sach[50];
	
	doctep(f,&n,sach);
	
	int temp = find(n,sach);
	if (temp==-1){
		printf("Ko tim thay sach\n");
	} else {
		printf("Quyen sach can tim: \n");
		printf("Ten: %s\n",sach[temp].name);
		printf("Tac gia: %s\n",sach[temp].tacgia);
		printf("Nam: %d\n",sach[temp].nam);	
	}
	
	sapxep(n,sach);
	if (sach[0].nam>=2000){
		printf("Ko co sach xuat ban truoc nam 2000\n");
	} else {
		printf("Cac sach xuat ban truoc nam 2000:\n");
		for (i=0;i<n;i++)
		{
			if (sach[i].nam<2000)
			{
				ghitep(sach[i].name);
			}
		}
	}	
}


#include <stdio.h>

// nhan 2 ma tran

void nhap(int a[][10], int hang, int cot)
{
	int i,j;
	for (i=0;i<hang;i++)
	{
		for (j=0;j<cot;j++)
		{
			printf("A[%d][%d] = ",i+1,j+1);
			scanf("%d",&a[i][j]);
		}
	}
}

void xuat(int a[][10], int hang, int cot)
{
	int i,j;
	for (i=0;i<hang;i++)
	{
		for (j=0;j<cot;j++)
		{
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

void nhanmatran(int a[][10], int b[][10], int c[][10],int hang1,int cot1,int hang2,int cot2)
{
	int i,j,k;
	for (i=0; i<hang1; i++)
	{
		for (j=0; j<cot2; j++)
		{
			c[i][j] = 0;
			for (k=0; k<cot1; k++)
			{
				c[i][j] += a[i][k] * b[k][j];
			}
		}
	}
}

int main()
{
	int i,j,k;
	int a[10][10], b[10][10], c[10][10];
	int hang1,cot1,hang2,cot2,hang3,cot3;
	
	printf("Ma tran 1: \n");
	printf("So hang: "); scanf("%d",&hang1);
	printf("So cot: "); scanf("%d",&cot1);
	nhap(a,hang1,cot1);
	
	printf("Ma tran 2: \n");
	printf("So hang: "); scanf("%d",&hang2);
	printf("So cot: "); scanf("%d",&cot2);
	nhap(b,hang2,cot2);
	
	if (cot1==hang2)
	{
		hang3 = hang1;
		cot3 = cot2;
		nhanmatran(a,b,c,hang1, cot1, hang2,cot2);
		xuat(c,hang3,cot3);
		return 0;
	} else {
		printf("ko nhan dc !");
		return 0;
	}

}




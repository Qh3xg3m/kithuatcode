#include <stdio.h>

int check(int a[][9], int hang, int cot, int n)
{
    int i;
    for (i=0; i<9; i++)
    {
        if (a[hang][i] == n || a[i][cot] == n)
        {
            return 0;
        }
    }
    if (a[hang][cot] != 0)
    {
    	return 0;
	}
    return 1;
}

int isFull(int a[][9])
{
	int i, j;
	for (i=0; i<9; i++)
    {
        for (j=0; j<9; j++)
        {
        	if (a[i][j]==0)
        	{
        		return 0;
			}
		}
    }
    return 1;
}

void output(int a[][9])
{
    system("cls");
    int i, j;
    for (i=0; i<9; i++)
    {
        for (j=0; j<9; j++)
        {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
	printf("\n");
}

int main()
{
	int hang, cot, n;
    int a[9][9] = {
        {0,1,0,0,5,0,8,0,0},
        {0,3,0,4,0,7,0,9,0},
        {2,0,5,0,0,9,0,0,0},
        {0,2,0,7,0,0,9,0,0},
        {1,0,2,0,6,0,7,0,0},
        {0,0,0,3,0,0,0,0,0},
        {8,0,0,0,0,0,4,0,3},
        {0,0,4,0,0,3,0,1,0},
        {0,4,0,0,0,0,2,0,0}
        };
    output(a);
	while (isFull(a)==0)
	{
		printf("Nhap o muon dien (hang cot): "); scanf("%d%d", &hang, &cot);
		printf("Nhap so muon dien: "); scanf("%d", &n);
		if (check(a,hang-1,cot-1,n)==1)
		{
			a[hang-1][cot-1] = n;
		}
		output(a);
	}
	printf("You Win!\nThanks For Playing My Game <3 \n");
}



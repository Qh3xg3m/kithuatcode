#include <stdio.h>
#include <math.h>

int nguyento(int n)
{
	int i;
	for (i = 2; i<=sqrt(n);i++)
	{
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}

int doixung(int n)
{
	char str[50];
	int length = sprintf(str,"%d", n);
	int i;
	for (i=0; i<length;i++)
	{
		if (str[i] != str[length-i-1])
		{
			return 0;
		}
	}
	return 1;
}

int main()
{
	int n,i;
	printf("n = "); scanf("%d", &n);
	for (i=11; i<=n; i++)
	{
		if (nguyento(i)==1 && doixung(i)==1)
		{
			printf("%d\n",i);
		}
	}
}

#include <stdio.h>

// phan tich thanh thua so nguyen to

int main()
{
	int n,i=2;
	printf("N = "); scanf("%d", &n);
	printf("%d = ", n);
	while (n != 1)
	{
		if (n%i==0)
		{
			n /= i;
			if (n>1){
				printf("%d*",i);
			} else {
				printf("%d",i);
			}
		} else {
			i++;
		}
	}
	printf("\n");
}
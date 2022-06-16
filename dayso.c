#include <stdio.h>

//tim UCLN BCNN cua 1 day so nguyen 

int uocchung(int a, int b);
int boichung(int a, int b);
int ucln(int number[], int n);
int bcnn(int number[], int n);

int main()
{
	int number[10] = {20,40,60,15};
	int n = 4;
	
	printf("UCLN: %d\n",ucln(number,n));
	printf("BCNN: %d\n",bcnn(number,n));
}

int ucln(int number[], int n)
{
	int i, uoc = uocchung(number[0],number[1]);
	for (i=2 ; i < n ; i++)
	{
		uoc = uocchung(uoc,number[i]);
	}
	return uoc;
}

int bcnn(int number[], int n)
{
	int i, temp = boichung(number[0], number[1]);
	for (i=2; i<n; i++)
	{
		temp = boichung(temp,number[i]);
	}
	return temp;
}

int uocchung(int a, int b)
{
	while (a != b)
	{
		if (a>b)
		{
			a = a - b;
		} else {
			b = b - a;
		}
	}
	return a;
}

int boichung(int a, int b)
{
	return a*b/uocchung(a,b);
}


#include <stdio.h>


void daonguoc(char x[])
{
	int n, i=0;
	char temp;
	for (n = 0 ; x[n] != '\0' ; n++) {} // tim do dai chuoi
	while (i<n)
	{
		n--;
		temp = x[i];
		x[i] = x[n];
		x[n] = temp;
		i++;
	}
}

int main()
{
	char x[50] = "123asd/*-";
	printf("ban dau: x = %s\n",x);
	daonguoc(x);
	printf("luc sau: x = %s\n",x);
}

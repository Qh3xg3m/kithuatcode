#include <stdio.h>

// cho 2 day tang dan
// sap xep thanh 1 day tang dan ma ko gop 2 day

void main()
{
	int a[] = {2,5,7,8,10,12,15,20};
	int b[] = {1,6,7,9};
	int c[100];
	int lena = sizeof(a) / sizeof(a[0]);
	int lenb = sizeof(b) / sizeof(b[0]);
	int i,j,k,ii,jj;

	for (i=0,j=0,k=0 ; i<lena && j<lenb;)
	{
		if (a[i]<b[j])
		{
			c[k] = a[i];
			k++; i++;
		} else {
			c[k] = b[j];
			k++; j++;
		}
	}

	int kk=k;
	if (i<lena && j>=lenb)
	{
		for (ii=i; ii<lena; ii++, kk++)
		{
			c[kk] = a[ii];
		}
	}

	if (i>=lena && j<lenb)
	{
		for (jj=j; jj<lenb; jj++, kk++)
		{
			c[kk] = b[jj];
		}
	}

	for (i=0; i<kk; i++)
	{
		printf("%d ",c[i]);
	}
}
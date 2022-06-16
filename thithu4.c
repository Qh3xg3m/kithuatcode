#include <stdio.h>
#include <string.h>

typedef struct {
	char name[30], school;
	float diem;
} danhsach;

void doctep(int *n, danhsach sv[])
{
	FILE *f;
	int i;
	
	f = fopen("input.txt","r");
	fscanf(f,"%d\n",n);
	for (i=0;i<*n;i++){
		fgets(sv[i].name,30,f);
		sv[i].name[strlen(sv[i].name)-1]='\0';
		fscanf(f,"%f\n",&sv[i].diem);
		fscanf(f,"%c\n",&sv[i].school);
	}
	fclose(f);
}

char truongmax(int n, danhsach sv[], float *a, float *b, float *c, float *d)
{
	int i;
	for (i=0; i<n;i++){
		if (sv[i].school=='A') *a+=sv[i].diem;
		if (sv[i].school=='B') *b+=sv[i].diem;
		if (sv[i].school=='C') *c+=sv[i].diem;
		if (sv[i].school=='D') *d+=sv[i].diem;
	}
	float max = *a;
	max = (*b>max)?*b:max;
	max = (*c>max)?*c:max;
	max = (*d>max)?*d:max;
	
	if (max==*a) return 'A';
	if (max==*b) return 'B';
	if (max==*c) return 'C';
	if (max==*d) return 'D';
}

int thisinhmax(int n, danhsach sv[], int ts[])
{
	int i,count=0;
	float max = sv[0].diem;
	for (i=0;i<n;i++){
		max = (sv[i].diem>max)?sv[i].diem:max;
	}
	for (i=0;i<n;i++){
		if (sv[i].diem==max){
			ts[count] = i;
			count++;
		}
	}
	return count;
}

void ghitep(char inp[30])
{
	FILE *f;
	f = fopen("output.txt","a");
	fputs(inp,f);
	fprintf(f,"\n");
	fclose(f);
}

int main()
{
	danhsach sv[30];
	int n,i;
	float a=0,b=0,c=0,d=0;
	int ts[30];
	
	doctep(&n,sv);
	char temp = truongmax(n,sv,&a,&b,&c,&d);
	printf("Tong diem truong A: %.1f\n",a);
	printf("Tong diem truong B: %.1f\n",b);
	printf("Tong diem truong C: %.1f\n",c);
	printf("Tong diem truong D: %.1f\n",d);
	printf("Truong co tong diem cao nhat: %c\n",temp);
	
	int count = thisinhmax(n,sv,ts);
	printf("Cac thi sinh dat diem cao nhat:\n");
	for (i=0;i<count;i++){
		printf("%s\n",sv[ts[i]].name);
		ghitep(sv[ts[i]].name);
	}
}


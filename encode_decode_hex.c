// encode string to hexadecimal and hexadecimal to string
//NullByte
#include <stdio.h>


void *encode_decode(char *encode){
	printf("[$] Encoding string -> ");
	for (int i = 0; i < sizeof(encode); i++){
		printf("\\0x0%x",encode[i]);
	printf("\n[#] Decoding String -> ");
		for (i; i < sizeof(encode);i++){
			printf("%c",encode[i]);
		}
	}
}


int main(void){


	char encodes[100]; 

	printf("[!] PUT YOUR STRING -> ");
	fgets(encodes,100,stdin);
	encode_decode(encodes);

	return 0;
}

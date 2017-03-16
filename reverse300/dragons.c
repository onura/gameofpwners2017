#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <string.h>


#define MSG_LEN 50

char KEY[] = "crackersgonnacrack";
char CMP[] = "\x1c\x3\x11\x4\x10\x12\xa\x4\x2\x4\x6\x6\x4\xa\x3\x13\x5\x6\xf\x3\x5\x1\x7\x4\xb\x4\x7\x4\xf\x64";

//GoP_{whoisthemotherofdragons}


void endfunc();

void chck1() {
	if (ptrace(PTRACE_TRACEME) == -1)
		exit(0); 
}

void chck2() {
	char *i;

	for(i = &chck1; i < &endfunc; i++) {
		if (*i == 0xCC)
			exit(0);
	}
}

short chck3(char* input) {
	short i;
	char msg[strlen(input)+1];
	
	if (strlen(input) < 1)
		return -1;

	for (i = 0; i < strlen(input); i++) {
		msg[i] = abs(input[i] - KEY[i % strlen(KEY)]);
	//	printf("\\x%hhx", msg[i]);
	}
	//printf("\n");
	
	for (i = 0; i < strlen(input); i++)
		if (CMP[i] != msg[i])
			return -1; 

	return 0;
}

int main() {
	char input[MSG_LEN];

	chck1();
	chck2();

	fgets(input, MSG_LEN, stdin);

	if (chck3(input) == 0)
		printf("You are the one!\n"); 
	else
		printf("This is the game of pwners, not loosers!\n");

	return 0;
}

void endfunc() {};

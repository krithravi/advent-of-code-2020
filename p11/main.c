#include <stdio.h>
//#define LINE_LENGTH 99
//#define FILE_SIZE 98
#define LINE_LENGTH 10
#define FILE_SIZE 10

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int main () {
	FILE *fp;
	fp = fopen("smol.txt", "r");


	char prev[FILE_SIZE][LINE_LENGTH];
	char curr[FILE_SIZE][LINE_LENGTH];

	for (int i = 0; i < FILE_SIZE; i++) {
		for (int j = 0; j < LINE_LENGTH; j++) {
			prev[i][j] = 'a';
			curr[i][j] = 'a';
			printf("%c", prev[i][j]);
		}
		printf("\n");
	}

	int index = 0;

	char buf[LINE_LENGTH];
	while(fgets(buf, sizeof buf, fp) != NULL) {

		char temp[FILE_SIZE];
		int i;
		for (i = 0; buf[i] != '\0'; i++) {
			temp[i] = buf[i];
			printf("%c", temp[i]);
		}
		//printf("\n");
		//printf(RED "%s" RESET, buf);
		//curr[index] = buf;
		index++;
	}


	fclose(fp);
}

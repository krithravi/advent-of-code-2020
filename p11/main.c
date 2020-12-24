#include <stdio.h>
//#define LINE_LENGTH 99
//#define FILE_SIZE 98
#define LINE_LENGTH 12
#define FILE_SIZE 10

#define RED     "\x1b[31m"
#define GREEN   "\x1b[32m"
#define YELLOW  "\x1b[33m"
#define BLUE    "\x1b[34m"
#define MAGENTA "\x1b[35m"
#define CYAN    "\x1b[36m"
#define RESET   "\x1b[0m"

int areEqual(char a[FILE_SIZE][LINE_LENGTH - 2], char b[FILE_SIZE][LINE_LENGTH - 2]) {
	for (int i = 0; i < FILE_SIZE; i++) {
		for (int j = 0; j < LINE_LENGTH - 2; j++) {
			if (a[i][j] != b[i][j]) {
				return 0;
			}
		}
	}
	return 1;
}

int main () {
	FILE *fp;
	fp = fopen("smol.txt", "r");


	char prev[FILE_SIZE][LINE_LENGTH - 2];
	char curr[FILE_SIZE][LINE_LENGTH - 2];

	for (int i = 0; i < FILE_SIZE - 2; i++) {
		for (int j = 0; j < LINE_LENGTH -2; j++) {
			prev[i][j] = 'a';
			curr[i][j] = 'a';
			printf("%c", prev[i][j]);
		}
		printf("\n");
	}

	int index = 0;

	char buf[LINE_LENGTH];
	while(fgets(buf, sizeof buf, fp) != NULL) {

		char temp[LINE_LENGTH - 2];
		int i;
		printf("%d: ", index);
		for (i = 0; buf[i] != '\0'; i++) {
			//temp[i] = buf[i];
			//
			printf( CYAN "%c" RESET, temp[i]);
		}
		//printf("\n");
		//printf(RED "%s" RESET, buf);
		//curr[index] = temp;

		index++;
	}


	fclose(fp);
}

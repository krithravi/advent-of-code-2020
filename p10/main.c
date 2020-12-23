#include <stdio.h>
#include <stdlib.h>
#define LINE_LENGTH 10
#define FILE_SIZE 108
int main(){
	int num1diff = 0;
	int num3diff = 0;

	// read in info
	FILE *fp;
	fp = fopen("text.txt", "r");
	char buf[LINE_LENGTH];

	int data[FILE_SIZE];
	int index = 0;
	while (fgets(buf, sizeof buf, fp) != NULL) {
		data[index] = atoi(buf);
		index++;
	}

	fclose(fp);


	// start with 0
	// pick the next 

	printf("final res: %d\n", num1diff * num3diff);
	}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LINE_LENGTH 15
#define FILE_SIZE 700

int main () {

	for (int changeIndex = 0; changeIndex < FILE_SIZE; changeIndex++) {

		printf("changeIndex: %d\t", changeIndex);
		FILE *fp;
		fp = fopen("p2.txt" , "r");
		char buf[LINE_LENGTH];

		int accum = 0;

		// the original list
		char a[FILE_SIZE][LINE_LENGTH];

		// no garbage values
		for (int i = 0; i < FILE_SIZE; i++) {
			strcpy(a[i], "");
		}

		int index = 0;
		while (fgets(buf, sizeof buf, fp) != NULL) {
			// get everything, chuck it into array
			strcpy(a[index], buf);
			index++;
		}

		fclose(fp);


		// now for going thru the orig and done
		int aInd = 0;
		int num = 1;

		int repeat = 0;

		while (repeat == 0) {
			//printf("num: %d ", num);
			// check if done contains tmp
			if (strcmp(a[aInd], "done") == 0) {
				repeat = 1;

				//printf("repeatVal: %d\t", repeat);
				// not there yet ig, change back

			}
			else {
				if (aInd == changeIndex) {
					if (a[aInd][0] == 'a') {
						char tmp[LINE_LENGTH] = "";
						for (int i = 4; i < LINE_LENGTH; i++) {
							char smol[2] = {a[aInd][i]};
							strcat(tmp, smol);
						}

						int c = atoi(tmp);
						accum += c;
						//printf("acc: %d\n", aInd + 1);

						strcpy(a[aInd], "done");
						aInd++;
					}
					else if (a[aInd][0] == 'j') {
						strcpy(a[aInd], "done");
						aInd++;
					}
					else {
						char tmp[LINE_LENGTH] = "";
						for (int i = 4; i < LINE_LENGTH; i++) {
							char smol[2] = {a[aInd][i]};
							strcat(tmp, smol);
						}

						int c = atoi(tmp);
						//printf("jmp: %d\n", aInd + 1);

						strcpy(a[aInd], "done");
						aInd += c;
					}
				}
				else {
					if (a[aInd][0] == 'a') {
						char tmp[LINE_LENGTH] = "";
						for (int i = 4; i < LINE_LENGTH; i++) {
							char smol[2] = {a[aInd][i]};
							strcat(tmp, smol);
						}

						int c = atoi(tmp);
						accum += c;
						//printf("acc: %d\n", aInd + 1);

						strcpy(a[aInd], "done");
						aInd++;
					}
					else if (a[aInd][0] == 'j') {
						// 4 to end
						char tmp[LINE_LENGTH] = "";
						for (int i = 4; i < LINE_LENGTH; i++) {
							char smol[2] = {a[aInd][i]};
							strcat(tmp, smol);
						}

						int c = atoi(tmp);
						//printf("jmp: %d\n", aInd + 1);

						strcpy(a[aInd], "done");
						aInd += c;
					}
					else {
						//printf("nop: %d\n", aInd + 1);
						strcpy(a[aInd], "done");
						aInd++;
					}
				}
			}
			num++;
		}
		printf("repeat%d", repeat);
		printf("final: %d\n\n", accum);
	}



	//printf("\nfinal: %d\n", accum);

}



#include <stdio.h>
#include <string.h>
#define LINE_LENGTH 200
#define MAP_SIZE 600


struct Map {
    char key[LINE_LENGTH];
    char value[LINE_LENGTH];
};


int main() {

    char DELIM [] = "contain";

    FILE *fp;
    fp = fopen("text.txt" , "r");
    char buf[LINE_LENGTH];

    struct Map map[MAP_SIZE];
    int index = 0;

    while (fgets(buf, sizeof buf, fp) != NULL) {
        // split buf - get a p1 and p2

		char p1 [LINE_LENGTH] = "";
		char p2 [LINE_LENGTH] = "";

		const char s[] = " ";
		char *token;
		token = strtok(buf, s);

		int isRHS = 0;
		while (token != NULL) {
			if (strcmp(token, "contain") == 0) {
				isRHS = 1;
			}
			else if (isRHS == 0) {
				strcat(p1, token);
			}
			else {
				strcat(p2, token);
			}

			token = strtok(NULL, s);
		}

		//printf("BAG: %s\n", p1);
		//printf("CONTENTS: %s\n", p2);

        // put (p1, p2) in a map
		struct Map tmp = {*p1, *p2};
		map[index] = tmp;
		printf("key retrieval: %s\n", tmp.key);

        index++;
    }

    fclose(fp);

	/*
	for (int i = 0; i < MAP_SIZE; i++) {
		printf("key: %s \n", map[i].key);
	}
	*/

    return 0;
}



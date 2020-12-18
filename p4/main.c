#include <stdio.h>
#include <string.h>

int main () {
    char myStr [200] = "mirrored blue bags contain 3 striped tan bags.";

	char p1[200] = "";
	char p2[200] = "";

	const char s[] = " ";
	char *token;
	token = strtok(myStr, s);

	// strtok
	int isRHS = 0;
	while (token != NULL) {
		//printf("comparing: %s %s %d\n", token, "contain", strcmp(token, "contain"));
		if (strcmp(token, "contain") == 0) {
			//printf("contains?: %s\n", token);
			isRHS = 1;
		}
		else if (isRHS == 0) {
			//printf("lhs: %s\n", token);
			strcat(p1, token);
			//printf("updated lhs: %s\n", p1);
			//printf("just checking: %s\n\n", p2);
		}
		else if (isRHS == 1){
			//printf("rhs: %s\n", token);
			strcat(p2, token);
			//printf("updated rhs: %s\n", p2);
			//printf("just checking: %s\n\n", p1);

		}
		token = strtok(NULL, s);
	}
	printf("output: \n");
	printf("p1: %s\n", p1);
	printf("p2: %s\n", p2);

}

#include <stdio.h>

int main () {
    printf("Hello world\n");
    FILE *fp;
    
    int x = 0;
    fp = fopen("text.txt" , "r");

    char buf[50];
    int count = 0;
    // only need to change the vert bit of slope
    int lineNum = 0;
    while (fgets(buf, sizeof buf, fp) != NULL) {
        if (lineNum % 2 == 0) {
            // buf is a string we can work with=
            if ((buf[x % 31]) == '#')
                count++;=
            // update value based on slope
            x += 1;
        }
        lineNum++;
    }
    printf("value: %d\n", count);
    fclose(fp);
    return 0;
}
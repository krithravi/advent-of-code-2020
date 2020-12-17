#include <stdio.h>
int seatVal (char str []);
int main() {
    FILE *fp;
    fp = fopen("text.txt" , "r");

    char buf[50];

    int max = -1;

    int resArr [1000];
    for (int i = 0 ; i < 1000; i++) {
        resArr[i] = -1;
    }

    while (fgets(buf, sizeof buf, fp) != NULL) {
        int tmp = seatVal(buf);
        if (tmp > max) {
            max = tmp;
        }
        resArr[tmp] = tmp;
    }

    printf("result: %d\n", max);

    fclose(fp);
    /*
    for (int i = 0 ; i < 1000; i++) {
        printf("%d ", resArr[i]);
    }
    */
    for (int i = 1 ; i < 999; i++) {
        if (resArr[i -1] != -1 && resArr[i + 1] != 1 && resArr[i] == -1) {
            printf("my seat: %d\n", i);
        }
    }
    printf("\n");
}

int seatVal (char str []) {
    int lower = 0;
    int upper = 127;

    int index = 0;

    // get the row
    for (index; index < 7; index++) {
        char item = str[index];
        // the lower half
        if (item == 'F') {
            upper = (upper - lower + 1)/2 + lower - 1;
        }
        // the upper half
        else {
            lower = upper - (upper - lower + 1)/2 + 1;
        }
        //printf("lower: %d upper: %d\n", lower, upper);
    }
    int row = upper;

    // get the col
    lower = 0;
    upper = 7;
    for (index; index < 10; index++) {
        char item = str[index];
        // the lower half
        if (item == 'L') {
            upper = (upper - lower + 1)/2 + lower - 1;
        }
        // the upper half
        else {
            lower = upper - (upper - lower + 1)/2 + 1;
        }
        //printf("lower: %d upper: %d\n", lower, upper);
    }
    int col = upper;

    //printf("row: %d col: %d\n", row, col);
    int res = row * 8 + col;
    //printf("%d\n", res);

    return res;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isValid(char input[]);

int main() {

    FILE *fp;
    
    fp = fopen("text.txt" , "r");

    char buf[50];

    int count = 0;
    while (fgets(buf, sizeof buf, fp) != NULL) {
        int temp = isValid(buf);
        if (temp == 1)
            count++;
        printf("%d\n", temp);

    }
    printf("result %d\n", count);
    fclose(fp);

}

int isValid(char input[]) {

    int index = 0;

    // get the min
    int min;
    char minArr[10];
    int minIndex = 0;
    
    while (input[index] != '-') {
        minArr[minIndex] = input[index];
        minIndex++;
        index++;
    }
    min = atoi(minArr);
    //printf("%d\n", min);
    
    // skip over
    index++;
    // get the max

    int max;
    char maxArr[10];
    int maxIndex = 0;

    while (input[index] != ' ') {
        maxArr[maxIndex] = input[index];
        maxIndex++;
        index++;
    }
    max = atoi(maxArr);
    //printf("%d\n", max);

    // skip over
    index++;
    // get the char
    char item = input[index];
    //printf("%c\n", item);

    // skip over 2
    index += 2;

    // count the rest
    // CODE FROM PART 1
    /*
    int currCount;
    while (input[index] != '\0') {
        if (input[index] == item)
            currCount++;
        //printf("%c", input[index]);
        //printf("\n");
        index++;
    }
    

    return (currCount >= min && currCount <= max);
    */

    // CODE FROM PART 2
    int passIndex = 1;
    char first;
    char second;
    while (input[index] != '\0') {
        //printf("pin %d", passIndex);
        //printf("%c", input[index]);
        if (passIndex == min) {
            first = input[index + 1];
            //printf("pin %d first %c\n", passIndex, first);
        }

        if (passIndex == max) {
            second = input[index + 1];
            //("pin %d second %c\n", passIndex, second);
        }
        index++;
        passIndex++;
    }


    //printf("%c %c", first, second);
    return (first == item) ^ (second == item);

}
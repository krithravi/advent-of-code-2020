#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
int main() {
    printf("hello world\n");
    FILE *fp;
    
    fp = fopen("text.txt" , "r");

    int arr [200];
    int index = 0;

    char buf[10];
    while (fgets(buf, sizeof buf, fp) != NULL) {
        //printf("String read: %s\n", buf);
        arr[index] = atoi(buf);
        //printf("Integer: %d \n", atoi(buf));
        index++;;
    }
    

    fclose(fp);
    for (int k = 0; k < 200; k++) {
        for (int i = 0; i < 200; i++) {
            int tmp = 2020 - arr[k] - arr[i];
            if (contains(arr, tmp) == 1 ) {
                int temp = arr[i] * (tmp) * arr[k];
                printf("list: %d %d %d \n", arr[k], arr[i], tmp );
                printf("value: %d\n", temp);
            }
        }
    }
    printf("gothere\n");
    return 0;
}

int contains(int arr[], int val) {
    for (int i = 0; i < 200; i++) {
        if (arr[i] == val)
            return 1;
    }
    return 0;
}
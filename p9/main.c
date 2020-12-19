#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#define LINE_LENGTH 20
#define FILE_SIZE 1000
#define PREAMBLE_SIZE 25

/* returns whether or not the number at a
 * given position can be expressed as the sum
 * of the previous *preamble_size* numbers
 *
 */
int isSum(int arr[FILE_SIZE], int pos) {
	int val = arr[pos];
	int low = pos - PREAMBLE_SIZE;
	int high = pos;
	for (int i = low; i <= high; i++) {
		for (int j = i + 1; j <= high; j++) {
			if (i !=j && arr[i] + arr[j] == val){
				return 1;
			}
		}
	}
	return 0;
}

int main () {
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

	int res = 0;
	for (int i = PREAMBLE_SIZE; i < FILE_SIZE; i++) {

		if (isSum(data,i) == 0) {
			printf("part 1: %d %d\n", i, data[i]);
			res = data[i];
		}
	}

	int beg = 0;
	int end = 0;

	for (int i = 0; i < FILE_SIZE; i++) {
		int sum = 0;
		for (int j = i; j < FILE_SIZE; j++) {
			sum += data[j];
			if (sum == res && i != j) {
				printf("p2 range %d %d\n", data[i], data[j]);
				beg = i;
				end = j;
				printf("debugging %d %d\n", beg, end);
				break;
			}
		}
	}

	int check = 0;
	for (int i = beg; i <= end; i++) {
		check += data[i];
	}
	printf("sum checking %d\n", check);


	int min = INT_MAX;
	int max = INT_MIN;

	for (int i = beg; i <= end; i++) {
		if (data[i] < min)
			min = data[i];
		if (data[i] > max)
			max = data[i];
	}
	printf("min: %d max: %d\n", min,  max);
	printf("final res: %d\n", min + max);

}

#include <stdlib.h>

int compare(const void *a, const void *b) {
    int **x = (int **)a;
    int **y = (int **)b;
    return (*x)[0] - (*y)[0];
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize,
            int* returnSize, int** returnColumnSizes) {

    // Sort intervals according to starting value
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    // Allocate result
    int **result = malloc(intervalsSize * sizeof(int*));
    *returnColumnSizes = malloc(intervalsSize * sizeof(int));

    int count = 0;

    // First interval
    result[count] = malloc(2 * sizeof(int));
    result[count][0] = intervals[0][0];
    result[count][1] = intervals[0][1];
    (*returnColumnSizes)[count] = 2;
    count++;

    // Merge intervals
    for (int i = 1; i < intervalsSize; i++) {

        // Overlap
        if (intervals[i][0] <= result[count - 1][1]) {

            if (intervals[i][1] > result[count - 1][1]) {
                result[count - 1][1] = intervals[i][1];
            }

        } 
        // No overlap
        else {
            result[count] = malloc(2 * sizeof(int));
            result[count][0] = intervals[i][0];
            result[count][1] = intervals[i][1];
            (*returnColumnSizes)[count] = 2;
            count++;
        }
    }

    *returnSize = count;

    return result;
}
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <netdb.h>

typedef int elementtype;

int data_source[20] = {12,3,45,45,46,213,48,87,678,1,454,56,5756,23,123,34,487,234,56,5474};
int data_sort[20];

void merge(int data[], int* sort, int start, int middle, int end) {
    int i = start, j = middle + 1;
    int k = start;
    int s = start;
    printf("merge start %d, middle %d, end %d\n", start, middle, end);

    while (i <= middle && j <= end) {
        if (data[i] <= data[j]) {
            data_sort[k++] = data[i++];
        } else {
            data_sort[k++] = data[j++];
        }
    }
    while (i <= middle) {
        data_sort[k++] = data[i++];
    }
    while (j <= end) {
        data_sort[k++] = data[j++];
    }

    int num = end - start + 1;
    for(int n=0; n<num; n++,s++) {
        data[s] = data_sort[s];
    }
}

void merge_sort(int data[], int* sort, int start, int end) {
    // printf("merge_sort start %d, end %d\n", start, end);
    if (start >= end) {
        return;
    }

    int middle = (end + start) / 2;
    merge_sort(data, sort, start, middle);
    merge_sort(data, sort, middle + 1, end);

    merge(data, sort, start, middle, end);
}

void merge_sort(int data[], int num) {
    int* sort = (int*) malloc(sizeof(data_source));
    if (sort != nullptr) {
        merge_sort(data, sort, 0, num);
        free(sort);
    }
}

int main() {
    for (int i=0; i<20; i++) {
        printf("data_source[%d]=%d\n", i, data_source[i]);
    }
    merge_sort(data_source, 19);
    printf("---------------------------\n");
    for (int i=0; i<20; i++) {
        printf("data_source[%d]=%d\n", i, data_source[i]);
    }
    printf("---------------------------\n");
    for (int i=0; i<20; i++) {
        printf("data_sort[%d]=%d\n", i, data_sort[i]);
    }

    return 0;
}

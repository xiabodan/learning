#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <netdb.h>

typedef int elementtype;

/*                     0  1  2  3  4  5  6   7  8  9 10  11  12  13  14 15 16  17  18  19 */
int data_source[20] = {12,3,45,45,46,213,48,87,678,1,454,56,5756,23,123,34,487,234,56,5474};
int data_sort[20];

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

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

int middle(int data[], int left, int right) {
    int center = (left + right) / 2;
    if(data[left] > data[center])
        swap(&data[left], &data[center]);
    if(data[left] > data[right])
        swap(&data[left], &data[right]);
    if(data[center] > data[right])
        swap(&data[center], &data[right]);

    swap(&data[center], &data[right - 1]);
    return data[right - 1];
}

void quick_sort(int data[], int start, int end) {
    printf("quick_sort start %d, end %d\n", start, end);
    if (start >= end) {
        return;
    }

    if(start + 3 <= end) {
        int i = start;
        int j = end - 1;
        int pivot = middle(data, start, end);
        for(;;) {
            while(data[++i] < pivot) {
            }
            while(data[--j] > pivot) {
            }
            if (i < j) {
                swap(&data[i], &data[j]);
            } else {
                break;
            }
        }
        swap(&data[i], &data[end - 1]);

        printf("quick_sort i %d, pivot %d, j %d\n", i, pivot, j);

        quick_sort(data, start, i - 1);
        quick_sort(data, i + 1, end);
    } else {
        merge_sort(data + start, nullptr, start, end);
    }
}

void quick_sort(int data[], int num) {
    quick_sort(data, 0, num);
}

int main() {
    for (int i=0; i<20; i++) {
        printf("data_source[%d]=%d\n", i, data_source[i]);
    }
    quick_sort(data_source, 19);
    printf("---------------------------\n");
    for (int i=0; i<20; i++) {
        printf("data_source[%d]=%d\n", i, data_source[i]);
    }

    return 0;
}

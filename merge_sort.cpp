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

//
void Merge(elementtype A[], elementtype TA[], int lpos, int rpos, int rightend) {
    int leftend = rpos - 1;
    int numelement = rightend - lpos + 1;
    int tpos = lpos;

    while(lpos<=leftend && rpos<=rightend) {
        if(A[lpos] <= A[rpos]) {
            TA[tpos++] = A[lpos++];
        } else {
            TA[tpos++] = A[rpos++];
        }
    }

    while(lpos<=leftend)
        TA[tpos++] = A[lpos++];
    while(rpos<=rightend)
        TA[tpos++] = A[rpos++];

    int i = 0;
    for(i=0;i<numelement;i++,rightend--) {
        A[rightend] = TA[rightend];
    }
}

void MSort(elementtype A[], elementtype* TA, int left, int right) {
    if (left < right) {
        int center = (left + right) / 2;
        MSort(A, TA, left, center);
        MSort(A, TA, center + 1, right);
        Merge(A, TA, left, center + 1, right);
    }
}

void mergesort(elementtype A[], int n) {
    elementtype *TA;
    TA = (elementtype*)malloc(sizeof(elementtype)); //just malloc once
    if (NULL != TA) {
        MSort(A, TA, 0, n-1);
        free(TA);
    } else {
        printf("error: TA can't be empty!\n");
    }
}
//

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

    // mergesort(data_source, 20);
    // printf("---------------------------\n");
    // for (int i=0; i<20; i++) {
    //     printf("data_source[%d]=%d\n", i, data_source[i]);
    // }
    return 0;
}

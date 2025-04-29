#include <stdio.h>
#include <math.h>

void merge(int arr[], int low, int mid, int high) {
    int n1, n2, i, j, k;
    n1 = mid - low + 1;
    n2 = high - mid;
    int l[n1 + 1];
    int r[n2 + 1];

    for (i = 0; i < n1; i++) {
        l[i] = arr[low + i];
    }
    for (j = 0; j < n2; j++) {
        r[j] = arr[mid + 1 + j];
    }
    l[n1] = INFINITY;
    r[n2] = INFINITY;
    i = 0;
    j = 0;

    for (k = low; k <= high; k++) {
        if (l[i] <= r[j]) {
            arr[k] = l[i];
            i++;
        } else {
            arr[k] = r[j];
            j++;
        }
    }
}

void merge_sort(int arr[], int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}

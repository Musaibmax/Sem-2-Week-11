#include <stdio.h>
#include <stdlib.h>

void countingSort(int arr[], int n, int max) {
    int count[max + 1];
    int output[n];

    for (int i = 0; i <= max; i++) count[i] = 0;

    for (int i = 0; i < n; i++) count[arr[i]]++;

    for (int i = 1; i <= max; i++) count[i] += count[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) arr[i] = output[i];
}

void merge(int arr[], int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++) L[i] = arr[l + i];
    for (int j = 0; j < n2; j++) R[j] = arr[m + 1 + j];

    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else arr[k++] = R[j++];
    }
    while (i < n1) arr[k++] = L[i++];
    while (j < n2) arr[k++] = R[j++];
}

void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        int m = (l + r) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

void heapify(int arr[], int n, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest]) largest = left;
    if (right < n && arr[right] > arr[largest]) largest = right;

    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(int arr[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) heapify(arr, n, i);
    for (int i = n - 1; i > 0; i--) {
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

int main() {
    int choice, n, max;
    while (1) {
        printf("\n--- Sorting Menu ---\n");
        printf("1. Counting Sort\n");
        printf("2. Merge Sort\n");
        printf("3. Heap Sort\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 4) break;

        printf("Enter number of elements: ");
        scanf("%d", &n);
        int arr[n];
        printf("Enter %d integers:\n", n);
        for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

        switch (choice) {
            case 1:
                max = arr[0];
                for (int i = 1; i < n; i++) if (arr[i] > max) max = arr[i];
                countingSort(arr, n, max);
                printf("Sorted array (Counting Sort): ");
                break;
            case 2:
                mergeSort(arr, 0, n - 1);
                printf("Sorted array (Merge Sort): ");
                break;
            case 3:
                heapSort(arr, n);
                printf("Sorted array (Heap Sort): ");
                break;
            default:
                printf("Invalid choice!\n");
                continue;
        }
        printArray(arr, n);
    }
    return 0;
}

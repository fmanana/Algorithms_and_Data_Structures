void countingSort(int arr[], int n, int exp) {
    int output[n];
    int C[10] = { 0 };

    for (int i = 0; i < n; i++)
        C[(arr[i] / exp) % 10]++;

    for (int i = 1; i < 10; i++)
        C[i] += C[i - 1];

    for (int i = n - 1; i >= 0; i--) {
        output[--C[(arr[i] / exp) % 10]] = arr[i];
        C[(arr[i] / exp) % 10]--;
    }

    for (int i = 0; i < n; i++)
        arr[i] = output[i];
}
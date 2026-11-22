//Вставкою______________________________
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
//Підрахунком__________________________
int sort(int arr[], int n, int k) {
    int st[256] = {0};
    for (int i = 0; i < n; i++) {
        st[arr[i]]++;
    }
    return st[k];
}

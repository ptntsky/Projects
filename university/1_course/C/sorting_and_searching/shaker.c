#include <stdio.h>
void shaker_sort(int a[], int n) {
    int l = 0, r = n - 1;
    while (l < r) {
    for (int i = l; i < r; i++) 
    if (a[i] > a[i + 1]) { int t = a[i]; a[i] = a[i + 1]; a[i + 1] = t; }
    r--;
    for (int i = r; i > l; i--) 
    if (a[i] < a[i - 1]) { int t = a[i]; a[i] = a[i - 1]; a[i - 1] = t; }
    l++;
    }
}
int main() {
int a[] = {45, 12, 89, 34, 67, 90, 23, 56, 78, 11};
int n = 10, k = 3, l = 7;
shaker_sort(a, n);
for (int i = k - 1; i < l; i++) printf("%d ", a[i]);
return 0;
}

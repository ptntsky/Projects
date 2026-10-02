#include <stdio.h>
#include <string.h>

typedef struct { char ukr[50], eng[50]; } Entry;

int b_search(Entry d[], int l, int h, const char* t) {
    if (l > h) return -1;
    int m = l + (h - l) / 2;//ф-ла на великих знач не провисає краще за (x+y)/2
    
    if (strcmp(d[m].ukr, t) == 0) {
        int left = b_search(d, l, m - 1, t);
        return (left != -1) ? left : m;
    }
    return strcmp(d[m].ukr, t) > 0 ? b_search(d, l, m - 1, t) : b_search(d, m + 1, h, t);
}
int main() {
    Entry dict[] = {
        {"замок", "castle"}, {"замок", "lock"}, {"зірка", "star"},
        {"ключ", "key"}, {"ключ", "wrench"}, {"ключ", "source"},
        {"мова", "language"}, {"ручка", "pen"}, {"ручка", "handle"}
    };
    int n =  9;

    for (int i = 0; i < n; ) {
        int first = b_search(dict, 0, n - 1, dict[i].ukr);
        int j = first;
        
        while (j < n && strcmp(dict[j].ukr, dict[first].ukr) == 0) j++;
        int count = j - first;

        if (count > 1) {
            printf("Слово: \"%s\" (%d переклади):\n", dict[first].ukr, count);
            for (int k = first; k < j; k++) printf("  - %s\n", dict[k].eng);
            printf("\n");
        }
        i = j;
    }
    return 0;
}

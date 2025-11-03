#include <stdio.h>

int main() {
    int arr[100], n, ch, pos, val, s, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) scanf("%d", &arr[i]);

    while (1) {
        printf("\n1.Insert  2.Delete  3.Search  4.Exit\nChoose: ");
        scanf("%d", &ch);

        if (ch == 1) { 
            printf("Position (1-%d): ", n + 1);
            scanf("%d", &pos);
            printf("Value: ");
            scanf("%d", &val);
            for (i = n; i >= pos; i--) arr[i] = arr[i - 1];
            arr[pos - 1] = val;
            n++;
            printf("Inserted. Array: ");
            for (i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        }

        else if (ch == 2) { 
            printf("Position (1-%d): ", n);
            scanf("%d", &pos);
            for (i = pos - 1; i < n - 1; i++) arr[i] = arr[i + 1];
            n--;
            printf("Deleted. Array: ");
            for (i = 0; i < n; i++) printf("%d ", arr[i]);
            printf("\n");
        }

        else if (ch == 3) { 
            printf("Enter value to search: ");
            scanf("%d", &s);
            for (i = 0; i < n; i++) if (arr[i] == s) break;
            if (i < n) printf("Found at position %d.\n", i + 1);
            else printf("Not found.\n");
        }

        else if (ch == 4) break; 
        else printf("Invalid choice!\n");
    }

    return 0;
}


#include<stdio.h>

int main() {
    int a[8] = {1, 2, 4, 6, 10, 12, 18, 20};
    int l = 0, r = 7;
    int data;
    int mid;
    printf("Enter data to be searched");
    scanf("%d",&data);
    while (l <= r) {
        mid = (l + r) / 2;
        if (data == a[mid]) {
            printf("Element %d found at index %d\n", data, mid);
            return 0;
        }
        else if (data < a[mid]) {
            r = mid - 1;
        }
        else {
            l = mid + 1;
        }
    }

    printf("Element %d not found in the array\n", data);
    return 0;
}

#include <stdio.h>

int main() {
    int a[10] = {0};  // Initialize the array with zeros
    int n, value;
    int temp = 1, hash;
    
    printf("Enter the value of n (table size): ");
    scanf("%d", &n);
    
    while (temp == 1) {
        printf("Enter the hash value: ");
        scanf("%d", &value);
        hash = value % n;
        
        if (a[hash] == 0) {
            a[hash] = value;
            printf("\n\ta[%d] the value %d is stored.", hash, value);
        } else {
            int originalHash = hash;
            hash++;
            
            while (hash != originalHash) {
                if (hash >= n) {
                    hash = 0;  // Wrap around the array
                }
                
                if (a[hash] == 0) {
                    a[hash] = value;
                    printf("\n\ta[%d] the value %d is stored.", hash, value);
                    goto menu;
                }
                
                hash++;
            }
            
            printf("No available space to store the value %d.", value);
        }
        
    menu:
        printf("\n\tEnter 1 to continue or 2 to exit: ");
        scanf("%d", &temp);
    }
    
    printf("Exiting...\n");
    return 0;
}

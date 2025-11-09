#include <stdio.h>
#include <time.h>

// Iterative Linear Search
void linearSearch(int arr[], int n, int x) {
    int flag;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            flag = 1;
            break;
        }
    }
    if (flag==1){
        printf("Element found\n");
    }
    else{
        printf("Not found\n");
    }
}

// Recursive Linear Search
void linearSearchR(int arr[], int n, int x, int i) {
    if (i >= n) {
        printf("Not found\n");
        return;
    }
    if (arr[i] == x) {
        printf("Element found\n");
        return;
    }
    linearSearchR(arr, n, x, i + 1);
}

// Iterative Binary Search
void binarySearch(int arr[], int n, int x) {
    int low = 0, high = n - 1, found = 0;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) {
            found = 1;
            break;
        } else if (arr[mid] < x) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    if (found)
        printf("Element found\n");
    else
        printf("Not found\n");
}

// Recursive Binary Search
void binarySearchR(int arr[], int low, int high, int x) {
    if (low > high) {
        printf( "Not found\n");
        return;
    }
    int mid = low + (high - low) / 2;
    if (arr[mid] == x) {
        printf("Element found\n");
        return;
    } else if (arr[mid] < x) {
        binarySearchR(arr, mid + 1, high, x);
    } else {
        binarySearchR(arr, low, mid - 1, x);
    }
}

int main() {
    int arr[10],n, x;
    clock_t start, end;
    double t1;
    printf("Enter number of elements: ");
    scanf("%d", &n);
    printf("Enter sorted array elements:\n");
    for (int i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Enter element to search: ");
    scanf("%d", &x);

    // Iterative Linear Search
    printf("Iterative linear search\n");
    start = clock();
    linearSearch(arr, n, x);
    end = clock();
    t1= (double)(end - start) / CLOCKS_PER_SEC;
    printf("%lf \n", t1);

    // Recursive Linear Search
    printf("Recursive Linear Search\n");
    start = clock();
    linearSearchR(arr, n, x, 0);
    end = clock();
    t1= (double)(end - start) / CLOCKS_PER_SEC;
    printf("%lf \n", t1);

    // Iterative Binary Search
    printf("Iterative Binary Search\n");
    start = clock();
    binarySearch(arr, n, x);
    end = clock();
    t1= (double)(end - start) / CLOCKS_PER_SEC;
    printf("%lf\n", t1);

    // Recursive Binary Search
    printf("Recursive Binary Search\n");
    start = clock();
    binarySearchR(arr, 0, n - 1, x);
    end = clock();
    t1= (double)(end - start) / CLOCKS_PER_SEC;
    printf("%lf \n", t1);

    return 0;
}
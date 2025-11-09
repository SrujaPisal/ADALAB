#include <stdio.h>

typedef struct {
    int weight;
    int profit;
} Item;

void sortByProfit(Item items[], int n) {
    // Sort items by profit in descending order
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].profit < items[j + 1].profit) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

double knapsack(Item items[], int n, int capacity) {
    double totalProfit = 0.0;
    int currentWeight = 0;

    for (int i = 0; i < n; i++) {
        if (currentWeight + items[i].weight <= capacity) {
            // Take whole item
            currentWeight += items[i].weight;
            totalProfit += items[i].profit;
            printf("Item %d included fully (Weight=%d, Profit=%d)\n", 
                    i + 1, items[i].weight, items[i].profit);
        } else {
            // Take fraction
            int remaining = capacity - currentWeight;
            if (remaining > 0) {
                double fraction = (double)remaining / items[i].weight;
                totalProfit += items[i].profit * fraction;
                currentWeight += remaining;
                printf("Item %d included %.2f fraction (Weight=%d, Profit=%d)\n", 
                        i + 1, fraction, items[i].weight, items[i].profit);
            }
            break; // sack full
        }
    }
 
    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);
    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);


    Item items[n];
    for (int i = 0; i < n; i++) {
        printf("Enter weight and profit of item %d: ", i + 1);
        scanf("%d %d", &items[i].weight, &items[i].profit);
    }

    // Sort by profit (not ratio!)
    sortByProfit(items, n);

    printf("\nSelected items:\n");
    double maxProfit = knapsack(items, n, capacity);

    printf("\nTotal Profit: %.2f\n", maxProfit);

    return 0;
}

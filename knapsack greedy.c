#include <stdio.h>

typedef struct {
    int weight;
    int profit;
    double ratio;
} Item;

void sortByRatio(Item items[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (items[j].ratio < items[j + 1].ratio) {
                Item temp = items[j];
                items[j] = items[j + 1];
                items[j + 1] = temp;
            }
        }
    }
}

double knapsack(Item items[], int n, int capacity) {
    int totalWeight = 0;
    double totalProfit = 0.0;

    printf("\nSelected items:\n");

    for (int i = 0; i < n; i++) {
        if (totalWeight + items[i].weight <= capacity) {
            totalWeight += items[i].weight;
            totalProfit += items[i].profit;

            printf("Item %d included fully (Weight = %d, Profit = %d)\n",
                   i + 1, items[i].weight, items[i].profit);
        }
        else {
            int remaining = capacity - totalWeight;
            double fraction = (double)remaining / items[i].weight;
            totalProfit += items[i].profit * fraction;
            totalWeight += remaining;

            printf("Item %d included partially (Fraction = %.2f, Weight = %d, Profit = %d)\n",
                   i + 1, fraction, items[i].weight, items[i].profit);
            break;
        }
    }

    return totalProfit;
}

int main() {
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    Item items[n];

    printf("Enter weight and profit of each item:\n");
    for (int i = 0; i < n; i++) {
        printf("Item %d weight: ", i + 1);
        scanf("%d", &items[i].weight);
        printf("Item %d profit: ", i + 1);
        scanf("%d", &items[i].profit);
        items[i].ratio = (double)items[i].profit / items[i].weight;
    }

    printf("Enter capacity of knapsack: ");
    scanf("%d", &capacity);

    sortByRatio(items, n);

    double maxProfit = knapsack(items, n, capacity);

    printf("\nMaximum Profit = %.2lf\n", maxProfit);

    return 0;
}

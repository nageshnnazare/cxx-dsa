#include <iostream>
#include <iomanip>
#include <algorithm>

typedef struct {
    int value;
    int weight;
} Item;

bool compare(Item a, Item b) {
    double r1 = static_cast<double> (a.value) / static_cast<double> (a.weight);
    double r2 = static_cast<double> (b.value) / static_cast<double> (b.weight);
    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n) {
    std::sort(arr, arr + n, compare);

    int currWt = 0;
    double finalVal = 0.0;

    for (int i = 0; i < n; i++) {

        if (currWt + arr[i].weight <= W) {
            currWt += arr[i].weight;
            finalVal += arr[i].value;
        }
        else {
            int remain = W - currWt;
            finalVal += (arr[i].value / static_cast<double> (arr[i].weight)) *
                static_cast<double> (remain);
            break;
        }
    }
    return finalVal;
}

int main(int argc, char const* argv[]) {
    int n = 3, weight = 50;
    Item arr[n] = { {100,20},{60,10},{120,30} };
    double ans = fractionalKnapsack(weight, arr, n);
    std::cout << "The maximum value is : "
        << std::setprecision(2) << std::fixed
        << ans << std::endl;

    return 0;
}

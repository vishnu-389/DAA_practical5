#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, W;

    cout << "Enter number of items: ";
    cin >> n;

    cout << "Enter capacity of knapsack: ";
    cin >> W;

    int weight[100], profit[100];

    cout << "Enter weights: ";
    for (int i = 0; i < n; i++) {
        cin >> weight[i];
    }

    cout << "Enter profits: ";
    for (int i = 0; i < n; i++) {
        cin >> profit[i];
    }

    int dp[101][101] = {0};

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= W; w++) {

            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i - 1][w],
                    profit[i - 1] + dp[i - 1][w - weight[i - 1]]
                );
            }
            else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum Profit = " << dp[n][W] << endl;

    return 0;
}

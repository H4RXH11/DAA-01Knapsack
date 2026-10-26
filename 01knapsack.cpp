
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, W;
    cin >> n >> W;

    vector<int> wt(n), val(n);

    for (int i = 0; i < n; i++)
        cin >> wt[i];

    for (int i = 0; i < n; i++)
        cin >> val[i];

    // dp[i][w] = maximum value using first i items
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            // Do not select item i-1
            dp[i][w] = dp[i - 1][w];

            // Select item i-1 if it fits
            if (wt[i - 1] <= w) {
                dp[i][w] = max(
                    dp[i][w],
                    val[i - 1] + dp[i - 1][w - wt[i - 1]]
                );
            }
        }
    }

    cout << "Maximum value: " << dp[n][W] << '\n';

    return 0;
}

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lcs(const string& X, const string& Y) {
    int m = X.length();
    int n = Y.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1));

    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= n; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (X[i - 1] == Y[j - 1]) {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            } else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[m][n];
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    cout << "Length of LCS is " << lcs(S1, S2) << endl;
    return 0;
}
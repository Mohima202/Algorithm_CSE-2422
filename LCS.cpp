#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    string X, Y;
    cout << "Enter the first string: ";
    getline(cin, X);

    cout << "Enter the second string: ";
    getline(cin, Y);

    int m = X.length();
    int n = Y.length();

    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (X[i - 1] == Y[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "\nLength of LCS: " << dp[m][n] << endl;

    string lcs = "";
    int i = m, j = n;

    while (i > 0 && j > 0) {
        if (X[i - 1] == Y[j - 1]) {
            lcs = X[i - 1] + lcs;
            i--;
            j--;
        } else if (dp[i - 1][j] > dp[i][j - 1])
            i--;
        else
            j--;
    }

    cout << "LCS: " << lcs << endl;

    return 0;
}

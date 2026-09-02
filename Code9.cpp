// WAP to perform longest common subsequence in DP . Print the output using D for diagonal,S for stable and U for upper.

#include<bits/stdc++.h>
using namespace std;

int main() {

    string s1 = "abcde";
    string s2 = "ace";

    int n = s1.length();
    int m = s2.length();

    // DP table
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Direction table
    // D = Diagonal
    // U = Upper
    // S = Stable (Left)
    vector<vector<char>> dir(n + 1, vector<char>(m + 1, '-'));

    // Step 1 :- Fill DP table
    for (int i = 1; i <= n; i++) {

        for (int j = 1; j <= m; j++) {

            // Characters are same
            if (s1[i - 1] == s2[j - 1]) {

                dp[i][j] = dp[i - 1][j - 1] + 1;
                dir[i][j] = 'D';
            }

            // Characters are different
            else {

                if (dp[i - 1][j] >= dp[i][j - 1]) {
                    dp[i][j] = dp[i - 1][j];
                    dir[i][j] = 'U';
                }
                else {
                    dp[i][j] = dp[i][j - 1];
                    dir[i][j] = 'S';
                }
            }
        }
    }

    // // Print DP values
    // cout << "DP Table:\n\n";

    // for (int i = 0; i <= n; i++) {

    //     for (int j = 0; j <= m; j++) {
    //         cout << dp[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // // Print Direction Table
    // cout << "\nDirection Table:\n\n";

    // for (int i = 0; i <= n; i++) {

    //     for (int j = 0; j <= m; j++) {
    //         cout << dir[i][j] << " ";
    //     }

    //     cout << endl;
    // }

    // cout << "\nLength of LCS = " << dp[n][m] << endl;

    // Step 2 :- Find and Print LCS using direction table
    string lcs = "";

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {

        if (dir[i][j] == 'D') {
            // Character is part of LCS
            lcs += s1[i - 1];

            i--;
            j--;
        }
        else if (dir[i][j] == 'U') {
            // Move upward
            i--;
        }
        else {
            // Move left
            j--;
        }
    }

    // We found LCS backwards, so reverse it
    reverse(lcs.begin(), lcs.end());

    cout << "Longest Common Subsequence = " << lcs << endl;
    cout << "Length = " << lcs.length() << endl;

    return 0;
}
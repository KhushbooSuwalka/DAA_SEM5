//You are given an integer array of length n where highest matrix as dimension arr[i-1]*arr[i] . 
//Implement a function using dynamic programming to compute the minimum number of scalar multiplications required to multiply the entire chain of matrices.

#include <bits/stdc++.h>
using namespace std;

// Function to print optimal parenthesization
void printOptimalPar(int s[][100], int i, int j)
{
    // If there is only one matrix
    if (i == j)
    {
        cout << "A" << i;
        return;
    }

    cout << "(";

    // Print left part
    printOptimalPar(s, i, s[i][j]);

    // Print right part
    printOptimalPar(s, s[i][j] + 1, j);

    cout << ")";
}

int main()
{
    int p[100];
    int m[100][100];
    int s[100][100];

    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    cout << "Enter dimensions of matrices:\n";
    cout << "For n matrices, enter " << n + 1 << " dimensions:\n";

    for (int i = 0; i <= n; i++)
    {
        cin >> p[i];
    }

    // Step 1:
    // For a single matrix, multiplication cost is 0
    for (int i = 1; i <= n; i++)
    {
        m[i][i] = 0;
    }

    // Step 2:
    // Chain length l = 2 to n
    for (int l = 2; l <= n; l++) {                               // Matrix chain ki length kitni hai ??
        
        // Set i = 1 to n-l+1
        for (int i = 1; i <= n - l + 1; i++) {                   // Chain kaha se start ho rahi hai ??
            int j = i + l - 1;                                   // Set j that chain kaha tak jaegii ?? 

            // Initially set m[i][j] = infinity
            m[i][j] = INT_MAX;

            // Try every possible split k
            for (int k = i; k <= j - 1; k++) {                  // Chain ko kaha split karna hai ??
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                // If q is smaller, update
                if (q < m[i][j])
                {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    // Step 3:
    // Minimum scalar multiplications
    cout << "\nMinimum number of scalar multiplications = "
         << m[1][n] << endl;

    // Step 4:
    // Print optimal sequence
    cout << "Optimal Parenthesization = ";
    printOptimalPar(s, 1, n);
    cout << endl;

    return 0;
}                                                    
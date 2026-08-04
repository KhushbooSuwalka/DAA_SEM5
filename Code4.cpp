//WAP to implement fractional knapsack problem using greedy method.
#include<bits/stdc++.h>
using namespace std;

int KnapsackProblem(vector<int> wt, vector<int> val, int W, int n) {
    vector<pair<double, int>> ratio(n);
    for (int i = 0; i < n; i++) {
        ratio[i] = { (double)val[i] / wt[i], i };
    }
    sort(ratio.rbegin(), ratio.rend()); 

    int profit = 0;
    for (int i = 0; i < n; i++) {
        if (W == 0) break;
        int idx = ratio[i].second;
        if (wt[idx] <= W) {
            profit += val[idx];
            W -= wt[idx];
        } else {
            profit += ratio[i].first * W;
            W = 0;
        }
    }
    return profit;
}

int main() {
    int n, W;
    cout << "Enter the number of items: ";
    cin >> n;
    vector<int> wt(n), val(n);
    cout << "Enter the weights of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> wt[i];
    }
    cout << "Enter the values or prices of the items: ";
    for (int i = 0; i < n; i++) {
        cin >> val[i];
    }
    cout << "Enter the maximum weight capacity of the knapsack: ";
    cin >> W;

    int maxProfit = KnapsackProblem(wt, val, W, n);
    cout << "Maximum profit in Knapsack = " << maxProfit << endl;

    return 0;
}
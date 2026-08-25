//WAP to find minimum cost spanning tree by using Kruskal Algorithm.

#include <iostream>
using namespace std;

int main()
{
    int n, e;

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> e;

    int u[20], v[20], w[20];

    cout << "Enter edges (u v weight):\n";

    for (int i = 0; i < e; i++)
    {
        cin >> u[i] >> v[i] >> w[i];
    }

    // Sort according to weight
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - i - 1; j++)
        {
            if (w[j] > w[j + 1])
            {
                swap(w[j], w[j + 1]);
                swap(u[j], u[j + 1]);
                swap(v[j], v[j + 1]);
            }
        }
    }

    int parent[10];

    for (int i = 0; i < n; i++)
        parent[i] = i;

    int total = 0;
    int count = 0;

    cout << "\nMinimum Spanning Tree:\n";

    for (int i = 0; i < e; i++)
    {
        int a = u[i];
        int b = v[i];

        while (parent[a] != a)
            a = parent[a];

        while (parent[b] != b)
            b = parent[b];

        if (a != b)
        {
            cout << u[i] << " - " << v[i]<< " = " << w[i] << endl;
            total += w[i];
            parent[a] = b;
            count++;
            
            if (count == n - 1)
                break;
        }
    }

    cout << "Minimum Cost = " << total << endl;

    return 0;
}
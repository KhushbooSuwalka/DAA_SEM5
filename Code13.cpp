//Implement All-Pairs Shortest Paths Problem using Floyd's algorithm.

// Algorithm:-
// 1. Input the number of vertices and the cost adjacency matrix.
// 2. Consider each vertex k as an intermediate vertex.
// 3. Update the distance using:
//    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j])
// 4. Repeat for all vertices.
// 5. Display the final shortest distance matrix.

#include <iostream>
using namespace std;

#define INF 99999

int main() {
    int n;
    cout << "Enter number of vertices: ";
    cin >> n;

    int dist[100][100];

    cout << "Enter adjacency matrix (use 99999 for INF):\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> dist[i][j];
        }
    }

    // Floyd's Algorithm
    // k decide karta hai ki abhi kaunsa vertex beech mein use karna hai. i starting vertex hai aur j destination vertex hai.
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    if (dist[i][k] + dist[k][j] < dist[i][j]) {
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                }
            }
        }
    }

    cout << "\nAll-Pairs Shortest Distance Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

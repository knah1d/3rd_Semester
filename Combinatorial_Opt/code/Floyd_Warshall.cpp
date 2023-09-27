#include <iostream>
#include <string>
#include <climits>

using namespace std;

const int INF = INT_MAX;

int main() {
    // Define the number of vertices
    int N =5;  // Replace with the actual number of vertices

    // Initialize the adjacency matrix with given distances
    int distances[N][N];
    string vertices[] = {"Dhaka", "Gazipur", "Tangail", "Narayanganj", "Cumilla"};

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == j) {
                distances[i][j] = 0;
            } else {
                distances[i][j] = INF;
            }
        }
    }

    int edge_weights[][3] = {
        {0, 1, 3},
        {0, 2, 8},
        {1, 3, 1},
        {1, 4, 7},
        {0, 4, -4},
        {2, 1, 4},
        {3, 0, 2},
        {3, 2, -5},
        {4, 3, 6}
    };

    for (int i = 0; i < 9; i++) {
        int source = edge_weights[i][0];
        int destination = edge_weights[i][1];
        int weight = edge_weights[i][2];
        distances[source][destination] = weight;
    }

    // Floyd-Warshall algorithm
    for (int k = 0; k < N; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (distances[i][k] != INF && distances[k][j] != INF &&
                    distances[i][k] + distances[k][j] < distances[i][j]) {
                    distances[i][j] = distances[i][k] + distances[k][j];
                }
            }
        }
    }

    // Display the shortest distances
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << "Shortest distance from " << vertices[i] << " to " << vertices[j] << ": " << distances[i][j] << endl;
        }
    }

    return 0;
}

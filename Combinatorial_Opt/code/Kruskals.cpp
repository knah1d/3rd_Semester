#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define a structure to represent an edge
struct Edge {
    char source, destination;
    int weight;

    Edge(char src, char dest, int w) : source(src), destination(dest), weight(w) {}
};

// Define a disjoint-set data structure
class DisjointSet {
public:
    vector<int> parent, rank;

    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i)
            parent[i] = i;
    }

    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }

    void unionSets(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX != rootY) {
            if (rank[rootX] < rank[rootY])
                swap(rootX, rootY);
            parent[rootY] = rootX;
            if (rank[rootX] == rank[rootY])
                rank[rootX]++;
        }
    }
};

// Comparator function to sort edges by weight
bool compareEdges(const Edge& a, const Edge& b) {
    return a.weight < b.weight;
}

// Kruskal's algorithm to find the MST and print the path
void kruskalMST(vector<Edge>& edges) {
    sort(edges.begin(), edges.end(), compareEdges);

    int numVertices = edges.size();
    DisjointSet ds(numVertices);

    vector<Edge> mst;

    for (int i = 0; i < numVertices; ++i) {
        char source = edges[i].source;
        char destination = edges[i].destination;

        int sourceSet = ds.find(source - 'a');
        int destSet = ds.find(destination - 'a');

        if (sourceSet != destSet) {
            mst.push_back(edges[i]);
            ds.unionSets(sourceSet, destSet);
        }
    }

    cout << "Minimum Spanning Tree (MST) Edges:" << endl;
    int totalWeight = 0;
    for (const Edge& edge : mst) {
        cout << edge.source << " - " << edge.destination << " : " << edge.weight << endl;
        totalWeight += edge.weight;
    }
    cout << "Total Weight of MST: " << totalWeight << endl;
}

int main() {
    vector<Edge> edges = {
        {'a', 'b', 4},
        {'b', 'c', 8},
        {'c', 'd', 7},
        {'d', 'e', 9},
        {'e', 'f', 10},
        {'f', 'g', 2},
        {'a', 'h', 8},
        {'b', 'h', 11},
        {'c', 'f', 4},
        {'c', 'i', 2},
        {'d', 'f', 14},
        {'g', 'h', 1},
        {'g', 'i', 6},
        {'h', 'i', 7}
    };

    kruskalMST(edges);

    return 0;
}

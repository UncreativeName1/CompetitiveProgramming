#include <iostream>
#include <vector>
#include <array>
#define ll long long
#define ARR_LENGTH(array) sizeof(array)/sizeof(*array)
#define SET_ARR(array, value) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) array[INDEX] = value;
#define PRINT_ARR(array) for (unsigned int INDEX = 0; INDEX < ARR_LENGTH(array); INDEX++) { cout << array[INDEX] << " "; } cout << endl;
#define PRINT_VEC(vector) for (unsigned int INDEX = 0; INDEX < vector.size(); INDEX++) { cout << vector[INDEX] << " "; } cout << endl;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	// Create a direct neighbor adjacency matrix and use Floyd warshall but add distances when a distance is connected by multiple edges.
    int vertices, edges, pairsOfVertices;
    int vertex1, vertex2;
    cin >> vertices >> edges >> pairsOfVertices;
    int adj[vertices][vertices];
    for (int i = 0; i < vertices; i++) {
        SET_ARR(adj[i], 0);
    }
    for (int i = 0; i < edges; i++) {
        cin >> vertex1 >> vertex2;
        adj[vertex1 - 1][vertex2 - 1] = 1;
        adj[vertex2 - 1][vertex1 - 1] = 1;

    }

    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            // If two nodes are adjacent, check for the adjacency of the y-coordinate to other points, and the connections of the x-coordinate with these are at most one more length.
            if (adj[j][i] > 0) {
                for (int k = 0; k < vertices; k++) {
                    // If the new connection is shorter than the orginal stored connection length.
                    if (adj[i][k]) {
                        if ((adj[j][k] == 0) || (adj[j][k] > adj[i][j] + 1)) {
                            adj[j][k] = adj[i][j] + 1;
                        }
                    }
                }
            }
        }
    }
    for (int i = 0; i < pairsOfVertices; i++) {
        cin >> vertex1 >> vertex2;
        cout << adj[vertex1 - 1][vertex2 - 1] << endl;
    }
	return 0;
}

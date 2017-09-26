#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

class Graph {
    int weight = 6;
    int n;
    vector<int> * nodes;

    public:
        Graph(int n) {
            this -> n = n;
            nodes = new vector<int>[n];
        }

        void add_edge(int u, int v) {
            nodes[u].push_back(v);
            nodes[v].push_back(u);
        }

        vector<int> shortest_reach(int start) {
            vector<int> distances(n, -1);
            queue<int> queue;

            queue.push(start);
            distances[start] = 0;
            int currentNode;
            while(!queue.empty()){
                currentNode = queue.front();
                queue.pop();

                for(int i : nodes[currentNode]){
                    if(distances[i] == -1){
                        queue.push(i);
                        distances[i] = distances[currentNode] + weight;
                    }
                }
            }

            return distances;
        }

};

int main() {
    int queries;
    cin >> queries;

    for (int t = 0; t < queries; t++) {

      int n, m;
        cin >> n;
        // Create a graph of size n where each edge weight is 6:
        cin >> m;
        Graph graph(n);

        // read and set edges
        for (int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--, v--;
            // add each edge to the graph
            graph.add_edge(u, v);
        }
      int startId;
        cin >> startId;
        startId--;
        // Find shortest reach from node s
        vector<int> distances = graph.shortest_reach(startId);

        for (int i = 0; i < distances.size(); i++) {
            if (i != startId) {
                cout << distances[i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}

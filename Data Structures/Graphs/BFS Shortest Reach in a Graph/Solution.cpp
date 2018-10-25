//// BFS.cpp : This file contains the 'main' function. Program execution begins and ends there.
////


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <unordered_set>
using namespace std;

class Graph {
private:
     std::vector<int>* adj;
     int N;
public:
     Graph(int n) {
          adj = new std::vector<int>[n];
          N = n;
     }

     ~Graph()
     {
          delete[] adj;
     }

     void add_edge(int u, int v) {
          adj[u].push_back(v);
          adj[v].push_back(u);
     }

     vector<int> shortest_reach(int start) {

          vector<int> distances(N, -1);
          queue<int> q;
          bool* visited = new bool[N]{};
         unordered_set<int> seen;
         
          q.push(start);
         
          visited[start] = true;
         seen.insert(start);
          distances[start] = 0;
         
          while (!q.empty())
          {
               int node = q.front();

               q.pop();

               for (int i = 0; i < adj[node].size(); ++i)
               {
                    int index = adj[node][i];
                    if (!visited[index])//(seen.find(index) == seen.end())
                    {
                         q.push(index);
                         distances[index] = distances[node] + 6;
                         visited[index] = true;
                        //seen.insert(index);
                    }

               }
          }
         
          delete[] visited;
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
          Graph graph(n);
          cin >> m;
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
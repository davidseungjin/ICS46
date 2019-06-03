// C program for Dijkstra's single
// source shortest path algorithm.
// The program is for adjacency matrix
// representation of the graph.
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <vector>
#define INF 77777


using namespace std;

class Graph{
public:
    int src, dst, wgt;
    int V, E;
    vector<vector<int> > graph;
    
public:
    Graph(string filename){
        ifstream in(filename);
        in >> V;

        graph.assign(V, vector<int>(V,INF));
        for(;;){
            if(in>>src>>dst>>wgt){
                graph[src][dst] = wgt;
                E++;
            }else{
                break;
            }
        }
        in.close();
         
        dijkstra(graph, 2);
    }

    void printPath(int parent[], int j){
        if (parent[j] == - 1){
            cout << j ;
            return;
        }
        printPath(parent, parent[j]);
        cout << "-" << j;
    }

    void printSolution(int dist[], int n, int parent[]){
        int src = 0;
        for (int i = 0; i < V; i++){
            cout << i << "\t"<< "\t";
            cout << "[" ; //<< src;
            printPath(parent, i);
            cout << "]" << " (" << dist[i] << ")" << endl;
        }
    }

    
    // A utility function to find the
    // vertex with minimum distance
    // value, from the set of vertices
    // not yet included in shortest
    // path tree
    /*
    int* arr;
    void minheapify(int high, int low)
    {
        
        int smallest;
        int largest = i; // Initialize largest as root
        int l = 2 * i + 1; // left = 2*i + 1
        int r = 2 * i + 2; // right = 2*i + 2
        
        if (l < high && arr[l] > arr[largest])
            largest = l;
        
        if (r < high && arr[r] > arr[largest])
            largest = r;
        
        if (largest != i) {
            swap(arr[i], arr[largest]);
            
            heapify(high, largest);
        }
    }
    
    void sort(int low, int high){
        for (int i = (high / 2) - 1; i >= 0; i--)
            heapify(high, i);
        
        for (int i = high - 1; i >= 0; i--){
            swap(arr[0], arr[i]);
            
            heapify(i, 0);
        }
    }
    */
    
    int minVindex(int dist[], bool sptSet[]){
        int min = INF;
        int min_index;
        
        for (int v = 0; v < V; v++){
            if (sptSet[v] == false && dist[v] < min){
                min = dist[v], min_index = v;
            }
        }
        return min_index;
    }

    void dijkstra(vector<vector<int> > graph, int src){
        int dist[V];
        bool sptSet[V];
        int parent[V];

        for (int i = 0; i < V; i++){
            parent[src] = -1;
            dist[i] = INF;
            sptSet[i] = false;
        }

        dist[src] = 0;
       
// Find shortest path for all vertices
        for (int i = 0; i < V - 1; i++){
// Pick the minimum distance vertex from the set of
// vertices not yet processed. u is always equal to src in first iteration.
            int u = minVindex(dist, sptSet);
            // if I use priority queue, u should be Q.extract_min().
            sptSet[u] = true;
            
            for (int v = 0; v < V; v++)
                
                if (!sptSet[v] && graph[u][v] &&
                    dist[u] + graph[u][v] < dist[v])
                {
                    parent[v] = u;
                    dist[v] = dist[u] + graph[u][v];
                    // Q.decrease_priority(v, alt)
                }
        }
        printSolution(dist, V, parent);
    }
};

// Driver Code
int main(int argc, char* argv[]){
//    const char* input_file = argc == 2 ? argv[1]: "largegraph.txt";
    argc = 3;
    
    
    Graph a(argv[2]);
    
    cout << "argv[1] is " << argv[1] << endl;
    int num = argv[1] + 1;
    cout << "num is " << num;
    
    return 0;
}

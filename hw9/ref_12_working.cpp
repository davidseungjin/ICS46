#include <iostream>
#include <fstream>
using namespace std;

// Data structure to store Adjacency list nodes
struct Node {
    int val, cost;
    Node* next;
};

// Data structure to store graph edges
struct Edge {
    int src, dest, weight;
};

class Graph
{
    // Function to allocate new node of Adjacency List
    Node* getAdjListNode(int value, int weight, Node* head)
    {
        Node* newNode = new Node;
        newNode->val = value;
        newNode->cost = weight;
        
        // point new node to current head
        newNode->next = head;
        
        return newNode;
    }
    
    int N;  // number of nodes in the graph
    int numverofvertex;
    int numberofedge;
    
public:
    
    // An array of pointers to Node to represent
    // adjacency list
    Node **head;
    
    // Constructor
    Graph(string filename)      //Edge edges[], int n, int N)
    {
        Edge edges[];
        int value;
        int count;
        ifstream in(filename);  //cout << "    test    " << endl;
        in >> value;    //cout << "2    test    " << endl;
        for(int i=0;;i++){
            if(in>>edges[i].src>>edges[i].dest>>edges[i].weight){
                count++;
            }else{
                break;
            }
        }
        numverofvertex = value;   //cout << "3    test    " << endl;
        numberofedge = count;
        //        cout << "8    test    " << endl;
        in.close();
        
        cout << "vertices are " << numverofvertex << endl;
        cout << "edges  are " << numberofedge << endl;
        
        
        // allocate memory
        head = new Node*[numverofvertex]();
        this->numverofvertex = numverofvertex;
        
        // initialize head pointer for all vertices
        for (int i = 0; i < numverofvertex; ++i)
            head[i] = nullptr;
        
        // add edges to the directed graph
        for (unsigned i = 0; i < numberofedge; i++)
        {
            int src = edges[i].src;
            int dest = edges[i].dest;
            int weight = edges[i].weight;
            
            // insert in the beginning
            Node* newNode = getAdjListNode(dest, weight, head[src]);
            
            // point head pointer to new node
            head[src] = newNode;
            
            // Uncomment below lines for undirected graph
            
            /*
             newNode = getAdjListNode(src, weight, head[dest]);
             
             // change head pointer to point to the new node
             head[dest] = newNode;
             */
        }
    }
    
    // Destructor
    ~Graph() {
        for (int i = 0; i < N; i++)
            delete[] head[i];
        
        delete[] head;
    }
};

// print all neighboring vertices of given vertex
void printList(Node* ptr, int i)
{
    while (ptr != nullptr)
    {
        cout << "(" << i << ", " << ptr->val
        << ", " << ptr->cost << ") ";
        
        ptr = ptr->next;
    }
    
    cout << endl;
}

// Graph Implementation in C++ without using STL
int main()
{
    // array of graph edges as per above diagram.
    int main(int argc, char* argv[]){
        const char* input_file = argc == 2 ? argv[1]: "largegraph.txt";
        
        
        Graph a(input_file);

//        Edge edges[] =
//    {
//        // (x, y, w) -> edge from x to y having weight w
//        { 0, 1, 6 }, { 1, 2, 7 }, { 2, 0, 5 }, { 2, 1, 4 },
//        { 3, 2, 10 }, { 4, 5, 1 }, { 5, 4, 3 }
//    };
//
//    // Number of vertices in the graph
//    int N = 6;
//
//    // calculate number of edges
//    int n = sizeof(edges)/sizeof(edges[0]);
//
    // construct graph
//    Graph graph(edges, n, N);
//
    // print adjacency list representation of graph
    for (int i = 0; i < N; i++)
    {
        // print all neighboring vertices of vertex i
        printList(graph.head[i], i);
    }
    
    return 0;
}

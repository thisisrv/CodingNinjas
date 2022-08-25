#include <iostream>
#include <algorithm>
using namespace std;

class Edge{
    
    public:
    int source;
    int destination;
    int weight;
};

bool compare(Edge const & a, Edge const & b){
    
    return a.weight < b.weight;
}

int topmostParent(int *parent, int v){
    
    if(parent[v] == v)
        return v;
    
    //rec call
    return topmostParent(parent, parent[v]);
}


void KruskalAlgo(Edge *input, int n, int e, Edge *output){
    //sort input array on basis of weight;
    sort(input, input + e, compare);
    
    //make parent array
    int *parent = new int[n];
    //fill parent array
    for(int i = 0; i < n; i++)
        parent[i] = i;
    
    //Loop
    int count = 0;
    int i = 0;
    
    while(count != n - 1){
        
        int v1 = input[i].source;
        int v2 = input[i].destination;
        
        int p1 = topmostParent(parent, v1);
        int p2 = topmostParent(parent, v2);
        
        
        if(p1 != p2){
            
            //add edge in output.
            output[count] = input[i];
            count++;
            //update parent
            parent[p2] = p1;
        }
        
        i++;
    }
    
    delete [] parent;
}

int main() {
    // Write your code here
    int n, e;
    cin >> n >> e;
    
    //Take input of edges
    Edge *input = new Edge[e];
    
    for(int i = 0; i < e; i++){
        int s, d, w;
        cin >> s >> d >> w;
        
       	input[i].source = s;
       	input[i].destination = d;   
        input[i].weight = w;
    }
    
    //create output array for MST graph
    Edge *output = new Edge[n - 1];
    
    
    KruskalAlgo(input, n, e, output);
    
    //Print output array
    for(int i = 0; i < n - 1; i++){
        
        if(output[i].source < output[i].destination)
            cout << output[i].source << " " << output[i].destination << " " << output[i].weight << endl;
        
        else
            cout << output[i].destination << " " << output[i].source << " " << output[i].weight << endl;
    }
        
    
    delete[] input;
    delete[] output;
}
#include<iostream>
#include<climits>
using namespace std;

int findminVertex(bool* visited, int *weights, int n){

    int minVertex = -1;

    for(int i = 0; i < n; i++){
        
        //check if vertex is unvisited
        if(visited[i] == false){

            if(minVertex == -1 || weights[i] < weights[minVertex])
                minVertex = i;
        }
    }

    return minVertex;
}

void prims(int **edges, int n){

    //create visited array, weights array and parent array
    bool *visited = new bool[n];
    int *weights = new int[n];
    int *parents = new int[n];

    //initialise visited as false and weights as INT_MAX;
    for(int i = 0; i < n; i++){
        visited[i] = false;
        weights[i] = INT_MAX;
    }

    //mark 0 as source and update parent and weight
    parents[0] = -1;
    weights[0] = 0;

    //Loop through unvisited min vertex
    for(int i = 0; i < n; i++){
        //calculate minVertex
        int minVertex = findminVertex(visited, weights, n);

        //mark minvertex as visited
        visited[minVertex] = true;

        //traverse neighbors of minVertex
        for(int j = 0; j < n; j++){

            if(edges[minVertex][j] != 0 && visited[j] == false){

                if(edges[minVertex][j] < weights[j]){
                    //update weight and parent
                    weights[j] = edges[minVertex][j];
                    parents[j] = minVertex;
                }
            }
        }
    }

    //print output MST
    for(int i = 1; i < n ; i++){

        if(parents[i] < i)
            cout << parents[i] << " " << i << " " << weights[i] << endl;
        else
            cout << i << " " << parents[i] << " " << weights[i] << endl;

    }

}


int main(){

    int n, e;
    cin >> n >> e;

    //create edge array
    int **edges = new int*[n];

    //initialise as 0
    for(int i = 0; i < n; i++){

        edges[i] = new int[n];
        for(int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    //add weights to edges
    for(int i = 0; i < e; i++){
        int f,s,w;
        cin >> f >> s >> w;

        edges[f][s] = w;
        edges[s][f] = w;
    }

    //call prims fn
    prims(edges, n);

    //delete array
    delete[] edges;
}
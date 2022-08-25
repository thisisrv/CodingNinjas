#include<iostream>
#include<climits>
using namespace std;

int findminVertex(bool* visited, int *distances, int n){

    int minVertex = -1;

    for(int i = 0; i < n; i++){
        
        //check if vertex is unvisited
        if(visited[i] == false){

            if(minVertex == -1 || distances[i] < distances[minVertex])
                minVertex = i;
        }
    }

    return minVertex;
}

void dijkstra(int **edges, int n){

    //create visited array, distance array
    bool *visited = new bool[n];
    int *distances = new int[n];
    // int *parents = new int[n];

    //initialise visited as false and distances as INT_MAX;
    for(int i = 0; i < n; i++){
        visited[i] = false;
        distances[i] = INT_MAX;
    }

    //mark 0 as source and distance from 0 to 0 as 0.
    distances[0] = 0;

    //Loop through unvisited min vertex
    for(int i = 0; i < n; i++){
        //calculate minVertex
        int minVertex = findminVertex(visited, distances, n);

        //mark minvertex as visited
        visited[minVertex] = true;

        //traverse neighbors of minVertex
        for(int j = 0; j < n; j++){

            if(edges[minVertex][j] != 0 && visited[j] == false){
                
                //calculate distance of reaching from source i.e 0 till j
                int dist = distances[minVertex] + edges[minVertex][j];

                //check if new distance is better than present distance of j
                if(dist < distances[j]){

                    //update distances
                    distances[j] = dist;
                }
            }
        }
    }

    //print distances array
    for(int i = 0; i < n ; i++){

        cout << i << " " << distances[i] << endl;
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
    dijkstra(edges, n);

    //delete array
    delete[] edges;
}
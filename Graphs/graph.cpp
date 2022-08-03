#include<iostream>
#include<queue>
using namespace std;

void printLoop(int **edges, int n){

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++)
            cout << edges[i][j] << " ";
        cout << endl;
    }
}

void printDFS(int **edges, int n, int startingvertex, bool *isVisited){

    //small calc
    cout << startingvertex << endl;

    //mark as visited
    isVisited[startingvertex] = true;

    //rec call
    for(int i = 0; i < n; i++){
        if(i == startingvertex)
            continue;

        if(edges[startingvertex][i] == true){
            
            if(isVisited[i] == true)
                continue;
            if(isVisited[i] == false)
                printDFS(edges, n, i, isVisited);
        }
    }
}

void printBFS(int **edges, int n, int startingIndex, bool* isVisited){

    //Make queue
    queue<int> pendingNodes;

    //push starting vertex
    pendingNodes.push(startingIndex);

    //update isvisited
    isVisited[startingIndex] = true;

    //loop
    while(pendingNodes.size() != 0){

        //front and pop
        int front = pendingNodes.front();

        pendingNodes.pop();

        cout << front << " ";

        //add adjacent vertex to queue
        for(int i = 0; i < n; i++){

            if(i == front)
                continue;
            
            if(edges[front][i] == 1){
                //There is an edge
                //check if already traversed
                if(isVisited[i] == true)
                    continue;
                
                if(isVisited[i] == false){

                    //add vertex in queue
                    pendingNodes.push(i);

                    //mark as visited
                    isVisited[i] = true;
                }
            }
        }
    }
}
bool alltrue(bool* isvisited, int n){
    
    for(int i = 0; i < n; i++)
        if (isvisited[i] == false)
            return false;
            
    return true;
}

void BFS(int **edges, int n){
    
    //make visited array
    bool* isVisited = new bool[n];

    for(int i = 0; i < n; i++)
        isVisited[i] = false;
    
    //Loop
    int i = 0;
    while(alltrue(isVisited, n) != true){
        
        if(i == n)
            i = 0;
        
        if(isVisited[i] == false)
            printBFS(edges,n, i, isVisited);
        
        i++;
    }

    delete[] isVisited;
}
void DFS(int **edges, int n){
    
    //make visited array
    bool* isVisited = new bool[n];

    for(int i = 0; i < n; i++)
        isVisited[i] = false;
    
    //Loop
    int i = 0;
    while(alltrue(isVisited, n) != true){
        
        if(i == n)
            i = 0;
        
        if(isVisited[i] == false)
            printDFS(edges,n, i, isVisited);
        
        i++;
    }

    delete [] isVisited;
}

void displayGraphMatrix(int **edges, int n){

    for(int i = 0; i < n; i++){

        for(int j = 0 ; j < n ; j++)
            cout << edges[i][j] << " ";
        
        cout << endl;
    }
}
int main(){

    //Get input of edges and vertices
    int n, e;
    cin >> n >> e;

    //Edges array 2d
    int** edges = new int*[n];

    //Loop to add array and initialise every value to 0.
    for(int i = 0; i < n ; i++){
        edges[i] = new int[n];

        for(int j = 0; j < n; j++)
            edges[i][j] = 0;
    }

    //Set edges using vertex as input
    for(int i = 0; i < e; i++){
        int f,s;
        cin >> f >> s;

        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    // displayGraphMatrix(edges, n);
    // // printLoop(edges, n);
    // printRecursive(edges, n, 0, isVisited);

    // BFS(edges, n);
    DFS(edges, n);

    // cout << endl;

    // for(int i = 0; i < n; i++)
    //     cout << isVisited[i] << " ";

    for(int i = 0; i < n; i++)
        delete [] edges[i];

    delete [] edges;
}
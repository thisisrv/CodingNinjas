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

bool hasPathDFS(int **edges, int n, int sv, int ev, bool* isVisited){
    //small calc
    //mark vertex as visited
    isVisited[sv] = true;

    //Loop
    for(int i = 0; i < n; i++){

        if(i == sv)
            continue;

        if(edges[sv][i] == 1 && isVisited[i] == false){
            //check adjacent
            if(i == ev)
                return true;

            //call on i as sv
            return hasPathDFS(edges, n, i, ev, isVisited);
        }
    }

    return false;
}

bool hasPathBFS(int **edges, int n, int sv, int ev, bool* isVisited){


    //queue
    queue<int> pendingnodes;
    pendingnodes.push(sv);
    isVisited[sv] = true;

    while(pendingnodes.size() != 0){

        //front and pop
        int front = pendingnodes.front();

        pendingnodes.pop();

        for(int i = 0; i < n; i++){

            if(i == front)
                continue;

            if(edges[front][i] == 1 && isVisited[i] == false){

                if(i == ev)
                  return true;
                
                //push elements into queue
                pendingnodes.push(i);
                isVisited[i] = true;
            }
        }
    }
        return false;
}
bool hasPath(int **edges, int n, int v1, int v2){

    //small calc
    bool* isVisited = new bool[n];
    
    for(int i = 0; i < n; i++)
        isVisited[i] = false;
    
    //only connected dfs
    // return hasPathDFS(edges, n, v1, v2, isVisited);
    return hasPathBFS(edges, n, v1, v2, isVisited);
}

vector<int>* PathDFSHelper(int **edges, int n, int sv, int ev, bool* isvisited){

    //add element to vector v
    if(sv == ev){
        //make a vector and add sv to it
        vector<int>* v = new vector<int>();
        v -> push_back(sv);
        isvisited[sv] = true;
        return v;
    }

    isvisited[sv] = true;

    //rec call and small calc
    vector<int>* smallans = NULL;

    for(int i = 0; i < n; i++){
        if(i == sv)
            continue;

        if(edges[sv][i] == 1 && isvisited[i] == false){

            smallans = PathDFSHelper(edges, n, i, ev, isvisited);
            if(smallans == NULL)
                return NULL;
            
            else{
                //add sv into it and return
                smallans -> push_back(sv);
                return smallans;
            }
        }
            
    }

    //small ans for vertex not found
    return NULL;
}

vector<int>* PathDFS(int **edges, int n, int v1, int v2){

    // vector<int> v;

    bool *isvisited = new bool[n];

    for(int i = 0; i < n ; i++)
        isvisited[i] = false;

    vector<int> *v = PathDFSHelper(edges, n, v1, v2, isvisited);

    return v;
    
}

#include<map>
vector<int>* PathBFSHelper(int **edges, int n, int sv, int ev, bool* isvisited){

    queue<int> pendingNodes;
    pendingNodes.push(sv);
    isvisited[sv] = true;

    map<int, int> map;
    //Loop
    while(pendingNodes.size() != 0){

        int front = pendingNodes.front();
        pendingNodes.pop();

        //add children
        for(int i = 0; i < n; i++){
            if(i == front)
                continue;

            if(edges[front][i] == 1 && isvisited[i] == false){
                //push vertex into queue
                pendingNodes.push(i);

                //push into map
                map.insert(pair<int, int>(i, front));

                //mark as visited
                isvisited[i] = true;
            }
        }
    }

    

    if(map.find(ev) == map.end())
        return NULL;
    
    vector<int> *v = new vector<int>();
    v->push_back(map.find(ev) -> first);

    //adding path to vector
    for(auto itr = map.find(map.find(ev) -> second); itr != map.end(); ){
        v->push_back(itr -> first);
        itr = map.find(itr -> second);
    }

    v -> push_back(sv);
    return v;

}
vector<int>* PathBFS(int **edges, int n, int v1, int v2){

    // vector<int> v;

    bool *isvisited = new bool[n];

    for(int i = 0; i < n ; i++)
        isvisited[i] = false;

    vector<int> *v = PathBFSHelper(edges, n, v1, v2, isvisited);

    delete [] isvisited;
    return v;
    
}

bool isconnected(int **edges, int n){
    //make bool arary
    bool* isvisited = new bool[n];

    for(int i = 0; i < n; i++)
        isvisited[i] = false;

    //DFS OR BFS
    printBFS(edges, n, 0, isvisited);

    //check isvisited
    for(int i = 0; i < n; i++){
        if(isvisited[i] == false)
            return false;
    }

    return true;
}

vector<int> allconnectedcomponentsBFS(int **edges, int n, int startingIndex, bool* isVisited){

    //Make queue
    queue<int> pendingNodes;

    //push starting vertex
    pendingNodes.push(startingIndex);

    //update isvisited
    isVisited[startingIndex] = true;

    vector<int> v;
    //loop
    while(pendingNodes.size() != 0){

        //front and pop
        int front = pendingNodes.front();

        pendingNodes.pop();

        // cout << front << " ";

        v.push_back(front);
        
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
    return v;
}

vector<vector<int>> allconnectedcomponents(int **edges, int n){

    //Bool array
    bool* isvisited = new bool[n];

    for(int i = 0; i < n; i++)
        isvisited[i] = false;

    vector<vector<int>> v;
    //bfs
    for(int i = 0; i < n; i++){

        vector<int> temp;
        if(isvisited[i] == false){
            temp = allconnectedcomponentsBFS(edges, n, i, isvisited);
        }

        if(temp.size() != 0)
            v.push_back(temp);
    }

    return v;
}

//************************************** ASSIGNMENT GRAPHS1 **********************************
void connectedGroupsBFS(int **edges, int n, int sv, bool *isvisited){

    //queue
    queue<int> pendingNodes;
    pendingNodes.push(sv);
    isvisited[sv] = true;

    while (pendingNodes.size() != 0)
    {
        /* code */
        //front and pop
        int front = pendingNodes.front();
        pendingNodes.pop();

        // cout << front << endl;

        for(int i = 0; i < n; i++){

            if(i == front)
                continue;

            if(edges[front][i] == 1 && isvisited[i] == false){
                pendingNodes.push(i);
                isvisited[i] = true;
            }
        }
    }
    
}
int connectedGroups(int **edges, int n){

    //bool array
    bool *isvisited = new bool[n];

    for(int i = 0; i < n; i++)
        isvisited[i] = false;

    int k = 0;

    for(int i = 0; i < n; i++){

        if(isvisited[i] == false){
            k++;
            connectedGroupsBFS(edges, n, i, isvisited);
        }
    }

    return k;
}

#include<string>

bool hasPathHelper(vector<vector<char>> &board, int n, int m, string s, int x, int y, int index){
	
    //base case
    if(index == s.length())
        return true;
    
    //index go out of scope
    if(x < 0 || y < 0 || x >= n || y >=m)
        return false;
    
    //small calc
    if(board[x][y] == s[index]){
        
        //mark as visited
        char temp = board[x][y];
        board[x][y] = '#';
        
        //rec call
        bool ans = hasPathHelper(board, n, m, s, x, y - 1, index + 1) || hasPathHelper(board, n, m, s, x + 1, y - 1, index + 1) ||
            	   hasPathHelper(board, n, m, s, x + 1, y, index + 1) || hasPathHelper(board, n, m, s, x + 1, y + 1, index + 1) ||
                   hasPathHelper(board, n, m, s, x, y + 1, index + 1) || hasPathHelper(board, n, m, s, x - 1, y + 1, index + 1) ||
                   hasPathHelper(board, n, m, s, x -1, y, index + 1)  || hasPathHelper(board, n, m, s, x - 1, y - 1, index + 1);
        
        //mark as unvisited
        board[x][y] = temp;
        
        return ans;
    }
    
    // if(board[x][y] != string[index])
    return false;
}

bool hasPath(vector<vector<char>> &board, int n, int m) {
    // Write your code here.
    //make string codingninja
    string s = "CODINGNINJA";
    
    //loop
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            
            if(board[i][j] == s[0]){
                
                //rec call Helper fn
                bool ans = hasPathHelper(board, n, m, s, i, j, 0);
                
                if(ans == true)
                    return true;
            }
        }
    }
    
    return false;
    
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
    // DFS(edges, n);

    // int v1, v2;
    // cin >> v1 >> v2;
    // cout << hasPath(edges, n, v1, v2);
    // cout << endl;

    // for(int i = 0; i < n; i++)
    //     cout << isVisited[i] << " ";

    // vector<int> *v = PathDFS(edges, n, v1, v2);
    // vector<int> *v = PathBFS(edges, n, v1, v2);
    
    // for(int i = 0; i < v -> size(); i++)
    //     cout << v -> at(i) << " ";
    // cout << endl;
    // cout << isconnected(edges, n) << endl;

    // vector<vector<int>> path = allconnectedcomponents(edges, n);
    
    cout << connectedGroups(edges, n) << endl;
    // for(int i = 0; i < path.size(); i++){

    //     for(int j = 0; j < path[i].size(); j++)
    //         cout << path[i][j] << " ";
        
    //     cout << endl;
    // }


    for(int i = 0; i < n; i++)
        delete [] edges[i];

    delete [] edges;
}
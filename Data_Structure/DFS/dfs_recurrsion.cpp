#include <iostream>
#include <vector>
// #include <stack>
using namespace std;

vector<vector<int>> graph;
vector<int> state; // 0-unvisited, 1=instack, 2=explored

void dfs(int v){
    state[v] = 1;
    for (int u: graph[v]){
        if (state[u] == 0){
            dfs(u);
        }
    }
    state[v] = 2;
}

int main(){
    graph = {
        {1, 2},    // 0
        {0, 2},    // 1
        {0, 1},    // 2
        {4},       // 3
        {3},       // 4
        {}         // 5
    };

    int n = graph.size();
    state.assign(n,0);

    for (int i = 0; i < n; i++){
        if (state[i] == 0){
            dfs(i);
        }
    }

    for (int i=0; i< n; i++){
        cout << "node " << i << ": state" << state[i] << "\n";
    }
    return 0;
    
}
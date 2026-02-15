#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> state;

void dfs(int v){
    cout << "visiting: " << v << endl;
    if (state[v] == 2) return;
    state[v] = 1;
    for (int i: graph[v]){
        if (state[i] == 0){
            dfs(i);
        }
    }
    state[v] = 2;
}

int main(){
    graph = {
        {2,3},{4,5},{6},{},{6},{}
    };

    int n = graph.size();
    state.resize(n,0);
    dfs(0);
    for (int i=0; i < n; i++){
        cout << "vetex: " << i << " state: "  << state[i] << endl; 
    }
    return 0;
}


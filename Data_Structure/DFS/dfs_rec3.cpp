#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> graph;
vector<int> state;

void dfs(int i){
    cout << "visiting vetex i:  " << i << endl;
    if (state[i] == 2) {
        cout << "Explored " << i << endl;
        return;
    }
    state[i] = 1;
    for (int u: graph[i]){
        if (state[u] == 0){
            dfs(u);
        }
    }
    state[i] = 2;
}

int main(){
    graph = {
        {2,3},{4,5},{6},{},{6},{}
    };
    int n = graph.size();
    state.resize(n, 0);

    
    for (int i=0; i < n; i++){
        dfs(i);
    }
    for (int i=0; i<n;i++){
        cout << "vetex: " << i << "state: " << state[i] << endl;
    }
    
    return 0;
}
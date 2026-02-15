#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;
unordered_map<string, vector<string>> graph;
unordered_map<string, string> state;

void dfs(string v){

    // state X = explored, E = exploring, U = unvisited
    if (state[v] == "X"){
        cout << "Explored %s: " << v << endl;
        return;
    }

    cout << "visiting vertex: " << v << endl;
    // cout << "state[v]: " << state[v] << endl;
    state[v] = "E";
    // cout << "state[v]: " << state[v] << endl;
    for (string& s: graph[v]){
        cout << "s: " << s << endl;
        if (state[s] != "X"){
            dfs(s);
        }
    }

    state[v] = "X";

}

int main(){
    
    graph = {
        {"A", {"B", "C"}},
        {"B", {"D", "E"}},
        {"C", {"F"}},
        {"D", {}},
        {"E", {"F"}},
        {"F", {}}
    };
    
    int n = graph.size();
    // for (int i=0; i<n; i++){
        dfs("A");
    // }
    for (const auto& [key, value]: state){
        cout << "node: " << key << " state: " << value << endl;
    }
}
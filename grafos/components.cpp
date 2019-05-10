
#include <iostream>
#include <vector>

using namespace std;

using graph = vector<vector<int>>; //representacion de listas de adyacencias
vector<int> component; //component[i] es la marca del i-esimo vertice.
const int none = -1;   //usamos -1 para desmarcar

//algoritmo DFS(G, v, m)
void mark_component(const graph& G, int v, int m) {
  if(component[v] == none) {
    component[v] = m;
    for(auto w: G[v]) mark_component(G, w, m);
  }
}

//algoritmo DFS(G)
void mark_components(const graph& G) {
  component.assign(G.size(), none);
  for(int v = 0; v < G.size(); ++v) mark_component(G, v, v); 
}

int main() {
  int n, m; cin >> n >> m;
  graph G(n);
  for(int e = 0; e < m; ++e) {
    int v, w; cin >> v >> w;
    G[v].push_back(w);
    G[w].push_back(v);
  }
  mark_components(G);
  for(int v = 0; v < n; ++v) cout << "component[" << v << "] = " << component[v] << endl;
  cout << endl;
  return 0;
}

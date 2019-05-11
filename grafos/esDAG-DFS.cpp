#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using graph = vector<vector<int> >;

const int none = -1;
vector<int> order, rankk, parent;

void DFS(const graph& G, int v, int p) {
  if(parent[v] == none) {
    parent[v] = p;
    for(auto w : G[v]) DFS(G, w, v);
    rankk[v] = order.size();
    order.push_back(v);
  }
}

void postorder_DFS(const graph& G) {
  order.clear(); 
  rankk.assign(G.size(), none); 
  parent.assign(G.size(), none);
  for(int v = 0; v < G.size(); ++v) DFS(G, v, v);
}


int main() {
  //transformacion de aristas a adyacencias 
  int n, m; cin >> n >> m;
  graph G(n);
  for(int i = 0; i < m; ++i) {
    int v, w; cin >> v >> w;
    G[v].push_back(w);
  }

  //ordenamiento topológico reverso
  postorder_DFS(G);

  //detección de arista invertida
  int v = -1, w;
  for(int x = 0; x < n and v == -1; ++x) for(auto y : G[x]) 
    if(rankk[x] < rankk[y]) {v = x; w = y; break;}    
  
  if(v != -1) {
    cout << "Ciclo detectado - Ejercicio: encontrar ciclo."; 
    //Ayueda: demostrar que w es un ancestro de v por ser el árbol DFS
  } else {
    cout << "Orden topologico: ";
    for(auto v = order.rbegin(); v != order.rend(); ++v) cout << *v << " ";
  }
  cout << endl;
  return 0;
}

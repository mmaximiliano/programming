#include <iostream>
#include <vector>

using namespace std;

using graph = vector<vector<int>>;

//Retorna true si se imprime el final del camino; caso contrario retorna false.
bool print_circuit(const graph& G, int v, const vector<int>& indeg, vector<bool>& mark) {
  if(mark[v]) {cout << v; return true;}
  mark[v] = true;
  for(auto w : G[v]) if(indeg[w] > 0 and print_circuit(G, w, indeg, mark)) {
    cout << " <- " << v; return true;
  }
  return false;
}

int main() {
  //transformacion de aristas a adyacencias 
  int n, m; cin >> n >> m;
  graph G(n);
  vector<int> indeg(n, 0);
  for(int i = 0; i < m; ++i) {
    int v, w; cin >> v >> w;
    G[v].push_back(w);
    indeg[w] += 1;
  }

  //ordenamiento topológico
  vector<int> F, topo;
  for(int v = 0; v < n; ++v) if(indeg[v] == 0) F.push_back(v);
  
  while(not F.empty()) {
    topo.push_back(F.back());
    F.pop_back();
    for(auto w : G[topo.back()]) if(--indeg[w] == 0) F.push_back(w);
  }

  //Output del algoritmo
  if(topo.size() < n) {
    cout << "Camino no simple detectado: "; //por simplicidad
    vector<bool> mark(n, false);
    int v = 0; while(indeg[v] == 0 or G[v].empty()) ++v;
    print_circuit(G, v, indeg, mark);
  } else {
    cout << "Orden topologico: ";
    for(auto v : topo) cout << v << " ";
  }
  cout << endl;
  return 0;
}

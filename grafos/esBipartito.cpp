
#include <iostream>
#include <vector>

using namespace std;
using graph = vector<vector<int> >; //representación de listas de adyacencias
vector<int> part;                  //part[i] marca al i-esimo vértice con su partición candidata.
vector<int> parent;                //arbol dfs

const int none = -1;    //usamos -1 para desmarcar
const int in_cycle = 2; //marca de pertenencia a cycle impar
const int lca = 3;      //marca del ancestro comun mas bajo

//algoritmo DFS donde v se marca con la marca inversa que su padre
void bipartition(const graph& G, int v, int p = none) {
  if(part[v] == none) {
    part[v] = p == none ? 0 : 1-part[p];
    parent[v] = p;
    for(auto w: G[v]) bipartition(G, w, v);
  }
}

//algoritmo DFS(G)
void bipartition(const graph& G) {
  part.assign(G.size(), none);
  parent.assign(G.size(), none);
  for(int v = 0; v < G.size(); ++v) bipartition(G, v); 
}

//Imprime un cycle impar para una arista vw con part[v] != part[w]
void print_cycle(int v, int w) {
  //marcamos los ancestro de v y recorremos los ancestros de w hasta marcado
  //para encontrar el ancestro común mas bajo.  Unimos los caminos y tenemos
  //un cycle impar
  for(int z = v; z != none; z = parent[z]) part[z] = in_cycle;
  vector<int> cycle;
  for(; part[w] != in_cycle; w = parent[w]) cycle.push_back(w);
  part[w] = lca;
  cout << w << ", "; 
  for(auto x = cycle.rbegin(); x != cycle.rend(); ++x) cout << *x << ", ";
  for(; part[v] != lca; v = parent[v]) cout << v << ", ";
  cout << v << endl;
}

int main() {
  int n, m; cin >> n >> m;
  graph G(n);
  for(int e = 0; e < m; ++e) {
    int v, w; cin >> v >> w;
    G[v].push_back(w);
    G[w].push_back(v);
  }
  bipartition(G);
  
  for(int v = 0; v < n; ++v) for(auto w: G[v]) if(part[v] == part[w]) {
      cout << "Ciclo impar encontrado: "; print_cycle(v,w);
      return 0;
  }
  
  cout << "Biparticion: "; 
  for(int b = 0; b < 2; ++b) {
    cout << "{"; for(int v = 0; v < n; ++v) if(part[v] == b) cout << v << " "; cout << "}";
  }
  cout << endl;
  return 0;
}

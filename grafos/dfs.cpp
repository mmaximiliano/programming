#include <iostream>
#include <vector>

using namespace std;

using graph = vector<vector<int> >; //representacion de listas de adyacencias
const int none = -1;   //usamos -1 para desmarcar

void dfs(const graph& G, int v, int w, vector<int> &parent, int raiz){
  if(parent[w] != none || w == raiz){    //si ya estoy marcado, fui alcanzado
    return;
  }

  parent[w] = v;            //digo quien es mi padre

  for(auto hijo: G[w]){        //marco a mis hijos
    dfs(G, w, hijo, parent, raiz);
  }
}

//arbol dfs en representacion con vector
void arbolDfs(const graph& G, int padre, vector<int> &parent){
  int raiz = padre;
  for(auto hijo: G[padre]){
    dfs(G, padre, hijo, parent, raiz);
  }
}

int main() {
  int n, m; cin >> n >> m;
  graph G(n);
  vector<int> parent(n,none); //parent[i] es el padre de i
  for(int e = 0; e < m; ++e) {
    int v, w; cin >> v >> w;
    G[v].push_back(w);
    G[w].push_back(v);
  }

  arbolDfs(G, 0, parent);
  
  for(int v = 0; v < n; ++v) cout << "parent[" << v << "] = " << parent[v] << endl;
  cout << endl;

  return 0;
}








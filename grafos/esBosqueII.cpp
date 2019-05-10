
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using graph = vector<vector<int>>; //representacion de listas de adyacencias
using edge = pair<int,int>;
using tree = vector<int>;
const int none = -1;   //usamos -1 para desmarcar

//Calcula el arbol DFS.  
//v es el nodo actual, p del que se invoca
//Guarda en l los niveles, en T el arbol y en B los back
void DFS(const graph& G, int v, int p, vector<int>& l, tree& T, vector<edge>& B) {
  if(l[p] + 1 < l[v]) B.push_back({p,v});
  if(l[v] == none) {
    T[v] = p; l[v] = l[p]+1;
    for(auto w: G[v]) DFS(G, w, v, l, T, B);
  }
}

//algoritmo DFS(G)
pair<tree, vector<edge>> bosqueDFS(const graph& G) {
  vector<int> l(G.size(), none);
  tree T(G.size(), none);
  vector<edge> B;
  for(int v = 0; v < G.size(); ++v) DFS(G, v, v, l, T, B);
  return make_pair(T, B);
}

int main() {
  int n, m; cin >> n >> m;
  m = min(n, m);
  graph G(n);
  for(int e = 0; e < m; ++e) {
    int v, w; cin >> v >> w;
    G[v].push_back(w);
    G[w].push_back(v);
  }
//   for(int v = 0; v < n; ++v) {
//     cout << "N[" << v << "]: "; for(auto w: G[v]) cout << w << " "; cout << endl;
//   }
  
  tree T; vector<edge> B;
  tie(T, B) = bosqueDFS(G);
//   cout << "T: "; for(int v = 0; v < n; ++v) cout << T[v] << " <- " << v << ", "; cout << endl;
//   cout << "B: "; for(auto e: B) cout << e.first << " " << e.second << " "; cout << endl;
//   return 0;
  if(B.empty()) {
    cout << "es bosque: ";
    for(int v = 0; v < n; ++v) cout << T[v] << " <- " << v << ", "; cout << endl;
  } else {
    cout << "no es bosque: " <<  B.front().first;
    for(auto v = B.front().second; v != B.front().first; v = T[v]) cout << " " << v;
    cout << " " << B.front().first << endl;
  }
}


#include <iostream>
#include <vector>
#include <deque>
#include <tuple>

using namespace std;

using graph = vector<vector<int> >; //lista de adyacencias
using tree = vector<int>;
const int none = -1;

pair<tree, vector<int> > BFS(const graph& G, int r) {
  tree T(G.size(), none); vector<int> d(G.size(),-1);
  deque<pair<int,int> > cola{{r,r}};
  while(not cola.empty()) {
    int v, p; tie(v,p) = cola.front();
    cola.pop_front();
    if(T[v] == none) {
      T[v] = p; d[v] = d[p] + 1;
      for(auto w: G[v]) cola.push_back({w,v});
    }
  }
  return make_pair(T, d);
}

int main() {
  int n, m; cin >> n >> m;
  graph G(n);
  for(int e = 0; e < m; ++e) {
    int v, w; cin >> v >> w;
    G[v].push_back(w);
    G[w].push_back(v);
  }
  
  int q, r; cin >> q >> r;
  tree T; vector<int> d;
  tie(T, d) = BFS(G, r);
  
  for(int i = 0; i < q; ++i) {
    int v; cin >> v;
    cout << "Distancia de " << v << " a " << r << ": " << d[v] << ".  Primer vecino: " << T[v] << endl;
  }
}

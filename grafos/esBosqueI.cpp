
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

using graph = vector<vector<int>>; //representacion de listas de adyacencias

pair<vector<int>,vector<int>> eliminarHojas(const graph& G) {
  vector<int> d(G.size()), L, res;
  for(int v = 0; v < G.size(); ++v) {
    d[v] = G[v].size();
    if(d[v] == 0) res.push_back(v);
    if(d[v] == 1) L.push_back(v);
  }
  while(not L.empty()) {
    auto v = L.back(); L.pop_back();
    if(d[v] == 0) continue;
    d[v] -= 1; res.push_back(v);
    for(auto w: G[v]) if(d[w] > 0) {
      d[w] -= 1;
      if(d[w] == 0) res.push_back(w);
      if(d[w] == 1) L.push_back(w);
    }
  }  
  return make_pair(res, d);
}

int imprimir_ciclo(const graph& G, const vector<int>& d, vector<bool>& visited, int v, int w) {
  if(visited[w]) { 
      cout << w << " "; 
      return w;
  }
  visited[w] = true;
  int z = 0; while(d[G[w][z]] == 0 or G[w][z] == v) z += 1;
  auto last = imprimir_ciclo(G, d, visited, w, G[w][z]);
  if(last >= 0) cout << w << " ";
  return w == last ? -1 : last;
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
  vector<int> ordenHojas, d;
  tie(ordenHojas, d) = eliminarHojas(G);
  
  if(ordenHojas.size() == G.size()) {
    cout << "bosque: ";
    for(auto v: ordenHojas) cout << v << " "; cout << endl;
  } else {
    cout << "no bosque: ";
    vector<bool> visited(G.size(), false);
    int start = 0; while(d[start] == 0) start += 1;
    imprimir_ciclo(G, d, visited, -1, start);
    cout << endl;
  }
  
  return 0;
}


#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <tuple>
#include <iomanip>

using namespace std;

using neigh = pair<int, int>;
using graph = vector<vector<neigh>>;
using matrix = vector<vector<int>>; 
using bridge = tuple<int, int, int, int>; //costo, v, w, costo real

const int infty = numeric_limits<int>::max() / 2 - 1;
const int none = -1;

int cost(neigh x) {return x.second;}
int to(neigh x) {return x.first;}

int main() {
  //transformacion de aristas a adyacencias
  int n, m, r; cin >> n >> m;
  graph G(n+1);
  for(int i = 0; i < m; ++i) {
    int v, w, c; cin >> v >> w >> c;
    G[v].push_back({w,c});
  }
  
  //Nuevo vertice
  for(int v = 0; v < n; ++v) G[n].push_back({v,0});
  
  vector<int> BF(n, infty);
  { //Bellman-Ford en su propio scope para no contaminar
    vector<int> M(n, false);  
    BF[r] = 0; bool changed = M[r] = true;
    for(int i = 0; i <= n and changed; ++i) {
      changed = false;
      for(int v = 0; v < n; ++v) if(M[v]) {
        M[v] = false;
        for(auto e: G[v]) if(BF[v] + cost(e) < BF[to(e)])
        {
          M[to(e)] = changed = true;
          BF[to(e)] = BF[v] + cost(e);
        }
      }
    }
    if(changed) {cout << "Ciclo negativo detectado"; return 0;}
  }
  
  //función de costos nueva
  auto weight = [&](int v, neigh e){return cost(e) + BF[v] - BF[to(e)];};
  
  //Dijkstra n veces
  matrix D(n, vector<int>(n));
  matrix P(n, vector<int>(n, none));
  for(int r = 0; r < n; ++r) {
    P[r][r] = r; D[r][r] = 0;
    priority_queue<bridge> S;
    for(auto x : G[r]) S.push({-weight(r, x), r, to(x), cost(x)});
    while(not S.empty()) {
      int p, v, w, c; tie(p,v,w,c) = S.top();
      S.pop();
      if(P[r][w] == none) {
        P[r][w] = v; D[r][w] = c;
        for(auto x : G[w]) if(P[r][to(x)] == none)
          S.push({p-weight(w, x), w, to(x), c+cost(x)});
      }
    }
  }
  
  //output
  cout << "D = " << endl;
  for(int i = 0; i < n; ++i) {for(int j = 0; j < n; ++j) cout << setw(3) << D[i][j] << " "; cout << endl;}
  cout << "P = " << endl;
  for(int i = 0; i < n; ++i) {for(int j = 0; j < n; ++j) cout << setw(3) << P[i][j] << " "; cout << endl;}

}


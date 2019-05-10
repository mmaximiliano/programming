
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>

using namespace std;

//vecino, costo
using neigh = pair<int, int>;
using graph = vector<vector<neigh>>;
//costo, v, w
using bridge = tuple<int,int,int>;

const int none = -1;

int costo(neigh x) {return x.second;}
int vecino(neigh x) {return x.first;}

int main() {
  //transformacion de aristas a adyacencias
  int n, m, r; cin >> n >> m >> r;
  graph G(n);
  for(int i = 0; i < m; ++i) {
    int v, w, c; cin >> v >> w >> c;
    G[v].push_back({w,c});
    G[w].push_back({v,c});
  }
  
  //algoritmo de prim
  vector<int> T(n, none); T[r] = r;
  priority_queue<bridge> S;
  for(auto x : G[r]) S.push({-costo(x), r, vecino(x)});
  //el for se puede ejecutar hasta que S = vacio
  for(int i = 0; i < n-1;) {
    int c, v, w;
    tie(c,v,w) = S.top();
    S.pop();
    if(T[w] == none) {
      T[w] = v; ++i;
      //el if que sigue es opcional
      for(auto x : G[w]) if(T[vecino(x)] == none)
        S.push({-costo(x), w, vecino(x)});
    }
  }
  
  //output del algoritmo
  for(int i = 0; i < n; ++i) cout << "T[" << i << "] = " << T[i] << "  "; cout << endl;
}

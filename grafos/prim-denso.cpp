
#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

using namespace std;

//matriz de costos
using costMatrix = vector<vector<int>>;
const int inf = numeric_limits<int>::max();
const int none = -1;

int main() {
  //transformacion de aristas a matriz
  int n, m, r; cin >> n >> m >> r;
  costMatrix C(n, vector<int>(n, inf));
  for(int i = 0; i < m; ++i) {
    int v, w, c; cin >> v >> w >> c;
    C[v][w] = C[w][v] = c;
  }
  
  //algoritmo de prim denso
  vector<int> T(n, none), S(n, r); 
  T[r] = r;
  for(int i = 0; i < n-1; ++i) {
    int w = 0;
    for(int z = 0; z < n; ++z) if(C[z][S[z]] < C[w][S[w]]) w = z;
    T[w] = S[w]; S[w] = w;
    for(int z = 0; z < n; ++z) if(T[z] == none) 
      if(C[w][z] < C[z][S[z]]) S[z] = w;
  }
  
  //output del algoritmo
  for(int i = 0; i < n; ++i) cout << "T[" << i << "] = " << T[i] << "  "; cout << endl;
}

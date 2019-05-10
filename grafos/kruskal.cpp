
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include "disjoint-set.h"

using namespace std;

using edge = tuple<int,int,int>;

int& cost(edge& e) {return get<0>(e);}
int& first(edge& e) {return get<1>(e);}
int& second(edge& e) {return get<2>(e);}

int main() {
  //lectura de la lista de aristas
  int n, m; cin >> n >> m;
  vector<edge> E(m);
  for(int i = 0; i < m; ++i) 
    cin >> first(E[i]) >> second(E[i]) >> cost(E[i]);
  
  //sort inicial
  sort(E.begin(), E.end());
  //algoritmo de Kruskal; imprime el output T
  DisjointSet ds(n);
  for(int i = 0, j = 0; i < n-1; ++i) {
    while(ds.find(first(E[j])) == ds.find(second(E[j]))) ++j;
    cout << "(" << first(E[j]) << "," << second(E[j]) << "), ";
    ds.unite(first(E[j]),second(E[j]));
  }
  cout << endl;

}

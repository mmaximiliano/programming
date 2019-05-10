#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;


int main() {
	
	array<int, 6> ans={1,1,1,1,0,1};		// creo un array con el maximo numero representable

//	ans=min(array<int, 2>{ca, t}, ans);	//Creo array con los valores (t,ca) recien calculados
	
	array<int, 6> a2={1,0,1,1,1,0};

	ans=min(a2,ans);

	for (int i = 0; i < ans.size(); ++i)
	{
		cout << ans[i] << ", ";
	}
	
	return 0;
}
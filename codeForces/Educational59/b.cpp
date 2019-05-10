//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int q; cin >> q;

	for(int i = 0; i < q; ++i){
		unsigned long long int k; cin >> k;
		int n; cin >> n;
		unsigned long long int ans = n + 9*(k-1);
		cout << ans << "\n";
	}


	return 0;
}
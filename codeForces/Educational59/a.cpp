//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<ll> vll;

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	int q;
	cin >> q;

	for(int i = 0; i < q; ++i){
		int n; cin >> n;
		
		string s; cin >> s;	

		if(n == 2 && s[0] >= s[1]){
			cout << "NO\n";
		}else{
			cout << "YES\n";
			cout << "2\n";
			cout << s[0] << " " << s.substr(1, s.size()) << "\n";
		}

	}
	return 0;
}
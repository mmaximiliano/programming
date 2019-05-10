#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define pp pop_back
#define mp make_pair

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define io ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;

const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;


int main() {
	int T, r, c;
	cin >> T;

	//Test cases
	for(int t = 1; t <= T; t++){

		cin >> r >> c;
		for (int i = 0; i < n; ++i)
		{
			cin >> s;
			v.pb(s);	
		}

		// armo los subconjuntos O(2^n)
		vector< vector<string> > subsets(1<<n);
		for(int i = 0; i < (1<<n); i++)			
		{
			for(int j = 0; j < n; j++)
			{
				if(i & (1<<j))
				{
					subsets[i].pb(v[j]);	
				}
			}
		}
		int maximo = 0; 
		for(int i=0;i < (1<<n);i++){
			if(sufijos(subsets[i]) == true){
				if(maximo < subsets[i].size()){
					maximo = subsets[i].size();
				}
			}
		}

		cout<< "Case #" << t << ": "<<maximo <<"\n";
	}
	
	




	return 0;
}














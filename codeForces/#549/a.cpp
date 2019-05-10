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

const int N = (int)5e5 + 7;
const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

int main() {
	
	ll n;
	cin >> n;
	vi v;
	int m;

	for(ll i; i<n;i++){
		cin >> m;
		v.push_back(m);
	}

	ll l=0;
	ll r=0;

	for(ll i; i<n;i++){
		if(v[i]==0){
			l = i + 1;
		}else{
			r = i + 1;
		}
	}

	if(r == v.size() || l == v.size()){
		cout << v.size() <<"\n";
	}else{
		cout << min(l,r) <<"\n";
	}
	


	return 0;
}
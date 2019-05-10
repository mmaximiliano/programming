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

bool comp(int &a, int &b){return (a<b);}

int ordenado(vi &v){
	if(v.size()==1) return 1;
	if(is_sorted(v.begin(), v.end(), comp)) return v.size();
	vi left(v.begin(),v.begin() + v.size()/2);
	vi rigth(v.begin() + v.size()/2,v.end());
	return max(ordenado(left), ordenado(rigth));
}

int main() {
	
	int n;
	cin >> n;
	vi v;
	int m;

	for(int i; i<n;i++){
		cin >> m;
		v.push_back(m);
	}

	cout << ordenado(v)<<'\n';

	return 0;
}




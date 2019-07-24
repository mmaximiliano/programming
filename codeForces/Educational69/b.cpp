#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

/*   Policy-based data structure: is like set but can be indexed like an array
		Definicion para int:

#include <ext/pb_ds/assoc_container.hpp> 
using namespace __gnu_pbds; 
typedef tree<int, null_type, less<int>, rb_tree_tag, 
             tree_order_statistics_node_update> 
    indexed_set;
*/

using namespace std;

#define pb 		push_back
#define pp 		pop_back
#define mp 		make_pair
#define all(a)	(a).begin(),(a).end()
#define rep(i,a,b) for(int i = a; i <=b; i++)

#define io ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0)


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

const int inf = INT_MAX;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;

//---------------------main-------------------------//


int f(int &m, int n, int k, vi* v){
	if(k == 1){
		int res = v[n];
		return res;
	}
	if(m[n][k] != inf) return m[n][k];
	else {
		int j = inf;
		rep(i,0,n-1){
			j = min(j, f(&m, n-j, k-1, &v) + v[n] - v[n-j]);
		}
		m[n][k] = j;
		return m[n][k];
	}
}


int main() {
	int n, k;
	cin >> n >> k;
	int m[n][k];
	
	vi v(n);
	int j;

	if(k==n){
		cout << 0 << "\n";
		return 0;
	}
	rep(i,0,n-1){
		cin >> j;
		v[i] = j;
	}

	rep(i,0,n-1){
		rep(j,0,k-1){
			m[i][j] = inf;
		}
	}
		
	cout << f(&m, n, k, &v) <<"\n";


	return 0;
}
















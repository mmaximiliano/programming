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

#define pb push_back
#define pp pop_back
#define mp make_pair

#define rep(i, l, r) for (int i = (l); i <= (r); i++)
#define per(i, l, r) for (int i = (l); i >= (r); i--)

#define io ios_base :: sync_with_stdio(0), cin.tie(0), cout.tie(0);


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;

const int inf = INT_MAX;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;


int main() {
	ll n;
	cin >> n;
	vll par;
	vll impar;
	vll a(n);
	
	for(ll i = 0; i < n; ++i){
		ll j;
		cin>>j;
		if(j % 2 == 0) par.pb(j);
		else impar.pb(j);
		a[i] = j;
	}
	if(impar.size() > 0 && par.size() > 0){
	sort(par.begin(),par.end());
	sort(impar.begin(), impar.end());

	merge(par.begin(),par.end(), impar.begin(), impar.end(), a.begin());
	}

	for(int j =0; j<n-1;++j){
		cout<<a[j]<< ' ';
	}
	cout << a[n-1] << "\n";
	return 0;
}
















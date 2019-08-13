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

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	vi rooms(10,0);
	int j;
	rep(i,0,n-1){
		if(s[i] == 'L'){
			j = 0;
			while(rooms[j] == 1) j++;
			rooms[j] = 1;
		}else if (s[i] == 'R'){
			j = 9;
			while(rooms[j] == 1) j--;
			rooms[j] = 1;
		}else{
			rooms[s[i]-48] = 0;
			
		}
	}

	rep(i,0,9){
		cout << rooms[i];
	}
	




	return 0;
}
















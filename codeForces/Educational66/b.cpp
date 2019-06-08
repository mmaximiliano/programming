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
	uint64_t ads, fors, res;
	ads = 0;
	fors = 0;
	res = 0;
	vi mult;

	cin>>n;
	vector<string> fun;
	for(int i = 0; i<n; ++i){
		string s;
		cin >> s;
		if(s == "for"){
			fun.pb(s);
			cin >> s;
			fun.pb(s);
		}
		else fun.pb(s);
	}

	for(int i = 0; i<fun.size(); ++i){
		if(fun[i] == "add"){
			if(mult.size() == 0) res++;
			else if(mult.size() == 1){
				res += mult[0];
			}
			else {
				uint64_t aux2 = 1;
				aux2 *= ads;
				for(int j = 0; j<mult.size(); ++j){
					aux2 *= mult[j];
					if(ads > 0 && aux2 > pow(2, 31) -1){
						cout << "OVERFLOW!!!" << "\n";
						return 0;
					}
				}
				res += aux2;
			}
		}
		else if(fun[i] == "for"){
			i++;
			mult.pb(stoi(fun[i],nullptr,10));
		}
		else{
			mult.pop_back();
		}
		if(res > pow(2, 31) -1){
			cout << "OVERFLOW!!!" << "\n";
			return 0;
		}
	}

	cout <<res << "\n";

	return 0;
}
















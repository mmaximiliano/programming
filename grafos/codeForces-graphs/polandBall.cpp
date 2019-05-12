#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

/*   Policy-based data structure: is like a set but can be indexed like an array
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
typedef pair<int,int> pii;

const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;



bool isPrime(int number){

    if(number < 2) return false;
    if(number == 2) return true;
    if(number % 2 == 0) return false;
    for(int i=3; (i*i)<=number; i+=2){
        if(number % i == 0 ) return false;
    }
    return true;

}

int main() {
	int n;
	cin >> n;
	
	
	int i = 1;
	while(isPrime(n*i+1))i++;
	cout << i << "\n";

	return 0;
}
















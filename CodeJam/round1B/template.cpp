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
typedef pair<int,int> pii;

const int inf = (int)1e9 + 7;
const int mod = (int)1e9 + 7;
const ll linf = (ll)1e18 + 7;



int main() {
	int T;
	cin >> T;
	int p,q,x,y;
	char d;


	//Test cases
	for(int t = 1; t <= T; t++){

		cin >> p >> q;
		vector<pair<pii,char> > zonas(p);
		vector<pair<pii,pii> > intersecciones;

		//zonas
		for(int i = 0 ; i<p; i++){
			cin >> x >> y >> d;

			switch (d){
				case 'W':
					zonas[i] = mp( mp(0,x-1), 'W' );

				case 'E':
					zonas[i] = mp( mp(x+1,q), 'E');

				case 'N':
					zonas[i] = mp( mp(y+1,q), 'N');

				case 'S':
					zonas[i] = mp( mp(y-1,0), 'S');

				default:
					break;
			}

		}

		//interseccion entre zonas
		for (int i = 0; i < p; ++i){
			for(int j = i+1; j<p;j++){

			}
		}
		
		

		
		

		cout<< "Case #" << t << ": "<< "res" <<"\n";
	}
	




	return 0;
}
















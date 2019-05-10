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
	
	int T;
	cin >> T;
	ull n;
	ull m;
	int i;
	ull a;
	ull b;

	for(int j=1; j<=T;j++){
		cin >> n;
		m = n;
		i = 0;
		a = 0;
		while(n/10!=0){
			if(n%10 == 4){
				a = a + 3*pow(10,i);
			}
			i++;
			n = n/10;

		}

		if(n==4 && i != 0){
			a = a + 3*pow(10,i);
		}
		if(n==4 && i == 0 ){
			a = 3;
		}

		b = m - a;


	cout << "Case #"<< j << ": " << a << ' ' << b << '\n';
	}


	return 0;
}




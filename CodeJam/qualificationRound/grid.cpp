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
	string s;


	for(int j=1; j<=T;j++){
		cin >> n;
		cin >> s;
		string w;
		char c;

		for (int i = 0; i < s.size(); ++i)
		{
			if(s[i] == 'E'){
				w+='S';
			}else{
				w+='E';
			}
		}
		


	cout << "Case #"<< j << ": " << w << '\n';
	}


	return 0;
}

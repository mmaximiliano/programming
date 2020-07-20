#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

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
	int T;
	cin >> T;
	string s;

	for(int t = 1; t <= T; t++){
		cin >> s;
		string res;
		vector<int> digits(s.size());
		int paren = 0;
		for (int i = 0; i < s.size(); ++i)
		{
			digits[i] = (int) s[i] - 48;
		}

		for (int i = 0; i < digits.size(); ++i)
		{
			if(paren == digits[i]){
				res+= s[i];
				continue;
			}else if(paren < digits[i]){
				for (int j = 0; j < digits[i] - paren; ++j)
				{
					res += '(';
				}
				paren += digits[i] - paren;
				res+= s[i];
			}else{
				for (int j = 0; j < paren - digits[i]; ++j)
				{
					res += ')';
				}
				paren -= paren - digits[i];
				res+= s[i];
			}
		}
		while(paren--){res+= ')';}

		cout << "Case #" << t << ": " << res <<'\n';
	}
	




	return 0;
}
















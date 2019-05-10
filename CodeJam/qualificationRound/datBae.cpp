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

int unos(string &s){
	int res=0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 1){
			res++;
		}
	}
	return res;
}

int ceros(string &s){
	int res=0;
	for (int i = 0; i < s.size(); ++i)
	{
		if(s[i] == 0){
			res++;
		}
	}
	return res;
}
string posCeros(string &res){
	string s;
	for (int i = 0; i < res.size()-1; ++i)
	{
		if(res[i]==0){
			s+=i;
			s+=' ';
		}
	}
	if(res[res.size()-1]== 0){
		s+=res.size()-1;
	}

	return s;
}

int main() {
	
	int T;
	cin >> T;
	int n,b,f;
	string s;

	for(int j=1; j<=T;j++){
		cin >> n >> b >> f;
		string res;

		for (int i = 0; i < n; ++i)
		{
			if(i < n/2){
				res+= '0';
			}else{
				res+= '1';
			}
		}

		cout << res << endl;
		cin >> s;

		if(unos(s) == n-b){
			cout << posCeros(res) << endl;
		}
		
		if(ceros(s) < n/2);
		

	}


	return 0;
}
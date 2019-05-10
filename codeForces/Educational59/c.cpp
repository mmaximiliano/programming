//~ while (clock()<=69*CLOCKS_PER_SEC)
//~ #pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
using namespace std;

using ll=long long;
using pii=pair<int,int>;
using pll=pair<ll,ll>;
using vi=vector<int>;
using vll=vector<ll>;

string chain(string s, int indice){
	
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	unsigned long long int hits; cin >> hits;

	unsigned long long int max; cin >> max;

	vector<int> dmg(hits);
	for(int i=0; i<hits; ++i) cin >> dmg[i];

	string s; cin >> s;

	int total = 0;

	for(int j=0; j < hits -1; ++j){
		if(s[j] != s[j+1]){
			total = total + dmg[j];
		}else{
			unsigned long long int k = 0;

			while((k+indice+1<s.size()) && s[k + indice] == s[k + indice + 1]){
				k++;
			}
			
			string cadena = s.substr(indice, k+indice);
			
			j = j + k;


			if (cadena.size()<=max){
				for (k; k > 0; --k)
				{
					total = total + dmg[k + indice];
				}
			}else{
				vector<pii> sol;
				
			}
		}
	}

	cout << total;

	return 0;
}
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
	
	string A;
	string B;
	cin >> A >> B;
  		// Your solution goes here.

		//get vector of strings
  		vector<string> m;
  		string s;
  		for(int i = 0; i < A.size(); ++i){
    		if(A[i] != ',' ) s += A[i];
    		else {m.push_back(s); s.clear();}
    	}
    	//last word
    	m.push_back(s);

    	vector<string> n;
    	s.clear();
  		for(int i = 0; i < B.size(); ++i){
    		if(B[i] != ',' ) s += B[i];
    		else {n.push_back(s); s.clear();}
    	}
    	//last word
    	n.push_back(s);

    	//sort strings and represent them by numbers
    	vector<int> orderA(m.size());
    	for(int i = 0; i < m.size(); ++i){
    		sort(m[i].begin(), m[i].end());

    		//number of appearence
    		orderA[i] = count(m[i].begin(), m[i].end(), m[i][0]);
    	}
    	sort(orderA.begin(),orderA.end());

    	vector<int> orderB(n.size());
    	for(int i = 0; i < n.size(); ++i){
    		sort(n[i].begin(), n[i].end());

    		//number of appearence
    		orderB[i] = count(n[i].begin(), n[i].end(), n[i][0]);
    	}

    	//prepare result
    	vector<int> res(orderB.size());
    	for(int i = 0; i<res.size(); ++i){
    		auto it = lower_bound(orderA.begin(), orderA.end(), orderB[i]);
    		if(it == orderA.end()) res[i] = orderA.size();
    		else res[i] = it - orderA.begin();
    	}


  		
  for(int i = 0; i < res.size(); ++i){
  	cout << res[i] << "\n";
  }
  	return 0 ; 
}
	

















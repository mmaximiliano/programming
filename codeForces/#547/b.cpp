#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define ll long long

using namespace std;


int main() {
	
	
	int n;
	cin >> n;
	vector<int> v;
	int k;
	int ans;

	for (int i = 0; i < n; ++i)
	{
		cin >> k;
		if(k == 0){
			v.push_back(i);
		}

	}

	if(v[0] != 0 && v[v.size()-1] != n-1 ){
		ans = v[0];
		for (int i = 0; i < v.size()-1; ++i)
		{
			ans = max((v[i+1]-v[i])-1,ans);
		}
		ans = max(v[0] + n-1 - v[v.size()-1],ans);
	}else{
		if(v[0] == 0 && v.size() == 1){
			ans = n - 1;
		}else{
			ans = v[0];
			for (int i = 0; i < v.size()-1; ++i)
			{
				ans = max((v[i+1]-v[i])-1,ans);
			}
			ans = max(n-1 - v[v.size()-1], ans);
		}
		
	}
	cout << ans << "\n";
	
	return 0;
}
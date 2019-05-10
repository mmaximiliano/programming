#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;


int main() {
	
	int n;
	cin >> n;

	vector<int> v(n);

	for (int i = 0; i < n; ++i)
	{
		cin >> v[i];
	}

	int x = *max_element(v.begin(), v.end());

	int ca = 0;

	for (int i = 0; i < v.size(); ++i)
	{
		if (v[i] == x)
		{
			ca++;
		}
	}

	if (ca > 1)
	{
		cout << x << " " << x;
	}else{

		int y = 1;
	
		for (int i = 0; i < v.size(); ++i)
		{
			if (x % v[i] != 0)
			{
				y = lcm(y, v[i]);
			}
		}
		
		cout << x << " " << y;
	}	
	return 0;
}
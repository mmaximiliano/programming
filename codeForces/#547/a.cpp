#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

#define ll long long

using namespace std;



int main() {
	
	long long int n;
	cin >> n;

	long long int m;
	cin >> m;

	long long int acum = 0;

	if(n==m){
		cout << acum << "\n";
	}else{
		if (m%n == 0)
		{
			m=m/n;
			while(m%2==0){
				m=m/2;
				acum++;
			}
			while(m%3==0){
				m=m/3;
				acum++;
			}
			if(m==1){
				cout << acum << "\n";
			}else{
				cout << "-1" << "\n";
			}

		}else{
			cout << "-1" << "\n";
		}

	}
	return 0;
}
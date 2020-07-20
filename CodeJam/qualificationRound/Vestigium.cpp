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
	int n;

	for(int t = 1; t <= T; t++){
		cin >> n;
		vector<vector<int>> matrix(n, vector<int>(n,0));
		vector<unordered_set<int>> rows(n);
		vector<unordered_set<int>> columns(n);
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> matrix[i][j];
				rows[i].insert(matrix[i][j]);
				columns[j].insert(matrix[i][j]);
			}
		}
		int trace = 0;
		int repeatedRows = 0;
		int repeatedColumns = 0;
		for (int i = 0; i < n; ++i)
		{
		 	trace+= matrix[i][i];
		 	if(rows[i].size() < n) repeatedRows++;
		 	if(columns[i].size() < n) repeatedColumns++;
		}

		cout << "Case #" << t << ": " << trace << ' ' << repeatedRows << ' ' << repeatedColumns <<'\n';
	}
	




	return 0;
}
















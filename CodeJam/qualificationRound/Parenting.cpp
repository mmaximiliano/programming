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
bool comp1(tuple<int, int, int> &t1, tuple<int, int, int> &t2){
	return get<0>(t1) < get<0>(t2);
}

bool comp3(tuple<int, int, int> &t1, tuple<int, int, int> &t2){
	return get<2>(t1) < get<2>(t2);
}

int main() {
	int T;
	cin >> T;
	int n,start, end, position;

	for(int t = 1; t <= T; t++){
		cin >> n;
		vector<tuple<int, int, int>> tasks(n);
		
		for (int i = 0; i < n; ++i)
		{
			cin >> start >> end;
			position = i;
			tasks[i] = make_tuple(start, end, position);
		}

		sort(tasks.begin(), tasks.end(), comp1);
		vector<tuple<int, int, int>> C, J;
		
		end = 0;
		for (int i = 0; i < tasks.size(); ++i)
		{
			if(end > get<0>(tasks[i])) continue;
			end = get<1>(tasks[i]);
			C.push_back(tasks[i]);
			get<0>(tasks[i]) = -1;
		}
		
		end = 0;
		for (int i = 0; i < tasks.size(); ++i)
		{
			if(get<0>(tasks[i]) == -1) continue;
			if(end > get<0>(tasks[i])) continue;
			end = get<1>(tasks[i]);
			J.push_back(tasks[i]);
			get<0>(tasks[i]) = -2;
		}

		if(C.size() + J.size() != tasks.size()){
			cout << "Case #" << t << ": " << "IMPOSSIBLE" <<'\n';	
		}else{
			string res;
			sort(tasks.begin(), tasks.end(), comp3);
			for (int i = 0; i < tasks.size(); ++i)
			{
				if(get<0>(tasks[i]) == -1){
					res += 'C';
				}else{
					res+= 'J';
				}
			}
			cout << "Case #" << t << ": " << res <<'\n';	
		}
		
	}
	

	return 0;
}





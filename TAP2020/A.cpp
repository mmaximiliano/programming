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
	long double N, A, B;
	cin >> N >> A >> B;

	long double expected = 0;
	long double size = abs(A-B) + 1;
	for(int i = A; i <= B; i++){
		expected += i;
	}

	expected /= size;
	expected = N / expected;

	expected += A == 0 ? (A+1)/size : A/size;

	cout << expected << endl;


	return 0;
}
















#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;


tuple<bool,int> hayRepetidos(string &s) {

	if(s.size() <= 1){

		return make_tuple(false,0);

	}else{
		tuple<bool,int> res (false,0);

		for (int i = 0; i < s.size()-1; ++i)
		{
			if(s[i] == s[i+1]){
				return make_tuple(true,i);
			}
		}
		return res;
	}

}

string eliminar(string &s){
	bool primer = true;

	
	for (int i = 0; primer; ++i)
	{
		if(s[i] == s[i+1]){
			s.erase(i,2);
			primer = false;
		}
	}
	return s;
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	string s;
	cin >> s;

	int total = 0;
    stack<char> stk;
    
    for (char ch : s) {
        if (stk.size() and stk.top() == ch) {
            stk.pop();
            total++;
        } else {
            stk.push(ch);
        }
    }


	if(total % 2 == 0){
		cout << "No";
	}else{
		cout << "Yes";
	}
	//*/

	//s.erase(1,2);
	//cout << s;
	
	return 0;
}


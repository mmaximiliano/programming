#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;


int main() {
	
	int n;
	cin >> n;

	string s;
	cin >> s;

	int cantidad = 0;


	if(s.size() > 3){
		for (int i = 0; i < s.size(); ++i)
		{
			if ((i+3 < s.size()) && s[i] != s[i+3])
			{
				cantidad++;
				s[i+3] = s[i];
			}
		}
		cout << cantidad << "\n";
		cout << s; 
	}else{
		if(s.size() == 1){
			cout << 0 << "\n";
			cout << s;
		}else{
			if(s.size() == 2){
				if (s[0]==s[1])
				{
					if(s[0] == "R"){
						s[0] = "G";
						cout << 1 << "\n";
						cout << s; 
					}else{
						if(s[0] == "G"){
							s[0] = "R";
							cout << 1 << "\n";
							cout << s;
						}else{
							s[0] = "G";
							cout << 1 << "\n";
							cout << s;
						}
					}
				}else{
					cout << 0 << "\n";
					cout << s;
				}
			}else{
				if(s[0] == s[1] && s[1] == s[2]){
					if(s[0] == "R"){
							s[0] = "G";
							s[1] = "B"
							cout << 2 << "\n";
							cout << s; 
					}else{
						if(s[0] == "G"){
							s[0] = "R";
							s[1] = "B"
							cout << 2 << "\n";
							cout << s;
						}else{
							s[0] = "G";
							s[1] = "R"
							cout << 2 << "\n";
							cout << s;
						}
					}
				}else{
					if (s[0]==s[1])
					{
						if(s[0] == "R"){
							if(s[2] == "B"){	
								s[0] = "G";
								cout << 1 << "\n";
								cout << s;	
							}else{
								s[0] = "B";
								cout << 1 << "\n";
								cout << s;
							} 
						}else{
							if(s[0] == "G"){
								s[0] = "R";
								cout << 1 << "\n";
								cout << s;
							}else{
								s[0] = "G";
								cout << 1 << "\n";
								cout << s;
							}
						}
					}else{
						if (s[0]==s[2])
						{
							if(s[0] == "R"){
								s[0] = "G";
								cout << 1 << "\n";
								cout << s; 
							}else{
								if(s[0] == "G"){
									s[0] = "R";
									cout << 1 << "\n";
									cout << s;
								}else{
									s[0] = "G";
									cout << 1 << "\n";
									cout << s;
								}
							}
						}else{
							cout << 0 << "\n";
							cout << s;
						}
					}
				}
			}
		}
	}

	return 0;
}
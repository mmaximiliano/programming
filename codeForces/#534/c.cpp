#pragma GCC optimize("O3")
//~ #pragma GCC optimize("Ofast")
//~ #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
//~ #pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>

using namespace std;

template<int D> int getDigit(int val)       {return getDigit<D-1>(val/10);}
template<>      int getDigit<1>(int val)    {return val % 10;}

/*
int main()
{
    std::cout << getDigit<5>(1234567) << "\n";
}
*/

array<int, 2> pos (int n, int grid[4][4]){
	if(n == 0){
		for (int i = 0; i < 3; ++i)
		{
			for (int j = 0; j < 4; ++j)
			{
				if(grid[i][j]==0 && grid[i+1][j]==0){
					return array<int,2>{i,j};
				}
			}
			
		}
	}else{
		for (int i = 0; i < 4; ++i)
		{
			for (int j = 0; j < 3; ++j)
			{
				if(grid[i][j]==0 && grid[j+1][i]==0){
					return array<int,2>{j,i};
				}
			}
			
		}
	}
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);

	string s;
	cin >> s;

	int grid[4][4] = {  
   	{0, 0, 0, 0} ,  /*  initializers for row indexed by 0 */
   	{0, 0, 0, 0} ,  /*  initializers for row indexed by 1 */
   	{0, 0, 0, 0} ,  /*  initializers for row indexed by 2 */
   	{0, 0, 0, 0} ,  /*  initializers for row indexed by 3 */
	};

	for (int i = 0; i < s.size(); ++i)
	{
		array<int, 2> posicion = pos(s[i],grid);
		
	}

	
	return 0;
}
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <bits/stdc++.h>
#include <utility>

#define forn(i,n) for (ll i = 0; i < (ll) n; i++)

using ll = long long;
using ld = long double;
using namespace std;


void horizontal(int i, int j, vector<vector<char>> &m, unordered_multiset<char> p, vector<vector<unordered_set<int>>> &cells, int indice){
	cout << "horizontal: i = " << i << " j = " << j << endl;
	int longitud = p.size();
	for(int c=j; c < j + longitud && c < m.size(); c++){
		cout << "horizontal (inner): i = " << i << " c = " << c << endl;
		const auto it = p.find(m[i][c]);
		cout << "m[" << i << "][" << c << "] = " << m[i][c] <<endl;
		if(it == p.end()){
			return;
		}else{
			cout << "horizontal (inner): borro" << endl;
			p.erase(it);
		}
	}
	if(p.empty()){
		for(int c=j; c < j + longitud && c < m.size(); c++){
			cells[i][c].insert(indice);
		}
	}
	
	return;
}

void vertical(int i, int j, vector<vector<char>> &m, unordered_multiset<char> p, vector<vector<unordered_set<int>>> &cells, int indice){
	cout << "vertical: i = " << i << " j = " << j << endl;
	int longitud = p.size();
	for(int r=i; r < i + longitud && (r < m.size()); r++){
		cout << "vertical (inner): m[0].size() = " << m[0].size() << endl;
		cout << "vertical (inner): r = " << r << " j = " << j << endl;
		const auto it = p.find(m[r][j]);
		cout << "m[" << r << "][" << j << "] = " << m[r][j] <<endl;
		if(it == p.end()){
			return;
		}else{
			cout << "vertical (inner): borro" << endl;
			p.erase(it);
		}
	}
	if(p.empty()){
		for(int r=i; r < i + longitud && (r < m.size()); r++){
			cells[r][j].insert(indice);
		}
	}
	
	return;
}

void diagonal(int i, int j, vector<vector<char>> &m, unordered_multiset<char> p, vector<vector<unordered_set<int>>> &cells, int indice){
	cout << "diagonal: i = " << i << " j = " << j << endl;
	int longitud = p.size();
	for(int l = 0; l < longitud; l++){
		cout << "diagonal (inner): i = " << i + l << " j = " << j + l << endl;
		if(i + l >= m.size()){
			return;
		}
		if(j + l >= m[0].size()){
			return;
		}
		cout << "m[" << i+l << "][" << j + l << "] = " << m[i+l][j+l] <<endl;
		const auto it = p.find(m[i+l][j+l]);
		if(it == p.end()){
			return;
		}else{
			cout << "diagonal (inner): borro" << endl;
			p.erase(it);
		}
	}

	if(p.empty()){
		for(int l = 0; l < longitud; l++){ 
			cells[i+l][j+l].insert(indice);
		}
	}
	
	return;
}

void diagonalR(int i, int j, vector<vector<char>> &m, unordered_multiset<char> p, vector<vector<unordered_set<int>>> &cells, int indice){
	cout << "diagonalR: i = " << i << " j = " << j << endl;
	int longitud = p.size();
	for(int l = 0; l < longitud; l++){
		cout << "diagonalR (inner): i = " << i + l << " j = " << j - l << endl;
		if(i + l >= m.size()){
			cout << "entre con i + l = " << i+l <<endl;
			return;
		}
		if(j - l < 0){
			cout << "entre con j - l = " << j-l <<endl;
			return;
		}
		const auto it = p.find(m[i+l][j-l]);
		cout << "m[" << i + l << "][" << j - l << "] = " << m[i+l][j-l] <<endl;
		if(it == p.end()){
			return;
		}else{
			cout << "diagonalR (inner): borro" << endl;
			p.erase(it);
		}
	}

	if(p.empty()){
		for(int l = 0; l < longitud; l++){ 
			cells[i+l][j-l].insert(indice);
		}
	}
	
	return;
}

int main() {
	ios_base::sync_with_stdio(0);
	
	//Leo entrada
	int r, c, n;
	cin >> r >> c;

	vector<vector<char>> m(r,vector<char> (c));

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> m[i][j];
		}
	}
	cin >> n;
	vector<unordered_multiset<char>> palabras(n);

	for(int i=0; i<n; i++){
		string s;
		cin >> s;
		for(int j = 0; j<s.size(); j++){
			palabras[i].insert(s[j]);
		}
	}

	//resuelvo
	int specialCells = 0;
	vector<vector<unordered_set<int>>> cells(r,vector<unordered_set<int>> (c));

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cout << "i = " << i << " j = " << j << endl;
			for(int indice = 0; indice < palabras.size(); indice++){
				horizontal(i,j,m,palabras[indice], cells, indice);
				vertical(i,j,m,palabras[indice], cells, indice);
				diagonal(i,j,m,palabras[indice], cells, indice);
				diagonalR(i,j,m,palabras[indice], cells, indice);
			}
		}
	}

	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			if(cells[i][j].size() > 1) specialCells++;
			if(j == c-1){
				cout << cells[i][j].size() << endl;
			}else{
				cout << cells[i][j].size() << ' ';
			}
		}
	}

	cout << specialCells;


	return 0;
}














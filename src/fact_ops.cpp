#include <bits/stdc++.h>

typedef long long ll;
typedef unsigned long long ull;

bool is_prime_prob(ll n, int a){
	if(n == a) return true;
	ll s = 0, d = n - 1;
	while(d%2 == 0) s++, d /=2;
	ll x = expmod(a, d, n);
	if((x == 1) || (x+1 == n)) return true;
	for(int i = 0; i < s-1; i++){
		x = mulmod(x,x,n);
		if(x == 1) return false;
		if(x+1 == n) return true;
	}
	return false;
}

//Si ejecutamos el test 𝑘 veces, la probabilidad de que falle es Ρ = 𝜌^k
//lo ejecutamos para {2,3,5,7,11,13,17,19,23}
//anda para todos los números hasta 10^18 
bool rabin(ll n){
	if(n == 1) return false;
	int ar[] = {2,3,5,7,11,13,17,19,23};
	for(int i = 0; i<9;i++)if(!is_prime_prob(n,ar[i])) return false;
}

//Para factorizar un número 𝒏 hacemos lo siguiente:
//.Chequeamos si 𝒏 es primo usando Rabin-Miller.
//.Si da cierto lo agregamos a la factorización y terminamos.
//.Si no es primo, usamos Rho para encontrar un divisor 𝒅 no trivial de 𝒏. 
//Una vez hallado factorizamos 𝒅 y 𝒏/𝒅 por separado y unimos las soluciones.
//time: O(root(4,n))

ll rho(ll n){
	if(!(n&1)) return 2;
	ll x = 2, y = 2, d = 1;
	ll c = rand()%n + 1;
	while(d == 1){
		x = (mulmod(x,x,n) + c) % n;
		y = (mulmod(y,y,n) + c) % n;
		y = (mulmod(y,y,n) + c) % n;
		if(x >= y) d = gcd(x-y, n);
		else d = gcd(y-x, n); 
	}
	return d == n ? rho(n) : d; 
}

void fact_rho(ll n, map<ll, int> &f){
	if(n == 1) return;
	if(rabin(n)){f[n]++;return;}
	ll q = rho(n);fact_rho(q,f); fact_rho(n/q,f);
}


//Cantidad de divisores
ll cantDiv(ll n){
	fact(n); //Necesitamos factorizar n
	ll ans = 1;
	for(auto f: F) ans *= (f.second + 1);
	return ans; 
}

//suma de divisores
ll sumDiv(ll n){
	fact(n); //Necesitamos factorizar n
	ll ans = 1;
	for(auto f: F){
		ans *= (exp(f.first, f.second+1) -1)/(f.first-1);	
	} 
	return ans; 
}







#include <bits/stdc++.h>
#define ll uint64_t
#define ff first
#define ss second
#define sz(x) x.size()
#define pb(x) push_back(x)
#define all(a) a.begin(),a.end()
#define setp(x) fixed << setprecision(x)

using namespace std;

typedef complex<long double> cd;
namespace input {
	template<class T> void re(complex<T>& x);
	template<class T1, class T2> void re(pair<T1,T2>& p);
	template<class T> void re(vector<T>& a);
	template<class T, size_t SZ> void re(array<T,SZ>& a);

	template<class T> void re(T& x) { cin >> x; }
	void re(double& x) { string t; re(t); x = stod(t); }
	void re(long double& x) { string t; re(t); x = stold(t); }
	template<class Arg, class... Args> void re(Arg& first, Args&... rest) {
		re(first); re(rest...);
	}

	template<class T> void re(complex<T>& x) { T a,b; re(a,b); x = cd(a,b); }
	template<class T1, class T2> void re(pair<T1,T2>& p) { re(p.ff,p.ss); }
	template<class T> void re(vector<T>& a) {
		for(auto &i:a)re(i);
	}
	template<class T, size_t SZ> void re(array<T,SZ>& a) {
		for(int i=0;i<SZ;++i) re(a[i]);
	}
}

using namespace input;

namespace io
{
	void setIn(string s) { ifstream cin (s);}
	void setOut(string s) {ofstream cout (s);}
	void setIO(string s = "")
	{
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cin.exceptions(cin.failbit);
		if (sz(s)) setIn(s+".inp"), setOut(s+".out");
	}
}
using namespace io;

constexpr int mod = 1e9+7;

/**
	funtion check (a^s)*d
	paramater: uint64_t x
	return (s,d)
*/
pair<ll, ll > factor(ll x){
	ll s=0;
	while((x&1)==0){
		s++;
		x>>=1;
	}
	return {s, x};
}

/**
	funtion pow(a,d,n)
	paramater: uint64_t -> a,d,n
	return (a^d)%n
*/
ll Pow(ll a, ll d, ll n){
	ll res=1;
	a%=n;
	while(d){
		if(d&1) res=res*a%n;
		a=a*a%n;
		d>>=1;
	}
	return res;
}

bool miller_check(ll s, ll d, ll n, ll a){
	if(n==a) return true;
	ll p = Pow(a,d,n);
	if(p==1) return true;
	while(s--){
		if(p==n-1) return true;
		p=p*p%n;
	}
	return false;
}

bool miller(ll n){
	if(n<2) return false;
	if(n%2==0) return n==2;
	ll s,d;
	tie(s,d) = factor(n-1);
	return miller_check(s,d,n,2)&&miller_check(s,d,n,3) && miller_check(s,d,n,7) && miller_check(s,d,n,41) && miller_check(s,d,n,61);
}

void solution()
{
	ll l,r;
	re(l);
	re(r);
	for(ll i = l; i<=r; ++i)
		if(miller(i)) cout<<i<<'\n';
	cout << '\n';
}

int main()
{
	setIO();
	srand(time(NULL));
	int t; re(t);
	while(t--)
		solution();
	return 0;
}



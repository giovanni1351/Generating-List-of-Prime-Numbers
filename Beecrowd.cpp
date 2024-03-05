#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_set>
#include <vector>
#include <numeric> 
#include <unordered_map>
#include <iomanip>
#include <string>
#include <queue>
#include <bitset>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <climits>
#include <stdlib.h>
#include <list>
#include <functional>
#define MAXN 200000
#define INF 9999999
#define ll long long int
//#include <sys/resource.h>
//ios_base::sync_with_stdio(0);
//cin.tie(0);
//cout.tie(0);
using namespace std;

typedef vector<int> vi;
typedef vector<unsigned ll> vull;
typedef vector<ll> vll;
typedef vector<double> vd;
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef pair<int, double> id;
typedef pair<double, double> dd;
typedef pair<dd, dd> dddd;
typedef vector<ii> vii;
typedef vector<id> vid;
typedef vector<dd> vdd;
typedef vector<dddd> vdddd;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vii> Graph;
typedef vector<vid> DGraph;
typedef queue<ii> qii;
typedef queue<id> qid;
typedef queue<int> qi;
typedef queue<ii> qii;
typedef map<int, int> mii;
typedef map<int, string> mis;
typedef map<char, string> mcs;
typedef map<char, int> mci;
typedef map<string, string> mss;
typedef multiset<int> ms;
typedef set<ii> sii;
typedef set<int> si;
typedef set<string> ss;
typedef unordered_set<int> usi;
typedef priority_queue<ii, vii, greater<ii>> pq;
typedef priority_queue<ii> pqr;
typedef priority_queue<id, vid, greater<id>> Dpq;
vs split(const string& str, char delimiter = ' ') {
	vs result;
	size_t start = 0;
	size_t end = str.find(delimiter);

	while (end != string::npos) {
		result.push_back(str.substr(start, end - start));
		start = end + 1;
		end = str.find(delimiter, start);
	}

	result.push_back(str.substr(start));
	return result;
}

//int dx[] = {1,0,-1,0};
//int dy[] = {0,1,0,-1};

ll _sieve_size;
bitset<10000010> bs; // 10^7 is the rough limit
vll p; // compact list of primes
void sieve(ll upperbound) { // range = [0..upperbound]
	_sieve_size = upperbound + 1; // to include upperbound
	bs.set(); // all 1s
	bs[0] = bs[1] = 0; // except index 0+1
	for (ll i = 2; i < _sieve_size; ++i) if (bs[i]) {
		// cross out multiples of i starting from i*i
		for (ll j = i * i; j < _sieve_size; j += i) bs[j] = 0;
		p.push_back(i); // add prime i to the list
	}
}

int numPF(ll N) {
	int ans = 0;
	for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)
		while (N % p[i] == 0) { 
			N /= p[i]; 
			++ans; 
		}
	return ans + (N != 1);
}
bool isPrime(ll N) { // good enough prime test
	if (N < _sieve_size) return bs[N]; // O(1) for small primes
	for (int i = 0; i < (int)p.size() && p[i] * p[i] <= N; ++i)
		if (N % p[i] == 0)
			return false;
	return true; // slow if N = large prime
}
vll primeFactors(ll N) { // pre-condition, N >= 1
	vll factors;
	for (int i = 0; (i < (int)p.size()) && (p[i] * p[i] <= N); ++i)
		while (N % p[i] == 0) { // found a prime for N
			N /= p[i]; // remove it from N
			factors.push_back(p[i]);
		}
	if (N != 1) factors.push_back(N); // remaining N is a prime
	return factors;
}	
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	sieve(10000000);
	vll r;
	r = primeFactors((1LL << 31) - 1); // Mersenne prime
	for (auto& pf : r) printf("> %lld\n", pf);
	r = primeFactors(136117223861LL); // large prime factors
	for (auto& pf : r) printf("> %lld\n", pf); // 104729*1299709
	r = primeFactors(5000000035LL); // large prime factors
	for (auto& pf : r) printf("> %lld\n", pf); // 5*1000000007
	r = primeFactors(142391208960LL); // large composite
	for (auto& pf : r) printf("> %lld\n", pf); // 2^10*3^4*5*7^4*11*13
	r = primeFactors(100000380000361LL); // 10000019^2
	for (auto& pf : r) printf("> %lld\n", pf); // fail to factor! (why?)

	
	return 0;
	
}
/**********************/
/* Mahabub Rahman     */
/* Cse 10th           */
/* Comilla University */
/**********************/
//#pragma GCC optimize("O3,unroll-loops") 
//#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define       ll                  long long int
#define       veci                 vector<int>
#define       vecl                 vector<long long int>
#define       pb                   push_back
#define       newline cerr << endl
#define       pii                  pair<int, int>
#define       F                    first
#define       S                    second
#define       nl                   "\n"
#define       all(v)               v.begin(), v.end()
#define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
///============ CONSTANT ===============///
#define mx9   1000000007
#define mx5   200005
#define inf   1<<30                                           //infinity value
#define eps   1e-9
#define mod   mx9
///=============== Debugging ============================///
void __print(int x) {cout << x;}
void __print(long x) {cout << x;}
void __print(long long x) {cout << x;}
void __print(unsigned x) {cout << x;}
void __print(unsigned long x) {cout << x;}
void __print(unsigned long long x) {cout << x;}
void __print(float x) {cout << x;}
void __print(double x) {cout << x;}
void __print(long double x) {cout << x;}
void __print(char x) {cout << '\'' << x << '\'';}
void __print(const char *x) {cout << '\"' << x << '\"';}
void __print(const string &x) {cout << '\"' << x << '\"';}
void __print(bool x) {cout << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cout << '{'; __print(x.first); cout << ','; __print(x.second); cout << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cout << '{'; for (auto &i: x) cout << (f++ ? "," : ""), __print(i); cout << "}";}
void _print() {cout << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cout << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cout << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif
///=============================================///
void init_code()
{
    ios::sync_with_stdio(false); cin.tie(0);cout.tie(0);
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
    #endif    
}

int main()
{
    //init_code();
    string str;
    for(char c = 'A'; c<='Z'; c++) str+=c;

	string s, cc, Stream, Cipher;
	cout << "Enter the ciphertext: ";
	getline(cin, cc);
	cout << "\nEnter the stream: ";
	getline(cin, s);
	
	
    transform(cc.begin(), cc.end(), cc.begin(), ::toupper);
    transform(s.begin(), s.end(), s.begin(), ::toupper);	
    
    for(int i=0; i<cc.size(); i++)
    {
    	if(!isspace(cc[i])) Cipher += cc[i];
    }
    
    for(int i=0; i<s.size(); i++)
    {
    	if(!isspace(s[i])) Stream += s[i];
    }
    
    map<pair<char, char>, char> encrypt, decrypt;
    for(char c='A'; c<='Z'; c++)
    {
    	if(c!='A')
    	{
    		char k = str[0];
    		str.erase(0, 1);
    		str += k;
    	}
    	for(int h='A', i=0; h<='Z'; h++, i++)
    	{
    		encrypt[{h, str[i]}] = c;
    		decrypt[{c, str[i]}] = h;
    	}
    }    
    
    cout << "\nDecryption text is: ";
    for(int i=0; i<Stream.size(); i++)
    {
    	cout << decrypt[{Cipher[i], Stream[i]}];
    }
    cout << nl;
return 0;
}

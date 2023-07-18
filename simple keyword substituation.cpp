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
    init_code();
    string k, m, keyword, message;
    cout << "Enter the keyword: ";
    getline(cin, k);
    cout << "\nEnter the plaintext: ";
    getline(cin, m);
    
    transform(k.begin(), k.end(), k.begin(), ::toupper);
    transform(m.begin(), m.end(), m.begin(), ::toupper);
    for(int i=0; i<m.size(); i++)
    {
    	if(!isspace(m[i])) message += m[i];
    }
    
    map<char, bool> vis;
    map<char, char> encrypt, decrypt;
    for(int i=0; i<k.size(); i++)
    {
    	if(!isspace(k[i]) and !vis[k[i]])
    	{
    		keyword += k[i];
    		vis[k[i]] = true;
    	}
    }
    set<char> Set;
    for(char c = 'A'; c<='Z'; c++) Set.insert(c);
    int id = 0;
    for(char c = 'A'; c<='Z'; c++)
    {
    	if(id < keyword.size())
    	{
    		encrypt[c] = keyword[id];
    		decrypt[keyword[id]] = c;
    		Set.erase(keyword[id]);
    		id++;
    	}
    	else
    	{
    		encrypt[c] = *Set.begin();
    		decrypt[*Set.begin()] = c;
    		Set.erase(Set.begin());
    	}
    }
    //debug(message, keyword);
    cout << "\nEncryption is: ";
    for(int i=0; i<message.size(); i++) cout << encrypt[message[i]];
    cout << nl;
return 0;
}

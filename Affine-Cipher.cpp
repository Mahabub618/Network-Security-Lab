
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long int
int inv(int m)
{
    for(int i=0; i<=25; i++)
    {
        if( (m*i )%26 ==1)return i;
    }
}
void ifdef()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    freopen("Error.txt", "w", stderr);
#endif
}
int main()
{

    //ifdef();
    string p="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // encrypts
    string plain;
    cout<<"Enter the plain text: ";
    getline(cin,plain);
    int m,c;
    cout<<"Enter the value m c: ";
    cin>>m>>c;
    cout<<"encrypts :";
    for(int i=0; i<plain.size(); i++)
    {
        if(plain[i]>='A' and plain[i]<='Z')
        {
            int x=plain[i]-'A';
            int y=(m*x + c)%26;
            cout<<p[y];

        }
        else cout<<plain[i];
    }
    cout<<endl;

    //decrypts

    string cipher;
    cin.ignore();
    cout<<"Enter the cipher text: ";
    getline(cin,cipher);
    cout<<"Enter the value m c: ";
    cin>>m>>c;
    cout<<"decrypts :";
    for(int i=0; i<cipher.size(); i++)
    {
        if(cipher[i]>='A' and cipher[i]<='Z')
        {
            int y=cipher[i]-'A';
            int x=(inv(m)*((y-c)%26))%26;
            cout<<p[x];
        }
        else cout<<cipher[i];
    }
    cout<<endl;
    return 0;
}



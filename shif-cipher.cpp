
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
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

    string plain;
    // encrypts
    cout<<"Enter the plain text: ";
    getline(cin,plain);
    int k;
    cout<<"Enter the key : ";
    cin>>k;
    cout<<"encrypts :";
    for(int i=0; i<plain.size(); i++)
    {
        if(plain[i]>='A' and plain[i]<='Z')
        {

            int in=(plain[i]-'A' +k)%26;
            cout<<p[in];

        }
        else cout<<plain[i];
    }
    cout<<endl;

    //decrypts

    string cipher;
    cin.ignore();
    cout<<"Enter the cipher : ";
    getline(cin,cipher);
    cout<<"Enter the key: ";
    cin>>k;
    cout<<"decrypts :";
    for(int i=0; i<cipher.size(); i++)
    {
        if(cipher[i]>='A' and cipher[i]<='Z')
        {

            int in=(cipher[i]-'A'-k+26)%26;
            cout<<p[in];
        }
        else cout<<cipher[i];
    }
    cout<<endl;
    return 0;
}



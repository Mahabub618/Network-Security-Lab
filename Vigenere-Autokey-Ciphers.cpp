
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long int
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

    // ifdef();
    string p="ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";

    char a[27][27];
    cout<<"  ";
    for(int i=0; i<26; i++)cout<<p[i];
    cout<<endl;
    for(int i=0; i<26; i++)
    {
        cout<<p[i]<<" ";
        for(int j=i; j<26+i; j++)
        {
            a[i][j-i]=p[j];
            cout<<a[i][j-i];
        }
        cout<<endl;
    }

    string plain,temp;
    cout<<"Enter plain text: ";
    getline(cin,plain);
    for(int i=0; i<plain.size(); i++)
    {
        if(plain[i]!=' ')temp+=plain[i];

    }
    plain=temp;
    string key;
    cout<<"Enter key: ";
    cin>>key;
    key+=plain;
    key.erase(key.begin()+key.size()-1);


    string cipher;

    for(int i=0; i<plain.size(); i++)
    {
        int x=plain[i]-'A';
        int y=key[i]-'A';
        //cout<<x<<" "<<y<<" "<<a[x][y]<<endl;
        cipher+=a[x][y];
    }
    cout<<"Ecrypts"<<endl;
    cout<<"Plain   :"<<plain<<endl;
    cout<<"key     :"<<key<<endl;
    cout<<"cipher  :"<<cipher<<endl;

    cout<<"Enter key: ";
    cin>>key;
    cin.ignore();
    cout<<"Enter cipher text: ";
    getline(cin,cipher);
    plain="";
    temp="";

    for(int i=0; i<cipher.size(); i++)
    {
        if(cipher[i]>='A' and cipher[i]<='Z')
        {
            temp+=cipher[i];
        }
    }
    cipher=temp;
    for(int i=0; i<cipher.size(); i++)
    {
        int x=key[i]-'A';
        for(int j=0; j<26; j++)
        {
            if(a[x][j]==cipher[i])
            {
                plain+=(char)('A'+j);
                key+=(char)('A'+j);
                break;
            }
        }
    }
    key.pop_back();
    cout<<"\nDecrypts"<<endl;
    cout<<"key     :"<<key<<endl;
    cout<<"cipher  :"<<cipher<<endl;
    cout<<"Plain   :"<<plain<<endl;

    return 0;
}

/*
input

A LOVING HEART IS THE TRUEST WISDOM
P
P
PLZJDVTNLERKBALALXKLYWLPEAVRA

*/




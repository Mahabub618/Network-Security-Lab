
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

    printf("Enter the  keyword: ");
    string p,keywords,k;
    getline(cin,keywords);


    map<char,int> check;
    for(int i=0; i<keywords.size(); i++)
    {
        if(keywords[i]==' ')continue;
        else if(!check[keywords[i]])
        {
            k+=keywords[i];
            check[keywords[i]]=1;
        }
    }
    cout<<"keyword after space removing : ";
    cout<<k<<endl;
    for(char i='A'; i<='Z'; i++)
    {
        if(!check[i])k+=i;
    }
    map<char,char>mp,mc;
    char ch='A';
    for(int   i=0; i<k.size(); i++)
    {
        mp[ch]=k[i];
        mc[k[i]]=ch;
        ch++;
    }


    cout<<"Plain text : ";
    for(char  i ='A'; i<='Z'; i++)cout<<i;

    cout<<"\nchiper text :";
    for(char  i ='A'; i<='Z'; i++)cout<<mp[i];
    cout<<endl;


    string plain;
    cout<<"Enter Plain text : ";
    getline(cin,plain);
    cout<<"encrypts :";
    for(int i=0; i<plain.size(); i++)
    {
        if(plain[i]>='A' and plain[i]<='Z')cout<<mp[plain[i]];
        else cout<<plain[i];
    }
    cout<<endl;



    string chiper;
    cout<<"Enter cipher text : ";
    getline(cin,chiper);
    cout<<"decrypts :";
    for(int i=0; i<chiper.size(); i++)
    {
        if(chiper[i]>='A' and chiper[i]<='Z')cout<<mc[chiper[i]];
        else cout<<chiper[i];
    }
    cout<<endl;
    return 0;
}




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

    printf("Enter the Keyword : ");
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

    int sz=k.size();



    cout<<"keyword after space removing : ";
    cout<<k<<endl;

    for(char i='A'; i<='Z'; i++)
    {
        if(!check[i])k+=i;
    }
    map<char,char>mp,mc;

    char ch='A';
    for(int  i=0; i<sz; i++)
    {

        for(int j=i; j<26; j+=sz)
        {
            mp[ch]=k[j];
            mc[k[j]]=ch;
            ch++;
        }
    }



    cout<<"Plain text : ";
    for(char  i ='A'; i<='Z'; i++)cout<<i;

    cout<<"\nchiper text :";
    for(char  i ='A'; i<='Z'; i++)cout<<mp[i];
    cout<<endl;

    string plain;
    // encrypts
    printf("Enter the plain text : ");
    getline(cin,plain);
    cout<<"encrypts :";
    for(int i=0; i<plain.size(); i++)
    {

        if(plain[i]>='A' and plain[i]<='Z')cout<<mp[plain[i]];
        else cout<<plain[i];
    }
    cout<<endl;

    //decrypts
    printf("Enter the cipher text : ");
    string chiper;
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



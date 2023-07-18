
#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
#define ll long long int
int inv(int m)
{
   for(int i=0;i<=25;i++)
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
   string p="ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ";

   char a[27][27];
   cout<<"  ";
     for(int i=0;i<26;i++)cout<<p[i];
      cout<<endl;
   for(int i=0;i<26;i++)
   {
      cout<<p[i]<<" ";
      for(int j=i;j<26+i;j++)
      {
         a[i][j-i]=p[j];
         cout<<a[i][j-i];
      }
      cout<<endl;
   }

   string plain,temp;
   cout<<"Enter plain text: ";
   getline(cin,plain);
   for(int i=0;i<plain.size();i++)
   {
      if(plain[i]!=' ')temp+=plain[i];

   }
    plain=temp;

    string key,keyline;
    cout<<"Enter keyline: ";
    getline(cin,keyline);

    for(int i=0;i<keyline.size();i++)
    {
      if(keyline[i]>='A' and keyline[i]<='Z')
      {
         key+=keyline[i];
      }
    }

//    while(key.size()>plain.size())key.pop_back();
    key=key.substr(0,plain.size());
    string cipher;

    for(int i=0;i<plain.size();i++)
    {
      int x=plain[i]-'A';
      int y=key[i]-'A';
      cipher+=a[x][y];
    }
    cout<<"Ecrypts"<<endl;
    cout<<"Plain   :"<<plain<<endl;
    cout<<"keyline     :"<<key<<endl;
    cout<<"cipher  :"<<cipher<<endl;
    cout<<"Enter keyline: ";
    getline(cin,keyline);
    cout<<"Enter cipher text: ";
    getline(cin,cipher);
    plain="";
    temp="";
    key="";


    for(int i=0;i<cipher.size();i++)
    {
      if(cipher[i]>='A' and cipher[i]<='Z')
      {
        temp+=cipher[i];
      }
    }
    cipher=temp;
    for(int i=0;i<keyline.size();i++)
    {
      if(keyline[i]>='A' and keyline[i]<='Z')
      {
         key+=keyline[i];
      }

    }

    for(int i=0;i<cipher.size();i++)
    {
       int x=key[i]-'A';
        for(int j=0;j<26;j++)
        {
          if(a[x][j]==cipher[i])
          {
            plain+=(char)('A'+j);
            break;
          }
        }
    }
    //while(key.size()>cipher.size())key.pop_back();
    key=key.substr(0,cipher.size());
    cout<<"\nDecrypts"<<endl;
    cout<<"keyline     :"<<key<<endl;
    cout<<"cipher  :"<<cipher<<endl;
    cout<<"Plain   :"<<plain<<endl;


    return 0;
}
/*

WHERE SHALL WE MEET AND AT WHAT TIME
FORCENTURIESTHESIMPLEMONOALPH
FORCENTURIESTHESIMPLEMONOALPH
BVVTI FAUCT AW FLIL IZS LX IVNH TTBL
*/


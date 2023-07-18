#include<bits/stdc++.h>
#include<vector>
using namespace std;
int main(){
    int x,y,i,j,n;

    cout<<"Enter the key: \n";
    string b;
    cin>>b;
    int sz=b.size();

    int sq=sqrt(sz);
    if((sq*sq)!=sz)
    {
        sq++;
    }
    n=sq;
    char ch='A';
    for(int i=b.size();i<n*n;i++,ch++)
    {
        b+=ch;
    }
    int k=0;

    vector<vector<int> > a(n, vector<int>(n));
    cout<<"KEY matrix vector "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){

            a[i][j]=b[k]-'A';
            cout<<a[i][j]<<" ";
            k++;
        }
        cout<<endl;
    }
    cout<<"Enter the message to encrypt\n";
    string s;
    cin>>s;
   if(s.size()%n!=0)
    {
       int d=n-(s.size()%n);
       while(d--)s+='X';

    }
    k=0;
    //cout<<s<<endl;
    string ans="";
    while(k<s.size()){
        for(i=0;i<n;i++){
            int sum = 0;
            int temp = k;
            for(j=0;j<n;j++){
                sum += (a[i][j]%26*(s[temp++]-'A')%26)%26;
                sum = sum%26;
            }
            ans+=(sum+'A');
        }
        k+=n;
    }
    cout<<ans<<'\n';

    return 0;
}


#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define lld long double
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define fl(i,n) for(int i=0;i<n;i++)
#define rl(i,m,n) for(int i=n;i>=m;i--)
#define py cout<<"YES\n";
#define pn cout<<"NO\n";
#define vr(v) v.begin(),v.end()
#define rv(v) v.end(),v.begin()
#define fast ios_base::sync_with_stdio(false);
#define input cin.tie(NULL);
#define output cout.tie(NULL);
#define give(x) cout<<x<<"\n";
using namespace std;
ll gcd(ll a, ll b){if (b == 0)return a;return gcd(b, a % b);}
ll lcm(ll a, ll b){return (a/gcd(a,b)*b);}
bool sorta(const pair<int,int> &a,const pair<int,int> &b){return (a.second < b.second);}
bool sortd(const pair<int,int> &a,const pair<int,int> &b){return (a.second > b.second);}
void printarr(ll arr[], ll n){fl(i,n) cout << arr[i] << " ";cout << "\n";}
string decToBinary(int n){string s="";int i = 0;while (n > 0) {s =to_string(n % 2)+s;n = n / 2;i++;}return s;}
ll binaryToDecimal(string n){string num = n;ll dec_value = 0;int base = 1;int len = num.length();for(int i = len - 1; i >= 0; i--){if (num[i] == '1')dec_value += base;base = base * 2;}return dec_value;}
 
void asquare(){
    int n,k,c=0;
    cin>>n>>k;
 
    vector<int> arr(n),srr(n);
    map<int,int> mpp;
 
    fl(i,n){
        cin>>arr[i];
        srr[i]=arr[i];
    }
 
    sort(srr.begin(),srr.end());
 
 
    fl(i,n){
        mpp[srr[i]]=i;
    }
 
    fl(i,n){
        if(mpp[arr[i]]>0 && i>0 && srr[mpp[arr[i]]-1]==arr[i-1]){continue;}
        else{c++;}
    }
 
    if(c<=k){cout<<"YES\n";}else
    cout<<"NO\n";
}
int main()
{
    fast input output
    ll t;
    cin>>t;
    while(t--)
    {
        asquare();
    }
    return 0;
}
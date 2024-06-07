#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define nn "\n" 
#define fr(x,y) for(ll x=0; x<y; x++)
#define fr1(x,t,y) for(ll x=t; x<y; x++)
#define fr3(x,t,y) for(ll x=t; x>y; x--)
#define ga(a,n) ll a[n]; fr(i,n) cin>>a[i];
#define gv(v,n) vll v(n); fr(i,n) cin>>v[i];
#define vll vector <ll>
#define vpair vector<pair<ll,ll>>
#define pb push_back
#define pp pop_back
#define ff first
#define ss second
#define yes cout<<"YES"<<nn
#define no cout<<"NO"<<nn
#define all(vector) vector.begin(), vector.end()
#define print(v) fr(i,v.size()) cout<<v[i]<<" "; cout<<nn;
const ll mod = 1e9+7;

class Solution {
public:
    string replaceWords(vector<string>& a, string s){
        ll n=a.size(), m = s.size();
        set<string> mp;
        fr(i,n){
            mp.insert(a[i]);
        }
        bool f=0;
        string ans = "", t="";
        fr(i,m){
            if(f && s[i] != ' '){
                if(i==m-1) ans += t;
                continue;
            }
            if(s[i] == ' '){
                ans += t;
                ans += ' ';
                t = "";
                f = 0;
            }
            else
            {
                t += s[i];
            }
            if(mp.find(t) != mp.end()){
                f = 1;
            }
            if(i==m-1) ans += t;
        }
        return ans;
    }
};
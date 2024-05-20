#include<bits/stdc++.h>
using namespace std;
#define ll long long

class Solution {
public:
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
    ll n,m;
    vector<string> s;
    vector<vll> dp;
    ll rec(ll i, ll pre){
        if(i==m) return 0;
        if(dp[i][pre+1] != -1) return dp[i][pre+1];
        ll ans = rec(i+1, pre);
        if(pre==-1){
            ans = max(ans, 1+rec(i+1,i));
        }
        else
        {
            bool f=1;
            fr(j,n){
                if(s[j][i] < s[j][pre]){
                    f=0;
                    break;
                }
            }
            if(f) ans = max(ans, 1+rec(i+1,i));
        }
        return dp[i][pre+1] = ans;
    }
    int minDeletionSize(vector<string>& str) {
        s = str;
        n = s.size(), m=s[0].size();
        dp.assign(m, vll(m+1, -1));
        return m - rec(0,-1);
    }
};
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
    ll n;
    ll dp[100010][2][3];
    ll rec(ll i, ll a, ll l){
        if(i==n) return 1;
        if(dp[i][a][l] != -1) return dp[i][a][l];
        ll ans = rec(i+1,a,0);
        if(a < 1){
            ans += rec(i+1,a+1,0);
        }
        if(l<2){
            ans += rec(i+1,a,l+1);
        }
        return dp[i][a][l] = ans%mod;
    }
    int checkRecord(int n1) {
        n = n1;
        memset(dp,-1,sizeof(dp));
        return rec(0,0,0);
    }
};
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
    ll n,k;
    string s;
    vector<vll> dp_pali;
    ll count(ll i, ll j){
        ll c=0;
        while(i < j){
            if(s[i] != s[j]) c++;
            i++;
            j--;
        }
        return c;
    }
    vector<vll> dp;
    ll rec(ll i, ll ct){
        if(i==n){
            if(ct == k) return 0;
            return 1e9;
        }
        if(dp[i][ct] != -1) return dp[i][ct];
        ll ans=1e9;
        for(ll j=i; j<n; j++){
            if(ct < k){
                ans = min(ans, dp_pali[i][j] + rec(j+1,ct+1));
            }
        }
        return dp[i][ct] = ans;
    }
    int palindromePartition(string s1, int k1) {
        s=s1;
        k=k1;
        n=s.size();
        dp_pali.resize(n, vll(n));
        dp.assign(n, vll(k, -1));
        fr(i,n){
            fr(j,n){
                dp_pali[i][j] = count(i,j);
            }
        }
        return rec(0,0);
    }
};
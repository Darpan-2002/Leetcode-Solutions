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
    ll n, ans;
    map<ll,ll> mp;
    void rec(ll i, vector<int>& a, int k){
        if(i==n){
            ans++;
            return;
        }
        rec(i+1,a,k);
        if(mp[abs(a[i]-k)] == 0){
            mp[a[i]]++;
            rec(i+1,a,k);
            mp[a[i]]--;
        }
    }
    int beautifulSubsets(vector<int>& a, int k) {
        sort(all(a));
        ans=0;
        rec(0,a,k);
        return ans-1;
    }
};

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
    map<ll,map<ll,ll>> freq;
    vector<ll> dp;
    ll rec(ll i, ll si, vpair& vp, ll k){
        if(i==si) return 1;
        if(dp[i] != -1) return dp[i];
        ll skip = rec(i+1,si,vp,k);
        ll take = (1 << vp[i].second) - 1;
        if(i+1 < si && vp[i+1].first-vp[i].first==k){
            take *= rec(i+2,si,vp,k);
        }
        else
        {
            take *= rec(i+1,si,vp,k);
        }
        return dp[i] = skip+take;
    }
    int beautifulSubsets(vector<int>& a, int k) {
        ll n = a.size();
        fr(i,n){
            freq[a[i]%k][a[i]]++;
        }
        ll ans=1;
        for(auto it:freq){
            vpair vp(it.second.begin(), it.second.end());
            dp.assign(vp.size(), -1);
            ans *= rec(0,vp.size(),vp,k);
        }
        return ans-1;
    }
};
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
    map<pair<ll,ll>, ll> mp;
    ll rec(ll x, ll jump, ll k){
        if(x>k) return 0;
        if(mp.find({x,jump}) != mp.end()) return mp[{x,jump}];
        int ct=0;
        if(x==k) ct=1;
        ct += rec(x+ (1LL << jump), jump+1, k);
        ct += rec(x+ (1LL << jump) - 1, jump+1, k);
        return mp[{x,jump}] = ct;
    }
    int waysToReachStair(int k) {
        return rec(1,0,k) + rec(0,0,k);
    }
};
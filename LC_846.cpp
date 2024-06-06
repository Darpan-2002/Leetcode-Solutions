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
    bool isNStraightHand(vector<int>& a, int g) {
        ll n=a.size();
        if(n % g) return 0;
        map<ll, ll> mp;
        fr(i,n){
            mp[a[i]]++;
        }
        for(auto it:mp){
            if(it.second > 0){
                ll x = it.first;
                for(ll i=x; i<x+g; i++){
                    if(mp[i] < it.second) return 0;
                    mp[i] -= it.second;
                }
            }
        }
        return 1;
    }
};
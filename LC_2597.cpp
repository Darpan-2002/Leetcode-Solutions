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
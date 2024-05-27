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
    ll check(ll mid, vector<int>& a){
        ll ct=0;
        fr(i,n){
            if(a[i] >= mid) ct++;
        }
        return ct;
    }
    int specialArray(vector<int>& a) {
        n = a.size();
        ll lo=0, hi=n;
        ll ans=-1;
        while(lo <= hi){
            ll mid = (lo + hi)/2;
            if(check(mid,a) >= mid){
                if(check(mid,a) == mid) ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};
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
    ll n, med;
    bool check(ll mid, vector<int>& a){
        ll ct = 0, uni=0, f=0;
        ll head=-1, tail=0;
        unordered_map<ll, ll> mp;
        while(tail < n){
            while(head+1<n && (uni + ((mp[a[head+1]] == 0) ? 1:0) ) <= mid){
                head++;
                mp[a[head]]++;
                if(mp[a[head]]==1) uni++;
                if(uni==mid) f=1;
                // if(mid==2) cout<<uni<<" "<<head<<" "<<tail<<nn;;
            }
            ct += (head-tail+1);
            if(ct > med) return 1;
            // if(mid==2) cout<<head<<" "<<tail<<nn;
            mp[a[tail]]--;
            if(mp[a[tail]]==0) uni--;
            tail++;
        }
        if(f) ct--;
        // cout<<nn;
        // cout<<mid<<" "<<ct<<nn;
        return ct >= med;
    }
    int medianOfUniquenessArray(vector<int>& a) {
        n=a.size();
        med = n*(n+1)/2;
        med = (med-1)/2;
        // cout<<med<<nn;
        ll lo=1, hi=n;
        ll ans=-1;
        while(lo <= hi){
            ll mid = (lo+hi)/2;
            if(check(mid,a)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};
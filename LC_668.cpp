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
    ll n,m,k;
    ll check(ll mid){
        ll ct=0, f=0;
        fr(i,n){
            if(mid % (i+1) == 0){
                if(mid/(i+1) <= m) f++;
            }
            ll x = mid/(i+1);
            ct += min(x,m);
        }
        ct -= f;
        return ct;
    }
    int findKthNumber(int n1, int m1, int k1) {
        n=n1, m=m1, k=k1;
        ll lo=1, hi=n*m;
        ll ans=0;
        while(lo <= hi){
            ll mid = (lo+hi)/2;
            if(check(mid) < k){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        } 
        while(1){
            ll tm=0;
            fr(i,n){
                if(ans%(i+1)==0 && ans/(i+1) <= m) tm++;
                if(tm > 1) return ans;
            }
            if(tm==1){
                if(check(ans) == k-1) return ans;
            }
            ans++;
        }
        return ans;
    }
};
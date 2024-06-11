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
    ll n;
    vll a;
    int dp[501][502][26];
    ll rec(ll i, ll pre, ll ct){
        if(i==n) return 0;
        if(dp[i][pre][ct] != -1) return dp[i][pre][ct];
        ll ans = rec(i+1,pre,ct);
        if(pre==n || a[i]==a[pre]){
            ans = max(ans, 1+rec(i+1,i,ct));
        }
        if(pre!=n && a[i]!=a[pre] && ct){
            ans = max(ans, 1+rec(i+1,i,ct-1));
        }
        return dp[i][pre][ct] = ans;
    }
    int maximumLength(vector<int>& nums, int k) {
        n = nums.size();
        fr(i,n){
            a.push_back(nums[i]);
        }
        memset(dp,-1,sizeof(dp));
        return rec(0,n,k);
    }
};
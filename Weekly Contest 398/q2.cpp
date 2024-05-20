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
    vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& q) {
        ll n=a.size();
        vll ps(n,0), v;
        set<ll> s;
        fr(i,n-1){
            if(a[i]%2 == a[i+1]%2){
                ps[i]=1;
                v.pb(i);
                s.insert(i);
            }
        }
        // cout<<v.size()<<"    ";
        // print(v);
        vector<bool> ans(q.size(),1);
        if(v.size()==0) return ans;
        fr(i,q.size()){
            if(q[i][0]==q[i][1]) continue;
            if(s.find(q[i][0]) != s.end()){
                ans[i] = 0;
                continue;
            }
            ll ind = lower_bound(all(v), q[i][0]) - v.begin();
            // cout<<ind<<" ";
            if(ind==v.size()) continue;
            if(v[ind] < q[i][1]) ans[i] = 0;
        }
        // ll ind = lower_bound(all(v), 4) - v.begin();
        // cout<<ind<<" ";
        // cout<<nn;
        return ans;
    }
};
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
    vector<vll> adj;
    vll deg;
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& e) {
        adj.resize(n);
        deg.assign(n,0);
        for(auto it:e){
            adj[it[0]].pb(it[1]);
            deg[it[1]]++;
        }
        queue<ll> q;
        fr(i,n){
            if(deg[i] == 0) q.push(i);
        }
        vector<set<ll>> ans(n);
        while(!q.empty()){
            ll node = q.front();
            q.pop();
            for(auto it:adj[node]){
                for(auto it1:ans[node]){
                    ans[it].insert(it1);
                }
                ans[it].insert(node);
                deg[it]--;
                if(deg[it] == 0) q.push(it);
            }
        }
        vector<vector<int>> ans1(n);
        fr(i,n){
            for(auto it:ans[i]){
                ans1[i].pb(it);
            }
        }
        return ans1;
    }
};
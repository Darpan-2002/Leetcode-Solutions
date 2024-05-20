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
    vector<vll> adj;
    vll vis, ans;
    vector<vll> dfs(ll node, vector<int>& c){
        vis[node] = 1;
        vll maxi(3,-1e9), mini(3,1e9);

        for(auto it:adj[node]){
            if(vis[it]) continue;
            vector<vll> tmp = dfs(it,c);
            vll pos(6), neg(6);
            pos[0] = tmp[0][0];
            pos[1] = tmp[0][1];
            pos[2] = tmp[0][2];
            pos[3] = maxi[0];
            pos[4] = maxi[1];
            pos[5] = maxi[2];

            neg[0] = tmp[1][0];
            neg[1] = tmp[1][1];
            neg[2] = tmp[1][2];
            neg[3] = mini[0];
            neg[4] = mini[1];
            neg[5] = mini[2];

            sort(all(pos));
            reverse(all(pos));
            sort(all(neg));

            maxi[0]=pos[0];
            maxi[1]=pos[1];
            maxi[2]=pos[2];

            mini[0]=neg[0];
            mini[1]=neg[1];
            mini[2]=neg[2];
        }
        if(c[node] > maxi[2]) maxi[2]=c[node];
        sort(all(maxi));
        reverse(all(maxi));

        if(c[node] < mini[2]) mini[2]=c[node];
        sort(all(mini));
        if(maxi[2] == -1e9){
            ans[node] = 1;
        }
        else
        {
            ll p = maxi[0]*maxi[1]*maxi[2];
            ll q = mini[0]*mini[1]*maxi[0];
            p = max(p,q);
            if(p<0) ans[node] = 0;
            else ans[node] = p;
        }
        vector<vll> t;
        t.pb(maxi);
        t.pb(mini);
        return t;
    }
    vector<long long> placedCoins(vector<vector<int>>& e, vector<int>& c) {
        n=e.size()+1;
        adj.resize(n);
        fr(i,n-1){
            adj[e[i][0]].pb(e[i][1]);
            adj[e[i][1]].pb(e[i][0]);
        }
        vis.assign(n,0);
        ans.resize(n);
        dfs(0,c);
        return ans;
    }
};
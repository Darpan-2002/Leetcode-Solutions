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
    ll n,m;
    ll dx[4] = {1,0,-1,0};
    ll dy[4] = {0,-1,0,1};
    int shortestPathAllKeys(vector<string>& grid) {
        n = grid.size(), m=grid[0].size();
        ll key_ct=0;
        queue<pair<set<ll>,pair<ll,ll>>> q;
        map<pair<set<ll>,pair<ll,ll>>, ll> vis;
        fr(i,n){
            fr(j,m){
                if(grid[i][j] == '@'){
                    q.push({{},{i,j}});
                    vis[{{},{i,j}}] = 1;
                }
                if(grid[i][j]>='a' && grid[i][j]<='z'){
                    key_ct++;
                }
            }
        }
        ll ans=0;
        while(!q.empty()){
            ll si = q.size();
            fr(i,si){
                auto it = q.front();
                q.pop();
                set<ll> key=it.first;
                ll x=it.second.first, y=it.second.second;
                if(grid[x][y]>='a' && grid[x][y]<='z'){
                    key.insert(grid[x][y]);
                }
                if(key.size() == key_ct) return ans;
                fr(k,4){
                    ll nx=x+dx[k], ny=y+dy[k];
                    if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                    if(grid[nx][ny] == '#') continue;
                    if(grid[nx][ny]>='A' && grid[nx][ny]<='Z' && key.find(tolower(grid[nx][ny])) == key.end()) continue;
                    if(vis[{key,{nx,ny}}] == 0){
                        vis[{key,{nx,ny}}] == 1;
                        q.push({key, {nx,ny}});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};
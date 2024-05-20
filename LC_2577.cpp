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
    vector<vll> dis;
    ll dx[4] = {1,0,-1,0};
    ll dy[4] = {0,-1,0,1};
    void bfs(vector<vector<int>>& g){
        ll time=0;
        priority_queue<pair<ll, pair<ll,ll>>> pq;
        pq.push({0,{0,0}});
        dis[0][0] = 0;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            ll d=-1*it.first;
            ll x=it.second.first, y=it.second.second;
            fr(k,4){
                ll nx=x+dx[k], ny=y+dy[k];
                if(nx<0 || ny<0 || nx>=n || ny>=m) continue;
                ll wait = g[nx][ny] - dis[x][y];
                if(wait<0) wait=0;
                if(wait%2==0) wait++;
                if(dis[nx][ny] > wait+dis[x][y]){
                    dis[nx][ny] = wait+dis[x][y];
                    pq.push({-dis[nx][ny], {nx,ny}});
                }
            }
        }
    }
    int minimumTime(vector<vector<int>>& g) {
        n=g.size(), m=g[0].size();
        if(g[0][1]>1 && g[1][0]>1) return -1;
        dis.assign(n, vll(m,1e9));
        return dis[n-1][m-1];
    }
};
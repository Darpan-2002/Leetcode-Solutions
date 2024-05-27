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
#define print(v) fr(i,v.size()) cout<<v[i]<<" ";
const ll mod = 1e9+7; 
    ll m;
    vpair vp;
    int mostBooked(int n, vector<vector<int>>& mt) {
        m=mt.size();
        fr(i,m){
            vp.push_back({mt[i][0], mt[i][1]});
        }
        sort(all(vp));
        // fr(i,m){
        //     cout<<vp[i].first<<" "<<vp[i].second<<nn;
        // }
        // cout<<nn<<nn;
        vll use(n,0), room(n,0);
        priority_queue<pair<ll, ll>> pq;
        set<ll> free;
        fr(i,n){
            free.insert(i);
        }
        fr(j,m){
            ll s=vp[j].ff, e=vp[j].ss;
            while(!pq.empty() && (-pq.top().first) <= s){
                free.insert(-pq.top().second);
                pq.pop();
            }
            if(free.size() == 0){
                auto i=pq.top();
                free.insert(-i.second);
                e = e - s - i.first; 
                pq.pop();
            }
            cout<<e<<" ";
            auto ind = *free.begin();
            cout<<ind<<nn;
            room[ind]++;
            free.erase(ind);
            pq.push({-e,-ind});
        }
        ll ans=-1, mini=-1;
        fr(i,n){
            // cout<<room[i]<<" ";
            if(room[i] > mini){
                ans=i;
                mini = room[i];
            }
        }
        return ans;
    }
};
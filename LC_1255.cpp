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
    vll sc;
    ll rec(ll i, vector<string>& w, map<char, ll> mp){
        if(i==n){
            return 0;
        }
        ll ans = rec(i+1, w, mp);
        ll tm=0, f=1;
        fr(j,w[i].size()){
            if(mp[w[i][j]] == 0){
                f=0;
                break;
            }
            else
            {
                mp[w[i][j]]--;
                tm += sc[w[i][j]-'a'];
            }
        }
        if(f){
            ans = max(ans, tm + rec(i+1,w, mp));
        }
        return ans;
    }
    int maxScoreWords(vector<string>& w, vector<char>& l, vector<int>& sc1) {
        n = w.size(), m=l.size();
        map<char, ll> mp;
        fr(i,m){
            mp[l[i]]++;
        }
        fr(i,26){
            sc.pb(sc1[i]);
        }
        return rec(0,w,mp);
    }
};
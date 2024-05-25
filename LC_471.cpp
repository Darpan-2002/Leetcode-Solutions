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
    string s;
    set<string> word;
    bool f=0;
    set<pair<ll, string>> dp;
    void rec(ll i, string cur, ll ct){
        if(i==n){
            if(word.find(cur) != word.end()){
                if(ct) f=1;
            }
            return;
        }
        if(dp.find({i,cur}) != dp.end()) return;
        rec(i+1, cur+s[i], ct);
        if(word.find(cur) != word.end()){
            string tm="";
            tm += s[i];
            rec(i+1, tm, ct+1);
        }
        dp.insert({i,cur});
    }
    bool wordBreak(string s1) {
        s=s1;
        n=s.size();
        f=0;
        rec(0,"",0);
        return f;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& w) {
        m=w.size();
        fr(i,m){
            word.insert(w[i]);
        }
        vector<string> ans;
        fr(i,m){
            if(wordBreak(w[i])) ans.push_back(w[i]);
            dp.clear();
        }
        return ans;
    }
};
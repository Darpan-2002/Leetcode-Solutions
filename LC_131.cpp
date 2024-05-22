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
    string s;
    vector<vector<string>> ans;
    vector<string> tm;
    bool is_pali(ll i, ll j){
        while(i < j){
            if(s[i] != s[j]) return 0;
            i++;
            j--;
        }
        return 1;
    }
    void rec(ll i){
        if(i>=n){
            ans.push_back(tm);
        }
        for(ll j=i; j<n; j++){
            if(is_pali(i,j)){
                tm.push_back(s.substr(i,j-i+1));
                rec(j+1);
                tm.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s1) {
        s=s1;
        n=s.size();
        rec(0);
        return ans;
    }
};
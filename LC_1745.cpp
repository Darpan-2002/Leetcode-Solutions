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
    vector<vll> pali;
    vll dp;
    bool is_palindrome(ll i, ll j){
        if(pali[i][j] != -1) return pali[i][j];
        while(i < j){
            if(s[i] != s[j]){
                return pali[i][j] = 0;
            }
            i++;
            j--;
        }
        return pali[i][j] = 1;
    }
    bool ans=0;
    void rec(ll i, ll ct){
        if(i==n) return;
        if(ct==2){
            if(is_palindrome(i,n-1)) ans=1;
            return;
        }
        if(dp[i] != -1) return;
    
        for(ll j=i; j<n; j++){
            if(is_palindrome(i,j)){
                rec(j+1,ct+1);
            }
        }
        dp[i] = 1;
        return;
    }
    bool checkPartitioning(string s1) {
        s = s1;
        n = s.size();
        pali.assign(n, vll(n, -1));
        dp.assign(n, -1);
        rec(0,0);
        return ans;
    }
};
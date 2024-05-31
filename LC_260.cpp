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
    vector<int> singleNumber(vector<int>& a) {
        ll n=a.size();
        ll x = 0;
        fr(i,n){
            x ^= a[i];
        }
        int pos=0;
        while((x & (1<<pos)) == 0){
            pos++;
        }
        int ans1=0, ans2=0;
        fr(i,n){
            if(a[i] & (1<<pos)) ans1 ^= a[i];
            else ans2 ^= a[i];
        }
        return {ans1, ans2};
    }
};
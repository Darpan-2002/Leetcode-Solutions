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
    long long sumDigitDifferences(vector<int>& a) {
        ll n=a.size();
        vector<vll> v(n);
        fr(i,n){
            ll x=a[i], j=0;
            while(j<11){
                v[i].push_back(a[i]%10);
                a[i] /= 10;
                j++;
            }
        }
        // fr(i,v.size()){
        //     // sort(all(v[i]));
        //     fr(j,v[i].size()){
        //         cout<<v[i][j]<<" ";
        //     }
        //     cout<<nn;
        // }
        ll ans=0;
        fr(i,11){
            vll tm;
            fr(j,n){
                tm.push_back(v[j][i]);
            }
            sort(all(tm));
            // print(tm);
            vll t;
            ll ct=1;
            fr(k,tm.size()-1){
                if(tm[k] == tm[k+1]) ct++;
                else
                {
                    t.push_back(ct);
                    ct = 1;
                }
                
                if(k==tm.size()-2) t.push_back(ct);
            }
            // print(t);
            // cout<<nn;
            ct=0;
            fr(k,t.size()){
                ans += ct*t[k];
                ct += t[k];
            }
        }
        return ans;
    }
};
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
    int equalSubstring(string s, string t, int cost) {
        n=s.size();
        ll ans=0;
        ll head=-1, tail=0;
        ll c=0;
        while(tail<0){
            while(head+1<n && (c + abs(t[head+1]-s[head+1])) <= cost){
                head++;
                c += abs(t[head] - s[head]);
            }
            ans = max(ans, head-tail+1);
            if(head < tail){
                tail++;
                head = tail-1;
            }
            else
            {
                c -= abs(t[tail] - s[tail]);
                tail++;
            }
        }
        return ans;
    }
};
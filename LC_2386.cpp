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
    long long kSum(vector<int>& nums, int k) {
        ll n=nums.size();
        ll sum=0;
        fr(i,n){
            if(nums[i] >= 0) sum += nums[i];
            nums[i] = abs(nums[i]);
        }
        priority_queue<pair<ll,ll>> pq;
        pq.push({sum,0});
        while(1){
            pair<ll,ll> it;
            sum = it.first;
            ll ind = it.second;
            if(k==1){
                return sum;
            }
            k--;
            pq.push({sum-nums[ind],ind+1});
            if(ind>0){
                pq.push({sum-nums[ind]+nums[ind-1],ind+1});
            }
        }
        return 0;
    }
};
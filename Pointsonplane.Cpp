#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<long long,long long> Container;
const int sz = 1e6+10;
const int mod = 1e9 + 7;
int n,k,m,q,dis,lim;
ll timer=1;
long long dp[sz];
long long trs[sz];
long long res[sz];
pair<int,pair<long long,long long>>a[sz];
long long b[sz];
vector<int>adj[sz];
bool cmp(pair<int,pair<long long,long long>>&a,pair<int,pair<long long,long long>>&b){
     if(a.second.first == b.second.first){
          if(a.second.first % 2 == 0) return a.second.second < b.second.second;
          else return a.second.second > b.second.second;
     }
     else return a.second.first < b.second.first;     
}
int main(){
       scanf("%d",&n);
       map<pair<long long,long long>,int>mp;
       for(int i = 1; i <= n; i++){
            scanf("%lld%lld",&a[i].second.first,&a[i].second.second);
            a[i].first = i; 
            a[i].second.first = a[i].second.first / 1000;
       }
       sort(a + 1, a + n + 1,cmp);
       for(int i = 1; i <= n; i++) printf("%d ",a[i].first);
} 

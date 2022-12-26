#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef map<long long,long long> Container;
const int sz = 5e5 + 10;
const int sq = 721;
const int mod = 1e9 + 7;
int n,k,m,q,dis,lim;
long long a[sz];
long long dp[sq][sq];
vector<int>adj[sz];
int main(){
     scanf("%d",&n); 
     for(int i = 1; i <= n; i++){
           int t,x,y;
           scanf("%d%d%d",&t,&x,&y);
           if(t == 1){
               a[x]+=y;
               for(int j = 1; j < sq; j++){
                    dp[j][x % j] += y;
               }
           }
           else{
               long long ans = 0;
               if(x > sq){
                    for(int j = y; j <= sz; j += x){
                         ans+=a[j];
                    }
               }
               else ans = dp[x][y];
               cout<<ans<<endl;
           }
     }
} 

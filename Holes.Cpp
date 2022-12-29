#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz =2e5+10;
const int ssz=5e3+1;
const int mod=1e9+7;
long long p,n,q,timer,m;
long long lb,rb; 
queue<int>qe;
int cnt[sz];
int nxt[sz];
int cur[sz];
int a[sz];
int block;
void upd(int a,int b){
    if(b > n){
        nxt[a] = n + 1;
        cur[a] = a;
        cnt[a] = 1;
        return;
    } 
    if(a/block ==  b/block){
        nxt[a] = nxt[b];
        cur[a] = cur[b]; 
        cnt[a] = cnt[b] + 1;
    }
    else{
        nxt[a] = b;
        cur[a] = a;
        cnt[a] = 1;
    }
}
int main(){
     scanf("%d%d",&n,&q);
     block = ceil(sqrt(n));
     for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
     for(int i = n; i > 0; i--) upd(i, i + a[i]);
     for(int i = 1; i <= q; i++){
          int t; scanf("%d",&t);
          if(!t){
               int x,y;
               scanf("%d%d",&x,&y);
               a[x] = y;
               for(int i = x; i > 0 and i/block == x/block ;i--) upd(i,i + a[i]);
          }
          else{
              int x; 
              scanf("%d",&x);
              int pos = x; 
              int val = cur[pos];
              int ans = cnt[pos];
              while(true){
                  pos = nxt[pos];    
                  if(pos > n) break; 
                  ans += cnt[pos];
                  val = cur[pos];              
              }
              printf("%d %d\n",val,ans); 
          }
     }
} 

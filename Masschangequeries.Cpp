#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz =2e5+10;
const int ssz=5e3+1;
const int mod=1e9+7;
long long p,n,q,timer,m,cnt;
long long lb,rb; 
queue<int>qe;
int ans[sz];
int lf[sz],rt[sz];
int lc[sz*100],rc[sz*100];
int cap[sz*100]; 
int val[sz];
int fa[sz];
void upd(int pos,int &root,int l = 1,int r = n){
      if(!root) root = ++cnt;
      if(l == r){
           cap[root]++;
           return;
      }
      int mid = (l + r)>>1;
      if(pos <= mid) upd(pos,lc[root],l,mid);
      else upd(pos,rc[root],mid + 1,r);
}
int merge(int roota, int rootb){
     if(!roota or !rootb) return roota + rootb;
     lc[roota] = merge(lc[roota],lc[rootb]);
     rc[roota] = merge(rc[roota],rc[rootb]);
     cap[roota] += cap[rootb];
     cap[rootb] = 0; 
     return roota;
}
void change(int L, int R, int &roota, int &rootb,int l = 1, int r = n){
     if(L > r or R < l) return; 
     if(!roota) roota = ++cnt;
     if(L <= l and r <= R){
           roota = merge(roota, rootb);
           rootb = 0;
           return; 
     }
     int mid = (l + r)>>1;
     change(L,R,lc[roota],lc[rootb],l,mid);
     change(L,R,rc[roota],rc[rootb],mid + 1,r);
}
void dfs(int val, int &root, int l = 1, int r = n){
     if(l == r){
         if(cap[root]) ans[l] = val;
         return;
     }
     int mid = (l + r)>>1;
     dfs(val,lc[root],l,mid);
     dfs(val,rc[root],mid + 1,r);
}
int main(){
     scanf("%d",&n);
     for(int i = 1; i <= n; i++){
          int x; scanf("%d",&x);
          upd(i,fa[x]);
     }
     scanf("%d",&q);
     for(int i = 1; i <= q; i++){
          int l,r,x,y;
          scanf("%d%d%d%d",&l,&r,&x,&y);
          if(x == y) continue;
          change(l,r,fa[y],fa[x]);
     } 
     for(int i = 1; i <= 100; i++) dfs(i,fa[i]);
     for(int i = 1; i <= n; i++) printf("%d ",ans[i]);
} 

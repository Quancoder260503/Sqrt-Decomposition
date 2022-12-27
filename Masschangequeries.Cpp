#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz =2e5+1;
const int ssz=5e3+1;
const int mod=1e9+7;
int p,n,q,timer,m;
queue<int>qe;
int ans[sz];
int cnt[sz*20]; 
int lf[sz*20];
int rt[sz*20];
int fa[sz];
void upd(int L,int &root,int l = 1, int r = n){
       if(!root){
           root = qe.front(); qe.pop();
           lf[root] = rt[root] = cnt[root] = 0; 
       }
       if(l == r){
             cnt[root]++;
             return;
       }
       int mid = (l + r) >> 1;
       if(L <= mid) upd(L,lf[root],l,mid);
       else upd(L,rt[root],mid + 1,r);
}
int merge(int roota,int rootb){
     if(!roota or !rootb) return roota + rootb; 
     lf[roota] = merge(lf[roota],lf[rootb]);
     rt[roota] = merge(rt[roota],rt[rootb]);
     cnt[roota]+= cnt[rootb];
     qe.push(rootb);
     return roota;
}
void change(int L, int R, int l,int r , int &roota, int &rootb){
      if(!roota){
            roota = qe.front(); qe.pop();
            lf[roota] = rt[roota] = cnt[roota] = 0;
      }
      if(L <= l and r <= R){
            roota = merge(roota,rootb);
            rootb = 0;
            return;
      }
      int mid = (l + r)>>1;
      if(L <= mid) change(L,R,l,mid,lf[roota],lf[rootb]);
      if(mid < R)  change(L,R,mid + 1,r,rt[roota],rt[rootb]);
}
void dfs(int idx,int val,int l = 1,int r = n){
      if(l == r){
           if(cnt[idx]) ans[l] = val;
           return; 
      }
      int mid = (l + r)>>1;
      dfs(lf[idx],val,l,mid);
      dfs(rt[idx],val,mid + 1,r);
}
int main(){
      scanf("%d",&n);
      for(int i = 1; i < sz * 20; i++) qe.push(i);
      for(int i = 1; i <= n; i++){
           int x; scanf("%d",&x);
           upd(i,fa[x]);
      } 
      scanf("%d",&q);
      for(int i = 1; i <= q; i++){
          int x,y,l,r; scanf("%d%d%d%d",&l,&r,&x,&y);
          if(x == y) continue;
          change(l,r,1,n,fa[y],fa[x]);
      }
      for(int i = 1; i <= 100; i++) dfs(fa[i],i);
      for(int i = 1; i <= n; i++) printf("%d ",ans[i]); 
}

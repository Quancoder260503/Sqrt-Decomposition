#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int sz =1e6+10;
const int ssz=5e3+1;
const int mod=1e9+7;
long long p,n,q,timer,m,cnt;
long long lb,rb; 
queue<int>qe;
int lf[sz],rt[sz];
int lc[sz*40],rc[sz*40];
int cap[sz*40]; 
int val[sz];
int fa[sz];
void read(int &now){
     now = ++cnt;
     scanf("%d",&val[now]);
     if(!val[now]){
         read(lf[now]);
         read(rt[now]); 
     }
}
void upd(int pos,int &num,int l = 1, int r = n){
     if(!num) num = ++timer;
     cap[num] = 1;
     if(l == r) return; 
     int mid = (l + r)>>1;
     if(pos <= mid) upd(pos,lc[num],l,mid);
     else upd(pos,rc[num],mid + 1, r);
}
int merge(int roota, int rootb){
    if(!roota or !rootb) return roota + rootb;
    cap[roota]+=cap[rootb];
    lb += (long long) cap[rc[rootb]] * cap[lc[roota]];
    rb += (long long) cap[rc[roota]] * cap[lc[rootb]]; 
    lc[roota] = merge(lc[roota],lc[rootb]);
    rc[roota] = merge(rc[roota],rc[rootb]);
    return roota;
}
long long dfs(int u){
     long long res = 0;
     if(!val[u]){
          res = dfs(lf[u]) + dfs(rt[u]);
          lb = rb = 0;
          fa[u] = merge(fa[lf[u]],fa[rt[u]]);
          res = res + min(lb,rb);
     }
     else upd(val[u],fa[u]);
     return res; 
}
int main(){
      scanf("%d",&n);
      int root;
      read(root);
      long long res = dfs(root);  
      cout<<res<<endl;
} 

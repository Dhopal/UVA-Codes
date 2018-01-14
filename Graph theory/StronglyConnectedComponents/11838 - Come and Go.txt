#include <bits/stdc++.h>
using namespace std;
#define N 2005
#define pb push_back

typedef vector<int> vi;

int n,m;
int used[N];
vi g[N], gr[N];
vi order;

void dfs1(int x){ //cout<<x<<" ";
  used[x] = 1;
  for(int i = 0; i < g[x].size(); i++){
    if(used[g[x][i]] == 0)dfs1(g[x][i]);
  }
  order.pb(x);
}

void dfs2(int x){
  used[x] = 1;
  for(int i = 0; i < gr[x].size(); i++){
    if(used[gr[x][i]] == 0)dfs2(gr[x][i]);
  }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);

while(1){
  cin >> n >> m ; if(n+m==0) break;
  for(int i = 0; i < N; i++){
    g[i].clear();  gr[i].clear();  used[i] = 0; 
  }
  order.clear();
  for(int i = 0; i < m; i++){
    int u, v, p; 
    cin >> u >> v >> p;
    g[u].pb(v);
    gr[v].pb(u);
    if(p == 2){
      g[v].pb(u);
      gr[u].pb(v);
    }
  }
  int scc = 0; //dfs1(1);
  for(int i = 1; i <= n; i++)
    if(used[i] == 0)dfs1(i);
    
  memset(used, 0, sizeof used);

  for(int i = 0; i < n; i++){
    int x = order[n-1-i];
    if(used[x] == 0){
      scc++;
      dfs2(x);
      if(scc >= 2)break;
    }
  }
  cout << (scc == 1 ? 1 : 0) << '\n';
  
}
return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define N 100005
#define pb push_back

typedef vector<int> vi;

int n,m;
int used[N];
vi g[N], gr[N];
vi order;


void dfs1(int x){
  used[x] = 1;
  for(int i = 0; i < g[x].size(); i++){
    int y = g[x][i];
    if(used[y] == 0)dfs1(y);
  }
  order.pb(x);
}

set<int> comp;
void dfs2(int x){
  used[x] = 1;
  comp.insert(x);
  for(int i = 0; i < gr[x].size(); i++){
    int y = gr[x][i];
    if(used[y] == 0)dfs2(y);
  }
}


int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
int T, t = 0;
cin >> T;
while(T--){
  t++;
  cin >> n >> m;
  for(int i = 0; i < N; i++){
    g[i].clear(); gr[i].clear(); used[i] = 0; comp.clear(); order.clear();
  }
  for(int i = 0; i < m; i++){
    int u, v; cin >> u >> v;
    g[u].pb(v);
    gr[v].pb(u);
  }
  for(int i = 1; i <= n; i++)
    if(used[i] == 0){
      dfs1(i);
    }
  for(int i = 0; i < N; i++){
    used[i] = 0;
  }

  int ans = 0;
  for(int i = 0; i < n; i++){
    int v = order[n-1-i];
    if(used[v] == 0){
      comp.clear();
      dfs2(v);
      bool pk = 1;
      set<int> :: iterator it = comp.begin();
      while(it != comp.end()){
        int x = *it; 
        bool ok = 1;
        for(int j = 0; j < gr[x].size(); j++){
          int y = gr[x][j];
          if(comp.find(y) == comp.end()){
            ok = 0; break;
          }
        }
        if(!ok){
          pk = 0; break;
        }
        it++;
      }

      if(pk){
        ans++;
      }
    }
  }
 cout << ans << '\n';
}
return 0;
}
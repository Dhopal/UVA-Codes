#include <bits/stdc++.h>
using namespace std;

const int N=205;
int n,m;
vector<int> g[N];
int color[N];
set<int> edge[N];

int paint[2];
int notbicol;
void dfs(int x, int par, int last){ //cout<<x<<" "<<!last<<endl;
  if(color[x] != -1){ //cout<<x<<endl;
    if(color[x] == last){
        notbicol = 1; return;
      }
        return;
  }
  color[x] = !last; paint[!last]++;
  for(int i = 0; i < g[x].size(); i++){
    int y = g[x][i]; if(y == par) continue;
    dfs(y, x, !last);
  }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);

int t; cin >> t;
while(t--){
  cin >> n >> m;
  for(int i = 0; i < N; i++){
    g[i].clear();
    edge[i].clear();
    color[i] = -1;
  }
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y; //if(x==y)continue;
    if(edge[x].find(y) == edge[x].end()){
      g[x].push_back(y);
        g[y].push_back(x);
        edge[x].insert(y);
        edge[y].insert(x);
      }
  }
  int ans=0;
  for(int i = 0; i < n; i++)
    if(color[i] == -1){
      notbicol=0;
      memset(paint,0,sizeof paint);
      dfs(i,-1,0);
      if(notbicol){
        ans=-1; break;
      }
      int x = min(paint[0],paint[1]);
      ans += max(1,x);
    }
  cout << ans << '\n';
}
return 0;
}
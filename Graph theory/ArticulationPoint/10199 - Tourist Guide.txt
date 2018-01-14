#include <bits/stdc++.h>
using namespace std;

const int cmx = 105;
vector<int> g[cmx];
int hascamera[cmx];
int seen[cmx];

int n, m;
int root;
int timer;
int dfs_num[cmx];
int dfs_low[cmx];
void cutvertex(int x, int p){
  dfs_num[x] = dfs_low[x] = ++timer;
  seen[x] = 1;
  int children = 0;
  for(int i = 0; i < g[x].size(); i++){
    int y = g[x][i];
    if(y == p)continue;
    if(seen[y] == 0){
      cutvertex(y, x);
      if(x == root)children++;
      dfs_low[x] = min(dfs_low[x], dfs_low[y]);
      if(dfs_low[y] >= dfs_num[x]){
        if(x == root){
          if(children > 1)hascamera[x] = 1; continue;
        }
        hascamera[x] = 1;
      }
    }
    else{
      dfs_low[x] = min(dfs_low[x], dfs_num[y]);
    }
  }
}

vector<string> ans[10000];

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
int t=0;
while(1){
 cin >> n; if(n == 0)break;  t++;
 set<string> s;
 for(int i = 0; i < n; i++){
  string t;
  cin >> t;
  s.insert(t);
 }
 map<string,int> id;
 map<int,string> rid;
 int idx = 0;
 set<string> :: iterator it = s.begin();
 while(it != s.end()){
  string x = *it;
  id[x] = idx; rid[idx] = x; idx++;
  it++;
 }
 
 for(int i = 0; i < cmx; i++){
  g[i].clear();
  timer = 0;
  seen[i] = 0;
  root = -1;
  dfs_num[i] = 0;
  dfs_low[i] = 0;
  hascamera[i] = 0;
 }
 cin >> m;
 for(int i = 0; i < m; i++){
  string x, y;
  cin >> x >> y;
  int u = id[x];
  int v = id[y];
  g[v].push_back(u);
  g[u].push_back(v);
 }
  for(int i = 0; i < n; i++)
    if(seen[i] == 0){
      root = i;
      cutvertex(i,-1);
    }
 
 for(int i = 0; i < n; i++)
  if(hascamera[i])ans[t].push_back(rid[i]);
 
}
for(int i = 1; i < t; i++){
  int c = ans[i].size();
  cout << "City map #"<<i<<": " << c << " camera(s) found\n";
  for(int j = 0; j < ans[i].size(); j++)cout << ans[i][j] << '\n';
  cout << '\n';
}
cout << "City map #"<<t<<": " << ans[t].size() << " camera(s) found\n";
for(int j = 0; j < ans[t].size(); j++)cout << ans[t][j] << '\n';
return 0;
}
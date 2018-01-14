#include <bits/stdc++.h>
using namespace std;

const int cmx = 10005;
vector<int> g[cmx];
int seen[cmx];

int root;
int n, m;
int timer;
int dfs_num[cmx];
int dfs_low[cmx];

int pigeonvalue[cmx];
void cutvertex(int x, int p){
  seen[x] = 1;
  dfs_low[x] = dfs_num[x] = ++timer;
  int children=0;
  for(int i = 0; i < g[x].size(); i++){
    int y = g[x][i]; if(y == p)continue;
    children++;
    if(!seen[y]){
      cutvertex(y, x);
      dfs_low[x] = min(dfs_low[x], dfs_low[y]);
      if(dfs_num[x] <= dfs_low[y]){
        if(x==root){
          if(children>1)pigeonvalue[x]++; continue;
        }
        pigeonvalue[x]++;
      }
    }
    else{
      dfs_low[x] = min(dfs_low[x], dfs_num[y]);
    }
  }
}
bool cmp(pair<int,int> &p1, pair<int,int> &p2){
  if(p1.first != p2.first) return p1.first > p2.first;
  return p1.second < p2.second;
}
void blank(){
  for(int i = 0; i < cmx; i++){
    g[i].clear();
    seen[i] = 0;
    dfs_low[i] = 0;
    dfs_num[i] = 0;
    pigeonvalue[i] = 0;
    timer=0;
  }
}
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
while(1){
  cin >> n >> m; if(n+m==0)break;
  blank();
  while(1){
    int x, y; cin >> x >> y;
    if(x == -1)break;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  root=0;
  cutvertex(0,-1);
  vector<pair<int,int> > ans;
   for(int i=0;i<n;i++)pigeonvalue[i]++;
  for(int i = 0; i < n; i++)
    ans.push_back(make_pair(pigeonvalue[i],i));
  sort(ans.begin(),ans.end(),cmp);
  for(int i = 0; i < m; i++)
    cout << ans[i].second << ' ' << ans[i].first << '\n';
  cout<<'\n';
}
// cin >> n >> m;
// for(int i = 0; i < m; i++){
//   int x, y;
//   cin >> x >> y;
//   g[x].push_back(y);
//   g[y].push_back(x);
// }
// cutvertex(0,-1); for(int i=0;i<n;i++)if(pigeonvalue[i] and i!=root)pigeonvalue[i]++;
// for(int i=0;i<n;i++)cout<<i<<" : "<<pigeonvalue[i] << endl;
return 0;
}
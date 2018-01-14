#include <bits/stdc++.h>
using namespace std;

const int cmx = 1005;
vector<int> g[cmx];
int seen[cmx];

int n, m;
int timer;
int dfs_num[cmx];
int dfs_low[cmx];

vector<pair<int,int> > ans;
set<pair<int,int> > exist;

void findbridges(int x, int p){// cout<<x<<endl;
  dfs_low[x] = dfs_num[x] = ++timer;
  seen[x] = 1;
  for(int i = 0; i < g[x].size(); i++){
    int y = g[x][i];
    if(y == p)continue;
    if(seen[y] == 0){
      findbridges(y,x);
      dfs_low[x] = min(dfs_low[x], dfs_low[y]);
      if(dfs_num[x] < dfs_low[y]){
         ans.push_back(make_pair(x,y)); //cout<<x<<"->"<<y<<endl;
         ans.push_back(make_pair(y,x));
      }
      else{
        ans.push_back(make_pair(x,y)); exist.insert(make_pair(x,y)); exist.insert(make_pair(y,x));
    }
    }
    else{
      dfs_low[x] = min(dfs_low[x], dfs_num[y]);
      if(exist.find(make_pair(x,y)) == exist.end() ){
        ans.push_back(make_pair(x,y));
        exist.insert(make_pair(x,y));
        exist.insert(make_pair(y,x));
      }
    }
  }
}

void blank(){
  for(int i = 0; i < cmx; i++){
    g[i].clear();
    exist.clear();
    seen[i] = 0;
    dfs_low[i] = 0;
    dfs_num[i] = 0;
    ans.clear();
    timer=0;
  }
}
int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
int t=0;
while(1){
  cin >> n >> m; if(n+m == 0)break; t++;
  blank();
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  findbridges(1,-1);
  cout << t << "\n\n";
  for(int i = 0; i < ans.size(); i++)
    cout << ans[i].first << ' ' << ans[i].second << '\n';
  cout << "#\n";
}
return 0;
}
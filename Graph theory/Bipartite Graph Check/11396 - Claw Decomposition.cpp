#include <bits/stdc++.h>
using namespace std;

const int N=305;
int n;
vector<int> g[N];
int color[N];


int notbicol;
void dfs(int x, int par){
  if(color[x] != -1){
    if(color[x] == color[par]){
        notbicol = 1; return;
      }
        return;
  }
  color[x] = color[par]==0?1:0; 
  for(int i = 0; i < g[x].size(); i++){
    int y = g[x][i]; if(y == par) continue;
    dfs(y, x);
  }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);

while(1){
  cin >> n; if(n == 0)break;
  for(int i = 0; i < N; i++){
    g[i].clear();
    color[i] = -1;
  }
  for(int i = 0; ; i++){
    int x, y;
    cin >> x >> y; if(x+y == 0)break;
    
      g[x].push_back(y);
      g[y].push_back(x);
  }
  
  for(int i = 1; i <= n; i++)
    if(color[i] == -1){ //cout<<"fuck";
      notbicol=0;
      dfs(i,0);
      if(notbicol){
        break;
      }
    }
  if(notbicol)cout << "NO\n";
  else cout << "YES\n";
}
return 0;
}
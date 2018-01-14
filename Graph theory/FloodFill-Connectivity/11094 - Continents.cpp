#include <bits/stdc++.h>
using namespace std;
const int N = 35;
char g[N][N];
int seen[N][N];
int n, m, a, b;
char l,w;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y){
  if(x < 0 or y < 0 or x >= n or y >= m or seen[x][y])return 0;
  return 1;
}

int dfs(int x, int y){
  int ret = 1;
  seen[x][y] = 1;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    ny = (ny + m) % m;
    if(ok(nx,ny) and g[nx][ny] == l)ret += dfs(nx,ny);
  }
  return ret;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin); freopen("b.txt","w",stdout);
while(cin >> n >> m){
for (int i = 0; i < n; ++i){
  for(int j = 0; j < m; j++){
    cin >> g[i][j];
  }
}
cin >> a >> b; 
l=g[a][b];
w='w';
for (int i = 0; i < n; ++i){
  for(int j = 0; j < m; j++){
    if(g[i][j]!=l)w=g[i][j];
  }
}
for(int i = 0; i < N; i++)for(int j = 0; j < N; j++)seen[i][j]=0;
dfs(a,b);
int ans = 0;
for(int i = 0; i < n; i++){
  for(int j = 0; j < m; j++){
    if(g[i][j] == l and seen[i][j] == 0){
      ans = max(ans, dfs(i,j));
    }
  }
}
cout << ans << '\n';
}
return 0;
}
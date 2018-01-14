#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 4;

int n, m, s;
char a[N];
char g[102][102];
int seen[102][102];

bool ok(int x, int y){
  if(x < 0 or y < 0 or x >= n or y >= m or g[x][y] == '#')return false;
  return true;
}

int ans;
#define F first
#define S second
pair<int,int> mov(int x, int y, char o){
  pair<int,int> ret;
  ret.F = x;
  ret.S = y;
  if(o == 'N' and ok(x - 1, y))ret.F = x - 1;
  if(o == 'S' and ok(x + 1, y))ret.F = x + 1;
  if(o == 'L' and ok(x, y + 1))ret.S = y + 1;
  if(o == 'O' and ok(x, y - 1))ret.S = y - 1;
  return ret;
}
char orien(char o, char ins){
  if(o == 'N'){
    if(ins == 'D')return 'L';
    if(ins == 'E')return 'O';
  }
  if(o == 'S'){
    if(ins == 'D')return 'O';
    if(ins == 'E')return 'L';
  }
  if(o == 'L'){
    if(ins == 'D')return 'S';
    if(ins == 'E')return 'N';
  }
  if(o == 'O'){
    if(ins == 'D')return 'N';
    if(ins == 'E')return 'S';
  }
}
void dfs(int x, int y, int pos, char o){
  if(g[x][y] == '*' and seen[x][y] == 0)ans++;
  seen[x][y] = 1;
  if(pos >= s)return;
  if(a[pos] == 'F'){
    pair<int, int> p = mov(x, y, o);
    dfs(p.F, p.S, pos+1, o);
    return;
  }
  dfs(x, y, pos+1, orien(o, a[pos]));
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //freopen("input.txt","r",stdin);

while(1){
cin >> n >> m >> s; if(n+m+s == 0)break;
int x,y;
for(int i = 0; i < n; i++)
  for(int j = 0; j < m; j++){
    cin >> g[i][j];
    if(g[i][j] != '*' and g[i][j] != '#' and g[i][j] != '.'){
      x = i;
      y = j;
    }
  }
 // cout<<x<<" "<<y<<endl;
  for(int i = 0; i < s; i++)
    cin >> a[i];

  for(int i = 0; i < 102; i++)
    for(int j = 0; j < 102; j++)
      seen[i][j] = 0;
  ans = 0;

  dfs(x, y, 0, g[x][y]);
  cout << ans << '\n';
}
return 0;
}
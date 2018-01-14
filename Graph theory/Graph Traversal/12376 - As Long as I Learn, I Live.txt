#include <bits/stdc++.h>
using namespace std;
const int N = 105;
vector<int> v[N];
int val[N];
int n, m, ans, final;

void dfs(int x){
  ans += val[x];
  if(x != 0 and v[x].size() == 0){
    final = x;
    return;
  }
  int y = -1, mx = 0;
  for(int i = 0; i < v[x].size(); i++)
    if(val[v[x][i]] > mx){
      mx = val[v[x][i]];
      y = v[x][i];
    }
  dfs(y);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);
int T = 0, t = 0;
cin >> t;
while(t--){
  T++; 
  cin >> n >> m;
  ans = 0;
  for(int i = 0; i < N; i++)v[i].clear();
  for(int i = 0; i < n; i++)
    cin >> val[i];
  for(int i = 0; i < m; i++){
    int x, y;
    cin >> x >> y;
    v[x].push_back(y);
  }
  dfs(0);
  cout << "Case "<< T << ": "<<ans << " " << final << '\n';
}
return 0;
}
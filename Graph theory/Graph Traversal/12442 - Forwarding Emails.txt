#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 4;

int n, t;
int seen[N];
vector<int> v[N];

int indeg[N];
bool on;

int id;
int cycle[N];
int color[N];
int cyc_sz[N];
set<int> cyl_nodes[N];

void dfs(int x, int y){ //cout<<x<<' ';
  if(color[x] == 2){
    return;
  }
  if(color[x] == 1){
    cycle[x] = id;
    cyl_nodes[id].insert(x);
    cyc_sz[id]++;
    on = true;
    return;
  }
  color[x] = 1;
  int u = v[x][0];
  dfs(u, x);
  if(cycle[u] > 0 and on == true){ //cout<<x<<" ->" << id<<endl;
    if(cycle[x] == 0 ){
      cycle[x] = id;
      cyl_nodes[id].insert(x);
      cyc_sz[id]++;
    }
    else { on = false; id++; }
  }
  color[x] = 2;
}

int dfs1(int x){
  int ret = 1;
  if(cycle[x] > 0)return cyc_sz[cycle[x]];
  ret += dfs1(v[x][0]);
  return ret;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //freopen("a.txt","r",stdin);
cin >> t; 
int T = 0;
while(t--){
  id = 1;
  memset(indeg, 0, sizeof indeg);
  memset(color, 0, sizeof color);
  memset(cycle, 0, sizeof cycle);
  memset(cyc_sz, 0, sizeof cyc_sz);
  for(int i = 0; i < N; i++)v[i].clear();
  for(int i = 0; i < N; i++)cyl_nodes[i].clear();

 T++;
 cin >> n;
 for(int i = 0; i < n; i++){
  int x, y;
  cin >> x >> y;
  v[x].push_back(y);
  indeg[y]++;
 }

vector<int> a;
 for(int i = 1; i <= n; i++)
  if(indeg[i] == 0)
    a.push_back(i);

 //for(int i=0;i<a.size();i++)cout<<a[i]<<' ';
//dfs(1,-1);
for(int i=0;i<a.size();i++){
  dfs(a[i],-1);
}
for(int i=1; i <=n; i++)if(color[i]==0)dfs(i,-1);

// for(int i = 1; i <= n; i++){
//   cout << i <<" : "<<cycle[i] << endl;
// }
// for(int i = 1; i < id; i++){
//   cout << i << " : " << cyc_sz[i] << endl;
// }
// set<int> :: iterator it;
// for(int i = 1; i < id; i++){
//   it = cyl_nodes[i].begin();
//   cout << i << " : ";
//   while(it != cyl_nodes[i].end()){
//     cout << (*it) << ' '; it++;
//   }
//   cout << endl;
// }
 
  int mx = 0;
  int ans = 1;
 
 for(int i = 0; i < a.size(); i++){
  int x = a[i];
  int big = dfs1(x); //cout<<a[i]<<"->"<<big<<endl;
 
  if(big >= mx){
    if(big == mx){
	if(ans > a[i])
	ans = a[i]; 
	mx = big;
   }
    else {
      ans = a[i];
      mx = big;
    }
  }
}
//cout<<mx<<endl;
//cout<<ans<<endl;
for(int i = 1; i < id; i++)
  if(cyc_sz[i] >= mx){ //cout<<i<<"->"<<cyc_sz[i]<<endl;
    if(cyc_sz[i] == mx){ //cout<<cyc_sz[i]<<" "<<mx<<" "<<ans<<" "<<*(cyl_nodes[i].begin())<<"\n";
	 if(ans > *(cyl_nodes[i].begin()))ans = *(cyl_nodes[i].begin());
    }
    else {
      mx = cyc_sz[i];
      ans = *(cyl_nodes[i].begin());
    }
  }
 cout << "Case " << T << ": " << ans << '\n';
}
return 0;
}
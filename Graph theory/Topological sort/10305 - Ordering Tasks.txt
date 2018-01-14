#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n,m;
vector<int> g[N];
int deg[N];
vector<int> ans;
int seen[N];

void dfs(int x){
  for(int i=0;i<g[x].size();i++)
    dfs(g[x][i]);
  if(seen[x]==0){
    ans.push_back(x);
    seen[x]=1;
  }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin); 

while(1){
  cin>>n>>m;
  if(n+m==0)break;
  
  ans.clear();
  for(int i=0;i<N;i++){
    g[i].clear(); deg[i]=0;  seen[i]=0;
  }
  for(int i=0;i<m;i++){
    int x,y;
    cin>>x>>y;
    g[x].push_back(y);
    deg[y]++;
  }
  for(int i=1;i<=n;i++)
    if(deg[i]==0) //cout<<i<<" ";
      dfs(i);
    reverse(ans.begin(),ans.end());
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<' ';
    cout<<'\n';
}
return 0;
}
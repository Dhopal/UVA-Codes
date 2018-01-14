#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;
vector<int> g[N];
int deg[N];

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  freopen("o.txt","w",stdout);

while(1){
 cin>>n>>m; if(n+m==0)break;
  
for(int i=0;i<N;i++){
  deg[i]=0;
  g[i].clear();
}

 
 for(int i=0;i<m;i++){
  int x,y;
  cin>>x>>y;
  g[x].push_back(y);
  deg[y]++;
 }
// cycle=0;
  set<int> s;
  for(int i=1;i<=n;i++)
    if(deg[i]==0){
      s.insert(i); //dfs(i); 
  }
 
 vector<int> ans;
  while(!s.empty()){
    int x=*s.begin(); s.erase(x);
    ans.push_back(x);
    for(int i=0;i<g[x].size();i++){
      int y=g[x][i];
      deg[y]--;
      if(deg[y]==0)s.insert(y);
    }
  }
  if(ans.size()!=n){
    cout<<"IMPOSSIBLE\n"; continue;
  }
  for(int i=0;i<ans.size();i++)cout<<ans[i]<<'\n';
}
return 0;
}
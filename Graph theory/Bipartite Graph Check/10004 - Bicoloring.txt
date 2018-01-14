#include <bits/stdc++.h>
using namespace std;
const int N=205;
int n,m;
vector<int> g[N];
int color[N];

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);

while(1){
 cin>>n;
 if(!n)break;
 for(int i=0;i<N;i++){
  g[i].clear();
  color[i]=N;
 }
 cin>>m;
 for(int i=0;i<m;i++){
  int x,y;
  cin>>x>>y;
  g[x].push_back(y);
  g[y].push_back(x);
 }
 bool bicolor=false;
 queue<int> q;
 q.push(0); 
 color[0]=0;
 while(!q.empty()){
  int u=q.front();
  q.pop();
  for(int i=0;i<g[u].size();i++){
    int v=g[u][i];
    if(color[v]==N){
      color[v]=1 - color[u]; q.push(v);
    }
    else{
      if(color[u]==color[v])bicolor=1;
    }
  }
 }
 if(bicolor==0)cout<<"BICOLORABLE.\n";
 else cout<<"NOT BICOLORABLE.\n";
}
return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 30;

int n;
int exist[N];
int deg[N];
vector<int> g[N];
vector<int> child[N];


vector<vector<string> > ans;
vector<string> temp;

int cycle;
int color[N];
void dfs(int x){
  if(color[x]==1){
   cycle=1; return;
  }
  color[x]=1;
  for(int i=0;i<g[x].size();i++){
    int y = g[x][i];
    dfs(y);
    for(int j=0;j<child[y].size();j++)
      child[x].push_back(child[y][j]);
    child[x].push_back(y);
  }
  color[x]=2;
}

char a[N];
int done[N];

void sol(int x){
  for(int i=0;i<x-1;i++){
    for(int j=0;j<child[a[i]-'A'].size();j++)
      if(child[a[i]-'A'][j] == (a[x-1]-'A')){
        return;
      }
  }
  if(x==n){
    string s="";
    for(int i=0;i<n;i++)s+=a[i];
      temp.push_back(s);
    return;
  }
  for(int i=0;i<N;i++)
    if(exist[i] and done[i]==0){
      a[x]=char(i+'A');
      done[i]=1;
      sol(x+1);
      done[i]=0;
    }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin); 
int t;
cin >> t; string s; getline(cin,s);
while(t--){
  string s; getline(cin,s);
  getline(cin,s);
  string r;
  getline(cin,r);
  
  temp.clear();
  memset(color,0,sizeof color);
  memset(exist,0,sizeof exist);
  n=0;
  for(int i=0;i<s.size();i++)
    if('A' <= s[i] and s[i] <= 'Z')
      exist[s[i]-'A']=1,n++;
  vector<int> v;
  for(int i=0;i<r.size();i++)
    if('A' <= r[i] and r[i] <= 'Z')v.push_back(r[i]-'A');

  for(int i=0;i<N;i++)g[i].clear();
  memset(deg,0,sizeof deg);
  for(int i=0;i+1<v.size();i+=2){
    int x=v[i];
    int y=v[i+1];
    g[y].push_back(x);
    deg[x]++;
  }
  for(int i=0;i<N;i++)child[i].clear();
 
  cycle=0;
  for(int i=0;i<N;i++)
    if(exist[i] and deg[i]==0){
     dfs(i); 
    }
  for(int i=0;i<N;i++)if(exist[i] and color[i]==0)cycle=1;

  if(cycle){
  temp.push_back("NO"); ans.push_back(temp);
  continue;
  }
  memset(done,0,sizeof done);
  
 
  sol(0);
  ans.push_back(temp);
}
int k=ans.size(); 
for(int i=0;i<k-1;i++){
  for(int j=0;j<ans[i].size();j++){ string s=ans[i][j]; 
  if(s=="NO"){
  	cout<<s<<'\n'; continue;
  }
    for(int u=0;u<s.size()-1;u++)cout<<s[u]<<' '; cout<<s[s.size()-1]<<'\n';
   }
  cout<<'\n';
}
for(int i=0;i<ans[k-1].size();i++){ 
string s=ans[k-1][i];
if(s=="NO"){
  	cout<<s<<'\n'; continue;
  }
for(int j=0;j<s.size()-1;j++)cout<<s[j]<<' ';
cout<<s[s.size()-1]<<'\n';
}

return 0;
}
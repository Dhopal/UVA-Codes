#include <bits/stdc++.h>
using namespace std;
const int N = 102;
int n,m;
vector<int> g[N];
int deg[N];
//vector<int> ans;
//int seen[N];

map<string,int> id;
map<int,string> rid;


int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin); 

int T=0;
while(cin>>n){
  T++;
 // v.clear();
  id.clear(); rid.clear();
  vector<string> v;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    id[s]=i;
    rid[i]=s;
  }
 

for(int i=0;i<N;i++){
  //seen[i]=0;
  deg[i]=0;
  g[i].clear();
}

 cin>>m;
 for(int i=0;i<m;i++){
  string s1,s2;
  cin>>s1>>s2;
  int x=id[s1];
  int y=id[s2];
  g[x].push_back(y);
  deg[y]++;
 }
 set<int> q;
 vector<int> ans;
 for(int i=0;i<n;i++)
  if(deg[i]==0)
    q.insert(i);
    
    while(!q.empty()){
      int x=*q.begin();
      q.erase(x);
      ans.push_back(x);
      for(int i=0;i<g[x].size();i++){
        int y=g[x][i];
        deg[y]--;
        if(deg[y]==0)q.insert(y);
      }
    }
//reverse(ans.begin(),ans.end());
printf("Case #%d: Dilbert should drink beverages in this order: ",T);
for(int i=0;i<ans.size()-1;i++)cout<<rid[ans[i]]<<' ';
  cout<<rid[ans[ans.size()-1]]<<".\n";
  cout<<'\n';
}
return 0;
}
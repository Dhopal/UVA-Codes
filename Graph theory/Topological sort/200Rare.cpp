#include <bits/stdc++.h>
using namespace std;
const int N = 1000;

vector<string> v;
//int can_comp[N][N];
vector<int> g[30];
int deg[30];
int exist[30];
set<int> already[30];
vector<int> ans;
int seen[30];
void dfs(int x){
  for(int i = 0; i < g[x].size(); i++){
    int y = g[x][i];
    dfs(y);
  }
  if(seen[x]==0){
  ans.push_back(x);
  seen[x] = 1;
  }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin); 


while(1){
  string s; 
  cin >> s;
  for(int i = 0; i < s.size(); i++)exist[s[i]-'A'] = 1;
  if(s == "#")break;
  v.push_back(s);
 }

int n = v.size();
for(int i = 0; i < n; i++)
for(int j = i+1; j < n; j++)
 {
    int k = 0;
    int mn = min(v[i].size(), v[j].size());
    while(k < mn and v[i][k] == v[j][k])k++;

    if(k != mn){
      int x = v[i][k]-'A';
      int y = v[j][k]-'A';
      if(already[y].find(x) == already[y].end()){
      	g[y].push_back(x);
      	already[y].insert(x);
      	deg[x]++;
	  }
      
    }
  }
int x = 0;
for(int i = 0; i < 26; i++)if(deg[i] == 0 and exist[i] == 1){
  x = i; break;
}
dfs(x);
for(int i = 0; i < ans.size(); i++)cout << (char) (ans[i] + 'A') ;
cout << '\n';
return 0;
}
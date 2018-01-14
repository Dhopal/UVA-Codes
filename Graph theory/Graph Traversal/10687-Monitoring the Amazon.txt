#include <bits/stdc++.h>
using namespace std;
const int N = 1005;
#define F first
#define S second
int n;
pair<int,int> a[N];
vector<int> v[N];

int dis(int i, int j){
  return (a[i].F - a[j].F)*(a[i].F - a[j].F) +  (a[i].S - a[j].S)*(a[i].S - a[j].S);
}

int seen[N];
int dfs(int x){ //cout<<x<<"->";
  seen[x] = 1;
  for(int i = 0; i < v[x].size(); i++)
    if(seen[v[x][i]] == 0)
      dfs(v[x][i]);
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);
int T = 0;
while(1){
  T++;
  cin >> n;
  if(n == 0)break;
  for(int i = 0; i < N; i++)v[i].clear();
  memset(seen, 0, sizeof seen);

  for(int i = 0; i < n; i++){
    cin >> a[i].F >> a[i].S;
  }
  for(int i = 0; i < n; i++){
    int i1 = -1, i2 = -1, mn = 1e9;
    for(int j = 0; j < n; j++){
      if(i == j)continue;
      int d = dis(i,j); //if(i==0)cout<<j<<" "<<mn<<' '<<d<<endl;
      if(d < mn){
        mn = d;
        i1 = j;
        continue;
      }
       if(d == mn and a[j] < a[i1]){
        i1 = j;
      }
    }
    if(i1 != -1){
      v[i].push_back(i1);
    }
    mn = 1e9;
    for(int j = 0; j < n; j++){
      if(i == j or j == i1)continue;
      int d = dis(i,j);
      if(d < mn){
        mn = d;
        i2 = j;
        continue;
      }
       if(d == mn and a[j] < a[i2]){
        i2 = j;
      }
    }
    if(i2 != -1){
      v[i].push_back(i2);
    }
  }
  dfs(0);
/*
 for(int i=0;i<n;i++){
 	cout<<i<<" : ";
 	for(int j=0;j<v[i].size();j++)cout<<v[i][j]<<' '; cout<<'\n';
 }
 */
  bool ok=0; //for(int i = 0; i < n; i++)cout<<seen[i]<<" ";
  for(int i = 0; i < n; i++)
    if(seen[i] == 0){
   	  cout << "There are stations that are unreachable.\n";
      ok=1;
      break;
    }
  if(ok)continue;
  cout << "All stations are reachable.\n";
}
return 0;
}
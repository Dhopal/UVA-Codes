#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;

int n, m;
//vi g[N];

int par[N];
//pii pts[N];
piii edge[25005];


int find(int x){
  return x == par[x] ? x : par[x] = find(par[x]);
}
bool add(int x, int y){
  int xx = find(x), yy = find(y);
  if(xx == yy) return false;
  if(rand()&1)swap(xx, yy);
  par[xx] = yy;
  return true;
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);

while(1){
  cin >> n >> m; if(n+m==0)break;
  
  for(int i = 0; i < N; i++){
     par[i] = i;
  }
  
  for(int i = 0; i < m; i++){
    int u, v, w; cin >> u >> v >> w;
    edge[i] = mp(w,mp(u,v));
  }

  sort(edge, edge + m);
  vector<int> ans;
  for(int i = 0; i < m; i++){
    int u = edge[i].S.F;
    int v = edge[i].S.S;
    int w = edge[i].F;
    if(add(u,v)){
      
  }else ans.pb(w);
}
if(ans.size()==0){
	cout << "forest\n"; continue;
}
  for(int i = 0 ; i < ans.size()-1; i++)
    cout << ans[i] << ' ';
  cout <<ans[ans.size()-1]<< '\n';
}
return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define N 1000005
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;

int n, m, k;
vi g[N];

int par[N];
piii edge[N];
vector<pii> ans;

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
while(cin >> n){
  for(int i = 0; i < N; i++){
    par[i] = i;
    g[i].clear();
  }
  int mst1 = 0, mst2 = 0;
  for(int i = 0; i < (n-1); i++){
    int u, v, w; cin >> u >> v >> w; mst1 += w;
  }
  int e = 0;
  cin >> k;
  for(int i = 0; i < k; i++){
    int u, v, w; cin >> u >> v >> w;
    g[u].pb(v); g[v].pb(u);
    edge[e++] = mp(w,mp(u,v));
  }
  cin >> m;
  for(int i = 0; i < m; i++){
    int u, v, w; cin >> u >> v >> w;
    edge[e++] = mp(w,mp(u,v));
  }
  sort(edge, edge + e);
  int tree = n;
  for(int i = 0; tree > 1 and i < e; i++){
    int u = edge[i].S.F;
    int v = edge[i].S.S;
    int w = edge[i].F;
    if(add(u,v)){
      mst2 += w; tree--;
    }
  }
  ans.pb(mp(mst1,mst2));
}
for(int i = 0; i < (ans.size() - 1); i++)
 cout << ans[i].F << '\n' << ans[i].S << "\n\n";
cout << ans[ans.size()-1].F << '\n' << ans[ans.size()-1].S << '\n';
return 0;
}
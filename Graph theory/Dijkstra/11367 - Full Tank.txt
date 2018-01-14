#include <bits/stdc++.h>
using namespace std;
#define N 1005
#define MOD 1000000007
#define pb push_back
#define mp make_pair
#define all(c) (c).begin(),(c).end()
#define sz(a) int((a).size())
#define F first
#define S second

#define rep(i, a, b) for(int i = a; i < b; ++i)

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int, pii> piii;
typedef vector<pii> vpii;
typedef vector<piii> vpiii;

int n,m;
vpii g[N];
int p[N];
int dis[N][104];

int s,e,c;

void dijkstra(){
  rep(i,0,N){
    rep(j,0,104){
      dis[i][j]=MOD;
    }
  }
  dis[s][0]=0;
  priority_queue<piii,vpiii,greater<piii> > pq;
  pq.push(mp(0,mp(s,0))); // cost vertex left
  while(!pq.empty()){
    piii P=pq.top();
    pq.pop();
    int u=P.S.F;
    int cost=P.F;
    int has=P.S.S;
    if(dis[u][has] < cost)continue;
    rep(i,0,g[u].size()){
      pii q=g[u][i];
      int v=q.F;
      int d=q.S;
      if(has>=d and (cost < dis[v][has-d])){
        dis[v][has-d]=cost;
        pq.push(mp(cost,mp(v,has-d)));
      }
      if((has+1) <= c and (cost + p[u]) < dis[u][has+1]){
        dis[u][has+1]=cost+p[u];
        pq.push(mp(cost+p[u],mp(u,has+1)));
      }
    }
  }
}

void blank(){
  rep(i,0,N){
    g[i].clear();
  }
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
cin>>n>>m;
rep(i,0,n){
  cin>>p[i];
}
rep(i,0,m){
  int u,v,d;
  cin>>u>>v>>d;
  g[u].pb(mp(v,d));
  g[v].pb(mp(u,d));
}
int q;
cin>>q;
while(q--){
  cin>>c>>s>>e;
  dijkstra();
  int ans=MOD;
  rep(i,0,c+1)
  ans=min(ans,dis[e][i]);
  if(ans>=MOD)cout<<"impossible\n";
  else cout<<ans<<'\n';
}
return 0;
}
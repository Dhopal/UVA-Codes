#include <bits/stdc++.h>
using namespace std;
#define N 10005
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

int T;
int n,m,s,t,p;
vpii g[N];
vpii gr[N];

int dis1[N];
int dis2[N];

vpiii edge;

void dijkstra1(){
  for(int i=0;i<N;i++)
    dis1[i]=MOD;
  dis1[s]=0;
  priority_queue<pii, vpii, greater<pii> > pq;
  pq.push(mp(0,s));
  while(!pq.empty()){
    pii x=pq.top();
    pq.pop();
    int u=x.S;
    int w=x.F;
    if(dis1[u]<w)continue;
    rep(i,0,g[u].size()){
      pii y=g[u][i];
      int v=y.F;
      int e=y.S;
      if((w+e) < dis1[v]){
          dis1[v]=w+e;
          pq.push(mp((w+e),v));
      }
    }
  }
}
void dijkstra2(){
  for(int i=0;i<N;i++)
    dis2[i]=MOD;
  dis2[t]=0;
  priority_queue<pii, vpii, greater<pii> > pq;
  pq.push(mp(0,t));
  while(!pq.empty()){
    pii x=pq.top();
    pq.pop();
    int u=x.S;
    int w=x.F;
    if(dis2[u]<w)continue;
    rep(i,0,gr[u].size()){
      pii y=gr[u][i];
      int v=y.F;
      int e=y.S;
      if((w+e) < dis2[v]){
          dis2[v]=w+e;
          pq.push(mp((w+e),v));
      }
    }
  }
}
int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
cin>>T;
while(T--){
  cin>>n>>m>>s>>t>>p;
  rep(i,0,N){
    g[i].clear(); gr[i].clear();
  }
  edge.clear();
  rep(i,0,m){
    int u,v,c;
    cin>>u>>v>>c;
    g[u].pb(mp(v,c));
    gr[v].pb(mp(u,c));
    edge.pb(mp(c,mp(u,v)));
  }
  dijkstra1();
  dijkstra2();
  int ans=-1;
  rep(i,0,sz(edge)){
    int u=edge[i].S.F;
    int v=edge[i].S.S;
    int c=edge[i].F;
    if((dis1[u]+dis2[v]+c) <= p){
      ans=max(ans,c);
    }
  }
  cout<<ans<<'\n';
}
return 0;
}
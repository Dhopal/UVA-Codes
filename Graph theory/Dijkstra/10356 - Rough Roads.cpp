#include <bits/stdc++.h>
using namespace std;
#define N 505
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

int dis[N][2];

void dijkstra(){
  rep(i,0,N)
  rep(j,0,2)
  dis[i][j]=MOD;

  priority_queue<piii,vpiii,greater<piii> > pq;
//  pq.push(mp(0,mp(0,1)));
  pq.push(mp(0,mp(0,0)));
  dis[0][0]=0;

  while(!pq.empty()){
    piii f=pq.top();
    pq.pop();
    int u=f.S.F;
    int walk=f.S.S;
    int cost=f.F;
    if(dis[u][walk] < cost)continue;
    rep(i,0,sz(g[u])){
      int v=g[u][i].F;
      int d=g[u][i].S;
     // if(v==n-1 and walk==0)continue;
      if((cost+d) < dis[v][!walk]){
        dis[v][!walk]=cost+d;
        pq.push(mp(cost+d,mp(v,!walk)));
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
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
int t=0;
while(cin>>n>>m){
  t++;
  blank();
  rep(i,0,m){
    int u,v,c;
    cin>>u>>v>>c;
    g[u].pb(mp(v,c));
    g[v].pb(mp(u,c));
  }
  dijkstra();
  cout<<"Set #"<<t<<"\n";
  if(dis[n-1][0]>=MOD)cout<<"?\n";
  else cout<<dis[n-1][0]<<"\n";
}
return 0;
}
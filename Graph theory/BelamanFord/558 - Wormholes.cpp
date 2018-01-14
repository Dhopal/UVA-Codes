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

int t,n,m;
vpii g[N];
int dis[N];

void blank(){
  rep(i,0,N){
    g[i].clear();
    dis[i]=MOD;
  }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
cin>>t;
while(t--){
  blank();
  cin>>n>>m;
  rep(i,0,m){
    int x,y,c;
    cin>>x>>y>>c;
    g[x].pb(mp(y,c));
  }
  //run belman-ford
  rep(i,0,n-1){
    rep(j,0,n){
      rep(k,0,sz(g[j])){
        int v=g[j][k].F;
        int w=g[j][k].S;
        int u=j;
        if(dis[u]+w < dis[v]){
          dis[v]=dis[u]+w;
        }
      }
    }
  }
 //detect cycle
  bool cycle=false;
  rep(i,0,n){ if(cycle)break;
    rep(j,0,sz(g[i])){
      int u=i;
      int v=g[i][j].F;
      int e=g[i][j].S;
      if(dis[u]+e < dis[v]){
        cycle=true;
        break;
      }
    }
  }
  if(cycle)cout<<"possible\n";
  else cout<<"not possible\n";
}
return 0;
}
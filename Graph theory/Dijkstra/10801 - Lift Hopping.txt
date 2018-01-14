#include <bits/stdc++.h>
using namespace std;
#define N 105
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
int n,k;
vpii g[N];
int t[10];
int dis[N][10];

void blank(){
  rep(i,0,N){
    g[i].clear();
    rep(j,0,10){
      dis[i][j]=MOD;
    }
  }
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);  //freopen("o.txt","w",stdout);
while(cin>>n>>k){ 
	blank();
  for(int i=0;i<n;i++)
    cin>>t[i];
  string s; getline(cin,s);
  for(int i=0;i<n;i++){
    getline(cin,s); //cout<<s<<"\n";
    int x;
    istringstream is(s);
    vi loc;
    while(is>>x){ //cout<<x<<" ";
      loc.pb(x);
    } //cout<<"\n";
    rep(j,1,sz(loc)){
      int u=loc[j-1];
      int v=loc[j];
      g[u].pb(mp(v,i));
      g[v].pb(mp(u,i));
    }
  }
  // for(int i=0;i<N;i++)
  //   if(sz(g[i])>0){
  //     cout<<i<<" : ";
  //     for(auto p:g[i])
  //       cout<<p.F<<" ";
  //   }
  priority_queue<piii,vpiii,greater<piii> > pq;
  for(int i=0;i<n;i++){
    pq.push(mp(0,mp(0,i)));
    dis[0][i]=0;
  }
  while(!pq.empty()){
    piii p=pq.top();
    int cost=p.F;
    int u=p.S.F;
    int from=p.S.S;
    pq.pop();
    if(dis[u][from]<cost)continue;
    rep(i,0,sz(g[u])){
      int v=g[u][i].F;
      int h=g[u][i].S;
      int w=(h==from)?0:60;
      w+=abs(v-u)*t[h];
      if((cost+w) < dis[v][h]){
        dis[v][h]=(cost+w);
        pq.push(mp((cost+w),mp(v,h)));
      }
    }
  }
  int ans=MOD;
  for(int i=0;i<n;i++)
    ans=min(ans,dis[k][i]);
  if(ans>=MOD)ans=-1;
  if(ans!=-1)cout<<ans<<'\n'; else cout<<"IMPOSSIBLE\n";
}
return 0;
}
#include <bits/stdc++.h>
using namespace std;
const int N = 500 + 4;
#define mp make_pair
#define pb push_back
int n, m;
//vector<int> v[N];
int dis[N];
int w[N][N];
int done[N];

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
// freopen("a.txt","r",stdin);
int T = 0;
while(1){
  T++;
  cin >> n >> m; if(n+m == 0)break;
  //for(int i = 0; i < N; i++)
    //v[i].clear();
  for(int i = 0; i < N; i++)
    for(int j = 0; j < N; j++){
      w[i][j] = -1;
    }
  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    // v[a].pb(b);
    // v[b].pb(a);
    w[a][b] = w[b][a] = c;
  }
  for(int i = 1; i <= n; i++){
      dis[i] = 1e9;
      done[i] = 0;
    }
  dis[1] = 0;
  while(1){
    int x = -1, bestdis = 1e9;
    for(int i = 1; i <= n; i++)
      if(!done[i] and dis[i] < bestdis){
        x = i;
        bestdis = dis[i];
      }
      if(bestdis == 1e9)break;
    for(int i = 1; i <= n; i++)
     if(!done[i] and w[x][i] != -1){
      if(bestdis + w[x][i] < dis[i]){
        dis[i] = bestdis + w[x][i];
      }
     }
     done[x] = 1;
  }
  //for(int i = 1; i <= n; i++)cout << dis[i]<<' '; cout<<"***\n";
  double mx = 0;
  int a = 0, b = 0;
  for(int i = 1; i <= n; i++)
    for(int j = i+1; j <= n; j++){
      if(w[i][j] != -1){
        int d = abs(dis[i] - dis[j]);
        double t = (double)max(dis[i], dis[j]) + (w[i][j] - d)/2.0;
        if(t >= mx){
          mx = t;
          a = i;
          b = j;
        }
      }
    }
    
 //for(int i=1;i<=n;i++)cout<<dis[i]<<"\n";
  printf("System #%d\n",T);
  if(n==1 and m == 0){
    	printf("The last domino falls after 0.0 seconds, at key domino 1.\n\n"); continue;
	}
  if(min(dis[a],dis[b]) + w[a][b] == max(dis[a], dis[b])){
    int x = b;
    if(dis[a] > dis[b])x = a;
   printf("The last domino falls after %.1f seconds, at key domino %d.\n\n",mx,x);
  }
  else{
    printf("The last domino falls after %.1f seconds, between key dominoes %d and %d.\n\n", mx, a, b);
  }
}
return 0;
}
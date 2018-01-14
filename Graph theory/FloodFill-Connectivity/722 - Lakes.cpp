#include <bits/stdc++.h>
using namespace std;
const int N = 105;
char g[N][N];
int seen[N][N];
int ans, n, m;
vector<string> v;
int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y){
  if(x < 0 or y < 0 or x >= n or y >= m or seen[x][y])return 0;
  return 1;
}

void dfs(int x, int y){
	if(g[x][y]=='1')return;
  ans++;
  seen[x][y] = 1;
  for(int i = 0; i < 4; i++){
    int nx = x + dx[i];
    int ny = y + dy[i];
    if(ok(nx, ny) and g[nx][ny] == '0')dfs(nx, ny);
  }
}

int main(){
//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

//freopen("a.txt","r",stdin); freopen("o.txt","w",stdout);
int T = 1, t = 0;
cin >> t;
while(T<=t){

  string a, b;
  cin >> a >> b; 
  int x = 0, y = 0;
  for(int i = 0; i < a.size(); i++)
    x = 10*x + a[i]-'0';
  for(int i = 0; i < b.size(); i++)
    y = 10*y + b[i]-'0';
  
  x--,y--;
  
   string s; getline(cin,s); 
   n=0;m=0;
  while(1){ 
  string s;
    getline(cin,s); v.push_back(s); if(s.size()==0)break; //cout<<s<<endl;
    m=s.size();
    for(int i=0;i<m;i++){
    	g[n][i]=s[i];
	}
	n++;
  }

 /* cout<<a<<" "<<b<<"\n"; for(int i=0;i<n;i++){
  	cout<<v[i]<<endl;
  }cout<<"\n\n";
*/
  
  ans=0;
  for(int i = 0; i < N; i++) for(int j = 0; j < N; j++)seen[i][j] = 0;
  dfs(x,y);
  if(T!=t)cout << ans << "\n\n";
 else cout << ans << '\n';
  
  T++;
}
return 0;
}
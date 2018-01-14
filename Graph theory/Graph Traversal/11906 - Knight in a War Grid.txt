#include <bits/stdc++.h>
using namespace std;

int t, r, c, n, m, q, T, x, y;
int a[104][104];
int seen[104][104];

bool ok1(int x, int y){
  if(x < 0 or y < 0 or x >= r or y >= c or seen[x][y] == 0 or a[x][y] == 1)return false;
  return true;
}
bool ok(int x, int y){
  if(x < 0 or y < 0 or x >= r or y >= c or seen[x][y] or a[x][y])return false;
  return true;
}



void dfs(int x, int y){ 
  seen[x][y] = 1;
  for(int i = -1; i <= 1; i++){
  	for(int j = -1; j <= 1; j++){
  		if(i != 0 && j != 0){
  			int nx = x + i * n;
  			int ny = y + j * m;
  			if(ok(nx,ny))dfs(nx,ny);
		  }
	  }
  }
   for(int i = -1; i <= 1; i++){
  	for(int j = -1; j <= 1; j++){
  		if(i != 0 && j != 0){
  			int nx = x + i * m;
  			int ny = y + j * n;
  			if(ok(nx,ny))dfs(nx,ny);
		  }
	  }
  }
}

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0); //freopen("input.txt","r",stdin);
cin >> t;
while(t--){
T++;
cin >> r >> c >> n >> m;
cin >> q;
for(int i = 0; i <= 102; i++)
 for(int j = 0; j <= 102; j++){
	a[i][j] = 0;
	seen[i][j] = 0;
}
while(q--){
cin >> x >> y;
a[x][y] = 1;
}

dfs(0,0);  

int e = 0, o = 0;
for(int i = 0; i < r; i++)
  for(int j = 0; j < c; j++)
    if(a[i][j] == 0 and seen[i][j] == 1){ 
	  int x = i, y = j;
      set<pair<int,int> > s;
      
   for(int i = -1; i <= 1; i++){
  	for(int j = -1; j <= 1; j++){
  		if(i != 0 && j != 0){
  			int nx = x + i * n;
  			int ny = y + j * m;
  			if(ok1(nx,ny))s.insert(make_pair(nx,ny));
		  }
	  }
  }
   for(int i = -1; i <= 1; i++){
  	for(int j = -1; j <= 1; j++){
  		if(i != 0 && j != 0){
  			int nx = x + i * m;
  			int ny = y + j * n;
  			if(ok1(nx,ny))s.insert(make_pair(nx,ny));
		  }
	  }
  }
      if(s.size() > 0 and s.size() % 2)o++; else e++;
      
}
cout << "Case " << T << ": " << e << ' ' << o << '\n';
}
return 0;
}
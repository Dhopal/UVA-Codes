#include <bits/stdc++.h>
using namespace std;

int cnt[300];

int main(){
ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
//freopen("a.txt","r",stdin);
int T = 0, t = 0;
cin >> t;
while(t--){
  T++; 
  memset(cnt, 0, sizeof cnt);
  string a;
  cin >> a;
  stack<char> s;
  s.push('$'); 
  for(int i = 0; i < a.size(); i++){
    if(s.top() == a[i]){
      s.pop();
      cnt[s.top()]++;
      cnt[a[i]]++;
    }
    else s.push(a[i]);
  }
  cnt[a[0]]--;
  cout << "Case " << T << '\n';
  if(a.size() == 2){
  	cout << a[0] << " = " << 0 << '\n'; 
  	continue;
  }
  for(char c = 'A'; c <= 'Z'; c++)
    if(cnt[c] > 0)cout << c << " = " << cnt[c] << '\n';
}
return 0;
}
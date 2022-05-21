#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;i++)

int main() {
  int N;
  cin>>N;
  string S;
  cin >> S;
  
  map<int,pair<int,int>> m;
  m[0] = make_pair(-1,-1);
  
  rep(i,1,N+1) {
    char ch = S.at(i-1);
    if (ch == 'L') {
      int old_lef = m.at(i-1).first;
      if (old_lef != -1) {
        m.at(old_lef).second = i;
      }
      m.at(i-1).first = i;
      m[i] = make_pair(old_lef,i-1);
    } else {
      int old_ri = m.at(i-1).second;
      if (old_ri != -1) {
        m.at(old_ri).first = i;
      }
      m.at(i-1).second = i;
      m[i] = make_pair(i-1,old_ri);
    }
  }
  
  int ini = -1;
  rep(i,0,N+1) {
    if (m.at(i).first == -1) {
      ini = i;
      break;
    }
  }
  
  int nx = ini;
  rep(i,0,N+1) {
    if (i!=N) cout << nx << " ";
    else cout << nx << endl;
    nx = m.at(nx).second;
  }
}


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  set<int> numset;
  rep(i,1,2*N+2) numset.insert(i);
  int tmp = *begin(numset);
  numset.erase(tmp);
  cout << tmp << endl;
  cout << flush;
  
  while (true) {
    int now;
    cin >> now;
    if (now == 0) return 0;
    
    numset.erase(now);
    int tmp2 = *begin(numset);
    numset.erase(tmp2);
    cout << tmp2 << endl;
    cout << flush;
  }
}

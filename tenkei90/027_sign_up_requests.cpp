#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N;
  cin >> N;
  
  set<string> se;
  rep(i,1,N+1) {
    string S;
    cin >> S;
    
    if (!se.count(S)) {
      se.insert(S);
      cout << i << endl;
    }
  }
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int A,B,C,D;
  
  cin >> A >> B >> C >> D;
  
  if (A<C) {
    cout << "Takahashi" << endl;
  } else if (A==C) {
    if (B<=D) {
      cout << "Takahashi" << endl;
    } else {
      cout << "Aoki" << endl;
    }
  } else {
    cout << "Aoki" << endl;
  }
}

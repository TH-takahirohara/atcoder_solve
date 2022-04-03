#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  vector<int> rui(100001, 0);
  rep(i,2,100001) {
    if (i%2==0) continue;
    int mid = (i+1)/2;
    bool cando = true;
    for (int j=2; j<=sqrt(i); j++) {
      if (j <= (int)sqrt(mid) && mid % j == 0) {
        cando = false;
        break;
      }
      if (i % j == 0) {
        cando = false;
        break;
      }
    }
    
    if (cando) rui.at(i) = 1;
    else rui.at(i) = 0;
  }
  
  rep(i,1,100001) {
    rui.at(i) += rui.at(i-1);
  }
  
  int Q;
  cin >> Q;
  
  rep(i,0,Q) {
    int left,right;
    cin >> left >> right;
    
    cout << rui.at(right) - rui.at(left-1) << endl;
  }
}

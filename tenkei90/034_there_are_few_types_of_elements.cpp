#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  rep(i,0,N) cin >> A.at(i);
  
  map<int,int> M;
  
  int ans = 1;
  int cnt = 1;
  M[A.at(0)] = 1;
  int left = 0, right = 0;
  while (true) {
    while (right < N && cnt <= K) {
      right++;
      if (right >= N) break;
      if (!M.count(A.at(right))) {
        cnt++;
        M[A.at(right)] = 1;
      } else {
        M.at(A.at(right)) += 1;
      }
    }
    
    ans = max(ans, right - left);
    
    if (M.at(A.at(left)) == 1) {
      cnt--;
      M.erase(A.at(left));
    } else {
      M.at(A.at(left)) -= 1;
    }
      
    left++;
    if (left >= N) break;
  }
  
  cout << ans << endl;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define rep(i,a,b) for(int i=a;i<b;i++)
#define fore(i,a) for(auto &i:a)

int main() {
  while (true) {
    int N;
    cin >> N;
    if (N==0) break;
    
    vector<int> S(60*60*24, 0);
    
    rep(i,0,N) {
      string str1,str2,s;
      cin >> str1 >> str2;
      vector<int> vec1, vec2;
      
      stringstream ss1{str1}, ss2{str2};
      while (getline(ss1, s, ':')) {
        int str_i = stoi(s);
        vec1.push_back(str_i);
      }
      while (getline(ss2, s, ':')) {
        int str_i = stoi(s);
        vec2.push_back(str_i);
      }
      
      int num1 = vec1.at(0)*60*60 + vec1.at(1)*60 + vec1.at(2);
      int num2 = vec2.at(0)*60*60 + vec2.at(1)*60 + vec2.at(2);
      
      S.at(num1) += 1;
      S.at(num2) -= 1;
    }
    
    rep(i,0,86399) S.at(i+1) += S.at(i);
    
    int ans = 0;
    rep(i,0,86400) ans = max(ans, S.at(i));
    cout << ans << endl;
  }
  return 0;
}

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<char> charset = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

int main() {
  int N;
  string S;
  
  cin >> N >> S;
  
  ll cnt = 0LL;
  for (char char1 : charset) {
    for (char char2 : charset) {
      for (char char3 : charset) {
        bool flag1 = false;
        bool flag2 = false;
        
        for (int l=0; l<N; l++) {
          char c = S.at(l);
          if (flag1 == false && flag2 == false && c == char1) {
            flag1 = true;
          } else if (flag1 == true && flag2 == false && c == char2) {
            flag2 = true;
          } else if (flag1 == true && flag2 == true && c == char3) {
            cnt++;
            break;
          }
        }
      }
    }
  }
  
  cout << cnt << endl;
}


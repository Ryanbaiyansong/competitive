#include <bits/stdc++.h>
 
 
using namespace std;
 
int n;
char s[300], t[3];
int dp[201][201][201];
int calc(int idx, int f, int k){
  if(idx == n)
    return 0;
  if(dp[idx][f][k] != -1)
    return dp[idx][f][k];
  int ret = 0;
  ret = f * (s[idx] == t[1]) + calc(idx+1, f + (s[idx] == t[0]), k);
  if(k){
    ret = max(ret, f + calc(idx+1, f + (t[0] == t[1]), k-1));
    ret = max(ret, calc(idx+1, f+1, k-1));
  }
  return dp[idx][f][k]=ret;
}
int k;
int main() {
  memset(dp, -1, sizeof dp);
  scanf("%d%d", &n, &k);
  scanf("%s%s", s, t);
  printf("%d", calc(0, 0, k));
  return 0;
}

#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cstdlib>
#include<cctype>
using namespace std;

int josephus(int n, int k) {
  if (n == 1)
	return 1;
  else
	return (josephus(n - 1, k) + k-1) % n + 1; 
}

int main() {
  int n;
  scanf("%d", &n);
  while(n!=0) {
    for(int i=1; i<=200; i++) {
	  if(josephus(n-1, i) == 12) {
		printf("%d\n", i);
		break;
	  } 
    }       
    scanf("%d", &n);
  }
  return 0;
}

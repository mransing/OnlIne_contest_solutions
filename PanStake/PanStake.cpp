#include <iostream>
#include <stdio.h>
#include <stdlib.h>
     
typedef unsigned long long uulong;
     
uulong arr[1001][1001];
int cur_max_bell=1;
     
long long readIntFromBufferAndAdvance()
{
  long long noRead=0;
  bool sign=false;
  char p=getchar_unlocked();
  for(;p<33;){p=getchar_unlocked();};
  if(p == '-')
    {
      sign=true;
    }
  for(;p>32;)
    {
      noRead = noRead * 10 + (p - '0');
      p=getchar_unlocked();
    }
  if(sign)
    {
      noRead*=-1;
    }
  return noRead;
};
     
uulong bell_number(int n)
{
  if(n <= cur_max_bell)
    {
      return arr[n][n-1];
    }
  for(int i=cur_max_bell+1;i<=n;++i)
    {
      arr[i][0]=arr[i-1][i-2];
      for(int j=1;j<i;++j)
	{
	  arr[i][j]=(arr[i][j-1] + arr[i-1][j-1]) % 1000000007;
	}
    }
  cur_max_bell=n;
  return arr[n][n-1];
};
     
int main()
{
  arr[1][0] = 1;
  int nTestCases=readIntFromBufferAndAdvance();
  for(int i=0;i<nTestCases;++i)
    {
      int p=readIntFromBufferAndAdvance();
      uulong ans = bell_number(p);
      printf("%llu\n",ans);
    }
  return 0;
}

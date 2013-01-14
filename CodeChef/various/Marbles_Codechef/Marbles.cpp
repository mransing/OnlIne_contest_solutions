#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
 
#define MAX_BUFFER 1000000
#define MAX_RANGE 1000
unsigned long long table[MAX_RANGE][MAX_RANGE];
 
unsigned long long Comb(int n, int k)
{
  if(n == k)
    {
      return 1;
    }
  else if(n < k)
    {
      return 0;
    }
  if(k > n -k)
    {
      k = n-k;
    }
  if(k == 1)
    {
      return n;
    }
  unsigned long long retValue = 1;
  for(int i =1; i<=k; i++)
    {
      retValue = (retValue * (n-k+i))/i;
    }
  return (unsigned long long) retValue;
}
 
int main()
{
  try
    {
      // cout << Comb(60,30);
      char *buf = new char[MAX_RANGE];
      char *outBuf = new char[MAX_RANGE];
      //int someread = read(0,buf,MAX_RANGE);
      int nTestCases =0;
      char *tempOutBuf = outBuf;
      int writeBytes=0;
      scanf("%d",&nTestCases);
      int n =0,k=0;
      for(int i=0;i<nTestCases;i++)
	{
	  //ss >> n >> k;
	  scanf("%d",&n);
	  scanf("%d",&k);
	  writeBytes = sprintf(outBuf,"%lld\n",Comb(n-1,k-1));
	  outBuf+=writeBytes;
	}
      printf("%s",tempOutBuf);
      fflush(stdout);
      delete [] buf;
      delete [] tempOutBuf;
    }
  catch(...)
    {
      cout << "Some exception\n";
    }
}

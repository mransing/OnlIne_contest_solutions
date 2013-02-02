#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int MAX=200000000;
int primeArr[MAX];
int startArr[MAX]={0};
int primeLen=0;

int nFactors(unsigned long long n)
{
  int totalFac = 1;
  int curPrime=0;
  while(n > 1)
    {
      int curFac=1;
      while(n % primeArr[curPrime] == 0)
	{
	  ++curFac;
	  n/=primeArr[curPrime];
	}
      totalFac*=curFac;
      ++curPrime;
    }
  return totalFac;
};

int main()
{
  for(int i=4;i<MAX;i+=2)
    {
      startArr[i]=1;
    }
  int j=3;
  int q = sqrt(MAX);
  do
    {
      int x = j;
      while( startArr[x] !=0 ) ++x;
      for(int i=3*x;i<MAX;i+=2*x)
	{
	  startArr[i]=1;
	}
      j=x+1;
    }while(j < q);
  
  for(int i=2;i<MAX;++i)
    {
      if(startArr[i] == 0)
	{
	  primeArr[primeLen] = i;
	  ++primeLen;
	}
    }
  unsigned long long i=2;
  unsigned long long k=i*(i+1)/2;
  while(nFactors(k) < 500)
    {
      ++i;
      k=i*(i+1)/2;
    }
  printf("%lld %lld",k,i);
  return 0;
}

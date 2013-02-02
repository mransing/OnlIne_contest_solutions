#include <stdio.h>
#include <stdlib.h>

typedef unsigned long long ULONG;

const ULONG prime=1000000007;
ULONG pow2Arr[1001];
int maxPow2=0;

ULONG pow2(int a)
{
  ULONG l=1;
  for(;a>0;--a)
	{
	  l = (l * 2) % prime;
	}
  return l;
};

ULONG invMod(ULONG a, ULONG b)
{
  long long  x = 1, y = 0;
  ULONG c=b;
  long long  xLast = 0, yLast = 1;
  long long q, r, m, n;
  while(a != 0) 
	{
	  q = b / a;
	  r = b % a;
	  m = xLast - q * x;
	  n = yLast - q * y;
	  xLast = x, yLast = y;
	  x = m, y = n;
	  b = a, a = r;
	};
  return (xLast + c) % c;
}

ULONG ncr(ULONG n, ULONG r)
{
  if((r==n) || (r ==0))
	return 1;
  if ((r == 1) || r == (n-1))
	{
	  return n;
	}
	
  if (r > (n -r)) r = n-r;
  ULONG i=n;
  ULONG nume=1;
  for(i=n;i>n-r;--i)
	{
	  nume = (nume * i) % prime;
	}
  i=r;
  ULONG deno=1;
  for(i=r;i>0;--i)
	{
	    deno = (deno * i) % prime;
	};
  return (nume * (invMod(deno,prime))) % prime;  
};

ULONG GiveCount(ULONG* a,int n)
{
  if((n == 1) || (n == 2))
	{
	  return 1;
	}
  if(n & 1 != 0)
	{
	  //int p=(n+1)/2;
	  ULONG k=pow2(n-1);
	  return k;
	}
  else
	{
	  ULONG x = ncr(n,n/2);
	  ULONG y = pow2(n);
	  ULONG z = invMod(2,prime);
	  ULONG l = ((y - x) + prime) % prime;
	  ULONG m = (l * z) % prime;
	  return m;
	}
};

int readIntFromBufferAndAdvance(char **InSomeBuf)
{
  long long noRead=0;
  char *InBuf=*InSomeBuf;
  for(;*InBuf==' ' || *InBuf=='\n' || *InBuf == '\0' || *InBuf == '\r';++InBuf);
  for(;*InBuf!=' ' && *InBuf!='\n' && *InBuf != '\0' && *InBuf != '\r';++InBuf)
	{
	  noRead = (noRead << 3) + (noRead << 1)+ (*InBuf - '0');
	}
  InBuf++;
  *InSomeBuf = InBuf;
  return noRead;  
};

int main()
{
  
  //printf("%d %d %d %d",invMod(6,7),invMod(5,11),ncr(10,3),GiveCount(arr,5));
  long long lInputBufferLength = 100 * 1000 * 8;
  int outBuffSize = 100* 20;
  char *InOrigBuf = malloc(lInputBufferLength);
  char *InBuf=InOrigBuf;
  char *OutBuf = malloc(outBuffSize);
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  read(0,InBuf,lInputBufferLength);
  int nTestCases = readIntFromBufferAndAdvance(&InBuf);
  for(;nTestCases>0;--nTestCases)
	{
	  int n=readIntFromBufferAndAdvance(&InBuf);
	  int i=0;
	  ULONG arr[1001];
	  for(;i< n;++i)
		{
		  arr[i]=readIntFromBufferAndAdvance(&InBuf);
		}
	  int tempBufLen=sprintf(tempOutBuf,"%llu\n",GiveCount(arr,n));
	  tempOutBuf=tempOutBuf + tempBufLen;
	  outBufLen+=tempBufLen;
	}
  write(1,OutBuf,outBufLen);
  free(InOrigBuf);
  free(OutBuf);
  return 0;
}

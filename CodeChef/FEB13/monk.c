#include <stdio.h>
#include <stdlib.h>

unsigned long long fibArr[1000000];
int maxFix=3;
unsigned long long fib(int n)
{
  if(n < maxFix)
	{
	  return fibArr[n];
	}
  for(;maxFix <= n; ++maxFix )
	{
	  fibArr[maxFix] = (fibArr[maxFix-1] + fibArr[maxFix-2]) % 1000000;
	}
  return fibArr[n];
}

int nBits(int n)
{
  if(n == 0) return 0;
  else return 1 + nBits(n & (n-1));
}

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
  fibArr[1]=1;
  fibArr[2]=1;
  long long lInputBufferLength = 100000 * 10;
  int outBuffSize = 100000 * 20;
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
	  int g=readIntFromBufferAndAdvance(&InBuf);
	  int tempBufLen;
	  if(g == nBits(fib(n+1)))
		{
		  tempBufLen=sprintf(tempOutBuf,"CORRECT\n");
		}
	  else
		{
		  tempBufLen=sprintf(tempOutBuf,"INCORRECT\n");
		}
	  tempOutBuf=tempOutBuf + tempBufLen;
	  outBufLen+=tempBufLen;
	}
  write(1,OutBuf,outBufLen);
  free(InOrigBuf);
  free(OutBuf);
  return 0;
}

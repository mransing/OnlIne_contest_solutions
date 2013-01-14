#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef unsigned long long ULONG;
ULONG readIntFromBufferAndAdvance(char **InSomeBuf)
{
  ULONG noRead=0;
  char *InBuf=*InSomeBuf;
  for(;*InBuf==' ' || *InBuf=='\n' || *InBuf == '\0' || *InBuf == '\r';++InBuf);
  for(;*InBuf!=' ' && *InBuf!='\n' && *InBuf != '\0' && *InBuf != '\r';++InBuf)
	{
	  noRead = noRead * 10 + (*InBuf - '0');
	}
  InBuf++;
  *InSomeBuf = InBuf;
  return noRead;  
};

void sort(ULONG a, ULONG b , ULONG c, ULONG *small, ULONG *large, ULONG *middle)
{
  if(a < b)
	{
	  if (b < c)
		{
		  *small =a;*large =c; *middle=b;
		}
	  else
		{
		  *large=b;
		  if(a < c)
			{
			  *small = a; *middle=c;
			}
		  else
			{
			  *middle = a;*small =c;
			}
		}
	}
  else
	{
	  if( a < c)
		{
		  *small =b;*large=c;*middle=a;
		}
	  else
		{
		  *large =a;
		  if(b < c)
			{
			  *small =b; *middle=c;
			}
		  else
			{
			  *small=c;*middle=b;
			}
		}
	}
};

int main()
{
  const ULONG prime=1000000007;
  long long lInputBufferLength = 100 * 100 * 10000;
  int outBuffSize = 10000;
  char *InOrigBuf = malloc(lInputBufferLength);
  char *InBuf=InOrigBuf;
  char *OutBuf = malloc(outBuffSize);
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  read(0,InBuf,lInputBufferLength);
  int nTestCases = readIntFromBufferAndAdvance(&InBuf);
  for(;nTestCases > 0; --nTestCases)
	{
	  ULONG a = readIntFromBufferAndAdvance(&InBuf);
	  ULONG b= readIntFromBufferAndAdvance(&InBuf);
	  ULONG c= readIntFromBufferAndAdvance(&InBuf);
	  ULONG small,middle,large;
	  sort(a,b,c,&small,&large,&middle);
	  ULONG ans=0;
	  if((small < 1) || (middle < 2) || (large < 3))
		{
		  goto label1;
		}
	  ans= ((((small % prime) * ((middle -1) % prime)) % prime) * ((large -2) %prime)) % prime;
	  
	label1:
	  {
		int tempBufLen=sprintf(tempOutBuf,"%llu\n",ans);
		tempOutBuf=tempOutBuf + tempBufLen;
		outBufLen+=tempBufLen;
	  }
	}
  write(1,OutBuf,outBufLen);
  free(InOrigBuf);
  free(OutBuf);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long long readIntFromBufferAndAdvance(char **InSomeBuf)
{
  long long noRead=0;
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

int main()
{
  long long lInputBufferLength = 100 * 100 * 10000;
  int outBuffSize = 10000;
  char *InOrigBuf = malloc(lInputBufferLength);
  char *InBuf=InOrigBuf;
  char *OutBuf = malloc(outBuffSize);
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  read(0,InBuf,lInputBufferLength);
  char **TempInBuff = &InBuf;
  int nTestCases = readIntFromBufferAndAdvance(&InBuf);
  for(;nTestCases > 0;--nTestCases)
	{
	  int tN = readIntFromBufferAndAdvance(&InBuf);
	  int small = readIntFromBufferAndAdvance(&InBuf);
	  int sum = small;
	  int tP = tN;
	  for(;tN > 1;--tN)
		{
		  int tempNum = readIntFromBufferAndAdvance(&InBuf);
		  if (small > tempNum)
			{
			  small = tempNum;
			}
		  sum+=tempNum;
		}
	  int tempBufLen=sprintf(tempOutBuf,"%d\n",sum - tP * small);
	  tempOutBuf=tempOutBuf + tempBufLen;
	  outBufLen+=tempBufLen;
	}
  write(1,OutBuf,outBufLen);
  free(InOrigBuf);
  free(OutBuf);
  return 0;
}

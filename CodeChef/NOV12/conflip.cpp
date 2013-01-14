#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

long long readIntFromBufferAndAdvance(char *&InBuf)
{
  long long noRead=0;
  for(;*InBuf==' ' || *InBuf=='\n' || *InBuf == '\0' || *InBuf == '\r';++InBuf);
  for(;*InBuf!=' ' && *InBuf!='\n' && *InBuf != '\0' && *InBuf != '\r';++InBuf)
	{
	  noRead = (noRead << 3) + (noRead << 1) + (*InBuf - '0');
	}
  InBuf++;
  return noRead;  
};


int maxInputLen = 20000 * 10 * 20;
int main()
{
  char *InOrigBuf = new char[maxInputLen]; 
  char *InBuf = InOrigBuf;
  char *OutBuf = new char[20000 * 10 * 15];
  char *tempOutBuf = OutBuf;
  int outBufLen = 0;
  int kCount = read(0,InBuf,maxInputLen);
  
  int nTestCases = readIntFromBufferAndAdvance(InBuf);
  for(int i=0;i<nTestCases;++i)
	{
	  int g = readIntFromBufferAndAdvance(InBuf);
	  for(int j =0 ;j<g;++j)
		{
		  char iState = readIntFromBufferAndAdvance(InBuf);
		  int nCoins = readIntFromBufferAndAdvance(InBuf);
		  char oState = readIntFromBufferAndAdvance(InBuf);
		  int niStateCoins = nCoins >> 1;
		  int tempBufLen = 0;
		  if(iState == oState)
			{
			  tempBufLen = sprintf(tempOutBuf,"%d\n",niStateCoins);
			}
		  else
			{
			  tempBufLen = sprintf(tempOutBuf,"%d\n",nCoins - niStateCoins);
			}
		  tempOutBuf = tempOutBuf + tempBufLen;
		  outBufLen += tempBufLen;
		}
	}
  write(1, OutBuf, outBufLen);
  delete [] InOrigBuf;
  delete [] OutBuf;
  return 0;
}

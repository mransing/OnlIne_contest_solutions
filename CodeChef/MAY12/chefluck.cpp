#include <stdio.h>
#include <stdlib.h>

long long readIntFromBufferAndAdvance()
{
  long long noRead=0;
  int sign=0;
  char p=getchar_unlocked();
  for(;p<33;){p=getchar_unlocked();};
  if(p == '-')
	{
	  sign=1;
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


int main()
{
  int checkarr[]={0,-1,-1,-1,0,-1,-1,0,0,-1,-1,0,0,-1,0,0,0,-1};
  char outBuff[10000];
  char *TempBuf=outBuff;
  int outBufLen=0;
  int TempOutBufLen=0;
  int nTests=readIntFromBufferAndAdvance();
  int i=0;
  u_int64_t arr[1001]={0};
  int64_t answer=0;
  const u_int64_t notOf3=~3;
  for(i=0;i<nTests;++i)
	{
	  arr[i]=readIntFromBufferAndAdvance();
	}
  for(i=0;i<nTests;++i)
	{
	  u_int64_t curNum=arr[i];
	  /* if(curNum<18 && checkarr[curNum]==-1)
		{
		  answer=-1;
		  goto label;
		  }*/
	  int modulo7=curNum % 7;
	  u_int64_t div7=curNum/7;
	  switch(modulo7)
		{
		case 0:
		case 4:
		  answer=div7;
		  break;
		case 1:
		case 5:
		  answer=div7-1;
		  break;
		case 2:
		case 6:
		  answer = div7-2;
		  break;
		case 3:
		  answer = div7-3;
		  break;
		}
	  if(answer < 0)
		{
		  answer = -1;
		}
	  else
		{
		  answer *= 7;
		}
	  //label:
	  TempOutBufLen=sprintf(TempBuf,"%lld\n",answer);
	  TempBuf+=TempOutBufLen;
	  outBufLen+=TempOutBufLen;
	}
  write(1,outBuff,outBufLen);
  return 0;
}

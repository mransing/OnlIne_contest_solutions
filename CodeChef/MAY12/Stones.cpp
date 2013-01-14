#include<stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>

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
	  noRead = (noRead << 3) + (noRead << 1) + (p - '0');
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
  int nTests=readIntFromBufferAndAdvance();
  int i=0;
  for(i=0;i<nTests;++i)
	{
	  int Table[128]={0};
	  int Total=0;
	  char p;
	  while((p=getchar_unlocked())!='\n')
		{
		  Table[p]=1;
		};
	  while((p=getchar_unlocked())!='\n')
		{
		  if(Table[p]==1) ++Total;
		};
	  printf("%d\n",Total);
	}
  return 0;
}

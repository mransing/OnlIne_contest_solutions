#include<stdio.h>
#include<stdlib.h>
 
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
  int nTestCases,i=0;
  nTestCases=readIntFromBufferAndAdvance();
  for(i=0;i<nTestCases;++i)
    {
      long long p=readIntFromBufferAndAdvance();
      if(p&1)
	{
	  //write(p-1);
	  printf("%llu\n",p-1);
	}
      else
	{
	  printf("%llu\n",p);
	}
    }
  return 0;
}

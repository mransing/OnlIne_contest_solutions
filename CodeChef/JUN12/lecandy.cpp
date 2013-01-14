#include <stdio.h>
#include <stdlib.h>

long long readIntFromBufferAndAdvance()
{
  long long noRead=0;
  char p=getchar_unlocked();
  for(;p<33;){p=getchar_unlocked();};
  for(;p>32;)
	{
	  noRead = noRead * 10 + (p - '0');
	  p=getchar_unlocked();
	}
  return noRead;  
};

int main()
{
  int nTestCases=readIntFromBufferAndAdvance();
  int i=0;
  for(i=0;i<nTestCases;++i)
	{
	  unsigned int nElephants,nCandies;
	  nElephants=readIntFromBufferAndAdvance();
	  nCandies=readIntFromBufferAndAdvance();
	  int j=0;
	  unsigned int total=0;
	  for(j=0;j<nElephants;++j)
		{
		  total+=readIntFromBufferAndAdvance();
		}
	  if(total >nCandies)
		{
		  printf("No\n");
		}
	  else
		{
		   printf("Yes\n");
		}
	}
  return 0;
}

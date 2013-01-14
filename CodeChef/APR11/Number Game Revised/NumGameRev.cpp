#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  int nTestCases;
  scanf("%d",&nTestCases);
  int i =0;
  for(;i<nTestCases;i++)
    {
      unsigned long long n = 0;
      scanf("%llu",&n);
      if((n-1)%4)
	{
	  printf("BOB\n");
	}
      else
	{
	  printf("ALICE\n");
	}
    }
  return 0;
}

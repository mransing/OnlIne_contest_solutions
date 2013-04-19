#include <stdio.h>
#include <stdlib.h>

int main()
{
  int nTestCases;
  scanf("%d",&nTestCases);
  for(;nTestCases>0;--nTestCases)
	{
	  int i=0;
	  int nArr[51];
	  int nSteps;
	  scanf("%d",&nSteps);
	  for(;i<nSteps;++i)
		{
		  scanf("%d",&nArr[i]);
		}
	  i=nSteps-1;
	  int jumps=0;
	  while(i != 0)
		{
		  int j=0;
		  int reachable=0;
		  while(reachable == 0)
			{
			  if((j + nArr[j]) >= i)
				{
				  break;
				}
			  ++j;
			}
		  i = j;
		  ++jumps;
		}
	  printf("%d\n",jumps);
	}
  return 0;
}

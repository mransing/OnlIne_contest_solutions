#include <stdio.h>
#include <stdlib.h>

int main()
{
  int nTestCases;
  scanf("%d",&nTestCases);
  for(;nTestCases>0;--nTestCases)
	{
	  int nNumber=0;
	  scanf("%d",&nNumber);
	  int i=2;
	  long long total=0;
	  for(;i<nNumber;++i)
		{
		  if((nNumber % i) == 0)
			{
			  total+=i;
			}
		}
	  printf("%lld\n",total + 1);
	}
  return 0;
}

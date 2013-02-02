#include <stdio.h>
#include <stdlib.h>

int main()
{
  int n;
  scanf("%d",&n);
  for(;n>0;--n)
	{
	  char str1[300];
	  char *str=str1;
	  scanf("%s",str1);
	  int uniq[100];
	  memset(uniq,0,100*sizeof(int));
	  for(;*str !=0 ;++str)
		{
		  ++uniq[*str - 65];
		}
	  int sum=0;
	  int i=57;
	  for(;i>-1;--i)
		{
		  sum+=(uniq[i] + 1)/2;
		}
	  printf("%d\n",sum);
	}
  return 0;
}

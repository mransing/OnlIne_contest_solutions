#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int isPalin(char *str)
{
  int i=0;
  int len=strlen(str) - 1;
  for(;i < len;--len,++i)
	{
	  if(str[i] != str[len])
		return 0;
	}
  return 1;
};

int main()
{
  int nTestCases;
  scanf("%d",&nTestCases);
  for(;nTestCases >0;--nTestCases)
	{
	  char str[12];
	  scanf("%s",str);
	  if (isPalin(str))
		{
		  printf("YES\n");
		}
	  else
		{
		  printf("NO\n");
		}
	}
  return 0;
}

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
 
long long power[10]={1,
		     10,
		     100,
		     1000,
		     10000,
		     100000,
		     1000000,
		     10000000,
		     100000000,
		     1000000000};
 
long long sumfrom1ton(char *str)
{
  int len=strlen(str);
  long long sum =0; int i=0;
  for(i =0;i<len-1;i++)
    {
      int n = str[i] - '0';
      int j = len -i-1;
      sum = sum + n*(n-1)/2 * power[j] + 45 * n * j * power[j-1] + n * (atoi(str + i+1) + 1);
    }
  int n = str[len -1] - '0';
  sum = sum + n * (n+1) / 2;
  return sum;
}
 
void minus1(char str[])
{
  int len = strlen(str);
  while(str[len -1] == '0')
    {
      str[len - 1]='9';
      --len;
    }
  str[len - 1]=str[len - 1] - 1;
}
 
int main()
{
  char str1[12]="0",str2[12]="0";
  //printf("%llu",sumfrom1ton("09"));
  while(1)
    {
      scanf("%s",str1);
      scanf("%s",str2);
      if(strcmp(str1,"-1") == 0)
	{
	  break;
	}
      if(strcmp(str1,"0") != 0)
	{
	  minus1(str1);
	}
      printf("%llu\n",sumfrom1ton(str2)-sumfrom1ton(str1));
    }
  return 0;
}
 

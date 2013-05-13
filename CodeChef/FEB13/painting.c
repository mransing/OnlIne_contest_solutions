#include <stdlib.h>
#include <stdio.h>

int main()
{
  int n;
  char* outBuf=malloc(2500 * 30);
  char *tempOutBuf=outBuf;
  int lenOutBuf=0;
  scanf("%d",&n);
  int i=0;
  int lines=0;
  for(i=0;i<n;++i)
	{
	  char str[60];
	  scanf("%s",str);
	  char *str1=str;
	  while(*str1!=0)
		{
		  char *str2=0;
		  while(*str1!=0 && *str1 == 'W') ++str1;
		  if(*str1 == 0)
			{
			  continue;
			}
		  else
			{
			  str2=str1;
			}
		  while(*str1 == 'B') ++str1;
		  int tempOutLen = sprintf(tempOutBuf,"%d %ld %d %ld B\n",i,str2-str,i,str1-str-1);
		  lenOutBuf+=tempOutLen;
		  tempOutBuf+=tempOutLen;
		  ++lines;
		}
	}
  printf("%d\n",lines);
  fflush(stdout);
  write(1,outBuf,lenOutBuf);
  free(outBuf);
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
 
int main()
{
  int i,nTestCases;
  scanf("%d",&nTestCases);
  for(i =0;i<nTestCases;i++)
    {
      int readlen,count=0;
      char* origstr= (char*)malloc(sizeof(char)*1000000);
      char *str = origstr;
      readlen=scanf("%s",origstr);
      while(*str!='\0')
	{
	  if(!((*str=='4') || (*str=='7')))
	    {
	      ++count;
	    }
	  ++str;
	}
      printf("%d\n",count);
      free(origstr);
    }
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <map>

typedef std::map<char,char> mapCC;
typedef mapCC::iterator iterCC;

int main()
{
  mapCC ccMap;
  int nTestCases;
  scanf("%d",&nTestCases);
  char strMap[30];
  scanf("%s",strMap);
  for(int i=0;i<26;++i)
	{
	  ccMap['a' + i]=strMap[i];;
	  ccMap['A' + i]=strMap[i]-'a'+'A';
	}
  ccMap['_']=' ';
  for(;nTestCases>0;--nTestCases)
	{
	  char newStr[102];
	  char *inStr=newStr;
	  scanf("%s",newStr);
	  char outStr[102];
	  int p=0;
	  while(newStr[p] != 0)
		{
		  char c=newStr[p];
		  if(ccMap.find(c)!=ccMap.end())
			{
			  outStr[p]=ccMap[c];
			}
		  else
			{
			  outStr[p]=c;
			}
		  ++p;
		}
	  outStr[p]='\0';
	  printf("%s\n",outStr);
	}
  return 0;
}

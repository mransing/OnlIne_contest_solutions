#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

typedef struct _Level3Struct
{
  int64_t priority;
  char* name;
}Level3Struct;

int numStrings=0;
int numQueries=0;
char *outBuff;
char *TempBuf;
int outBufLen=0;
int TempOutBufLen=0;

Level3Struct level3Arr[1001];
char **namesArr;
char **queriesArr;
int queriesLen[1001];

int64_t readIntFromBufferAndAdvance()
{
  long long noRead=0;
  int sign=0;
  char p=getchar_unlocked();
  for(;p<33;){p=getchar_unlocked();};
  if(p == '-')
	{
	  sign=1;
	  p=getchar_unlocked();
	}
  for(;p>32;)
	{
	  noRead = noRead * 10 + (p - '0');
	  p=getchar_unlocked();
	}
  if(sign)
	{
	  noRead*=-1;
	}
  return noRead;  
};

int compare (const void * a, const void * b)
{
  return ( ((Level3Struct*)b)->priority - ((Level3Struct*)a)->priority );
}


int main()
{
  outBuff=(char *)malloc(sizeof(char)*1005000);
  TempBuf=outBuff;
  numStrings=readIntFromBufferAndAdvance();
  namesArr = (char **)malloc(sizeof(char*) * numStrings);
  int i=0;
  for(i=0;i<numStrings;++i)
	{
	  namesArr[i]=(char *)malloc(sizeof(char) * 1001);
	}
  for(i=0;i<numStrings;++i)
	{
	  char ch;
	  int curLen=0;
	  while((ch=getchar_unlocked())!=' ')
	  	{
	  	  namesArr[i][curLen]=ch;
	  	  ++curLen;
		}
	  namesArr[i][curLen]='\0';
	  level3Arr[i].name=namesArr[i];
	  level3Arr[i].priority=readIntFromBufferAndAdvance();
	}
  numQueries=readIntFromBufferAndAdvance();
  queriesArr = (char **)malloc(sizeof(char*) * numQueries);
  for(i=0;i<numQueries;++i)
	{
	  queriesArr[i]=(char *)malloc(sizeof(char) * 1001);
	}
  for(i=0;i<numQueries;++i)
	{
	  char ch;
	  int curLen=0;
	  while((ch=getchar_unlocked())!='\n')
	  	{
	  	  if(ch==EOF) break;
	  	  queriesArr[i][curLen]=ch;
	  	  ++curLen;
	  	}
	  queriesArr[i][curLen]='\0';
	  queriesLen[i]=curLen;
	}
  qsort(level3Arr,numStrings,sizeof(Level3Struct),compare);
  /* for(i=0;i<numStrings;++i) */
  /* 	{ */
  /* 	  printf("%d %s\n",level3Arr[i].priority,level3Arr[i].name); */
  /* 	} */
 
  for(i=0;i<numQueries;++i)
	{
	  int j=0;
	  int indexInNames=0;
	  for(j=0;j<numStrings;++j)
		{
		  if(strncmp(queriesArr[i],level3Arr[j].name,queriesLen[i]) == 0)
			{
			  indexInNames=j;
			  break;
			}
		}
	  if(j>=numStrings)
		{
		  //Answer is NO.
		  TempOutBufLen=sprintf(TempBuf,"NO\n");
		  TempBuf+=TempOutBufLen;
		  outBufLen+=TempOutBufLen;
		}
	  else
		{
		  TempOutBufLen=sprintf(TempBuf,"%s\n",level3Arr[indexInNames].name);
		  TempBuf+=TempOutBufLen;
		  outBufLen+=TempOutBufLen;
		}
	}
  write(1,outBuff,outBufLen);
  free(outBuff);
  for(i=0;i<numStrings;++i)
	{
	  free(namesArr[i]);
	}
  free(namesArr);
  for(i=0;i<numQueries;++i)
	{
	  free(queriesArr[i]);
	}
  free(queriesArr);
  return 0;
}

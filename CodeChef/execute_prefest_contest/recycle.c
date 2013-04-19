#include <stdio.h>
#include <stdlib.h>

typedef struct _someStruct
{
  char perm[4];
  char comb[7];
}someStruct;

const someStruct const mainStruct[]={{"BCG",{3,6,2,8,1,4}},
						 {"BGC",{3,6,1,7,2,5}},
						 {"CBG",{5,8,0,6,1,4}},
						 {"CGB",{5,8,1,7,0,3}},
						 {"GBC",{4,7,0,6,2,5}},
						 {"GCB",{4,7,2,8,0,3}}
};

int main()
{
  int nTestCases;
  scanf("%d",&nTestCases);
  for(;nTestCases>0;--nTestCases)
	{
	  int nArr[9];
	  int i=0;
	  for(;i<9;++i)
		{
		  scanf("%d",&nArr[i]);
		}
	  const char *curComb=0;
	  long long curSmall=17179869185;
	  for(i=0;i<6;++i)
		{
		  int j=0;
		  long long curTot=0;
		  for(j=0;j<6;++j)
			{
			  curTot+=nArr[mainStruct[i].comb[j]];
			}
		  if (curTot < curSmall ) 
			{
			  curComb=mainStruct[i].perm;
			  curSmall=curTot;
			}
		}
	  printf("%s %lld\n",curComb,curSmall);
	}
  return 0;
}

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
 
typedef unsigned long ulong;
bool cmp(unsigned long lhs, unsigned long rhs)
{
  return lhs>rhs;
};
 
long long readIntFromBufferAndAdvance()
{
  long long noRead=0;
  bool sign=false;
  char p=getchar_unlocked();
  for(;p<33;){p=getchar_unlocked();};
  if(p == '-')
    {
      sign=true;
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
 
int main()
{
  int nTestCases = readIntFromBufferAndAdvance();
  for(int i=0;i<nTestCases;++i)
    {
      int nMatches = readIntFromBufferAndAdvance();
      ulong diff=0;
      ulong currGoals=readIntFromBufferAndAdvance();
      ulong cur_min=currGoals;
      for(int j=1;j<nMatches;++j)
	{
	  currGoals=readIntFromBufferAndAdvance();
	  if(currGoals < cur_min)
	    {
	      cur_min = currGoals;
	      continue;
	    }
	  ulong curdiff=currGoals - cur_min;
	  if(diff < curdiff)
	    {
	      diff=curdiff;
	    }
	}
      if (nMatches < 2)
	{
	  puts("UNFIT");
	  continue;
	}
      if(diff == 0)
	{
	  puts("UNFIT");
	  continue;
	}
      char str[12];
      int cur_pos=11;
      str[cur_pos]='\0';
      --cur_pos;
      while(diff > 0)
	{
	  str[cur_pos]='0' + diff%10;
	  diff/=10;
	  --cur_pos;
	}
      puts(str + cur_pos + 1);
    }
  return 0;
}

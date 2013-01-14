#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long readIntFromBufferAndAdvance()
{
  long long noRead=0;
  char p=getchar_unlocked();
  for(;p<33;){p=getchar_unlocked();};
  for(;p>32;)
    {
      noRead = noRead * 10 + (p - '0');
      p=getchar_unlocked();
    }
  return noRead;
};

int main()
{
  int nTestCases =readIntFromBufferAndAdvance();
  int i=0;
  for(i=0;i<nTestCases;++i)
    {
      unsigned int curNum=readIntFromBufferAndAdvance();
      unsigned int curDiff=curNum-1;
      int j=2;
      int sqr=sqrt(curNum);
      for(j=2;j <=sqr;++j)
        {
          if((curNum % j ) == 0)
            {
              unsigned int diff=(curNum/j) - j;
              if(curDiff > diff)
                {
                  curDiff=diff;
                }
            }
        }
      printf("%u\n",curDiff);
    }
   return 0;
}

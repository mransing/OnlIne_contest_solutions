#include <stdio.h>
#include <iostream>
#include <stdlib.h>
 
typedef unsigned long long uulong;
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
 
uulong gcd(uulong a, uulong b)
{
  if(b<a)
    {
      uulong temp=a;
      a=b;
      b=temp;
    }
  if( a == 1)
    {
      return 1;
    }
  while(a>1)
    {
      b = b % a;
      uulong temp=a;
      a=b;
      b = temp;
    }
  if(a == 0)
    {
      return b;
    }
  else
    {
      return 1;
    }
};
 
inline int log10(uulong a)
{
  int k=0;
  while(a>0)
    {
      a/=10;
      ++k;
    }
  return k;
}
 
uulong lcm(uulong a, uulong b)
{
  uulong curGCD=gcd(a,b);
  uulong div=a/curGCD;
  if((log10(div) + log10(b)) >18 )
    {
      return 0;
    }
  else
    {
      return div * b;
    }
}
 
int main()
{
  int nTestCases=readIntFromBufferAndAdvance();
  for(int i=0;i<nTestCases;++i)
    {
      uulong a=readIntFromBufferAndAdvance();
      uulong b=readIntFromBufferAndAdvance();
      uulong c=readIntFromBufferAndAdvance();
      uulong d=readIntFromBufferAndAdvance();
      uulong k=readIntFromBufferAndAdvance();
      uulong p=lcm(gcd(a,b),gcd(c,d));
      if(p)
	{
	  printf("%llu\n",2*(k/p) + 1);
	}
      else
	{
	  printf("%d\n",1);
	}
    }
  return 0;
}

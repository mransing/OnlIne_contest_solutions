#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <ext/hash_map>
#include <ext/hash_set>
#include <set>
#include <time.h>
#include <sys/time.h>
#include <string.h>
 
namespace __gnu_cxx
{
  template<>
  struct hash<unsigned long long>
  {
    size_t
    operator()(unsigned long long __x) const
    { return __x; }
  };
}
 
typedef __gnu_cxx::hash_map<unsigned long long, int > Power2Map;
typedef __gnu_cxx::hash_map<unsigned long long, int>::iterator Power2MapIter;
 
Power2Map simpleMap(1000);
 
unsigned long long pow2Arr[64];
int lInputBufferLength=100 * 4000 * 30;
char *InOrigBuf;
int kCount;
 
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
      noRead = (noRead << 3) + (noRead << 1) + (p - '0');
      p=getchar_unlocked();
    }
  if(sign)
    {
      noRead*=-1;
    }
  return noRead;
};
 
 
typedef struct _row
{
  unsigned long long low;
  unsigned long long high;
}row;
 
inline void Set(row* mat,int i,int j)
{
  row& temprow = mat[i];
  if(j<64)
    {
      temprow.low=temprow.low | pow2Arr[j];
    }
  else
    {
      temprow.high=temprow.high | pow2Arr[j-64];
    }
}
 
inline unsigned long long Get(row* mat,int i,int j)
{
  unsigned long long p =0;
  if(j< 64)
    {
      p=mat[i].low;
    }
  else
    {
      p=mat[i].high;
      j=j-64;
    }
  return p & pow2Arr[j];
}
inline void GetNewSetsBits(row *mat, int i, row& rRow, const row ignoreRow)
{
  row tempRow;
  tempRow.low = mat[i].low & ~(ignoreRow.low);
  tempRow.high = mat[i].high & ~(ignoreRow.high);
  rRow=tempRow;
};
 
inline void Multiply(row *mat,int i, int j)
{
  if(i==j)
    {
      return;
    }
  row& ir=mat[i];
  row& jr=mat[j];
  row p;
  p.low=ir.low | jr.low;
  p.high=ir.high|jr.high;
  ir = p ;
  jr = p ;
}
 
int main()
{
  pow2Arr[0]=1;
  for(int i=1;i<64;i++)
    {
      pow2Arr[i] = 2 * pow2Arr[i-1];
      simpleMap.insert(std::pair<unsigned long long, int>(pow2Arr[i],i));
    }
  int nTestCases = readIntFromBufferAndAdvance();
  for(int i=0;i<nTestCases;++i)
    {
      int nCities=0;
      int nRoads=0;
      nCities=readIntFromBufferAndAdvance();
      nRoads=readIntFromBufferAndAdvance();
      row *mat = new row [nCities];
      memset(mat,0,nCities * sizeof(row));
      row *arrIgnoreSet = new row[nCities];
      memset(arrIgnoreSet,0,nCities * sizeof(row));
 
      for(int j=0;j<nRoads;++j)
	{
	  int city1=readIntFromBufferAndAdvance();
	  int city2=readIntFromBufferAndAdvance();
	  if(city1!=city2)
	    {
	      Set(mat,city1,city2);
	      Set(mat,city2,city1);
	    }
	}
      int nQueries=0;
      nQueries=readIntFromBufferAndAdvance();
      for(int j=0;j<nQueries;++j)
	{
	  int q1=readIntFromBufferAndAdvance();
	  int q2=readIntFromBufferAndAdvance();
	  unsigned long long found=false;
	  if((q1 == q2) || Get(mat,q1,q2) || Get(mat,q2,q1))
	    {
	      found =true;
	      goto printanswer;
	    }
	  if((mat[q1].low == 0 && mat[q1].high ==0)||(mat[q2].low == 0 && mat[q2].high ==0))
	    {
	      found =false;
	    }
	  else
	    {
	      row insertRow;
	      insertRow.low=0;
	      insertRow.high=0;
	      if(q1 < 64)
		{
		  insertRow.low|=pow2Arr[q1];
		  arrIgnoreSet[q1].low|=pow2Arr[q1];
		}
	      else
		{
		  insertRow.high|=pow2Arr[q1-64];
		  arrIgnoreSet[q1].high|=pow2Arr[q1-64];
		}
	      while(insertRow.low > 0 || insertRow.high > 0 )
		{
		  GetNewSetsBits(mat,q1,insertRow,arrIgnoreSet[q1]);
		  while( insertRow.low > 0 || insertRow.high > 0 )
		    {
		      unsigned long long* curByte;
		      if(insertRow.low > 0)
			{
			  curByte = &insertRow.low;
			}
		      else
			{
			  curByte = &insertRow.high;
			}
		      unsigned long long p=*curByte & (*curByte-1);
		      int ithBit;
		      if(insertRow.low > 0)
			{
			  ithBit=simpleMap[p ^ *curByte];
			}
		      else
			{
			  ithBit=simpleMap[p ^ *curByte] + 64;
			}
		      Multiply(mat,q1,ithBit);
		      if(ithBit<64)
			{
			  arrIgnoreSet[q1].low|=pow2Arr[ithBit];
			  if(q1 < 64)
			    {
			      arrIgnoreSet[ithBit].low|=pow2Arr[q1];
			    }
			  else
			    {
			      arrIgnoreSet[ithBit].high|=pow2Arr[q1-64];
			    }
			}
		      else
			{
			  arrIgnoreSet[q1].high|=pow2Arr[ithBit-64];
			  if(q1 < 64)
			    {
			      arrIgnoreSet[ithBit].low|=pow2Arr[q1];
			    }
			  else
			    {
			      arrIgnoreSet[ithBit].high|=pow2Arr[q1-64];
			    }
			}
		      if(Get(mat,q1,q2))
			{
			  found=true;
			  break;
			}
		      *curByte=p;
		    }
		  if(found)
		    {
		      break;
		    }
		  GetNewSetsBits(mat,q1,insertRow,arrIgnoreSet[q1]);
		}
	    }
	printanswer:
	  char *answer;
	  if(found)
	    {
	      putchar_unlocked('Y');putchar_unlocked('O');putchar_unlocked('\n');
	    }
	  else
	    {
	      putchar_unlocked('N');putchar_unlocked('O');putchar_unlocked('\n');
	    }
	}
      delete [] arrIgnoreSet;
      delete [] mat;
    }
  return 0;
}

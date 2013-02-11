#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <map>
#include <vector>
#include <ext/hash_map>

using namespace std;

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

typedef unsigned long long ULONG;

int readIntFromBufferAndAdvance(char **InSomeBuf)
{
  long long noRead=0;
  char *InBuf=*InSomeBuf;
  for(;*InBuf==' ' || *InBuf=='\n' || *InBuf == '\0' || *InBuf == '\r';++InBuf);
  for(;*InBuf!=' ' && *InBuf!='\n' && *InBuf != '\0' && *InBuf != '\r';++InBuf)
	{
	  noRead = (noRead << 3) + (noRead << 1)+ (*InBuf - '0');
	}
  InBuf++;
  *InSomeBuf = InBuf;
  return noRead;  
};

typedef vector<pair<ULONG,ULONG> > vec;
typedef __gnu_cxx::hash_map<ULONG,vec> myMap;

typedef vec::iterator vecIter;
typedef myMap::iterator myIter;

const ULONG mapSize=6 * 100000;

int main()
{
  myMap lMap;
  lMap.resize(mapSize);
  long long lInputBufferLength = 1000000 * 20 ;
  int outBuffSize = 100000 * 30;
  char *InOrigBuf = new char[lInputBufferLength];
  char *InBuf=InOrigBuf;
  char *OutBuf = new char[outBuffSize];
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  read(0,InBuf,lInputBufferLength);
  ULONG nPoints=readIntFromBufferAndAdvance(&InBuf);
  ULONG nQueries=readIntFromBufferAndAdvance(&InBuf);
  for(;nPoints>0;--nPoints)
	{
	  ULONG xp=readIntFromBufferAndAdvance(&InBuf);
	  ULONG yp=readIntFromBufferAndAdvance(&InBuf);
	  ULONG dist=xp + yp;
	  myIter iter = lMap.find(dist);
	  if(iter != lMap.end())
		{
		  iter->second.push_back(pair<ULONG,ULONG>(xp,yp));
		}
	  else
		{
		  vec someVec;
		  someVec.reserve(1000);
		  someVec.push_back(pair<ULONG,ULONG>(xp,yp));
		  lMap[dist]=someVec;
		}
	}
  for(;nQueries>0;--nQueries)
	{
	  ULONG xp=readIntFromBufferAndAdvance(&InBuf);
	  ULONG yp=readIntFromBufferAndAdvance(&InBuf);
	  ULONG dis=readIntFromBufferAndAdvance(&InBuf);
	  ULONG num1=xp + yp;
	  ULONG num2=xp+yp+dis;
	  ULONG i=num1;
	  ULONG nTotal=0;
	  while(i<=num2)
		{
		  vec vec1=lMap[i];
		  for(ULONG k=0;k<vec1.size();++k)
			{
			  ULONG curx=vec1.at(k).first;
			  ULONG cury=vec1.at(k).second;
			  if(((curx < xp) || (cury < yp)) == false)
				{
				  ++nTotal;
				}
			}
		  ++i;
		}
	  int tempBufLen = sprintf(tempOutBuf,"%lld\n",nTotal);
	  tempOutBuf=tempOutBuf + tempBufLen;
	  outBufLen+=tempBufLen;
	}
  write(1,OutBuf,outBufLen);
  delete [] InOrigBuf;
  delete [] OutBuf;
}

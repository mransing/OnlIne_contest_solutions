#include <set>
#include <list>
#include <vector>
#include <queue>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


using namespace std;

typedef vector<list<int> > myList;
typedef list<int>::iterator myIter;

typedef set<int> mySet;
typedef mySet::iterator mySetIter;

long long readIntFromBufferAndAdvance(char **InSomeBuf)
{
  long long noRead=0;
  char *InBuf=*InSomeBuf;
  for(;*InBuf==' ' || *InBuf=='\n' || *InBuf == '\0' || *InBuf == '\r';++InBuf);
  for(;*InBuf!=' ' && *InBuf!='\n' && *InBuf != '\0' && *InBuf != '\r';++InBuf)
	{
	  noRead = noRead * 10 + (*InBuf - '0');
	}
  InBuf++;
  *InSomeBuf = InBuf;
  return noRead;  
};

int main()
{
  long long lInputBufferLength = 100 * 100 * 10000;
  int outBuffSize = 10000;
  char *InOrigBuf = (char *)malloc(lInputBufferLength);
  char *InBuf=InOrigBuf;
  char *OutBuf = (char *)malloc(outBuffSize);
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  read(0,InBuf,lInputBufferLength);
  int nTestCases = readIntFromBufferAndAdvance(&InBuf);
  for(;nTestCases>0;--nTestCases)
	{
	  int nEmp=readIntFromBufferAndAdvance(&InBuf);
	  int nPairs=readIntFromBufferAndAdvance(&InBuf);
	  myList vec(nEmp);
	  mySet empSet;
	  stack<int> st;
	  vector<int> doors;
	  bool* isVisited = new bool[nEmp];
	  for(int i=0;i<nEmp;++i)
		{
		  isVisited[i]=true;
		}

	  for(int i=0;i<nPairs;++i)
		{
		  int fir=readIntFromBufferAndAdvance(&InBuf);
		  int sec=readIntFromBufferAndAdvance(&InBuf);
		  if(fir > sec)
			{
			  int temp=sec;
			  sec=fir;
			  fir=temp;
			}
		  vec[fir-1].push_back(sec-1);
		  empSet.insert(fir-1);
		  empSet.insert(sec-1);
		  isVisited[fir-1]=false;
		  isVisited[sec-1]=false;
		}
	  int single_members=nEmp-empSet.size();
	  while(!empSet.empty())
		{
		  int curTot=1;
		  int curEl=*(empSet.begin());
		  isVisited[curEl]=true;
		  empSet.erase(curEl);
		  if(vec.at(curEl).empty())
			{
			  doors.push_back(1);
			  continue;
			}
		  st.push(curEl);
		  while (!st.empty())
			{
			  int stTop=st.top();
			  list<int>& curList = vec.at(stTop);
			  if(curList.empty())
				{
				  st.pop();
				  continue;
				}
			  while(!curList.empty())
				{
				  int curListElem=curList.front();
				  curList.pop_front();
				  if(isVisited[curListElem] == true)
					{
					  continue;
					}
				  empSet.erase(curListElem);
				  isVisited[curListElem]=true;
				  st.push(curListElem);
				  ++curTot;
				}
			}
		  doors.push_back(curTot);
		}
	  delete [] isVisited;
	  int iSize=doors.size();
	  unsigned long long ways=1L;
	  for(int i=0;i < iSize;++i)
		{
		  if(doors[i] > 1)
			{
			  ways = (ways * doors[i]) % 1000000007;
			}
		}
	  int tempBufLen=sprintf(tempOutBuf,"%u %llu\n",iSize + single_members,ways);
	  tempOutBuf=tempOutBuf + tempBufLen;
	  outBufLen+=tempBufLen;
	}
  write(1,OutBuf,outBufLen);
  free(InOrigBuf);
  free(OutBuf);
  return 0;
}

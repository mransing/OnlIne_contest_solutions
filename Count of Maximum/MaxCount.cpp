#include <ext/hash_set>
#include <queue>
#include <vector>
#include <iostream>
 
int lInputBufferLength=500000;
char *InOrigBuf;
int kCount;
typedef struct _val_freq
{
  int val;
  int freq;
}val_freq;
 
struct hash_func
{
  int operator()(const val_freq& vTrip) const
  {
    __gnu_cxx::hash<int> hashTable;
    return hashTable(vTrip.val);
  }
};
 
struct val_freq_comp
{
  bool operator()(const val_freq& t1, const val_freq& t2) const
  {
    return t1.val == t2.val;
  }
};
 
struct val_freq_que_comp
{
  bool operator()(const val_freq& t1, const val_freq& t2)
  {
    if(t1.freq<t2.freq)
      {
	return true;
      }
    else if(t1.freq>t2.freq)
      {
	return false;
      }
    else
      {
	return(t1.val > t2.val);
      }
  }
};
 
int readIntFromBufferAndAdvance(char *& InBuf)
{
  int noRead=0;
  bool sign=false;
  for(;*InBuf==' ' || *InBuf=='\n' || *InBuf == '\0' || *InBuf == '\r';++InBuf);
  if(*InBuf == '-')
    {
      sign=true;
      InBuf++;
    }
  for(;*InBuf!=' ' && *InBuf!='\n' && *InBuf != '\0' && *InBuf != '\r';++InBuf)
    {
      noRead = noRead * 10 + (*InBuf - '0');
    }
  if(sign)
    {
      noRead*=-1;
    }
  InBuf++;
  return noRead;
};
 
int main()
{
  InOrigBuf = new char[lInputBufferLength];
  char *InBuf=InOrigBuf;
  char *OutBuf = new char[2000];
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  int inBufLen=0;
  kCount = read(0,InBuf,lInputBufferLength);
  int nTestCases = readIntFromBufferAndAdvance(InBuf);
  for(int iTestCase=0;iTestCase<nTestCases;++iTestCase)
    {
      __gnu_cxx::hash_set<val_freq,hash_func,val_freq_comp> theSet;
      typedef __gnu_cxx::hash_set<val_freq,hash_func,val_freq_comp>::iterator theSetIter;
      std::priority_queue<val_freq,std::vector<val_freq>,val_freq_que_comp> theQue;
      int nNumbers=readIntFromBufferAndAdvance(InBuf);
      for(int iNumber=0;iNumber<nNumbers;iNumber++)
	{
	  int p=readIntFromBufferAndAdvance(InBuf);
	  val_freq tempValFreq;
	  tempValFreq.val=p;
	  tempValFreq.freq=1;
	  std::pair<theSetIter,bool> someVar = theSet.insert(tempValFreq);
	  if(someVar.second!=true)
	    {
	      tempValFreq.freq=(someVar.first)->freq + 1;
	    }
	  theSet.erase(someVar.first);
	  theSet.insert(tempValFreq);
	}
      theSetIter tempIter;
      for(tempIter=theSet.begin();tempIter!=theSet.end();tempIter++)
	{
	  theQue.push(*tempIter);
	}
      val_freq temp=theQue.top();
      int tempBufLen=sprintf(tempOutBuf,"%d %d\n",temp.val,temp.freq);
      tempOutBuf = tempOutBuf + tempBufLen;
      outBufLen+=tempBufLen;
    }
  write(1,OutBuf,outBufLen);
  delete [] InOrigBuf;
  delete [] OutBuf;
  return 0;
}

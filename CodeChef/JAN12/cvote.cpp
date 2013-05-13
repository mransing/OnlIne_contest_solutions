#include <map>
#include <queue>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <iostream>

typedef std::map<int,std::string> mapIntStr;
typedef mapIntStr::iterator iterIntStr;

typedef std::map<std::string,int> mapStrInt;
typedef mapStrInt::iterator iterStrInt;


typedef std::map<int,int> mapIntInt;
typedef mapIntInt::iterator iterIntInt;

typedef std::pair<std::string,int> pairStrInt;
typedef std::pair<int,std::string> pairIntStr;
typedef std::pair<int,int> pairIntInt;

typedef std::priority_queue<int> queInt;

bool someStrFunc(std::string lhs, std::string rhs)
{
  return (lhs > rhs);
};

bool somefunc(pairIntInt lhs,pairIntInt rhs)
{
  return  (lhs.second < rhs.second);
};

int main()
{
  mapStrInt plMap,cnMap;
  mapIntStr mPlMap,mCnMap;
  mapIntInt plCnMap,plScoreMap,cnScoreMap;
  
  int nPlayers,nVotes;
  int nCont=0;
  scanf("%d %d",&nPlayers,&nVotes);
  for(;nPlayers>0;--nPlayers)
	{
	  char plName[12];
	  char contName[12];
	  scanf("%s %s",&plName,&contName);	  
	  plMap.insert(pairStrInt(std::string(plName),nPlayers));
	  mPlMap.insert(pairIntStr(nPlayers,std::string(plName)));

	  std::pair<iterStrInt,bool> tmpIter=cnMap.insert(pairStrInt(std::string(contName),nCont));
	  // cnMap.insert(pairStrInt(std::string(contName),nCont));
   
	  if(tmpIter.second == true)
		{
		  mCnMap.insert(pairIntStr(nCont,std::string(contName)));
		  ++nCont;
		}
	  plCnMap.insert(pairIntInt(nPlayers,cnMap[std::string(contName)]));
	};
  
#ifdef __DEBUG__
  for(iterStrInt pIter=plMap.begin();pIter!=plMap.end();++pIter)
	{
	  std::cout << pIter->first << " " << pIter->second << std::endl; 
	}

    for(iterStrInt pIter=cnMap.begin();pIter!=cnMap.end();++pIter)
	{
	  std::cout << pIter->first << " " << pIter->second << std::endl; 
	};

	for(iterIntStr pIter=mPlMap.begin();pIter!=mPlMap.end();++pIter)
	{
	  std::cout << pIter->first << " " << pIter->second << std::endl; 
	}

    for(iterIntStr pIter=mCnMap.begin();pIter!=mCnMap.end();++pIter)
	{
	  std::cout << pIter->first << " " << pIter->second << std::endl; 
	};

	for(iterIntInt pIter=plCnMap.begin();pIter!=plCnMap.end();++pIter)
	{
	  std::cout << pIter->first << " " << pIter->second << std::endl; 
	};
	
	std::cout << "end of input 1" << std::endl;
#endif __DEBUG__
  queInt plQue,cnQue;
  for(;nVotes > 0;--nVotes)
  {
	char plName[12];
	scanf("%s",&plName);
	int iPl = plMap[std::string(plName)];
	std::pair <iterIntInt,bool> tmpIter=plScoreMap.insert(pairIntInt(iPl,1));
	if(tmpIter.second==false)
	  {
		iterIntInt pIter = plScoreMap.find(iPl);
		++(pIter->second);
	  }
	int iCn=plCnMap[iPl];
	tmpIter=cnScoreMap.insert(pairIntInt(iCn,1));
	if(tmpIter.second==false)
	  {
		iterIntInt pIter = cnScoreMap.find(iCn);
		++(pIter->second);
	  }
  };

#ifdef __DEBUG__
  for(iterIntInt pIter=plScoreMap.begin();pIter!=plScoreMap.end();++pIter)
	{
	  std::cout << pIter->first << " " << pIter->second << std::endl; 
	};
  
  for(iterIntInt pIter=cnScoreMap.begin();pIter!=cnScoreMap.end();++pIter)
	{
	  std::cout << pIter->first << " " << pIter->second << std::endl; 
	};
  
  
#endif __DEBUG__
  
  bool(*fn_pt)(pairIntInt,pairIntInt) = somefunc;
  std::priority_queue<pairIntInt,std::vector<pairIntInt>,bool(*)(pairIntInt,pairIntInt)> plQueue(fn_pt);
  std::priority_queue<pairIntInt,std::vector<pairIntInt>,bool(*)(pairIntInt,pairIntInt)> cnQueue(fn_pt);
  
  iterIntInt iter=plScoreMap.begin();
  for(;iter!=plScoreMap.end();++iter)
	{
	  pairIntInt p(iter->first,iter->second);
	  plQueue.push(p);
	};
  
  iter=cnScoreMap.begin();
  for(;iter!=cnScoreMap.end();++iter)
	{
	  pairIntInt p(iter->first,iter->second);
	  cnQueue.push(p);
	};

  std::priority_queue<std::string,std::vector<std::string>, bool(*) (std::string,std::string)> plStrQueue(&someStrFunc);
  int perPl = plQueue.top().second;
  int curPl = perPl;
  while(plQueue.empty() == false && perPl == curPl)
	{
	  pairIntInt pInt = plQueue.top();
	  plStrQueue.push(mPlMap[pInt.first]);
	  plQueue.pop();
	  pInt = plQueue.top();
	  curPl = pInt.second;
	}

  std::priority_queue<std::string,std::vector<std::string>, bool(*) (std::string,std::string)> cnStrQueue(someStrFunc);
  int perCn = cnQueue.top().second;
  int curCn = perCn;
  while(cnQueue.empty() == false && perCn == curCn)
	{
	  pairIntInt pInt = cnQueue.top();
	  cnStrQueue.push(mCnMap[pInt.first]);
	  cnQueue.pop();
	  pInt = cnQueue.top();
	  curCn = pInt.second;
	}
  
  printf("%s\n%s",cnStrQueue.top().c_str(),plStrQueue.top().c_str());
  return 0;
}

#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <assert.h>
#include <iostream>

using namespace std;

const int max_const=200;

pair<bool,int> isSingleElementRemain(bool *arr, int n)
{
  int count=0;
  int last=0;
  int i=0;
  for(i=0;i<n;++i)
	{
	  if(arr[i]==false)
		{
		  ++count;
		  last=i;
		  if(count > 1)
			break;
		}
	}
  //if (count == 0) assert(0);
  if(count !=1 ) 
	{
	  pair<bool,int> p(false,0);
	  return p; 
	}
  else 
	{
	  pair<bool,int> p(true,last);
	  return p; 
	}
}

void TestSingleElementRemain()
{
  bool arr[]={true,true,false,true,true,true};
  int i=sizeof(arr)/sizeof(arr[0]);
  pair<bool,int> p = isSingleElementRemain(arr,i);
  cout << p.first << " " << p.second << std::endl;
};

int singlePass(bool* arr,int n,int k, int start)
{
  if(arr[start] == false) assert(0);
  int begin=(start+1) % n;
  int total=0;
  while(total < k)
	{
	  if(arr[begin]==false)
		{
		  ++total;
		}
	  begin=(begin + 1) % n;
	}
  return (begin - 1 + n) % n;
}

void TestSinglePass()
{
  bool arr[]={true,true,false,true,false,false};
  int i=sizeof(arr)/sizeof(arr[0]);
  int p = singlePass(arr,i,3,1);
  cout << p << std::endl;
};

int RunWhileSingleElememtRemain(bool *arr, int n, int k)
{
  int i=0;
  for(i=0;i<=n;++i)
	{
	  arr[k]=false;
	}
  arr[0]=true;
  bool done=false;
  int newBegin=0;
  int last=0;
  while(!done)
	{
	  std::pair<bool,int> p;
	  int q=singlePass(arr,n,k,newBegin);
	  newBegin=q;
	  arr[q]=true;
	  p=isSingleElementRemain(arr,n);
	  if((p.first == false) && (q == 12))
		{
		  last = 0;
		  done=true;
		}
	  else
		{
		  done=p.first;
		  if(done) last=p.second;
		}
	}
  return last;
}

void TestRunWhileSingleElementRemain()
{
  bool arr[7];
  int i=10;
  std::cout << RunWhileSingleElememtRemain(arr,i,10) << std::endl;
};

int main()
{
  //TestSingleElementRemain();
  //TestSinglePass();
  //bool arr1[1000];
  //TestRunWhileSingleElementRemain();
  //return 0;
  int n=0;
  char OutBuffer[5000];
  scanf("%d",&n);
  while(n!=0)
	{
	  bool done=false;
	  int start=2;
	  while(!done)
		{
		  bool arr[max_const];
		  int p=RunWhileSingleElememtRemain(arr,n,start);
		  if (p == 12)
			{
			  done=true;
			}
		  else
			{
			  ++start;
			}
		}
	  printf("\n%d",start);
	  fflush(stdout);
	  scanf("%d",&n);
	}
  return 0;
}

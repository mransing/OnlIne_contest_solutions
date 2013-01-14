#include<iostream>
#include<queue>
 
using namespace std;
typedef long long LLONG;
 
struct chef
{
  LLONG age;
  int rank;
};
 
template<bool revese>
class MyCompare
{
public:
  bool operator() (chef lhs, chef rhs) const
  {
    return (lhs.age < rhs.age);
  };
};
 
template<>
class MyCompare<true>
{
public:
  bool operator() (chef lhs, chef rhs) const
  {
    return (lhs.age>rhs.age);
  };
};
 
int main()
{
  typedef priority_queue<int,vector<chef>,MyCompare<false> > mypq_type;
  typedef priority_queue<int,vector<chef>,MyCompare<true> > mypq_type_rev;
 
  LLONG cur1Rank = 0L;
  LLONG cur2Rank = 0L;
  mypq_type gr1;
  mypq_type_rev gr2;
 
  int n;
  scanf("%d",&n);
  for(int i=0;i<n;i++)
    {
      LLONG Age = 0L;
      int r = 0;
      scanf("%lld",&Age);
      scanf("%d",&r);
      chef c;
      c.rank=r;
      c.age=Age;
      if(i ==0)
	{
	  cur1Rank=r;
	  gr1.push(c);
	  printf("%d\n",r);
	  continue;
	}
      if(gr1.size() == gr2.size())
	{
	  //Insert in gr1
	  chef p = gr2.top();
	  if (Age > p.age)
	    {
	      //Remove from group 2
	      gr2.pop();
	      cur2Rank -= p.rank;
	      //Insert in group1
	      gr1.push(p);
	      cur1Rank+=p.rank;
	      //Add in gr2
	      gr2.push(c);
	      cur2Rank = cur2Rank + r;
	    }
	  else
	    {
	      //Add in gr1
	      gr1.push(c);
	      cur1Rank+=c.rank;
	    }
	}
      else
	{
	  //Insert in gr2
	  chef p = gr1.top();
	  if (Age < p.age)
	    {
	      //Remove from group 1
	      gr1.pop();
	      cur1Rank -= p.rank;
	      //Insert in group2
	      gr2.push(p);
	      cur2Rank+=p.rank;
	      //Add in gr1
	      gr1.push(c);
	      cur1Rank = cur1Rank + r;
	    }
	  else
	    {
	      //Add in gr2
	      gr2.push(c);
	      cur2Rank+=c.rank;
	    }
	}
      if(cur1Rank > cur2Rank)
	{
	  printf("%lld\n",cur1Rank-cur2Rank);
	}
      else
	{
	  printf("%lld\n",cur2Rank-cur1Rank);
	}
    }
  return 0;
}

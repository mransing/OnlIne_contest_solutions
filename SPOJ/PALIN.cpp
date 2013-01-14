#include<iostream>
#include<stdio.h>
#include<cmath>
#include<vector>
#include<algorithm>
#include<string.h>
#define SZ(s) s.size()
#define PB(num) push_back(num)
 
using namespace std;
 
 
/*string bigAdd(string str1, string str2)
  {
  string s1, s2, ans;
  if(SZ(str1) < SZ(str2))
  {
  s2 = str1;
  s1 = str2;
  }
  else
  {
  s1 = str1;
  s2 = str2;
  }
  s2.insert(0, SZ(s1) - SZ(s2), '0');
  int cnt = SZ(s1) - 1;
  int i, sum, carry = 0;
  for(i = SZ(s1)-1; cnt >= 0; cnt--,i--)
  {
  sum = (s1[cnt] - '0') + (s2[cnt] - '0') + carry;
  carry = (int)(sum / 10);
  sum = sum % 10;
  ans.push_back((char)(sum + '0'));
  }
  if(carry != 0)
  {
  ans.push_back((char)(carry+'0'));
  }
  reverse(ans.begin(),ans.end());
  return ans;
  }*/
 
void AddOne(char *s1)
{
  int cnt = strlen(s1) - 1;
  int i =0;
  bool carry = true;
  for(i = cnt;i>=0 && carry;i--)
    {
      if(s1[i] < '9')
	{
	  s1[i]++;
	  carry = false;
	}
      else
	{
	  s1[i] = '0';
	  carry = true;
	}
    }
}
 
//212 --> 313?
 
//string s;
char *s;
int findPalin(int start, int end, bool greaterRequired)
{
  //even palindromes only!
  if(end < start)
    return 0;
  if(end == start)
    {
      if(greaterRequired)
	{
	  s[start] = ((s[start]-'0') + 1)%10 + '0';
	  if(s[start] == '0')
	    return -1;
	  return 1;
	}
      return 0;
    }
  if(end == start + 1 && greaterRequired && s[end] == s[start])
    {
      s[start] = ((s[start]-'0') + 1)%10 + '0';
      s[end] = ((s[end]-'0') + 1)%10 + '0';
      if(s[start] == '0') return -1;
      return 1;
    }
 
  if(s[start] == s[end])
    {
 
      return findPalin(start + 1, end - 1, greaterRequired);
 
    }
  else if(s[end] < s[start])
    {
      s[end] = s[start];
      int greater = findPalin(start + 1, end - 1, false);
      if(greater == -1)
	{
	  for(int i = start + 1; i < end; i++) s[i] = '0';
	  return 1;
	}
      else //good
	{
	  return greater;
	}
    }
  else
    {
      s[end] = s[start];
      int greater = findPalin(start + 1, end - 1, true);
      if(greater == 1) //happy
	{
	  return greater;
	}
      else
	{
	  s[start]++;s[end]++;
	  for(int i = start + 1; i < end; i++) s[i] = '0';
	  return 1;
	}
    }
}
 
 
char a[1000002];
int main()
{
  int cases, cas;
  //char buf[500000000];
  //read(0,buf,410*100);
  scanf("%d",&cases);
  for(cas = 0; cas < cases; cas++)
    {
      scanf("%s", a);
      int len =strlen(a);
      //Case for all 9's
      int i=0;
      for(;i<len;i++)
	{
	  if(a[i] != '9')
	    {
	      break;
	    }
	}
      if(i == len)
	{
	  printf("1");
	  for(int j=0;j<len -1;++j)
	    {
	      printf("0");
	    }
	  printf("1\n");
	  continue;
	}
      s = a;
      int j;
      for(i = 0, j = strlen(s) - 1; i <= j; i++, j--)
	{
	  if(s[i] != s[j])
	    break;
	}
      if(i > j)
	{
	  //s = bigAdd(s, "1");
	  AddOne(s);
	}
      int greater = findPalin(0, strlen(s)-1, false);
      //cout << s << endl;
      printf("%s\n",s);
    }
  return 0;
}

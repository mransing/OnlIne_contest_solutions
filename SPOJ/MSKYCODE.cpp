#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
 
const long MAXP = 10000;
long prime[MAXP] = {0} , num_prime = 0;
int isNotPrime[MAXP] = {1, 1};

int icCount[10005] = {0};
long long C4[10005] = {0};
long countNum[10005];

int main()
{

 
  long n, i, j, maxnum;
  long count;
  long long psn, res;


  for(i = 2 ; i <  MAXP ; i ++)
    {
	  if(! isNotPrime[i])
		prime[num_prime ++]=i;
	  for(j = 0 ; j < num_prime && i * prime[j] <  MAXP ; j ++)
        {
		  isNotPrime[i * prime[j]] = 1;
		  if( !(i % prime[j]))
			break;
        }
    }


  for(i = 0; i < num_prime; i ++)
    {
	  icCount[ prime[i] ] = 1;
	  for(j = 2; j < 10005 && j * prime[i] < 10005; j ++)
        {
		  if(j % prime[i] && icCount[j])
			icCount[j * prime[i]] = icCount[j] + 1;
        }
    }
  for(j = 2; j < 10005; j ++)
	if(icCount[j])
	  icCount[j] = (icCount[j] % 2)? 1: -1;

  for(i = 4; i < 10005; i ++)
	C4[i] = ((long long)((i) * (i - 1) / 2) * (long long)(i - 2) / 3) * (long long)(i - 3) / 4;

  while(scanf("%ld", &n) != EOF)
    {
	  maxnum = 0;
	  memset(countNum, 0, sizeof(countNum));
	  for(i = 0; i < n; i ++)
        {
		  scanf("%ld", &count);
		  maxnum = (maxnum > count)? maxnum: count;
		  countNum[count] ++;
		  for(j = 2; j * j <= count; j ++)
            {
			  if(count % j == 0)
                {
				  countNum[j] ++;
				  if(j * j != count)
					countNum[count / j] ++;
                }
            }
        }
	  if(n < 4)
        {
		  printf("0\n");
		  continue;
        }
	  psn = 0;
	  for(i = 2; i <= maxnum; i ++)
        {
		  if(!icCount[i])
			continue;
		  psn += icCount[i] * C4[countNum[i]];
        }
	  res = C4[n];
	  printf("%lld\n", res - psn);
    }
 
  return 0;
}

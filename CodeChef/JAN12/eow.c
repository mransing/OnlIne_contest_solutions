#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

int prime_array_numbers[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97,101,103,107,109,113,127,131,137,139,149,151,157,163,167,173,179,181,191,193,197,199,211,223,227,229,233,239,241,251,257,263,269,271,277,281,283,293,307,311,313,317,331,337,347,349,353,359,367,373,379,383,389,397,401,409,419,421,431,433,439,443,449,457,461,463,467,479,487,491,499,503,509,521,523,541,547,557,563,569,571,577,587,593,599,601,607,613,617,619,631,641,643,647,653,659,661,673,677,683,691,701,709,719,727,733,739,743,751,757,761,769,773,787,797,809,811,821,823,827,829,839,853,857,859,863,877,881,883,887,907,911,919,929,937,941,947,953,967,971,977,983,991,997,1009,1013,1019,1021,1031,1033,1039,1049,1051,1061,1063,1069,1087,1091,1093,1097,1103,1109,1117,1123,1129,1151,1153,1163,1171,1181,1187,1193,1201,1213,1217,1223,1229,1231,1237,1249,1259,1277,1279,1283,1289,1291,1297,1301,1303,1307,1319,1321,1327,1361,1367,1373,1381,1399,1409,1423,1427,1429,1433,1439,1447,1451,1453,1459,1471,1481,1483,1487,1489,1493,1499,1511,1523,1531,1543,1549,1553,1559,1567,1571,1579,1583,1597,1601,1607,1609,1613,1619,1621,1627,1637,1657,1663,1667,1669,1693,1697,1699,1709,1721,1723,1733,1741,1747,1753,1759,1777,1783,1787,1789,1801,1811,1823,1831,1847,1861,1867,1871,1873,1877,1879,1889,1901,1907,1913,1931,1933,1949,1951,1973,1979,1987,1993,1997,1999,2003,2011,2017,2027,2029,2039,2053,2063,2069,2081,2083,2087,2089,2099,2111,2113,2129,2131,2137,2141,2143,2153,2161,2179,2203,2207,2213,2221,2237,2239,2243,2251,2267,2269,2273,2281,2287,2293,2297,2309,2311,2333,2339,2341,2347,2351,2357,2371,2377,2381,2383,2389,2393,2399,2411,2417,2423,2437,2441,2447,2459,2467,2473,2477,2503,2521,2531,2539,2543,2549,2551,2557,2579,2591,2593,2609,2617,2621,2633,2647,2657,2659,2663,2671,2677,2683,2687,2689,2693,2699,2707,2711,2713,2719,2729,2731,2741,2749,2753,2767,2777,2789,2791,2797,2801,2803,2819,2833,2837,2843,2851,2857,2861,2879,2887,2897,2903,2909,2917,2927,2939,2953,2957,2963,2969,2971,2999,3001,3011,3019,3023,3037,3041,3049,3061,3067,3079,3083,3089,3109,3119,3121,3137,3163};

int readIntFromBufferAndAdvance(char **InSomeBuf)
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

int *prime_big_arr;
int lPrimeArr = sizeof(prime_array_numbers)/sizeof(int);
int maxKnownPrime = 3163;
int *primeMap;
int nPrimeNum;

typedef enum _someenum {even,odd,prime} enumType;

inline int isPrime_bare (int n)
{
  int i;
  int q=sqrt(n);
  for(i = 1; ((n % prime_big_arr[i]) != 0) && (prime_big_arr[i] < q + 1) ;++i);
  if((prime_big_arr[i] * prime_big_arr[i]) < (n + 1)) return 0;else return 1;
};

int isPrime (int n)
{
  if(n <= maxKnownPrime)
	{
	  return primeMap[n];
	}
  if(isPrime_bare(n) == 0)
	{
	  return 0;
	}
  //We know that this number is prime and we need to find all the numbers between this and the maxKnownPrime;
  int i=0;
  for(i=maxKnownPrime + 2;i< n;i+=2)
	{
	  if(isPrime_bare(i) == 0)
		continue;
	  maxKnownPrime = i;
	  prime_big_arr[nPrimeNum] = i;
	  primeMap[i]=nPrimeNum;
	  ++nPrimeNum;
	}
  maxKnownPrime = n;
  prime_big_arr[nPrimeNum] = n;
  primeMap[n] = nPrimeNum;
  ++nPrimeNum;
  return (nPrimeNum - 1);
};
 
typedef struct _stackElem
{
  int row;
  int col;
}stackElem;

stackElem *stack;
int stackLen;
enumType *matEnum;

inline int isEmpty(void)
{
  return (stackLen == -1); 
};

inline stackElem pop(void)
{
  --stackLen;
  return stack[stackLen+1];
  
};

inline void push(stackElem st)
{
  ++stackLen;
  stack[stackLen] = st;
};

int isEnd(stackElem n, enumType et, stackElem* retStackElem, int nSize, int *matVisit)
{
  int k;
  int x = n.row;
  int y = n.col;
  int newx;
  int newy;

  if(x + 1 < nSize)
	{
	  newx=x+1;
	  newy=y;
	  k = newx * nSize + newy;
	  
	  if(matVisit[k] == 0 && matEnum[k] == et)
		{
		  retStackElem->row = newx;
		  retStackElem->col = newy;
		  return 1;
		}
	}
  
  if(y+1 < nSize)
	{
	  newx=x;
	  newy=y+1;
	  k = newx * nSize + newy;
	  if(newy < nSize)
		{
		  if(matVisit[k] == 0 && matEnum[k] == et)
			{
			  retStackElem->row = newx;
			  retStackElem->col = newy;
			  return 1;
			}
		}
	}

  if(x - 1 > -1)
	{
	  newx = x-1;
	  newy = y;
	  k = newx * nSize + newy;
	  if(newx > -1)
		{
		  if(matVisit[k] == 0 && matEnum[k] == et)
			{
			  retStackElem->row = newx;
			  retStackElem->col = newy;
			  return 1;
			}
		}
	}
  if (y-1 > -1)
	{
	  newx=x;
	  newy=y-1;
	  k = newx * nSize + newy;
	  if(newy > -1)
		{
		  if(matVisit[k] == 0 && matEnum[k] == et)
			{
			  retStackElem->row = newx;
			  retStackElem->col = newy;
			  return 1;
			}
		}
	}
  return 0;
};

void printStack()
{
  int i=0;
  printf("Current Stack\n");
  for(i=0;i<=stackLen;++i)
	{
	  printf("%d %d %d\n",stack[i].row, stack[i].col);
	}
  printf("End of Stack\n");
};

void printVisit(int * mapVisit, int nSize)
{
  int i=0;
  printf("Current mapVisit\n");
  for(i=0;i<nSize;++i)
	{
	  int j =0;
	  for(j=0;j<nSize;++j)
		{
		  printf("%d ",mapVisit[i * nSize +j ]);
		}
	  printf("\n");
	}
  printf("End of mapVisit\n");
};

void printMat(int *mat, int nSize)
{
  int i=0;
  printf("Current mat\n");
  for(i=0;i<nSize;++i)
	{
	  int j =0;
	  for(j=0;j<nSize;++j)
		{
		  printf("%8d ",mat[i * nSize +j ]);
		}
	  printf("\n");
	}
  printf("End of mat\n");
};

int main()
{
  struct timeval t1,t2,t3,t4;
  gettimeofday(&t1,NULL);
  primeMap = malloc(sizeof(int) * 10000000);
  memset(primeMap,0,sizeof(int) * 10000000);
  prime_big_arr = malloc(sizeof(int) * 10000000);
  nPrimeNum=lPrimeArr;
  memcpy(prime_big_arr,prime_array_numbers,lPrimeArr * sizeof(int));

  int i;
  for(i=0;i<nPrimeNum;++i)
	{
	  primeMap[prime_big_arr[i]] = i;
	};

  long long lInputBufferLength = 350 * 350 * 8 * 20;
  int outBuffSize = 10000;
  char *InOrigBuf = malloc(lInputBufferLength);
  char *InBuf=InOrigBuf;
  char *OutBuf = malloc(outBuffSize);
  char *tempOutBuf=OutBuf;
  int outBufLen=0;
  read(0,InBuf,lInputBufferLength);
  int nTestCases = readIntFromBufferAndAdvance(&InBuf);
  double p = 0.0L;
  for(;nTestCases > 0;--nTestCases)
	{
	  int nSize=readIntFromBufferAndAdvance(&InBuf);
	  int i,j,kCur;
	  int *mat;
	  long long total=0;
	  mat = malloc(nSize*nSize*sizeof(int));
	  matEnum = malloc(nSize * nSize * sizeof(matEnum));
	  stack = malloc(nSize*nSize*sizeof(stackElem));
	  int *matVisit = malloc(nSize * nSize * sizeof(int));
	  memset(matVisit,0,nSize * nSize * sizeof(int));
	  stackLen=-1;
	  for(kCur=0;kCur< nSize*nSize;++kCur)
		{
		  
		  mat[kCur]=readIntFromBufferAndAdvance(&InBuf);

		  if(mat[kCur] == 2)
			{
			  matEnum[kCur]=prime;
			  mat[kCur]=0;
			  matVisit[kCur]=1;
			  continue;
			}
		  if((mat[kCur] & 1) == 0)
			{
			  matEnum[kCur]=even;
			}
		  else
			{
			  gettimeofday(&t2,NULL);
			  int ntries = isPrime(mat[kCur]); 
			  gettimeofday(&t3,NULL);
			  p+=((t3.tv_sec - t2.tv_sec) * 1000000 + (t3.tv_usec - t2.tv_usec))/1000000.0;
			  if(ntries != 0)
				{
				  mat[kCur]=ntries;
				  matEnum[kCur]=prime;
				  matVisit[kCur]=1;
				  total+=ntries;
				}
			  else
				{
				  matEnum[kCur]=odd;
				}
			}
		}
	  
	  for(kCur=0;kCur< nSize*nSize;++kCur)
		{
		  if(matVisit[kCur] == 1)
			{
			  continue;
			}
		  //This is new node and neibhors needs to be calculated and mark
		  enumType curEnum = matEnum[kCur];
		  int curVal;
		  if(curEnum == even)
			{
			  curVal = mat[kCur] >> 1;
			}
		  else
			{
			  curVal = (mat[kCur] >> 1) + 2;
			}
		  stackElem curPoint;
		  curPoint.row=kCur/nSize;
		  curPoint.col=kCur % nSize;
		  total+=curVal;
		  matVisit[kCur] = 1;
		  push(curPoint);
		  stackElem newStElem;
		  while(1)
			{
			  if (isEnd(curPoint,curEnum,&newStElem,nSize,matVisit) == 0)
				{
				  if(isEmpty())
					{
					  break;
					}
				  curPoint = pop();
				  continue;
				}
#ifdef __TEST__
			  printf("New visited is %d %d \n",newStElem.row, newStElem.col);
#endif  
			  matVisit[newStElem.row *nSize+ newStElem.col] = 1;
			  push(curPoint);
			  push(newStElem);
			  curPoint = newStElem;
			}
#ifdef __TEST__
		  printf("Total after visiting Node %d %d is %d\n",i,j,total);
		  printVisit(matVisit,nSize);
#endif
		}
	  gettimeofday(&t4,NULL);
#ifdef __TEST__
	  printMat(mat,nSize);
#endif	  
	  free(stack);
	  free(mat);
	  free(matEnum);
	  free(matVisit);
	  int tempBufLen=sprintf(tempOutBuf,"%llu\n",total);
	  tempOutBuf=tempOutBuf + tempBufLen;
	  outBufLen+=tempBufLen;
	}
  write(1,OutBuf,outBufLen);
  free(InOrigBuf);
  free(OutBuf);
  free(prime_big_arr);
  free(primeMap);
  //printf("%f ",((t2.tv_sec - t1.tv_sec) * 1000000 + (t2.tv_usec - t1.tv_usec))/1000000.0);
  printf("%f ",p);
  //printf("%f ",((t4.tv_sec - t3.tv_sec) * 1000000 + (t4.tv_usec - t3.tv_usec))/1000000.0);
  return 0;
}

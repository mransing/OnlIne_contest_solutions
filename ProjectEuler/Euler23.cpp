#include <iostream>
#include <algorithm>
#include <functional>
#include <math.h>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;

std::vector<int> Divisors(int n){
	int p=sqrt(n);
	std::vector<int> retVec; 
	if(p * p == n){retVec.push_back(p);}else{p=p+1;};
	for(int i=2;i < p;++i ){
		if(n%i == 0){
			retVec.push_back(i);
			retVec.push_back(n/i);
		}
	}
	return retVec;
}

bool sumDivisorsIfGreaterThann(int n){
	auto vec=Divisors(n);
	int Sum = 1 + std::accumulate(vec.begin(),vec.end(),0,std::plus<int>());
	if(Sum > n){
		return true;
	}else{
		return false;
	}
};

int main(){
	std::vector<int> vec;
	for (int i=10; i<20162; ++i){
		if( sumDivisorsIfGreaterThann(i) ){
			vec.push_back(i);
		}	
	}
	std::unordered_set<int> sumAdun;
	int vecLen=vec.size();
	for(int i=0;i<vecLen;++i){
		for(int j=i;j<vecLen;++j){
			if(vec[i] + vec[j] <= 20162){
				sumAdun.insert(vec[i] + vec[j]);
			}
		}
	}
	std::vector<int> nonSumAdun;
	for(int k=20162;k>0;--k){
		if(sumAdun.find(k) == sumAdun.end()){
			nonSumAdun.push_back(k);
		}
	}
	std::cout << std::accumulate(nonSumAdun.begin(),nonSumAdun.end(),0,std::plus<int>());
		
	return 0;
}

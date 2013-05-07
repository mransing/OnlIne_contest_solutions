#include <set>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  int nTestCases;
  char par1[40001],par2[40001];
  scanf("%d",&nTestCases);
  for(;nTestCases > 0;nTestCases--){
	scanf("%s %s",par1,par2);
	int len1=strlen(par1);
	std::multiset<char> multset(par1,par1+len1);
	char *tempPar2=par2;
	char c;
	while((c = *tempPar2++) != 0){
	  multset.insert(c);
	};
	int nChildren=0;
	scanf("%d",&nChildren);
	bool child_not_found=false;
	for(;nChildren > 0;--nChildren){
	  char child[40001];
	  scanf("%s",child);
	  if(child_not_found){
		continue;
	  }
	  char* tempChildPtr=child;
	  char c;
	  while((c=*tempChildPtr++) != 0){
		std::multiset<char>::iterator iterMult=multset.find(c);
		if( iterMult == multset.end()){
		  child_not_found=true;
		  break;
		}
		multset.erase(iterMult);
	  }
	}
	if(child_not_found){
	  printf("NO\n");
	}
	else{
	  printf("YES\n");
	}
  }
  return 0;
}

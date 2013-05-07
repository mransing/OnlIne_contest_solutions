#include <set>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
  std::multiset<char> multset;
  int nTestCases;
  scanf("%d\n",&nTestCases);
  char c;
  for(;nTestCases > 0;nTestCases--){
	while((c = getchar_unlocked()) != '\n'){
	  if(c==' '){
		continue;
	  }
	  multset.insert(c);
	};
	int nChildren=0;
	scanf("%d\n",&nChildren);
	bool child_not_found=false;
	for(;nChildren > 0;--nChildren){
	  if(child_not_found){
		continue;
	  }
	  while( (c=getchar_unlocked()) != '\n') {
		if(child_not_found){
		  continue;
		}
		std::multiset<char>::iterator iterMult=multset.find(c);
		if( iterMult == multset.end()){
		  child_not_found=true;
		  continue;
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

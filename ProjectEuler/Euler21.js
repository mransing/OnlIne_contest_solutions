function getDivisorSum(n){
    var j = Math.floor(Math.sqrt(n));
    var sum=0;
    var perfectSquare=false;
    if(j * j == n){
	perfectSquare = true;
    }
     for(i=2;i < j + 1; i++){
	if((n % i) == 0){
	    sum = sum + i;
	    if(!((perfectSquare) && (i == j))){
		sum = sum + (Math.floor(n / i));
	    }
	}
    }
    return [n,sum + 1];
}

function range(start, end) {
    var foo = [];
    for (var i = start; i <= end; i++) {
        foo.push(i);
    }
    return foo;
}

var n =10000;
var arr1=range(1,n);
var arr2=arr1.map(getDivisorSum);
var newSum=0;
var arr2Len=arr2.length;
for(i = 1;i<arr2Len;i++){
    if(arr2[i][1] <= n){
	if((arr2[i][1] > arr2[i][0]) && (arr2[arr2[i][1]-1][1] == arr2[i][0])){
	    newSum=newSum + arr2[i][0] + arr2[i][1];
	    print(arr2[i][0] + " " + arr2[i][1] + " " + arr2[arr2[i][1]-1][1]);
	}
    }
}

print(newSum);

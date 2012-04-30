#!/usr/bin/python
import sys
import operator as op
def ncr(n, r):
    r = min(r, n-r)
if r == 0: return 1
if r ==1: return n
num = reduce(op.mul, xrange(n, n-r, -1))
denom = reduce(op.mul, xrange(1, r+1))
return num//denom

constVal=1000000007
data = raw_input();
iNumbers=eval(data)
for i in range(0,iNumbers):
    newdata=raw_input()
totalLen=len(newdata)
dl={}
for j in range(0,len(newdata)):
    curChar=newdata[j];
if(dl.has_key(curChar)):
    temp=dl[curChar]
dl[curChar]=temp+1
else:
    dl[curChar]=1
alist=dl.values()
nonOneElems=0
final=1
remainingElems=totalLen
for j in range(0,len(alist)):
    curElem=alist[j]
if (curElem != 1):
    combVal=ncr(remainingElems,curElem) % constVal
final=(final*combVal) % constVal
remainingElems=remainingElems-curElem

if(remainingElems>1):
    num = reduce(op.mul, xrange(remainingElems, 1, -1)) % constVal
final=(final*num) % constVal
print final

#!/bin/bash
declare -i NTEST=8
echo "$NTEST"
for k in $(eval echo {1..$NTEST})
do
	declare -i VAR=350
	echo $VAR
	for i in $(eval echo {1..$VAR})
	do
		for j in $(eval echo {1..$VAR})
		do
			declare -i VAR1=`echo $(od -vAn -N4 -tu4 < /dev/urandom)`
			declare -i VAR2=$(($VAR1 % 10000000))
			echo -n "$VAR2 "
		done
		echo ""
	done
done

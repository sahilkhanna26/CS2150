#!/bin/bash
#Reading in input
echo "enter the exponent for counter.cpp:"
read s1 
if [[ $s1 == "quit" ]];then
	exit 0
fi
n=0
Sum_Time=0
#while loop to add all times
while [ $n -lt 5 ]; do
	let n=n+1
	RUNNING_TIME=`./a.out $s1`
	Sum_Time=$((Sum_Time+RUNNING_TIME))
	echo "Running iteration $n..."
	echo  "time taken $RUNNING_TIME ms"
done 
#divisor
Divisor=5
#calculating and printing average
avg=$((Sum_Time/Divisor))
echo "Average time was $avg ms"
exit 0
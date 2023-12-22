#!/bin/bash
#Reading in files
echo "input dictionary"
read dictfile
echo "input gridfile"
read gridfile
#getting the 5 running times
RUNNING_TIME1=`./a.out $dictfile $gridfile| tail -1`
RUNNING_TIME2=`./a.out $dictfile $gridfile| tail -1`
RUNNING_TIME3=`./a.out $dictfile $gridfile| tail -1`
RUNNING_TIME4=`./a.out $dictfile $gridfile| tail -1`
RUNNING_TIME5=`./a.out $dictfile $gridfile| tail -1`
#adding times
Sum_Time=$((RUNNING_TIME1+RUNNING_TIME2+RUNNING_TIME3+RUNNING_TIME4+RUNNING_TIME5))
Divisor=5
#calculating and printing average
avg=$((Sum_Time/Divisor))
echo $avg
exit 0
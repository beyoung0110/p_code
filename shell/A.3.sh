#!/bin/bash
# simpler-mined version of rename filenames

ONE=1
number=0
FOUND=0

for filename in *
do
    echo "$filename" | grep -q " "
    if [ $? -eq $FOUND ]
    then
        fname=$filename
        n=`echo $fname | sed -e "s/ /_/g"`
        mv "$fname" "$n"
        let "number += 1"
    fi
done

if [ "$number" -eq "$ONE" ]
then
    echo "$number file renamed."
else 
    echo "$number files renamed."
fi 

exit 0

#!/bin/bash

#  The notorious "hailstone" or Collatz series.
#  -------------------------------------------
#  1) Get the integer "seed" from the command line.
#  2) NUMBER <--- seed
#  3) Print NUMBER.
#  4)  If NUMBER is even, divide by 2, or
#  5)+ if odd, multiply by 3 and add 1.
#  6) NUMBER <--- result 
#  7) Loop back to step 3 (for specified number of iterations).
#
#  The theory is that every sequence,
#+ no matter how large the initial value,
#+ eventually settles down to repeating "4,2,1..." cycles,
#+ even after fluctuating through a wide range of values.
#
#  This is an instance of an "iterate",
#+ an operation that feeds its output back into the input.
#  Sometimes the result is a "chaotic" series.

MAX_ITERATION=200

h=${1:-$$}

echo
echo "C($h) --- $MAX_ITERATION Iterations"
echo

for ((i=1; i<=MAX_ITERATION; i++))
do
    echo -n "$h         "
    let "remainder = h % 2"
    if [ "$remainder" -eq 0 ]
    then
        let "h /= 2"
    else
        let "h = h*3 + 1"
    fi

    COLUMNS=10
    let "line_break = i % $COLUMNS"
    if [ "$line_break" -eq 0 ]
    then
        echo
    fi
done

echo 

exit 0

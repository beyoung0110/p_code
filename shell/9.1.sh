#!/bin/bash

output_args_one_per_line() {
    for arg
        do echo "[$arg]"
    done
}

echo; echo "IFS=\" \""
echo "----------"

#IFS=" " #default value
var="a    b c     "
output_args_one_per_line $var

echo; echo "IFS=:"
echo "----------"

IFS=:
var=":a::::b:c:::"
output_args_one_per_line $var

echo

exit 0

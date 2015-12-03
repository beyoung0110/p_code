#!/bin/bash

echo; echo

echo "\v\v\v\v"
echo "============="
echo "VERTICAL TABS"
echo -e "\v\v\v\v"
echo "============="

echo "QUOTATION MARK"
echo -e "\042"
echo "============="

echo;
echo "NEWLINE AND BEEP"
echo '\n'
echo $'\n'
echo $'\a'
echo "============="

echo "QUATATION MARKS"
echo $'\t \042 \t'
echo $'\t \x22 \t'
echo "============="

quote=$'\042'
echo "$quote This is a quoted string, $quote and this lies outside the quotes."

echo

triple_underline=$'\137\137\137\137'
echo "$triple_underline UNDERLINE $triple_underline"

echo

ABC=$'\101\102\103\010'
echo $ABC

echo;echo

escape=$'\033'
echo "\"escape\" echoes as $escape"

exit 0

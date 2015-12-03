#!/bin/bash
#Game of Life

GENERATION=()
NEXT_GENERATION=()

#printGeneration() {
#print GENERATION
#}

initGeneration() {
#get line
row=$#
echo "row : $row"
#GENERATION[1]=()
for ((i=1; i<=row; i++))
do
    len = ${#$i[@]}
    GENERATION[i+1][1]="_"
    for ((j=1; j<=len; j++))
    do
    GENERATION[i+1][j+1]=$i[j]
    done
    GENERATION[i+1][len+1]="-"
done
#GENERATION[line+1]=()
#GENERATION
}

#nextGeneration() {

#}

#coutAliveNum() {

#}

#main() {
#    initGeneration
#    printGeneration
#    nextGeneration
#    printGeneration
#}

initGeneration
echo $GENERATION

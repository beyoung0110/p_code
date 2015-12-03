#!/bin/bash
#This script processes text files to produce a sorted list of words found in the files.

E_BADARGS=65

if [ ! -r "$1" ]
then
    echo "Usage: $0 files-to-process"
    exit $E_BADARGS
fi

cat $* |
       tr A-Z a-z |
       tr ' ' '\012' |
       tr -c '\012a-z' '\012' |
       sort |
       uniq |
       grep -v '^#' |
       grep -v '^$'

exit 0

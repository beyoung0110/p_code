#!/bin/bash
#formatting an e-mail message

# standard check for script arguments
ARGS=1
E_BADARGS=65
E_NOFILE=66

if [ $# -ne $ARGS ]
then
    echo "Usage: `basename $0` filename"
    exit $E_BADARGS
fi

if [ -f "$1" ]
then
    file_name=$1
else
    echo "FILE \"$1\" dose not exists."
    exit $E_NOFILE
fi

#=========================================

MAXWIDTH=70
sedscript='s/^>//
s/^  *>//
s/^  *//
s/             *//'

sed "$sedscript" $1 | fold -s --width=$MAXWIDTH

exit 0

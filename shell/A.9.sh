#!/bin/bash

ARGCOUNT=1
E_WRONGARGS=70

if [ $# -ne "$ARGCOUNT" ]
then
    echo "Usage:`basename $0` name"
    exit $E_WRONGARGS
fi

assign_value() {
val1=bfpv
val2=cgjkqsxz
val3=dt
val4=l
val5=mn
val6=r

value=$( echo "$1" \
    | tr -d wd \
    | tr $val1 1 | tr $val2 2 | tr $val3 3 \
    | tr $val4 4 | tr $val5 5 | tr $val6 6 \
    | tr -s 123456 \
    | tr -d aeiouy )
}

input_name="$1"
echo
echo "Name = $input_name"

name=$( echo $input_name | tr A-Z a-z)

char_pos=0
perfix0=${name:$char_pos:1}
perfix=`echo $perfix0 | tr a-z A-Z`

let "char_pos += 1"
name1=${name:$char_pos}

char1=`echo $perfix | tr A-Z a-z`

assign_value $name
s1=$value
assign_value $name1
s2=$value
assign_value $char1
s3=$value
s3=9$s3

if [[ "$s1" -ne "$s2" || "$s3" -eq 9 ]]
then
    suffix=$s2
else
    suffix=${s2:$char_pos}
fi

padding=000

soun=$perfix$suffix$padding

MAXLEN=4
soundex=${soun:0:$MAXLEN}

echo "soundex = $soundex"

echo

exit 0

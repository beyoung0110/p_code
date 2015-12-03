#!/bin/bash

let "dec = 32"
echo "decimal number = $dec"  #32

let "oct = 032"
echo "octal number = $oct"  #26

let "hex = 0x32"
echo "hexadecimal number = $hex"  #50

let "bin = 2#111100111001101"
echo "binary number = $bin"  #31181

let "b32 = 32#77"
echo "base-32 number = $b32"  #231

let "b64 = 64#@_"
echo "base-64 number = $b64" #4031

echo

echo $((36#zz)) $((2#10101010)) $((16#AF16)) $((53#1aA))

exit 0

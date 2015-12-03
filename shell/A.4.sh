#!/bin/bash
# uploading to an ftp site, using a locally encrypted password

E_BADARGS=65

if [ -z "$1" ]
then
    echo "Usage: `basename $0` filename"
    exit $E_BADARGS
fi

Username=haoqing
pword=/home/haoqing/secret/password_encrypted.file

Filename=`basename $1`

Server="XXX"
Directory="YYY"

Password=`cruft <$pword`

ftp -n $server <<End-Of-Session
user $Username $Password
binary
bell
cd $Directory
put $Filename
bye
End-Of-Session

exit 0

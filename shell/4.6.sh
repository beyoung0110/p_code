#!/bin/bash
E_NOZRGS=65

if [ -z "$1" ]
then
    echo "Ussage: `basename $0` [domain-name]"
    exit $E_NOARGS
fi

case `basename $0` in
    "wh" ) whois $1@whois.ripe.net;;
    "wh-ripe" ) whois $1@whois.ripe.net;;
    "wh-radb" ) whois $1@whois.radb.net;;
    "wh-cw" ) whois $1@whois.cw.net;;
    * ) echo "Usage: `basename $0` [domain-name]";;
esac

exit $?

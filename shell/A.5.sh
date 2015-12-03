#!/bin/bash
# copy a data CD

CDROM=/dev/cdrom
OF=

BLOCKSIZE=2048
SPEED=2
DEVICE=cdrom

echo; echo "Insert source CD, but do *not* mount it."
echo "Press ENTER when ready."
read ready

echo; echo "Copying the source CD to $OF."
echo "This may take a while. Please be patient."

dd if=$CDROM of=$OF bs=$BLOCKSIZE

echo; echo "Remove data CD."
echo "Insert blank CDR."
echo "Press ENTER when ready."
ready ready

echo "Copying $OF to CDR"

cdrecord -v -isosize speed=$SPEED dev=$DEVICE $OF

echo; echo "Done copying $OF to CDR on device $CDROM."

echo "Do you want to erase the image file (y/n)?"
read answer

case "$answer" in
    [yY]) rm -f $OF
        echo "$OF erased."
        ;;
    *)  echo "$OF not erased.";;
esac

echo

exit 0

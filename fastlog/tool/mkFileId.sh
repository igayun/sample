#!/bin/sh

if [ $# != 1 ];then
    echo "Usage : $0 <srcPath>"
    exit 1
fi

if [ ! -d $1 ];then
    echo "$1 is not exist or not directory"
    exit 1
fi

printf "#ifndef __FILEID__\n"
printf "#define __FILEID__\n\n"

printf "typedef enum {\n"
find $1 -name "*.c" | \
while read line
do
    printf "    FILEID_%s,\n" `echo $line | sed -e 's%.*/%%' | tr -t '<a-z>' '<A-Z' | sed -e 's/\./_/'`
done
printf "}fileId_t;\n\n"

printf "#endif /*__FILEID__ */\n"


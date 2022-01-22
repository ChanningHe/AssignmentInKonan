#!/usr/bin/env sh

if [ ! -f a.out ]; then
    echo "Can't find a.out here. Check it again."
    exit
fi

# test #1
input="CGTTTGAAAA"
res=`echo "$input" | ./a.out`

if [ "$res" = "CGT3GA4" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"

# test #2
input="ATGC"
res=`echo "$input" | ./a.out`

if [ "$res" = "ATGC" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"

# test #3
input="CCCCCCCCC"
res=`echo "$input" | ./a.out`

if [ "$res" = "C9" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"


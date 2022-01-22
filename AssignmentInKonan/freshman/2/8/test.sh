#!/usr/bin/env sh

if [ ! -f a.out ]; then
    echo "Can't find a.out here. Check it again."
    exit
fi

# test #1
input="KonanU
KoNan"
res=`echo "$input" | ./a.out`

if [ "$res" = "5" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"

# test #2
input="KONAN
nanbo"
res=`echo "$input" | ./a.out`

if [ "$res" = "3" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"

# test #3
input="Konan
KOBAN"
res=`echo "$input" | ./a.out`

if [ "$res" = "2" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"

# test #4
input="Konan
Okamoto"
res=`echo "$input" | ./a.out`

if [ "$res" = "1" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"

# test #5
input="Kobe
Itami"
res=`echo "$input" | ./a.out`

if [ "$res" = "0" ]; then
    echo 'correct \c'
else
    echo 'wrong \c'
fi
echo for \"$input\"

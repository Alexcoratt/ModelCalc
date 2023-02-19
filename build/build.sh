#Build script file for ModelCalc
#Author Alexander Smirnov

HOME=/run/media/alexsm/LinuxFiles/Workshop/Projects/ModelCalc
HEADS=$HOME/src/Linear/Headers
SRCS=$HOME/src/Linear/Sources
MAIN=$HOME/src/ModelCalc.cpp
TESTS=$HOME/tests
OUT=$HOME/out
RES=ModelCalc

rm -rf $OUT
mkdir $OUT

cp -al $HEADS/. $OUT/
cp -al $SRCS/. $OUT/
cp -l $MAIN $OUT/

g++ $OUT/* -o $OUT/$RES

rm $OUT/*.?pp

cp -al $TESTS/. $OUT/

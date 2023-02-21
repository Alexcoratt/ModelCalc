#Build script file for ModelCalc
#Author Alexander Smirnov

HOME=/run/media/alexsm/LinuxFiles/Workshop/Projects/ModelCalc
SRC=$HOME/src
HEADS=$SRC/Linear/Headers
SRCS=$SRC/Linear/Sources
MAIN=MxAnalyse.cpp
TESTS=$HOME/tests
OUT=$HOME/outMxAn
RES_NAME=ModelCalcMxAn

rm -rf $OUT
mkdir $OUT

cp -al $SRCS/. $OUT/
cp -l $SRC/$MAIN $OUT/
clang++ --std=c++11 $OUT/* -I $HEADS

#cp -al $TESTS/. $OUT/

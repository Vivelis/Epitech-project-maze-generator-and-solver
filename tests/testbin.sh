EXPECT=0
RES=0
OPT1=$1
OPT2=$2
OPT3=$3
GENRES=res_generator.txt
SOLVRES=res_solver.txt

rm -f $GENRES
rm -f $SOLVRES
START=$(date +%s)
./generator/generator $OPT1 $OPT2 $OPT3 > $GENRES
END=$(date +%s)
DURATION=$((END - START))
RES=$?
echo "\e[01;2m\n----------------------------------------------\n\e[00m"
echo "options: \e[00;33m$OPT1, $OPT2, $OPT3\e[00m"
if [ $RES != $EXPECT ]
then
    echo "\e[01;31m[error: generator have return ($RES)]\e[00m"
else
    echo "\e[01;32m[generator have successed]\e[00m"
    minutes=$((DURATION/60))
    seconds=$((DURATION%60))
    echo "Completed in \e[00;33m$minutes\e[00m minute(s) and \e[00;33m$seconds\e[00m second(s)"
    echo "-------------"
fi
START=$(date +%s)
./solver/solver $GENRES > $SOLVRES
END=$(date +%s)
DURATION=$((END - START))
RES=$?
if [ $RES != $EXPECT ]
then
    echo "\e[01;31m[error: solver have return ($RES)]\e[00m\n"
    echo "\e[01;2m\n----------------------------------------------\n\e[00m"
    return 84
else
    echo "\e[01;32m[solver have successed]\e[00m"
    minutes=$((DURATION/60))
    seconds=$((DURATION%60))
    echo "Completed in \e[00;33m$minutes\e[00m minute(s) and \e[00;33m$seconds\e[00m second(s)"
    echo "\e[01;2m\n----------------------------------------------\n\e[00m"
    return 0
fi

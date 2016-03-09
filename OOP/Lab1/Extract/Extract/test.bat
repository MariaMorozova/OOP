rem @echo off
SET program="%1"
if %program% == "" goto err

mkdir outputs
echo "1"
%program% "tests\input.txt" "outputs\output1.txt" "0" "25"
if ERRORLEVEL 1 goto testFailed

echo "1"
%program% "tests\input.txt" "outputs\output2.txt" "50" "107"
if ERRORLEVEL 1 goto testFailed

echo "1"
%program% "tests\input.txt" "outputs\output2.txt" "-10" "107"
if ERRORLEVEL 1 goto testFailed

echo "1"
%program% "tests\empty.txt" "outputs\output2.txt" "50" "107"
if ERRORLEVEL 1 goto testFailed

echo OK
exit /B

:testFailed
echo Testing failed
exit /B

:err
echo Usage: test.bat <Path to program>
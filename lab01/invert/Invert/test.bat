set PROGRAM="Debug/invert.exe"

%PROGRAM% file1.txt >> out1.txt
fc out1.txt needed_out1.txt
if ERRORLEVEL 1 goto err

%PROGRAM% file2.txt >> out2.txt
fc out2.txt needed_out2.txt
if ERRORLEVEL 1 goto err

%PROGRAM% file3.txt >> out3.txt
fc out3.txt needed_out3.txt
if ERRORLEVEL 1 goto err

%PROGRAM% non-existing-file
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
set PROGRAM="Debug/multimatrix.exe"

%PROGRAM% "file1.txt" "file2.txt" >> out.txt
fc "out.txt" "neededout.txt"
if ERRORLEVEL 1 goto err

%PROGRAM% "file1.txt"
if NOT ERRORLEVEL 1 goto err

%PROGRAM% non-existing-file-name.txt Да
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
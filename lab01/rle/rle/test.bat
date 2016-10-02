set PROGRAM="../Debug/rle.exe"

%PROGRAM% "unpack" "inp.txt" "out.txt"
if ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
set PROGRAM="../Debug/rle.exe"

%PROGRAM% "AAAAABBCCDDEEEEEF" "pack"
if ERRORLEVEL 1 goto err

%PROGRAM% "5,'A',9,'B',1,'C',12,'D'" "unpack"
if ERRORLEVEL 1 goto err

%PROGRAM% "A"
if NOT ERRORLEVEL 1 goto err

%PROGRAM% "AAAAABBCCDDEEEEEF" "unpack"
if NOT ERRORLEVEL 1 goto err

%PROGRAM% "5,'A',9,'B',1,'C',12,'D'" "unpack"
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
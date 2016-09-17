set PROGRAM="../Debug/flipbyte.exe"

%PROGRAM% "5"
if ERRORLEVEL 1 goto err

%PROGRAM% "15"
if ERRORLEVEL 1 goto err

%PROGRAM% "555"
if NOT ERRORLEVEL 1 goto err

%PROGRAM% "-100"
if NOT ERRORLEVEL 1 goto err

%PROGRAM% "Да"
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
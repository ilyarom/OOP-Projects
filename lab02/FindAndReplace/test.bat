set PROGRAM="Debug/FindAndReplace.exe"

%PROGRAM% "Hello World" "Hello" "Good bye"
if ERRORLEVEL 1 goto err

%PROGRAM% "HelloHelloHello" "Hello" "HelloHello"
if ERRORLEVEL 1 goto err

%PROGRAM% "HelloHelloHello" "HelloHello" "Hello"
if ERRORLEVEL 1 goto err

%PROGRAM% "Hello"
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
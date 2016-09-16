set PROGRAM="../Debug/FindText.exe"

%PROGRAM% emptytest.txt "findme"
if ERRORLEVEL 1 goto err

%PROGRAM% englishtest.txt yellow 
if ERRORLEVEL 1 goto err

%PROGRAM% russiantest.txt Синий 
if ERRORLEVEL 1 goto err

%PROGRAM% non-existing-file-name.txt Да
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
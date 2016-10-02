set PROGRAM="../Debug/replace.exe"

%PROGRAM% "emptytest.txt" "emptytestout.txt" "findme" "replaceme"
if ERRORLEVEL 1 goto err

%PROGRAM% "englishtest.txt" "englishtestout.txt" "yellow" "indigo"
if ERRORLEVEL 1 goto err

%PROGRAM% "russiantest.txt" "russiantestout.txt" "�����" "����" 
if ERRORLEVEL 1 goto err

%PROGRAM% non-existing-file-name.txt ��
if NOT ERRORLEVEL 1 goto err

echo Program testing succeeded
pause
exit 0

:err
echo Program testing failed
pause
exit 1
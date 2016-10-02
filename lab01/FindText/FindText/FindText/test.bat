set PROGRAM="../Debug/FindText.exe"

%PROGRAM% "emptytest.txt" "findme" 
if ERRORLEVEL 1 goto err

%PROGRAM% "englishtest.txt" "yellow" >> english_out.txt 
fc english_out.txt english_needed_out.txt
if ERRORLEVEL 1 goto err

%PROGRAM% "russiantest.txt" "Синий" >> russian_out.txt
fc russian_out.txt russian_needed_out.txt
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
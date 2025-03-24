all:
	gcc -shared -fPIC -o libpeteste.so peteste.c

clean:	
	del /Q libpeteste.so

install:
	@if not exist "%USERPROFILE%\lib" mkdir "%USERPROFILE%\lib" 
	@copy /Y libpeteste.so "%USERPROFILE%\lib" 

uninstall:
	@if exist "%USERPROFILE%\lib" del /F /Q "%USERPROFILE%\lib\libpeteste.so"
	@if exist "%USERPROFILE%\lib" rd "%USERPROFILE%\lib" 2>nul	
	 

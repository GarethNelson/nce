;Change this file to customize zip2exe generated installers with a modern interface

SilentInstall silent
Section
  SetOutPath $INSTDIR
SectionEnd

Function .onInstSuccess
  Exec '"$INSTDIR\build\win32\main.exe"'
FunctionEnd 

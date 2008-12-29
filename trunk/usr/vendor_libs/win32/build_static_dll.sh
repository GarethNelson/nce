#!/bin/sh
# tries to build a static lib from a DLL
echo EXPORTS > $1.def
i386-mingw32-nm $1.dll | grep ' T _' | sed 's/.* T _//' >> $1.def
i386-mingw32-dlltool --def $1.def --dllname $1.dll --output-lib $1.a



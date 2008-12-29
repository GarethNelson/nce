#!/bin/sh

echo $@
./scons.py win32=1 $@ 2>&1 | tee build-win32.log
./scons.py linux=1 $@ 2>&1 | tee build-linux.log

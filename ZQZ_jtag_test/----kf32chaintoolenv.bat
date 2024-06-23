@echo off
rem This file is the script to set path for tool chain.




set TL_PATH=%~dp0
set PATH=%TL_PATH%;%PATH%

rem  gdb -q --args    kf32-gdb.exe   _13KDebug_ROM.elf

kf32-gdb.exe   _13KDebug_ROM.elf

cmd /K cd %CD% 


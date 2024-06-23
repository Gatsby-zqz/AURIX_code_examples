@echo off
rem This file is the script to set path for tool chain.




set TL_PATH=%~dp0
set PATH=%TL_PATH%;%PATH%

SendSignal.exe 16208


cmd /K cd %CD% 


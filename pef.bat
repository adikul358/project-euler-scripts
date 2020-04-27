@echo off
set /p id="Problem name: "
set /p txt="Text File (y/n): "

xcopy C:\Users\adity\Dev\project-euler-scripts\template.cpp C:\Users\adity\Dev\project-euler-scripts\%id%.cpp*

if "%txt%" == "y"
echo "Hello" > C:\Users\adity\Dev\project-euler-scripts\%id%.txt
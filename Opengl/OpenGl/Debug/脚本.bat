@echo off

REM 设置保存图片的路径为桌面上的一个文件夹
set save_path=D:\vs_test\output.png

REM 在指定的路径下创建图片文件
echo Creating output.png at the specified location...
echo This is a sample image file. > "%save_path%"

REM 运行 your_program.exe 并传递保存图片的路径作为参数
echo Running your_program.exe with %save_path%...
OpenGl.exe "%save_path%"

echo Process completed.
pause
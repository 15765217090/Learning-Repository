@echo off
chcp 65001 >nul
echo 正在清空 bin 目录下的所有内容（保留目录）...

if exist bin (
    cd bin
    del /f /s /q *.* 2>nul
    for /d %%d in (*) do rmdir /s /q "%%d"
    cd ..
) else (
    mkdir bin
)

echo 进入 bin 目录进行构建...
cd bin

echo 运行 CMake (MinGW Makefiles)...
cmake -G "MinGW Makefiles" ..

echo 编译项目...
make

echo 完成。可执行文件应位于 bin 目录中。
cd ..
pause
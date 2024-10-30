**CMake基本构建方法**

- CMakeLists.txt 文件创建，其中基本内容为

```
cmake_minimum_required(VERSION 3.0)//代表最低版本
project(CALC)//表示文件名字
add_executable(app add.cpp div.cpp main.cpp mult.cpp sub.cpp)//执行什么程序
```

- build文件夹创建（用来放一些乱七八糟的编译程序）

```
$mkdir build //创建名字为build的vip文件夹
$cd build
$cmake .. //..表示在上一级目录，.代表在当前目录
$make //开始利用makefile编译
出现CMakeCache.txt  CMakeFiles  Makefile  app  cmake_install.cmake
$./app //执行可执行程序app
```


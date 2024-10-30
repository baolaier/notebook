**`CMake` set用法**

- 包括一些文件简化程序

```
set(SRC add.cpp div.cpp main.cpp mult.cpp sub.cpp)
add_executable(app ${SRC})
```

- 设置最后输出路径

```
set(EXECUTABLE_OUTPUT_PATH /root/hello_world/test/res)
```

- 设置C++版本

```
set(CMAKE_CXX_STANDARD 11)
```


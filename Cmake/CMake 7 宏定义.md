**`CMake` 宏定义**

在main.cpp文件中

```cpp
#ifdef DEBUG
    printf("我是一个程序猿, 我不会爬树...\n");
#endif
```

在`CMakeList.txt`文件中

```cmake
cmake_minimum_required(VERSION 3.0)
project(CALC)
add_definitions(-DDEBUG)#关键
add_executable(app ./main.cpp)
```

如果在关键处定义了`-DDEBUG`这个宏，那么最后会输出

反之就不会输出，利用这个特性可以写一些调试语句，在最后发行的时候就可以通过这个开关关闭调试语句的输出
**`CMake` 嵌套**

首先建立这样的目录

![image-20241101202052543](C:\Users\鲍钱莱尔\AppData\Roaming\Typora\typora-user-images\image-20241101202052543.png)

- 最外面的CMakeLists.txt表示为

```cmake
cmake_minimum_required(VERSION 3.0)
project(test)

#设置静态库生成路径
set(LIB_PATH ${CMAKE_CURRENT_SOURCE_DIR}/lib)
#设置头文件路径
set(HEAD_PATH ${CMAKE_CURRENT_SOURCE_DIR}/include)
#设置测试程序生成路径
set(EXE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/res)

#设置库名字
set(CALCLIB calc)
#设置生成程序名字
set(APPNAME test1)

#添加子目录
add_subdirectory(calc)
add_subdirectory(test1)
```

- `calc`作用是生成头文件的库文件，表示为

```cmake
cmake_minimum_required(VERSION 3.0)
project(calc)
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
include_directories(${HEAD_PATH})
set(LIBRARY_OUTPUT_PATH ${LIB_PATH})
add_library(${CALCLIB} STATIC ${SRC})
```

- `test1`作用是导入库文件，运行其中main.cpp文件，表示为

- ```cmake
  cmake_minimum_required(VERSION 3.0)
  project(test1)
  
  file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
  include_directories(${HEAD_PATH})
  link_directories(${LIB_PATH})
  set(EXECUTABLE_OUTPUT_PATH ${EXE_PATH})
  add_executable(${APPNAME} ${SRC})
  target_link_libraries(${APPNAME} ${CALCLIB})
  ```


更多

[CMake 保姆级教程（下） | 爱编程的大丙](https://subingwen.cn/cmake/CMake-advanced/)
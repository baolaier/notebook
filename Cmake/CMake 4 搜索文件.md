**CMake搜索文件**

- aux_source_directory搜索方式，可以找到目录下所有文件

```
aux_source_directory(${PROJECT_SOURCE_DIR} SRC)
add_executable(app ${SRC})
```

其中${PROJECT_SOURCE_DIR}代表当前CMakeLists.txt的路径

- file搜索方式，可以找到目录下所有特征后缀的文件

```
file(GLOB SRC ${CMAKE_CURRENT_SOURCE_DIR}/*.cpp)
add_executable(app ${SRC})
```

其中第一个参数有GLOB（将指定目录下搜索到的满足条件的所有文件名生成一个列表，并将其存储到变量中。）和GLOB_RECURSE（递归搜索指定目录，将搜索到的满足条件的文件名生成一个列表，并将其存储到变量中。）两种方式，第二个{CMAKE_CURRENT_SOURCE_DIR}表示CMakeLists.txt的路径，最后/*.后为筛选的文件类型尾缀。



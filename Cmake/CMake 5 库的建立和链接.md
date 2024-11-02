**`CMake` 库的建立和链接**

- 创建静态库和动态库

```cmake
set(LIBRARY_OUTPUT_PATH /root/hello_world/test1/res)#更改输出库文件路径
add_library(calc SHARED ${SRC})#建立动态库
add_library(calc STATIC ${SRC})#建立动态库
```

建立后，.a文件表示静态库，.so文件表示动态库

- 使用动态和静态库

```cmake
link_directories(${PROJECT_SOURCE_DIR}/lib1)#链接库所在目标路径
link_libraries(app calc)
target_link_libraries(app calc)
```

其中`link_libraries(app calc)`为全局链接，也就是说所有被找到的文件都会链接`calc`的库

`target_link_libraries(app calc)`为目标链接，写在`add_executable(app ${SRC})`的后面，需要注意的是在运行程序的过程中这种链接方式的库是不会预先加载的
**`CMake` 字符串操作**

- 常量字符串和变量字符串

```cmake
abc=123
message(${abc})#取到的是123
message(abc)#取到的是abc
```

- 字符串的拼接

```cmake
set(A "hello")
set(B "world")
set(C ${A} ${B})#将A B中的值相加存放到C中
list(APPEND C ${A} ${B})#和set操作是一样的
message("${C}")
```

最后会输出带有分号分隔的字符串类型

```
hello;world
```

- 字符串的移除

```cmake
set(A "hello")
set(B "world")
list(APPEND C ${A} ${B})
list(REMOVE_ITEM C ${A})
```

其实就是把list的APPEND关键字改成REMOVE_ITEM关键字

- list的其他用法

```cmake
获取 list 的长度。

CMAKE
1
list(LENGTH <list> <output variable>)
LENGTH：子命令LENGTH用于读取列表长度
<list>：当前操作的列表
<output variable>：新创建的变量，用于存储列表的长度。
读取列表中指定索引的的元素，可以指定多个索引

CMAKE
1
list(GET <list> <element index> [<element index> ...] <output variable>)
<list>：当前操作的列表
<element index>：列表元素的索引
从0开始编号，索引0的元素为列表中的第一个元素；
索引也可以是负数，-1表示列表的最后一个元素，-2表示列表倒数第二个元素，以此类推
当索引（不管是正还是负）超过列表的长度，运行会报错
<output variable>：新创建的变量，存储指定索引元素的返回结果，也是一个列表。
将列表中的元素用连接符（字符串）连接起来组成一个字符串

CMAKE
1
list (JOIN <list> <glue> <output variable>)
<list>：当前操作的列表
<glue>：指定的连接符（字符串）
<output variable>：新创建的变量，存储返回的字符串
查找列表是否存在指定的元素，若果未找到，返回-1

CMAKE
1
list(FIND <list> <value> <output variable>)
<list>：当前操作的列表
<value>：需要再列表中搜索的元素
<output variable>：新创建的变量
如果列表<list>中存在<value>，那么返回<value>在列表中的索引
如果未找到则返回-1。
将元素追加到列表中

CMAKE
1
list (APPEND <list> [<element> ...])
在list中指定的位置插入若干元素

CMAKE
1
list(INSERT <list> <element_index> <element> [<element> ...])
将元素插入到列表的0索引位置

CMAKE
1
list (PREPEND <list> [<element> ...])
将列表中最后元素移除

CMAKE
1
list (POP_BACK <list> [<out-var>...])
将列表中第一个元素移除

CMAKE
1
list (POP_FRONT <list> [<out-var>...])
将指定的元素从列表中移除

CMAKE
1
list (REMOVE_ITEM <list> <value> [<value> ...])
将指定索引的元素从列表中移除

CMAKE
1
list (REMOVE_AT <list> <index> [<index> ...])
移除列表中的重复元素

CMAKE
1
list (REMOVE_DUPLICATES <list>)
列表翻转

CMAKE
1
list(REVERSE <list>)
列表排序

CMAKE
1
list (SORT <list> [COMPARE <compare>] [CASE <case>] [ORDER <order>])
COMPARE：指定排序方法。有如下几种值可选：
STRING:按照字母顺序进行排序，为默认的排序方法
FILE_BASENAME：如果是一系列路径名，会使用basename进行排序
NATURAL：使用自然数顺序排序
CASE：指明是否大小写敏感。有如下几种值可选：
SENSITIVE: 按照大小写敏感的方式进行排序，为默认值
INSENSITIVE：按照大小写不敏感方式进行排序
ORDER：指明排序的顺序。有如下几种值可选：
ASCENDING:按照升序排列，为默认值
DESCENDING：按照降序排列
```


**`numpy`创建**

从列表创建

```python
import numpy as np
arr = np.array([1, 2, 3, 4])
```

内置函数

```python
zeros = np.zeros((2, 3))  # 生成 2x3 的零数组
ones = np.ones((2, 3))    # 生成 2x3 的一数组
random_arr = np.random.rand(2, 3)  # 生成 2x3 的随机数组
```

**数组属性**

形状

```python
shape = arr.shape
```

比如如果读的是一个四通道真彩色图像，那么这个`shape`就会是`(width,height,4)`

其他

```python
ndim = arr.ndim    # 数组的维度
size = arr.size    # 数组的元素总数
```

**数组操作**

数组计算

```python
arr_squared = arr ** 2  # 数组元素平方，返回一个numpy.ndarray类型
arr_add = arr + 5  #数组元素都加5
total = np.sum(arr)  # 求和
mean = np.mean(arr)  # 求均值
```

`numpy.ndarray`类似列表的一个东西

连接

```python
arr1 = np.array([1, 2])
arr2 = np.array([3, 4])
concatenated = np.concatenate((arr1, arr2))  # 连接
split_arr = np.split(concatenated, 2)         # 分割，2表示分割的数组数量
```

`split_arr`为元素为`numpy`的列表

布尔索引

```python
filtered = arr[arr > 1]  # 筛选大于 1 的元素，返回numpy类型
```

搜索

```
index = np.where(arr == 2)  # 查找元素 2 的索引
```


**导入库**

```python
import cv2
```

**读图像**

```python
img = cv2.imread("zxp.png",cv2.IMREAD_UNCHANGED)
```

其中`IMREAD_UNCHANGED`表示不改变任何读入方式，`IMREAD_GRAYSCALE`表示将图像以灰度模式读取，`IMREAD_COLOR`表示以彩色模式读取

`img` 是一个`NumPy` 数组

**使用`Pillow`库**

首先需要导入一个`pil`库

```python
from PIL import Image,ImageDraw
```

创建一个空白图像

```python
img = Image.new("RGB", (200, 200), "white")
```

创建一个绘制对象

```python
draw = ImageDraw.Draw(img)
```

然后我们对这个绘制对象才能进行一些操作比如我们要绘制一个红色矩形，这个代码的意思是在`(50,50)`的矩形左上角和`(150,150)`的矩形右下角构建一个矩形，fill的值是填充颜色的意思，也可以用RGB元组表示

```python
draw.rectangle([50, 50, 150, 150], fill="red")
```

如果需要保存图像

```python
img.save("output_png")
```

显示图像

```python
img.show()
```

所以需要注意如果我们是对图像的部分进行处理时我们针对的对象应该是绘制对象draw，而针对整幅图像的处理的针对对象应该是创建图像的img
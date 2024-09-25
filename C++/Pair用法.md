**1，pair的应用**

```cpp
pair<T1, T2> p1;            //创建一个空的pair对象（使用默认构造），它的两个元素分别是T1和T2类型，采用值初始化。
pair<T1, T2> p1(v1, v2);    //创建一个pair对象，它的两个元素分别是T1和T2类型，其中first成员初始化为v1，second成员初始化为v2。
make_pair(v1, v2);          // 以v1和v2的值创建一个新的pair对象，其元素类型分别是v1和v2的类型。
p1 < p2;                    // 两个pair对象间的小于运算，其定义遵循字典次序：如 p1.first < p2.first 或者 !(p2.first < p1.first) && (p1.second < p2.second) 则返回true。
p1 == p2；                  // 如果两个对象的first和second依次相等，则这两个对象相等；该运算使用元素的==操作符。
p1.first;                   // 返回对象p1中名为first的公有数据成员
p1.second;                 // 返回对象p1中名为second的公有数据成员
```

**2.创建和初始化**

```cpp
pair<string, string> author("James","Joy");    // 创建一个author对象，两个元素类型分别为string类型，并默认初始值为James和Joy。
pair<string, int> name_age("Tom", 18);
pair<string, int> name_age2(name_age);    // 拷贝构造初始化
```

**3.first和second操作**

```cpp
pair<int ,double> p1;
 
p1.first = 1;
 
p1.second = 2.5;
 
cout<<p1.first<<' '<<p1.second<<endl;
 
//输出结果：1 2.5
 
 
string firstBook;
if(author.first=="James" && author.second=="Joy")
    firstBook="Stephen Hero";
```

**4.用make_pair生成新对象**

```cpp
 pair<int, double> p1;
 p1 = make_pair(1, 1.2);
```

**5.用tie获取pair的值**

需要include<turple>

```cpp
pair<int, double> p;
p = make_pair(10, 2.5);
int a;
double b;
tie(a, b) = p;
cout << a << "," << b << endl;
```

**注意**

在引用pair当对象时要写全 vector<pair<int,int>>
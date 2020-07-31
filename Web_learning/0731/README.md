### 开始学sql语法

最基础的

`select 列名 from 表名`

注意：sql对大小写并不敏感

我设两个表

表一：List1

| id   | A    | B    | C    |
| ---- | ---- | ---- | ---- |
| 1    | a1   | b1   | c1   |
| 2    | a2   | b2   | c2   |
| 2    | a3   | b3   | c3   |

表二：List2

| id   | D    | E    | F    |
| ---- | ---- | ---- | ---- |
| 1    | d1   | e1   | f1   |
| 2    | d2   | e2   | f2   |
| 3    | d3   | e3   | f3   |

如上，**id,A,B,C**即为列名，这个表比如说List1就叫表名

### 1.

`select A from List1`

即结果为列出List1中的A列

| A    |
| ---- |
| a1   |
| a2   |
| a3   |

### 2.

`select * from List2`

即结果为列出List2所有列，*即选取所有列

| id   | D    | E    | F    |
| ---- | ---- | ---- | ---- |
| 1    | d1   | e1   | f1   |
| 2    | d2   | e2   | f2   |
| 3    | d3   | e3   | f3   |

#### 3.

`select distinct id from List1`

即不重复列出List1中id列

| id   | A    | B    | C    |
| ---- | ---- | ---- | ---- |
| 1    | a1   | b1   | c1   |
| 2    | a2   | b2   | c2   |

id=2有两行，省略了后一行

#### 4.

`select * from List2 where D='d2'`

即列出List2中D列值为d2的行

| 1    | d1   | e1   | f1   |
| ---- | ---- | ---- | ---- |
| 2    | d2   | e2   | f2   |

这里要注意

首先，select后面一般就跟*，因为查询的是行了，如果`select D from List2 where D='d2'`这看起来没什么意义。

其次，关于引号的使用，sql用单引号环绕文本值，有些数据库也支持双引号

即

##### 关于文本值

这是正确的：

`select * from List2 where D='d2'`

这是错误的：

~~`select * from List2 where D=d2`~~



##### 关于数值

这是正确的：

`select * from List2 where id>1`

这是错误的：

~~`select * from List2 where id>'1'`~~


## 我又来划了

回头看了下SQL的知识

一个数据库通常包含多个表

mysql命令的`use`用来选择数据库

`set names utf8`设定字符集

然后用上次的select读取表信息

### 一些重要的SQL命令

·select-从数据库提取数据

·update-更新数据库的数据

·delete-从数据库删除数据

·insert into-向数据库插入新数据

·create database-创建新数据库

·alter database-修改数据库

·create table-创建新表

·alter table-变更数据库表

·drop table-删除表

·create index-创建索引

·drop index-删除索引

## where

补充下

`select * from a where id>1 or id<3`

结果显示为id为2的数据行

也就是说where进行运算也是可以的

#### 逻辑运算

优先级

```
（）   >   not   >   and   >   or
```

#### 特殊条件

##### 空值判断：is null

`select * from a where id is null`

##### 之间判断：between and

`select * from a where id between 1 and 3`

##### In

`select * from a where id in (1,2,3)`

查询a表id列等于1,2,3的值

##### Like

`select * from a where id like M%`

模糊查询，查询a表id列中有M的值，M为查询内容的模糊信息

- **%** 表示多个字值，**_** 下划线表示一个字符；
-  **M%** : 为能配符，正则表达式，表示的意思为模糊查询信息为 M 开头的。
-  **%M%** : 表示查询包含M的所有内容。
-  **%M_** : 表示查询以M在倒数第二位的所有内容。

#####  WHERE 子句并不一定带比较运算符 

例如where 0，where 1，会自动转换为false和true，也就是结果为空集，和全部值


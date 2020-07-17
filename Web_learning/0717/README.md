# Lamp环境的搭建

#####  `LAMP`是`Linux Apache MySQL PHP`的简写，即把Apache、MySQL以及PHP安装在Linux系统上，组成一个环境来运行PHP的脚本语言，通常是网站。------某百科

## 1.安装Linux

此处省略一万字

## 2.安装MySQL

 MySQL官网：https://www.mysql.com/ 

#### 下载软件包

·首先查看Linux是多少位的:

```
$ uname -i
```

·然后利用指令下载

```
$ wget (下载链接)
```

#### 初始化

·解压包

```
$ tar -zxvf (包名称)
```

tar解压指令

z代表gzip的压缩包；

x代表解压；

v代表显示过程信息；

f代表后面接的是文件 

       z：通过gzip支持压缩或解压缩。还有其他的压缩或解压缩方式，比如j表示bzip2的方式。
     
       x：解压缩。c：是压缩。 
     
       v：在压缩或解压缩过程中显示正在处理的文件名
     
       f：f后面必须跟上要处理的文件名。也就是说你不能写成这样 tar -zxfv abc.tar.gz 
    
       tar -xzvf 压缩包名.tar.gz    解压文件，解压完成后得到的是文件夹
    
       tar -czvf 压缩包名.tar.gz 文件名    压缩文件
·更改文件夹名称或位置，移动到那个目录下(cd )

·建立MySQL用户，启动mysql需要该用户：
```
$ useradd -s /sbin/nologin mysql
```

·创建datadir，数据库文件会放到这里：

```
$ mkdir -p data/mysql
```

·更改权限，否则后面会报错：

```
$ chown -R mysql:mysql data/mysql
```

·进行初始化，指定用户为mysql，指定数据存放路径：

```
./scripts/mysql_install_db --user=mysql --datadir=(绝对路径)
```

如果提示没有`libaio.so.1`就安装：

```
$ yum install -y libaio*
```

·测试

```
$ echo $?
```

输出为0即为指令执行，安装完成。

## 3.配置MySQL

初始化完成之后，接下来就是配置。

·首先复制配置文件：
```
$ cp support-files/my-default.cnf /etc/my.cnf
cp：是否覆盖"/etc/my.cnf"？ y
```

·打开配置文件，做以下修改：

```
[mysqld]

# Remove leading # and set to the amount of RAM for the most important data
# cache in MySQL. Start at 70% of total RAM for dedicated server, else 10%.
 innodb_buffer_pool_size = 128M

# Remove leading # to turn on a very important data integrity option: logging
# changes to the binary log between backups.
# log_bin = 

# These are commonly set, remove the # and set as required.
 basedir = /usr/local/mysql
 datadir = /usr/local/mysql/data/mysql
 port = 3306
# server_id = .....
# socket = .....

# Remove leading # to set options mainly useful for reporting servers.
```

其中，basedir是MySQL包所在的路径，datadir是定义的存放数据的地方，port定义MySQL服务监听的端口，如果不定义默认就是3306，server_id定义该MySQL服务的ID号，用于做主从配置。

·然后复制启动脚本文件并修改其属性：
```
$ cp support-files/mysql.server /etc/init.d/mysqld

$ chmod 755 /etc/init.d/mysqld
```


然后修改启动脚本：

```
$ vim /etc/init.d/mysqld

basedir=/usr/local/mysql  
datadir=/usr/local/mysql/data/mysql 
```


·接下来将启动脚本加入系统服务项并设置开机启动：

```
$ chkconfig --add mysqld

$ chkconfig mysqld on
```

·最后启动服务：
```
$ service mysqld start

Starting MySQL.Logging to '/usr/local/mysql/data/mysql/localhost.localdomain.err'.
. SUCCESS!
```


上面已经启动成功，如果没有成功启动，我们也可以到./data/mysql目录下查看错误日志。

检查MySQL是否启动的命令为：
```
$ ps aux |grep mysqld				#结果应该大于2行
```

```
$ netstat -lntp |grep 3306				#查看是否在监听3306端口
```

如果是上面这样的情况，说明MySQL启动成功。

另外，停止MySQL服务：

```
service mysqld stop
```


还可以以命令行的方式启动脚本，--defaults-file指定配置文件，指定用户，指定目录，最后加上&符号，放到后台执行。

```
$ /usr/local/mysql/bin/mysqld_safe --defaults-file=/etc/my.cnf --user=mysql --datadir=/data/mysql &
```

以命令行的方式启动的mysql脚本不能直接stop，可以使用killall停止服务。

使用killall会停止当前的写读操作，再将没有写入到磁盘中的数据写到磁盘里面去，写完之后再将进程杀死。

如果遇到mysql的进程杀不死，可能说明数据量比较大，在慢慢写入磁盘，这时候不要使用kill -9强制杀死进程，可能会损坏数据。

最后，MariaDB的安装方法与MySQL大致相同，不做更多赘述。

## 4.安装Apache

 Apache官网：[https://www.apache.org](https://www.apache.org/) 

 编译安装`apache`之前先安装`apr`以及`apr-util`，`apr`和`apr-util`是一个通用的函数库，主要为上层应用提供支持，它让httpd可以不关心底层的操作系统平台，可以很方便地移植（从linux移植到windows）。 

·下载httpd，apr，apr-util同上

·解压压缩包同上

·进入各自目录

安装apr（进入apr目录）：
```
$ cd apr-1.6.3

$ ./configure --prefix=/usr/local/apr

$ make && make install
```

安装apr-util（进入apr-util目录）：
```
$ cd /usr/local/src/apr-util-1.6.1

$ ./configure --prefix=/usr/local/apr-util --with-apr=/usr/local/apr

$ make && make install
```


如果上面在安装时出现错误，可以试着去安装expat-devel，因为apr-util需要expat-devel依赖。

继续安装httpd（进入httpd目录）：
```
$ cd /usr/local/src/httpd-2.4.33

$ ./configure \
> --prefix=/usr/local/apache2.4 \
> --with-apr=/usr/local/apr \
> --with-apr-util=/usr/local/apr-util \
> --enable-so \
> --enable-mods-shared=most
```

上面，

```
\		表示转义字符，加上它可以将一行命令写成多行，更加直观

--prefix		指定安装目录

--enable-so		表示启用DSO，表示支持扩展模块，动态扩展模块，apache和php都支持以一个模块的形式存在

--enable-mods-shared=most		表示指定需要哪些动态扩展的模块，需要加载哪些呢？most就是绝大多数 
```


为了避免在make的时候出错，我们可以提前安装pcre和pcre-devel：

```
$ yum install -y pcre pcre-devel
```

·最后编译和安装：
```
$ make

$ make install
```

上面两个步骤都可以通过echo $?来判断上一条命令是否正确执行。

·启动apache：

```
$ /usr/local/apache2.4/bin/apachectl start
```

## 5.安装PHP

 PHP官网：http://www.php.net/ 

·下载，解压同上

· 配置编译各种参数（进入php目录） 

```
$ cd php-5.6.36

$ ./configure \
> --prefix=/usr/local/php \
> --with-apxs2=/usr/local/apache2.4/bin/apxs \
> --with-config-file-path=/usr/local/php/etc \
> --with-mysql=/usr/local/mysql \
> --with-pdo-mysql=/usr/local/mysql \
> --with-mysqli=/usr/local/mysql/bin/mysql_config \
> --with-libxml-dir \
> --with-gd \
> --with-jpeg-dir \
> --with-png-dir \
> --with-freetype-dir \
> --with-iconv-dir \
> --with-zlib-dir \
> --with-bz2 \
> --with-openssl \
> --with-mcrypt \
> --enable-soap \
> --enable-gd-native-ttf \
> --enable-mbstring \
> --enable-sockets \
> --enable-exif
```

关于PHP的编译参数比较多，编译参数可以指定我们需要的功能模块，跟前面的httpd类似。上面的这些参数算是常用的，如果没有特殊要求，直接使用这些参数即可。

另外，apxs是httpd的一个工具，因为有它才会自动把PHP模块安装到httpd的modules目录下，也就是说PHP将会以一个模块的形式和httpd结合在一起工作。

遇到错误安装对应的包即可继续编译

```
$ yum install -y (包名称)
```

·接下来就是编译：

```
$ make
```

·然后安装：

```
$ make install 
```

·然后把配置文件放到`/usr/local/php/etc/`目录下改名为`php.ini`：

```
$ cp php.ini-production /usr/local/php/etc/php.ini
```

## 6.Apache和PHP结合

httpd的主配置文件是 /usr/local/apache2.4/conf/httpd.conf，对于这个文件，我们要做4处修改：

```
$ vim /usr/local/apache2.4/conf/httpd.conf				#做下面修改

ServerName www.example.com:80

<Directory />  
    AllowOverride none  
    Require all granted				#目的是允许所有请求，如果不做修改，则访问时候会显示403错误
</Directory>

AddType application/x-gzip .gz .tgz
AddType application/x-httpd-php .php				#注意php和.php之间有空格

<IfModule dir_module>
    DirectoryIndex index.html index.php
</IfModule>
```

·配置完成，保存退出。

可以测试一下配置语法是否正确：
```
$ /usr/local/apache2.4/bin/apachectl -t 

Syntax OK
```


说明配置语法没问题。

·然后重新加载配置文件：
```
$ /usr/local/apache2.4/bin/apachectl graceful
```


·启动服务：

```
$ /usr/local/apache2.4/bin/apachectl start
```


·查看是否启动：

```
$ netstat -lntp | grep 80
```

·最后，测试是否正确解析PHP：
```
$ vim /usr/local/apache2.4/htdocs/1.php

<?php
 echo "php解析正常";
?>

$ curl localhost/1.php

php解析正常[root@localhost php-5.6.36]# 
```

说明PHP解析正确。

另外，如果是利用浏览器来访问Linux（虚拟）机器，需要在Linux机器上打开80端口：

```
$ iptables -I INPUT -p tcp --dport 80 -j ACCEPT  
```


然后用浏览器访问linux机器的IP地址即可。

----

个人主页：[err0r.top](http://err0r.top/)

下班
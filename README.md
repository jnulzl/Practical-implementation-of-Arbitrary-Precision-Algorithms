# Practical implementation of Arbitrary Precision π Algorithms

## 环境

- 系统：Linux && Windows

- 编译器：g++ for Linux，Visual Studio 2022

- cmake

## 安装

```shell
>>git clone https://github.com/jnulzl/Practical-implementation-of-Arbitrary-Precision-Algorithms
>>cd Practical-implementation-of-Arbitrary-Precision-Algorithms
```

## 编译运行

```shell
>>cmake -B build_all -DCMAKE_BUILD_TYPE=Release
>>cmake --build build_all --config Release
#  For Linux
>>./build_all/BorweinNonic 
Usage:
	 ./build_all/BorweinNonic digits_of_pi
>>./build_all/BorweinNonic 50 
pi = 3.14159265358979323846242518065653893272160552913878E0
#  For Win
> build_all\Release\BorweinNonic.exe
Usage:
         build_all\Release\BorweinNonic.exe digits_of_pi
> build_all\Release\BorweinNonic.exe 50
pi = 3.14159265358979323846242518065653893272160552913878E0
```

**强烈建议阅读一下[Practical implementation of PI Algorithms](doc/HVE Practical implementation of PI Algorithms.pdf)，里面包含许多经典算法的源码！**


## 参考链接

以下参考链接均来自同一个人**[Henrik Vestermark](https://scholar.google.com/citations?user=A37RUQcAAAAJ&hl=da)**

- [Numerical Analysis & Applications](http://www.hvks.com)

- [Practical implementation of π Algorithms ](http://www.hvks.com/Numerical/Downloads/HVE%20Practical%20implementation%20of%20PI%20Algorithms.pdf)

- [Arbitrary precision package](http://www.hvks.com/Numerical/arbitrary_precision.html)

- [Numerical Papers](http://www.hvks.com/Numerical/papers.html)
## REVIEW-C++
1. 函数
   1. 形参(formal parameter) 实参(actual parameter)
   2. 将实参复制给形参——复制构造函数;函数运行结束,形参的析构函数释放形式参数
   3. 模板函数 template<class T>   
   T abc(T a,T b,T c)  
   {  
     语句;  
     return 返回值;  
   }  
   4. 引用参数(reference parameter) 无复制和释放  
   template<class T> 
   T abc(T& a.T& b,T& c)
   {  
     语句;  
     return 返回值;  
   }//可以修改变量值
   5. 常量应用(const reference)  
   指明引用参数不能被函数修改  
   T abc(const T& a,const T& b,const T& c)  
   {    
     语句;    
     return 返回值;   
   }  
   6. 返回值 可以返回一个值或者一个引用或一个常量引用  
   引用返回  T& mystery(int i,*T&z*) //定义了一个函数mystery,其返回值位T的一个引用


## 引入
1. 图书馆存放书籍，该怎么摆放 分类->字母
2. 输入N,打印1~N的所有正整数 循环/递归
3. 计算给定多项式再给定点x的 循环*x/秦九韶 第一个满很多…… 用#include<time.h> 不在测试范围内的准备工作写在clock()调用之前 
   * 调用clock()函数的模板
   * #include<stdio.h>
  #include<time.h>
  clock_t start,stop;/* clock_t是clock()函数的返回类型 */
double duration;   
int main()  
{  
  start=clock();  
  Myfunctions();  
  stop=clock();  
  duration=((double)(stop-start))/CLK_TCK;//常熟CLK_TCK是机器时钟每秒所走的时钟打点数  
  return 0;  
}  
4. 解决问题与数据结构，算法都有关
5. 数据对象在计算机中的组织方式 
   1. 结构:线性结构 树形结构 图的结构
   2. 物理存储:数组 链表
6. 抽象数据类型
   * 数据类型:**数据对象集**，**数据集合相关联的操作集**
   * 抽象:不依赖于如何做到。没有具体的值或者是存储数据的大小
7. 算法 Algorithm
   * 每一条指令不能有歧义
   * 计算机能处理的范围内(量子计算机VS通用量子计算机)
   * 描述应该不依赖于任何一种计算机语言
 * 空间复杂度和时间复杂度 S(n) T(n) 与数据规模有关
 * 机器算加减法几乎忽略不算，只要算乘除法
 * 分析算法效率 Tworst(n) Tavg(n) 但是一般只要比较数据增长时，时间增长的快慢
8. 最大子列和
   1. 全部算一遍 O(N^3) 每次都重新算
   2. 合理使用上次相加的值再加下一个值 减少一个循环 O(N^2)
   3. 分而治之 分一半 递归分别算左边右边和跨越的返回值
   4. 在线处理 如果从i到j的值之和小于0，直接舍弃

## 线性表结构 Linear List
1. 由同类型数据元素构成有序序列的线性结构
   * 几个概念：长度 空表 表头 表尾
2. 线性表的顺序存储实现 数组 
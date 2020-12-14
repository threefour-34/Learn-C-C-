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
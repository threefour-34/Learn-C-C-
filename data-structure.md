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

   
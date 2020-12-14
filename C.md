## 编写程序流程
1. **定义程序目标**
2. **设计程序**
3. 编写代码
4. 编译
5. 运行程序
6. 测试和调试
7. 维护和修改

---

## Concepts Explanation
* 编译器 编译器是把源代码转换成可执行代码的程序
* 可执行代码 是用计算机的机器语言表示的代码。
* 源代码文件source code file(.c)
  * basename，extension
* 目标代码文件缺失启动代码（startup code）  启动代码充当着程序和操作系统之间的接口
* 链接器 把你编写的目标代码、系统的标准启动代码和库代码 这 3 部分合并成一个文件，即可执行文件
* **源代码-编译器-目标代码-链接器-可执行代码** 
    PS:简而言之，目标文件和可执行文件都由机器语言指令组成的。然而，目标文件中只包含编译器为你编写的代码翻译的机器语言代码，可执行文件中 还包含你编写的程序中使用的库函数和启动代码的机器代码。

---

## Basic 
* 存储单元
  * 位(bit)
    * 储存0和1
  * 字节(byte)
    * 1字节为8位
  * 字
    * 设计计算机时给定的自然存储单位
    * 目前为64位，字长越长，数据转移越快，允许的内存访问越多
* 程序输出一闪而过:
  * getchar();  
    return 0;
* \n :换行符 newline character,使光标移至下一行的起点
* static/extern函数
  * 用static定义函数:只能在源文件中使用,其他文件无法使用,具有私密性
    * 全局static,全局可用
    * 局部static,局部可用
  * 用extern定义函数:可以在外部文件中使用
* printf("",,)
  * %.2f //只显示小数点前两位
  * 若直接测试printf("%d"),则打印的值为内存中的任意值
    * 所以打印数量要一致
  * 前缀!!,保证格式一致,否则后果严重
  * 八进制%o %O,若要显示前缀,则分别用%#o(0)
  * 十六进制%x %X,显示前缀%#x(0x),%#X(0X)
  * 转换说明修饰符
    * 例 int a=100; printf("*a=%10d*\n")  * (这里有7个空格)100 * PS(一共10位,默认左边补空格,若为-10,则输出* 100(这里有7个空格) *)
    * * %*d 通过程序指定字段宽度
    * int width=8; int number=222.2; int precision=3;
    * printf("the number is:%*.*d:\n",width,precision,number);
    * 222.200
* scanf()
  * &
  * 数字表示最大字段宽度
    * "%10s"
  * %hhd/%hhu 将整数作为signed char/unsigned char
  * **转换说明**
  * 例 %d 每次读取一个字符，跳过所有空白字符，直至遇到第一个非空白字符才开始读取;但是若使用字段宽度，scanf会在字段结尾或者第一个非空白字符处停止读取;若第一个非空格字符为A,则无法读取;C规定在第一个出错处就停止读取输入
  * %s 读取除了空格之外的所有字符
  * %c 
    * 若为scanf("%c",  &ch) 则从输入的第一个字符开始   
    * 若为scanf("%c",&ch) 则从第一个非空白字符开始读取
  * %*d 跳过相应项
    * scanf("%\*d%\*d%d",&a);//跳过输入的前两个整数.
* constant/variable 常量/变量
* variable
  * 存储方式不同
  * 某些运算浮点型损失的精度越大
  * 整型
    * int
      * 有符号
      * -2^31~2^31-1  -214773648~2147483647
      *  %d
      *  溢出从-214773648重新开始
     * short (int) 数值小(16位) %hd %ho %hx
     * long 数值大(32位) %ld/long long (64位)速度慢,非必须不用
     * unsigned 非负值0~65535 %u %lu(unsigned long)
  * 字符型
    * char
      * string='a';
      * 转义序列
      * %c
 * 浮点型
   * float
     * 10e-37~10e+37  2E10 100. .2 .2E-22
     * 可以没有小数点或者指数部分，但是不能同时省略两者
     * 浮点型常量中间不要加空格
     * %f %e(打印指数记数法的浮点数)
   * double
     * 没有后缀的浮点型常量为double型,f/F改为float,l/L改为long double
 * 复数和虚数类型
   * float_Complex,double_Complex,long double_complex
   * float_Imaginary,double_Imaginary,long double_Imaginary
 * sizeof()以字节为单位给出类型的大小
* auto/register/static/extern
* 表示字符常量
  * \101 101为八进制数(最长原则)
  * \x41 41为十六进制数  \xhh……
  * 直接用字符A 
  * char str[]="salal\10a\1s11\111"
* 整数除法损失小数部分
* % 取模运算符(modulus operator)
  * 只要a和b都是整数值，便可通过a - (a/b)*b来计算a%b
* 递增递减符号
  * 优先级  x*y++表示的是(x)*(y++)，而不是(x*y)++
  * 如果n++是表达式的一部分，可将其视为“先使用n，再递增”；而++n则表示“先递增n，再使用”。
* 强制类型转换运算符
  * (type)name

***

## 字符串
* strlen()函数 数组中(内容)字符的个数
  * string.h 头文件
  * 其他函数
    * strcmp(string1，string2)函数 比较两个数组是否相同 相同返回0 不同时给出第一个不同字符的ASCII码的差值
    * strcpy(string1，string2)函数，将string2拷贝到string1，并且返回string1 \*其中string1和string2不重叠
      * 套路 复制一个字符串 char \*dst=(char\*)malloc(strlen(src)**+1**);strcpy(dst,src);//动态内存分布时加1是因为\0.
    * char\*strchr(const char*s,int c)查找某个字符第一次出现的次序，找不到就返回NULL,找到了就**返回**一个指向那个字符的**指针**
      * 套路 找第二个字符 char string[]="hellololo";char \*p=strchr(string,'l');p=strchr(p+1,'l');
      * 打印*p所指的字符前面的字符串(即在上一个例子中输出he)  char string[]="hellololo";  
  char \*p=strchr(string,'l');  
  char c=\*p;  
  \*p='\0';  
  printf("%s",string);  
  \*p=c; //将string改回来
      * strstr()函数 字符串中查找字符串
      * strcasestr()函数 查找字符串但是忽略字母大小写
* sizeof(string)/sizeof(string[0]) ??不知道是否可以正确算出 char string[100]="hello array";
* 用字符型数组储存字符串
* "" 双引号
  * "x"!='x'
    * 'x' char类型
    * "x" char数组 'x'和'\0'
* '\0' 空字符 null character 非打印字符
* scanf()不读取空格,且不要加&
* 字符串数组 char**a 指向指针2的指针1，然后指针2指向数组
* char a[][]  或者char *a[] 这两个不一样

## 数组
* 函数参数表中的数组实际上使指针 void swap(int a[]) 【单个[] *也可】 (函数原型)等价于 void swap(int *a) 可以用a[i]
* 数组变量本身表达地址，但是每一个变量不是 a==&a[0] 可以有&a[i],但是不能有&a,也不必要int *p=a;
* 可以用*a 赋值
* sizeof(string)/sizeof(string[0])

## 指针
* const修饰 为了保证数组不被函数破坏就可以加const
  * int i;
  * const int *p=&i;与下面的那个一样 不能通过指针去修改那个变量 即不能 *p=1;
  * int const* p=&i;
  * int *const p=&i;表示一旦得到了某个变量的地址，就不能再指向其他变量
* 指针的运算
  * + - += -= ++ -- 两个指针相减 可以运算
  * int arr[]={1,2,3,4,5,6,7};  
int *p=arr;  
p=p+1;往后移一位  
*p==arr[0];  
*(p+1)==arr[1]; // *运算符优先级比+高，所以要加();
  * 两个指针相减 意义为两个地址的差/sizeof(type) 在这两个地址中间有几个这样类型的"东西"存在
  * *p++ 取除p所指的数据，再将p移到后一个位置去 *的优先级没有++高 常用于数组的连续空间操作 在某些CPU上可以直接翻译为编译语言
* 指针的比较
  * 比较在内存中的地址
* NULL
* 无论指向什么类型，所有指针的大小都是一样的，因为都是地址;但是指向不同类型的指针不能直接相互赋值
* void *p
* 指针的类型转换
  * int *p=&i;void *q=(void *)p;//这不改变p所指变量的类型

## 动态内存分布
* *example* int n;scanf("%d",&n);int\*arr;arr=(int\*)malloc(n\* sizeof(int)); //分配n\*sizeof(int)给数组arr
* 记得一定要在合适的地方free(arr);可以free(NULL);但是不能重复free

## enumeration
用枚举而不是定义独立的const int变量  
enum 枚举类型名字{名字0，名字1……名字n} //都是int常量，数值分别为0~n 也可以指定值 名字1=8,后面的就依次加1  
* 套路——自动计数(需要遍历所有枚举量时)
  * enum colors{red,green,white,numcolors};  
  char *arr[numcolors]={……};

## struct 结构体
1. struct DATE{int month;int year; int day;}**;**
2. struct {int x;int y;} p1,p2; //结构体没有名字，只不过定义了p1,p1这两个变量，变量类型为自定义的结构体
3. struct point{int x;int y;} p1,p2; //定义结构体的同时创建两个变量

若放在main函数中，则只能在函数内部使用;若放在main函数外面，(即与函数相同地位)则可以被多个main函数使用  
**类型为 struct DATE而不是DATE**  
struct DATE today={按顺序依次赋值};//或者不按顺序直接.year=……，.month=……；    
today.year=……；
today.day=……；

结构体数组  
struct DATE dates[100]={{ },{ }};  

指向结构体指针 struct DATE *p=&today;  
(*p).month=12;  
或者 p->month=12; //PS:只有指针能够用->,其他变量名只能用.

## 自定义数据类型
1. 例：typedef int length;//使length成为int的别名  
length a,b,len;
2. 简化结构体(省去struct)
typedef struct DATE { int month;int year;int day} Date; //可以用Date代替struct DATE(别名)

## union联合

## 函数指针
例 void f()
{
  printf("lalal");
}
void g()
{
  printf("lalalll");
}
void h()
{
  printf("lalalhh");
}
在main 函数中  
void (*pf)()=f; //指向函数的指针,作用
f();
(*pf)();

或者
在main 函数中  
void (*pf[3])()={f,g,h}; //指向函数的指针,作用
int i;
scanf("%d",&i);
if(i>=0 && i<sizeof(pf)/sizeof(pf[0]))
{
  (*pf[i])();
}
//用法 1. 比如说用户输入一个指令，然后执行某个函数 
2.用作函数的参数,即将函数传入函数中
int plus(int a,int b)
{
  return a+b;
}
void cal(int (*p)(int ,int),int a,int b)
{
    printf("%d",(*p)(a,b));
}

## 回调函数???

## 文件的输入输出 很少用了，要么用第三方的函数，要么用数据库
在stdio.h头文件中包含相关函数  
打开文件的标准代码  
FILE*fp=fopen("file","r")   
//对于fopen函数(对于文本读写)
r打开只读  
r+打开读写，从文件头开始   
w打开只写，若不存在则新建，存在则清空   
w+打开读写，若不存在则新建，存在则清空  
a 打开追加，若不存在则新建，存在则从文件尾开始(即若是要写，则不清空，而是从文件尾部继续加)  
..x 只新建，若文件已存在则不能打开  
fwrite()函数等等
if(fp){  
    fscanf(fp,……);//后面……的内容与scanf一样  
    fclose(fp);   
}  
else{  
  ……  
}  



## CONSTANT
* #define指令
  * #define NAME VALUE(无等号,末尾无分号,一般用大写表示符号常量)
    * #define PI 3.1415926 
* const限定符
  * 只读不改
  * const type name=value;
    * const int months=12;
* float.h头文件和limits.h头文件中有一些已经定义了的明示常量

___

## OTHERS
* #ifdef 和 #endif
* 用异或交换整数ab的值
  * int a=10;int b=11;
  * a=a^b;
  * b=a^b;
  * a=a^b;
* 按位运算 对二进制进行运算
  * 按位与 & 对应位上都是1结果才为1，其他都为0  
  * 按位或 | 对应位上有一个为1结果为1，其他都为0
  * 按位取反 ~ 每一位都取反
  * 按位的异或 ^ 若两位相等，结果为0，不相同，为1
  * 左移 <<  x<<2等价于 x*=4  x<<n等价于 x*=2^n 
  * 右移 >>  右移 对于signed类型(比如普通的int 类型)考虑符号位，符号位不变
    * 移位不要移负数
* 不创建临时变量交换两个数的值
  * a=a+b;
  * b=a-b;
  * a=a-b;
* ACLLib
  * 写Windows应用程序

## 位段 bit field
int main(){
    struct bs{
        unsigned m;
        unsigned n: 4;
        unsigned char ch: 6;
    } a = { 0xad, 0xE, '$'};
    //第一次输出
    printf("%#x, %#x, %c\n", a.m, a.n, a.ch);
    //更改值后再次输出
    a.m = 0xb8901c;
    a.n = 0x2d;
    a.ch = 'z';
    printf("%#x, %#x, %c\n", a.m, a.n, a.ch);
    return 0;
}

运行结果：
0xad, 0xe, $
0xb8901c, 0xd, :

对于 n 和 ch，第一次输出的数据是完整的，第二次输出的数据是残缺的。

第一次输出时，n、ch 的值分别是 0xE、0x24（'$' 对应的 ASCII 码为 0x24），换算成二进制是 1110、10 0100，都没有超出限定的位数，能够正常输出。

第二次输出时，n、ch 的值变为 0x2d、0x7a（'z' 对应的 ASCII 码为 0x7a），换算成二进制分别是 10 1101、111 1010，都超出了限定的位数。超出部分被直接截去，剩下 1101、11 1010，换算成十六进制为 0xd、0x3a（0x3a 对应的字符是 :）。

C语言标准规定，位域的宽度不能超过它所依附的数据类型的长度。通俗地讲，成员变量都是有类型的，这个类型限制了成员变量的最大长度，:后面的数字不能超过这个长度。

无名位域  
位域成员可以没有名称，只给出数据类型和位宽，如下所示：
struct bs{
    int m: 12;
    int  : 20;  //该位域成员不能使用
    int n: 4;
};
无名位域一般用来作填充或者调整成员位置。因为没有名称，无名位域不能使用。

上面的例子中，如果没有位宽为 20 的无名成员，m、n 将会挨着存储，sizeof(struct bs) 的结果为 4；有了这 20 位作为填充，m、n 将分开存储，sizeof(struct bs) 的结果为 8。


## 程序结构
1. 全局变量 定义在函数外部 
   没有初始化的全局变量会得到0，指针会得到NULL  
   只能用编译时刻已知的值来初始化全局变量  
   初始化发生在main之前  
   int gALL=1;int gALL2=gALL;//error  
   const int gALL=1;int gALL2=gALL;//right  
   在main或其他函数修改了可变的全局变量，则修改处以后的全局变量的值全部修改  
   如果在一个更小的范围内定义了一个同名变量，则这个范围内的值为新定义的那个值。
2. 静态本地变量(有全局的生存期，函数内局部的作用域)
   加上static修饰符  
   例 int f()  
   { 
     static int a=1;  
     printf("a=%d",a);  
     a+=2;
     printf("a(again)=%d",a);  
     return a;  
   }  
   int main()  
   {
     f();  //a=1 a(again)=3  
     f();  //a=3 a(again)=5
     f();  //a=5 a(again)=7
   }
3. tips
   返回本地变量的地址是危险的/返回全局变量或者静态变量的地址是安全的(对于返回指针的函数)  
   返回在函数内部malloc的内存是安全的，但是容易造成问题  
   不要使用全局变量在函数间传递参数和结果  
   **尽量避免使用全局变量**  

## 编译预处理
1. #开头的是编译预处理指令
2. \#define用来定义一个宏 例\#define PI 3.1415926 //结尾不加分号 如果一个宏超过一行，最后一行之前的行末都需要加\\(就是单个反斜杠) 
   例 \#define PRT printf("%d",PI);\\
                   printf("%d",PI*2)   //不加';'
3. 还有一些以及定义了的 例_LINE_ 自己搜
4. 在结尾绝对不加';'
5. 宏可以带参数 例\#define cube(x) ((x)\*(x)\*(x))
6. 错误定义宏
   例 \#define A1(x) (x*15.123)  
      \#define A2(x) (x)*15.123  
      int main()  
      {  
          printf("%f",A1(5+2));  
          printf("%f",100/A2(1));
      }  

      实际 
          printf("%f",(5+2*15.123));  
          printf("%f",100/(1)*15.123);  
      正确 \#define A1(x) ((x)*15.123)  
           \#define A2(x) ((x)*15.123)  
           对于带参数的宏
           1. 整个值要括号
           2. 参数出现的每个地方都要括号 

## 大程序结构
1. 一般的做法是任何.c都有对应的同名的.h,把所有对外公开的函数的原型和全局变量的声明都放进去
2. 只有声明可以放在头文件中 同名结构不能重复声明所以用#ifndef #define #endif(#pragma once  也可以起到相同作用)


学习路线 C语言进阶，数据结构，Java面向对象，数据库（大数据），Python程序设计(处理数据)，神经网络与深度学习，计算机网络，DevOps导论  
加各种书籍推荐参考什么的  
网络资料课程  
**！做项目！**


## MVC???


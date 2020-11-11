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

***

## 字符串
* strlen()函数
  * string.h 头文件
* 用字符型数组储存字符串
* "" 双引号
  * "x"!='x'
    * 'x' char类型
    * "x" char数组 'x'和'\0'
* '\0' 空字符 null character 非打印字符
* scanf()不读取空格

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


# 2020.11.11 PAGE217
#include <stdio.h>
#include <stdarg.h>


void
simple_va_fun(int start, ...){

  va_list arg_ptr; /*就是 char * 类型*/
  int nArgValue = start;
  int nArgCount = 0; /*可变参数的数目*/
  va_start(arg_ptr, start); /*以固定参数的地址为起点确定变参的内存起始地址*/
  do{
    ++nArgCount;
    printf("the %d th arg: %d\n", nArgCount, nArgValue); /* 输出各参数的值 */
    nArgValue = va_arg(arg_ptr, int); /* 得到下一个可变参数的值 */
  }while(nArgValue != -1);

  return;
}

void
func(int a, int b, int c){
  printf("&a = %p, &b = %p, &c = %p\n", &a, &b, &c);
}

int 
main(int argc, char **argv){

  simple_va_fun(100, -1);
  simple_va_fun(100, 200, -1);

  func(10, 20, 30);

  return 0;
}
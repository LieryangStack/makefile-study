#ifndef __T_DOUBLE_H__
#define __T_DOUBLE_H__


#include <glib-object.h>
/**
 * G_DECLARE_FINAL_TYPE 中要使用 T_TYPE_DOUBLE
*/
#define T_TYPE_DOUBLE (t_double_get_type ())
/**
 * 1.声明 <name space>_<name>_get_type ()函数.这仅仅是一个声明，可以通过G_DEFINE_TYPE定义
 * 2.声明typedef struct _TDouble TDouble
 * 3.定义T_DOUBLE宏
 * 4.定义T_IS_DOUBLE宏
 * 5.类结构体TDoubleClass被定义 (一个最终类对象不需要有自己的类成员)
 *  typedef struct _TDoubleClass TDoubleClass
 *  struct _TDoubleClass {
 *    GObjectClass parent_class;
 *  };
*/
G_DECLARE_FINAL_TYPE (TDouble, t_double, T, DOUBLE, GObject);

gboolean
t_double_get_value (TDouble *d, double *value);

void 
t_double_set_value (TDouble *d, double vlaue);

TDouble *
t_double_new (double value);



#endif

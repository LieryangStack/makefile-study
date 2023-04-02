#include "tdouble.h"

struct _TDouble {
  GObject parent;
  double value;
};
/**
 * 该宏可以做以下内容：
 * 1.声明一个类的初始化函数 <name space>_<name>_class_init.
 * 2.声明一个实例的初始化函数 <name space>_<name>_init.
 * 3.定义一个静态变量指向父类 <name space>_<name>_parent_class
 * 4.定义一个 <name space>_<name>_get_type () 函数
 *   该函数的实现需要 class_size 和 instance_size
*/
G_DEFINE_TYPE (TDouble, t_double, G_TYPE_OBJECT)

static void
t_double_class_init (TDoubleClass *class){
}

static void
t_double_init (TDouble *d) {
}

gboolean
t_double_get_value (TDouble *d, double *value) {
  g_return_val_if_fail (T_IS_DOUBLE (d), FALSE);
 
  *value = d->value;
   return TRUE;
}
 
void
t_double_set_value (TDouble *d, double value) {
  g_return_if_fail (T_IS_DOUBLE (d));
 
  d->value = value;
}
 
TDouble *
t_double_new (double value) {
  TDouble *d;
 
  d = g_object_new (T_TYPE_DOUBLE, NULL);
  d->value = value;
  return d;
}



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
 * 5.定义类结构体TDoubleClass (一个最终类对象不需要有自己的类成员)
 *  typedef struct _TDoubleClass TDoubleClass
 *  struct _TDoubleClass {
 *    GObjectClass parent_class;
 *  };
*/
G_DECLARE_FINAL_TYPE (TDouble, t_double, T, DOUBLE, GObject)

struct _TDouble{
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
t_double_class_init (TDoubleClass *class) {
}

static void
t_double_init (TDouble *d) {
}

int
main (int argc, char **argv) {
  GType dtype;
  TDouble *d;

  dtype = t_double_get_type (); /* or d = T_TYPE_DOUBLE */
  if (dtype)
    g_print ("Registration was a success. The type is %lx.\n", dtype);
  else
    g_print ("Registration failed.\n");

  d = g_object_new (T_TYPE_DOUBLE, NULL);
  if (d)
    g_print ("Instantiation was a success. The instance address is %p.\n", d);
  else
    g_print ("Instantiation failed.\n");

  if (T_IS_DOUBLE (d))
    g_print ("d is TDouble instance.\n");
  else
    g_print ("d is not TDouble instance.\n");

  if (G_IS_OBJECT (d))
    g_print ("d is GObject instance.\n");
  else
    g_print ("d is not GObject instance.\n");

  return 0;
}


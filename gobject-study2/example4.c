#include <glib-object.h>

#define T_TYPE_DOUBLE (t_double_get_type ())

typedef struct _TDouble TDouble;
struct _TDouble {
  GObject parent;
  double value;
};

typedef struct _TDoubleClass TDoubleClass;
struct _TDoubleClass {
  GObjectClass parent_class;
};

/**
 * 该宏可以做以下内容：
 * 1.声明一个类的初始化函数 <name space>_<name>_class_init.
 * 2.声明一个实例的初始化函数 <name space>_<name>_init.
 * 3.定义一个静态变量指向父类 <name space>_<name>_parent_class
 * 4.定义一个 <name space>_<name>_get_type () 函数
*/
G_DEFINE_TYPE(TDouble, t_double, G_TYPE_OBJECT)

static void
t_double_class_init (TDoubleClass *class){
  g_print("t_double_class_init...\n");
}

static void
t_double_init (TDouble *d) {
  g_print("t_double_init...\n");
}

int
main (int argc, char **argv) {
  GType dtype;
  TDouble *d, *d1;
  GObject *object;
  GObjectClass *class;

  object = g_object_new(G_TYPE_OBJECT, NULL);
  class = G_OBJECT_GET_CLASS(object);
  g_print ("gobject class address is %p\n", class);

  dtype = t_double_get_type (); /* or d = T_TYPE_DOUBLE */
  if (dtype)
    g_print ("Registration was a success. The type is %lx.\n", dtype);
  else
    g_print ("Registration failed.\n");

  d = g_object_new (T_TYPE_DOUBLE, NULL);
  d1 = g_object_new (T_TYPE_DOUBLE, NULL);
  g_print ("parent_class address is %p\n", t_double_parent_class); /* 指向GObjectClass地址 */
  if (d)
    g_print ("Instantiation was a success. The instance address is %p.\n", d);
  else
    g_print ("Instantiation failed.\n");

  g_object_unref(d);
  g_object_unref(d1);
  d = NULL;
  d1 = NULL;

  return 0;
}

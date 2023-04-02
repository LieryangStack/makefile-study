#include <glib-object.h>

#define T_TYPE_DOUBLE (t_double_get_type ())

typedef struct _TDoubleClass TDoubleClass;
struct _TDoubleClass{
  GObjectClass parent_class;
};

typedef struct _TDouble TDouble;
struct _TDouble{
  GObject parent;
  double value;
};

static void
t_double_class_init (TDoubleClass *class){

}

static void
t_double_init (TDouble *d){

}

GType
t_double_get_type (void) {
  static GType type = 0;
  GTypeInfo info;

  if (type == 0) {
    info.class_size = sizeof (TDoubleClass);
    /* 这些函数是初始化/最终化类的动态成员，在大多数情况下，他们不是必须的，一般赋值NULL */
    info.base_init = NULL;
    info.base_finalize = NULL;
    /* 初始化类的静态成员，用类初始化函数赋值 */
    info.class_init = (GClassInitFunc) t_double_class_init;
    /* 类的最终化，因为GObject子类的类型是静态的，它没有最终化函数 */
    info.class_finalize = NULL;
    /* 可以传入到 init/finalize 函数里 */
    info.class_data = NULL;
    info.instance_size = sizeof (TDouble);
    /* 这个是被忽略的，它在Glib的旧版本已经使用 */
    info.n_preallocs = 0;
    info.instance_init = (GInstanceInitFunc) t_double_init;
    /* 这个仅仅对于fundamental type是游泳的，如果是GObject子类，通常赋值NULL */
    info.value_table = NULL;
    type = g_type_register_static (G_TYPE_OBJECT, "TDouble", &info, 0);
  }
  return type;
}

int
main(int argc, char **argv) {
  GType dtype;
  TDouble *d;

  /* or dtype = T_TYPE_DOUBLE */
  dtype = t_double_get_type ();
  if (dtype) {
    g_print ("Registration was a success. The type is %lx.\n", dtype);
  } else {
    g_print ("Registration failed.\n");
  }

  d = g_object_new (T_TYPE_DOUBLE, NULL);
  if (d) {
    g_print ("Instantiation was a success. The instance address is %p.\n", d);
  } else {
    g_print ("Instantiation failed.\n");
  }

  return 0;
}


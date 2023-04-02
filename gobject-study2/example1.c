#include <glib-object.h>

int
main (int argc, char **argv) {
  GObject *instance1, *instance2;
  GObjectClass *class1, *class2;

  /* 变量 G_TYPE_OBJECT 表示一种类型， GObject有自己的类型系统 
   * G_TYPE_OBJECT已经被注册到类型系统里面了, glib提供了一系列注册类型函数
   * GType 是一个无符号长整形变量
   * 每一个注册到系统的类型，都会有一个GType值
   * GObject是一个静态基类（实例的内存释放，类的内存也不会释放）
   */
  instance1 = g_object_new (G_TYPE_OBJECT, NULL);
  instance2 = g_object_new (G_TYPE_OBJECT, NULL);

  g_print ("The address of instance1 is %p\n", instance1);
  g_print ("The address of instance2 is %p\n", instance2);

  class1 = G_OBJECT_GET_CLASS (instance1);
  class2 = G_OBJECT_GET_CLASS (instance2);

  g_print ("The address of the class of instance1 is %p\n", class1);
  g_print ("The address of the class of instance2 is %p\n", class2);

  g_print ("The memory of GObject is %ld\n", sizeof(GObject));
  g_print ("The memory of GObjectClass is  %ld\n", sizeof(GObjectClass));


  g_object_unref (instance1);
  g_object_unref (instance2);

  return 0;
}
#ifndef __T_STR_H__
#define __T_STR_H__

#include <glib-object.h>

#define T_TYPE_STR (t_str_get_type ())
/**
 *  1.t_number_get_type()函数的声明。该函数必须在tnumber.c文件中定义。
 *       该宏的定义通常使用G_DEFINE_TYPE或其家族宏完成。
 *  2.定义TNumber实例，其成员仅为其父实例。
 *    typedef _TStr TStr {
 *      GObject parent;
 *    };
 *  3.typedef _TStrClass TStrClass
 *  4.定义了方便宏T_NUMBER(转换为实例)，T_NUMBER_CLASS(转换为类)，
 *      T_IS_NUMBER(实例检查)，T_IS_NUMBER_CLASS(类检查)和T_NUMBER_GET_CLASS。
 *  5.g_autoptr()的支持。
*/
G_DECLARE_DERIVABLE_TYPE (TStr, t_str, T, STR, GObject)

struct _TStrClass {
  GObjectClass parent_class;
  /* expect that descendants will override the setter */
  void (*set_string) (TStr *self, const char *s);
};

TStr *
t_str_concat (TStr *self, TStr *other);

/* setter and getter */
void
t_str_set_string (TStr *self, const char *s);

char *
t_str_get_string (TStr *self);

/* create a new TStr instance */
TStr *
t_str_new_with_string (const char *s);

TStr *
t_str_new (void);

#endif /* __T_STR_H__ */

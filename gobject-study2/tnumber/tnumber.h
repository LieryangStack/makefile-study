#ifndef __T_NUMBER_H__
#define __T_NUMBER_H__

#include <glib-object.h>

#define T_TYPE_NUMBER             (t_number_get_type ())
/**
 *  1.t_number_get_type()函数的声明。该函数必须在tnumber.c文件中定义。
 *       该宏的定义通常使用G_DEFINE_TYPE或其家族宏完成。
 *  2.定义TNumber实例，其成员仅为其父实例。
 *    typedef _TNumber TNumber {
 *      GObject parent;
 *    };
 *  3.typedef _TNumberClass TNumberClass
 *  4.定义了方便宏T_NUMBER(转换为实例)，T_NUMBER_CLASS(转换为类)，
 *      T_IS_NUMBER(实例检查)，T_IS_NUMBER_CLASS(类检查)和T_NUMBER_GET_CLASS。
 *  5.g_autoptr()的支持。
*/
G_DECLARE_DERIVABLE_TYPE (TNumber, t_number, T, NUMBER, GObject)

struct _TNumberClass {
  GObjectClass parent_class;
  TNumber* (*add) (TNumber *self, TNumber *other);
  TNumber* (*sub) (TNumber *self, TNumber *other);
  TNumber* (*mul) (TNumber *self, TNumber *other);
  TNumber* (*div) (TNumber *self, TNumber *other);
  TNumber* (*uminus) (TNumber *self);
  char * (*to_s) (TNumber *self);
  /* signal */
  void (*div_by_zero) (TNumber *self);
};

/* arithmetic operator */
/* These operators create a new instance and return a pointer to it. */
TNumber *
t_number_add (TNumber *self, TNumber *other);

TNumber *
t_number_sub (TNumber *self, TNumber *other);

TNumber *
t_number_mul (TNumber *self, TNumber *other);

TNumber *
t_number_div (TNumber *self, TNumber *other);

TNumber *
t_number_uminus (TNumber *self);

char *
t_number_to_s (TNumber *self);
#endif /* __T_NUMBER_H__ */


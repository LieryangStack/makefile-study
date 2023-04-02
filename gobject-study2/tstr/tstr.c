#include "tstr.h"

/**
 * 用于注册多个类属性
*/
enum {
  PROP_0,
  PROP_STRING,
  N_PROPERTIES
};

static GParamSpec *str_properties[N_PROPERTIES] = {NULL, };

/**
 * 因为是用 G_DECLARE_DERIVABLE_TYPE 宏声明的可派生类，所以宏定义了实例结构体
 * 实例结构体成员可以看作是私有区域
 * 可派生类没有实例，故通过TStrPrivate定义私有成员
*/
typedef struct {
  char *string;
} TStrPrivate;

/**
 * 1.声明t_str_class_init是一个类初始化函数。
 * 2.声明实例初始化函数t_str_init。
 * 3.定义t_str_parent_class静态变量。它指向TStr的父类。
 * 4.将私有实例数据添加到类型中。它是一个C结构，它的名字是TStrPrivate。
 * 5.定义t_str_get_type()函数。该函数在第一次调用时注册该类型。
 * 6.定义一个私有实例getter函数t_str_get_instance_private()。这个函数有一个参数，它是指向实例的指针。
*/
G_DEFINE_TYPE_WITH_PRIVATE (TStr, t_str, G_TYPE_OBJECT)

static void
t_str_set_property (GObject *object, guint property_id,
                    const GValue *value, GParamSpec *pspec) {
  TStr *self = T_STR (object);
  if (property_id == PROP_STRING) {
    t_str_set_string (self, g_vlaue_get_string (value));
  } else {
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
t_str_get_property (GObject *object, guint property_id,
                    GValue *value, GParamSpec *pspec) {
  TStr *self = T_STR (object);
  if (property_id == PROP_STRING) {
    g_value_set_string (value, g_vlaue_get_string (self));
  } else {
    G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
  }
}

static void
t_str_real_set_string (TStr *self, const char *s) {
  TStrPrivate *priv = t_str_get_instance_private (self);

  if (priv->string)
    g_free (priv->string);
  priv->string = g_strdup (s);
}

static void
t_str_finalize (GObject *object) {
  TStr *self = T_STR (object);
  TStrPrivate *priv = t_str_get_instance_private (self);

  if (priv->string)
    g_free (priv->string);
  G_OBJECT_CLASS (t_str_parent_class)->finalize (object);
}

static void
t_str_init (TStr *self) {
  TStrPrivate *priv = t_str_get_instance_private (self);
  priv->string = NULL;
}

static void
t_str_class_init (TStrClass *class) {
  GObjectClass *gobject_class = G_OBJECT_CLASS (class);

  gobject_class->finalize = t_str_finalize;
  gobject_class->set_property = t_str_set_property;
  gobject_class->get_property = t_str_get_property;
  str_properties[PROP_STRING] = g_param_spec_string ("string", "str", "string", "", G_PARAM_READWRITE);
  g_object_class_install_properties (gobject_class, N_PROPERTIES, str_properties);

  class->set_string = t_str_real_set_string;
}

/* setter and getter */
void
t_str_set_string (TStr *self, const char *s) {
  g_return_if_fail (T_IS_STR (self));
  TStrClass *class = T_STR_GET_CLASS (self);

  class->set_string (self, s);
}

char *
t_str_get_string (TStr *self) {
  g_return_val_if_fail (T_IS_STR (self), NULL);
  TStrPrivate *priv = t_str_get_instance_private (self);

  return g_strdup (priv->string);
}

TStr *
t_str_concat (TStr *self, TStr *other) {
  g_return_val_if_fail (T_IS_STR (self), NULL);
  g_return_val_if_fail (T_IS_STR (other), NULL);

  char *s1, *s2, *s3;
  TStr *str;

  s1 = t_str_get_string (self);
  s2 = t_str_get_string (other);

  if (s1 && s2) 
    s3 = g_strconcat (s1, s2, NULL);
  else if (s1)
    s3 = g_strdup (s1);
  else if (s2)
    s3 = g_strdup (s2);
  else
    s3 = NULL;
  str = t_str_new_with_string (s3);
  if (s1) g_free (s1);
  if (s2) g_free (s2);
  if (s3) g_free (s3);
  return str;
}

TStr *
t_str_new_with_string (const char *s) {
  return T_STR (g_object_new (T_TYPE_STR, "string", s, NULL));
}

TStr *
t_str_new (void) {
  return T_STR (g_object_new (T_TYPE_STR, NULL));
}
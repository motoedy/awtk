﻿/**
 * File:   style_mutable.h
 * Author: AWTK Develop Team
 * Brief:  mutable style
 *
 * Copyright (c) 2018 - 2018  Guangzhou ZHIYUAN Electronics Co.,Ltd.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * License file for more details.
 *
 */

/**
 * History:
 * ================================================================
 * 2018-10-31 Li XianJing <xianjimli@hotmail.com> created
 *
 */

#ifndef TK_STYLE_MUTABLE_H
#define TK_STYLE_MUTABLE_H

#include "base/style.h"

BEGIN_C_DECLS

/*遍历的回调函数*/
typedef ret_t (*tk_on_style_item_t)(void* ctx, uint32_t widget_state, style_id_t id,
                                    const value_t* val);

struct _widget_state_style_t;
typedef struct _widget_state_style_t widget_state_style_t;

/**
 * @class style_mutable_t
 * @parent style_t
 * @annotation ["scriptable"]
 * 控件风格(可实时修改并生效，用于在designer中被编辑的控件)。
 */
typedef struct _style_mutable_t {
  style_t style;

  /**
   * @property {char*} name
   * @annotation ["readable","scriptable"]
   * 名称。
   */
  char* name;
  /**
   * @property {widget_t*} widget
   * @annotation ["private"]
   * 与之关联的控件。
   */
  widget_t* widget;
  /**
   * @property {style_t*} default_style
   * @annotation ["private"]
   * 缺省的style，在mutable中找不到时，再到default_style中找。
   */
  style_t* default_style;
  /**
   * @property {widget_state_style_t*} styles
   * @annotation ["private"]
   * 控件在不同状态下的style。
   */
  widget_state_style_t* styles;
} style_mutable_t;

/**
 * @method style_mutable_get_name
 * 获取style的名称。
 * @annotation ["scriptable"]
 * @param {style_t*} s style对象。
 *
 * @return {const char*} style的名称。
 */
const char* style_mutable_get_name(style_t* s);

/**
 * @method style_mutable_set_name
 * 设置style的名称。
 * @annotation ["scriptable"]
 * @param {style_t*} s style对象。
 * @param {const char*} name 名称。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t style_mutable_set_name(style_t* s, const char* name);

/**
 * @method style_mutable_set_int
 * 设置指定id整数格式的值。
 * @annotation ["scriptable"]
 * @param {style_t*} s style对象。
 * @param {widget_state_t} state 控件状态。
 * @param {style_id_t} id 属性ID。
 * @param {int32_t} val 值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t style_mutable_set_int(style_t* s, widget_state_t state, style_id_t id, uint32_t val);

/**
 * @method style_mutable_set_color
 * 设置指定id的颜色值。
 * @param {style_t*} s style对象。
 * @param {widget_state_t} state 控件状态。
 * @param {style_id_t} id 属性ID。
 * @param {color_t} val 值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t style_mutable_set_color(style_t* s, widget_state_t state, style_id_t id, color_t val);

/**
 * @method style_mutable_set_str
 * 设置指定id字符串的值。
 * @param {style_t*} s style对象。
 * @param {widget_state_t} state 控件状态。
 * @param {style_id_t} id 属性ID。
 * @param {const char*} val 值。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t style_mutable_set_str(style_t* s, widget_state_t state, style_id_t id, const char* val);

/**
 * @method style_mutable_foreach
 * 遍历。对每项调用回调函数on_style_item。
 * @param {style_t*} s style对象。
 * @param {tk_on_style_item_t} on_style_item 回调函数。
 * @param {void*} ctx 回调函数的上下文。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t style_mutable_foreach(style_t* s, tk_on_style_item_t on_style_item, void* ctx);

/**
 * @method style_mutable_create
 * 创建style_mutable对象。除了测试程序外不需要直接调用，widget会通过style_factory_create创建。
 * @annotation ["constructor", "scriptable"]
 * @param {widget_t*} widget 控件
 *
 * @return {style_t*} style对象。
 */
style_t* style_mutable_create(widget_t* widget);

/**
 * @method style_mutable_register
 * 将自己注册到style_factory。
 *
 * @return {ret_t} 返回RET_OK表示成功，否则表示失败。
 */
ret_t style_mutable_register(void);

END_C_DECLS

#endif /*TK_STYLE_MUTABLE_H*/

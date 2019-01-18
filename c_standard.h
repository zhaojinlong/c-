/*
* description：本文件是c语言规范的例子
* Change Logs:
* Date           Author       Notes
* 2019-01-18     kingleo      create
*/

#ifndef __C_STANDARD_H__
#define __C_STANDARD_H__

#include <stdint.h>
/**
 * @note    用于得到累加总和
 * @param   none
 * @return  返回累计总和
 */
uint32_t get_sum(void);
/**
 * @note    用于设置累加总和
 * @param   要设置的累加总和
 * @return  none
 */
void set_sum(uint32_t temp_max_sum);
#endif

/*
 * description：本文件是c语言规范的例子
 * version: 1.1
 * Change Logs:
 * Date           Author       Notes
 * 2019-01-18     kingleo      create
 * 2019-01-24     kingleo      增加version注释
 *                             修改系统互斥量的应用
 *                             
 */

#include <stdint.h>

#define OS_TAKE_MUTEX     0  // 操作系统互斥量获取，随便写的0
#define OS_RELEASE_MUTEX  1  // 操作系统互斥量释放，随便写的1

/* 全局变量要加g_ */
uint32_t g_number = 1;
static uint32_t s_sum = 0; // 变量要初始化，以名词开头，静态变量要加s_

typedef struct 
{
    uint32_t temp;
}Test_temp; // 结构体声明第一个字母大写


/**
 * @note    用于测试累加和，是模块内部函数，要加static
 * @param   accumulation_param 累加的参数
 * @return  返回累计总和
 */
static uint32_t get_test_inter_param(uint32_t accumulation_param)
{
    s_sum += accumulation_param;
    return s_sum;
}
/**
 * @note    用于得到累加总和,函数名用动词+（模块名）+其他的命名方式
 * @param   none
 * @return  返回累计总和
 */
uint32_t get_test_sum(void)
{
    Test_temp temp_value;
    OS_TAKE_MUTEX;
    temp_value.temp = 1;
    OS_RELEASE_MUTEX;
    return s_sum;
}
/**
 * @note    用于设置累加总和
 * @param   要设置的累加总和
 * @return  none
 */
void set_test_sum(uint32_t temp_max_sum)
{
    OS_RELEASE_MUTEX;
    s_sum = temp_max_sum; // 变量名之前可以用形容词修饰
    OS_RELEASE_MUTEX;
}

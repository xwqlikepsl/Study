/*
 * @Descripttion: 
 * @version: 
 * @Author: smile
 * @Date: 2025-03-09 22:05:29
 * @LastEditors: smile
 * @LastEditTime: 2025-03-11 14:57:10
 */
#ifndef __TINYOS_H
#define __TINYOS_H
#include <stdint.h>

typedef  uint32_t tTaskStack;

typedef struct _tTask {
	tTaskStack* stack;
}tTask;

extern tTask * curTask;
extern tTask * nextTask;

void tTaskSwitch(void);
void tTaskRunFirst(void);
#endif
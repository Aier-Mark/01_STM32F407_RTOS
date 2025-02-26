/*
 * FreeRTOS V202212.01
 * Copyright (C) 2020 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * https://www.FreeRTOS.org
 * https://github.com/FreeRTOS
 *
 */

#ifndef FREERTOS_CONFIG_H
#define FREERTOS_CONFIG_H

/*-----------------------------------------------------------
 * Application specific definitions.
 *
 * These definitions should be adjusted for your particular hardware and
 * application requirements.
 *
 * THESE PARAMETERS ARE DESCRIBED WITHIN THE 'CONFIGURATION' SECTION OF THE
 * FreeRTOS API DOCUMENTATION AVAILABLE ON THE FreeRTOS.org WEB SITE.
 *
 * See http://www.freertos.org/a00110.html
 *----------------------------------------------------------*/

/* 头文件 */
#include "./SYSTEM/sys/sys.h"
#include "./SYSTEM/usart/usart.h"

/* Ensure stdint is only used by the compiler, and not the assembler. */
#if defined(__ICCARM__) || defined(__CC_ARM) || defined(__GNUC__)
#include <stdint.h>
extern uint32_t SystemCoreClock;
#endif

/* 基础配置项 */
#define configUSE_PREEMPTION 1                    /* 1: 抢占式调度器, 0: 协程式调度器, 无默认需定义 */
#define configUSE_PORT_OPTIMISED_TASK_SELECTION 1 /* 1: 使用硬件计算下一个要运行的任务, 0: 使用软件算法计算下一个要运行的任务, 默认: 0 */
#define configUSE_TICKLESS_IDLE 0                 /* 1: 使能tickless低功耗模式, 默认: 0 */
#define configCPU_CLOCK_HZ (SystemCoreClock)      /* 定义CPU主频, 单位: Hz, 无默认需定义 */
// #define configSYSTICK_CLOCK_HZ (configCPU_CLOCK_HZ / 8) /* 定义SysTick时钟频率，当SysTick时钟频率与内核时钟频率不同时才可以定义, 单位: Hz, 默认: 不定义 */
#define configTICK_RATE_HZ ((TickType_t)1000)          /* 定义系统时钟节拍频率, 单位: Hz, 无默认需定义 */
#define configMAX_PRIORITIES (32)                      /* 定义最大优先级数, 最大优先级=configMAX_PRIORITIES-1, 无默认需定义 */
#define configMINIMAL_STACK_SIZE ((unsigned short)128) /* 定义空闲任务的栈空间大小, 单位: Word, 无默认需定义 */
#define configMAX_TASK_NAME_LEN (16)                   /* 定义任务名最大字符数, 默认: 16 */
#define configUSE_16_BIT_TICKS 0                       /* 1: 定义系统时钟节拍计数器的数据类型为16位无符号数, \
                                                          0: 定义系统时钟节拍计数器的数据类型为32位无符号数, 无默认需定义 */
#define configIDLE_SHOULD_YIELD 1                      /* 1: 使能在抢占式调度下,同优先级的任务能抢占空闲任务, 默认: 1 */
#define configUSE_TASK_NOTIFICATIONS 1                 /* 1: 使能任务间直接的消息传递,包括信号量、事件标志组和消息邮箱, 默认: 1 */
#define configTASK_NOTIFICATION_ARRAY_ENTRIES 1        /* 定义任务通知数组的大小, 默认: 1 */
#define configUSE_MUTEXES 1                            /* 1: 使能互斥信号量, 默认: 0 */
#define configUSE_RECURSIVE_MUTEXES 1                  /* 1: 使能递归互斥信号量, 默认: 0 */
#define configUSE_COUNTING_SEMAPHORES 1                /* 1: 使能计数信号量, 默认: 0 */
#define configUSE_ALTERNATIVE_API 0                    /* 已弃用!!! */
#define configQUEUE_REGISTRY_SIZE 8                    /* 定义可以注册的信号量和消息队列的个数, 默认: 0 */
#define configUSE_QUEUE_SETS 1                         /* 1: 使能队列集, 默认: 0 */
#define configUSE_TIME_SLICING 1                       /* 1: 使能时间片调度, 默认: 1 */
#define configUSE_NEWLIB_REENTRANT 0                   /* 1: 任务创建时分配Newlib的重入结构体, 默认: 0 */
#define configENABLE_BACKWARD_COMPATIBILITY 0          /* 1: 使能兼容老版本, 默认: 1 */
#define configNUM_THREAD_LOCAL_STORAGE_POINTERS 0      /* 定义线程本地存储指针的个数, 默认: 0 */
#define configSTACK_DEPTH_TYPE uint16_t                /* 定义任务堆栈深度的数据类型, 默认: uint16_t */
#define configMESSAGE_BUFFER_LENGTH_TYPE size_t        /* 定义消息缓冲区中消息长度的数据类型, 默认: size_t */

/* 内存分配相关定义 */
#define configSUPPORT_STATIC_ALLOCATION 0           /* 1: 支持静态申请内存, 默认: 0 */
#define configSUPPORT_DYNAMIC_ALLOCATION 1          /* 1: 支持动态申请内存, 默认: 1 */
#define configTOTAL_HEAP_SIZE ((size_t)(10 * 1024)) /* FreeRTOS堆中可用的RAM总量, 单位: Byte, 无默认需定义 */
#define configAPPLICATION_ALLOCATED_HEAP 0          /* 1: 用户手动分配FreeRTOS内存堆(ucHeap), 默认: 0 */
#define configSTACK_ALLOCATION_FROM_SEPARATE_HEAP 0 /* 1: 用户自行实现任务创建时使用的内存申请与释放函数, 默认: 0 */

/* 钩子函数相关定义 */
#define configUSE_IDLE_HOOK 0                /* 1: 使能空闲任务钩子函数, 无默认需定义  */
#define configUSE_TICK_HOOK 0                /* 1: 使能系统时钟节拍中断钩子函数, 无默认需定义 */
#define configCHECK_FOR_STACK_OVERFLOW 0     /* 1: 使能栈溢出检测方法1, 2: 使能栈溢出检测方法2, 默认: 0 */
#define configUSE_MALLOC_FAILED_HOOK 0       /* 1: 使能动态内存申请失败钩子函数, 默认: 0 */
#define configUSE_DAEMON_TASK_STARTUP_HOOK 0 /* 1: 使能定时器服务任务首次执行前的钩子函数, 默认: 0 */

/* 运行时间和任务状态统计相关定义 */
#define configGENERATE_RUN_TIME_STATS 0 /* 1: 使能任务运行时间统计功能, 默认: 0 */
#if configGENERATE_RUN_TIME_STATS
#include "btim.h"
#define portCONFIGURE_TIMER_FOR_RUN_TIME_STATS() ConfigureTimeForRunTimeStats()
extern uint32_t FreeRTOSRunTimeTicks;
#define portGET_RUN_TIME_COUNTER_VALUE() FreeRTOSRunTimeTicks
#endif
#define configUSE_TRACE_FACILITY 1             /* 1: 使能可视化跟踪调试, 默认: 0 */
#define configUSE_STATS_FORMATTING_FUNCTIONS 1 /* 1: configUSE_TRACE_FACILITY为1时，会编译vTaskList()和vTaskGetRunTimeStats()函数, 默认: 0 */

#define configUSE_APPLICATION_TASK_TAG 0 /* 1: 在构建中包含任务标记功能及其相关API, 默认: 0 */

/* 协程相关定义 */
#define configUSE_CO_ROUTINES 0           /* 1: 启用协程, 默认: 0 */
#define configMAX_CO_ROUTINE_PRIORITIES 2 /* 定义协程的最大优先级, 最大优先级=configMAX_CO_ROUTINE_PRIORITIES-1, 无默认configUSE_CO_ROUTINES为1时需定义 */

/* 软件定时器相关定义 */
#define configUSE_TIMERS 1                                          /* 1: 使能软件定时器, 默认: 0 */
#define configTIMER_TASK_PRIORITY (configMAX_PRIORITIES - 1)        /* 定义软件定时器任务的优先级, 无默认configUSE_TIMERS为1时需定义 */
#define configTIMER_QUEUE_LENGTH 5                                  /* 定义软件定时器命令队列的长度, 无默认configUSE_TIMERS为1时需定义 */
#define configTIMER_TASK_STACK_DEPTH (configMINIMAL_STACK_SIZE * 2) /* 定义软件定时器任务的栈空间大小, 无默认configUSE_TIMERS为1时需定义 */

/* 可选函数, 1: 使能 */
#define INCLUDE_vTaskPrioritySet 1            /* 设置任务优先级 */
#define INCLUDE_uxTaskPriorityGet 1           /* 获取任务优先级 */
#define INCLUDE_vTaskDelete 1                 /* 删除任务 */
#define INCLUDE_vTaskSuspend 1                /* 挂起任务 */
#define INCLUDE_xResumeFromISR 1              /* 恢复在中断中挂起的任务 */
#define INCLUDE_vTaskDelayUntil 1             /* 任务绝对延时 */
#define INCLUDE_vTaskDelay 1                  /* 任务延时 */
#define INCLUDE_xTaskGetSchedulerState 1      /* 获取任务调度器状态 */
#define INCLUDE_xTaskGetCurrentTaskHandle 1   /* 获取当前任务的任务句柄 */
#define INCLUDE_uxTaskGetStackHighWaterMark 1 /* 获取任务堆栈历史剩余最小值 */
#define INCLUDE_xTaskGetIdleTaskHandle 1      /* 获取空闲任务的任务句柄 */
#define INCLUDE_eTaskGetState 1               /* 获取任务状态 */
#define INCLUDE_xEventGroupSetBitFromISR 1    /* 在中断中设置事件标志位 */
#define INCLUDE_xTimerPendFunctionCall 1      /* 将函数的执行挂到定时器服务任务 */
#define INCLUDE_xTaskAbortDelay 1             /* 中断任务延时 */
#define INCLUDE_xTaskGetHandle 1              /* 通过任务名获取任务句柄 */
#define INCLUDE_xTaskResumeFromISR 1          /* 恢复在中断中挂起的任务 */

/* 中断嵌套行为配置 */
#ifdef __NVIC_PRIO_BITS
/* __BVIC_PRIO_BITS will be specified when CMSIS is being used. */
#define configPRIO_BITS __NVIC_PRIO_BITS
#else
#define configPRIO_BITS 4 /* 15 priority levels */
#endif

/* 中断最低优先级 */
#define configLIBRARY_LOWEST_INTERRUPT_PRIORITY 15

/* FreeRTOS可管理的最高中断优先级 (高优先级是较低的数值) */
#define configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY 5

/* Interrupt priorities used by the kernel port layer itself.  These are generic
to all Cortex-M ports, and do not rely on any particular library functions. */
#define configKERNEL_INTERRUPT_PRIORITY (configLIBRARY_LOWEST_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
/* !!!! configMAX_SYSCALL_INTERRUPT_PRIORITY must not be set to zero !!!!
See http://www.FreeRTOS.org/RTOS-Cortex-M3-M4.html. */
#define configMAX_SYSCALL_INTERRUPT_PRIORITY (configLIBRARY_MAX_SYSCALL_INTERRUPT_PRIORITY << (8 - configPRIO_BITS))
#define configMAX_API_CALL_INTERRUPT_PRIORITY configMAX_SYSCALL_INTERRUPT_PRIORITY

/* FreeRTOS MPU 特殊定义 */
// #define configINCLUDE_APPLICATION_DEFINED_PRIVILEGED_FUNCTIONS 0
// #define configTOTAL_MPU_REGIONS                                8
// #define configTEX_S_C_B_FLASH                                  0x07UL
// #define configTEX_S_C_B_SRAM                                   0x07UL
// #define configENFORCE_SYSTEM_CALLS_FROM_KERNEL_ONLY            1
// #define configALLOW_UNPRIVILEGED_CRITICAL_SECTIONS             1

/* ARMv8-M 安全侧端口相关定义。 */
// #define secureconfigMAX_SECURE_CONTEXTS         5

#if 0
/* 正常的assert()语义，不依赖于assert.h头文件的提供 */
#define configASSERT(x)           \
    if ((x) == 0)                 \
    {                             \
        taskDISABLE_INTERRUPTS(); \
        for (;;)                  \
            ;                     \
    }
#else
/* 断言 */
#define vAssertCalled(char, int) printf("Error: %s, %d\r\n", char, int)
#define configASSERT(x) \
    if ((x) == 0)       \
    vAssertCalled(__FILE__, __LINE__)
#endif

#if SYS_SUPPORT_OS
/* FreeRTOS中断服务函数相关定义 */
#define vPortSVCHandler SVC_Handler
#define xPortPendSVHandler PendSV_Handler
// #define xPortSysTickHandler SysTick_Handler
#endif

#endif /* FREERTOS_CONFIG_H */
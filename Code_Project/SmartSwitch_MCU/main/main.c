#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"
#include "freertos/queue.h"
#include "driver/gpio.h"

#define MOTOR_PIN_FORWARD GPIO_NUM_14
#define MOTOR_PIN_REVERSE GPIO_NUM_12
#define GPIO_OUTPUT_PIN_SEL  ((1ULL<<MOTOR_PIN_FORWARD) | (1ULL<<MOTOR_PIN_REVERSE))

void app_main(void)
{
 // GPIO 配置结构体
    gpio_config_t io_conf;
    // 禁用中断
    io_conf.intr_type = GPIO_INTR_DISABLE;
    // 设置为输出模式
    io_conf.mode = GPIO_MODE_OUTPUT;
    // 选择哪些管脚作为输出管脚
    io_conf.pin_bit_mask = GPIO_OUTPUT_PIN_SEL;
    // 禁用下拉
    io_conf.pull_down_en = 0;
    // 禁用上拉
    io_conf.pull_up_en = 0;
    // 使用以上设置配置 GPIO
    gpio_config(&io_conf);

    // 循环，模拟电机控制
    while (1) {
        // 启动电机：将 GPIO_MOTOR_START 管脚设为高电平
        gpio_set_level(MOTOR_PIN_FORWARD, 1);
        // 停止电机：将 GPIO_MOTOR_STOP 管脚设为低电平
        gpio_set_level(MOTOR_PIN_REVERSE, 0);
        printf("Motor started\n");
        
        // 延时一段时间，保持电机运行
        vTaskDelay(5000 / portTICK_PERIOD_MS);

        // 停止电机：将 GPIO_MOTOR_START 管脚设为低电平
        gpio_set_level(MOTOR_PIN_FORWARD, 0);
        // 启动电机：将 GPIO_MOTOR_STOP 管脚设为高电平
        gpio_set_level(MOTOR_PIN_REVERSE, 1);
        printf("Motor stopped\n");
        
        // 延时一段时间，保持电机停止状态
        vTaskDelay(5000 / portTICK_PERIOD_MS);
    }

}

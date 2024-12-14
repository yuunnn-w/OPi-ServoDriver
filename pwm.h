// pwm.h
#ifndef PWM_H
#define PWM_H

#ifdef __cplusplus
extern "C" {
#endif

#include <wiringPi.h> //这个是C的库

#ifdef __cplusplus
}  // extern "C"
#endif

#include <iostream>
#include <cstdlib>
#include <cstdint>

// 定义舵机类
class PWMServo {
public:
    PWMServo(int pin); // 构造函数：初始化舵机对象

    void init(); // 初始化舵机
    void gotoAngle(int angle, int wait_us = 1000); // 转到指定角度，并指定等待时间（微秒为单位）
    void setAngleRange(int min_angle, int max_angle); // 设置舵机的最小和最大角度范围
    int getCurrentAngle() const; // 获取当前舵机的角度

private:
    int calculateCCR(int angle) const; // 计算 CCR 值的函数
    void setPWMInfo(); // 设置 PWM 信息的函数
    int pin_; // 舵机引脚编号
    int min_angle_; // 舵机的最小和最大角度范围
    int max_angle_;
    int current_angle_; // 当前舵机的角度

    // PWM 参数
    struct PWMInfo {
        unsigned int ccr;
        unsigned int arr;
        unsigned int div;
        unsigned int div_stepping;
    } pwm_info_;
};

#endif // PWM_H


#include "pwm.h"

// 构造函数：初始化舵机对象
PWMServo::PWMServo(int pin) : pin_(pin), min_angle_(0), max_angle_(180), current_angle_(0) {
    // 默认角度范围为 0 到 180 度
}

// 初始化舵机
void PWMServo::init() {
    wiringPiSetup(); // 初始化 WiringPi
    setPWMInfo(); // 设置 PWM 信息
    pinMode(pin_, PWM_OUTPUT); // 设置引脚模式为 PWM 输出

    // 设置 PWM 参数
    pwmSetRange(pin_, pwm_info_.arr);
    pwmSetClock(pin_, pwm_info_.div);
    std::cout << "PWMServo initialized on pin " << pin_ << std::endl;
}

// 转到指定角度，并指定等待时间（微秒为单位）
void PWMServo::gotoAngle(int angle, int wait_us) {
    // 检查角度是否在有效范围内
    if (angle < min_angle_ || angle > max_angle_) {
        std::cerr << "Angle must be between " << min_angle_ << " and " << max_angle_ << "." << std::endl;
        return;
    }
    int ccr_value = calculateCCR(angle); // 计算 CCR 值
    pwmWrite(pin_, ccr_value); // 写入 CCR 值到 PWM 输出
    current_angle_ = angle; // 更新当前角度
    delayMicroseconds(wait_us); // 等待指定时间（微秒）
}

// 设置舵机的最小和最大角度范围
void PWMServo::setAngleRange(int min_angle, int max_angle) {
    if (min_angle >= max_angle) {
        std::cerr << "Invalid angle range: min_angle must be less than max_angle." << std::endl;
        return;
    }

    min_angle_ = min_angle;
    max_angle_ = max_angle;
}

// 获取当前舵机的角度
int PWMServo::getCurrentAngle() const {
    return current_angle_;
}

// 计算 CCR 值的函数
int PWMServo::calculateCCR(int angle) const {
    // 线性映射角度到 CCR 值
    return 1500 + (angle * (7500 - 1500) / 180);
}

// 设置 PWM 信息的函数
void PWMServo::setPWMInfo() {
    int model;
    piBoardId(&model); // 获取树莓派型号

    // 默认 PWM 参数
    pwm_info_.ccr = 4500;  // 1.5ms 脉冲（90度）
    pwm_info_.arr = 60000; // 20ms 周期
    pwm_info_.div = 8;     // 时钟分频
    pwm_info_.div_stepping = 1; // 步进值

    // 根据香橙派型号验证 PWM 引脚是否设置准确
    switch (model) {
    case PI_MODEL_5_MAX:
        if (pin_ != 0 && pin_ != 1 && pin_ != 2 && pin_ != 8 && pin_ != 9 && pin_ != 17 && pin_ != 20 && pin_ != 21 && pin_ != 22 && pin_ != 23) {
            std::cerr << "The pin you choose doesn't support hardware PWM" << std::endl;
            exit(1);
        }
        break;
    case PI_MODEL_3B:
        if (pin_ != 2 && pin_ != 21) {
            std::cerr << "The pin you choose doesn't support hardware PWM" << std::endl;
            exit(1);
        }
        break;
    default:
        std::cout << "Oops - unable to determine board type..." << std::endl;
        exit(1);
    }
}
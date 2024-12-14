#include "pwm.h"

int main() {
    // 创建舵机对象，指定引脚编号
    PWMServo servo(21);  // OrangePi 3B的21号引脚
    // 初始化舵机
    servo.init();
    // 设置舵机的角度范围
    servo.setAngleRange(0, 180);


    servo.gotoAngle(210, 1000);
    // 控制舵机从 0 度扫描到 180 度，再从 180 度扫描回 0 度
    while (true) {
        for (int angle = 0; angle <= 180; angle++) {
            servo.gotoAngle(angle, 1000); // 转到指定角度，等待 1000us (1ms)
        }

        for (int angle = 180; angle >= 0; angle--) {
            servo.gotoAngle(angle, 1000); // 转到指定角度，等待 1000us (1ms)
        }
    }
    return 0;
}
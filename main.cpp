#include "pwm.h"

int main() {
    // �����������ָ�����ű��
    PWMServo servo(21);  // OrangePi 3B��21������
    // ��ʼ�����
    servo.init();
    // ���ö���ĽǶȷ�Χ
    servo.setAngleRange(0, 180);


    servo.gotoAngle(210, 1000);
    // ���ƶ���� 0 ��ɨ�赽 180 �ȣ��ٴ� 180 ��ɨ��� 0 ��
    while (true) {
        for (int angle = 0; angle <= 180; angle++) {
            servo.gotoAngle(angle, 1000); // ת��ָ���Ƕȣ��ȴ� 1000us (1ms)
        }

        for (int angle = 180; angle >= 0; angle--) {
            servo.gotoAngle(angle, 1000); // ת��ָ���Ƕȣ��ȴ� 1000us (1ms)
        }
    }
    return 0;
}
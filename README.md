# OPi-ServoDriver

[![License: AGPL v3](https://img.shields.io/badge/License-AGPL_v3-blue.svg)](https://www.gnu.org/licenses/agpl-3.0)

---

## Introduction

OPi-ServoDriver is a lightweight library designed for controlling PWM servos on Orange Pi. It provides precise angle control with microsecond-level timing and hardware PWM support, making it ideal for robotics and automation projects. This library is compatible with Orange Pi and leverages the WiringPi-compatible interface for efficient servo control.

OPi-ServoDriver 是一个轻量级库，专为在 Orange Pi 上控制 PWM 舵机而设计。它提供微秒级别的精确角度控制和硬件 PWM 支持，非常适合机器人和自动化项目。该库兼容 Orange Pi，并利用兼容 WiringPi 的接口实现高效的舵机控制。

---

## Features

- **Precise Angle Control**: Supports microsecond-level timing for accurate servo positioning.
- **Hardware PWM Support**: Utilizes hardware PWM for stable and efficient control.
- **Easy to Use**: Simple API for initializing servos, setting angles, and controlling movement.
- **Customizable Angle Range**: Allows users to define the minimum and maximum angles for each servo.
- **Cross-Platform**: Designed specifically for Orange Pi, but can be adapted for other WiringPi-compatible platforms.
---
- **精确角度控制**：支持微秒级别的定时，实现精确的舵机定位。
- **硬件 PWM 支持**：利用硬件 PWM 实现稳定且高效的控制。
- **易于使用**：简单的 API，用于初始化舵机、设置角度和控制运动。
- **自定义角度范围**：允许用户为每个舵机定义最小和最大角度。
- **跨平台兼容**：专为 Orange Pi 设计，但可以适应其他支持 WiringPi 的平台。

---

## Project Structure

The project is organized as follows:

- **CMakeLists.txt**: CMake configuration file for building the project.
- **main.cpp**: Example usage of the `PWMServo` class.
- **pwm.c**: Original example from the [wiringOP](https://github.com/orangepi-xunlong/wiringOP/blob/next/examples/pwm.c) repository.
- **pwm.h**: Header file for the `PWMServo` class.
- **pwm.cpp**: Implementation of the `PWMServo` class.
- **CMakePresets.json**: CMake presets for configuring the build environment.

---

## Usage

### Prerequisites

Before building and running the OPi-ServoDriver project, ensure that the following prerequisites are met:

#### Software Requirements

1. **CMake**: Version 3.10 or higher is required for building the project. You can install it using the following command:

     ```bash
     sudo apt-get install cmake
     ```

3. **GCC/G++**: A C++ compiler that supports C++11 or later is required. GCC/G++ is typically pre-installed on most Linux distributions.

     ```bash
     sudo apt-get install build-essential
     ```

5. **WiringPi**: The project relies on the WiringPi library for GPIO and PWM control. Ensure that WiringPi is installed on your Orange Pi.
   - **Installation**:
     ```bash
     wget https://github.com/orangepi-xunlong/orangepi-build/blob/next/external/cache/debs/arm64/wiringpi_2.57.deb
     dpkg -i wiringpi_2.57.deb
     ```

#### Hardware Requirements

1. **Orange Pi**: The project is designed for Orange Pi boards. Ensure that your Orange Pi is properly set up and connected to the servos.
2. **Servo Motors**: PWM-compatible servos that can be controlled via GPIO pins.

#### Additional Notes

- **Root Privileges**: Some operations, such as GPIO access, may require root privileges. Ensure that you run the application with `sudo` if necessary.
- **Pin Configuration**: Verify the pin configuration for your specific Orange Pi model. The example uses pin 21, but this may vary depending on your board.

By ensuring these prerequisites are met, you can successfully build and run the OPi-ServoDriver project.

### Example

```cpp
#include "pwm.h"

int main() {
    // Create a servo object on pin 21 (OrangePi 3B)
    PWMServo servo(21);

    // Initialize the servo
    servo.init();

    // Set the angle range (0 to 180 degrees)
    servo.setAngleRange(0, 180);

    // Move the servo to 210 degrees (out of range, will be clamped to 180)
    servo.gotoAngle(210, 1000);

    // Scan from 0 to 180 degrees and back
    while (true) {
        for (int angle = 0; angle <= 180; angle++) {
            servo.gotoAngle(angle, 1000); // Move to angle with 1000us delay
        }

        for (int angle = 180; angle >= 0; angle--) {
            servo.gotoAngle(angle, 1000); // Move to angle with 1000us delay
        }
    }

    return 0;
}
```

---

## License

This project is licensed under the **AGPL-3.0 License**. See the [LICENSE](LICENSE) file for more details.

---

## Acknowledgments

- The original `pwm.c` example is from the [wiringOP](https://github.com/orangepi-xunlong/wiringOP/blob/next/examples/pwm.c) repository.
- Special thanks to the Orange Pi and WiringPi communities for their contributions and support.

---

## Contributing

We welcome contributions to OPi-ServoDriver! If you have any improvements, bug fixes, or new features, feel free to open an issue or submit a pull request. Please ensure that your contributions adhere to the project's coding standards and licensing requirements.

---

## Author

If you have any questions or need further assistance, please contact the project maintainers:

- **Maintainer Name**: yuunnn_w
- **Email**: [jiaxinsugar@gmail.com](mailto:jiaxinsugar@gmail.com)
- **GitHub**: [yuunnn-w](https://github.com/yuunnn-w)

---

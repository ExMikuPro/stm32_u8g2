
# STM32_u8g2

This repository contains the STM32 project template for integrating the **u8g2** graphics library with STM32 microcontrollers. The **u8g2** library is used to drive monochrome displays such as OLED and LCD. This project demonstrates how to use the library on STM32 and supports data transfer through both SPI and I2C communication interfaces.

## Features

- **u8g2 Library Integration**: Full integration of the u8g2 graphics library into the STM32 project.
- **Hardware SPI and I2C Support**: Select SPI or I2C communication based on defined macros.
- **Flexible Display Interface**: Easily switch between SPI or I2C communication interfaces as needed.

## Supported Platforms

- STM32F0xx Series (e.g., STM32F030, STM32F070)
- STM32F1xx Series (e.g., STM32F103)
- STM32F4xx Series (e.g., STM32F401, STM32F407)
- STM32F7xx Series (e.g., STM32F746)
- STM32H7xx Series (e.g., STM32H743)

## Prerequisites

- **STM32CubeMX**: Used for peripheral configuration.
- **STM32 HAL Libraries**: For driving STM32 microcontroller peripherals (SPI, I2C, GPIO).
- **u8g2 Library**: Added as a Git submodule.

## Getting Started

### 1. Clone the Repository

Clone this repository to your local machine:

```bash
git clone https://github.com/ExMikuPro/stm32_u8g2.git
cd stm32_u8g2
```

### 2. Change MCU Model
When changing the MCU model in STM32CubeMX, follow these steps:

#### 2.1 Move `u8g2_user_port.h` and `u8g2_user_port.c`
After selecting the new MCU model in STM32CubeMX, manually move the following files to the new `Core` directory:

- `Core/Inc/u8g2_user_port.h`
- `Core/Src/u8g2_user_port.c`
- `Drivers/U8G2` directory

#### 2.2 Update `CMakeLists.txt`
In the new MCU configuration, update the `CMakeLists.txt` file to ensure that u8g2 library source files are properly included.

Add the following code before `include_directories(${includes})` in `CMakeLists_template.txt`:

```cmake
# u8g2 begin
include_directories(Drivers/U8G2/csrc)
include_directories(Drivers/U8G2)
include_directories(Core/Inc)

file(GLOB_RECURSE U8G2_SOURCES
        Drivers/U8G2/csrc/*.c
        Drivers/U8G2/u8g2_port.c
)

list(APPEND sources ${U8G2_SOURCES})
# u8g2 end
```

#### 2.3 Change MCU Model in STM32CubeMX
Open STM32CubeMX and select the new MCU model.

Check the peripheral configuration (such as SPI, I2C) according to the new MCU model.

Generate the new code.

### 3. Build and Upload the Project
After generating the code, compile and upload the project via STM32CubeIDE or CLion. Ensure that the new MCU model matches the configuration and verify that the hardware connections are correct.

## Code Structure

- **Core/**: Contains the main application logic and initialization code.
    - **u8g2_user_port.c**: User-defined SPI/I2C communication interface.
- **Drivers/**: Contains peripheral drivers and u8g2 integration code.
- **Inc/**: Contains project configuration header files.
    - **u8g2_user_port.h**: User-defined header file.
- **STM32CubeMX/**: CubeMX configuration files.

## Common Issues

- **Error: u8g2port.h not found**: Ensure that the correct communication interface (SPI/I2C) is defined in `u8g2_user_port.h` and that the hardware is correctly configured in STM32CubeMX.

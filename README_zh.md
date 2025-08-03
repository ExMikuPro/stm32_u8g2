
# STM32_u8g2

本仓库包含了将 **u8g2** 图形库集成到 STM32 微控制器的工程模板。**u8g2** 库用于驱动单色显示屏（如 OLED、LCD）。此项目展示了如何在 STM32 上使用该库，并支持通过 SPI 和 I2C 两种通信接口进行数据传输。

## 特性

- **u8g2 库集成**：将 u8g2 图形库完整集成到 STM32 项目中。
- **硬件 SPI 和 I2C 支持**：根据定义的宏选择 SPI 或 I2C 进行通信。
- **灵活的显示接口**：根据需要轻松切换 SPI 或 I2C 通信接口。

## 支持的平台

- STM32F0xx 系列（例如：STM32F030、STM32F070）
- STM32F1xx 系列（例如：STM32F103）
- STM32F4xx 系列（例如：STM32F401、STM32F407）
- STM32F7xx 系列（例如：STM32F746）
- STM32H7xx 系列（例如：STM32H743）

## 前提条件

- **STM32CubeMX**：用于外设配置。
- **STM32 HAL 库**：驱动 STM32 微控制器的外设（SPI、I2C、GPIO）。
- **u8g2 库**：通过 Git 子模块添加 u8g2 库。

## 开始使用

### 1. 克隆仓库

将此仓库克隆到本地机器：

```bash
git clone https://github.com/ExMikuPro/stm32_u8g2.git
cd stm32_u8g2
```

### 2. 更换 MCU 型号
使用 STM32CubeMX 更换 MCU 型号时，需要以下步骤：

#### 2.1 移动 `u8g2_user_port.h` 和 `u8g2_user_port.c`
在 STM32CubeMX 中选择新的 MCU 型号后，需要手动将以下文件移到新的 `Core` 目录：

- `Core/Inc/u8g2_user_port.h`
- `Core/Src/u8g2_user_port.c`
- `Drivers/U8G2` 目录

#### 2.2 更新 `CMakeLists.txt`
在新的 MCU 配置中，更新 `CMakeLists.txt` 文件，确保 u8g2 库源文件被正确包含。

在 `CMakeLists_template.txt` 中 **`include_directories(${includes})`** 之前添加以下代码：

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

#### 2.3 在 STM32CubeMX 中更换 MCU 型号
打开 STM32CubeMX，选择新的 MCU 型号。

根据新的 MCU 型号检查外设配置（如 SPI、I2C）。

生成新的代码。

### 3. 构建并上传项目
生成代码后，通过 STM32CubeIDE 或 CLion 编译并上传项目。确保新的 MCU 型号与配置匹配，并验证硬件连接是否正确。

## 代码结构

- **Core/**: 包含主应用程序逻辑和初始化代码。
    - **u8g2_user_port.c**: 用户定义的 SPI/I2C 通信接口。
- **Drivers/**: 包含外设驱动和 u8g2 集成代码。
- **Inc/**: 包含项目配置头文件。
    - **u8g2_user_port.h**: 用户定义的头文件。
- **STM32CubeMX/**: CubeMX 配置文件。

## 常见问题

- **错误：找不到 u8g2port.h**：确保在 `u8g2_user_port.h` 中定义了正确的通信接口（SPI/I2C），并在 STM32CubeMX 中正确配置了硬件。

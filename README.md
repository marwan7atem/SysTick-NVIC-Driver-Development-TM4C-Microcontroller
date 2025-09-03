# SysTick-NVIC-Driver-Development-TM4C-Microcontroller
Low-level ARM Cortex-M drivers for the TM4C microcontroller. Implements SysTick timer for periodic interrupts and busy-wait delays, and an NVIC driver for interrupt/exception management. Includes priority setting, enabling/disabling, and comprehensive documentation.

# ARM Cortex-M System Drivers: SysTick & NVIC

Low-level drivers for the SysTick timer and Nested Vectored Interrupt Controller (NVIC) on the Texas Instruments TM4C123GH6PM microcontroller (Tiva-C Series). Provides core functionality for precise timing and advanced interrupt management in ARM Cortex-M embedded systems.

## ✨ Features

*   **Precise Timing:** SysTick driver supports both interrupt-based periodic events and polling-based busy-wait delays.
*   **Advanced Interrupt Management:** NVIC driver enables full control over interrupt priorities, enabling, and disabling.
*   **System Exception Handling:** Configure priorities and manage ARM system exceptions (e.g., BusFault, UsageFault, SVCall).
*   **Hardware Abstraction:** Clean, reusable API abstracts the complex register-level operations.
*   **Fully Documented:** Every function includes detailed comments explaining parameters, behavior, and usage.

## 🧰 Hardware Components

*   **Microcontroller:** TM4C123GH6PM (Tiva-C LaunchPad)
*   **System Clock:** 16 MHz

## 🏗️ Software Architecture

The drivers are built following a modular and layered approach for maximum portability.

Application Layer (Test Files)
|
MCAL (Microcontroller Abstraction Layer)
├── SysTick Driver
└── NVIC Driver
|
TM4C123GH6PM Microcontroller Registers

## 📁 Project Structure
ARM_SysTick_NVIC_Drivers/
├── Inc/
│ ├── SysTick.h # SysTick driver interface & config types
│ ├── NVIC.h # NVIC driver interface & config types
│ └── TM4C123GH6PM.h # Device-specific register definitions
├── Src/
│ ├── SysTick.c # SysTick driver implementation
│ └── NVIC.c # NVIC driver implementation
├── Test/
│ ├── main_irq_test.c # Application 1: Tests IRQ & Interrupt SysTick
│ └── main_busy_wait.c # Application 2: Tests Exceptions & Busy-Wait SysTick
└── README.md

## ⚙️ API Overview

### SysTick Driver
| Function | Description |
| :--- | :--- |
| `SysTick_Init(uint16 timeMs)` | Initializes SysTick for periodic interrupts. |
| `SysTick_StartBusyWait(uint16 timeMs)` | Blocks for a precise duration using polling. |
| `SysTick_SetCallback(void (*Ptr2Func)(void))` | Sets the function to call on each interrupt. |
| `SysTick_Start()` / `Stop()` | Starts/Stops the timer. |

### NVIC Driver
| Function | Description |
| :--- | :--- |
| `NVIC_EnableIRQ(NVIC_IRQType IRQ_Num)` | Enables a specific peripheral interrupt. |
| `NVIC_SetPriorityIRQ(...)` | Sets the priority level for an IRQ. |
| `NVIC_EnableException(NVIC_ExceptionType Exception_Num)` | Enables a system exception. |
| `NVIC_SetPriorityException(...)` | Sets the priority for a system exception. |

## 🚀 Getting Started

### Prerequisites
*   **IDE:** [Keil MDK](https://www.keil.com/) or [Code Composer Studio (CCS)](https://www.ti.com/tool/CCSTUDIO).
*   **Target Board:** Tiva-C Series TM4C123G LaunchPad or equivalent.
*   **Toolchain:** ARM-Clang or TI Arm Clang Compiler.

### Building and Flashing
1.  **Clone the repository:**
    ```bash
    git clone https://github.com/marwan7atem/ARM_SysTick_NVIC_Drivers.git
    ```
2.  **Open the Project:** Import the `Inc` and `Src` folders into your IDE project.
3.  **Configure Target:** Ensure the target device is set to `TM4C123GH6PM` and the system clock is configured for 16 MHz.
4.  **Build:** Compile the project without errors.
5.  **Flash:** Load the generated binary onto your target hardware.

### Running the Tests
Two main applications are provided to validate the drivers:
1.  **Interrupt Test (`main_irq_test`):** Demonstrates periodic SysTick interrupts for LED control and NVIC IRQ configuration for a switch.
2.  **Busy-Wait Test (`main_busy_wait`):** Demonstrates SysTick busy-wait functionality and tests system exception configuration with assert macros.

## 👨‍💻 Developer

**Marwan Mohamed Hatem**
*   Email: marwanhatem017@gmail.com
*   LinkedIn: [linkedin.com/in/marwan-hatem-6a516b225](https://linkedin.com/in/marwan-hatem-6a516b225)
*   GitHub: [github.com/marwan7atem](https://github.com/marwan7atem)

## 📄 License
This project was developed as part of the ARM Cortex-M course from **Edges For Training**. The code is provided for educational and reference purposes.


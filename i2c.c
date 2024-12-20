#include <stdio.h>
#include <stdint.h>
#include <string.h>

// 定義 I2C 從機設備結構
typedef struct {
    uint8_t address;
    uint8_t memory[256]; // 模擬 256 字節的內存
} I2C_Device;

// 模擬 I2C 總線的結構
typedef struct {
    I2C_Device *devices[128]; 
} I2C_Bus;

// 初始化 I2C 從機設備
void i2c_device_init(I2C_Device *device, uint8_t address) {
    device->address = address;
    memset(device->memory, 0, sizeof(device->memory));
}

// 將從機設備附加到總線上
void i2c_bus_attach_device(I2C_Bus *bus, I2C_Device \*device) {
    bus->devices[device->address] = device;
}

// 在 I2C 總線上寫入數據
void i2c_write_byte(I2C_Bus *bus, uint8_t address, uint8_t reg, uint8_t value) {
    if (bus->devices[address] != NULL) {
        bus->devices[address]->memory[reg] = value;
        printf("Wrote value %d to address 0x%02X, register 0x%02X.\n", value, address, reg);
    } else {
        printf("No device found at address 0x%02X.\n", address);
    }
}

// 在 I2C 總線上讀取數據
uint8_t i2c_read_byte(I2C_Bus *bus, uint8_t address, uint8_t reg) {
    if (bus->devices[address] != NULL) {
        uint8_t value = bus->devices[address]->memory[reg];
        printf("Read value %d from address 0x%02X, register 0x%02X.\n", value, address, reg);
        return value;
    } else {
        printf("No device found at address 0x%02X.\n", address);
        return 0;
    }
}

int main() {
    // 創建 I2C 總線
    I2C_Bus bus;
    memset(bus.devices, 0, sizeof(bus.devices));

    // 創建 I2C 從機設備
    I2C_Device sensor;
    i2c_device_init(&sensor, 0x50);

    // 將從機設備附加到總線上
    i2c_bus_attach_device(&bus, &sensor);

    // 寫入數據到從機設備
    i2c_write_byte(&bus, 0x50, 0x00, 123);

    // 從從機設備讀取數據
    uint8_t value = i2c_read_byte(&bus, 0x50, 0x00);
    printf("Value read: %d\n", value); // 應該輸出 123

    return 0;
}

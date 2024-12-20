#include <stdint.h>
#include <stdio.h>

#define REG_ADDRESS 0x1000 // 註：0x1000 是假設的內存地址
volatile uint16_t *reg = (volatile uint16_t *)REG_ADDRESS;

void set_device_status(unsigned char status) {
    // 設置低8位，保留高8位
    *reg = (*reg & 0xFF00) | (status & 0x00FF);
}

unsigned char get_device_status(void) {
    // 獲取低8位
    return *reg & 0x00FF;
}

void set_device_control(unsigned char control) {
    // 設置高8位，保留低8位
    *reg = (*reg & 0x00FF) | ((control & 0x00FF) << 8);
}

unsigned char get_device_control(void) {
    // 獲取高8位
    return (*reg >> 8) & 0x00FF;
}

int main() {
    // 測試設置和獲取設備狀態
    set_device_status(0x3C);
    unsigned char status = get_device_status();
    printf("Device Status: 0x%X\n", status);

    // 測試設置和獲取設備控制
    set_device_control(0xAB);
    unsigned char control = get_device_control();
    printf("Device Control: 0x%X\n", control);

    return 0;
}

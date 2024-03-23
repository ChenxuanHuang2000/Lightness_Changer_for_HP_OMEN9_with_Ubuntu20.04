#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <limits>
#include <stdexcept>
#include <sys/stat.h>

const std::string ORIGINAL_PATH = "/sys/class/backlight/nvidia_wmi_ec_backlight/brightness";
const std::string TEMP_FILE_NAME = "brigntness_temp_down.txt";

void adjust_brightness(const std::string& ORIGINAL_PATH) {
    try {
        std::ifstream inFile(ORIGINAL_PATH);
        if (!inFile) {
            std::cerr << "无法打开文件: " << ORIGINAL_PATH << std::endl;
            return;
        }

        // 读取当前亮度值
        int current_brightness;
        inFile >> current_brightness;
        inFile.close();

        // 确保新的亮度值在0-200范围内
        int new_brightness = std::max(current_brightness - 10, 0);

        // 写入新的亮度值
        std::ofstream outFile(ORIGINAL_PATH, std::ios::trunc);
        if (!outFile) {
            std::cerr << "无法打开文件以写入: " << ORIGINAL_PATH << std::endl;
            return;
        }
        outFile << new_brightness;
        outFile.close();
    } catch (const std::exception& e) {
        std::cerr << "异常发生: " << e.what() << std::endl;
    }
}

int main() {
    adjust_brightness(ORIGINAL_PATH);
    return 0;
}
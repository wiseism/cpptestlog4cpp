#include <log4cpp/Category.hh>
#include <log4cpp/PropertyConfigurator.hh>
#include <iostream>

int main() {
    // 初始化 log4cpp 系统
    log4cpp::PropertyConfigurator::configure("log4cpp.properties"); // 使用配置文件配置日志

    // 获取或创建名为 "root" 的日志分类（Category）
    log4cpp::Category& root = log4cpp::Category::getRoot();

    // 设置优先级阈值（可选，因为我们在配置文件中可能已经设置了）
    // root.setPriority(log4cpp::Priority::INFO);

    // 打印 INFO 级别的日志
    root.info("This is an informational message.");

    // 其他日志级别示例
    // root.debug("This is a debug message.");
    // root.warn("This is a warning message.");
    // root.error("This is an error message.");
    // root.fatal("This is a fatal message.");

    return 0;
}
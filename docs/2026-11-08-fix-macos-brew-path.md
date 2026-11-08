# 修复记录：macos log4cpp 头文件路径失败（2026-11-08）

## 失败信息
- 仓库：wiseism/cpptestlog4cpp
- Workflow：main macos
- 失败 run：[41938309491](https://github.com/wiseism/cpptestlog4cpp/actions/runs/41938309491)（2026-11-05）

## 错误日志摘录
```
src/log4cpp_main.cpp:1:10: fatal error: 'log4cpp/Category.hh' file not found
1 error generated.
##[error]Process completed with exit code 2.
```

## 原因分析
`CMakeLists.txt` Darwin 分支硬编码
`/usr/local/Cellar/log4cpp/1.1.3/include|lib`：
- Homebrew 装的版本号目录会变化（不再是 1.1.3）；
- macos-latest 已是 ARM runner，默认前缀为 `/opt/homebrew`。
两个路径都失效，头文件找不到。

## 修复内容
`CMakeLists.txt` Darwin 分支改为 `execute_process(COMMAND brew --prefix log4cpp ...)`
动态获取安装前缀，失败时回退 `/usr/local/opt/log4cpp`。

## 验证
| run id | 结果 |
| --- | --- |
| 本次推送触发 | 待填 |

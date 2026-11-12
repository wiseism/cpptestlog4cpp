# 修复 mac 链接：link_directories 在 add_executable 之后不生效

## 失败信息
- Run 42442953785（main macos）：
  `ld: library 'log4cpp' not found`（链接命令行没有 -L/opt/homebrew/opt/log4cpp/lib）

## 原因分析
- Darwin 分支里 `link_directories()` 调用位于 `add_executable(log4cpp_main)` 之后，
  目录级链接目录属性只影响其后创建的 target，导致链接时找不到 liblog4cpp。
- include 因目录 include 属性仍在生成期被读取而"碰巧"可用，链接则明确失败。

## 修复内容
- 改用 `find_library(LOG4CPP_LIB log4cpp PATHS .../lib REQUIRED)` 得到全路径，
  `target_link_libraries(... ${LOG4CPP_LIB})` 显式链接（与调用顺序无关）。

## 验证记录
| Run | 结果 |
|---|---|
| 42442953785 (修复前) | failure — library not found |
| 43049381921 (main macos, e40e67b) | ✅ success |
| 43049381902 (main ubuntu) | failure — runner DNS 抖动(已加重试)
| 43223748511 (main ubuntu, 4309cfb) | ✅ success |
| 43223748579 (main macos) | ✅ success |

## 补记: ubuntu apt DNS 抖动
- apt update/install 加 3 次重试（runner DNS 瞬时故障导致连续 3 次失败，macos 已 ✅）。

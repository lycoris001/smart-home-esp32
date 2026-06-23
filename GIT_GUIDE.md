# Git 快速入门# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZ# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.p# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.pio/
build/
*.o
*.bin
# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.pio/
build/
*.o
*.bin
*.elf

# IDE 配置
.vscode/
.idea/

# 操作系统垃圾文件# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.pio/
build/
*.o
*.bin
*.elf

# IDE 配置
.vscode/
.idea/

# 操作系统垃圾文件
Thumbs.db
.DS_Store

# 本地配置文件（WiFi密码等，# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.pio/
build/
*.o
*.bin
*.elf

# IDE 配置
.vscode/
.idea/

# 操作系统垃圾文件
Thumbs.db
.DS_Store

# 本地配置文件（WiFi密码等，不要提交到公开仓库）
src/config.local.h# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.pio/
build/
*.o
*.bin
*.elf

# IDE 配置
.vscode/
.idea/

# 操作系统垃圾文件
Thumbs.db
.DS_Store

# 本地配置文件（WiFi密码等，不要提交到公开仓库）
src/config.local.h
```

---

## 场景四：写错了想回退

```bash
# 还没# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.pio/
build/
*.o
*.bin
*.elf

# IDE 配置
.vscode/
.idea/

# 操作系统垃圾文件
Thumbs.db
.DS_Store

# 本地配置文件（WiFi密码等，不要提交到公开仓库）
src/config.local.h
```

---

## 场景四：写错了想回退

```bash
# 还没 git add 的改动，直接丢弃
git checkout -- 文件名

# 已经 git add# Git 快速入门指南

> 适用于本智能家居项目的版本管理操作

---

## 一次性配置（装完 Git 后只做一次）

```bash
# 设置用户名和邮箱（提交时会记录）
git config --global user.name "你的名字"
git config --global user.email "你的邮箱@example.com"

# 查看配置是否生效
git config --global --list
```

---

## 场景一：从零开始创建项目仓库

```bash
# 1. 进入项目目录
cd D:\ZZZpj\smart-home-esp32

# 2. 初始化 Git 仓库
git init

# 3. 添加所有文件到暂存区
git add .

# 4. 第一次提交
git commit -m "初始化项目：智能家居联动控制系统，ESP32-S3主控"

# 5. （可选）关联远程仓库（GitHub/Gitee）
git remote add origin https://github.com/你的用户名/smart-home-esp32.git
git push -u origin master
```

---

## 场景二：日常开发流程

```bash
# 写了一些代码后，看看改了什么
git status

# 查看具体改动内容
git diff

# 添加改动的文件
git add src/sensors/pir_sensor.h

# 或一次性添加所有改动
git add .

# 提交，并写清楚这次做了什么
git commit -m "新增PIR人体红外传感器驱动"

# 推送到远程仓库
git push
```

---

## 场景三：`.gitignore` 忽略不需要版本管理的文件

在项目根目录创建 `.gitignore` 文件，内容如下：

```bash
# 编译产物
.pio/
build/
*.o
*.bin
*.elf

# IDE 配置
.vscode/
.idea/

# 操作系统垃圾文件
Thumbs.db
.DS_Store

# 本地配置文件（WiFi密码等，不要提交到公开仓库）
src/config.local.h
```

---

## 场景四：写错了想回退

```bash
# 还没 git add 的改动，直接丢弃
git checkout -- 文件名

# 已经 git add 了但还没 commit，撤销暂存
git reset HEAD 文件名

# 已经 commit
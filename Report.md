# 2048 Game GUI Version Design Report

## I. Project Overview

This project is a GUI version of the 2048 game implemented using the Qt framework. It comprises the core game logic (GameBoard class) and the graphical user interface (MainWindow class).

- **GameBoard Class:** Encapsulates the core game logic, including functions such as initializing the game board, moving tiles, and merging tiles.

- **MainWindow Class:** Responsible for GUI-related drawing and interactions, reflecting the game state and receiving user input by connecting with the GameBoard.

## II. Design Changes

1. Implemented GUI interface using the Qt framework with the main window using QWidget and rendering the board through canvas drawing.

2. Read external JSON files to configure different tile probabilities and text styles.

3. Added menu bar functionality, supporting file operations such as opening and saving game states.

4. Introduced a restart feature, allowing players to restart the game directly after it ends.

5. Included achievement notifications, displaying a "Level Completed" message upon reaching the 2048 tile.

6. The status bar displays the current score and the highest score achieved.

## III. Implementation Details

- **GameBoard Class:** Retained the original core game logic.

- **MainWindow Class:** Based on QWidget, implemented board drawing by overriding the paintEvent. Connected with GameBoard signals and slots to update the interface. Keyboard events are delegated to GameBoard for move validation.

- **MenuBar:** Provides file operations and game settings.

- **Status Bar:** Displays real-time current score and highest score.

- **Popup Notifications:** Implemented logic for level completion and restarting.

## IV. Summary

This GUI version, leveraging the Qt framework, adeptly translates the original game rules into a graphical interface. While maintaining the core game logic, the design elevates the user experience through nuanced improvements. The design is lucid, with clear responsibilities for each class, and a judicious coupling of GUI and game rules. This stands as an outstanding implementation of the 2048 game in a GUI environment.

# 2048游戏GUI版本设计报告

## 一、 项目概述

该项目是一个使用Qt框架实现的2048游戏GUI版本，包括核心逻辑（GameBoard类）和图形用户界面（MainWindow类）。

- **GameBoard类：** 封装了游戏的核心逻辑，包括初始化棋盘、移动方块、合并方块等关键功能。
  
- **MainWindow类：** 负责GUI界面的设计和交互，通过连接GameBoard来反映游戏状态并接收用户输入。

## 二、 设计变更

1. 使用Qt框架实现GUI界面，主窗口采用QWidget，通过画布绘图渲染棋盘。

2. 通过读取外部json文件配置不同方块概率和文本样式。

3. 增加菜单栏功能，支持文件操作如打开、保存游戏状态。

4. 增加重启功能，游戏结束后支持直接重新开始。

5. 添加成就提示，在达到2048方块时提示“通关”。

6. 状态栏显示当前得分和最高得分。

## 三、 具体实现

- **GameBoard类：** 保留原有核心游戏逻辑不变。

- **MainWindow类：** 基于QWidget，通过重写paintEvent实现棋盘绘制，连接GameBoard信号槽更新界面，将键盘事件交给GameBoard进行移动判断。

- **MenuBar：** 提供文件操作和游戏设置。

- **状态栏：** 实时显示当前分数和最高分。

- **弹出提示：** 实现通关及重新开始逻辑。

## 四、 总结

该GUI版本通过引入Qt框架，将原有游戏规则巧妙地融入图形界面。在保留核心游戏逻辑不变的同时，通过优化用户体验细节，提升了整体设计水平。设计思路清晰，类职责明确，GUI和游戏规则的耦合得当。这是一个出色的2048游戏GUI实现。

---

**注意：** 以上是初版设计报告的修改版本，按照Markdown格式呈现。

***Please roll down to see the English version***

# 2048游戏(GUI版)

该项目是一个基于Qt框架的2048小游戏GUI实现。

![image](https://github.com/AdAstraAbyssoque/2048/assets/126367816/017adb82-878e-4e58-a176-23996a01a5a2)


## 项目概述

- 2048是一款网红数字匹配游戏。用户通过方向键上下左右移动棋盘内的方块,使得值相同的方块合并得到更高分数。

- 该项目使用C++和Qt框架开发了2048的图形界面版本。保留了原始版游戏的基本规则和逻辑,并实现了更友好的GUI玩法。

## 主要特征

- 游戏核心逻辑封装在GameBoard类中,保留原版游戏规则实现。

- MainWindow类基于QWidget实现 GUI 界面绘制及交互。

- 读取外部JSON配置定制方块样式和概率。

- 提供文件操作菜单如打开、保存游戏状态。

- 增加“通关”提示及重新开始功能。

- 状态栏实时显示当前得分和最高记录。

## 使用说明

1. 想开始新游戏,点击"开始"按钮。

2. 使用方向键或鼠标移动方块合并得分。 

3. 当达到2048方块将提示"通关",询问是否继续。

4. 游戏结束后,按R可立即重新开始。

5. 菜单栏可以打开保存已有游戏数据。

## 项目地址

该项目源码已上传至GitHub:

[https://github.com/AdAstraAbyssoque/2048]

欢迎Star、Fork收藏,也欢迎提出 Issues 和 PR !

# 2048 Game (GUI Version)

This project is a graphical user interface (GUI) implementation of the 2048 game based on the Qt framework.

## Project Overview

- 2048 is a popular number-matching game where users move blocks on the board using arrow keys to merge blocks with the same value and achieve higher scores.

- Developed in C++ using the Qt framework, this project implements a graphical version of the 2048 game. It retains the basic rules and logic of the original game while introducing a more user-friendly GUI gameplay.

## Key Features

- The core game logic is encapsulated in the GameBoard class, preserving the rules of the original game.

- The MainWindow class, based on QWidget, handles GUI interface drawing and interaction.

- External JSON configurations are read to customize block styles and probabilities.

- File operation menu options are provided, such as opening and saving game states.

- Added "Level Completed" prompt and restart functionality.

- The status bar dynamically displays the current score and the highest record.

## Instructions for Use

1. To start a new game, click the "Start" button.

2. Use arrow keys or the mouse to move and merge blocks for points.

3. Upon reaching the 2048 block, a "Level Completed" prompt will appear, asking if you want to continue.

4. After the game ends, press 'R' to immediately restart.

5. The menu bar allows you to open and save existing game data.

## Project Repository

The source code for this project has been uploaded to GitHub:

[https://github.com/AdAstraAbyssoque/2048]

Feel free to Star, Fork, and contribute by raising Issues and PRs!

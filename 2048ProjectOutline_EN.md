# 2048 Game Project Execution Process

## Description

The 2048 game is a single-player sliding block puzzle with a 4x4 grid, where the player combines numbered tiles by sliding them using arrow keys. The objective is to create a tile with the number 2048, with the option to continue playing for higher scores.

## Gameplay Mechanics

- Start with two tiles of 2 or 4.
- Use arrow keys for tile movement.
- Merge tiles of the same number to form a new tile with the sum of their values.
- New tiles (2 or 4) randomly appear in empty spots after each move.

## Scoring

- Earn points equal to the value of a new tile when two tiles merge.
- Cumulative score throughout the game.

## Game Over

The game ends when the board is filled, and no more moves are possible.

## Implementation Requirements

### Core Game Logic

- Handle tile movements and resulting board configuration.
- Determine current score.
- Track total accumulated score.
- Check for game completion.
- Decide whether to generate a "2 tile" or a "4 tile."
- Assess if the game is over.

### Shared Core Logic for CLI and GUI

- Implement a single codebase for both interfaces.
- Use functions or classes to encapsulate core game logic.

### Two Separate Executables for CLI and GUI

- Develop a Makefile for code compilation.
- Define targets for building CLI and GUI versions.

## Evaluation Criteria

- **Integrity of Core Game Mechanics (30%):** Assess correctness, modularity, and code style.
- **Functionality of GUI (40%):** Evaluate usability, design, and error-free operation.
- **Correctness of CLI (30%):** Judge ease of use, consistency, and correctness.

## Bonus Feature Opportunities (Additional 10%)

Complete at least three of the following enhancements:

- Configuration File for Game Settings
- Game Save and Resume Functionality
- User-Friendly GUI and CLI
- Variant Support
- Unit Testing

## How to Hand In Your Project

- Compress project folder into a ZIP file.
- Name the ZIP file: `[yourstudentid]-[yourname in all lower case]-project.zip`.

## Report

Compose a concise report detailing your design and implementation process. Highlight noteworthy or innovative aspects of your project and explain why these elements stand out.

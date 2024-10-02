<p align="center">
  <img src="https://github.com/user-attachments/assets/1bc0abb6-bbb1-442e-980e-addacc69e9e8" />
</p>

# Custom Title Bar Template for C++ Qt

![GitHub stars](https://img.shields.io/github/stars/imitatehappiness/QtCustomTitleBar?style=social)
![GitHub forks](https://img.shields.io/github/forks/imitatehappiness/QtCustomTitleBar?style=social)
![GitHub watchers](https://img.shields.io/github/watchers/imitatehappiness/QtCustomTitleBar?style=social)
![GitHub followers](https://img.shields.io/github/followers/imitatehappiness?style=social)

![Qt version](https://img.shields.io/badge/Qt-5.15.2-151515.svg?Color=EEE&logoColor=EEE)
![MinGw version](https://img.shields.io/badge/MinGw-5.3.0-151515.svg?Color=EEE&logoColor=EEE)

This repository contains a basic template for a custom title bar in a C++ Qt application. The custom title bar provides essential functionality, such as hiding, dragging, maximizing, and closing the window. You can use this template as a starting point in your real projects to create a more personalized and visually appealing title bar for your Qt applications.

## Features
### 1. Interactive Window Controls
- **Collapse Button**: Toggles between collapsing and expanding the window body.
- **Minimize Button**: Minimizes the window to the taskbar.
- **Maximize/Restore Button**: Allows the window to switch between maximized and normal states.
- **Close Button**: Closes the window.

### 2. Draggable Header
- **Move Window**: The window can be dragged and moved around the screen by clicking and holding the left mouse button on the header.
- **Double-Click to Maximize/Restore**: Double-clicking the header toggles between maximized and restored states.

### 3. Context Menu
- **Right-Click Menu on Header**: Right-clicking the header brings up a context menu with an "Exit" option to close the window.

<details>
  <summary>Preview</summary>
  <p align="center">
    <img src="https://github.com/user-attachments/assets/fd5da370-6855-4240-b46b-3f9a5602e51c">
  </p>
</details>

## Basic usage

``` C++
#include "mainwindow.h"
#include "windowframe.h"

#include <QApplication>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    WindowFrame w(nullptr, new MainWindow());
    w.show();
    return a.exec();

}
```
## Example

<p align="center">
  <video src="https://github.com/user-attachments/assets/d4fdcd9a-8565-40e6-85cc-cbb7d70438e5" />
</p>















<p align="center">
  <img src="https://github.com/imitatehappiness/QtCustomTitleBar/assets/79199956/d4d1f4ed-62d7-4c8e-b028-626cd2d6e63a" />
</p>

# Custom Title Bar Template for C++ Qt

![GitHub stars](https://img.shields.io/github/stars/imitatehappiness/QtCustomTitleBar?style=social)
![GitHub forks](https://img.shields.io/github/forks/imitatehappiness/QtCustomTitleBar?style=social)
![GitHub watchers](https://img.shields.io/github/watchers/imitatehappiness/QtCustomTitleBar?style=social)
![GitHub followers](https://img.shields.io/github/followers/imitatehappiness?style=social)

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
  <video src="https://github.com/user-attachments/assets/6da88f11-a2d4-4866-b2e0-52cb83bb3e80" />
</p>









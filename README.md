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
+ **Custom Title Bar:** Replace the default system title bar with a custom-designed one, giving your application a unique look and feel.
+ **Draggable:** Drag the window by clicking and holding the title bar area, providing the same behavior as the standard title bar.
+ **Collapse/Minimize/Maximize/Close:** Add buttons to collapse, minimize, maximize (restore), and close the window, allowing users to interact with the application as expected.
+ **Style Customization:** Easily modify the appearance of the title bar by adjusting colors, fonts, and icons to match your application's theme.

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

<p align="center">
  <img src="https://github.com/user-attachments/assets/8e769ac7-2693-47e9-9858-a9f0bf32c92b" />
  <img src="https://github.com/user-attachments/assets/f5fe5fcf-b927-4dad-bf1d-a9c2ace786f2" />
</p>



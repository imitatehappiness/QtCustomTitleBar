<p align="center">
  <img src="https://github.com/user-attachments/assets/1bc0abb6-bbb1-442e-980e-addacc69e9e8" />
</p>

# Custom Title Bar Template for C++ Qt

![GitHub stars](https://img.shields.io/github/stars/imitatehappiness/QtCustomTitleBar?style=social)
![GitHub forks](https://img.shields.io/github/forks/imitatehappiness/QtCustomTitleBar?style=social)

![Qt version](https://img.shields.io/badge/Qt-5.15.2-151515.svg?Color=EEE&logoColor=EEE)
![MinGW version](https://img.shields.io/badge/MinGW-5.3.0-151515.svg?Color=EEE&logoColor=EEE)
![OS](https://img.shields.io/badge/OS-Win-151515.svg?Color=EEE&logoColor=EEE)

## About project
In standard C++/Qt applications, the window's title bar is managed by the operating system, which imposes limitations on customization. 

This repository provides a template for creating a custom title bar in a C++ Qt application. The custom title bar replicates essential window functionality, including hiding, dragging, maximizing, and closing the window. It serves as an excellent starting point for developers looking to design a more personalized and visually appealing title bar for their Qt applications.

<details>
  <summary>Example</summary>
  <p align="center">
    <img src="https://github.com/user-attachments/assets/19ae5e4b-ccf9-43bb-b15c-832483a9f7b3">
  </p>
</details>

## Quick Start

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
## Demo

<p align="center">
  <video src="https://github.com/user-attachments/assets/d4fdcd9a-8565-40e6-85cc-cbb7d70438e5" />
</p>




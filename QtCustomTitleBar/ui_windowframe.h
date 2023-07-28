/********************************************************************************
** Form generated from reading UI file 'windowframe.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINDOWFRAME_H
#define UI_WINDOWFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WindowFrame
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *header;
    QGridLayout *gridLayout;
    QWidget *buttons;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *minimum;
    QPushButton *maximum;
    QPushButton *close;
    QWidget *body;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QWidget *WindowFrame)
    {
        if (WindowFrame->objectName().isEmpty())
            WindowFrame->setObjectName(QString::fromUtf8("WindowFrame"));
        WindowFrame->resize(857, 563);
        WindowFrame->setStyleSheet(QString::fromUtf8(""));
        verticalLayout = new QVBoxLayout(WindowFrame);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        header = new QWidget(WindowFrame);
        header->setObjectName(QString::fromUtf8("header"));
        header->setMaximumSize(QSize(16777215, 44));
        header->setStyleSheet(QString::fromUtf8(""));
        gridLayout = new QGridLayout(header);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        buttons = new QWidget(header);
        buttons->setObjectName(QString::fromUtf8("buttons"));
        horizontalLayout_2 = new QHBoxLayout(buttons);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        horizontalSpacer = new QSpacerItem(419, 18, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        minimum = new QPushButton(buttons);
        minimum->setObjectName(QString::fromUtf8("minimum"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(minimum->sizePolicy().hasHeightForWidth());
        minimum->setSizePolicy(sizePolicy);
        minimum->setMinimumSize(QSize(0, 0));
        minimum->setMaximumSize(QSize(16777215, 16777215));
        minimum->setStyleSheet(QString::fromUtf8(""));
        minimum->setIconSize(QSize(50, 40));

        horizontalLayout_2->addWidget(minimum);

        maximum = new QPushButton(buttons);
        maximum->setObjectName(QString::fromUtf8("maximum"));
        sizePolicy.setHeightForWidth(maximum->sizePolicy().hasHeightForWidth());
        maximum->setSizePolicy(sizePolicy);
        maximum->setMinimumSize(QSize(0, 0));
        maximum->setMaximumSize(QSize(16777215, 16777215));
        maximum->setStyleSheet(QString::fromUtf8(""));
        maximum->setIconSize(QSize(50, 40));

        horizontalLayout_2->addWidget(maximum);

        close = new QPushButton(buttons);
        close->setObjectName(QString::fromUtf8("close"));
        sizePolicy.setHeightForWidth(close->sizePolicy().hasHeightForWidth());
        close->setSizePolicy(sizePolicy);
        close->setMinimumSize(QSize(0, 0));
        close->setMaximumSize(QSize(16777215, 16777215));
        close->setStyleSheet(QString::fromUtf8(""));
        close->setIconSize(QSize(50, 40));

        horizontalLayout_2->addWidget(close);


        gridLayout->addWidget(buttons, 0, 0, 1, 1);


        verticalLayout->addWidget(header);

        body = new QWidget(WindowFrame);
        body->setObjectName(QString::fromUtf8("body"));
        body->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_2 = new QVBoxLayout(body);
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(3, 3, 3, 3);

        verticalLayout->addWidget(body);


        retranslateUi(WindowFrame);

        QMetaObject::connectSlotsByName(WindowFrame);
    } // setupUi

    void retranslateUi(QWidget *WindowFrame)
    {
        WindowFrame->setWindowTitle(QString());
        minimum->setText(QString());
        maximum->setText(QString());
        close->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class WindowFrame: public Ui_WindowFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINDOWFRAME_H

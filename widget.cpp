#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <stdio.h>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    pbSet(false, false, false);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::pbSet(bool a, bool b, bool c){
    ui->pbCoffee->setEnabled(a);
    ui->pbTea->setEnabled(b);
    ui->pbMilk->setEnabled(c);
}

void Widget::changeMoney(int diff){
    money+=diff;
    ui->lcdNumber->display(money);

    if(money < 100){
        pbSet(false, false, false);
    }
    if(money >= 100 && money < 150){
        pbSet(true, false, false);
    }
    else if(money >= 150 && money < 200){
        pbSet(true, true, false);
    }
    else if(money >= 200){
        pbSet(true, true, true);
    }

}

void Widget::on_pb10_clicked()
{
    changeMoney(10);
}


void Widget::on_pb50_clicked()
{
    changeMoney(50);
}


void Widget::on_pb100_clicked()
{
    changeMoney(100);
}


void Widget::on_pb500_clicked()
{
    changeMoney(500);
}


void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}


void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}


void Widget::on_pbMilk_clicked()
{
    changeMoney(-200);
}


void Widget::on_pbReset_clicked()

{
    char changes[100] = {0, };
    sprintf(changes, "500: %d, 100: %d, 50: %d, 10: %d", money/500, (money%500)/100, (money%100)/50, (money%50)/10);

    QMessageBox mb;
    mb.information(this, "Changes", changes);

    money = 0;
    ui->lcdNumber->display(money);
    pbSet(false, false, false);

}


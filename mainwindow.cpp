#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTableWidgetItem>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , turn(0)
    , numPlayers(2)
    , boardSize(8)
{
    ui->setupUi(this);
	colors << QColor(192,0,0)
           << QColor(0,192,0)
           << QColor(0,0,192)
           << QColor(192,192,0);
	resetBoard();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_tableWidget_clicked(const QModelIndex &index)
{
    if (index.data(Qt::UserRole) != -1)
        return;

    if (isValidPlace(index.row(), index.column(), turn)) {
        place(index.row(), index.column(), turn);

        if (++turn >= numPlayers) {
            turn = 0;
        }
    }
}

void MainWindow::on_actionExit_triggered()
{
    close();
}

bool MainWindow::isValidPlace(int row, int column, int player)
{
    for (int i = row -1; i <= row+1; ++i) {
        for (int j = column-1; j <= column+1; ++j) {
            if (i >= 0 && j >= 0 && i < boardSize && j < boardSize
                && (i != row || j != column))
            {
                QTableWidgetItem *item = ui->tableWidget->item(i, j);
                if (item->data(Qt::UserRole) == player) {
                    return true;
                }
            }
        }
    }
    return false;
}

void MainWindow::resetBoard()
{
    for (int row = 0 ; row < boardSize; ++row) {
        for (int column = 0; column < boardSize; ++column) {
			QTableWidgetItem *item = new QTableWidgetItem;
			item->setData(Qt::UserRole, QVariant(-1));
			ui->tableWidget->setItem(row, column, item);
		}
	}
    place(1, 1, 0);
    place(boardSize-2, boardSize-2, 1);
}

void MainWindow::place(int row, int column, int player)
{
	QTableWidgetItem *item = new QTableWidgetItem();
	item->setData(Qt::UserRole, player);
	item->setBackgroundColor(colors.at(player));
	ui->tableWidget->setItem(row, column, item);

	QTableWidgetItem *upItem = ui->tableWidget->item(row-1, column);
	QTableWidgetItem *downItem = ui->tableWidget->item(row+1, column);
	QTableWidgetItem *rightItem = ui->tableWidget->item(row, column+1);
	QTableWidgetItem *leftItem = ui->tableWidget->item(row, column-1);

    // change adjacents itens to same color of the current player

    // up
	if (row > 0 && upItem->data(Qt::UserRole) != -1) {
		item = new QTableWidgetItem();
		item->setData(Qt::UserRole, player);
		item->setBackgroundColor(colors.at(player));
		ui->tableWidget->setItem(row-1,column, item);
	}

    // right
	if (column < 7 && rightItem->data(Qt::UserRole) != -1) {
		item = new QTableWidgetItem();
		item->setData(Qt::UserRole, player);
		item->setBackgroundColor(colors.at(player));
		ui->tableWidget->setItem(row,column+1, item);
	}

    // down
	if (row < 7 && downItem->data(Qt::UserRole) != -1) {
		item = new QTableWidgetItem();
		item->setData(Qt::UserRole, player);
		item->setBackgroundColor(colors.at(player));
		ui->tableWidget->setItem(row+1,column, item);
	}

    // left
	if (column > 0 && leftItem->data(Qt::UserRole) != -1) {
		item = new QTableWidgetItem();
		item->setData(Qt::UserRole, player);
		item->setBackgroundColor(colors.at(player));
		ui->tableWidget->setItem(row,column-1, item);
	}
}

void MainWindow::on_actionNewGame_triggered()
{
    this->resetBoard();
}

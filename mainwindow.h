#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>
#include <QList>
#include <QColor>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
	void on_tableWidget_clicked(const QModelIndex &index);
	void on_actionExit_triggered();
    void on_actionNewGame_triggered();

private:
    Ui::MainWindow *ui;
	int turn;
	int numPlayers;
	QList<QColor> colors;
	bool isValidPlace(int row, int column, int player);
	void resetBoard();
	void place(int row, int column, int player);
    int boardSize;
};

#endif // MAINWINDOW_H

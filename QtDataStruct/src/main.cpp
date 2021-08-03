#include <QApplication>
#include <QPushButton>
#include <QPushButton>
#include <QLabel>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QLabel label("this is a control window.");
    label.setWindowTitle("DataStruct");
    label.setGeometry(100,50,360,160);
    label.setAlignment(Qt::AlignCenter);
    label.show();
    QPushButton btn;
    btn.setWindowTitle("Button");
    btn.setText("这是一个大大的按钮");
    btn.setGeometry(480,50,360,160);
    btn.show();
    return a.exec();
}

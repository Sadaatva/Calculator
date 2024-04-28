#include "calculator.h"

int main(int argc,char** argv) {
    QApplication w(argc,argv);
    Calculator Calculator;

    Calculator.show();
    return w.exec();
}

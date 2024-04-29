#include "calculator.h"

Calculator::Calculator() {
    lineEdit = new QLineEdit(this);
    lineEdit->setReadOnly(true);

    grid = new QGridLayout(this);
    grid->setSpacing(5);

    QPushButton *Btn1 = new QPushButton("delete",this);
    Btn1->setStyleSheet("background-color: #FF69B4; font-size: 16px;");
    QPushButton *Btn2 = new QPushButton("+",this);
    Btn2->setStyleSheet("background-color: #FF69B4; font-size: 18px;");
    QPushButton *Btn3 = new QPushButton("-",this);
    Btn3->setStyleSheet("background-color: #FF69B4; font-size: 18px;");
    QPushButton *Btn4 = new QPushButton("*",this);
    Btn4->setStyleSheet("background-color: #FF69B4; font-size: 18px;");
    QPushButton *Btn5 = new QPushButton("/",this);
    Btn5->setStyleSheet("background-color: #FF69B4; font-size: 18px;");
    QPushButton *Btn6 = new QPushButton("=",this);
    Btn6->setStyleSheet("background-color: #FF69B4; font-size: 18px;");
    QPushButton *Btn7 = new QPushButton("clear",this);
    Btn7->setStyleSheet("background-color: #FF69B4; font-size: 18px;");
    QPushButton *Btn8 = new QPushButton("^",this);
    Btn8->setStyleSheet("background-color: #FF69B4; font-size: 18px;");
    QPushButton *Btn82 = new QPushButton("sqrt",this);
    Btn82->setStyleSheet("font-size: 16px;");
    QPushButton *Btn9 = new QPushButton(".",this);
    Btn9->setStyleSheet("font-size: 18px;");

    lineEdit->setReadOnly(true);
    setFixedSize(350,400);

    grid->addWidget(Btn9,6,2);
    Btn9->setMaximumSize(1000, 1000);
    grid->addWidget(Btn1, 1,1,1,1);
    Btn1->setMaximumSize(1000, 1000);
    grid->addWidget(Btn7, 1,0,1,1);
    Btn7->setMaximumSize(1000, 1000);
    grid->addWidget(Btn2, 4,3);
    Btn2->setMaximumSize(1000, 1000);
    grid->addWidget(Btn3, 3,3);
    Btn3->setMaximumSize(1000, 1000);
    grid->addWidget(Btn4, 1,2);
    Btn4->setMaximumSize(1000, 1000);
    grid->addWidget(Btn5, 1,3);
    Btn5->setMaximumSize(1000, 1000);
    grid->addWidget(Btn6, 6,3);
    Btn6->setMaximumSize(1000, 1000);
    grid->addWidget(Btn8, 5,3);
    Btn8->setMaximumSize(1000, 1000);
    grid->addWidget(Btn82, 6,0);
    Btn82->setMaximumSize(1000, 1000);
    grid->addWidget(lineEdit, 0, 0, 1, 4);
    lineEdit->setFixedSize(327,40);

    for(int i = 0; i < 10; i++) {
        QPushButton *btn = new QPushButton((symbols[i]), this);
        numbers.push_back(btn);
    }

    for(int i = 0; i < 10; i++) {
        numbers[i]->setMaximumSize(1000, 1000);
        numbers[i]->setStyleSheet("font-size: 16px;");
        connect(numbers[i], &QPushButton::clicked, this, &Calculator::pointAndNum);
    }

    grid->addWidget(numbers[7], 3, 0);
    grid->addWidget(numbers[8], 3, 1);
    grid->addWidget(numbers[9], 3, 2);
    grid->addWidget(numbers[4], 4, 0);
    grid->addWidget(numbers[5], 4, 1);
    grid->addWidget(numbers[6], 4, 2);
    grid->addWidget(numbers[1], 5, 0);
    grid->addWidget(numbers[2], 5, 1);
    grid->addWidget(numbers[3], 5, 2);
    grid->addWidget(numbers[0], 6, 1);

    connect(Btn7,&QPushButton::clicked,lineEdit,&QLineEdit::clear);
    connect(Btn7,&QPushButton::clicked,this,&Calculator::zero);
    connect(Btn2, &QPushButton::clicked, this, [this](){ mathOperation("+"); });
    connect(Btn3, &QPushButton::clicked, this, [this](){ mathOperation("-"); });
    connect(Btn4, &QPushButton::clicked, this, [this](){ mathOperation("*"); });
    connect(Btn5, &QPushButton::clicked, this, [this](){ mathOperation("/"); });
    connect(Btn8, &QPushButton::clicked, this, &Calculator::square);
    connect(Btn82, &QPushButton::clicked, this, &Calculator::sqrt);
    connect(Btn6, &QPushButton::clicked, this, &Calculator::equal);
    connect(Btn1, &QPushButton::clicked, this, &Calculator::clearAll);
    connect(Btn9, &QPushButton::clicked, this, &Calculator::pointAndNum);

    setLayout(grid);
}

void Calculator::sqrt() {
    double num = lineEdit->text().toDouble();
    if (num < 0) {
        lineEdit->setText("Error");
    } else {
        double squareRoot = qSqrt(num);
        lineEdit->setText(QString::number(squareRoot));
    }
}

void Calculator::square() {
    double num = lineEdit->text().toDouble();
    double squared = num * num;
    lineEdit->setText(QString::number(squared));
}

void Calculator::mathOperation(QString oprt) {
    if (!lineEdit->text().isEmpty()) {
        number.push_back(lineEdit->text().toDouble());
        lineEdit->clear();
        operations.push_back(oprt);
    }
}

void Calculator::equal() {
    if (!lineEdit->text().isEmpty()) {
        number.push_back(lineEdit->text().toDouble());
    }

    double resultt = number[0];
    for(int i = 0; i < operations.size(); ++i) {
    if (operations[i] == "+") {
        resultt += number[i+1];
    }
    else if  (operations[i] == "-") {
        resultt -= number[i+1];
    }
    else if (operations[i] == "*") {
        resultt *= number[i+1];
    }
    else if (operations[i] == "/") {
        if (number[i+1] != 0.0) {
            resultt /= number[i+1];
        }
        else {
            lineEdit->setText("Error");
            return;
        }
    }
    }

    lineEdit->setText(QString::number(resultt));
    number.clear();
    operations.clear();
}

void Calculator::pointAndNum() {
    if(lineEdit->text() == "0") {
        lineEdit->clear();
    }

    QPushButton *button = qobject_cast<QPushButton*>(sender());
    if (button) {
        QString num = button->text();
        QString text = lineEdit->text();

        if (num == "." && text.contains(".")) {
            return;
        }

        if ((text.isEmpty() || text == "0") && num == ".") {
            lineEdit->setText("0.");
        }

        else if (lineEdit) {
            lineEdit->insert(num);
        }
    }
}

void Calculator::zero() {
    lineEdit->insert("0");
}

void Calculator::clearAll() {
    lineEdit->clear();
    number.clear();
    operations.clear();
}

Calculator::~Calculator() {
    delete lineEdit;
    delete grid;
}

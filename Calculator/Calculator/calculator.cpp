#include "calculator.h"

double num1 = 0.0;

Calculator::Calculator() {
    lineEdit = new QLineEdit(this);
    lineEdit->setReadOnly(true);
    result = 0.0;

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
    result = 0.0;
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
        num1 = lineEdit->text().toDouble();
        lineEdit->clear();
    }
    Operation = oprt;
}

void Calculator::equal() {
    double num2 = lineEdit->text().toDouble();
    if (Operation == "+") {
        result = num1 + num2;
    }
    else if (Operation == "-") {
        result = num1 - num2;
    }
    else if (Operation == "*") {
        result = num1 * num2;
    }
    else if (Operation == "/") {
        if (num2 != 0.0) {
            result = num1 / num2;
        }
        else {
            lineEdit->setText("Error");
            return;
        }
    }

    lineEdit->setText(QString::number(result));
    result = 0.0;
    num1 = 0.0;
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

        if (text == "0" && num == ".") {
            lineEdit->setText("0.");
        }

        else if (lineEdit) {
            lineEdit->insert(num);
        }
    }
}

void Calculator::zero() {
    lineEdit->insert("0");
    result = 0.0;
}

void Calculator::clearAll() {
    QString currentText = lineEdit->text();
    if (!currentText.isEmpty()) {
        currentText.chop(1);
        lineEdit->setText(currentText);
        if (lineEdit->text().isEmpty()) {
            lineEdit->setText("0");
        }

    }
}

Calculator::~Calculator() {
    delete lineEdit;
    delete grid;
}

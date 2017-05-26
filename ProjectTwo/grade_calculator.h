#ifndef GRADE_CALCULATOR_H
#define GRADE_CALCULATOR_H

#include <QMainWindow>

namespace Ui {
    class grade_calculator;
}

class grade_calculator : public QMainWindow{
    Q_OBJECT

    public:
        explicit grade_calculator(QWidget *parent = 0);
        ~grade_calculator();

        double calculatePIC10C();
        double calculateMath132();
        double calculateMath180();
        double calculatePoliSci30();
        double calculateAA10();

    public slots:

    signals:

    private slots:
        void on_radioButton_Clicked();
        void on_radioButton2_Clicked();
        void on_radioButton3_Clicked();
        void on_radioButton4_Clicked();
        void on_radioButton5_Clicked();
        void on_submit_Clicked();
        void on_reset_Clicked();

    private:
     Ui::grade_calculator *ui;
     bool gradingPIC10C;
     bool gradingMath132;
     bool gradingMath180;
     bool gradingPoliSci30;
     bool gradingAA10;

};

#endif // GRADE_CALCULATOR_H

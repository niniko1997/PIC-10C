#ifndef grade_calculator.h
#define grade_calculator_h

#include <QMainWindow>

namespace Ui {
    class grade_calculator;

}

class grade_calculator : public QMainWindow {
    Q_OBJECT

    public:
        grade_calculator();
        ~grade_calculator();

    public slots:
        signals:

    private slots:

    private:
        Ui::MainWindow * window;

};

#endif 
// grade_calculator header end

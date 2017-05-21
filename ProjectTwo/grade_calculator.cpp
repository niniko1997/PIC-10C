#include "grade_calculator.h"
#include "ui_grade_calculator.h"

grade_calculator::grade_calculator() 
:window(nullptr) {
    try{
        window = new Ui::MainWindow();
    } catch (std::exception& e){
        std::cout << "Memory Allocation Failed";
        throw;
    }

}

grade_calculator::~grade_calculator()
{
    delete window;
}

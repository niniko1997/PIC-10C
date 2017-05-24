#include "grade_calculator.h"
#include "ui_grade_calculator.h"

// default constructor
// sets all grading schemes to false and initializes a window based on parent
grade_calculator::grade_calculator(QWidget *parent)
    :QMainWindow(parent), ui(new Ui::grade_calculator), gradingPIC10C(false), gradingMath132(false), gradingMath180(false), gradingPoliSci30(false), gradingAA10(false){
    ui->setupUi(this);
}

// destructor
grade_calculator::~grade_calculator()
{
    delete ui;
}

// checks if the PIC10C radio button is clicked and activates that grading scheme
void grade_calculator::on_radioButton_Clicked(){
    gradingPIC10C = true;
}

// checks if the Math132 radio button is clicked and activates that grading scheme
void grade_calculator::on_radioButton2_Clicked(){
    gradingMath132 = true;
}

// checks if the Math180 radio button is clicked and activates that grading scheme
void grade_calculator::on_radioButton3_Clicked(){
    gradingMath180 = true;
}

// checks if the Poli Sci 30 radio button is clicked and activates that grading scheme
void grade_calculator::on_radioButton4_Clicked(){
    gradingPoliSci30 = true;
}

// checks if the AA 10 radio button is clicked and activates that grading scheme
void grade_calculator::on_radioButton5_Clicked(){
    gradingAA10 = true;
}

// calculates average hw grade, average midterm grade, final grade and final project grade for the PIC10C class
double grade_calculator::calculatePIC10C(){
    double averageHWGrade = 0;
    double averageMidtermGrade = 0;
    double finalGrade = 0;
    double finalProjectGrade = 0;

    // calculate average hw
    double hwScore = ((ui->hwOneScore->text()).toDouble() + (ui->hwOneScore->text()).toDouble() + (ui->hwOneScore->text()).toDouble());
    double hwTotal = ((ui->hwOneScoreTotal->text()).toDouble() + (ui->hwTwoScoreTotal->text()).toDouble() + (ui->hwThreeScoreTotal->text()).toDouble());
    averageHWGrade = hwScore/hwTotal;

    // calculate average midterm
    averageMidtermGrade = ((ui->midtermOneScore->text()).toDouble())/((ui->midtermOneScoreTotal->text()).toDouble());

    // calculate final exam grade
    finalGrade = ((ui->finalScore->text()).toDouble())/((ui->finalScoreTotal->text()).toDouble());

    // calculate final project grade
    finalProjectGrade = ((ui->finalProjectScore->text()).toDouble())/((ui->finalProjectScoreTotal->text()).toDouble());

    double overallGrade1 = .15 * averageHWGrade + .25 * averageMidtermGrade + .30 * finalGrade + .30 * finalProjectGrade;
    double overallGrade2 = .15 * averageHWGrade + .50 * finalGrade + .35 * finalProjectGrade;

    if(overallGrade1 >= overallGrade2){
        return overallGrade1;
    }

    return overallGrade2;
}

// checks which scheme was chosen and calls the appropriate calculate function
// outputs total score into the line edit field
void grade_calculator::on_submit_Clicked(){
    double grade = 0;
    if(gradingPIC10C){
       grade = calculatePIC10();
    } else if(gradingMath132){
        calculateMath132();
    } else if(gradingMath180){
        calculateMath180();
    } else if(gradingPoliSci30){
        calculatePoliSci30();
    } else if(gradingAA10){
        calculateAA10();
    }

    ui->lineEdit->setText(QString::number(grade) + "%");
}



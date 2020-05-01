#include <iostream>

using namespace std;

class Student {
protected:
    float rating = 5.0;
    unsigned int mark = 5;
    unsigned int scholarship = 7800;
    string sorry = "Sorry, i didn't study for the exam. ";
public:
    string surname;               //Отсутсвие инкапсуляции

  void setRating(float rating) {  //инкапсуляция с помощью set/get
        this->rating = rating;
    }

    float getRating() const {
        return rating;
    }

    void setMark(unsigned int mark) {
        this->mark = mark;
    }

    unsigned int getMark() const {
        return mark;
    }

  void fallingRating(float rating) { //инкапсуляция с помощью специальных методов
       this->rating /= rating;
  }

    virtual void saySorry() const {  //замена поведения
        cout << sorry << endl;
    }

    virtual void Mark() {           //расширение поведения
       mark-- ;
      cout<< "Your mark : "<< getMark() << endl;
  }

};

 class BadStudent : public Student {
 public:
     void saySorry() const {
         cout<< "I didn't do anything." << endl;
     }

     void Mark() {
         Student::Mark();
         cout<< "This is my first good mark." << endl;
     }

 };

 class GoodStudent : public Student {  //инкапсуляция за счет абстракций
 public:
     GoodStudent(const float rating, const unsigned int mark, const unsigned int scholarship, const string sorry, const string surname) {
         this->rating = rating;
         this->mark = mark;
         this->scholarship = scholarship;
         this->sorry = sorry;
         this->surname = surname;
 }

 void setScholarship(unsigned int scholarship) {
   this->scholarship = scholarship;
 }

 unsigned int getScholarship() {
     return scholarship;
 }

 };

 void exam(Student *s) {
     s->saySorry();
 }

 void badExam(Student *s) {
     s->Mark();
 }

int main() {
    Student A;
    BadStudent B;
    GoodStudent H(5.0,4,5000,"k","g");
    A.surname = "Kuznetcova";
    cout << A.surname << endl;
    A.fallingRating(3.6);
    cout << A.getRating() <<endl;
    cout << H.getScholarship() <<endl;
    exam(&A);
    exam(&B);
    badExam(&A);
    badExam(&B);
    return 0;
}

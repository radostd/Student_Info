#include <iostream>
#include <ctime>
#include <fstream>
#include <algorithm>
#include <string>

using namespace std;

class Date {
public:
    int day;
    int month;
    int year;

    int getDay() {return day;}
    void setDay();
    int getMonth() {return month;}
    void setMonth();
    int getYear() {return year;}
    void setYear();

    Date(int day, int month, int year);

    void getBDate(int day, int month, int year)
    {
        this->day = day;
        this->month = month;
        this->year = year;
        cout << day << "/" << month << "/" << year << endl;
    };

};

Date::Date(int day, int month, int year){
        this->day = day;
        this->month = month;
        this->year = year;
};


class Student : public Date{

public:
    string name;
    Date bd();
    int fnum;
    double sr_uspeh;

    int writeStudentsIntoFile();
    string getName() {return name;}
    void setName();
    Date getBd() {return bd();}
    void setBd();
    int getFnum() {return fnum;}
    void setFnum();
    double getSr_uspeh() {return sr_uspeh;}
    void setSr_uspeh();

    Student(string name, int fnum, double sr_uspeh) : Date(day, month, year)
    {
        this->name = name;
        this->fnum = fnum;
        this->sr_uspeh = sr_uspeh;
    }
    Student(string name, Date bd(), int fnum, double sr_uspeh) : Date(day, month, year)
    {
        this->name = name;
        this->bd() = bd();
        this->fnum = fnum;
        this->sr_uspeh = sr_uspeh;
    }
    ~Student(){};
};

class PStudent : public Student {
public:


    PStudent(string name, int fnum, double sr_uspeh) : Student(name, fnum, sr_uspeh){};

    int age(int day, int month, int year)
    {
        struct tm data = {0};
        data.tm_mday = day;
        data.tm_mon  = month-1;
        data.tm_year = year-1900;
        time_t normal = mktime(&data);
        time_t current;
        time(&current);
        int age_ = (difftime(current, normal) + 86400L/2) / 86400L;
        int p_age = age_/365;
        return p_age;
    };


};

int main()
{
    PStudent s1("Jana", 123456789, 3);
    cout<<"name: "<<s1.getName()<<endl;
    cout<<"date of birth: ";
    s1.getBDate(12, 11, 2001);
    cout<<"age: ";
    s1.age(12,11,2001);
    cout<<"faculty number: "<<s1.getFnum()<<endl;
    cout<<"average score: "<<s1.getSr_uspeh()<<endl;
    cout<<endl;


    PStudent s2("Boris", 124563987, 5);
    cout<<"name: "<<s2.getName()<<endl;
    cout<<"date of birth: ";
    s2.getBDate(21, 9, 2000);
    cout<<"age: ";
    s2.age(21,9,2000);
    cout<<"faculty number: "<<s2.getFnum()<<endl;
    cout<<"average score: "<<s2.getSr_uspeh()<<endl;
    cout<<endl;


    PStudent s3("Pami", 129865743, 4.5);
    cout<<"name: "<<s3.getName()<<endl;
    cout<<"date of birth: ";
    s3.getBDate(3, 5, 1998);
    cout<<"age: ";
    s3.age(3, 5,1998);
    cout<<"faculty number: "<<s3.getFnum()<<endl;
    cout<<"average score: "<<s3.getSr_uspeh()<<endl;
    cout<<endl;


    PStudent s4("Atanas", 125463789, 3.5);
    cout<<"name: "<<s4.getName()<<endl;
    cout<<"date of birth: ";
    s4.getBDate(12, 7, 1997);
    cout<<"age: ";
    s4.age(12,7,1997);
    cout<<"faculty number: "<<s4.getFnum()<<endl;
    cout<<"average score: "<<s4.getSr_uspeh()<<endl;
    cout<<endl;


    PStudent s5("Ivan", 123498765, 4);
    cout<<"name: "<<s5.getName()<<endl;
    cout<<"date of birth: ";
    s5.getBDate(1, 1, 1973);
    cout<<"age: ";
    s5.age(1,1,1973);
    cout<<"faculty number: "<<s5.getFnum()<<endl;
    cout<<"average score: "<<s5.getSr_uspeh()<<endl;
    cout<<endl;


    double max_sr_usp;
    if (s1.getSr_uspeh()>s2.getSr_uspeh() && s1.getSr_uspeh()>s3.getSr_uspeh() && s1.getSr_uspeh()>s4.getSr_uspeh() && s1.getSr_uspeh()>s5.getSr_uspeh()){
        max_sr_usp = s1.getSr_uspeh();
        cout<<"The highest average score is "<< max_sr_usp <<endl;
    }else if (s2.getSr_uspeh()>s3.getSr_uspeh() && s2.getSr_uspeh()>s4.getSr_uspeh() && s2.getSr_uspeh()>s5.getSr_uspeh()) {
        max_sr_usp = s2.getSr_uspeh();
        cout<<"The highest average score is "<< max_sr_usp <<endl;
    }else if (s3.getSr_uspeh()>s4.getSr_uspeh() && s3.getSr_uspeh()>s5.getSr_uspeh()) {
        max_sr_usp = s3.getSr_uspeh();
        cout<<"The highest average score is "<< max_sr_usp <<endl;
    }else if (s4.getSr_uspeh()>s5.getSr_uspeh()) {
        max_sr_usp = s4.getSr_uspeh();
        cout<<"The highest average score is "<< max_sr_usp <<endl;
    }else {
        max_sr_usp = s5.getSr_uspeh();
        cout<<"The highest average score is "<< max_sr_usp <<endl;
    }
    cout<<" "<<endl;


    cout<<"The students with age between 18 and 26 are: "<<endl;

    int s1_age = s1.age(12,11,2001);
    int s2_age = s2.age(21,9,2000);
    int s3_age = s3.age(3, 5,1998);
    int s4_age = s4.age(12,7,1997);
    int s5_age = s5.age(1,1,1973);

    if (s1_age>=18 && s1_age<=26){
        cout<<"name: "<<s1.getName()<<", "<<s1_age<<endl;
    }
    if (s2_age>=18 && s2_age<=26){
       cout<<"name: "<<s2.getName()<<", "<<s2_age<<endl;
    }
    if (s3_age>=18 && s3_age<=26){
        cout<<"name: "<<s3.getName()<<", "<<s3_age<<endl;
    }
    if (s4_age>=18 && s4_age<=26){
        cout<<"name: "<<s4.getName()<<", "<<s4_age<<endl;
    }
    if (s5_age>=18 && s5_age<=26){
        cout<<"name: "<<s5.getName()<<", "<<s5_age<<endl;
    }

    return 0;
}

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee {
protected:
    std::string name;
    int id;

public:
    // Constructor
    Employee(const std::string& name_, int id_) : name(name_), id(id_) {}

    // Virtual destructor to ensure correct destruction of derived objects
    virtual ~Employee() {}

    // Pure virtual functions
    virtual double calculate_weekly_salary() const = 0;
    virtual double compute_health_care_contributions() const = 0;
    virtual double compute_vacation_days() const = 0;

    std::string get_name() const;
    int get_id() const;
};

class Professional : public Employee {
private:
    double monthly_salary;
    double number_of_vacation_days;

public:
    // Constructor
    Professional(const std::string& name_, int id_, double monthly_salary_);

    // Overridden virtual functions
    double calculate_weekly_salary() const override;
    double compute_health_care_contributions() const override;
    double compute_vacation_days() const override;
    void add_vacation_days(); // update number_of_vacation_days
    double get_salary();
};

class Nonprofessional : public Employee {
private:
    double hourly_rate;
    int hours_worked;
    int number_of_vacation_hours;

public:
    // Constructor
    Nonprofessional(const std::string& name_, int id_, double hourly_rate_);

    // Overridden virtual functions
    double calculate_weekly_salary() const override;
    double compute_health_care_contributions() const override;
    double compute_vacation_days() const override;
    void set_hours_worked(int hours);
    void add_vacation_hours(); // update number_of_vacation_hours
    double get_rate();
};

#endif // EMPLOYEE_H

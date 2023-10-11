#include "Employee.h"


// Implementation for Professional
Professional::Professional(const std::string& name_, int id_, double monthly_salary_)
: Employee(name_, id_), monthly_salary(monthly_salary_), number_of_vacation_days(0) {}

double Professional::calculate_weekly_salary() const {
    return monthly_salary / 4;  // Assuming 4 weeks in a month
}

double Professional::compute_health_care_contributions() const {
    // Sample rule: 1% of monthly salary for health care
    return monthly_salary * 0.01;
}

double Professional::compute_vacation_days() const {
    // Sample rule: Professionals earn 0.5 vacation days per week
    return 0.5;

}

void Professional::add_vacation_days() {
    number_of_vacation_days += compute_vacation_days();

}

double Professional::get_salary() {
    return monthly_salary;
}

// Implementation for Nonprofessional
Nonprofessional::Nonprofessional(const std::string& name_, int id_, double hourly_rate_)
: Employee(name_, id_), hourly_rate(hourly_rate_), hours_worked(0) {}

double Nonprofessional::calculate_weekly_salary() const {
    return hourly_rate * hours_worked;
}

double Nonprofessional::compute_health_care_contributions() const {
    // Sample rule: Flat $50 for healthcare if worked more than 20 hours a week
    if (hours_worked > 20) {
        return 50.0;
    } else {
        return 0;
    }
}

double Nonprofessional::compute_vacation_days() const {
    // Sample rule: Nonprofessionals earn 0.1 vacation days for every 10 hours worked in a week
    return 0.1 * (hours_worked / 10);
}

void Nonprofessional:: set_hours_worked(int hours) {
    hours_worked = hours;
}

void Nonprofessional::add_vacation_hours() {
    number_of_vacation_hours += static_cast<int>(compute_vacation_days() * 8);
}

double Nonprofessional::get_rate() {
    return hourly_rate;
}

std::string Employee::get_name() const {
    return name;
}

int Employee::get_id() const {
    return id;
}
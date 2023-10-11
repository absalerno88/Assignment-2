Employee and LinkedList Assignment

This project consists of the implementation of a single linked list and an employee management system for professional and nonprofessional employees.

Overview:
1. Single_Linked_List: A templated implementation of a single linked list that can store any datatype.
The included operations are:
push_front
push_back
pop_front
pop_back
insert
remove
find
size
print

2. Employee System: A reprentation of employees in a company differentiated by their status as a professional or nonprofessional.
    - Employee: Abstract base class that declares common functionalities for both professional and nonprofessional employees.
    - Professional: Derived class from Employee. Represents employees who have a fixed monthly salary and receive vacation days based on weeks worked.
    - Nonprofessional: Derived class from Employee. Represents employees who have an hourly rate and receive vacation hours based on hours worked.

    Some functionalities included are:
    - Calculation of weekly salary
    - Computation of health care contributions
    - Computation of vacation days

I used Visual Studio Code with g++ and compiled it in the terminal with "g++ main.cpp Employee.cpp -o myprogram" and ran the code with "./myprogram"

This will run the test cases I created in the main.cpp for both the linked list and employee classes. All methods and functionalities are tested for.

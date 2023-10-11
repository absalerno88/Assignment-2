#include "LinkedList.h"
#include "Employee.h"

using namespace std;

int main() {

    // Testing Single_Linked_List
    cout << "\n===== Testing Single_Linked_List =====\n";

    Single_Linked_List<int> myList;

    // Testing push_front
    myList.push_front(5);
    cout << "After push_front(5), Front: " << myList.front() << ", Back: " << myList.back() << "\n";  // Should print 5

    // Testing push_back
    myList.push_back(10);
    cout << "After push_back(10), Front: " << myList.front() << ", Back: " << myList.back() << "\n";  // Should print 5 & 10

    myList.push_back(15);
    cout << "After push_back(15), Front: " << myList.front() << ", Back: " << myList.back() << "\n";  // Should print 5 & 15

    // Testing insert
    myList.insert(1, 7);
    cout << "After inserting 7 at index 1, the value 7 is at index: " << myList.find(7) << "\n"; // Should print 1

    myList.insert(10, 20);  // Testing inserting beyond the end of the list
    cout << "After inserting 20 at an out-of-range index, Back: " << myList.back() << "\n";   // Should print 20

    // Print list
    cout << "The list: ";
    myList.print();

    // Testing remove
    myList.remove(3);
    cout << "After removing the element at index 3 (15), Back: " << myList.back() << "\n";   // Should print 20

    bool removalStatus = myList.remove(10);  // Trying to remove an out-of-range index
    cout << "Attempting to remove element at an out-of-range index: " << (removalStatus ? "Successful" : "Failed") << "\n";  // Should print Failed

    // Testing find
    std::size_t index = myList.find(7);
    if (index != myList.size()) {
        cout << "Element 7 found at index: " << index << "\n";  // Should print index of 7
    } else {
        cout << "Element 7 not found in the list.\n";
    }

    index = myList.find(25);
    if (index != myList.size()) {
        cout << "Element 25 found at index: " << index << "\n";
    } else {
        cout << "Element 25 not found in the list.\n";  // Should print this line
    }

    // Print list
    cout << "The list: ";
    myList.print();

    // Testing empty
    cout << "Is the list empty? " << (myList.empty() ? "Yes" : "No") << "\n";  // Should print No

    // Testing pop_front and pop_back
    myList.pop_front();
    cout << "After pop_front(), Front: " << myList.front() << "\n";  // Should display the value after 5

    myList.pop_back();
    cout << "After pop_back(), Back: " << myList.back() << "\n";  // Should display the value before 20

    // Print list
    cout << "The list: ";
    myList.print();

    // ====================================================================================================



    cout << "\n===== Testing Employee Classes =====\n";

    // Create Professional and Nonprofessional employees
    Professional prof("John Smith", 101, 6000); // ID 101 Monthly salary of 6000
    Nonprofessional nonProf("Jane Doe", 202, 25); // ID 202 Hourly pay rate 25

    // Set working hours for Nonprofessional
    nonProf.set_hours_worked(30);

    // Displaying names and IDs
    cout << "Professional Name: " << prof.get_name() << ", ID: " << prof.get_id() << ", Monthly salary: $" << prof.get_salary() << "\n";
    cout << "Nonprofessional Name: " << nonProf.get_name() << ", ID: " << nonProf.get_id() << ", Hourly rate: $" << nonProf.get_rate() << "\n";

    // Calculate and display weekly salary for both
    cout << "Professional Weekly Salary: $" << prof.calculate_weekly_salary() << "\n";
    cout << "Nonprofessional Weekly Salary: $" << nonProf.calculate_weekly_salary() << "\n";

    // Calculate and display health care contributions
    cout << "Professional Health Care Contributions: $" << prof.compute_health_care_contributions() << "\n";
    cout << "Nonprofessional Health Care Contributions: $" << nonProf.compute_health_care_contributions() << "\n";

    // Calculate and display vacation days/hours
    cout << "Professional Vacation Days: " << prof.compute_vacation_days() << "\n";
    prof.add_vacation_days(); // update vacation days
    cout << "Nonprofessional Vacation Days: " << nonProf.compute_vacation_days() << "\n";
    nonProf.add_vacation_hours(); // update vacation hours

    return 0;

}

#include "../std_lib_facilities.h"

vector<int> mondays;
vector<int> tuesdays;
vector<int> wednesdays;
vector<int> thursdays;
vector<int> fridays;
vector<int> saturdays;
vector<int> sundays;

bool handle_input(string day, int value) {
    if (day == "Monday" || day == "monday" || day == "Mon" || day == "mon") {
        mondays.push_back(value);
        return true;
    }
    else if (day == "Tuesday" || day == "tuesday" || day == "Tue" || day == "tue") {
        tuesdays.push_back(value);
        return true;
    }
    else if (day == "Wednesday" || day == "wednesday" || day == "Wed" || day == "wed") {
        wednesdays.push_back(value);
        return true;
    }
    else if (day == "Thursday" || day == "thursday" || day == "Thu" || day == "thu") {
        thursdays.push_back(value);
        return true;
    }
    else if (day == "Friday" || day == "friday" || day == "Fri" || day == "fri") {
        fridays.push_back(value);
        return true;
    }
    else if (day == "Saturday" || day == "saturday" || day == "Sat" || day == "sat") {
        saturdays.push_back(value);
        return true;
    }
    else if (day == "Sunday" || day == "sunday" || day == "Sun" || day == "sun") {
        sundays.push_back(value);
        return true;
    }
    else
        return false;
}

void print_day_values(vector<int> vec) {
    for (int v: vec)
        cout << v << '\n';
}

int sum_day_values(vector<int> vec) {
    int sum = 0;
    for (int v: vec)
        sum += v;
    return sum;
}

void print_all_weekdays() {
    if (mondays.size() > 0) {
        cout << "Values for Monday:\n";
        print_day_values(mondays);
        cout << "Sum: " << sum_day_values(mondays) << '\n';
    }
    if (tuesdays.size() > 0) {
        cout << "Values for Tuesday:\n";
        print_day_values(tuesdays);
        cout << "Sum: " << sum_day_values(tuesdays) << '\n';
    }
    if (wednesdays.size() > 0) {
        cout << "Values for Wednesday:\n";
        print_day_values(wednesdays);
        cout << "Sum: " << sum_day_values(wednesdays) << '\n';
    }
    if (thursdays.size() > 0) {
        cout << "Values for Thursday:\n";
        print_day_values(thursdays);
        cout << "Sum: " << sum_day_values(thursdays) << '\n';
    }
    if (fridays.size() > 0) {
        cout << "Values for Friday:\n";
        print_day_values(fridays);
        cout << "Sum: " << sum_day_values(fridays) << '\n';
    }
    if (saturdays.size() > 0) {
        cout << "Values for Saturday:\n";
        print_day_values(saturdays);
        cout << "Sum: " << sum_day_values(saturdays) << '\n';
    }
    if (sundays.size() > 0) {
        cout << "Values for Sunday:\n";
        print_day_values(sundays);
        cout << "Sum: " << sum_day_values(sundays) << '\n';
    }
}

int main() {
    try {
        string temp_day;
        int temp_value;
        int rejected = 0;
        while (cin >> temp_day >> temp_value) {
            if (!handle_input(temp_day, temp_value))
                ++rejected;
        }
        print_all_weekdays();
        cout << "Rejected " << rejected << " values.\n";
        return 0;
    } catch (exception& e) {
        cerr << "Error: " << e.what() << '\n';
        return 1;
    } catch (...) {
        cerr << "Unknown exception!\n";
        return 2;
    }
}
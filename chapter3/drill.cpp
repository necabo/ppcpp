#include "../std_lib_facilities.h"

int main() {
    cout << "Enter the name of the person you want to write to:\n";
    string recipient_name;
    cin >> recipient_name;
    cout << "Enter the age of the person you want to write to:\n";
    int recipient_age;
    cin >> recipient_age;
    if (recipient_age <= 0 || recipient_age >= 110)
        simple_error("you're kidding!");
    
    cout << "Enter the name of a friend:\n";
    string friend_name;
    cin >> friend_name;
    char friend_sex {0};
    cout << "Enter an 'm' if your friend is male and an 'f' if your friend is female:\n";
    cin >> friend_sex;

    cout << "Dear " << recipient_name << ",\n"
         << "How are you? I am fine. I miss you.\n"
         << "Add a few more lines\n"
         << "of your choosing\n"
         << "- it's your letter.\n"
         << "Have you seen " << friend_name << " lately?\n";
    if (friend_sex == 'm')
        cout << "If you see " << friend_name << " please ask him to call me.\n";
    if (friend_sex == 'f')
        cout << "If you see " << friend_name << " please ask her to call me.\n";
    cout << "I hear you just had a birthday and you are " << recipient_age << " years old.\n";
    if (recipient_age < 12)
        cout << "Next year you will be " << ++recipient_age << ".\n";
    if (recipient_age == 17)
        cout << "Next year you will be able to vote.\n";
    if (recipient_age > 70)
        cout << "I hope you are enjoying retirement.\n";
    cout << "Yours sincerely, \n\nFynn";
}

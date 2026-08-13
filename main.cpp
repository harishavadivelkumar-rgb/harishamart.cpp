#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

// =====================================================
// USER CLASS
// =====================================================

class User
{
private:
    string username;
    string password;

public:

    // Default Constructor
    User()
    {
        username = "";
        password = "";
    }

    // Parameterized Constructor
    User(string name, string pass)
    {
        username = name;
        password = pass;
    }

    // =================================================
    // VALIDATE USER DETAILS
    // =================================================

    bool validateDetails()
    {
        if (username.length() < 3)
        {
            cout << "\nUsername must have at least 3 characters.\n";
            return false;
        }

        for (int i = 0; i < username.length(); i++)
        {
            if (!isalpha(username[i]))
            {
                cout << "\nUsername must contain letters only.\n";
                return false;
            }
        }

        if (password.length() < 6)
        {
            cout << "\nPassword must have at least 6 characters.\n";
            return false;
        }

        return true;
    }

    // =================================================
    // CHECK USERNAME
    // =================================================

    bool checkUsername()
    {
        ifstream file("users.txt");

        string name;
        string pass;

        while (file >> name >> pass)
        {
            if (name == username)
            {
                file.close();
                return true;
            }
        }

        file.close();
        return false;
    }

    // =================================================
    // REGISTER NEW USER
    // =================================================

    bool createAccount()
    {
        if (!validateDetails())
        {
            return false;
        }

        if (checkUsername())
        {
            cout << "\nUsername already exists!\n";
            return false;
        }

        ofstream file("users.txt", ios::app);

        if (!file)
        {
            cout << "\nUnable to access user database.\n";
            return false;
        }

        file << username << " " << password << endl;

        file.close();

        cout << "\n====================================\n";
        cout << "      ACCOUNT CREATED SUCCESSFULLY\n";
        cout << "====================================\n";

        return true;
    }

    // =================================================
    // LOGIN FUNCTION
    // =================================================

    bool authenticate()
    {
        ifstream file("users.txt");

        if (!file)
        {
            cout << "\nUser database is unavailable.\n";
            return false;
        }

        string savedName;
        string savedPassword;

        while (file >> savedName >> savedPassword)
        {
            if (savedName == username &&
                savedPassword == password)
            {
                file.close();

                cout << "\n====================================\n";
                cout << "          LOGIN SUCCESSFUL\n";
                cout << "====================================\n";
                cout << "Welcome, " << username
                     << " to HarishaMart!\n";

                return true;
            }
        }

        file.close();

        return false;
    }

    // =================================================
    // CHANGE PASSWORD MODULE
    // =================================================

    void changePassword()
    {
        string oldPassword;
        string newPassword;

        cout << "\n====================================\n";
        cout << "          CHANGE PASSWORD\n";
        cout << "====================================\n";

        cout << "Enter current password: ";
        cin >> oldPassword;

        if (oldPassword != password)
        {
            cout << "\nIncorrect current password!\n";
            return;
        }

        cout << "Enter new password: ";
        cin >> newPassword;

        if (newPassword.length() < 6)
        {
            cout << "\nNew password must contain at least 6 characters.\n";
            return;
        }

        ifstream input("users.txt");

        if (!input)
        {
            cout << "\nUnable to open user database.\n";
            return;
        }

        ofstream temp("temp.txt");

        string storedName;
        string storedPassword;

        while (input >> storedName >> storedPassword)
        {
            if (storedName == username)
            {
                temp << storedName << " "
                     << newPassword << endl;
            }
            else
            {
                temp << storedName << " "
                     << storedPassword << endl;
            }
        }

        input.close();
        temp.close();

        remove("users.txt");
        rename("temp.txt", "users.txt");

        password = newPassword;

        cout << "\nPassword changed successfully!\n";
    }

    // =================================================
    // PROFILE MODULE
    // =================================================

    void showProfile()
    {
        cout << "\n====================================\n";
        cout << "              PROFILE\n";
        cout << "====================================\n";

        cout << "Username       : " << username << endl;
        cout << "Account Status : Active" << endl;
        cout << "Website        : HarishaMart" << endl;

        cout << "====================================\n";
    }

    // =================================================
    // USER DASHBOARD
    // =================================================

    void dashboard()
    {
        int option;
        bool active = true;

        while (active)
        {
            cout << "\n====================================\n";
            cout << "          HARISHAMART ACCOUNT\n";
            cout << "====================================\n";

            cout << "Logged in as: " << username << "\n\n";

            cout << "1. View Profile\n";
            cout << "2. Change Password\n";
            cout << "3. Logout\n";

            cout << "\nEnter your choice: ";
            cin >> option;

            switch (option)
            {
                case 1:
                    showProfile();
                    break;

                case 2:
                    changePassword();
                    break;

                case 3:
                    cout << "\nLogout successful!\n";
                    cout << "Thank you for visiting HarishaMart.\n";
                    active = false;
                    break;

                default:
                    cout << "\nInvalid option! Please try again.\n";
            }
        }
    }
};

// =====================================================
// CREATE DEFAULT USER
// =====================================================

void initializeDatabase()
{
    ifstream file("users.txt");

    if (file)
    {
        string name;
        string pass;

        if (file >> name >> pass)
        {
            file.close();
            return;
        }

        file.close();
    }

    ofstream newFile("users.txt");

    if (!newFile)
    {
        cout << "\nUnable to create database.\n";
        return;
    }

    // Default account
    newFile << "admin admin123" << endl;

    newFile.close();
}

// =====================================================
// LOGIN MODULE
// =====================================================

bool loginProcess()
{
    string name;
    string pass;

    int attempts = 3;

    while (attempts > 0)
    {
        cout << "\n====================================\n";
        cout << "            HARISHAMART LOGIN\n";
        cout << "====================================\n";

        cout << "Username: ";
        cin >> name;

        cout << "Password: ";
        cin >> pass;

        User customer(name, pass);

        if (customer.authenticate())
        {
            customer.dashboard();
            return true;
        }

        attempts--;

        if (attempts > 0)
        {
            cout << "\nInvalid login details!";
            cout << "\nAttempts remaining: "
                 << attempts << endl;
        }
        else
        {
            cout << "\nToo many failed attempts.\n";
            cout << "Returning to main menu...\n";
        }
    }

    return false;
}

// =====================================================
// MAIN FUNCTION
// =====================================================

int main()
{
    initializeDatabase();

    int choice;

    do
    {
        cout << "\n====================================\n";
        cout << "          WELCOME TO HARISHAMART\n";
        cout << "====================================\n";

        cout << "1. Create Account\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
            // =========================================
            // CREATE ACCOUNT
            // =========================================

            case 1:
            {
                string name;
                string pass;

                cout << "\n====================================\n";
                cout << "          CREATE ACCOUNT\n";
                cout << "====================================\n";

                cout << "Enter username: ";
                cin >> name;

                cout << "Enter password: ";
                cin >> pass;

                User newUser(name, pass);

                newUser.createAccount();

                break;
            }

            // =========================================
            // LOGIN
            // =========================================

            case 2:
            {
                loginProcess();
                break;
            }

            // =========================================
            // EXIT
            // =========================================

            case 3:
            {
                cout << "\n====================================\n";
                cout << "       THANK YOU FOR USING\n";
                cout << "           HARISHAMART!\n";
                cout << "====================================\n";

                break;
            }

            // =========================================
            // INVALID OPTION
            // =========================================

            default:
            {
                cout << "\nInvalid choice!\n";
                cout << "Please select 1, 2 or 3.\n";
            }
        }

    } while (choice != 3);

    return 0;
}

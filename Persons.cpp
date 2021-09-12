#include "Persons.h"


void Persons::menu()
{
    //на тот случай если файла не существует, то создаётся новый пустой
    ifstream file(m_person_storage.c_str());
    if(!file.is_open())
    {
        ofstream new_empty_file(m_person_storage);
    }
    cout << "Please enter 1, 2 or 3:\n"
            "1) show data\n"
            "2) add new data\n"
            "3) quit\n";
    int choice;
    cin >> choice;
    while (choice != 3)
    {
        switch (choice)
        {
            case 1: this->read_file();
                break;
            case 2: this->add();
                break;
            default: cout << "You entered incorrect number\n";
        }
        cout << endl;
        cout << endl;
        cout << "Please enter 1, 2 or 3:\n"
                "1) show data\n"
                "2) add new data\n"
                "3) quit\n";
        cin >> choice;

    }
}

void Persons::read_file()
{
    char ch;
    ifstream fin(m_person_storage.c_str());
    if(fin.peek() == EOF)
    {
        cout << "Fail is empty\n";
    }
    else
    {
        while (!fin.eof())
        {
            ch = fin.get();
            cout << ch;
        }
    }
    fin.close();
}

void Persons::enter_name()
{
    cout << "Enter the name of the person: ";
    cin >> m_person.m_name;
}

void Persons::enter_gender()
{
    bool incorrect_data = false;
    cout << m_person.m_name << " is a man or a woman?\n";
    cout << "Enter the gender of " << m_person.m_name << ": ";
    string gender;
    cin >> gender;
    if(gender == "man" || gender == "woman")
    {
        m_person.m_gender = gender;
    }
    else
    {
        incorrect_data = true;
        while(incorrect_data)
        {
            cout << "Incorrect data\n";
            cout << "Enter \'man\' or \'woman\'\n";
            cout << "Enter the gender of " << m_person.m_name <<": ";
            cin >> gender;
            if(gender == "man" || gender == "woman")
            {
                incorrect_data = false;
                m_person.m_gender = gender;
            }
        }
    }
}

void Persons::enter_age()
{
    bool incorrect_data = false;
    int age = 0;
    cout << "Enter the age of "<< m_person.m_name <<" in years: ";

    cin >> age;
    if(age <= 0 || age > 100)
    {
        incorrect_data = true;
        while(incorrect_data)
        {
            cout << "Incorrect data\n";
            cout << "The age can't be more than 100 years or less than zero\n";
            cout << "Enter the age of "<< m_person.m_name <<": ";
            cin >> age;
            if(age > 0 && age <= 100)
            {
                incorrect_data = false;
                m_person.m_age = age;
            }
        }
    }
    else
    {
        m_person.m_age = age;
    }
}

void Persons::enter_height()
{
    bool incorrect_data = false;
    cout << "Enter the height of the " << m_person.m_name << " in centimeters: ";
    int height = 0;
    cin >> height;
    if(m_person.m_age == 1)
    {
        if(height < 51 || height > 76)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The height of the person in 1 year can't be less than 51 cm or more than 76 cm\n";
                 cout << "Enter the height of the person: ";
                 cin >> height;
                 if(height >= 51 && height <= 76)
                 {
                     incorrect_data = false;
                     m_person.m_height = height;
                 }
            }
        }
        else
        {
            m_person.m_height = height;
        }
    }
    else if(m_person.m_age > 1 && m_person.m_age <= 3)
    {
        if(height < 76 || height > 96)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The height of the person from 1 year to 3 years can't be less than 76 cm or more than 96 cm\n";
                 cout << "Enter the height of "<< m_person.m_name <<": ";
                 cin >> height;
                 if(height >= 76 && height <= 96)
                 {
                     incorrect_data = false;
                     m_person.m_height = height;
                 }
            }
        }
        else
        {
            m_person.m_height = height;
        }
    }
    else if(m_person.m_age > 3 && m_person.m_age <= 10)
    {
        if(height < 96 || height > 138)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The height of the person from 3 years to 10 years can't be less than 96 cm or more than 138 cm\n";
                 cout << "Enter the height of "<< m_person.m_name <<": ";
                 cin >> height;
                 if(height >= 96 && height <= 138)
                 {
                     incorrect_data = false;
                     m_person.m_height = height;
                 }
            }
        }
        else
        {
            m_person.m_height = height;
        }
    }
    else if(m_person.m_age > 10 && m_person.m_age <= 15)
    {
        if(height < 138 || height > 167)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The height of the person from 10 years to 15 years can't be less than 138 cm or more than 167 cm\n";
                 cout << "Enter the height of the " << m_person.m_name << ": ";
                 cin >> height;
                 if(height >= 138 && height <= 167)
                 {
                     incorrect_data = false;
                     m_person.m_height = height;
                 }
            }
        }
        else
        {
            m_person.m_height = height;
        }
    }
    else if(m_person.m_age > 15 && m_person.m_age <= 17)
    {
        if(height < 150 || height > 177)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The height of the person from 15 years to 17 years can't be less than 150 cm or more than 177 cm\n";
                 cout << "Enter the height of the " << m_person.m_name << ": ";
                 cin >> height;
                 if(height >= 150 && height <= 177)
                 {
                     incorrect_data = false;
                     m_person.m_height = height;
                 }
            }
        }
        else
        {
            m_person.m_height = height;
        }
    }
    else if(m_person.m_age > 17 && m_person.m_age <= 100)
    {
        if(height < 150 || height > 200)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The height of the person from 17 years to 100 years can't be less than 150 cm or more than 200 cm\n";
                 cout << "Enter the height of the " << m_person.m_name << ": ";
                 cin >> height;
                 if(height >= 150 && height <= 200)
                 {
                     incorrect_data = false;
                     m_person.m_height = height;
                 }
            }
        }
        else
        {
            m_person.m_height = height;
        }
    }

}

void Persons::enter_weight()
{
    bool incorrect_data = false;
    cout << "Enter the weight of " << m_person.m_name << " in kilograms: ";
    int weight;
    cin >> weight;
    if(m_person.m_age == 1)
    {
        if(weight < 4 || weight > 10)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "Incorrect data\n";
                cout << "The weight can't of the person in 1 year can't be less than 4 kg or more than 10 kg\n";
                cout << "Enter the weight of " << m_person.m_name << ": ";
                cin >> weight;
                if(weight >= 4 && weight <= 10)
                {
                    incorrect_data = false;
                    m_person.m_weight = weight;
                }
            }
        }
        else
        {
            m_person.m_weight = weight;
        }

    }
    else if(m_person.m_age > 1 && m_person.m_age <= 3)
    {
        if(weight < 10 || weight > 15)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The weight of the person from 1 year to 3 years can't be less than 10 kg or more than 15 kg\n";
                 cout << "Enter the weight of " << m_person.m_name << ": ";
                 cin >> weight;
                 if(weight >= 10 && weight <= 15)
                 {
                     incorrect_data = false;
                     m_person.m_weight = weight;
                 }
            }
        }
        else
        {
            m_person.m_weight = weight;
        }
    }
    else if(m_person.m_age > 3 && m_person.m_age <= 10)
    {
        if(weight < 15 || weight > 31)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The weight of the person from 3 years to 10 years can't be less than 15 kg or more than 31 kg\n";
                 cout << "Enter the weight of " << m_person.m_name << ": ";;
                 cin >> weight;
                 if(weight >= 15 && weight <= 31)
                 {
                     incorrect_data = false;
                     m_person.m_weight = weight;
                 }
            }
        }
        else
        {
            m_person.m_weight = weight;
        }
    }
    else if(m_person.m_age > 10 && m_person.m_age <= 15)
    {
        if(weight < 31 || weight > 55)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The weight of the person from 10 years to 15 years can't be less than 31 kg or more than 55 kg\n";
                 cout << "Enter the weight of " << m_person.m_name << ": ";
                 cin >> weight;
                 if(weight >= 31 && weight <= 55)
                 {
                     incorrect_data = false;
                     m_person.m_weight = weight;
                 }
            }
        }
        else
        {
            m_person.m_weight = weight;
        }
    }
    else if(m_person.m_age > 15 && m_person.m_age <= 17)
    {
        if(weight < 55 || weight > 66)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The weight of the person from 15 years to 17 years can't be less than 55 kg or more than 66 kg\n";
                 cout << "Enter the weight of " << m_person.m_name << ": ";
                 cin >> weight;
                 if(weight >= 55 && weight <= 66)
                 {
                     incorrect_data = false;
                     m_person.m_weight = weight;
                 }
            }
        }
        else
        {
            m_person.m_weight = weight;
        }
    }
    else if(m_person.m_age > 17 && m_person.m_age <= 100)
    {
        if(weight < 55 || weight > 100)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                 cout << "Incorrect data\n";
                 cout << "The weight of the person from 17 years to 100 years can't be less than 55 kg or more than 100 kg\n";
                 cout << "Enter the weight of " << m_person.m_name << ": ";
                 cin >> weight;
                 if(weight >= 55 && weight <= 100)
                 {
                     incorrect_data = false;
                     m_person.m_weight = weight;
                 }
            }
        }
        else
        {
            m_person.m_weight = weight;
        }
    }
}

void Persons::enter_nationality()
{
    bool incorrect_data = false;
    cout << "Choose the nationality of " << m_person.m_name << " from the list:\n";
    for(unsigned i = 0; i < m_person.m_nationality.size(); i++)
    {
        cout << i << ") " + m_person.m_nationality.at(i) << endl;
    }
    unsigned choice = 0;
    cout << "Your choice: ";
    cin >> choice;
    if(choice >= m_person.m_nationality.size() || int(choice) < 0)
    {
        incorrect_data = true;
        while(incorrect_data)
        {
            cout << "Incorrect choice\n";
            cout << "The nationality must be from 0" << " to " << m_person.m_nationality.size() - 1 << endl;
            cout << "Choose the nationality of " << m_person.m_name << " from the list: ";
            cin >> choice;
            if(int(choice) >= 0 || choice < m_person.m_nationality.size())
            {
                incorrect_data = false;
                m_person.m_choice_nationality = m_person.m_nationality.at(choice);
            }
        }
    }
    else
    {
        m_person.m_choice_nationality = m_person.m_nationality.at(choice);
    }
}

void Persons::enter_the_date_of_birthday()
{
    time_t t2;
    time(&t2);
    tm *t1 = localtime(&t2);

    //int cur_day = t1->tm_mday;
    int cur_month = t1->tm_mon + 1;
    int cur_year  = t1->tm_year + 1900;

    bool incorrect_data = false;
    int year_of_birth = 0;
    cout << "Enter the year of birth: ";
    cin >> year_of_birth;

    if(year_of_birth < 0 || year_of_birth > cur_year)
    {
        incorrect_data = true;
        while(incorrect_data)
        {
            cout << "Enter the year from 0 to " << cur_year << endl;
            cout << "Enter the year of birth: ";
            cin >> year_of_birth;
            if(year_of_birth >= 0 || year_of_birth <= cur_year)
            {
                incorrect_data = false;
                m_person.m_year_of_birth = year_of_birth;
            }
        }
    }
    else
    {
        m_person.m_year_of_birth = year_of_birth;
    }

    int month_of_birth = 0;
    int possible_year_of_birth = cur_year - m_person.m_age;

    if(possible_year_of_birth == m_person.m_year_of_birth)
    {
        cout << "Enter the month of birth (number from 1 to " << cur_month <<"): ";
        cin >> month_of_birth;
        if(month_of_birth < 1 || month_of_birth > cur_month)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "The month of birth can't be less than 1 or more than " <<  cur_month <<"\n";
                cout << "Enter the month of birth: ";
                cin >> month_of_birth;
                if(month_of_birth >= 1 && month_of_birth <= cur_month)
                {
                    incorrect_data = false;
                    m_person.m_month_of_birth = month_of_birth;
                }
            }
        }
        else
        {
            m_person.m_month_of_birth = month_of_birth;
        }
    }
    else
    {
        cout << "Enter the month of birth (number from 1 to 12): ";
        cin >> month_of_birth;
        if(month_of_birth < 1 || month_of_birth > 12)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "The month of birth can't be less than 1 or more than 12: ";
                cout << "Enter the month of birth: ";
                cin >> month_of_birth;
                if(month_of_birth >= 1 && month_of_birth <= 12)
                {
                    incorrect_data = false;
                    m_person.m_month_of_birth = month_of_birth;
                }
            }
        }
        else
        {
            m_person.m_month_of_birth = month_of_birth;
        }
    }

    int day_of_birth = 0;

    cout << "Enter the day of birth: ";
    cin >> day_of_birth;
    auto _31day = [&]()
    {
        if(day_of_birth < 1 || day_of_birth > 31)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "There are 31 days in " << m_person.m_month_of_birth << "th month\n";
                cout << "Enter the day of birth: ";
                cin >> day_of_birth;
                if(day_of_birth >= 1 && day_of_birth <= 31)
                {
                    incorrect_data = false;
                }
            }
            return day_of_birth;
        }
        else
        {
            return day_of_birth;
        }
    };
    auto _28day = [&]()
    {
        if(day_of_birth < 1 || day_of_birth > 28)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "There are 28 days in " << m_person.m_month_of_birth << "th month\n";
                cout << "Enter the day of birth: ";
                cin >> day_of_birth;
                if(day_of_birth >= 1 && day_of_birth <= 28)
                {
                    incorrect_data = false;
                }
            }
            return day_of_birth;
        }
        else
        {
            return day_of_birth;
        }
    };
    auto _30day = [&]()
    {
        if(day_of_birth < 1 || day_of_birth > 28)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "There are 30 days in " << m_person.m_month_of_birth << "th month\n";
                cout << "Enter the day of birth: ";
                cin >> day_of_birth;
                if(day_of_birth >= 1 && day_of_birth <= 30)
                {
                    incorrect_data = false;
                }
            }
            return day_of_birth;
        }
        else
        {
            return day_of_birth;
        }
    };
    switch (m_person.m_month_of_birth)
    {
        case 1: m_person.m_day_of_birth = _31day();
            break;
        case 2: m_person.m_day_of_birth = _28day();
            break;
        case 3: m_person.m_day_of_birth = _31day();
            break;
        case 4: m_person.m_day_of_birth = _30day();
            break;
        case 5: m_person.m_day_of_birth = _31day();
            break;
        case 6: m_person.m_day_of_birth = _30day();
            break;
        case 7: m_person.m_day_of_birth = _31day();
            break;
        case 8: m_person.m_day_of_birth = _31day();
            break;
        case 9: m_person.m_day_of_birth = _30day();
            break;
        case 10: m_person.m_day_of_birth = _31day();
            break;
        case 11: m_person.m_day_of_birth = _30day();
            break;
        case 12: m_person.m_day_of_birth = _31day();
            break;
    }
}

void Persons::enter_the_date_of_death()
{


    bool person_is_alive = the_person_is_alive();
    bool incorrect_data = false;
    if(!person_is_alive)
    {
        the_person_is_dead();
    }
    else
    {
        cout << "Choose \'1\' or \'2\':\n";
        cout << "1 - " << m_person.m_name << " is dead\n";
        cout << "2 - " << m_person.m_name << " is alive\n";
        int choice;
        cin >> choice;
        if(choice < 1 || choice > 2)
        {
            incorrect_data = true;
            while (incorrect_data)
            {
                cout << "Incorrect data\n";
                cout << "Your choice must be \'1\' or \'2\': ";
                cin >> choice;
                if(choice == 1)
                {
                    incorrect_data = false;
                    the_person_is_dead();
                }
                else if(choice == 2 && person_is_alive)
                {
                    incorrect_data = false;
                }
                else if(choice == 2 && !person_is_alive)
                {
                    cout <<  m_person.m_name << " can't be alive (or live more than 100 years), please choose \'1\': ";
                    cin >> choice;
                    if(choice == 1)
                    {
                        incorrect_data = false;
                        the_person_is_dead();
                    }
                }
            }
        }
        else
        {
            if(choice == 1)
            {
                the_person_is_dead();
            }
            else if(choice == 2 && person_is_alive)
            {
                incorrect_data = false;
            }
            else if(choice == 2 && !person_is_alive)
            {
                cout << m_person.m_name << " can't live more than 100 years, please choose \'1\': ";
                cin >> choice;
                if(choice == 1)
                {
                    incorrect_data = false;
                    the_person_is_dead();
                }
            }
        }
    }

}

void Persons::the_person_is_dead()
{
    time_t t2;
    time(&t2);
    tm *t1 = localtime(&t2);
    //int cur_day   = t1->tm_mday;

    int cur_month = t1->tm_mon + 1;
    int cur_year  = t1->tm_year + 1900;

    bool incorrect_data = false;
    int possible_year_of_death = m_person.m_year_of_birth + m_person.m_age;
    int year_of_death = 0;
    cout << "Enter the year of death: ";
    cin >> year_of_death;
    if(year_of_death == possible_year_of_death || year_of_death == possible_year_of_death + 1)
    {
        m_person.m_year_of_death = year_of_death;
    }
    else
    {
        incorrect_data = true;
        while (incorrect_data)
        {
            cout << "Maybe " << m_person.m_name << " died in " << possible_year_of_death << "?\n";
            cout << "Enter the year of death: ";
            cin >> year_of_death;
            if(year_of_death == possible_year_of_death || year_of_death == possible_year_of_death + 1)
            {
                incorrect_data = false;
                m_person.m_year_of_death = year_of_death;
            }
        }
    }

    int month_of_death = 0;

    if(m_person.m_year_of_death == cur_year)
    {
        cout << "Enter the month of dead from " << m_person.m_month_of_birth << " to " << cur_month <<": ";
        cin >> month_of_death;
        if(month_of_death < m_person.m_month_of_birth || month_of_death > cur_month)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "Enter the month from " << m_person.m_month_of_birth << " to " << cur_month <<": ";
                cin >> month_of_death;
                if(month_of_death >= m_person.m_month_of_death && month_of_death <= cur_month)
                {
                    incorrect_data = true;
                    m_person.m_month_of_death = month_of_death;
                }
            }
        }
        else
        {
            m_person.m_month_of_death = month_of_death;
        }
    }
    else if(possible_year_of_death == m_person.m_year_of_death)
    {
        cout << "Enter the month of dead from " << m_person.m_month_of_birth << " to 12: ";
        cin >> month_of_death;
        if(month_of_death < m_person.m_month_of_birth || month_of_death > 12)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "Enter the month from " << m_person.m_month_of_birth << " to 12: ";
                cin >> month_of_death;
                if(month_of_death >= m_person.m_month_of_death && month_of_death <= 12)
                {
                    incorrect_data = true;
                    m_person.m_month_of_death = month_of_death;
                }
            }
        }
        else
        {
            m_person.m_month_of_death = month_of_death;
        }
    }
    else if(possible_year_of_death == possible_year_of_death + 1)
    {
        cout << "Enter the month from 1 " << m_person.m_month_of_birth << endl;
        cin >> month_of_death;
        if(month_of_death < 1 || month_of_death > m_person.m_month_of_birth)
        {
            incorrect_data = true;
            while(incorrect_data)
            {
                cout << "Enter the month from 1 " << m_person.m_month_of_birth << endl;
                cin >> month_of_death;
                if(month_of_death >= 1 && month_of_death <= m_person.m_month_of_birth)
                {
                    incorrect_data = true;
                    m_person.m_month_of_death = month_of_death;
                }
            }
        }
        else
        {
            m_person.m_month_of_death = month_of_death;
        }
    }

    int day_of_death = 0;
    cout << "Enter the day of death: ";
    cin >> day_of_death;
    if(m_person.m_month_of_death == m_person.m_month_of_birth)
    {
        auto _31day = [&]()
        {
            if(m_person.m_age == possible_year_of_death - m_person.m_year_of_birth)
            {

                if(day_of_death < m_person.m_day_of_birth  || day_of_death > 31)
                {
                    incorrect_data = true;
                    while(incorrect_data)
                    {
                        cout << "Maybe " << m_person.m_name << " died in the period from " << m_person.m_day_of_birth << " to 31\n";
                        cout << "Enter the day of death: ";
                        cin >> day_of_death;
                        if(day_of_death >= m_person.m_day_of_death && day_of_death <= 31)
                        {
                            incorrect_data = false;
                        }
                    }
                    return day_of_death;
                }
                else
                {
                    return day_of_death;
                }
            }
            else
            {
                if(day_of_death < 1  || day_of_death >= m_person.m_year_of_birth)
                {
                    incorrect_data = true;
                    while(incorrect_data)
                    {
                        cout << "Maybe " << m_person.m_name << " died in the period from " << 1 << " to " << m_person.m_day_of_birth - 1;
                        cout << "Enter the day of death: ";
                        cin >> day_of_death;
                        if(day_of_death >= 1 && day_of_death < m_person.m_day_of_birth - 1)
                        {
                            incorrect_data = false;
                        }
                    }
                    return day_of_death;
                }
                else
                {
                    return day_of_death;
                }
            }
        };
        auto _28day = [&]()
        {
            if(m_person.m_age == possible_year_of_death - m_person.m_year_of_birth)
            {

                if(day_of_death < m_person.m_day_of_birth  || day_of_death > 28)
                {
                    incorrect_data = true;
                    while(incorrect_data)
                    {
                        cout << "Maybe " << m_person.m_name << " died in the period from " << m_person.m_day_of_birth << " to 31\n";
                        cout << "Enter the day of death: ";
                        cin >> day_of_death;
                        if(day_of_death >= m_person.m_day_of_death && day_of_death <= 28)
                        {
                            incorrect_data = false;
                        }
                    }
                    return day_of_death;
                }
                else
                {
                    return day_of_death;
                }
            }
            else
            {
                if(day_of_death < 1  || day_of_death >= m_person.m_year_of_birth)
                {
                    incorrect_data = true;
                    while(incorrect_data)
                    {
                        cout << "Maybe " << m_person.m_name << " died in the period from " << 1 << " to " << m_person.m_day_of_birth - 1;
                        cout << "Enter the day of death: ";
                        cin >> day_of_death;
                        if(day_of_death >= 1 && day_of_death < m_person.m_day_of_birth - 1)
                        {
                            incorrect_data = false;
                        }
                    }
                    return day_of_death;
                }
                else
                {
                    return day_of_death;
                }
            }
        };
        auto _30day = [&]()
        {
            if(m_person.m_age == possible_year_of_death - m_person.m_year_of_birth)
            {

                if(day_of_death < m_person.m_day_of_birth  || day_of_death > 30)
                {
                    incorrect_data = true;
                    while(incorrect_data)
                    {
                        cout << "Maybe " << m_person.m_name << " died in the period from " << m_person.m_day_of_birth << " to 31\n";
                        cout << "Enter the day of death: ";
                        cin >> day_of_death;
                        if(day_of_death >= m_person.m_day_of_death && day_of_death <= 30)
                        {
                            incorrect_data = false;
                        }
                    }
                    return day_of_death;
                }
                else
                {
                    return day_of_death;
                }
            }
            else
            {
                if(day_of_death < 1  || day_of_death >= m_person.m_year_of_birth)
                {
                    incorrect_data = true;
                    while(incorrect_data)
                    {
                        cout << "Maybe " << m_person.m_name << " died in the period from " << 1 << " to " << m_person.m_day_of_birth - 1;
                        cout << "Enter the day of death: ";
                        cin >> day_of_death;
                        if(day_of_death >= 1 && day_of_death < m_person.m_day_of_birth - 1)
                        {
                            incorrect_data = false;
                        }
                    }
                    return day_of_death;
                }
                else
                {
                    return day_of_death;
                }
            }
        };
        switch (m_person.m_month_of_birth)
        {
            case 1: m_person.m_day_of_death = _31day();
                break;
            case 2: m_person.m_day_of_death = _28day();
                break;
            case 3: m_person.m_day_of_death = _31day();
                break;
            case 4: m_person.m_day_of_death = _30day();
                break;
            case 5: m_person.m_day_of_death = _31day();
                break;
            case 6: m_person.m_day_of_death = _30day();
                break;
            case 7: m_person.m_day_of_death = _31day();
                break;
            case 8: m_person.m_day_of_death = _31day();
                break;
            case 9: m_person.m_day_of_death = _30day();
                break;
            case 10: m_person.m_day_of_death = _31day();
                break;
            case 11: m_person.m_day_of_death = _30day();
                break;
            case 12: m_person.m_day_of_death = _31day();
                break;
        }
    }
    else
    {
        auto _31day = [&]()
        {
            if(day_of_death < 1 || day_of_death > 31)
            {
                incorrect_data = true;
                while(incorrect_data)
                {
                    cout << "There are 31 days in " << m_person.m_month_of_death << "th month\n";
                    cout << "Enter the day of birth: ";
                    cin >> day_of_death;
                    if(day_of_death >= 1 && day_of_death <= 31)
                    {
                        incorrect_data = false;
                    }
                }
                return day_of_death;
            }
            else
            {
                return day_of_death;
            }
        };
        auto _28day = [&]()
        {
            if(day_of_death < 1 || day_of_death > 28)
            {
                incorrect_data = true;
                while(incorrect_data)
                {
                    cout << "There are 28 days in " << m_person.m_month_of_death << "th month\n";
                    cout << "Enter the day of birth: ";
                    cin >> day_of_death;
                    if(day_of_death >= 1 && day_of_death <= 28)
                    {
                        incorrect_data = false;
                    }
                }
                return day_of_death;
            }
            else
            {
                return day_of_death;
            }
        };
        auto _30day = [&]()
        {
            if(day_of_death < 1 || day_of_death > 28)
            {
                incorrect_data = true;
                while(incorrect_data)
                {
                    cout << "There are 30 days in " << m_person.m_month_of_death << "th month\n";
                    cout << "Enter the day of birth: ";
                    cin >> day_of_death;
                    if(day_of_death >= 1 && day_of_death <= 30)
                    {
                        incorrect_data = false;
                    }
                }
                return day_of_death;
            }
            else
            {
                return day_of_death;
            }
        };
        switch (m_person.m_month_of_death)
        {
            case 1: m_person.m_day_of_death = _31day();
                break;
            case 2: m_person.m_day_of_death = _28day();
                break;
            case 3: m_person.m_day_of_death = _31day();
                break;
            case 4: m_person.m_day_of_death = _30day();
                break;
            case 5: m_person.m_day_of_death = _31day();
                break;
            case 6: m_person.m_day_of_death = _30day();
                break;
            case 7: m_person.m_day_of_death = _31day();
                break;
            case 8: m_person.m_day_of_death = _31day();
                break;
            case 9: m_person.m_day_of_death = _30day();
                break;
            case 10: m_person.m_day_of_death = _31day();
                break;
            case 11: m_person.m_day_of_death = _30day();
                break;
            case 12: m_person.m_day_of_death = _31day();
                break;
        }
    }


}

bool Persons::the_person_is_alive()
{
    time_t t2;
    time(&t2);
    tm *t1 = localtime(&t2);

    int cur_day   = t1->tm_mday;
    int cur_month = t1->tm_mon + 1;
    int cur_year  = t1->tm_year + 1900;
    bool person_is_alive = false;
    int dif_from_the_cur_year = cur_year - m_person.m_year_of_birth;
    if(dif_from_the_cur_year <= 101)
    {
        if(dif_from_the_cur_year == 101)
        {

            if(cur_month < m_person.m_month_of_birth)
            {
                person_is_alive = true;
                return person_is_alive;
            }
            else if(cur_month == m_person.m_month_of_birth)
            {
                if(cur_day < m_person.m_day_of_birth)
                {
                    person_is_alive = true;
                    return person_is_alive;
                }
                else if(cur_day >= m_person.m_day_of_birth)
                {
                    return person_is_alive;
                }
            }
            else if(cur_month > m_person.m_month_of_birth)
            {
                return person_is_alive;
            }
        }
        else if(dif_from_the_cur_year == m_person.m_age + 1)
        {
            person_is_alive = true;
            return person_is_alive;
        }
        else if(dif_from_the_cur_year == m_person.m_age)
        {
            person_is_alive = true;
            return person_is_alive;
        }
    }
    return person_is_alive;
}

void Persons::add()
{
    enter_name();

    enter_gender();

    enter_age();

    enter_height();

    enter_weight();

    enter_nationality();

    enter_the_date_of_birthday();

    enter_the_date_of_death();

    create_content_of_file();

    write_file();
}

void Persons::create_content_of_file()
{
    string temp;
    temp = m_person.m_name;
    temp.insert(0, "[");
    temp.push_back(']');
    temp.push_back('\n');
    m_temp_container.push_back(temp);
    temp.clear();

    temp = m_person.m_gender;
    temp.insert(0, "=");
    temp.insert(0, "gender");
    temp.push_back('\n');
    m_temp_container.push_back(temp);
    temp.clear();

    temp = to_string(m_person.m_age);
    temp.insert(0, "=");
    temp.insert(0, "age");
    temp.push_back('\n');
    m_temp_container.push_back(temp);
    temp.clear();

    temp = to_string(m_person.m_height);
    temp.insert(0, "=");
    temp.insert(0, "height");
    temp.push_back('\n');
    m_temp_container.push_back(temp);
    temp.clear();

    temp = to_string(m_person.m_weight);
    temp.insert(0, "=");
    temp.insert(0, "weight");
    temp.push_back('\n');
    m_temp_container.push_back(temp);
    temp.clear();

    temp = m_person.m_choice_nationality;
    temp.insert(0, "=");
    temp.insert(0, "nationality");
    temp.push_back('\n');
    m_temp_container.push_back(temp);
    temp.clear();

    temp = to_string(m_person.m_day_of_birth);
    temp.push_back('.');
    temp = temp + to_string(m_person.m_month_of_birth);
    temp.push_back('.');
    temp = temp + to_string(m_person.m_year_of_birth);
    temp.insert(0, "=");
    temp.insert(0, "date_of_birthday");
    temp.push_back('\n');
    m_temp_container.push_back(temp);
    temp.clear();

    if(m_person.m_year_of_death == 0)
    {
        temp.push_back('-');
        temp.insert(0, "=");
        temp.insert(0, "date_of_death");
        temp.push_back('\n');
        m_temp_container.push_back(temp);
        temp.clear();
    }
    else
    {
        temp = to_string(m_person.m_day_of_death);
        temp.push_back('.');
        temp = temp + to_string(m_person.m_month_of_death);
        temp.push_back('.');
        temp = temp + to_string(m_person.m_year_of_death);
        temp.insert(0, "=");
        temp.insert(0, "date_of_death");
        temp.push_back('\n');
        m_temp_container.push_back(temp);
        temp.clear();
    }

}

void Persons::write_file()
{
    ofstream fout(m_person_storage.c_str(), ios_base::out | ios_base::app);
    char ch;
    for(unsigned i = 0; i < m_temp_container.size(); i++)
    {
        for(unsigned j = 0; j < m_temp_container.at(i).size(); j++)
        {
            if(m_temp_container.at(i).at(j) == '\0')
            {
                continue;
            }
            else
            {
                ch = m_temp_container.at(i).at(j);
                fout << ch;
            }
        }
    }
    m_temp_container.clear();
}























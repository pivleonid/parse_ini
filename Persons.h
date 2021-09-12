#ifndef PERSONS_H
#define PERSONS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <time.h>
#include <functional>
using namespace std;
/*!
 * \brief The Content_of_section class - в объекте класса хранится описание конкретного человека
 */
struct Content_of_section
{
    string m_name    = "empty string";
    string m_gender  = "empty string";
    int m_age        = 0;
    int m_height     = 0;
    int m_weight     = 0;
    string m_choice_nationality = "empty string";
    int m_day_of_birth   = 0;
    int m_month_of_birth = 0;
    int m_year_of_birth  = 0;
    int m_day_of_death   = 0;
    int m_month_of_death = 0;
    int m_year_of_death  = 0;

    vector<string> m_nationality = {"Russian", "American", "Indian", "Chinese", "French", "German", "African", "Japanese", "Englishman", "Canadian"};

};

class Persons
{
public:
    /*
      menu  - предоставляет меню для выбора действия: посмотреть содержимое файла,
                                                      добавить новые данные,
                                                      выйти из программы.
                                                      Если файл для чтения отсутсвует, то создаёт пустой.
     */
    void menu();
private:
    string m_person_storage = "person_storage.ini";

    Content_of_section m_person;

    //m_temp_container - контейнер хранит контент для файла
    vector<string> m_temp_container;

    //reate_content_of_file - создаёт контент для файла, путём заполнения объекта vector<string> m_temp_container
    void create_content_of_file();
    void read_file();
    //получает данные из командной строки для функции create_content_of_file()
    void add();
    //получает имя человека введённое в командной строке
    void enter_name();
    //получает пол человека введённый в командной строке
    void enter_gender();
    //получает возраст человека введённый в командной строке
    void enter_age();
    //получает рост человека введённый в командной строке
    void enter_height();
    //получает вес человека введённый в командной строке
    void enter_weight();
    //получает национальность человека введённую в командной строке
    void enter_nationality();
    //получает дату рождения человека введённую в командной строке
    void enter_the_date_of_birthday();
    //получает дату смерти человека введённую в командной строке
    void enter_the_date_of_death();

    void the_person_is_dead();
    //проверяет может ли человек быть живым на данный момент true-жив, false-нет
    bool the_person_is_alive();

    //записывает данные из объекта vector<string> m_temp_container в файл "m_person_storage.ini"
    void write_file();
};

#endif // PERSONS_H

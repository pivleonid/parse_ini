#include "CVector.h"
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

CVector::CVector()
{
    storage_words = NULL;
    capacity_storage = 0;
    adress_words = NULL;
    capacity_adress = 0;
}

void CVector::push(const CString &str)
{
    //увеличить ёмкость
    capacity_storage += str.m_size;

    //если вектор пуст
    if(storage_words == NULL)
    {
        //записываем данные
        char *temp = new char[capacity_storage];
        for(int i = 0; i < str.m_size - 1; i++)
        {
            temp[i] = str.m_word[i];
        }
        temp[str.m_size - 1] = ' ';
        //записываем позицию слова в storage_words
        adress_words = new int[1];
        adress_words[0] = capacity_adress;
        capacity_adress++;

        storage_words = temp;
    }

    else if(storage_words != NULL)
    {
        //записываем данные старого массива
        char *temp0 = new char[capacity_storage];
        for(int i = 0; i < capacity_storage - str.m_size; i++)
        {
            temp0[i] = storage_words[i];
        }

        //добавляем новые
        for(int i = capacity_storage - str.m_size, j = 0; i < capacity_storage - 1; i++, j++)
        {
            temp0[i] = str.m_word[j];
        }
        temp0[capacity_storage - 1] = ' ';
        //записываем данные старого массива для хранения позиций
        capacity_adress++;
        int *temp1 = new int[capacity_adress];
        for(int i = 0; i < capacity_adress - 1; i++)
        {
            temp1[i] = adress_words[i];
        }

        //добавляем позицию нового слова
        temp1[capacity_adress] = capacity_storage - str.m_size;

        delete [] storage_words;
        delete [] adress_words;

        storage_words = temp0;
        adress_words = temp1;


    }
}

int CVector::size_vector()
{
    return capacity_storage;
}

void CVector::push(const char *new_word, int index)
{
    //если добавляем в конец вектора
    if(index == capacity_storage)
    {
        //определяем размер добавляемого слова
        const char *temp0 = new_word;
        int append_size = 0;
        while (*temp0++)
        {
            append_size++;
        }

        //увеличиваем размер вектора на величину добавляемого слова
        capacity_storage += append_size + 1;

        //записываем данные старого массива
        char *temp1 = new char[capacity_storage];
        for(int i = 0; i < capacity_storage - append_size - 1; i++)
        {
            temp1[i] = storage_words[i];
        }
        temp1[capacity_storage - append_size - 1] = ' ';

        //добавляем новые
        for(int i = capacity_storage - append_size, j = 0; i < capacity_storage; i++, j++)
        {
            temp1[i] = new_word[j];
        }

        //записываем данные старого массива для хранения позиций
        capacity_adress++;
        int *temp2 = new int[capacity_adress];
        for(int i = 0; i < capacity_adress - 1; i++)
        {
            temp2[i] = adress_words[i];
        }

        //добавляем позицию нового слова
        temp2[capacity_adress] = capacity_storage - append_size;

        delete [] storage_words;
        delete [] adress_words;

        storage_words = temp1;
        adress_words = temp2;
    }

    else if (index >= 0 && index < capacity_storage - 1)
    {
        //определяем размер добавляемого слова
        const char *temp0 = new_word;
        int append_size = 0;
        while (*temp0++)
        {
            append_size++;
        }

        //увеличиваем размер вектора на величину добавляемого слова
        capacity_storage += append_size + 1;

        //записываем данные старого массива до добавляемого слова
        char *temp1 = new char[capacity_storage];
        for(int i = 0; i < adress_words[index]; i++)
        {
            temp1[i] = storage_words[i];
        }

        //добавляем новое слово
        for(int i = adress_words[index], j = 0; i < adress_words[index] + append_size + 1; i++, j++)
        {
            temp1[i] = new_word[j];
        }

        //добавляем в конец пробел для разделения слов
        temp1[adress_words[index] + append_size + 1] = ' ';

        //добавляем оставшуюсь часть массива
        for(int i = adress_words[index] + append_size + 2, j = adress_words[index]; j < capacity_storage - append_size; i++, j++)
        {
            temp1[i] = storage_words[j];
        }

        //записываем до index старый adress_words
        int *temp2 = new int[capacity_adress];

        for(int i = 0; i < index + 1; i++)
        {
            temp2[i] = adress_words[i];
        }

        //с index увеличиваем остальные позиции на append_size+1
        for(int i = index + 1; i < capacity_adress; i++)
        {
            temp2[i] = adress_words[i] + append_size + 1;
        }

        delete [] storage_words;
        delete [] adress_words;

        storage_words = temp1;
        adress_words = temp2;
    }

    //если введён индекс вне диапазона вектора
    else if(index < 0 || index > capacity_storage)
    {
        cout << "Enter the index from 0 to " << capacity_storage << " !" << endl;
    }
}




















#include <iostream>
#include <string>

/*Функция по поиску и замене слова.
В качестве параметров принимает исходный текст(переменная text), 
слово которое требуется заменить(переменная search_word),
слово на которое на которое будем менять (переменная change_word)*/
void Word_replacement(std::string& text, const std::string& search_word, const std::string& change_word);

int main()
{
    setlocale(LC_CTYPE, "rus");

    std::string text_a= "Жизнь прежде всего творчество, но это не значит, что каждый человек, чтобы жить, должен родиться художником, балериной или ученым.";
    //Слово ,которое будем менять 
    std::string seach{ "художником" };
    //Слово , на  которое будем менять 
    std::string change{ "музыкантом" };
    
    Word_replacement(text_a, seach,change);
    //Вывод результата
    std::cout << text_a << std::endl;

    system("pause"); 
    return 0;
}

void Word_replacement(std::string& text, const std::string& search_word, const std::string& change_word)
{
    //Временная переменная для хранения слов
    std::string temp;
    //Переменная для изменённый текст
    std::string new_text;
    //Считываем текст по символьно 
    for (auto ch : text)
    {
        
        if (ch==',' || ch=='.' || ch==' ')
        {
           //Ищем нужное слово для замены
            if (temp== search_word)
            {
                //Если находим меняем 
                new_text += change_word +ch;
            }
            else
            {
                //Иначе добавляем слово в текст
                new_text += temp + ch;
            }
            temp.clear();
        }
        else
        {
            //Запись слов 
            temp += ch;
        }
    }
    //Записываем изменённый текст 
    text = new_text;
}

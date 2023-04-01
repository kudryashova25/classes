#include <iostream>
#include <string>
#include <clocale>
#include <regex> 
#include <ctime>
#include <time.h>

//#define DEBUG_FLG

using namespace std;

//абстракный, фундамеет	   //Источник:calmsen.ru/funkcziya-isalpha/
class Library {

private:
	string Name;          //название библиотеки	
	string  Id;          //id vk библиотеки	
	int Kolvo;          //количество читателей библиотеки	

public:
	string getName() {
		return Name;
	};
	int setName(string test_name) {
		int error_code_Name{ 0 };
		smatch m;
		if (!regex_search(test_name, m, regex(" {1,}"))) {   // если регулярное выражение от 1 до бесконечности, то
			error_code_Name = 0;                               //то код ошибки = 0, иначе
		}
		else {
			error_code_Name = -1;                               // иначе = - 1
		};
		if (!regex_search(test_name, m, regex("[0-9]")) && error_code_Name == 0) {
			error_code_Name = 0;
		}
		else {
			error_code_Name = -1;
		};
		if (error_code_Name == 0) {
			Name = test_name;
		}
		return error_code_Name;
	};
	// доделай id, создай шаблон
	string getId() {
		return Id;
	};

#ifdef DEBUG_FLG
	int setId(int test_id) {
		int error_code_Id;
		if (test_id > 0) {
			Id = test_id;
			error_code_Id = 0;
		}
		else {
			error_code_Id = -1;
		}
		return error_code_Id;
#endif // DEBUG_FLG

		int setId(string test_id) {     //string test_id
			int error_code_Id{ 0 };
			smatch m;
			if (!regex_search(test_id, m, regex(" {0,40}"))) {   // если регулярное выражение от 1 до бесконечности, то
				error_code_Id = 0;                               //то код ошибки = 0, иначе
			}
			else {
				error_code_Id = -1;                               // иначе = - 1
			};
			if (!regex_search(test_id, m, regex("^id[0-9]{1,40}$")) && error_code_Id == 0) {
				error_code_Id = 0;
			}
			else {
				error_code_Id = -1;
			};
			if (error_code_Id == 0) {
				Id = test_id;
			}
			return error_code_Id;

		};


		int getKolvo() {
			return Kolvo;
		};                                                    // проверяет, чтобы кол-во читателей было положительным, а не отрицатльным
		int setKolvo(int test_kolvo) {
			int error_code_Kolvo;
			if (test_kolvo > 0) {
				Kolvo = test_kolvo;
				error_code_Kolvo = 0;
			}
			else {
				error_code_Kolvo = -1;
			}
			return error_code_Kolvo;
		};
	};

	// дочь мероприятие
	class Event : public Library {

	private:
		string NameEvent;    //название мероприятия	
		int Date;             //дата проведения мероприятия

	public:
		string getNameEvent() {
			return NameEvent;
		};
		int setNameEvent(string test_name_event) {
			int error_code_NameEvent{ 0 };
			smatch m;
			if (!regex_search(test_name_event, m, regex(" {1,}"))) {   // если регулярное выражение от 1 до бесконечности, то
				error_code_NameEvent = 0;                               //то код ошибки = 0, иначе
			}
			else {
				error_code_NameEvent = -1;                               // иначе = - 1
			};
			if (!regex_search(test_name_event, m, regex("[0-9]")) && error_code_NameEvent == 0) {
				error_code_NameEvent = 0;
			}
			else {
				error_code_NameEvent = -1;
			};
			if (error_code_NameEvent == 0) {
				NameEvent = test_name_event;
			}
			return error_code_NameEvent;
		};
		int getDate() {
			Date;
		}; // доделай дату
		int setDate(int test_date) {
			int error_code_Date;
			if (test_date > 0) {
				Date = test_date;
				error_code_Date = 0;
			}
			else {
				error_code_Date = -1;
			}
			return error_code_Date;
		};
	};
	
	// хочу чтобы вводишь название библио, а в ответ вся инфа про id, кол-во, название мероприятия, дата
	int main() {
		// Установка поддержки кириллицы   
		//setlocale(LC_CTYPE, "rus");
		// название билиотеки
		string test_name;
		Library objLibrary;
		cin >> test_name;
		int error_code_Name = objLibrary.setName(test_name);
		cout << "Код ошибки\n";
		cout << error_code_Name << endl;
		cout << objLibrary.getName() << endl;

		int test_id;
		cin >> test_id;
		int error_code_Id = objLibrary.setId(test_id);
		cout << "Код ошибки\n";
		cout << error_code_Id << endl;
		if (error_code_Id <= 0) {
			cout << objLibrary.getId() << endl;
		}
		else {
			cout << "Ошибка в присвоении х\n";
		};


#ifdef DEBUG_FLG



		string test_name_event;
		Event objEvent;
		cin >> test_name_event;
		int error_code_NameEvent = objEvent.setNameEvent(test_name_event);
		cout << "Код ошибки\n";
		cout << error_code_NameEvent << endl;
		cout << objLibrary.getName() << endl;
#endif // DEBUG_FLG




#ifdef DEBUG_FLG

#endif // DEBUG_FLG
	
	; 
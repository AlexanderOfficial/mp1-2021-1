#include <iostream>
#include <string>
#include <vector>
#include <iostream>
#include <clocale> 
#include <windows.h>
#include <fstream> 
#include <sstream> 
#include <cctype> 
#include <cstring>
#include <locale>
#include <string>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
const string THREE_MONTH = "3-��������";
const string SIX_MONTH = "6-��������";
const string ONE_YEAR = "1-�������";
const string TWO_YEAR = "2-�������";
const string THREE_YEAR = "3-�������";

const double CREDIT_FOR_3_MONTH_FOR_THE_POOR = 2.5;
const double CREDIT_FOR_6_MONTH_FOR_THE_POOR = 2.8;
const double CREDIT_FOR_1_YEAR_FOR_THE_POOR = 3;
const double CREDIT_FOR_2_YEAR_FOR_THE_POOR = 3.2;
const double CREDIT_FOR_3_YEAR_FOR_THE_POOR = 3.5;

const double CREDIT_FOR_3_MONTH_FOR_THE_MIDDLE = 3.0;
const double CREDIT_FOR_6_MONTH_FOR_THE_MIDDLE = 3.2;
const double CREDIT_FOR_1_YEAR_FOR_THE_MIDDLE = 3.5;
const double CREDIT_FOR_2_YEAR_FOR_THE_MIDDLE = 4.0;
const double CREDIT_FOR_3_YEAR_FOR_THE_MIDDLE = 4.5;

const double CREDIT_FOR_3_MONTH_FOR_THE_RICH = 3.5;
const double CREDIT_FOR_6_MONTH_FOR_THE_RICH = 3.8;
const double CREDIT_FOR_1_YEAR_FOR_THE_RICH = 4.0;
const double CREDIT_FOR_2_YEAR_FOR_THE_RICH = 4.5;
const double CREDIT_FOR_3_YEAR_FOR_THE_RICH = 4.8;

const double CREDIT_FOR_3_MONTH_FOR_THE_VERY_RICH = 4.0;
const double CREDIT_FOR_6_MONTH_FOR_THE_VERY_RICH = 4.2;
const double CREDIT_FOR_1_YEAR_FOR_THE_VERY_RICH = 4.5;
const double CREDIT_FOR_2_YEAR_FOR_THE_VERY_RICH = 5.0;
const double CREDIT_FOR_3_YEAR_FOR_THE_VERY_RICH = 5.5;

const double MONTH_3 = 3;
const double MONTH_6 = 6;
const double YEAR_1 = 12;
const double YEAR_2 = 24;
const double YEAR_3 = 36;


const int ONE_HUNDRED_PERCENT = 100;

const int DAY_iN_YEAR = 365;
const int MONTH_IN_YEAR = 12;

int DAY;
int MONTH;
int YEAR;

void setDate(int _day, int _month, int _year);

void mainMenu();

struct informationAboutDeposit {
	bool depositStatus; //false - close/ true - open
	double procentOfDeposit; //������� ��������
	string nameDeposit; // ��� = ����
	double  depositAmount; //����� �� ��������
	int termOfDeposit; //���� �������� 
	double interestOnTheDeposit;//����� �� ��������
	unsigned int dayOfOpen;
	unsigned int dayOfClose;
	unsigned int monthOfOpen;
	unsigned int monthOfClose;
	unsigned int yearOfOpen;
	unsigned int yearOfClose;
	informationAboutDeposit(bool _depositStatus, double _procentOfDeposit, string _nameDeposit, long double  _depositAmount, int _termOfDeposit,
		unsigned int _dayOfOpen, unsigned int _dayOfClose, unsigned int _monthOfOpen, unsigned int _monthOfClose,
		unsigned int _yearOfOpen, unsigned int _yearOfClose, double _interestOnTheDeposit) :
		depositStatus(_depositStatus), procentOfDeposit(_procentOfDeposit), nameDeposit(_nameDeposit),
		depositAmount(_depositAmount), termOfDeposit(_termOfDeposit),
		dayOfOpen(_dayOfOpen), dayOfClose(_dayOfClose), monthOfOpen(_monthOfOpen),
		monthOfClose(_monthOfClose), yearOfOpen(_yearOfOpen), yearOfClose(_yearOfClose),
		interestOnTheDeposit(_interestOnTheDeposit) {};
	informationAboutDeposit& operator=(const informationAboutDeposit& deposit) {
		if (this != &deposit) {
			depositStatus = deposit.depositStatus;
			procentOfDeposit = deposit.procentOfDeposit;
			nameDeposit = deposit.nameDeposit;
			depositAmount = deposit.depositAmount;
			termOfDeposit = deposit.termOfDeposit;
			dayOfOpen = deposit.dayOfOpen;
			dayOfClose = deposit.dayOfClose;
			monthOfOpen = deposit.monthOfOpen;
			monthOfClose = deposit.monthOfClose;
			yearOfOpen = deposit.yearOfOpen;
			yearOfClose = deposit.yearOfClose;
			interestOnTheDeposit = deposit.interestOnTheDeposit;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, informationAboutDeposit& deposit) {
		out << deposit.depositStatus << ' ' << deposit.procentOfDeposit << ' ' << deposit.nameDeposit << ' ' << deposit.depositAmount
			<< ' ' << deposit.termOfDeposit << ' ' << deposit.dayOfOpen << ' ' << deposit.monthOfOpen << ' ' << deposit.yearOfOpen << ' ' << deposit.dayOfClose
			<< ' ' << deposit.monthOfClose << ' ' << deposit.yearOfClose << ' ' << deposit.interestOnTheDeposit;
		return out;
	}
};
struct informationAboutClient {
	string clientIndeficator; //����� ����������� ����� �0001� �� �9999�
	string clientPassword; //������ - ������������ ������ ������ 3 ��������
	string firstName; //���
	string patronymicName; //��������
	string surName; //�������
	double amountSalaryAccount; //����� �� ���������� �����
	vector <informationAboutDeposit> informationAboutDepositAndHisDate;
	informationAboutClient() {};
	void Observation(string _surName, string _firstName, string _patronymicName,
		double _amountSalaryAccount,
		bool _depositStatus, double _procentOfDeposit, string _nameDeposit, long double  _depositAmount, int _termOfDeposit,
		unsigned int dayOfOpen, unsigned int dayOfClose, unsigned int monthOfOpen, unsigned int monthOfClose,
		unsigned int yearOfOpen, unsigned int yearOfClose, double _interestOnTheDeposit) {//��� ���� ��� ���� ����� �����������
		firstName = _firstName;
		patronymicName = _patronymicName;
		surName = _surName;
		amountSalaryAccount = _amountSalaryAccount;
		informationAboutDeposit _newDeposit(_depositStatus, _procentOfDeposit, _nameDeposit, _depositAmount, _termOfDeposit,
			dayOfOpen, dayOfClose, monthOfOpen, monthOfClose, yearOfOpen, yearOfClose, _interestOnTheDeposit);
		informationAboutDepositAndHisDate.push_back(_newDeposit);
	}
	informationAboutClient(string _clientIndeficator, string _clientPassword) {
		clientIndeficator = _clientIndeficator;
		clientPassword = _clientPassword;
		firstName = "NOT_INSTALLED";
		patronymicName = "NOT_INSTALLED";
		surName = "NOT_INSTALLED";
		double amountSalaryAccount = -1;
	}
	informationAboutClient& operator=(const informationAboutClient& client) {
		if (this != &client) {
			informationAboutDepositAndHisDate = client.informationAboutDepositAndHisDate;
			clientIndeficator = client.clientIndeficator;
			clientPassword = client.clientPassword;
			firstName = client.firstName;
			patronymicName = client.patronymicName;
			surName = client.surName;
			amountSalaryAccount = client.amountSalaryAccount;
		}
		return *this;
	}
	friend ostream& operator<<(ostream& out, informationAboutClient& client) {
		out << client.clientIndeficator << ' ' << client.clientPassword << ' ' << client.surName << ' ' << client.firstName << ' ' << client.patronymicName
			<< ' ' << client.amountSalaryAccount << ' ';
		return out;
	}
};

class ProcessingCentr {
public:
	ProcessingCentr() {}
	ProcessingCentr(string filename);
	void saveInfFile();
	friend class Deposit;
private:
	vector <informationAboutClient> clientBaze;
protected:
};

class Deposit {
private:
	ProcessingCentr centrInDeposit;
	informationAboutClient clientInDeposit = {};
public:
	void growthInContribution(int _clientNumberIWorkWith);
	void  printIncomeOnDeposits(int _clientNumberIWorkWith);
	Deposit(ProcessingCentr _centrInDeposit) { centrInDeposit = _centrInDeposit; }
	int clientAuthorization(string _clientIndeficator, string _clientPassword);
	void availableDepositsThatTheClientCanOpen(int _clientNumberIWorkWith);
	void checkForOpenDeposits(int _clientNumberIWorkWith);
	void termsOfMenuDeposits();
	void openADeposit(int _clientNumberIWorkWith);
	void closeDeposit(int _clientNumberIWorkWith, int _depositIndeficator);
	void withdrawInterest(int _clientNumberIWorkWith, int _depositIndeficator);
	string getFullName(int _clientNumberIWorkWith);
};


void setDate(int _day, int _month, int _year) {
	DAY = _day;
	MONTH = _month;
	YEAR = _year;
}
void mainMenu()
{
	cout << "1. �������������� ������� " << endl;
	cout << "2. ��������� �������� " << endl;
	cout << "3. �������� �������� " << endl;
	cout << "4. ������� " << endl;
	cout << "5. ����� �� ������� " << endl;
	cout << "6. ��������� �������� �� �������� ���� " << endl;
	cout << "7. ������� ������� " << endl;

}
int main()
{
	SYSTEMTIME st;
	GetLocalTime(&st);
	setDate(st.wDay, st.wMonth, st.wYear);
	setlocale(LC_ALL, "rus");
	string str = "clientBaze.txt";

	ProcessingCentr centr(str);
	Deposit client(centr);
	//Deposit client(centr);
	int choiceMenu;
	int checkClient = -1;
	unsigned int clientNumberIWorkWith = -1;
	cout << "����� ����������! " << "                                                       ������� ����:  " << DAY << "." << MONTH << "." << YEAR << endl;
	cout << "��� �������� ����� ��������� ��� ������������� � ������� ����! " << endl;
	cout << "������ ����� ��������� ��������� �������. ���� ������ ������� ��������� �� ������ �� �������� ����,  " << endl;
	cout << "�� ���� �������� ������ ����������� �� ���� ���� �������� (���� �������� ������ �� ����������)" << endl;
	cout << "��� �������� ������ ���������� � ��� �������� � ����� (���� ��������/��������). " << endl;
	cout << "��� ��� ��� ���� ����� ������, �� ����� ��������� �������� �� ���� �������, ���� ������������ ��� �� ������� �����!!! " << endl;
	cout << "������� ������ ����� ���� : " << endl;
	mainMenu();
	cin >> choiceMenu;
	while (1) {
		switch (choiceMenu) {
		case 1: {// 1) ������������ �������
			string _clientdIndeficator;
			string _clientPassword;
			cout << "������� ����� ����� " << endl;
			cin >> _clientdIndeficator;
			while (_clientdIndeficator.length() != 4) {
				cout << "����� ����� ������ ��������� 4 �����! " << endl;
				cout << "������� ����� ����� ������! " << endl;
				cin >> _clientdIndeficator;
			}
			cout << "������� ������ " << endl;
			cin >> _clientPassword;
			while (_clientPassword.length() < 3) {
				cout << "����� ����� ������ ��������� 4 �����! " << endl;
				cout << "������� ������ ������! " << endl;
				cin >> _clientPassword;
			}
			checkClient = clientNumberIWorkWith = client.clientAuthorization(_clientdIndeficator, _clientPassword);
			if (checkClient == -1) { cout << "���������� �������������� ������! " << endl; break; }
			cout << client.getFullName(clientNumberIWorkWith) << endl;
			client.growthInContribution(clientNumberIWorkWith); //��������� ���� �� ���������
			//cout << "����� ������� � ����:" << clientNumberIWorkWith << endl;
			break;
		}
		case 2: {//2) �������� ���������� � ��������� ������� ���������, ������ �� ����� �� ��� ���������� �����, 
			if (checkClient == -1) { cout << " ������� ���������������!" << endl; break; }
			cout << "��������� ��������: " << endl;
			client.availableDepositsThatTheClientCanOpen(clientNumberIWorkWith);
			break;
		}
		case 3: {//3) ��������� ������� ��������� ��������,
			if (checkClient == -1) { cout << " ������� ���������������!" << endl; break; }
			cout << "������ �������� ���������: " << endl;
			client.checkForOpenDeposits(clientNumberIWorkWith);
			break;
		}
		case 4: {//4) ������� ������� (�������� ��������� ����� � ����������� ����� ������� �� �������), 
			if (checkClient == -1) { cout << " ������� ���������������!" << endl; break; }
			cout << "������ �� ������� ������� ����� ������� " << endl;
			client.openADeposit(clientNumberIWorkWith);

			break;
		}
		case 5: {//5) �������� ��������� ��������,
			if (checkClient == -1) { cout << " ������� ���������������!" << endl; break; }
			client.growthInContribution(clientNumberIWorkWith);
			client.printIncomeOnDeposits(clientNumberIWorkWith);
			break;
		}
		case 7: { // 7) ������� ������� (�������� ��� ����������� ����� �� ���������� ���� �������).
			if (checkClient == -1) { cout << " ������� ���������������!" << endl; break; }
			int depositIndeficator;
			cout << "������ �������� ���������: " << endl;
			client.checkForOpenDeposits(clientNumberIWorkWith);
			cout << "������� ������������� ��������, ������� �� ������ �������: " << endl;
			cin >> depositIndeficator;
			client.closeDeposit(clientNumberIWorkWith, depositIndeficator);
			//cout << "������� ������! " << endl;
			break;
		}
		case 6: {// 6) ����� �������� (�������� �� �� ���������� ���� �������), 
			if (checkClient == -1) { cout << " ������� ���������������!" << endl; break; }
			int depositIndeficator;
			cout << "������ �������� ���������: " << endl;
			client.checkForOpenDeposits(clientNumberIWorkWith);
			cout << "������� ������������� ��������, �������� � �������� ������ ���������: " << endl;
			cin >> depositIndeficator;
			client.withdrawInterest(clientNumberIWorkWith, depositIndeficator);
			cout << "������ ����������! " << endl;
			break;
		default:
			cout << "������ ������ ���� ���! ����� ���� � ��������������! " << endl;
		}
		}
		mainMenu();
		cout << "������� ������ ����� ���� : " << endl;
		cin >> choiceMenu;

	}
}

void Deposit::growthInContribution(int _clientNumberIWorkWith) {
	int monthCounter = 0;
	// cout << "����� �� ���� ������� (��� ����� ����� ������): " << endl;
	for (int i = 0; i < centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.size(); i++) {
		if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositStatus == true) {
			//������ ���� ��� �������� �������� � ����� ��������
			if (YEAR == centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].yearOfOpen) {
				if (DAY < centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].dayOfOpen) {
					monthCounter = MONTH - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen - 1;
				}
				else { monthCounter = MONTH - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen; }
				centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].interestOnTheDeposit
					= ((centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositAmount)
						* (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].procentOfDeposit))
					/ (ONE_HUNDRED_PERCENT) / (MONTH_IN_YEAR) *
					(monthCounter);
				centrInDeposit.saveInfFile();
			}
			if ((YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].yearOfOpen) == 1) {
				if (DAY < centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].dayOfOpen) {
					monthCounter = MONTH_IN_YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen +
						MONTH - 1;
				}
				else { monthCounter = MONTH_IN_YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen + MONTH; }
				centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].interestOnTheDeposit
					= ((centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositAmount) * (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].procentOfDeposit))
					/ (ONE_HUNDRED_PERCENT) / (MONTH_IN_YEAR) * (monthCounter);
				centrInDeposit.saveInfFile();
			}
			if ((YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].yearOfOpen) == 2) {
				if (DAY < centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].dayOfOpen) {
					monthCounter = MONTH_IN_YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen + MONTH_IN_YEAR + MONTH - 1;
				}
				else { monthCounter = MONTH_IN_YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen + MONTH_IN_YEAR + MONTH; }

				centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].interestOnTheDeposit
					= ((centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositAmount)
						* (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].procentOfDeposit))
					/ (ONE_HUNDRED_PERCENT) / (MONTH_IN_YEAR) * (monthCounter);
				centrInDeposit.saveInfFile();
			}
			if ((YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].yearOfOpen) == 3) {
				if (DAY < centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].dayOfOpen) {
					monthCounter = MONTH_IN_YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen + (2 * MONTH_IN_YEAR) + MONTH - 1;
				}
				else { monthCounter = MONTH_IN_YEAR - centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen + (2 * MONTH_IN_YEAR) + MONTH; }
				centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].interestOnTheDeposit
					= ((centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositAmount)
						* (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].procentOfDeposit))
					/ (ONE_HUNDRED_PERCENT) / (MONTH_IN_YEAR) * (monthCounter);
				centrInDeposit.saveInfFile();
			}
		}
	}
}

void Deposit::printIncomeOnDeposits(int _clientNumberIWorkWith) {
	bool checkDeposit = false;
	for (int i = 0; i < centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.size(); i++) {
		if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositStatus == true) {
			cout << "�������� �������� " << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].nameDeposit << endl
				<< "����� � ������� ��������  " << int(centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].interestOnTheDeposit) << " ���." << endl;
			checkDeposit = true;
		}
	}
	if (checkDeposit == false) { cout << " ��� �������� ���������! " << endl; }
}

int Deposit::clientAuthorization(string _clientIndeficator, string _clientPassword) {
	for (int i = 0; i < centrInDeposit.clientBaze.size(); i++) {
		if (centrInDeposit.clientBaze[i].clientIndeficator == _clientIndeficator
			&& centrInDeposit.clientBaze[i].clientPassword == _clientPassword) {
			cout << "������ �������������!" << endl;
			return i;
		}
		if (centrInDeposit.clientBaze[i].clientIndeficator == _clientIndeficator
			|| centrInDeposit.clientBaze[i].clientPassword == _clientPassword) {
			cout << "���-�� ������� �� ���! ���������� �������������� ������! " << endl;
			return -1;
		}
	}
}

void Deposit::availableDepositsThatTheClientCanOpen(int _clientNumberIWorkWith) {
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount < 100000) {
		cout << "�� ����� ����� ����� 100 �.�., ��� �������� ��������� �������� ��� �������: " << endl;
		cout << "�� ���� 3 ������: " << CREDIT_FOR_3_MONTH_FOR_THE_POOR << endl;
		cout << "�� ���� 6 �������: " << CREDIT_FOR_6_MONTH_FOR_THE_POOR << endl;
		cout << "�� ���� 1 ���: " << CREDIT_FOR_1_YEAR_FOR_THE_POOR << endl;
		cout << "�� ���� 2 ���� " << CREDIT_FOR_2_YEAR_FOR_THE_POOR << endl;
		cout << "�� ���� 3 ����: " << CREDIT_FOR_3_YEAR_FOR_THE_POOR << endl;
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount >= 100000 && centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount < 500000) {
		cout << "�� ����� ����� �����  100 �.�., �� ������ 500 �.�., ��� �������� ��������� �������� ��� �������: " << endl;
		cout << "�� ���� 3 ������: " << CREDIT_FOR_3_MONTH_FOR_THE_MIDDLE << endl;
		cout << "�� ���� 6 �������: " << CREDIT_FOR_6_MONTH_FOR_THE_MIDDLE << endl;
		cout << "�� ���� 1 ���: " << CREDIT_FOR_1_YEAR_FOR_THE_MIDDLE << endl;
		cout << "�� ���� 2 ���� " << CREDIT_FOR_2_YEAR_FOR_THE_MIDDLE << endl;
		cout << "�� ���� 3 ����: " << CREDIT_FOR_3_YEAR_FOR_THE_MIDDLE << endl;
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount >= 500000 && centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount < 1000000) {
		cout << "�� ����� ����� ����� 500 �.�., �� ����� 1 ���.�., ��� �������� ��������� �������� ��� �������: " << endl;
		cout << "�� ���� 3 ������: " << CREDIT_FOR_3_MONTH_FOR_THE_RICH << endl;
		cout << "�� ���� 6 �������: " << CREDIT_FOR_6_MONTH_FOR_THE_RICH << endl;
		cout << "�� ���� 1 ���: " << CREDIT_FOR_1_YEAR_FOR_THE_RICH << endl;
		cout << "�� ���� 2 ���� " << CREDIT_FOR_2_YEAR_FOR_THE_RICH << endl;
		cout << "�� ���� 3 ����: " << CREDIT_FOR_3_YEAR_FOR_THE_RICH << endl;
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount > 1000000) {
		cout << "�� ����� ����� ����� 1 ���. �., ��� �������� ��������� �������� ��� �������: " << endl;
		cout << "�� ���� 3 ������: " << CREDIT_FOR_3_MONTH_FOR_THE_VERY_RICH << endl;
		cout << "�� ���� 6 �������: " << CREDIT_FOR_6_MONTH_FOR_THE_VERY_RICH << endl;
		cout << "�� ���� 1 ���: " << CREDIT_FOR_1_YEAR_FOR_THE_VERY_RICH << endl;
		cout << "�� ���� 2 ���� " << CREDIT_FOR_2_YEAR_FOR_THE_VERY_RICH << endl;
		cout << "�� ���� 3 ����: " << CREDIT_FOR_3_YEAR_FOR_THE_VERY_RICH << endl;
	}
}

void Deposit::checkForOpenDeposits(int _clientNumberIWorkWith) {
	bool checkDeposit = false;
	for (int i = 0; i < centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.size(); i++) {
		if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositStatus == true) {
			cout << "������������� ��������: " << i << endl;
			cout << "�������� ��������: " << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].nameDeposit << endl;
			cout << "������� ��������: " << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].procentOfDeposit << endl;
			cout << "����� ��������: " << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].depositAmount << endl;
			cout << "���� ��������: " << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].dayOfOpen
				<< "." << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfOpen
				<< "." << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].yearOfOpen << endl;
			cout << "���� ��������: " << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].dayOfClose
				<< "." << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].monthOfClose
				<< "." << centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[i].yearOfClose << endl;
			checkDeposit = true;
			cout << "_____________________________________________________________________________________________________________________________________" << endl;
		}
	}
	if (checkDeposit == false) { cout << " ��� �������� ���������! " << endl; }
}

void Deposit::termsOfMenuDeposits() {
	cout << "1. 3 ������ " << endl;
	cout << "2. 6 ������� " << endl;
	cout << "3. 1 ��� " << endl;
	cout << "4. 2 ����" << endl;
	cout << "5. 3 ����" << endl;
}

void Deposit::openADeposit(int _clientNumberIWorkWith) {
	int sum = -1;
	int creditTerm;
	cout << "�������� ������� �� ������ �������: " << endl;
	availableDepositsThatTheClientCanOpen(_clientNumberIWorkWith);
	//informationAboutDeposit newDeposit();
	cout << "������� �����, ������� ������ �������� " << endl;
	cin >> sum;
	while (sum >= centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount || sum <= 0) {
		cout << "������������ ������� ��� ����� ������������. ������� ������! " << endl;
		cin >> sum;
	}
	if (sum < 100000) {
		cout << "�������� ����, �� ������� �� ������ ������� �������" << endl;
		int _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose, _yearOfOpen, _yearOfClose;
		_dayOfOpen = DAY;
		_monthOfOpen = MONTH;
		_yearOfOpen = YEAR;
		termsOfMenuDeposits();
		cin >> creditTerm;
		switch (creditTerm) {
		case 1: { //3 ������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 3; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_MONTH_FOR_THE_POOR, THREE_MONTH, sum,
				MONTH_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 2: { //����� �������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 6; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_6_MONTH_FOR_THE_POOR, SIX_MONTH, sum,
				MONTH_6, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 3: { // 1 ���
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 12; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_1_YEAR_FOR_THE_POOR, ONE_YEAR, sum,
				YEAR_1, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 4: { // 2 ���� 
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 24; //���������� 
			_monthOfClose = _monthOfClose % 24;
			_yearOfClose = _yearOfOpen + 2;
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_2_YEAR_FOR_THE_POOR, TWO_YEAR, sum,
				YEAR_2, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 5: { // 3 ����
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 36; //���������� 
			_monthOfClose = _monthOfClose % 36;
			_yearOfClose = _yearOfOpen + 3;
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_YEAR_FOR_THE_POOR, THREE_YEAR, sum,
				YEAR_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		}
	}
	if (sum < 500000 && sum >= 100000) {
		cout << "�������� ����, �� ������� ������ ��������" << endl;
		int _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose, _yearOfOpen, _yearOfClose;
		_dayOfOpen = DAY;
		_monthOfOpen = MONTH;
		_yearOfOpen = YEAR;
		termsOfMenuDeposits();
		cin >> creditTerm;
		switch (creditTerm) {
		case 1: { //3 ������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 3; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_MONTH_FOR_THE_MIDDLE, THREE_MONTH, sum,
				MONTH_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 2: { //����� �������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 6;
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_6_MONTH_FOR_THE_MIDDLE, SIX_MONTH, sum,
				MONTH_6, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 3: { // 1 ���
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 12; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_1_YEAR_FOR_THE_MIDDLE, ONE_YEAR, sum,
				YEAR_1, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 4: { // 2 ���� 
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 24; //���������� 
			_monthOfClose = _monthOfClose % 24;
			_yearOfClose = _yearOfOpen + 2;
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_2_YEAR_FOR_THE_MIDDLE, TWO_YEAR, sum,
				YEAR_2, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 5: { // 3 ����
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 36; //���������� 
			_monthOfClose = _monthOfClose % 36;
			_yearOfClose = _yearOfOpen + 3;
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_YEAR_FOR_THE_MIDDLE, THREE_YEAR, sum,
				YEAR_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		}
	}
	if (sum < 1000000 && sum >= 500000) {
		cout << "�������� ����, �� ������� ������ ��������" << endl;
		int _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose, _yearOfOpen, _yearOfClose;
		_dayOfOpen = DAY;
		_monthOfOpen = MONTH;
		_yearOfOpen = YEAR;
		termsOfMenuDeposits();
		cin >> creditTerm;
		switch (creditTerm) {
		case 1: { //3 ������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 3; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_MONTH_FOR_THE_RICH, THREE_MONTH, sum,
				MONTH_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 2: { //����� �������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 6; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_6_MONTH_FOR_THE_RICH, SIX_MONTH, sum,
				MONTH_6, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 3: { // 1 ���
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 12; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_1_YEAR_FOR_THE_RICH, ONE_YEAR, sum,
				YEAR_1, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 4: { // 2 ���� 
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 24; //���������� 

			_monthOfClose = _monthOfClose % 24;
			_yearOfClose = _yearOfOpen + 2;

			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_2_YEAR_FOR_THE_RICH, TWO_YEAR, sum,
				YEAR_2, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 5: { // 3 ����
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 36; //���������� 

			_monthOfClose = _monthOfClose % 36;
			_yearOfClose = _yearOfOpen + 3;

			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_YEAR_FOR_THE_RICH, THREE_YEAR, sum,
				YEAR_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		}
	}
	if (sum < 1000000 && sum >= 500000) {
		cout << "�������� ����, �� ������� ������ ��������" << endl;

		int _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose, _yearOfOpen, _yearOfClose;
		_dayOfOpen = DAY;
		_monthOfOpen = MONTH;
		_yearOfOpen = YEAR;
		termsOfMenuDeposits();
		cin >> creditTerm;
		switch (creditTerm) {
		case 1: { //3 ������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 3; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_MONTH_FOR_THE_VERY_RICH, THREE_MONTH, sum,
				MONTH_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 2: { //����� �������
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 6; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else {
				_yearOfClose = _yearOfOpen;
			}
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_6_MONTH_FOR_THE_VERY_RICH, SIX_MONTH, sum,
				MONTH_6, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 3: { // 1 ���
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 12; //���������� 3 ������
			if (_monthOfClose > 12) {
				_monthOfClose = _monthOfClose % 12;
				_yearOfClose = _yearOfOpen + 1;
			}
			else { _yearOfClose = _yearOfOpen; }
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_1_YEAR_FOR_THE_VERY_RICH, ONE_YEAR, sum,
				YEAR_1, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 4: { // 2 ���� 
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 24; //���������� 

			_monthOfClose = _monthOfClose % 24;
			_yearOfClose = _yearOfOpen + 2;

			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_2_YEAR_FOR_THE_VERY_RICH, TWO_YEAR, sum,
				YEAR_2, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		case 5: { // 3 ����
			_dayOfClose = _dayOfOpen; //���� �������� ����� ��� ��������
			_monthOfClose = _monthOfOpen + 36; //���������� 
			_monthOfClose = _monthOfClose % 36;
			_yearOfClose = _yearOfOpen + 3;
			centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount - sum;
			informationAboutDeposit newDeposit(true, CREDIT_FOR_3_YEAR_FOR_THE_RICH, THREE_YEAR, sum,
				YEAR_3, _dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
				_yearOfOpen, _yearOfClose, 0);
			centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate.push_back(newDeposit);
			centrInDeposit.saveInfFile();
			break;
		}
		}
	}


}


//��� ����� ���� ������������� �������, �� �� ��������� ������ ������� �� ����� �������
void Deposit::closeDeposit(int _clientNumberIWorkWith, int _depositIndeficator) {
	if ((centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].yearOfClose) < YEAR) {
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositStatus = false;
		centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount
			+ (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositAmount
				+ centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit);
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit = 0;
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositAmount = 0;
		centrInDeposit.saveInfFile();
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].yearOfClose == YEAR
		&& centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].monthOfClose < MONTH) {
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositStatus = false;
		centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount
			+ (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositAmount
				+ centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit);
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit = 0;
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositAmount = 0;
		centrInDeposit.saveInfFile();
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].yearOfClose == YEAR
		&& centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].monthOfClose == MONTH
		&& centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].dayOfClose <= DAY) {
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositStatus = false;
		centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount
			+ (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositAmount
				+ centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit);
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit = 0;
		centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].depositAmount = 0;
		centrInDeposit.saveInfFile();
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].yearOfClose > YEAR) {
		cout << "����� ������� ��� ������! ����!" << endl;
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].yearOfClose == YEAR
		&& centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].monthOfClose == MONTH
		&& centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].dayOfClose > DAY) {
		cout << "����� ������� ��� ������! ����!" << endl;
	}
	if (centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].yearOfClose == YEAR
		&& centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].monthOfClose > MONTH) {
		cout << "����� ������� ��� ������! ����!" << endl;
	}
}

void Deposit::withdrawInterest(int _clientNumberIWorkWith, int _depositIndeficator) {
	centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount = centrInDeposit.clientBaze[_clientNumberIWorkWith].amountSalaryAccount
		+ centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit;
	centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].dayOfOpen = DAY;
	centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].monthOfOpen = MONTH;
	centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].yearOfOpen = YEAR;
	centrInDeposit.clientBaze[_clientNumberIWorkWith].informationAboutDepositAndHisDate[_depositIndeficator].interestOnTheDeposit = 0;
	centrInDeposit.saveInfFile();

}

string Deposit::getFullName(int _clientNumberIWorkWith) {
	string fullName;
	fullName = centrInDeposit.clientBaze[_clientNumberIWorkWith].firstName + ' ' + centrInDeposit.clientBaze[_clientNumberIWorkWith].patronymicName;
	return fullName;
}

ProcessingCentr::ProcessingCentr(string filename) {
	ifstream in(filename);
	if (!in) { cout << "�� �����" << endl; }
	string _clientIndeficator; //����� ����������� ����� �0001� �� �9999�
	string _clientPassword; //������ - ������������ ������ ������ 3 ��������
	string _firstName; //���
	string _patronymicName; //��������
	string _surName; //�������
	unsigned int _dayOfOpen;
	unsigned int _dayOfClose;
	unsigned int _monthOfOpen;
	unsigned int _monthOfClose;
	unsigned int _yearOfOpen;
	unsigned int _yearOfClose;
	string _termOfTheDeposit;//���� ��������
	double _procentOfDeposit; //������� ��������
	long double  _initialDepositAmount;//��������� ����� ��������
	int _termOfDeposit; //���� �������� 
	bool _statusDeposit; // ��������� ��������
	double  _amountSalaryAccount;//!!!
	double _depositAmount;
	string line;
	string _nameDeposit; //��� ����� ���� 
	string str1, str2, str3, str4;
	int countString = 0;
	bool check = false;
	bool checkFirstClient = true;
	double _interestOnTheDeposit;
	while (getline(in, line)) {
		check = false;
		istringstream ist(line);
		ist >> _clientIndeficator;
		ist >> _clientPassword;

		ist >> _surName;
		ist >> _firstName;

		ist >> _patronymicName;
		ist >> _amountSalaryAccount;

		ist >> _statusDeposit;
		ist >> _procentOfDeposit;

		ist >> _nameDeposit;
		ist >> _depositAmount;

		ist >> _termOfDeposit;

		ist >> _dayOfOpen;
		ist >> _monthOfOpen;
		ist >> _yearOfOpen;
		ist >> _dayOfClose;
		ist >> _monthOfClose;
		ist >> _yearOfClose;

		ist >> _interestOnTheDeposit;
		if (checkFirstClient == false) {
			for (size_t i = 0; i < clientBaze.size(); i++) {
				if (clientBaze[i].clientIndeficator == _clientIndeficator) {
					clientBaze[i].Observation(_surName, _firstName, _patronymicName, _amountSalaryAccount,
						_statusDeposit, _procentOfDeposit, _nameDeposit, _depositAmount, _termOfDeposit,
						_dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
						_yearOfOpen, _yearOfClose, _interestOnTheDeposit);
					check = true;
				}
			}

		}

		if (check == false) {
			informationAboutClient newClient(_clientIndeficator, _clientPassword);
			clientBaze.push_back(newClient);
			for (int i = 0; i < clientBaze.size(); i++) {
				if (clientBaze[i].clientIndeficator == _clientIndeficator) {
					clientBaze[i].Observation(_surName, _firstName, _patronymicName, _amountSalaryAccount,
						_statusDeposit, _procentOfDeposit, _nameDeposit, _depositAmount, _termOfDeposit,
						_dayOfOpen, _dayOfClose, _monthOfOpen, _monthOfClose,
						_yearOfOpen, _yearOfClose, _interestOnTheDeposit);
					check = false;
					checkFirstClient = false;
				}
			}
		}
	}
	in.close();
}

void ProcessingCentr::saveInfFile() {
	ofstream out;
	out.open("clientBaze.txt");
	if (!out.is_open()) { cout << "���� �� ��������" << endl; }
	for (int i = 0; i < clientBaze.size(); i++) {
		for (int j = 0; j < clientBaze[i].informationAboutDepositAndHisDate.size(); j++) {
			out << clientBaze[i] << clientBaze[i].informationAboutDepositAndHisDate[j] << endl;
		}
	}
	out.close();
}

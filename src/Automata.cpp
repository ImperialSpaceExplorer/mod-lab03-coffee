#include "Automata.h"

	 Automata::Automata()
	{
		 cash = 0;
		 menu = new string[3]{"���", "����","������"};
		 prices = new unsigned int[3]{5,15,8};
		 state = Off;
	}

	 void Automata::on() //1
	 {
		 if (state == Off) { state = Wait; cout << "������� ���������." << endl; }
		 else cout << "������� ��� �������." << endl;

	 }

	 void Automata::off()//2
	 {
		 if (state == Wait){ state = Off; cout << "������� ����������." << endl;}
		 else if (state == Off) cout << "������� ��� ��������." << endl;
		 else cout << "������� �� �������� ���� ������." << endl;
	 }
	 void Automata::coin(unsigned int sum)//3
	 {
		 if (state == Wait || state == Accept) { state = Accept; cash += sum; cout << "������ �������: "<< sum << endl; }
		
		 else cout << "��������� ���������� ������ ��������." << endl;
	 }
	 void Automata::GetMenu()//4
	 {
		 cout << " ����:--------------------------------------- " << endl;
		 for (int i = 0; i < 3; i++) { cout << menu[i]<<" - "<< prices[i] << endl; }
		 cout << " ---------------------------------------V0.1- " << endl;
	 }
	 States Automata::GetState()//5
	 {
		 return state;
	 }
	 void Automata::choice(int num)//6
	 {
		 if (state == Accept) {state = Check; cout << "����� ������: " << num << endl;}
		 
		 else cout << "������� ������ � �������� �������." << endl;
	 }
	 void Automata::check(int num)//7
	 {
		 if (state == Check) 
		 {
			 if (prices[num-1] <= cash) { state = Check; cout << "��� ������ ������� �������." << endl;  }
		 
			 else { cout << "������������ ����� �� �����, ������� �� ������ �����." << " ( "<<cash<<"��"<<prices[num-1]<< " )"<< endl; }
		 }
		 else cout << "������� ������ � �������� �������." << endl;
	 }
	 void Automata::cancel()//8
	 {
		 if (state == Accept || state ==Check) {state = Wait; cout << "�������� ��������." << endl;}
		 else cout << "��������� ���������� ������ ��������." << endl;
	 }
	 void Automata::cook(int num)//9
	 {
		 if (state == Check && cash>=prices[num-1]) { state = Cook;  cout << "������������� �������..." << menu[num-1] << endl;cash -= prices[num-1];}
		 else cout << "������� ������ � �������� �������." << endl;
	 }
	 void Automata::finish()//10
	 {
		 if (state == Cook) { state = Wait;  cout << "������� �����. ��������� ��������." << endl;}
	 
		 else cout << "��������� ���������� ������ ��������." << endl;
	 }
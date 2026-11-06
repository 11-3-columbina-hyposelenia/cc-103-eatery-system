#include <iostream> /* input output to baka itanong sa defense */
#include <cstdlib>  /* c++ standard library */
#include <cstdio> /* para sa file operations like read write */
#include <fstream> /* file operations rin */
#include <string> /* for string operations like yung sa Java na + tas yung .length stc */
#include <vector> /* for dynamic array size ng pagkain */
#include <iomanip> /* for decimal places */
#include <cstddef> /* para sa size_t, ginamit sa space function*/

using namespace std;

struct Meal {
	string food;
	double price;
};

int ui(); /* basically sinasabi mo sa complier na hintayin nya yung code ng function nayan */ // ✅

void createorder(); // ✅
void readorder(); // 🕒
void updateorder();
void deleteorder();

string replaceto(); // ✅

double calcu_n_fileinput(); // ✅
void pktc(); // ✅
double payorder();

void queue();
void stack();
void linkedlist();
void doublelinkedlist();

int main() { 
	ui(); 
}

int ui() {
	int choice;
	
	system("cls");
	cout<<"Welcome sa bitik eatery!"<<endl<<"1.) Put an order. "<<endl<<"2.) View current list of orders. "<<endl<<"3.) Modify an existing order. "<<endl<<"4.) Remove an existing order. "<<endl<<"5.) Pay order."<<endl<<"6.) Exit the Program. "<<endl<<endl<<"Input placed here: ";
	cin>>choice; /* Output natin ya */
	
	/* Eto naman if-else-if statement ng papa-run natin na CRUD */
	if (choice == 1) { createorder(); } 
	else if (choice == 2) { readorder(); }
	else if (choice == 3) {  }
	else if (choice == 4) {  }
	else if (choice == 5) {  }
	else { }
	return choice;
}

string replaceto(string targettxt, char toChangeChar, char toReplaceChar) {
	for (int i = 0; i < targettxt.length(); i++) {
		if(targettxt[i] == toChangeChar) {
			targettxt[i] = toReplaceChar;
		}
	}
	return targettxt;
}

string space(string text, const size_t num, const char s = ' ') {
	int text_size = text.size();
	for(int i = text_size; i < num; i++) {
		text = text + s;
	}
	return text;
}

double calcu_n_fileinput(string food, double price, string status) {
	int sum, quantity;
	int newcount = 0, totalcount = 1;
	
	// Para makita kung ano na yung nasa loob para accurate ang count
	ifstream output("orderlist.txt");
	string temp_food, temp_status;
	double temp_price;
	int temp_count;
	while (output >> temp_count >> temp_food >> quantity >> temp_price >> temp_status) {
		totalcount = temp_count + 1; 
	}
	output.close();
	
	cout<< fixed << setprecision(2);
	cout << "How many orders of " << food << " do you want?: ";
	cin >> quantity;
	sum = price * quantity;
	cout << "Amount to pay: ₱"<< sum << endl;
		
	food = replaceto(food, ' ', '_');
	newcount = totalcount;
	
	ofstream input("orderlist.txt", ios::app);
	input << newcount << ' ' << food << ' ' << quantity << ' ' << sum  << ' ' << status << endl;
	input.close();
	
	return sum;
}

void pktc() {
	int key;
	system("cls");
	cout<<"We received your order. Please wait for the food. for the meantime \n\n• Take a seat and relax\n• Continue ordering\n";
	cout<<"Press any key to continue: ";
	cin>>key;
	cout<<endl;
}

void createorder() {
	ofstream input("orderlist.txt", ios::app); /* ofstream = write */
	ifstream output("orderlist.txt"); /* ifstream = read */
	string food, newfood, orderstatus;
	int price, newprice, price_cal, quantity;
	int count = 0, totalcount = 1, newcount, ordercount;
	int foodchoice;
	bool loop = false;
	
	vector<Meal> menu;
	
	/* etong while statement nare, walang pake kung nasa newfood at newprice yung data, as long as same datatype papasok yan */
	while (output >> count >> food >> quantity >> price >> orderstatus) {
		totalcount++; 
	}
	output.close();
	
	do {
		system("cls");
		cout<<fixed<<setprecision(2);
		cout<<"Sandrone: Ano? Ano order nyo?"<<endl<<"Ikaw: ang order ko po ayy..."<<endl<<"1.) Ado-bo — ₱35"<<endl<<"2.) Sui-nigang na May yabi — ₱35"<<endl<<"3.) Sisig ni Boss Wreck — ₱50"<<endl<<"4.) Diwata ni Pares — ₱50"<<endl<<"5.) Itlog ni Remielle — ₱50"<<endl<<"6.) 3 in 1 ni Tin Master — ₱20"<<endl<<"7.) Kanin ni Busing — ₱15"<<endl<<endl<<"Enter the corresponding number: "; /* Test Name lang muna, baguhin nalang. pati yung etong prompt */
		cin>>foodchoice;
		system("cls");
		if (foodchoice == 1) { 
			newfood = "Adobo"; 
			price_cal = 35;
			orderstatus = "unpaid";
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
			pktc();
			ui();
		} else if (foodchoice == 2) { 
			newfood = "Sinigang na may gabi";
			price_cal = 35;
			orderstatus = "unpaid";
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
			pktc();
			ui();
		} else if (foodchoice == 3) { 
			newfood = "Sisig"; 
			price_cal = 50;
			orderstatus = "unpaid";
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
			pktc();
			ui();
		} else if (foodchoice == 4) {
			newfood = "Pares";
			price_cal = 50;
			orderstatus = "unpaid";
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
			pktc();
			ui();
		} else if (foodchoice == 5) {
			newfood = "Itlog";
			price_cal = 50;
			orderstatus = "unpaid";
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
			pktc();
			ui();
		} else if (foodchoice == 6) {
			newfood = "3 in 1 Coffee";
			price_cal = 20;
			orderstatus = "unpaid";
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
			pktc();
			ui();
		} else if (foodchoice == 7) {
			newfood = "Rice";
			price_cal = 15;
			orderstatus = "unpaid";
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
			pktc();
			ui();
		} else {
			system("cls");
			cout<<"Please enter a valid choice...";
			
			loop = true;
		} 
	} while (loop == true);
}

void readorder() {
	ifstream outputdata("orderlist.txt");
	string food, status;
	int quantity, sum;
	
	int count, totalcount = 0;
	
	system("cls");
					
cout<<"——————————————————————————"<<endl;
cout<<"| No. | Food                                    | Quantity | Price        | Status |"<<endl;
cout<<"——————————————————————————"<<endl;

	while (outputdata >> count >> food >> quantity >> sum >> status) {
		food = replaceto(food,'_',' '); 
		cout << "| " <<space(to_string(count), 6)<< " | " <<space(food, 40)<< " | " << space(to_string(quantity), 16)<< " | ₱"<< space(to_string(sum), 10)<< " | "<<space(status, 4)<<" |"<<endl;
		cout<<"——————————————————————————"<<endl;
	}
	outputdata.close();
}

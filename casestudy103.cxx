#include <iostream> /* input output to baka itanong sa defense */
#include <cstdlib>  /* c++ standard library */
#include <cstdio> /* para sa file operations like read write */
#include <fstream> /* file operations rin */
#include <string> /* for string operations like yung sa Java na + tas yung .length stc */
#include <vector> /* for dynamic array size ng pagkain */
#include <iomanip> /* for decimal places */
#include <cstddef> /* para sa size_t, ginamit sa space function*/
#include <sstream> /* for string to int conversions ng onlyint function*/
#include <algorithm> /* for basic vector commands */

using namespace std;

struct Meal {
	string food;
	int price;
};

struct Order {
	int no;
	string food;
	int qty;
	int sum;
	string status;
};

const vector<Meal> menu = {
    {"Adobo", 35},
    {"Sinigang na may gabi", 35},
    {"Sisig", 35},
    {"Pares", 50},
    {"Itlog", 50},
    {"3 in 1 Coffee", 20},
    {"Rice", 15}
};

vector <Order> loadorders() {
	vector <Order> orders;
	ifstream in("orderlist.txt");
	Order o; /* similar to sa new object ng Java, pero we don't actually DO new struct ng order. based on my understanding, isa siyang temporary container na once natapos yung function, tapos narin sya*/
	while (in >> o.no >> o.food >> o.qty >> o.sum >> o.status) {
		orders.push_back(o);
	}
	return orders;
}

void saveOrders(const vector<Order>& orders) {
    ofstream out("orderlist.txt");
    for (const Order& o : orders)
        out << o.no << ' ' << o.food << ' ' << o.qty << ' ' << o.sum << ' ' << o.status << '\n';
}

int ui(); /* basically sinasabi mo sa complier na hintayin nya yung code ng function nayan */ // ✅

void createorder(); // ✅
void readorder(); // ✅
void updateorder(); // ✅
void deleteorder(); // ✅

string replaceto(string targettxt, char toChangeChar, char toReplaceChar); // ✅

int onlyint(); // Every day, I imagine a future where I can be with you ✅
double calcu_n_fileinput(string food, double price, string status); // ✅
void pktc(bool verify); // may certain action base sa boolean status ✅
void pktc2(); // eto wala, basta't press enter lang sya ✅
double payorder();

void queue();
void stack();
void linkedlist();
void doublelinkedlist();

int main() { 
	system("chcp 65001 > nul"); // para UTF-8 ang gamiting encoding kapag sa computer pinatakbo yung code. matik mababasa na yung — at ₱.
	ui(); 
}

int ui() /* function */{
	int choice;
	bool loop = false;
	
	system("cls");
	cout<<"Welcome sa bitik eatery!"<<endl<<"1.) Put an order. "<<endl<<"2.) View current list of orders. "<<endl<<"3.) Modify an existing order. "<<endl<<"4.) Remove an existing order. "<<endl<<"5.) Pay order."<<endl<<"6.) Exit the Program. "<<endl<<endl<<"Input placed here: ";
	cin>>choice; /* Output natin ya */
	
	/* Eto naman if-else-if statement ng papa-run natin na CRUD */
	if (choice == 1) { createorder(); } 
	else if (choice == 2) { readorder(); pktc(false); }
	else if (choice == 3) { updateorder(); }
	else if (choice == 4) { deleteorder(); }
	else if (choice == 5) {  }
	else if (choice == 6) { return EXIT_SUCCESS; }
	else { 
		loop = false;
		cout<<"Invalid Choice, Please try again."<<endl;
		cin.ignore();
		cout<<"Press enter to continue: ";
		cin.get();
		ui();
	}
	return choice;
}

int onlyint() /* function*/ {
    string input;
    int number = 0;
    bool isValid = false;

    do {
        cout << "Input placed here: ";
        cin >> input; 
        isValid = true;
        for (int i = 0; i < input.length(); i++) {
            // Kapag may nakitang letters, symbols and decimal points matik yan sibak yan.
            if (!isdigit(input[i])) {
                isValid = false;
                break;
            }
        }

        if (!isValid) {
            cout << "Huwaggg, magloloko system namin dyan ya. Try mo tamang datatype lulusot yan\n";
        } else {
            // Kung puro numbers yan, pasok yan sa int concept! 
            stringstream monika(input);
            monika >> number;
            break; 
        }
    } while (true);

    return number;
}

string replaceto(string targettxt, char toChangeChar, char toReplaceChar) /* function*/ {
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
	int realquantity, sum;
	string quantity;
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
	
	cout << "How many orders of " << food << " do you want?: ";
	realquantity = onlyint(); // eto sya guys
	sum = price * realquantity;
	cout << "Amount to pay: ₱"<<fixed << setprecision(2)<< sum << endl;
	cin.ignore();
	cout<<"Press enter to continue: ";
	cin.get();
		
	food = replaceto(food, ' ', '_');
	newcount = totalcount;
	
	ofstream input("orderlist.txt", ios::app);
	input << newcount << ' ' << food << ' ' << realquantity << ' ' << sum  << ' ' << status << endl;
	input.close();
	
	return sum;
}

void pktc(bool verify) /* function*/ {
	if (verify == true) {
		system("cls");
		cout<<"We received your order. Please wait for the food. for the meantime \n\n• Take a seat and relax\n• Continue ordering\n";
		cout<<"Press any enter to continue: ";
		cin.get();
		cout<<endl;
		ui();
	} else {
		cin.ignore();
		cout<<"Press any key to continue: ";
		cin.get();
		ui();
	}
}

void pktc2() {
	cin.ignore();
	cout<<"Enter any key to continue: ";
	cin.get();
}

void createorder()  /* function*/  {
	ofstream input("orderlist.txt", ios::app); /* ofstream = write */
	ifstream output("orderlist.txt"); /* ifstream = read */
	string food, newfood, orderstatus = "unpaid";
	int price, newprice, price_cal, quantity;
	int count = 0, totalcount = 1, newcount, ordercount;
	int foodchoice;
	bool loop = false; bool pktc_bool = true;
	
	/* etong while statement nare, walang pake kung nasa newfood at newprice yung data, as long as same datatype papasok yan */
	while (output >> count >> food >> quantity >> price >> orderstatus) {
		totalcount++; 
	}
	output.close();
	
	do {
		system("cls");
		cout<<fixed<<setprecision(2);
		cout<<"Sandrone: Ohh ano sa inyo?"<<endl;
		for (size_t i = 0; i < menu.size(); i++) {
			cout<<i+1<<".) "<<menu[i].food<<" — ₱"<<menu[i].price<<endl;
		}
		cin>>foodchoice;
		system("cls");
		if (foodchoice >= 1 && foodchoice <= menu.size()) { 
			newfood = menu[foodchoice - 1].food;
			price_cal = menu[foodchoice - 1].price;
			
			calcu_n_fileinput(newfood, price_cal, orderstatus);
		} else {
			system("cls");
			cout<<"Please enter a valid choice... \n";
			
			loop = true;
			pktc_bool = false;
			pktc(pktc_bool);
		} 
	} while (loop == true);
	pktc(loop);
}

void readorder()  /* function*/  {
	ifstream outputdata("orderlist.txt");
	string food, status;
	int quantity, sum;
	int count, totalcount = 0;
	
	bool loop = false;
	
	system("cls");
					
cout<<"——————————————————————————"<<endl;
cout<<"| No. | Food                                    | Quantity | Price        | Status |"<<endl;
cout<<"——————————————————————————"<<endl;

	while (outputdata >> count >> food >> quantity >> sum >> status) {
		food = replaceto(food,'_',' '); 
		cout<<fixed<<setprecision(2);
		cout << "| " <<space(to_string(count), 6)<< " | " <<space(food, 40)<< " | " << space(to_string(quantity), 16)<< " | ₱"<< space(to_string(sum), 10)<< " | "<<space(status, 4)<<" |"<<endl;
		cout<<"——————————————————————————"<<endl;
		totalcount++;
	}
	cout<<"total orders: "<<totalcount<<endl;
	outputdata.close();
}

void displayorder()  /* function*/ {
	bool loop = false;
	readorder();
}

void updateorder() /* function*/ {
    int no, foodchoice, qty;
    
    vector<Order>orders = loadorders();
    if (orders.empty()) {
        cout << "No orders to update yet.\n";
        pktc(false);
        return;
    }

    readorder();  // display only, no navigation

    cout << "\nEnter no of order to update: ";
    no = onlyint();
    vector<Order>::iterator it = find_if(orders.begin(), orders.end(),
                                     [no](const Order& o) { return o.no == no; });
    if (it == orders.end()) { //
        cout << "Order not found.\n";
        pktc(false);
        return;
    }

    cout << "Columbina: ...ohh hi there, ano gusto ninyo?\n\n";
    for (size_t i = 0; i < menu.size(); i++)
        cout << i + 1 << ".) " << menu[i].food << " — ₱" << menu[i].price << endl;

    foodchoice = onlyint();
    if (foodchoice < 1 || foodchoice > (int)menu.size()) {
        cout << "Invalid choice.\n";
        pktc(false);
        return;
    }

    cout << "How many orders of " << menu[foodchoice - 1].food << " do you want?: ";
    qty = onlyint();

    it->food = replaceto(menu[foodchoice - 1].food, ' ', '_');
    it->qty = qty;
    it->sum = menu[foodchoice - 1].price * qty;

    saveOrders(orders);
    cout << "Order updated!\n";
    pktc(false);
}

void deleteorder() /* function*/ {
	int no;
	
	vector<Order> orders = loadorders();
	if (orders.empty()) {
		cout<<"Currently, there's no order so we can't delete"<<endl;
		system("pause");
		return;
	}
	readorder();
	
	cout<<"Enter the number of exact order you wanted to delete: ";
	no = onlyint();
	auto it = find_if(orders.begin(), orders.end(), [&](const Order& o)
	{ return o.no == no; }); /* so basically, eto ay parang isang question. so yung find if tinatanong nya kung "eto ba yung order na same sa no varible. then yung orders.begin at end yun yung haba ng ichcheck nya tas yung "[&](const Order& o)" yan ay tinatawag na lambda na sinasabi nya na etong eto lang yung order na ichecheck natin at reference natin, yang "o" nayan. tas kapag yung o.no ay nag equal sa no. ibabalik nya yung order.
	*/
	
	if (it == orders.end()) /*kapag umabot sa end, means wala sya nakita*/{
		cout<<"No orders matched based by input. Please try again";
		pktc2();
		return;
	}
	
	orders.erase(it); /* diba may auto it tayo sa 335, isipin natin na parang normal variable lang sya, ang ginagawa nya is idedelete nya yung order na nag-match sa auto it sa loob ng orders. */
	saveOrders(orders);
	
	cout<<"The order no."<<no<<" has been removed successfully."<<endl;
	readorder();
	pktc2();
}

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

/*int main() {
	string greeting = "Hello";
	//cout << "The is: " << greeting.size();
	//greeting[0] = 'h';
	cout << greeting;
	return 0;
}The backslash(\) escape character turns special characters into string characters :

int main() {
	string myString = "We are \"the\" winners";
	string myString2 = "We\'re \"the\" winners all the \\ time";
	string myString3 = "We will win\nyou will\tlose";
	cout << myString3;
	return 0;
}

// Input a string and print it after that
int main() {
	string firstName;
	cout << "Type your first name: ";
	getline(cin, firstName);
	cout << "Your name is: " << firstName;
	return 0;
} //This code will return all the text even spaces between text

int main() {
	std::string greetings = "Hello";
	std::cout << greetings;
	return 0;
}

int main() {
	int x = 5;
	int y = 9;
	int z = 5.999;
	int max1 = max(x, y);
	int sq = sqrt(y);
	int roun = round(z);
	cout << max1 << sq << roun;
	return 0;
}

IF, ELSE IF, ELSE STATEMENT

int main() {
	int myAge = 18;
	int votingAge = 18;

	if (myAge > votingAge) {
		cout << "Old enough to vote!";
	}
	else if (myAge == votingAge) {
		cout << "wow";
	}
	else {
		cout << "Not old enough!!!!!";
	
	}
}*/


class book {
private:
	char* author, * title, * publisher;
	float* price;
	int* stock;

public:
	book() {
		author = new char[20];
		title = new char[20];
		publisher = new char[20];
		price = new float;
		stock = new int;
	}

	void feedData();
	void editData();
	void showData();
	int search(char[], char[]);
	void buyBook();
};

void book::feedData() {
	cin.ignore();
	cout << "\nEnter Author Name: ";
	cin.getline(author, 20);
	cout << "Enter Title Name: ";
	cin.getline(title, 20);
	cout << "Enter Publisher: ";
	cin.getline(publisher, 20);
	cout << "Enter price: ";
	cin >> *price;
	cin.ignore();
	cout << "Enter Stock Position: ";
	cin >> *stock;
	cin.ignore();
}

void book::editData() {
	cout << "\nEnter Author Name: ";
	cin.getline(author, 20);
	cout << "Enter Title Name: ";
	cin.getline(title, 20);
	cout << "Enter Publisher: ";
	cin.getline(publisher, 20);
	cout << "Enter price: ";
	cin >> *price;
	cin.ignore();
	cout << "Enter Stock Position: ";
	cin >> *stock;
	cin.ignore();
}

void book::showData() {
	cout << "\nAuthor Name: "<<author;
	cout << "\nTitle Name: "<<title;
	cout << "\nPublisher: "<<publisher;
	cout << "\nEnter price: "<<*price;
	cout << "\nPosition: "<<*stock;
}

int book::search(char tbuy[20], char abuy[20]) {
	if (strcmp(tbuy, title) == 0 && strcmp(abuy, author) == 0)
		return 1;
	else return 0;
}

void book::buyBook() {
	int count;
	cout << "\nEnter Number of Books to buy: ";
	cin >> count;
	if (count <= *stock) {
		*stock = *stock - count;
		cout << "\nBooks Bought Succefully";
		cout << "\nAmount: $ " << (*price) * count;
	}
	else {
		cout << "\nRequired copies not in stock: ";
	}
}

int main() {
	book* B[20];
	int i = 0, r, t, choice;
	char titlebuy[20], authorbuy[20];
	while (1)
	{
		cout << "\n\n\t\tMENU"
			<< "\n1. Entry of New Book"
			<< "\n2. Buy Book"
			<< "\n3. Search For Book"
			<< "\n4. Edit Details of Book"
			<< "\n5. Exit"
			<< "\n\nEnter your Choice: ";
		cin >> choice; //cin is something the user insert, this case, it will be store in choice variable.

		switch (choice)
		{
		case 1: B[i] = new book;
			B[i]->feedData();
			i++;
			break;
		case 2: cin.ignore();
			cout << "\nEnter Title of book: ";
			cin.getline(titlebuy, 20);
			cout << "Enter Author of Book: ";
			cin.getline(authorbuy, 20);
			
			for (t = 0;t < i;t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					B[t]->buyBook();
					break;
				}
			}
			if (t == 1) {
				cout << "\nThis book is not in stock";
			}break;

		case 3: cin.ignore();
			cout << "\nEnter Title of book: ";
			cin.getline(titlebuy, 20);
			cout << "Enter author of book: ";
			cin.getline(authorbuy, 20);

			for (t = 0;t < i;t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nBook Found Successfully";
					B[t]->showData();
					break;
				}
			}
			if (t == i) {
				cout << "n\This book is not in stock";
			}
			break;

		case 4: cin.ignore();
			cout << "\nEnter title of book: ";
			cin.getline(titlebuy, 20);
			cout << "Enter author of book: ";
			cin.getline(authorbuy, 20);

			for (t = 0;t < i;t++) {
				if (B[t]->search(titlebuy, authorbuy)) {
					cout << "\nBook found successfully";
					B[t]->editData();
					break;
				}
			}
			if (t == i) {
				cout << "\nThis book is not in stock";
				
			}
			break;
		case 5: exit(0);
		default: cout << "\nInvalid choice entered";
		}
	}
	return 0;
}
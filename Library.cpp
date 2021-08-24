#include <iostream> 
#include <string>
using namespace std;

// our function which will tell the user what is the program and how it works
void welcome_message(){
	cout << "\tWELCOME TO LIBRARY MANAGEMENT SYSTEM!" << endl;
	cout << endl;
	cout << "How to Use(RULES):" << endl;
	cout << "1) You need to add books to the library using the book menu." << endl;
	cout << "2) Adding books to lists doesnt add the book to the library but confines it to the list." << endl;
	cout << "3) You need to add students using the students menu." << endl;
	cout << "4) Each Student can be Issued a Maximum of 5 Books." << endl;
	cout << "5) ID of any Book, Student or List CAN NOT be 0, 0 represents NULL/Empty in our program." << endl;
	cout << endl;
}

// our function which will display the main menu choices to the user
void display_menu(){
	cout << "Main Menu!" << endl;
	cout << "	1.Student" << endl;
	cout << "	2.Book" << endl;
	cout << "	3.List" << endl;
	cout << "	4.Library" << endl;
	cout << "	5.Exit" << endl;
	cout << "Enter the corresponding number to select your choice!" << endl;
}

// our student sub menu to display the options he has for student class
void display_student_menu(){
	cout << "Student Sub Menu!" << endl;
	cout << "	1.Add New Student" << endl;
	cout << "	2.Delete Existing Student" << endl;
	cout << "	3.Show Particular Student" << endl;
	cout << "	4.Show All Students" << endl;
	cout << "	5.Back" << endl;
	cout << "Enter the corresponding number to select your choice!" << endl;
}
// our book sub menu to display the options he has for book/booklist class
void display_book_menu(){
	cout <<"Book Sub Menu!" << endl;
	cout << "	1.Add New Book" << endl;
	cout << "	2.Delete Existing Book" << endl;
	cout << "	3.Show Particular Book" << endl;
	cout << "	4.Show All Books" << endl;
	cout << "	5.Sort Books In Ascending Order" << endl;
	cout << "	6.Sort Books In Descending Order" << endl;
	cout << "	7.Back" << endl;
	cout << "Enter the corresponding number to select your choice!" << endl;
}
// our student sub menu to display the options he has for list class
void display_list_menu(){
	cout << "List Sub Menu!" << endl;
	cout << "	1.Add New List" << endl;
	cout << "	2.Delete Existing List" << endl;
	cout << "	3.Show Particular List" << endl;
	cout << "	4.Show All Lists" << endl;
	cout << "	5.Back" << endl;
	cout << "Enter the corresponding number to select your choice!" << endl;
}
// our student sub menu to display the options he has for library class
void display_library_menu(){
	cout << "Library Sub Menu!" << endl;
	cout << "	1.Issued A Book" << endl;
	cout << "	2.Return A Book" << endl;
	cout << "	3.Print Books Issued" << endl;
	cout << "	4.Print Lists" << endl;
	cout << "	5.Back" << endl;
	cout << "Enter the corresponding number to select your choice!" << endl;
}
// our function which will display a message when the user desired to exit the program
void display_closing_msg(){
	cout << endl;
	cout << "Program Terminated!" << endl;
	cout << "Thank You for using the Library Management System!" << endl;
	cout << endl;
	cout << "\tMADE BY " << endl;
	cout << "Ashhar Shah" << endl;
}

// our structure of CBookNode which will store variable of the Book Class in order to Add or Delete Students
// declaring the structure outside of the class incase we need to use it in other classes in their functions
struct CBookNode{
	int ID;
	string BookName;
	string author;
	string ISBN;
	int price;
	int pages;
	int IssuedBy;
	string IssuedOn;
	string ReturnDate;	
	CBookNode* next;
};

class CBook{
	private:
		// the head of our node which posesses all the variables of this class
		CBookNode* Head;
	public:
		// our default constructor 
		CBook(){
			Head = NULL;
		};
		// our overloaded constructor to assign values taken as arguments into our data members
		CBook(int id, string name, string aut, string isbn, int pri, int pag){
			this -> Head->ID = id;
			this -> Head->BookName = name;
			this -> Head->author = aut;
			this -> Head->ISBN = isbn;
			this -> Head->price = pri;
			this -> Head->pages = pag;
			this -> Head->IssuedBy = 0;
			this -> Head->IssuedOn = "0";
			this -> Head->ReturnDate = "0";
			this -> Head->next = NULL;
		}
		// our destructor
		~CBook(){
			Head = NULL;
		};
		// our function which will return the value of the head incase it is needed in further steps
		CBookNode* getHead(){
			return Head;
		}
		// our get functions to return values of our data members
		int getid(){
			return Head->ID;
		}
		string getName(){
			return Head->BookName;
		}
		string getAuthor(){
			return Head->author;
		}
		string getISBN(){
			return Head->ISBN;
		}
		int getPrice(){
			return Head->price;
		}
		int getPages(){
			return Head->pages;
		}
		int getIssuedBy(){
			return Head->IssuedBy;
		}
		string getIssuedOn(){
			return Head->IssuedOn;
		}
		string getReturnDate(){
			return Head->ReturnDate;
		}
		// our set functions to set the value taken as arguments into our data members
		void setHead(CBookNode* h){
			Head = h;
		}
		void setName(string n){
			this -> Head->BookName = n;
		}
		void setAuthor(string aut){
			this -> Head->author = aut;
		}
		void setISBN(string isbn){
			this -> Head->ISBN = isbn;
		}
		void setPrice(int p){
			this -> Head->price = p;
		}
		void setPages(int p){
			this -> Head->pages = p;
		}
		void setIssuedBy(int ib){
			this -> Head->IssuedBy = ib;
		}
		void setIssuedOn(string io){
			this -> Head->IssuedOn = io;
		}
		void setReturnDate(string rd){
			this -> Head->ReturnDate = rd;
		}
		void setId(int id){
			this -> Head->ID = id;
	 	}
	 	// our function which will Add Book to the library
	 	void Add(){
	 		// getting the input for the book we want to add
	 		int BookId;
	 		string bookName;
	 		string authorName;
	 		string ibanNo;
	 		int bookPrice;
	 		int bookPages;
			cout << "Enter Book ID: ";
			cin >> BookId;
			if(BookId == 0){
				cout << "ID OF A BOOK, STUDENT OR LIST CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			cout << "Enter Book Name: ";
			cin.ignore();
			getline(cin, bookName);
			cout << "Enter Author of the Book: ";
			getline(cin, authorName);
			cout << "Enter IBAN Number of the Book: ";
			getline(cin,ibanNo);
			
			cout << "Enter Price of the Book: ";
			cin >> bookPrice;
			cout << "Enter Pages of the Book: ";
			cin >> bookPages;
			// making 2 nodes which will manage where to add the new book in the library
			CBookNode* newbook = new CBookNode;
	 		CBookNode* temp = new CBookNode;
	 		
	 		temp = Head;
	 		// this node will be used to store the data entered and will be joined to an empty end of our book node
 			newbook->ID = BookId;
 			newbook->BookName = bookName;
 			newbook->author = authorName;
 			newbook->ISBN = ibanNo;
 			newbook->price = bookPrice;
 			newbook->pages = bookPages;
 			newbook->IssuedBy = 0;
 			newbook->IssuedOn = "0";
 			newbook->ReturnDate = "0";
 			newbook->next = NULL;
	 			
	 		if(Head == NULL){
				Head = newbook;
				cout << "Book Added Sucessfully!" << endl;
				return;
			}
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newbook;
			cout << "Book Added Sucessfully!" << endl;
		}
		// our function to print the available books in the library to the user
		void PrintAll(){
			CBookNode* temp = new CBookNode;
			temp = Head;
			// if the first node is empty that means there are no books in the library/list
			if(temp == NULL){
				cout << "There are no books to display!" << endl;
				return;
			}
			else{
				while(temp != NULL){
					cout << "Book ID: " << temp->ID << endl;
					cout << "Book Name: " << temp->BookName << endl;
					cout << "Book Author: " << temp->author << endl;
					cout << "Book ISBN: " << temp->ISBN << endl;
					cout << "Book Price: " << temp->price << endl;
					cout << "Book Pages: " << temp->pages << endl;
					cout << "Issued On: " << temp->IssuedOn << endl;
					cout << "Issued By: " << temp->IssuedBy << endl;
					cout << "Return Date: " << temp->ReturnDate << endl;
					cout << endl;
					temp = temp->next;
				}
				return;
			}
		}
		// our function which will print information about a desired book to the user
		void PrintSome(){
			// this node will act as a copy to store the info that is to be displayed
			CBookNode* temp = new CBookNode;
			int id;
			int found = 0;
			temp = Head;
			// if the head is empty then the library contains no books
			if(Head == NULL){
				cout << "There are no books to display!" << endl;
				return;
			}
			// asking the user to input the id of the book for which he wants to display the details
			cout << "Enter the ID of the Book for which you want details!" << endl;
			cin >> id;
			// searching if the book exists in the library
			while(temp != NULL){
				if(temp->ID == id){
					found = 1;
					break;
				}
				temp = temp->next;
			}
			// if books exists then print the info else display warning to user
			if(found != 1){
				cout << "Book Not Found!" << endl;
				return;
			}
			else{
				cout << "Book ID: " << temp->ID << endl;
				cout << "Book Name: " << temp->BookName << endl;
				cout << "Book Author: " << temp->author << endl;
				cout << "Book ISBN: " << temp->ISBN << endl;
				cout << "Book Price: " << temp->price << endl;
				cout << "Book Pages: " << temp->pages << endl;
				cout << "Issued On: " << temp->IssuedOn << endl;
				cout << "Issued By: " << temp->IssuedBy << endl;
				cout << "Return Date: " << temp->ReturnDate << endl;
				cout << endl;
			}
		}
		// our function to delete the book from the library/list
		void Delete(){
			int id;
			int f = 1;
			int index = 1;
			int size = 0;
			
			cout << "Enter the ID of the Book you wish to Delete!" << endl;
			cin >> id;
			if(id == 0){
				cout << "ID OF A BOOK, STUDENT OR LIST CAN NOT BE 0! TRY AGAIN! " << endl;
				return;
 			}

			CBookNode* current = new CBookNode;
			CBookNode* sizecheck = new CBookNode;
			CBookNode* end = new CBookNode;
			
			sizecheck = Head;
			current = Head;
			end = Head;
			
			if(Head == NULL){
				cout << "There are No Books to Delete!" << endl;
				return;
			}
			// loop to check where in the linked list is the book located and does it even exist
			while(current != NULL){
				if(current->ID == id){
					f = 0;
					break;
				}
				index++;
				current = current->next;
			}
			// loop to calculate the size of the linked list
			while(sizecheck != NULL){
				size++;
				sizecheck = sizecheck->next;
			}
			if(f == 1){
				cout << "Book was not found in the list!" << endl;
				return;
			}
			// if the book is at the start then shift head node to the next book
			if(Head->ID == id && f == 0){
				Head = Head->next;
				cout << "Book was Deleted Sucessfully!" << endl << endl;
				return;
			}
			// if the book is at then end then detach the end node
			if(size == index && f == 0){
				while(end->next->next != NULL){
					end = end->next;
				}
				end->next = NULL;
				cout << "Book was Deleted Sucessfully!" << endl << endl;
				return;
			}
			// else if book is somewhere in between the list then delete the node and attach the previous one to the next one
			CBookNode* cur = new CBookNode;
			CBookNode* pre = new CBookNode;
			
			cur = Head;
			for(int i = 1; i < index; i++){
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
			cout << "Book was Deleted Sucessfully!" << endl << endl;
		}
};
// our class which will store books in different lists however this wont add them to the library
class CBookList{
	private:
		// our private variable for storing data into our list
		struct CBookListNode{
			CBook books;
			int ListID;
			CBookListNode* next;
		};
		// our head node which represents the first list
		CBookListNode* Head;
	public:
		// our default constructor
		CBookList(){
			Head = NULL;
		}
		// our overloaded constructor
		CBookList(CBook b, int lid){
			CBookListNode* Data = new CBookListNode;
			Data->books = b;
			Data->ListID = lid;
			Data->next = NULL;
			Head = Data;
		}
		// our destructor
		~CBookList(){
			Head = NULL;
		}
		// our getter functions
		CBook getbooks(){
			return Head->books;
		}
		int getid(){
			return Head->ListID;
		}
		// our setter functions
		void setbooks(CBook b){
			Head->books = b;
		}
		void setid(int id){
			Head->ListID = id;
		}
		// our function which will make new lists and add books to them, multiple books can be added once to a list
		void Add(){
			int id;
			int more = 0;
			// asking user to enter the id for the new list
			cout << "Enter the ID of the List " << endl;
			cin >> id;
			
			if(id == 0){
				cout << "ID OF A BOOK, STUDENT OR LIST CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			// nodes which control where to add the list
			CBookListNode* newlist = new CBookListNode;
			CBookListNode* temp = new CBookListNode;
			temp = Head;
			// CBook variable which will store data about the books to be added to the list
			CBook book;
			
			cout << "Enter Books to Add to this List!" << endl;
			// our loop which will check if the user wants to add more than one book to the current list
			while(more == 0){
				book.Add();
				cout << "Add more books to the list? Enter 0 for yes, Enter Anyother Number for No!" << endl;
				cin >> more;
			}
			// make a copy of the list that was created by the user
			newlist->ListID = id;
			newlist->books = book;
			newlist->next = NULL;
			// if the first list is empty then make this list the first one
			if(Head == NULL){
				Head = newlist;
				cout << "List Made Sucessfully!" << endl;
				return;
			}
			// else use a loop to go to the end of the lists and add a new list there
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newlist;
			cout << "List Made Sucessfully!" << endl;
		}
		// our function to print the list to the user based on the ID he entered
		void PrintSome(){
			int id;
			int f = 0;
			
			cout << "Enter the ID of the List!" << endl;
			cin >> id;
			
			CBookListNode* temp = new CBookListNode;
			CBookListNode* check = new CBookListNode;
			
			temp = Head;
			check = Head;
			// checking if the list even exists
			while(check != NULL){
				if(check->ListID == id){
					f = 1;
					break;
				}
				check = check->next;
			}
			// if list doesnt exist prompting the user
			if(f == 0){
				cout << "There is no list with that ID!" << endl;
				return;
			}
			// if the List is the first list then printing the first list
			if(Head->ListID == id){
				Head->books.PrintAll();
				return;
			}
			// else moving along till we find the list then print it
			else{
				while(temp->ListID != id){
					temp = temp->next;
				}
				temp->books.PrintAll();
			}
		}
		// our print all function that will print all the lists along with the books inside them
		void PrintAll(){
			CBookListNode* temp = new CBookListNode;
			temp = Head;
			if(temp == NULL){
				cout << "There are no lists to print!" << endl;
				return;
			}
			while(temp != NULL){
				cout << "List Number: " << temp->ListID << endl;
				temp->books.PrintAll();
				temp = temp->next;
			}
		}
		// our delete all function which will delete all the lists the user has made
		void DeleteAll(){
			Head = NULL;
			cout << "ALL LISTS SUCESSFULLY DELETED!" << endl;
		}
		// our delete function which will locate the list to be deleted and then remove the node from the list based on its location, Head Tail or Between
		void Delete(){
			int delid;
			int index = 1;
			int sizeoflist = 0;
			int found;
			
			cout << "Enter the ID of the List you wish to Delete!" << endl;
			cin >> delid;
			
			if(delid == 0){
				cout << "ID OF A STUDENT, LIST OR BOOK CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			
			CBookListNode* temp = new CBookListNode;
			CBookListNode* find = new CBookListNode;
			CBookListNode* size = new CBookListNode;
			CBookListNode* end = new CBookListNode;
			
			end = Head;
			find = Head;
			size = Head;
			
			while(find != NULL){
				if(find->ListID == delid){
					found = 1;
					break;
				}
				index++;
				find = find->next;
			}
			if (found == 0){
				cout << "There was no List with that ID!" << endl;
				return;
			}
			if(Head->ListID == delid){
				Head = Head->next;
				cout << "List Deleted Sucessfully!" << endl << endl;
				return;
			}
			while(size != NULL){
				sizeoflist++;
				size = size->next;
			}
			if(index == sizeoflist){
				while(end->next->next != NULL){
					end = end->next;
				}
				end->next = NULL;
				cout << "List Deleted Sucessfully!" << endl << endl;
				return;
			}
			CBookListNode* cur = new CBookListNode;
			CBookListNode* pre = new CBookListNode;
			
			cur = Head;
			for(int i = 1; i < index; i++){
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
			cout << "List Deleted Sucessfully!" << endl << endl;
		}
		// our sorting function which will sort books in ascending order based on their ID's
		void sortAsc(CBook b){
			CBookNode* library = new CBookNode;
			CBookNode* temp = new CBookNode;
			CBookNode* swap = new CBookNode;
			
			library = b.getHead();
			while(library->next != NULL){
				temp = library->next;
				while(temp != NULL){
					if(library->ID > temp->ID){
						// swapping all the data in one book to another book using a temporary book node
						swap->ID = library->ID;
						swap->author = library->author;
						swap->BookName = library->BookName;
						swap->ISBN = library->ISBN;
						swap->IssuedBy = library->IssuedBy;
						swap->IssuedOn = library->IssuedOn;
						swap->pages = library->pages;
						swap->price = library->price;
						swap->ReturnDate = library->ReturnDate;
						
						library->ID = temp->ID;
						library->author = temp->author;
						library->BookName = temp->BookName;
						library->ISBN = temp->ISBN;
						library->IssuedBy = temp->IssuedBy;
						library->IssuedOn = temp->IssuedOn;
						library->pages = temp->pages;
						library->price = temp->price;
						library->ReturnDate = temp->ReturnDate;
						
						temp->ID = swap->ID;
						temp->author = swap->author;
						temp->BookName = swap->BookName;
						temp->ISBN = swap->ISBN;
						temp->IssuedBy = swap->IssuedBy;
						temp->IssuedOn = swap->IssuedOn;
						temp->pages = swap->pages;
						temp->price = swap->price;
						temp->ReturnDate = swap->ReturnDate;
					}
					temp = temp->next;
				}
				library = library->next;
			}
			cout << "Books Sorted in Ascending Order!" << endl;
		}
		// our function which will sort the books in descending order based on the id of the books
		void sortDes(CBook b){
			CBookNode* library = new CBookNode;
			CBookNode* temp = new CBookNode;
			CBookNode* swap = new CBookNode;
			
			library = b.getHead();
			while(library->next != NULL){
				temp = library->next;
				while(temp != NULL){
					if(library->ID < temp->ID){
						// swapping all the data in one book to another book using a temporary book node
						swap->ID = library->ID;
						swap->author = library->author;
						swap->BookName = library->BookName;
						swap->ISBN = library->ISBN;
						swap->IssuedBy = library->IssuedBy;
						swap->IssuedOn = library->IssuedOn;
						swap->pages = library->pages;
						swap->price = library->price;
						swap->ReturnDate = library->ReturnDate;
						
						library->ID = temp->ID;
						library->author = temp->author;
						library->BookName = temp->BookName;
						library->ISBN = temp->ISBN;
						library->IssuedBy = temp->IssuedBy;
						library->IssuedOn = temp->IssuedOn;
						library->pages = temp->pages;
						library->price = temp->price;
						library->ReturnDate = temp->ReturnDate;
						
						temp->ID = swap->ID;
						temp->author = swap->author;
						temp->BookName = swap->BookName;
						temp->ISBN = swap->ISBN;
						temp->IssuedBy = swap->IssuedBy;
						temp->IssuedOn = swap->IssuedOn;
						temp->pages = swap->pages;
						temp->price = swap->price;
						temp->ReturnDate = swap->ReturnDate;
					}
					temp = temp->next;
				}
				library = library->next;
			}
			cout << "Books Sorted In Descending Order!" << endl;
		}
};

// our CStudent class which is also dynamically made using linked list in order for the add and delete functions to work
class CStudent{
	private:
		// these variables are made for the cStudentList class
		int id;
		string name;
		int roll;
		int* issuedbooks;
		// these variables are made for the cStudent class in order to add and delete students in the same class using linked lists
		struct CStudentNode{
			int ID;
			string StdName;
			int RollNo;
			int BooksIssued;
			CStudentNode* next;
		};
		CStudentNode* Head;
	public:
		// our default constructor
		CStudent(){
			issuedbooks = new int[5];
			for(int i = 0; i < 5; i++){
				issuedbooks[i] = 0;
			}
			Head = NULL;
		}
		// our overloaded constructor 
		CStudent(int i, string n, int rn, int bi){
			CStudentNode* newnode = new CStudentNode;
			newnode->ID = i;
			newnode->StdName = n;
			newnode->RollNo = rn;
			newnode->BooksIssued = bi;
			Head = newnode;
			Head->next = NULL;
			newnode = NULL;
		}
		// our destructor
		~CStudent(){
			Head = NULL;
		}
		// our getter functions 
		int getid(){
			return id;
		}
		string getName(){
			return name;
		}
		int getRoll(){
			return roll;
		}
		int* getBooksIssued(){
			return issuedbooks;
		}
		// our setter functions
		void setid(int i){
			this -> id = i;
		}
		void setName(string n){
			this-> name = n;
		}
		void setRoll(int r){
			this-> roll = r;
		}
		// this is an extra function that will be used in further CLibrary class to issue maximum 5 books to the student
		void setBooksIssued(int bi){
			int freeslot = 0;
			
			for (int i = 0; i < 5; i++){
				if(issuedbooks[i] == 0){
					freeslot = 1;
					issuedbooks[i] = bi;
					break;
				}
			}
			if(freeslot == 0){
				cout << "This student has been issued the maximum(5) number of books!" << endl;
				return;
			}
		}
		// this is a add function which will add students using linked list data structure
		void Add(){
			string n;
			int rn;
			int i;
			cout << "Enter the Name of the Student: " << endl;
			getline(cin, n);
			cout << "Enter the Roll Number of the Student: " << endl;
			cin >> rn;
			cout << "Enter the ID of the Student: " << endl;
			cin >> i;
			cin.ignore();
			
			if(i == 0){
				cout << "ID OF A STUDENT OR BOOK CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			
			CStudentNode* newnode = new CStudentNode;
			CStudentNode* temp = new CStudentNode;
			
			temp = Head;
			
			newnode->StdName = n;
			newnode->RollNo = rn;
			newnode->ID = i;
			newnode->BooksIssued = 0;
			newnode->next = NULL;
			
			if(Head == NULL){
				Head = newnode;
				return;
			}
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newnode;
			newnode = NULL;
		}
		// this function will print all the students in the linked list
		void PrintAll(){
			CStudentNode* temp = new CStudentNode;
			temp = Head;
			if(Head == NULL){
				cout << "There are no Students to print!" << endl;
				return;
			}
			while(temp != NULL){
				cout << "Students Name: " << temp->StdName << endl;
				cout << "Students Roll Number: " << temp->RollNo << endl;
				cout << "Students ID: " << temp->ID << endl;
				cout << "Books Issued: " << temp->BooksIssued << endl;
				temp = temp->next;
			}
		}
		// this function will find a student in the linked list based on the students id and then print its information
		void PrintSome(){
			CStudentNode* temp = new CStudentNode;
			int rn;
			int f = 0;
			temp = Head;
			cout << "Enter the Roll Number of the student whose details you want!" << endl;
			cin >> rn;
			
			if(rn == 0){
				cout << "ID OF A STUDENT, BOOK OR LIST CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			
			while(temp != NULL){
				if(temp->RollNo == rn){
					f = 1;
					break;
				}
				temp = temp->next;
			}
			if(f == 0){
				cout << "There was no student with the following Roll Number!" << endl;
				return;
			}
			cout << "Name of the Student: " << temp->StdName << endl;
			cout << "Roll Number of the Student: " << temp->RollNo << endl;
			cout << "The ID of the Student: " << temp->ID << endl;
			cout << "Books Issued: " << temp->BooksIssued << endl;
		}
		// this function will be used in the Return function of cLibrary class to return the book issued to the student
		void ResetBook(int b){
			for(int i = 0 ; i < 5; i++){
				if(issuedbooks[i] == b){
					issuedbooks[i] = 0;
				}
			}
		}
		// this function will be used to print the books issued to the student
		void PrintBooks(){
			int f = 0;
			for(int i = 0; i < 5; i++){
				if(issuedbooks[i] != 0){
					f = 1;
					cout << "ID: " << issuedbooks[i] << endl;
				}
			}
			// if the student has no books it will then prompt the user with the following message
			if(f == 0){
				cout << "No Books Issued!" << endl;
				return;
			}
		}
		// our boolean function which will check if the student has reached the maximum issuance limit(will be used in CLibrary)
		bool checkBooks(){
			for(int i = 0; i < 5; i++){
				if(issuedbooks[i] == 0){
					return false;
				}
			}
			return true;
		}
};

// declaring our structure outside the class for use in the CLibrary class for functions
struct CStudentListNode{
	CStudent std;
	CStudentListNode* next;
};


class CStudentList{
	private:
		// our head node which will contain info about students
		CStudentListNode* Head;
		
	public:
		CStudentList(){
			Head = NULL;
		}
		CStudentList(CStudentListNode* h){
			Head = h;
		}
		~CStudentList(){
			Head = NULL;
		}
		CStudentListNode* getHead(){
			return Head;
		}
		void setHead(CStudentListNode* h){
			Head = h;
		}
		// our add function which will add students to the end of the linked list
		void Add(){
			CStudentListNode* temp = new CStudentListNode;
			string name;
			int roll, id;
			
			cout << "Enter the Name of the Student: " << endl;
			getline(cin, name);
			cout << "Enter the Roll Number of the Student: " << endl;
			cin >> roll;
			cout << "Enter the ID of the Student: " << endl;
			cin >> id;
			cin.ignore();
			// incase of wrong input prompt the user and exit the function
			if(id == 0){
				cout << "ID OF A STUDENT OR BOOK CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}

			CStudentListNode* newnode = new CStudentListNode;

			temp = Head;
			newnode->std.setid(id);
			newnode->std.setName(name);
			newnode->std.setRoll(roll);
			newnode->std.setBooksIssued(0);
			newnode->next = NULL;
			
			if(Head == NULL){
				Head = newnode;
				cout << "Student Added Sucessfully!" << endl << endl;
				return;
			}
			
			while(temp->next != NULL){
				temp = temp->next;
			}
			temp->next = newnode;
			cout << "Student Added Sucessfully!" << endl << endl;
		}
		// our function which will print all the students that have been entered by the user
		void PrintAll(){
			CStudentListNode* temp = new CStudentListNode;
			temp = Head;
			if(Head == NULL){
				cout << "There are no Students in the List!" << endl;
				return;
			}
			while(temp != NULL){
				cout << "The Name of the Student: " << temp->std.getName() << endl;
				cout << "The Roll Number of the Student: " << temp->std.getRoll() << endl;
				cout << "The ID of the Student: " << temp->std.getid() << endl;
				cout << "Books Issued to the Student: " << endl;
				temp->std.PrintBooks();
				cout << endl;
				temp = temp->next;
			}
		}
		// our delete function which will find the student based on the ID of the student and then remove it from the linked list
		void Delete(){
			CStudentListNode* temp = new CStudentListNode;			
			CStudentListNode* sizelist = new CStudentListNode;
			CStudentListNode* findindex = new CStudentListNode;
			CStudentListNode* end = new CStudentListNode;
			int index = 1;
			
			temp = Head;
			sizelist = Head;
			findindex = Head;
			end = Head;
			
			int remid;
			int size = 0;
			int found = 0;
			
			cout << "Enter the ID of the Student who you want to remove!" << endl;
			cin >> remid;
			// incase of wrong input prompt the user 
			if(remid == 0){
				cout << "ID OF A STUDENT, LIST OR BOOK CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			
			if(Head->std.getid() == remid){
				Head = Head->next;
				cout << "Student Deleted Sucessfully!" << endl << endl;
				return;
			}
			while(sizelist != NULL){
				size++;
				sizelist = sizelist->next;
			}
			while(findindex != NULL){
				if(findindex->std.getid() == remid){
					found = 1;
					break;
				}
				index++;
				findindex = findindex->next;
			}
			if(found == 0){
				cout << "There is no Student with the Following ID in the List!" << endl;
				return;
			}
			if(size == index){
				while(end->next->next != NULL){
					end = end->next;
				}
				end->next = NULL;
				cout << "Student Deleted Sucessfully!" << endl;
				return;
			}
			CStudentListNode* cur = new CStudentListNode;
			CStudentListNode* pre = new CStudentListNode;
			cur = Head;
			for(int i = 1; i < index; i++){
				pre = cur;
				cur = cur->next;
			}
			pre->next = cur->next;
			cout << "Student Deleted Sucessfully!" << endl;
		}
		// our function that will print the info of a particular student by searching for him based on his student ID
		void PrintSome(){
			CStudentListNode* temp = new CStudentListNode;
			int found = 0;
			temp = Head;
			int id;
			cout << "Enter ID(not RollNo) of the Student who you want to print: " << endl;
			cin >> id;
			// incase of wrong input prompt the user
			if(id == 0){
				cout << "ID OF A STUDENT, BOOK OR LIST CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			// search if the student even exists, if not then prompt the user
			while(temp != NULL){
				if(temp->std.getid() == id){
					found = 1;
					break;
				}
				temp = temp->next;
			}
			if(found == 0){
				cout << "No Student with the following ID was found!" << endl;
				return;
			}
			cout << "Name of the Student: " << temp->std.getName() << endl;
			cout << "Roll Number of the Student: " << temp->std.getRoll() << endl;
			cout << "The ID of the Student: " << temp->std.getid() << endl;
			cout << "Books Issued to the Student: " << endl;
			temp->std.PrintBooks();
			cout << endl;
		}
		
};

// our Clibrary class which will be used to issued and return books to the student
class CLibrary{
	private:
		CBook CList;
		CStudentList stdlist;
	public:
		// default constructor
		CLibrary(){
		}
		// overloaded constructor
		CLibrary(CBook b, CStudentList l){
			this->CList = b;
			this->stdlist = l;
		}
		// destructor
		~CLibrary(){
		}
		// our function which will issue books to the students
		void Issue(){
			int bid;
			bool isfull = true;
			int found = 0;
			int stdfound = 0;
			int issuedto;
			cout << "Enter the ID of the Book to be Issued!" << endl;
			cin >> bid;

			if(bid == 0){
				cout << "ID OF A BOOK, STUDENT OR LIST CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			
			cout << "Enter the ID(not Roll Number) of the Student to whome the books is Issued!" << endl;
			cin >> issuedto;
			
			if(issuedto == 0){
				cout << "ID OF A BOOK, STUDENT OR LIST CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			
			cin.ignore();
			CBookNode* temp = new CBookNode;
			CStudentListNode* list = new CStudentListNode;
			
			list = stdlist.getHead();
			temp = CList.getHead();
			// search if the student who the book is being issued to is even in the system if not the prompt the user
			while(list != NULL){
				if(list->std.getid() == issuedto){
					stdfound = 1;
					isfull = list->std.checkBooks();
					// if the student is issued the maximum number of books then exit the function and prompt the user with the message
					if(isfull == true){
						cout << "This Student was Issued the Maximum Number of Books(5)" << endl;
						return;
					}
					list->std.setBooksIssued(bid);
				}
				list = list->next;
			}
			if(stdfound == 0){
				cout << "There was no student with the following ID!" << endl;
				return;
			}
			// set the date of issue, date of return of the book into the book database
			while(temp != NULL){
				if(temp->ID == bid){
					found = 1;
					string issdate;
					string expdate;
					int issuedby;
					cout << "Enter the Date of Issuance of the Book!" << endl;
					getline(cin, issdate);
					cout << "Enter the Date of Return of the Book!" << endl;
					getline(cin, expdate);
					cout << "Enter Who was the Books Issued By!(Integers)" << endl;
					cin >> issuedby;
					temp->IssuedBy = issuedby;
					temp->IssuedOn = issdate;
					temp->ReturnDate = expdate;
				}
				temp = temp->next;
			}
			// if the book entered was not in the database then prompt the user with a message
			if (found == 0){
				cout << "The Book was not found!" << endl;
				return;
			}
		}
		// our print function which will print lists of either a student or of the books in the library upon the users decision
		void Print(){
			char selection;
			cout << "Do you want to Print the List of Students or List of Books?" << endl;
			cout << "Enter S for Students, Enter L for Books!" << endl;
			cin >> selection;
			if(selection == 's' || selection == 'S'){
				stdlist.PrintAll();
			}
			else if(selection == 'L' || selection == 'l'){
				CList.PrintAll();
			}
			else{
				cout << "Invalid Input!" << endl;
				return;
			}
		}
		// this function will search the students in the database to see who were issued books and then print the books that were issued
		void PrintIssued(){
			CStudentListNode* list = new CStudentListNode;
			int found = 0;
			
			list = stdlist.getHead();
			
			cout << endl;
			cout << "Searching for Issued Books!" << endl;
			cout << endl;
			
			int* issued = new int[5];
			
			while(list != NULL){
				issued = list->std.getBooksIssued();
				for(int i = 0; i < 5; i++){
					if(issued[i] != 0){
						found = 1;
						cout << "Book ID: " << issued[i] << endl;
					}
				}
				list = list->next;
			}
			// if no book was issued then prompt the user
			if(found == 0){
				cout << "No Book Is Issued!" << endl;
				return;
			}
		}
		// our function which will be used to return the book back to the library
		void Return(){
			int retid;
			cout << "Enter the ID of the Book you want to return!" << endl;
			cin >> retid;
			// upon wrong input it will prompt the user
			if(retid == 0){
				cout << "ID OF A BOOK, STUDENT OR LIST CAN NOT BE 0! TRY AGAIN!" << endl;
				return;
			}
			
			CBookNode* temp = new CBookNode;
			CStudentListNode* list = new CStudentListNode;
			
			list = stdlist.getHead();
			temp = CList.getHead();
			// reset the return info about the book
			while(temp != NULL){
				if(temp->ID == retid){
					temp->ReturnDate = "0";
					temp->IssuedBy = 0;
					temp->IssuedOn = "0";
				}
				temp = temp->next;
			}
			// reset the info about the book issued to the student
			list->std.ResetBook(retid);
		}
};

int main(){
	// declaring our objects that will be used to handle the program
	CBook Books;
	CBookList Lists;
	CStudent Student;
	CStudentList StdList;
	// our variables that will be used to control the loops and flow of the program
	int mainchoice;
	int subchoice;
	// display a message to the user to know what is the program and how it functions
	welcome_message();
	
	// using loops to show menus to the user according to his choices
	while(mainchoice != 5){
		display_menu();
		cin >> mainchoice;
		if(mainchoice == 5){
			cin.ignore();
			break;
		}
		cin.ignore();
		if(mainchoice == 1){
			while(true){
				display_student_menu();
				cin >> subchoice;
				if(subchoice == 1){
					cin.ignore();
					StdList.Add();
				}
				else if(subchoice == 2){
					StdList.Delete();
				}
				else if(subchoice == 3){
					StdList.PrintSome();
				}
				else if(subchoice == 4){
					StdList.PrintAll();
					cout << endl;
				}
				else if(subchoice == 5){
					break;
				}
			}
			if(subchoice == 5){
				continue;
			}
		}
		else if(mainchoice == 2){
			while(true){
				display_book_menu();
				cin >> subchoice;
				if(subchoice == 1){
					Books.Add();
					cout << endl;
				}
				else if(subchoice == 2){
					Books.Delete();
					cout << endl;
				}
				else if(subchoice == 3){
					Books.PrintSome();
				}
				else if(subchoice == 4){
					Books.PrintAll();
				}
				else if(subchoice == 5){
					Lists.sortAsc(Books);
				}
				else if(subchoice == 6){
					Lists.sortDes(Books);
				}
				else if(subchoice == 7){
					break;
				}
			}
			if(subchoice == 7){
				continue;
			}
		}
		else if(mainchoice == 3){
			while(true){
				display_list_menu();
				cin >> subchoice;
				if(subchoice == 1){
					Lists.Add();
				}
				else if(subchoice == 2){
					Lists.Delete();
					cout << endl;
				}
				else if(subchoice == 3){
					Lists.PrintSome();
				}
				else if(subchoice == 4){
					Lists.PrintAll();
				}
				else if(subchoice == 5){
					break;
				}
			}
			if(subchoice == 5){
				continue;
			}
		}
		else if(mainchoice == 4){
			CLibrary Library(Books, StdList);
			while(true){
				display_library_menu();
				cin >> subchoice;
				if(subchoice == 1){
					Library.Issue();
				}
				else if(subchoice == 2){
					Library.Return();
				}
				else if(subchoice == 3){
					Library.PrintIssued();
				}
				else if(subchoice == 4){
					Library.Print();
				}
				else if(subchoice == 5){
					break;
				}
			}
			if(subchoice == 5){
				continue;
			}
		}
	}
	// if the user wishes to exit a program display a closing message to the user
	display_closing_msg();

	return 0;
}

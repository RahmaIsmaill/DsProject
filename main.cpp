#include <bits/stdc++.h>
using namespace std;
class Employee {
public:
    string name;
    int id;
    string Date_of_Joining;
    double salary;
    bool administrator;

    Employee(){}

    Employee(string name,int id,  string Date_of_Joining, double salary,  bool administrator)
    {
        this->name=name;
        this->id=id;
        this->Date_of_Joining=Date_of_Joining;
        this->salary=salary;
        this->administrator=administrator;
    }

    friend ostream& operator<<(ostream& Output, const Employee& emp) {
        Output << "Information about Employee number : "<<emp.id<<endl<<" -ID: " << emp.id<<endl<<
               " -Name: " << emp.name<<endl
               << " -Date of Joining: " << emp.Date_of_Joining<<endl<< " -Salary: $" << emp.salary<<endl
               << " -Administrator: " << (emp.administrator ? "YES" : "NO")<<endl;
        return Output;
    }
};
struct Node {
    Employee data;
    Node* next;
    Node(const Employee& emp)
    {
        this->data=emp;
        this->next=NULL;
    }
};

class Main {
private:
    Node* head;

public:
    Main() { head=NULL;}

    void Hire(const Employee& emp)
    {
        Node* newNode = new Node(emp);
        if (head == nullptr)
        {
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }
    }
    void Update(int id) {
        Node* element = head;
        while (element != nullptr) {
            if (element->data.id == id) {
                element->data.salary += element->data.salary * 0.50;
                return;
            }
            element = element->next;
        }
        cout << "Employee with ID " << id << " not found." << endl;
    }
    void PRINTA_SPEC_EMP(int id) {
        if (head == nullptr) {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node* current = head;
        while (current != nullptr) {
            if (current->data.id == id) {
                cout << current->data << endl;
                return;
            }
            current = current->next;
        }
        cout << "Employee with ID " << id << " not found.^^" << endl;
    }
    void PRINTA_ALL_EMPS()
    {
        if(head == NULL) {
            return void(cout << "Empty Linked List" << endl) ;
        }
        Node* current = head;
        while (current != NULL)
        {
            cout << current->data << endl;
            current = current->next;
        }
    }
    void PRINTA_EMPS_IN_RANGE(int Ssalary,int Esalary) {
        if (head == nullptr) {
            cout << "Empty Linked List" << endl;
            return;
        }
        Node* current = head;
        bool f=0;
        while (current != nullptr) {
            if (current->data.salary >=Ssalary && current->data.salary<=Esalary ) {
                cout << current->data << endl;
                f=1;
            }
            current = current->next;
        }
        if (!f) cout << "Employee with this range " << Ssalary <<" - " << Esalary<<" are not exist." << endl;
    }
    void print_sorted_by_name() {
        if (head == nullptr)
            return void(cout << "Empty Linked List" << endl);
        vector<Employee> vec;
        Node* current = head;
        while (current != NULL) {
            vec.push_back(current->data);
            current = current->next;
        }
        sort(vec.begin(), vec.end(), [](const Employee& a, const Employee& b) {
            return a.name < b.name;
        });

        for (const auto & i : vec)
            cout << i << endl;
    }
    void print_sorted_by_ID() {
        if (head == NULL)
            return void(cout << "Empty Linked List" << endl);
        vector<Employee> vec;
        Node* current = head;
        while (current != NULL) {
            vec.push_back(current->data);
            current = current->next;
        }
        sort(vec.begin(), vec.end(), [](const Employee& a, const Employee& b) {
            return a.id < b.id;
        });

        for (const auto & i : vec)
            cout << i << endl;
    }
    int Search_by_id(int ID) {
        int pos = 0;
        Node* element = head;
        while (element != nullptr) {
            if (element->data.id == ID) {
                return pos+1;
            }
            element = element->next;
            pos++;
        }

        return -1;
    }
    int Search_by_Name(const string& Name) {
        int pos = 0;
        Node* element = head;

        while (element != nullptr) {
            if (element->data.name == Name) {
                return pos+1;
            }
            element = element->next;
            pos++;
        }
        return -1;
    }
    void Delete(int ID ){
        Node *cur = head, *pre = nullptr;
        if(head == NULL) {
            cout << "Empty Linked List" << endl <<endl;
        }
        else {
            while(cur != NULL && cur->data.id!= ID){
                pre = cur;
                cur = cur->next;
            }
            if(cur == NULL) {
                cout << "Value not found in the Linked List" << endl<<endl;
            }
            else {
                if(pre == NULL){
                    head = cur->next;
                }
                else {
                    pre->next = cur->next;
                }
                delete cur;
            }
        }
    }
};
bool isAdmin;
int Id;
Main All_emp;
void INSERT(){
    cout << "Enter Number of Employees: "<<endl;
    int Number_Of_Employees;
    cin>>Number_Of_Employees;
    cout << "      ****Enter Information of Employees****" << endl<<endl;
    for (int i = 1; i <=Number_Of_Employees; i++) {
        cout << "Enter name of employee: ";
        string name;
        cin>>name;

        cout << "Enter hiring date of "<<name <<" : ";
        string Hire_date;
        cin >> Hire_date;

        cout << "Enter salary of "<<name<<" : ";
        double salary;
        cin >> salary;

        cout << "Enter ID of employee: ";
        int ID;
        cin >> ID;
        if(All_emp.Search_by_id(ID)==-1){
            Employee emp(name, ID, Hire_date, salary, isAdmin);
            All_emp.Hire(emp);}
        else { cout<<"ID MUST BE UNIQUE ENTER ANOTHER : ";
            cin>>ID;
            Employee emp(name, ID, Hire_date, salary, isAdmin);
            All_emp.Hire(emp);}
        cout << endl;
    }
}
void check() {
    INSERT();
    cout << "Is this Employee an administrator (1 for YES, 0 for NO): ";
    cin >> isAdmin;
    x:
    cout << "Enter operation you want to do on list: ";
    string op;
    cin >> op;
    if (isAdmin == false) {
        if (op == "Add" || op == "Update" || op == "Delete") {
            cout << "Only admins have this accessibility.  You can only Search or print \n";
            goto x;
        }

    }
    else {
        if (op == "Add")INSERT();

        else if (op == "Update") {

            cout << "Enter Employee id to Update salary : " << endl;
            cin >> Id;
            All_emp.Update(Id);
            All_emp.PRINTA_SPEC_EMP(Id);
        } else if (op == "Delete") {
            cout << "All Employees Information before deleting" << endl;
            All_emp.PRINTA_ALL_EMPS();
            cout << "Enter Employee id to be deleted  : " << endl;
            cin >> Id;
            All_emp.Delete(Id);
            //All_emp.PRINTA_ALL_EMPS();
            cout << "All Employees Information after deleting" << endl;
            All_emp.PRINTA_ALL_EMPS();
        }
    }
    if (op == "print_All") All_emp.PRINTA_ALL_EMPS();
    else if (op == "certain_employee") {
        cout << "Enter Id of certain_employee: ";
        int ID;
        cin >> ID;
        All_emp.PRINTA_SPEC_EMP(ID);
    } else if (op == "print_based_on_salaryRange") {
        cout << "Enter range of salaries : ";
        int Ssalary, Esalary;
        cin >> Ssalary >> Esalary;
        All_emp.PRINTA_EMPS_IN_RANGE(Ssalary, Esalary);
    } else if (op == "print_sorted_by_name") {
        cout << "       ****All Employees Information Sorted by Name ****   " << endl;
        All_emp.print_sorted_by_name();
    } else if (op == "print_sorted_by_ID") {
        cout << "       ****All Employees Information Sorted by ID****   " << endl;
        All_emp.print_sorted_by_ID();

    } else if (op == "Search_By_Name") {
        string name;
        cout << "Enter Employee name to Search for " << endl;
        cin >> name;
        int pos = All_emp.Search_by_Name(name);
        if (pos == -1)
            cout << "Employee is not found" << endl;
        else
            cout << "Employee is found at pos: " << pos << endl;
    } else if (op == "Search_By_ID")
    {
        int id;
        cout << "Enter Employee id to Search for " << endl;
        cin >> id;
        if (All_emp.Search_by_id(id) == -1)
            cout << "Employee is not found" << endl;
        else cout << "Employee is found At pos: " << All_emp.Search_by_id(id) << endl;
    }
    char next;
    cout<<"Anthor Operation? Y\\N";
    cin>>next;
    if (next=='Y')
        goto x;
}
int main() {
    check();
}

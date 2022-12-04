#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <stdio.h>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <list>

using namespace std;
int size_l;

list<string> book_names;
vector<vector<string>> chrVector/*{ {"1", "2", "13" }, {"2", "1","13","4"}, {"7", "8"}, {"2", "13","4",}, {"15", "1","2","4"} }*/;
struct list_s_book
{
    int date_s;
    string name_s;
    string author_s;
    int amount_of_pages_s;
    list_s_book operator = (list_s_book a)
    {
        this->date_s = a.date_s;
        this->name_s = a.name_s;
        this->author_s = a.author_s;
        this->amount_of_pages_s = a.amount_of_pages_s;
        return *this;
    }
};
struct list_s
{
    list_s_book mass[100];
    int last;
};
list_s a;
class Book {
public:
    char name[256];
    char author[256];
    int date;
    int amount_of_pages;
    char annottation[256];
};
Book book;
class Сharacter {
public:
    string ch_name;
    vector<string> books;
    vector<string> roles;
};
struct Node {
    char l_name[256];
    char l_author[256];
    int l_date;
    int l_amount_of_pages;
    char l_annottation[256];
    Node* next;
    Node* prev;
};
struct List {
    Node* head = nullptr;
    Node* tail = nullptr;
    int push() {
        Book book;
        FILE* b;
        if ((b = fopen("books.txt", "r+b")) == NULL) {
            perror("Error occured while opening file");
            return 1;
        }
        while (fread(&book, sizeof(class Book), 1, b) == 1) {
            Node* ptr = new Node;
            ptr->next = NULL;
            ptr->l_amount_of_pages = book.amount_of_pages;
            strcpy(ptr->l_annottation, book.annottation);
            strcpy(ptr->l_author, book.author);
            ptr->l_date = book.date;
            strcpy(ptr->l_name, book.name);
            if (head != NULL) {
                ptr->prev = tail;
                tail->next = ptr;
                tail = ptr;
            }
            else {
                ptr->prev = NULL;
                head = tail = ptr;
            }
        }
        fclose(b);
        return 0;
    }
    int push_last() {

        FILE* b;
        if ((b = fopen("books.txt", "r+b")) == NULL) {
            perror("Error occured while opening file");
            return 1;
        }
        fseek(b, size_l * sizeof(class Book), 0);
        fread(&book, sizeof(class Book), 1, b);
        Node* ptr = new Node;
        ptr->next = NULL;
        ptr->l_amount_of_pages = book.amount_of_pages;
        strcpy(ptr->l_annottation, book.annottation);
        strcpy(ptr->l_author, book.author);
        ptr->l_date = book.date;
        strcpy(ptr->l_name, book.name);
        if (head != NULL) {
            ptr->prev = tail;
            tail->next = ptr;
            tail = ptr;
        }
        else {
            ptr->prev = NULL;
            head = tail = ptr;
        }

        fclose(b);
        return 0;
    }
    int showl() {
        Node* ptr = head;
        while (ptr != NULL) {
            cout << ptr->l_name << " " << ptr->l_author << " " << ptr->l_date << " " << ptr->l_amount_of_pages << " " << ptr->l_annottation << endl;
            ptr = ptr->next;
        }
        return 0;
    }
    int search_d(string s) {

        Node* ptr = head;

        while (ptr != NULL) {

            if (ptr->l_name == s) {
                return ptr->l_date;

            }

            ptr = ptr->next;
        }


    }
    int search_p(string s) {

        Node* ptr = head;

        while (ptr != NULL) {

            if (ptr->l_name == s) {
                return ptr->l_amount_of_pages;

            }

            ptr = ptr->next;
        }


    }
    string search_a(string s) {

        Node* ptr = head;

        while (ptr != NULL) {

            if (ptr->l_name == s) {
                return ptr->l_author;

            }

            ptr = ptr->next;
        }


    }
    int sort_big_amount_of_pages_buble_sort() {
        /* Node* ptr = head;*/
        int temp_p; // временная переменная для обмена элементов местами
        int temp_d;
        char temp_n[256];
        char temp_a[256];
        char temp_an[256];
        // Сортировка массива пузырьком
        for (int i = 0; i < size_l - 1; i++) {
            Node* ptr = head;
            for (int j = 0; j < size_l - i - 1; j++) {

                if (ptr->l_amount_of_pages > ptr->next->l_amount_of_pages) {
                    // меняем элементы местами
                    temp_p = ptr->l_amount_of_pages;
                    ptr->l_amount_of_pages = ptr->next->l_amount_of_pages;
                    ptr->next->l_amount_of_pages = temp_p;

                    temp_d = ptr->l_date;
                    ptr->l_date = ptr->next->l_date;
                    ptr->next->l_date = temp_d;

                    strcpy(temp_n, ptr->l_name);
                    strcpy(ptr->l_name, ptr->next->l_name);
                    strcpy(ptr->next->l_name, temp_n);

                    strcpy(temp_a, ptr->l_author);
                    strcpy(ptr->l_author, ptr->next->l_author);
                    strcpy(ptr->next->l_author, temp_a);

                    strcpy(temp_an, ptr->l_annottation);
                    strcpy(ptr->l_annottation, ptr->next->l_annottation);
                    strcpy(ptr->next->l_annottation, temp_an);
                }
                ptr = ptr->next;
            }
        }

        return 0;
    }
    int sort_big_name_clist_sort() {
        Node* ptr = head;
        while (ptr != NULL) {
            book_names.push_back(ptr->l_name);
            ptr = ptr->next;
        }

        return 0;
    }
    int sort_big_date_quick_sort() {
        /* Node* ptr = head;*/
        int temp_p; // временная переменная для обмена элементов местами
        int temp_d;
        char temp_n[256];
        char temp_a[256];
        char temp_an[256];
        // Сортировка массива пузырьком
        for (int i = 0; i < size_l - 1; i++) {
            Node* ptr = head;
            for (int j = 0; j < size_l - i - 1; j++) {

                if (ptr->l_date > ptr->next->l_date) {
                    // меняем элементы местами
                    temp_p = ptr->l_amount_of_pages;
                    ptr->l_amount_of_pages = ptr->next->l_amount_of_pages;
                    ptr->next->l_amount_of_pages = temp_p;

                    temp_d = ptr->l_date;
                    ptr->l_date = ptr->next->l_date;
                    ptr->next->l_date = temp_d;

                    strcpy(temp_n, ptr->l_name);
                    strcpy(ptr->l_name, ptr->next->l_name);
                    strcpy(ptr->next->l_name, temp_n);

                    strcpy(temp_a, ptr->l_author);
                    strcpy(ptr->l_author, ptr->next->l_author);
                    strcpy(ptr->next->l_author, temp_a);

                    strcpy(temp_an, ptr->l_annottation);
                    strcpy(ptr->l_annottation, ptr->next->l_annottation);
                    strcpy(ptr->next->l_annottation, temp_an);
                }
                ptr = ptr->next;
            }
        }

        return 0;
    }
};
int sort_sm_name_quicksort(int size) {

    int i = 0;
    int j = size - 1;


    string mid = a.mass[size / 2].name_s;


    do {

        while (a.mass[i].name_s < mid) {
            i++;
        }

        while (a.mass[j].name_s > mid) {
            j--;
        }


        if (i <= j) {
            string tmp = a.mass[i].name_s;
            a.mass[i].name_s = a.mass[j].name_s;
            a.mass[j].name_s = tmp;

            i++;
            j--;
        }
    } while (i <= j);



    if (j > 0) {

        sort_sm_name_quicksort(j + 1);
    }
    if (i < size) {

        sort_sm_name_quicksort(size - i);
    }
    return 0;
}
int sort_sm_amount_of_pages_insertion_sort(int size) {
    int counter = 0;
    for (int i = 1; i < size; i++) {
        for (int j = i; j > 0 && a.mass[j - 1].amount_of_pages_s > a.mass[j].amount_of_pages_s; j--) {
            counter++;
            int tmp = a.mass[j - 1].amount_of_pages_s;
            string tmp2 = a.mass[j - 1].name_s;
            a.mass[j - 1].amount_of_pages_s = a.mass[j].amount_of_pages_s;
            a.mass[j - 1].name_s = a.mass[j].name_s;
            a.mass[j].amount_of_pages_s = tmp;
            a.mass[j].name_s = tmp2;
        }
    }
    return 0;
}

int merge_sort(int first, int last) {

    int middle, start, final, j;
    int* mas2 = new int[100];
    string* mas1 = new string[100];
    middle = (first + last) / 2;
    start = first;
    final = middle + 1;
    for (j = first; j <= last; j++)
        if ((start <= middle) && ((final > last) || (a.mass[start].date_s < a.mass[final].date_s)))
        {
            mas2[j] = a.mass[start].date_s;
            mas1[j] = a.mass[start].name_s;
            start++;
        }
        else
        {
            mas2[j] = a.mass[final].date_s;
            mas1[j] = a.mass[start].name_s;
            final++;
        }

    for (j = first; j <= last; j++) {
        a.mass[j].date_s = mas2[j];
        a.mass[j].name_s = mas1[j];
    }
    delete[]mas2;
    delete[]mas1;
    return 0;
}
int sort_sm_date_merge_sort(int first, int last) {

    if (first < last)
    {
        sort_sm_date_merge_sort(first, (first + last) / 2);
        sort_sm_date_merge_sort((first + last) / 2 + 1, last);
        merge_sort(first, last);
    }
    return 0;
}
int build_classes(List list) {
    int A[50];
    int m = chrVector.size();

    for (int i = 0; i < m; i++) A[i] = 1;
    for (int i = 0; i < m; i++) {
        for (int l = 0; l < m; l++) {
            int ss = 0;
            for (int j = 0; j < chrVector[i].size(); j++) {
                int s = 0;
                for (int p = 0; p < chrVector[l].size(); p++) {
                    if (i != l && A[i] != 0) {
                        if (chrVector[i][j] == chrVector[l][p]) s = 1;
                    }
                }
                ss = ss + s;

            }

            if (chrVector[i].size() == ss) A[i] = 0;

        }
    }
    //////////////////////////////////////


    for (int i = 0; i < m; i++) {
        if (A[i] == 1) {
            for (int j = 0; j < chrVector[i].size(); j++) {
                /* cout << a.mass[j].name_s;*/
                a.mass[j].date_s = list.search_d(chrVector[i][j]);
                a.mass[j].name_s = chrVector[i][j];
                a.mass[j].author_s = list.search_a(chrVector[i][j]);
                a.mass[j].amount_of_pages_s = list.search_p(chrVector[i][j]);
                /* cout << a.mass[j].date_s << " " << a.mass[j].name_s;*/
                /* sort_sm_name_quicksort(chrVector[i].size(), a);*/
                 /* cout <<  a.mass[j].name_s;*/
            }
            cout << "Which way of sort do you want?" << endl;
            cout << "1-name_sort;" << endl;
            cout << "2-amount_of_pages_sort;" << endl;
            cout << "3-date_sort;" << endl;
            int k;
            cin >> k;
            switch (k) {
            case 1:
                sort_sm_name_quicksort(chrVector[i].size());
                for (int j = 0; j < chrVector[i].size(); j++) {
                    cout << a.mass[j].name_s << endl;
                }
                break;
            case 2:
                sort_sm_amount_of_pages_insertion_sort(chrVector[i].size());
                for (int j = 0; j < chrVector[i].size(); j++) {
                    cout << a.mass[j].name_s << " " << a.mass[j].amount_of_pages_s << endl;
                }
                break;
            case 3:
                sort_sm_date_merge_sort(0, chrVector[i].size() - 1);
                for (int j = 0; j < chrVector[i].size(); j++) {
                    cout << a.mass[j].name_s << " " << a.mass[j].date_s << endl;
                }
                break;
            }
            ///
           /* sort_sm_name_quicksort(chrVector[i].size());
            for (int j = 0; j < chrVector[i].size(); j++) {
                cout << a.mass[j].name_s<<endl;
            }*/
            ////////////////
           /* sort_sm_amount_of_pages_insertion_sort(chrVector[i].size());
            for (int j = 0; j < chrVector[i].size(); j++) {
                cout << a.mass[j].name_s << " " << a.mass[j].amount_of_pages_s<<endl;
            }*/
            ////////////////
            /*sort_sm_date_merge_sort(0, chrVector[i].size() - 1);
            for (int j = 0; j < chrVector[i].size(); j++) {
                cout << a.mass[j].name_s << " " << a.mass[j].date_s << endl;
            }*/

        }
        cout << endl;
    }
    ////////////////

    return 0;
}
void text_menu() {
    cout << "------------------------------------------------" << endl;
    cout << "[1] show the list of books;" << endl;
    cout << "[2] show and read characters;" << endl;
    cout << "[3] build series of books;" << endl;
    cout << "[4] sort list by amount of pages;" << endl;
    cout << "[5] sort list by name of books;" << endl;
    cout << "[6] sort list by dates;" << endl;
   // cout << "[7] insert book;" << endl;

    cout << "------------------------------------------------" << endl;
}
int read_characters() {
    ifstream filer;
    Сharacter charact;
    filer.open("characters.txt");
    int i = -1;
    int j = 0;
    while (!filer.eof()) {
        i++;
        string s;
        getline(filer, s);
        charact.ch_name = s;
        stringstream x;
        string word;
        getline(filer, s);
        x << s;
        vector<string> temp;
        chrVector.push_back(temp);
        while (x >> word) {
            charact.books.push_back(word);
            chrVector[i].push_back(word);

        }

        getline(filer, s);
        stringstream y;
        y << s;
        while (y >> word) {
            charact.roles.push_back(word);

        }
        
        cout << "*" << charact.ch_name << endl;
        for (int j = 0; j < charact.books.size(); j++) {
            cout << "||" << charact.books[j] << "(" << charact.roles[j] << ")" << endl;
        }

        charact.books.clear();
        charact.roles.clear();
        
    }



    filer.close();
    return 0;
}
int insert_b() {
    FILE* b;
    if ((b = fopen("books.txt", "a+b")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    cout << "name of book: ";
    cin>>book.name;
    cout << "author: ";
    cin >> book.author;
    cout << "date: ";
    cin >> book.date;
    cout << "ammount of pages: ";
    cin >> book.amount_of_pages;
    cout << "annottation: ";
    cin >> book.annottation;
    fseek(b, (size_l + 1) * sizeof(class Book), 0);
    fwrite(&book, sizeof(class Book), 1, b);
    size_l++;
    fclose(b);
}

int main()
{
    ifstream file;

    FILE* b;
    if ((b = fopen("books.txt", "a+b")) == NULL) {
        perror("Error occured while opening file");
        return 1;
    }
    size_l = 11;
    List list;
    ofstream filew;
    ifstream filer;

    int variant;
    list.push();
    list.sort_big_name_clist_sort();
    while (true) {

        text_menu();
        cout << "choose your action: ";
        cin >> variant;
        switch (variant) {
        case 1:
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            list.showl();
            break;
        case 2:
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            read_characters();
            break;
        case 3:
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            build_classes(list);
            break;
        case 4:
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            list.sort_big_amount_of_pages_buble_sort();
            list.showl();
            break;
        case 5:
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;

            book_names.sort();
            for (auto iter = book_names.begin(); iter != book_names.end(); iter++)
            {
                std::cout << *iter << "\n";
            }

            break;
        case 6:
            cout << "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++" << endl;
            list.sort_big_date_quick_sort();
            list.showl();
            break;
        case 7:
            insert_b();
            list.push_last();
            break;
        }
    }
    fclose(b);
    return 0;
}


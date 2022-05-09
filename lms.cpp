/*By default , these are the registered users in Library Management System 
Students:
UserId : 0, Name : Pratham , password : pratham
Professors:
UserId : 1, Name : Indranil , password : cs253
Librarian:
UserId : 2, Name : XYZ , password : library

By default, these are the books present 
BookId : 1, Name : thermo , owner : narayan
BookId : 2, Name : computer , owner : pinaki
BookId : 3, Name : hss , owner : ABC
BookId : 4, Name : arch , owner : urbic


Some general Instructions
 
UserId and BookID are numeric and you should remember them to access your account.
*/

#include<bits/stdc++.h>
using namespace std;
class book{
    public:
    static int ID1;
    int bid;
    string title;
    string author;
    int available;
    int owner;
    book(){
        ID1++;
        bid=ID1;
    }

};
int book::ID1=0;
class user{
    public:
    static int ID2;
    int uid;
    string name;
    string password;
    int book_issued;
    user()
    {
        uid=ID2;
        book_issued=0;
    }
};
int user::ID2=0;
class prof:public user{
    public:
    int fine;
    prof(){
        ID2++;
    }
    vector<book>pb;
    void display()
    {
        cout<<"\nUser ID: "<<uid<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Role : Professor\n";
    }
    void display_issued_books()
    {
        cout<<"\nYou have issued "<<pb.size()<<" books.\n";
        for(int i=0;i<pb.size();i++)
        cout<<"Book ID : "<<pb[i].bid<<"    Book Name : "<<pb[i].title<<"    Book Author : "<<pb[i].author<<"\n";
    }
};

class student:public user{
    public:
    int fine;
    student(){
        ID2++;
    }
    vector<book>sb;
    void display()
    {
        cout<<"\nUser ID: "<<uid<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Role : Student\n";
    }
    void display_issued_books()
    {
        cout<<"\nYou have issued "<<sb.size()<<" books.\n";
        for(int i=0;i<sb.size();i++)
        cout<<"Book ID : "<<sb[i].bid<<"    Book Name : "<<sb[i].title<<"    Book Author : "<<sb[i].author<<"\n";
    }
};
class lib:public user{
    public:
    lib(){
        ID2++;
    }
    void display()
    {
        cout<<"\nUser ID: "<<uid<<"\n";
        cout<<"Name: "<<name<<"\n";
        cout<<"Role : Librarian\n";
    }
};
class prof_database{
    public:
    vector<prof>all_prof;
    void add_prof(prof a){
        all_prof.push_back(a);
    }
    void remove_prof(int id)
    {
        for(int i=0;i<all_prof.size();i++)
        {
            if(all_prof[i].uid==id)
            all_prof.erase(all_prof.begin()+i);
        }
        cout<<"Professor Removed\n";
        return;
    }
    int is_prof_present(int id)
    {
        for(int i=0;i<all_prof.size();i++)
        if(all_prof[i].uid==id)
        return 1;
        return 0;
    }
    prof search_prof(int id){
    for(int i=0;i<all_prof.size();i++)
    {
        if(all_prof[i].uid==id)
        return all_prof[i];
    }
    return all_prof[0];
    }

};
class lib_database{
public:
    vector<lib>all_lib;
    int is_lib_present(int id)
    {
        for(int i=0;i<all_lib.size();i++)
        if(all_lib[i].uid==id)
        return 1;
        return 0;
    }
    lib search_lib(int id){
    for(int i=0;i<all_lib.size();i++)
        if(all_lib[i].uid==id)
        return all_lib[i];
        return all_lib[0];
    }
};
class student_database{
    public:
    vector<student>all_students;
    void add_student(student a){
        all_students.push_back(a);
    }
    int is_student_present(int id)
    {
        for(int i=0;i<all_students.size();i++)
        if(all_students[i].uid==id)
        return 1;
        return 0;
    }
    student search_student(int id){
    for(int i=0;i<all_students.size();i++)
        if(all_students[i].uid==id)
        return all_students[i];
        return all_students[0];
    }
    void remove_student(int id)
    {
        for(int i=0;i<all_students.size();i++)
        {
            if(all_students[i].uid==id)
            all_students.erase(all_students.begin()+i);
        }
        cout<<"Student Removed\n";
        return;
    }

};


class book_database{
    public:
    vector<book>all_books;
    void add_book()
    {
        book a;
        string x;
        cout<<"\nEnter book title\n";
        //cin>>x;
        getchar();
        getline(cin,x);
        a.title=x;
        cout<<"Enter book author\n";
        //cin>>x;
        getchar();
        getline(cin,x);
        a.author=x;
        a.available=1;
        a.owner=-1;
        all_books.push_back(a);
    }
    int delete_book(int id)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==id)
            {
               //delete from owner
                all_books.erase(all_books.begin()+i);
                return 1;
            }
        }
        return 0;
    }
    void display()
    {
        cout<<"\n";
        for(int i=0;i<all_books.size();i++)
        {
            cout<<"Book ID : "<<all_books[i].bid<<"      Book Name : "<<all_books[i].title<<"      Book Author : "<<all_books[i].author<<"\n";
        }
    }
    void display_available()
    {
        cout<<"\n";
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].available==1)
              cout<<"Book ID : "<<all_books[i].bid<<"      Book Name : "<<all_books[i].title<<"      Book Author : "<<all_books[i].author<<"\n";
        }
    }
    int issue_book(int bookid,int userid)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==bookid)
            {
                if(all_books[i].available==0)
                return 1;
                else
                {
                    all_books[i].available=0;
                    all_books[i].owner=userid;
                    return 2;
                }
            }
        }
        return 3;
    }
    int is_book_available(int bookid)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==bookid)
            {
                if(all_books[i].available==0)
                return 1;
                else
                {
                    return 2;
                }
            }
        }
        return 3;

    }
    int return_book(int bookid,int userid)
    {
        for(int i=0;i<all_books.size();i++)
        {
            if(all_books[i].bid==bookid)
            {
                if(all_books[i].available==1)
                return 1;
                else
                {
                    all_books[i].available=1;
                    all_books[i].owner=-1;
                    return 2;
                }
            }
        }
        return 3;
    }
    book search_book(int id)   //made to work only when book with this id is present
    {
        for(int i=0;i<all_books.size();i++)
        if(all_books[i].bid==id)
        return all_books[i];
        return all_books[0];//control never reaches here
    }
};

//-----------------------------------------------------------------------------------------------------------------

int first_call(){
    cout<<"\n\nAre you a student, professor or librarian? \nPress 1 if you are student.\nPress 2 if you are professor.\nPress 3 if you are librarian.\n\n";
    int x;
    cin>>x;
    if(x==1||x==2||x==3)
    return x;
    else{
    cout<<"Please enter valid input\n";
    return first_call();
    }   
}
int login_call()
{
    cout<<"\n\nEnter 1 to login or 2 to register.\nEnter 3 to go back\n\n";
    int x;
    cin>>x;
    if(x==1||x==2||x==3)
    return x;
    else
    {
     cout<<"Please enter valid input\n";
     return login_call();   
    }
}
int lib_login_call()
{
    cout<<"\n\nEnter 1 to login.\nEnter 2 to go back\n\n";
    int x;
    cin>>x;
    if(x==1||x==2)
    return x;
    else
    {
     cout<<"Please enter valid input\n";
     return lib_login_call();   
    }
}
int function_call()
{
    cout<<"\n\nEnter 1 to view your profile\n";
    cout<<"Enter 2 to view all books\n";
    cout<<"Enter 3 to view available books\n";
    cout<<"Enter 4 issue a book\n";
    cout<<"Enter 5 to return book\n";
    cout<<"Enter 6 to view your issued books\n";
    cout<<"Enter 7 to show current fine\n";
    cout<<"Enter 8 to clear fine\n";
    cout<<"Enter 9 to check availablabilty of particular book.\n";
    cout<<"Enter 10 to logout\n\n\n";
    int x;
    cin>>x;
    if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8||x==9||x==10)
    return x;
    else
    {
        cout<<"Please enter valid input\n";
        return function_call();
    }
}
int lib_function_call()
{
    cout<<"\n\n";
    cout<<"Enter 1 to view your profile\n";
    cout<<"Enter 2 to view all books\n";
    cout<<"Enter 3 to view available books\n";
    cout<<"Enter 4 to list all users\n";
    cout<<"Enter 5 add a book\n";
    cout<<"Enter 6 to delete a book\n";
    cout<<"Enter 7 add a student\n";
    cout<<"Enter 8 to delete a student\n";
    cout<<"Enter 9 to add a prof\n";
    cout<<"Enter 10 to delete a prof\n";
    cout<<"Enter 11 to  issued books with users\n";
    // cout<<"Enter 12 to show current status of book\n";
    // cout<<"Enter 13 to show current status of user\n";
    cout<<"Enter 12 to logout\n\n\n";
    int x;
    cin>>x;
    // if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8||x==9||x==10||x==11||x==12||x==13||x==14)
    if(x==1||x==2||x==3||x==4||x==5||x==6||x==7||x==8||x==9||x==10||x==11||x==12)
    return x;
    else
    {
        cout<<"Please enter valid input\n";
        return lib_function_call();
    }
}
int main()
{
    student_database sd;
    prof_database pd;
    lib_database ld;
    book_database bd;
    //----------------------------------------------------------------------------------------------------------------
    book b1;
    b1.title="thermo";
    b1.author="narayan";
    b1.available=0;
    b1.owner=0;

    book b2;
    b2.title="computer";
    b2.author="pinaki";
    b2.available=0;
    b2.owner=1;
    
    book b3;
    // b3.bid=2;
    b3.title="hss";
    b3.author="ABC";
    b3.available=1;
    b3.owner=-1;
    
    book b4;
    // b4.bid=3;
    b4.title="arch";
    b4.author="urbic";
    b4.available=1;
    b4.owner=-1;

    bd.all_books.push_back(b1);
    bd.all_books.push_back(b2);
    bd.all_books.push_back(b3);
    bd.all_books.push_back(b4);

    student s1;
    s1.uid=0;
    s1.name="Pratham";
    s1.password="pratham";
    s1.fine=0;
    s1.sb.push_back(b1);

    prof p1;
    p1.uid=1;
    p1.name="Indranil";
    p1.password="cs253";
    p1.fine=0;
    p1.pb.push_back(b2);

    lib l1;
    l1.uid=2;
    l1.name="XYZ";
    l1.password="library";
    ld.all_lib.push_back(l1);

    sd.all_students.push_back(s1);
    pd.all_prof.push_back(p1);
    ld.all_lib.push_back(l1);
    //------------------------------------------------------------------------------------------------
    while(1)
    {
        int x=first_call();
        if(x==1)
        {
            cout<<"\nWelcome,Student\n\n";
            while(1)
            {
                int flag=1;
                int y=login_call();
                if(y==3)
                break;
                else if(y==1)
                {
                    student curr;
                        cout<<"\nEnter ID : ";
                        int id;
                        cin>>id;
                        int t=sd.is_student_present(id);
                        if(t==0)
                        {
                            cout<<"This user doesn't exist.\n";
                            flag=0;

                        }
                        else
                        {
                            curr=sd.search_student(id);
                            string x;
                            cout<<"Enter password\n";
                            //cin>>x;
                            getchar();
                            getline(cin,x);
                            if(curr.password!=x)
                            {
                                cout<<"Wrong password\n";
                                flag=0;
                            }
                        }
                    if(flag==0)
                    continue;
                    while(1)
                    {
                        int z=function_call();
                        if(z==10)
                        break;
                        else if(z==1)
                        {
                            curr.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==2)
                        {
                            bd.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==3)
                        {
                            bd.display_available();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==4)
                        {
                            if(curr.book_issued>=5)
                            cout<<"\nYou have reached maximum capacity of issuing books\n";
                            else{
                            cout<<"\nEnter bookid of book to be issued\n";
                            int z;
                            cin>>z;
                            int p=bd.issue_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                curr.sb.push_back(bd.search_book(z));
                                curr.book_issued++;
                                cout<<"\nBook issued\n";
                            }
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==5)
                        {
                            cout<<"\nEnter bookid of book to be returned\n";
                            int z;
                            cin>>z;
                            int p=bd.issue_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook is already unissued\n";
                            else{
                                //remove book in student
                                cout<<"\nBook Returned\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==6)
                        {
                            curr.display_issued_books();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                        else if(z==7)
                        {
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                        else if(z==8)
                        {
                            curr.fine=0;
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==9)
                        {
                            cout<<"\nEnter bookid : ";
                            int z;
                            cin>>z;
                            int p=bd.is_book_available(z);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                cout<<"\nBook available\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                    }
                }
                else if(y==2)
                {
                    student newst;
                    cout<<"\nYour user id is : "<<newst.uid<<"\n";
                    newst.fine=0;
                    cout<<"\nEnter your name : ";
                    string x;
                    //cin>>x;
                    getchar();
                    getline(cin,x);
                    newst.name=x;
                    cout<<"Enter your password : ";
                    getchar();
                    getline(cin,x);
                    newst.password=x;
                    sd.add_student(newst);
                    cout<<"\nSuccessfully Registered\n";
                    continue;

                }
            }

        }
        else if(x==2)
        {
            cout<<"\nWelcome,Professor\n\n";
            while(1)
            {
                int flag=1;
                int y=login_call();
                if(y==3)
                break;
                else if(y==1)
                {
                    prof curr;
                        cout<<"\nEnter ID : ";
                        int id;
                        cin>>id;
                        int t=pd.is_prof_present(id);
                        if(t==0)
                        {
                            cout<<"\nThis user doesn't exist.\n";
                            flag=0;

                        }
                        else
                        {
                            curr=pd.search_prof(id);
                            string x;
                            cout<<"Enter password\n";
                            getchar();
                            getline(cin,x);
                            if(curr.password!=x)
                            {
                                cout<<"\nWrong password\n";
                                flag=0;
                            }
                        }
                    if(flag==0)
                    continue;
                    while(1)
                    {
                        int z=function_call();
                        if(z==10)
                        break;
                        else if(z==1)
                        {
                            curr.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==2)
                        {
                            bd.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==3)
                        {
                            bd.display_available();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==4)
                        {
                            cout<<"\nEnter bookid of book to be issued\n";
                            int z;
                            cin>>z;
                            int p=bd.issue_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                curr.pb.push_back(bd.search_book(z));
                                curr.book_issued++;
                                cout<<"\nBook issued\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==5)
                        {
                            cout<<"\nEnter bookid of book to be returned\n";
                            int z;
                            cin>>z;
                            int p=bd.issue_book(z,curr.uid);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook is alredy unissued\n";
                            else{
                                //remove book in student
                                cout<<"\nBook Returned\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==6)
                        {
                            curr.display_issued_books();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==7)
                        {

                        }
                        else if(z==8)
                        {
                            curr.fine=0;
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==9)
                        {
                            cout<<"\nEnter bookid : ";
                            int z;
                            cin>>z;
                            int p=bd.is_book_available(z);
                            if(p==3)
                            cout<<"\nThis Book is not present in library\n";
                            else if(p==1)
                            cout<<"\nBook currently not available\n";
                            else{
                                cout<<"\nBook available\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();

                        }
                    }
                }
                else if(y==2)
                {
                    prof newst;
                    cout<<"\nYour user id is : "<<newst.uid<<"\n";
                    newst.fine=0;
                    cout<<"\nEnter your name : ";
                    string x;
                    //cin>>x;
                    getchar();
                    getline(cin,x);
                    newst.name=x;
                    cout<<"Enter your password : ";
                    //cin>>x;
                    getchar();
                    getline(cin,x);
                    newst.password=x;
                    pd.add_prof(newst);
                    cout<<"\nSuccessfully Registered\n";
                    continue;
                }
            }

        }
        else if(x==3)
        {
            cout<<"\nWelcome,Librarian\n\n";
            while(1)
            {
                int flag=1;
                int y=lib_login_call();
                if(y==2)
                break;
                else if(y==1)
                {
                    lib curr;
                        cout<<"\nEnter ID : ";
                        int id;
                        cin>>id;
                        int t=ld.is_lib_present(id);
                        if(t==0)
                        {
                            cout<<"\nThis user doesn't exist.\n";
                            flag=0;

                        }
                        else
                        {
                            curr=ld.search_lib(id);
                            string x;
                            cout<<"Enter password\n";
                            getchar();
                            getline(cin,x);
                            if(curr.password!=x)
                            {
                                cout<<"\nWrong password\n";
                                flag=0;
                            }
                        }
                    if(flag==0)
                    continue;
                    while(1)
                    {
                        int z=lib_function_call();
                        if(z==12)
                        break;
                        else if(z==1)
                        {
                            curr.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==2)
                        {
                            bd.display();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==3)
                        {
                            bd.display_available();
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==4)
                        {
                            for(int i=0;i<sd.all_students.size();i++)
                            {
                                cout<<"User id : "<<sd.all_students[i].uid<<"     Name : "<<sd.all_students[i].name<<"      Role : Student\n";
                            }
                            for(int i=0;i<pd.all_prof.size();i++)
                            {
                                cout<<"User id : "<<pd.all_prof[i].uid<<"     Name : "<<pd.all_prof[i].name<<"      Role : Professor\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==5)
                        {
                            bd.add_book();
                            cout<<"\nPress Enter to go back\n";
                            //getchar();
                            getchar();
                        }
                        else if(z==6)
                        {
                            cout<<"\nEnter book id\n";
                            int id;
                            cin>>id;
                            int p=bd.delete_book(id);
                            if(p==1)
                            cout<<"\nBook successfully deleted\n";
                            else
                            cout<<"\nInvalid book id\n";
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==7)
                        {
                            student sn;
                            cout<<"\nUserId is "<<sn.uid<<"\n";
                            string x;
                            cout<<"\nName of Student : ";
                            getchar();
                            getline(cin,x);
                            sn.name=x;
                            cout<<"Password of Student : ";
                            getchar();
                            getline(cin,x);
                            sn.password=x;
                            sn.fine=0;
                            sd.add_student(sn);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            //getchar();
                        }
                        else if(z==8)
                        {
                            cout<<"\nUser id of student : ";
                            int id;
                            cin>>id;
                            sd.remove_student(id);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==9)
                        {
                            prof sn;
                            cout<<"\nUserId is "<<sn.uid<<"\n";
                            string x;
                            cout<<"\nName of Professor : ";
                            getchar();
                            getline(cin,x);
                            sn.name=x;
                            cout<<"Password of Professor : ";
                            getchar();
                            getline(cin,x);
                            sn.password=x;
                            sn.fine=0;
                            pd.add_prof(sn);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            //getchar();

                        }
                        else if(z==10)
                        {
                            cout<<"\nUser id of Professor : ";
                            int id;
                            cin>>id;
                            pd.remove_prof(id);
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                        else if(z==11)
                        {
                            for(int i=0;i<bd.all_books.size();i++)
                            {
                                if(bd.all_books[i].available==0)
                                cout<<"Book id : "<<bd.all_books[i].bid<<"      Name of book : "<<bd.all_books[i].title<<"      owner id : "<<bd.all_books[i].owner<<"\n";
                            }
                            cout<<"\nPress Enter to go back\n";
                            getchar();
                            getchar();
                        }
                    }
                }
            }

        }
    }


    return 0;
}
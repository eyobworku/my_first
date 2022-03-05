//26/06/14
#include<iostream>
using namespace std;
void menu();
float add(float,float);
float mul(float,float);

int main(){
    float x,y,result;
    int choice;
    do
    {
        menu();
        cin>>choice;
        switch (choice)
        {
        case 1:
            cout << "Enter Two numbers"<<endl;
            cin >> x >> y;
            result = add(x,y);
            cout << "The result is "<< result<<endl;
            break;
        case 2:
            cout << "Enter Two numbers"<<endl;
            cin >> x >> y;
            result = mul(x,y);
            cout << "The result is "<< result<<endl;
            break;
        case 3:
            exit(0);
            break;
        }
        cout << "(please enter to continue or press any key to exit)";
        cin.ignore('\n',10);
        if (cin.get() == '\n') {
                cout << true;
            }
        else{
            cout << "exit";
            exit(0);
        }
    } while(true);
    return 0;
}

void menu(){
    cout<<"Menu"<<endl;
    cout<<"1: ADD"<<endl;
    cout<<"2: MULTIPLY"<<endl;
    cout<<"3: Exit"<<endl;
    cout<<"Enter your choice: ";

}
float add(float num1,float num2){
    return num1 + num2;
}
float mul(float num1,float num2){
    return num1 * num2;
}
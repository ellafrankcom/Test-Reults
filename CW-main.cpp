#include <iostream>
using namespace std;
int main()
{
    //main program
    int mark; //inputed mark with user
    int mark0_29 = 0, mark30_39 = 0, mark40_69 = 0, mark70_100 = 0; //variable for mark group, has to start at zero for the table
    int table[4][6] = {0}; //array for table, 2nd number doesn't matter on value
    int x =0; //for array loops
    
    //used for the statistics
    int M_Ov100 = 0;
    int user_input_sum = 0; //sum of all numbers user inputs
    int highest = 0, lowest = 100;
    float markcount, pass_rate, fail_rate;  //using float for accurate statistics
    float pass_percent, fail_percent;
    float mark_total; //total of marks added up - final inputed mark (over 100)
    float average;
    
    cout<<"This program will work out statistics for the student's marks you enter."<<endl;
    cout<<"If you enter anything over 100 or any letter the program will quit."<<endl; // user knows when programme will stop
    cout<<endl;
    
    cout<<"Please enter the student's mark: "<<endl;
    cin>> mark;
    user_input_sum = user_input_sum + mark;  //used to calculate the total of all marks entered
    
    while (mark <=100){//while mark is less than or equal to 100 perfom on of the if statements
        
        if(cin.fail()) {
            cin.clear();
            cout<<"Error, program has ended"<<endl;
            break;
        }
        
        if (mark>highest){   //determines highest mark
            highest = mark;
        }
        
        if (mark < lowest  && mark > 0){   //determines lowest mark
            lowest = mark;
        }
        
    
        if(mark >=0 && mark <=29){
            table[0][mark0_29] = mark;  //will store mark in first row of array
            mark0_29++;  //will add one to value of mark range
        }
        
        else if(mark >=30 && mark <=39){
            table[1][mark30_39] = mark;  //will store mark in second row of array
            mark30_39++;  //will add one to value of mark range
        }
        
        else if(mark >=40 && mark <=69){
            table[2][mark40_69] = mark;  //will store mark in third row of array
            mark40_69++;  //will add one to value of mark range
        }
        
        else if(mark >=70 && mark <=100){
            table[3][mark70_100] = mark;  //will store mark in fourth row of array
            mark70_100++;  //will add one to value of mark range
        }
    
        else {
        cout<<"Error"<<endl;
         }
         
        cout<<"Please enter the student's mark: ";  //repeats loop
        cin>> mark;
        user_input_sum = user_input_sum + mark;
    }
    
    
    if (mark >= 101 ||mark <0){   //stores memory of mark entered over 100
        M_Ov100 = M_Ov100 + mark;
    }
    
    markcount = mark0_29 + mark30_39 + mark40_69 + mark70_100; //adds up total of marks counted
    
    cout<<endl;
    cout<<"Total marks counted = "<<markcount<<endl;
    cout<<"__________________________"<<endl;
    cout<<endl;
    
    cout<<"\t0-29\t";  //loops to print out * for histogram (\t) is new tab
    for(x=0; x<mark0_29; x++) cout<<"*";
    
    cout<<endl;
    cout<<"\t30-39\t";  //loops to print out * for histogram (\t) is new tab
    for(x=0; x<mark30_39; x++) cout<<"*";
    
    cout<<endl;
    cout<<"\t40-69\t";  //loops to print out * for histogram (\t) is new tab
    for(x=0; x<mark40_69; x++) cout<<"*";
    
    cout<<endl;
    cout<<"\t70-100\t";  //loops to print out * for histogram (\t) is new tab
    for(x=0; x<mark70_100; x++) cout<<"*";
    
    cout<<endl;
    cout<<"__________________________"<<endl;
    cout<<endl;
    
    pass_rate = mark40_69 + mark70_100;
    fail_rate = mark30_39 + mark0_29;
    pass_percent = (pass_rate / markcount)*100;
    fail_percent = (fail_rate / markcount)*100;
    
    mark_total = user_input_sum - M_Ov100;  //have to take away the mark entered over 100 as not counted as mark
    average = mark_total/markcount;
    
    
    cout<<"Total pass marks: "<<pass_rate<<endl; //display pass and fail rate
    cout<<"Pass rate is: "<<pass_percent<<"%"<<endl;
    cout<<endl;
    cout<<"Total fail marks: "<<fail_rate<<endl;
    cout<<"Fail rate is: "<<fail_percent<<"%"<<endl;
    cout<<endl;
    cout<<"Total of all marks is: "<<mark_total<<endl;
    cout<<"Average mark is: "<<average<<"%"<<endl;
    cout<<"Highest mark is: "<<highest<<endl;
    cout<<"Lowest mark is: "<<lowest<<endl;
    cout<<endl;

    return 0;
    
}

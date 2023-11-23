#include <string>
#include <iostream>
#include <vector>
#include<fstream>
#include <algorithm>
#include<iomanip>
#include<ctime>
using namespace std;
class Task
{
private:

string name;
int priority;
bool complete;
tm  due_Date;
public:
  
Task() : name(""), priority(0), complete(false),due_Date{} {}
Task(string name, int priority,bool complete, tm due_Date) 
{
this->name=name;
this->priority= priority;
 this -> complete= complete;
this ->due_Date =due_Date;

}
 // Setter methods
    void setName(const string& newName) 
    { 
        name = newName; }
    void setPriority(int newPriority) 
    { priority = newPriority; 
    }
    
    void setComplete(bool newComplete) 
    { complete = newComplete; 
    }

    void setDue_date(tm due_Date){
        this-> due_Date=due_Date;
    }

//Getter methods
     string getName() const 
       { return name;
           }
    
    int getPriority() const 
    { return priority; 
    }



    bool isComplete() const 
    { return complete; 
    }

 tm getDue_date()const{
    return due_Date;
 }
};


class Taskmanager
{
private:
    vector <Task> tasks;
   Task newtask;

public:

 void add(/* args */)
{
    string name;
    int priority;
    bool complete;
    tm due_date;
cout<<"Enter task name: "<<endl;
cin>> name;
cout<<"Enter task priority: "<<endl;
cin>> priority;
cout<<"Enter due date: MM DD "<<endl;
cin>>get_time(&due_date,"%m %d");
if(cin.fail()){
    cout<<"Invalid date input";
}

complete=false;
newtask.setName(name);
newtask.setPriority(priority);
newtask.setComplete(complete);
newtask.setDue_date(due_date);
tasks.push_back(newtask);

}

 
void displayTasks()
{
for(auto &task:tasks){

cout<<"Name: "<<task.getName() <<" "<<"Priority :"<<task.getPriority()<<" "<<"Due date: "<<put_time().getDue_date()<<" "<<"Updated Status: "<<(task.isComplete()?"Complete":"InComplete")<<endl;


}}

auto sort_byPriority(){

auto& sort_task =tasks;

sort (sort_task.begin(),sort_task.end(),newtask.getPriority(),[](const Task& task1, const Task& task2){
     return task1.getPriority() < task2.getPriority();

})
 return task1.getPriority() < task2.getPriority();
 
//* display sorted tasks by priority 
for (const auto &task : sort_task) {
        cout << "Name: " << task.getName() << " Priority: " << task.getPriority() << " Due date: " << task.getDue_date() << " Status: " << (task.isComplete() ? "Complete" : "Incomplete") << endl;
    }

}
auto getTasks(){
    auto& task_vector = tasks;
return task_vector;
}

 bool isComplete(){
 int taskindex;
 cout<<"Enter index of the task:";
 cin>>taskindex;

 if(taskindex>=0 &&  taskindex <tasks.size()){
    tasks[taskindex].setComplete(true);
    return true;
 }else{
    cout<<"Invalid index"<<endl;
    return false;
 }

}

};













//main class
int main(int argc, char const *argv[])
{
ofstream myFile("todolist_log.txt",ios::app);//* new file creation

if(!myFile.is_open()){
    cout<<"Error opening file";
}
    Taskmanager task; //declaration of object
    bool running= true;
while(running !=false){
cout<<"Welcome to your todolist"<<endl;

task.displayTasks();
cout<<"Enter 1:to add a task,2:to complete a task, 3:to display your tasks, 4:quit:, 5:to sort by priorities :"<<endl;
int option ;
cin>>option;

//*ensures that user puts in an integer
if(!option>=1 && !option<=5 ){
    cin.clear(option);
    cout<<"Choose a number 1-5. "<<"       "<<"Enter 1:to add a task,2:to complete a task, 3:to display your tasks, 4:quit:, 5:to sort by priorities :"<<endl;

    cin>>option;
}

switch (option)
{
        case 1:
            task.add();
        break;

        case 2:
        
            task.isComplete();

        break;
        case 3:
            task.displayTasks();
        break;
        case 4:
            running=false;
             //*adding the taks unto the file
             for (const auto &task :task.getTasks()){//? rectify this with chat
                    myFile << "Name: " << task.getName() << " Priority: " << task.getPriority() << " Status: " << (task.isComplete() ? "Complete" : "Incomplete") << "\n";

             }

            myFile.close(); //* closed file
            break;

        case 5:
            task.sort_byPriority();
            break;
default:
cout<<"Error occured";
    break;
}


}

    return 0;
}



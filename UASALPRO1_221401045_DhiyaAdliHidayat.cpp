#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct TodoItem
{
    string activity;
    bool status;
};

// add new data to todo list
vector<TodoItem> add(vector<TodoItem> &todoList)
{
    char data[20];
    cout << endl
         << "===adding data===" << endl;
    cout << "activity : ";
    cin.ignore();
    cin.get(data, 20);                 // get new activity
    todoList.push_back({data, false}); // add the activity to todo list and it will automatically mark as "not done"
    cout << "added! " << endl;
    return todoList;
}

// removing data from todo list
vector<TodoItem> remove(vector<TodoItem> &todoList)
{
    int data;
    cout << endl
         << "===removeing data===" << endl;
    cout << "number : ";
    cin >> data; // which number the user want to remove
    if (data > todoList.size())
    {
        cout << "no data found" << endl;
    }
    else
    {
        todoList.erase(todoList.begin() + (data - 1)); // removing the data
        cout << "removed!" << endl;
    }
    return todoList;
}

// customize todo list data
vector<TodoItem> edit(vector<TodoItem> &todoList)
{
    int data;
    cout << endl
         << "===editing data===" << endl;
    cout << "number : ";
    cin >> data;                // get the data that the user want to edit
    if (data > todoList.size()) // find the data from database
    {
        cout << "no data found" << endl;
    }
    else
    {
        TodoItem temp = todoList[data - 1];
        int input;
        cout << "change option :" << endl;
        cout << "1. change activity" << endl;
        cout << "2. change status" << endl;
        cout << "choose : ";
    reInput:
        cin >> input; // know what the user want to edit from the data

        if (input == 1)
        {
            char newActivity[20];
            cout << "new activity : ";
            cin.ignore();
            cin.get(newActivity, 20);                       // get new activity
            todoList.erase(todoList.begin() + (data - 1));  // erase the data
            todoList.push_back({newActivity, temp.status}); // create a new list with edited data
        }
        else if (input == 2)
        {
            char newStatus;
            todoList.erase(todoList.begin() + (data - 1)); // erase the data
            cout << "done? y/n : ";
        reInpuStatus:
            cin >> newStatus; // get the new condition of the data
            if (newStatus == 'y')
            {
                todoList.push_back({temp.activity, true}); // recreate the data with "done" status
            }
            else if (newStatus == 'n')
            {
                todoList.push_back({temp.activity, false}); // recreate the data with "not done" status
            }
            else
            {
                goto reInpuStatus;
            }
        }
        else
        {
            goto reInput;
        }
        cout << "edited!" << endl;
    }
    return todoList;
}

// show all the to do list to user
void show(vector<TodoItem> &todoList)
{
    cout << "your list" << endl;
    cout << "==================" << endl;
    for (int i = 0; i < todoList.size(); i++) // show all the list
    {
        string status = (todoList[i].status == 1) ? "done" : "not done"; // if the status is 1, the program will show "done"
        cout << i + 1 << ". " << todoList[i].activity << " (" << status << ") " << endl;
    }
}

// exit program
void done()
{
    cout << "thanks for using this program :)" << endl
         << endl;
}

int main()
{

    int input;
    TodoItem data;
    vector<TodoItem> todoList;

    // give menu to user
    cout << "your todo list" << endl;
    cout << "================== " << endl;
    cout << "1. add list " << endl;
    cout << "2. remove list" << endl;
    cout << "3. edit list" << endl;
    cout << "4. show list " << endl;
    cout << "5. done " << endl;

userInput:
    cout << endl
         << "input menu: ";
    cin >> input; // get the user command

    if (input == 1)
    {
        todoList = add(todoList); // run add function
        goto userInput;           // go to userInput label
    }
    else if (input == 2)
    {
        todoList = remove(todoList); // run remove function
        goto userInput;              // go to userInput label
    }
    else if (input == 3)
    {
        todoList = edit(todoList); // run edit function
        goto userInput;            // go to userInput label
    }
    else if (input == 4)
    {
        show(todoList); // run show function
        goto userInput; // go to userInput label
    }
    else if (input == 5)
    {
        done();         // run done function
    }
    else
    {
        cout << "input gagal" << endl
             << endl;
        goto userInput; // go to userInput label
    }

    return 0;
}

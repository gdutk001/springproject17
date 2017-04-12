#include "SemesterProject.h"




string searchSKU(string SKU){
    
}


struct itemNode{ //struct for managing items
    string name;
    string price;
    string dimension;
    string revision;
    string model;
    string color;
    string serial;
    itemNode* nextItem;
};

itemNode *g_head; //will point to head of data structure

bool initiateData(int intitalSize) { //creates the linked list data structure

    int i = 0;
    itemNode *n;
    itemNode *temp;

    n = new itemNode;
    n->name = "NA";
    n->price = "NA";
    n->dimension = "NA";
    n->revision = "NA";
    n->model = "NA";
    n->color = "NA";
    n->serial = "NA";
    temp = n;
    g_head = n;

    while (i <= intitalSize) { //loop to initialize all free lists
        n = new itemNode;
        n->name = "NA";
        n->price = "NA";
        n->dimension = "NA";
        n->revision = "NA";
        n->model = "NA";
        n->color = "NA";
        n->serial = "NA";
        temp->nextItem = n;
        temp = temp->nextItem;
        i++;
    }

    return true;
}




/*

int inputValid(){  //checks if input is valid (is a number)

    int choice;
    bool isValid = false;


    while(isValid == false) {  //loops while as long as the program doesn't know if choice is valid

        try {  //this may throw an exception if input is not valid
            cin >> choice;
                if(choice != 0 && choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5 && choice != 6 && choice != 7 && choice != 8 && choice != 9) {
                    throw invalid_argument("Invalid Input, please only use integers");
            }

            isValid = true;
        }

        catch (exception e) {  //catches any exceptions
            cout << "Invalid input, please try again" << endl;
            choice = 0;
        }
    }

    cout << endl;
    return choice;
};



int main() {
    bool isRunning = true;
    bool hasSpace = true;
    string itemName;

    cout << "Hello, and welcome to warehouse inventory manager 2000!" << endl;
    cout << "Please enter the size of your warehouse: ";

    string * warehouse;
    int input = inputValid();
    int warehouseSize = input;
    warehouse = new string [input];

    for(int i = 0; i < warehouseSize; i++){  //initializes array
        warehouse[i] = "xxxx";
    }

    while(isRunning == true){
        cout << "Please select from the following options:\n";
        cout << "1) Add item to inventory\n";
        cout << "2) Remove item from inventory\n";
        cout << "3) Print contents of warehouse\n";
        cout << "4) Exit program" << endl;

        input = inputValid();

        if(input == 1){
            cout << "Please enter name of item: ";
            cin >> itemName;   //need to add input verification
            hasSpace = false;

            for(int i = 0; i < warehouseSize; i++){ //looks for the next empty space in warehouse
                if(warehouse[i] == "xxxx"){
                    warehouse[i] = itemName;
                    i = warehouseSize;
                    hasSpace = true;
                }
            }

            if(hasSpace == false){
                cout << "Warning, no room in warehouse.  Please remove items and then try again\n" << endl;
            }

        }

        else if(input == 2){
            cout << "Please enter name of item: ";
            cin >> itemName;  //add input verification

            for(int i = 0; i < warehouseSize; i++){ //looks for the next empty space in warehouse
                if(warehouse[i] == itemName){
                    warehouse[i] = "xxxx";
                }
            }

            cout << "Item removed from list\n" << endl;

        }

        else if(input == 3){

            for(int i = 0; i < warehouseSize; i++){ //looks for the next empty space in warehouse
                cout << "item #";
                cout << i+1;
                cout << " ";
                cout << warehouse[i] << endl;
            }
            cout << endl;

        }

        else if (input == 4) {
        isRunning = false;
        }

        else {
            cout << "Error, not a valid option\n" << endl;
        }
    }


    //data structure may be better, and more input verification is needed
    //at least at the moment a dynamic array works
    return 0;
}
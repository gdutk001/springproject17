#include "SemesterProject.h"



struct itemNode{ //struct for managing items
    string name;
    string price;
    string dimension;
    string revision;
    string model;
    string color;
    string serial;
    string SKU;
    itemNode* nextItem;
};

itemNode *g_head; //will point to head of data structure
int g_sizeOfWarehouse = 0;

bool initiateData() { //creates the linked list data structure

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
    n->SKU = "NA";
    temp = n;
    g_head = n;

    while (i <= g_sizeOfWarehouse) { //loop to initialize all free lists
        n = new itemNode;
        n->name = "NA";
        n->price = "NA";
        n->dimension = "NA";
        n->revision = "NA";
        n->model = "NA";
        n->color = "NA";
        n->serial = "NA";
        n->SKU = "NA";
        temp->nextItem = n;
        temp = temp->nextItem;
        i++;
    }

    return true;
}

string searchSKU(string SKUcheck) {

    itemNode *n = g_head;


    for (int i = 0; i <= g_sizeOfWarehouse; i++) {  //loop used find a matching SKU and print its values


        if ((n->SKU) == SKUcheck) {
            cout << "NAME:      " << n->name << endl;
            cout << "PRICE:     " << n->price << endl;
            cout << "DIMENSION: " << n->dimension << endl;
            cout << "REVISION:  " << n->revision << endl;
            cout << "MODEL:     " << n->model << endl;
            cout << "COLOR:     " << n->color << endl;
            cout << "SERIAL:    " << n->serial << endl;
            cout << "SKU:       " << n->SKU << endl;

            i = g_sizeOfWarehouse;
        }

        if (i < g_sizeOfWarehouse) {
            n = n->nextItem;
        }

        if (i == g_sizeOfWarehouse) {
            cout << "ERROR: SKU '" << SKUcheck << "' NOT FOUND IN SYSTEM, PLEASE TRY AGAIN." << endl;
        }

    }

}




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
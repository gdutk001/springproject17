#include <iostream>
#include <string>
#include <vector>
using namespace std;



void DeleteNode(int n){
     struct Node* temp1 = g_head;
    if(n == 1){
        g_head = tempt->nextItem;
        free(temp1);
        return;
    }
    int i;
for(i = 0; i < n-2;i++)
    temp1=temp1->nextItem

 struct Node* temp2 = temp1->nextItem;
    temp1->nextItem=temp2->nextItem;
    free(temp2);
}


void PrintNode(itemNode* n){


         cout << "NAME:      " << n->name << endl;
            cout << "PRICE:     " << n->price << endl;
            cout << "DIMENSION: " << n->dimension << endl;
            cout << "REVISION:  " << n->revision << endl;
            cout << "MODEL:     " << n->model << endl;
            cout << "COLOR:     " << n->color << endl;
            cout << "SERIAL:    " << n->serial << endl;
            cout << "SKU:       " << n->SKU << endl;
}


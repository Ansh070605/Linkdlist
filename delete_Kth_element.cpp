#include <bits/stdc++.h>
using namespace std;

class node{
    public: 
        int data;
        node *next;
    
        node(int data1, node *next1){
            data = data1;
            next = next1;
        }
        node(int data1){
            data = data1;
            next = nullptr;
        }

    
};
void print(node* head){
    node* temp = head;
    while(temp != nullptr){
        cout<<temp->data;
        temp = temp->next;
    }
   
}
node* convertll(vector<int> arr){
    node* head = new node(arr[0]);
    node* mover = head;
    for(int i = 1; i < arr.size(); i++){
        node* temp = new node(arr[i]);
        mover->next = temp;
        mover = temp;
    }
    return head;
}
node* deletek(node* head, int k){
    if(head == nullptr){
        return head;
    }
    if(k == 1){
        node* temp = head;
        head = head->next;
        delete temp;
        return head;
    }
    node* temp = head;
    int count = 0;
    node* prev = NULL;
    while(temp != nullptr){
        count++;
        if(count == k){
            prev->next = prev->next->next;
            delete temp;
            return head;
        }
        prev = temp;
        temp = temp->next;
    }
    return head;
}

int main() 
{
    vector<int> arr = {2, 5, 7, 9, 4};
    node* head = convertll(arr);
    head = deletek(head, 7);
    print(head);
    
}
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
node* insertk(node* head, int k, int v){
    if(head == nullptr){
        
    
    if(k == 1){
        node* nn = new node(v);
       return nn;
    }
    return head;
    }
    if(k == 1){
        node* nn = new node(v, head);
        return nn;
    }
    int count = 0;
    node* temp = head;
    while(temp != nullptr){
        count++;
        if(count == k-1){
            node* nn = new node(v);
            nn->next = temp->next;
            temp->next = nn;
            break;
        }else{
            temp = temp->next;
        }
    }
    return head;
}

int main() 
{
    vector<int> arr = {2, 5, 7, 9, 4};
    node* head = convertll(arr);
    head = insertk(head, 5, 3);
    print(head);
    
}
/*input
1
2
3
4
5
6
*/
#include <bits/stdc++.h>

using namespace std;

struct node{
    int value;
    node *next;
};

void print(node *List){
    node *iter;
    iter = List;
    while(iter!=NULL){
        cout<<iter->value<<endl;
        iter=iter->next;
    }
    cout<<"NULL"<<endl;
}

node *create_node(int value, node *node1){
    node *temp;
    temp  = new(struct node);
    temp->value = value;
    // cout<<temp->value<<"test1 ";
    temp->next = NULL;
    node1->next=temp;
    return temp;
    // cout<<"Successfully added "<<value<<endl;
}

node *reverse(node *List){
    node *p1, *p2, *p3, *Head;
    p1 = List;
    p2 = p1->next;
    p3 = p2->next;
    p1->next = NULL;
    p2->next = p1;
    // cout<<p1->value<<" "<<p2->value<<" "<<p3->value<<" "<<endl;

    while(p3 != NULL){
        // cout<<p1<<" "<<p2<<" "<<sp3<<" "<<endl;
        // cout<<p1->next<<" "<<p2->next<<" "<<p3->next<<" "<<endl;
        // cout<<p1->value<<" "<<p2->value<<" "<<p3->value<<" "<<p3<<endl;
        // cout<<"while"<<endl;
        p1 = p2;
        p2 = p3;
        p3 = p3->next;
        p2->next = p1;
        // cout<<p1->value<<" "<<p2->value<<" "<<p3->value<<" "<<p3<<endl;
    }
    Head = p2;
    return Head;
}

int main(){

    ios::sync_with_stdio(false);
    node *List, *head, *lastNode;
    List = new(struct node);
    List->next=NULL;
    int n;
    cin>>n;    
    List->value = n;
    head = List;
    lastNode = List;
    cout<<"Working"<<endl;
    //create list
    while (cin>>n){
        lastNode = create_node(n, lastNode);
    }
    cout<<"Printing "<<head<<endl;
    print(head);
    // head = head->next;
    // print(head);
    //insert at the beginning
    //reverse
    head = reverse(head);
    cout<<"Printing "<<head<<endl;
    print(head);
    return 0;
}
class Solution {
  public:
    Node* linkdelete(Node* head, int n, int m) {
       Node* curr=head;
       Node* delh=nullptr;
       if(m==0)
       return nullptr;
       if(n==0)
       return head;
       while(curr!=nullptr){
           for(int i=0;i<m-1&&curr!=nullptr;i++){
               curr=curr->next;
           }
           if(curr==nullptr)
           break;
           delh=curr->next;
           for(int j=0;j<n&&delh!=nullptr;j++){
               delh=delh->next;
           }
           curr->next=delh;
           curr=delh;
       }
       return head;
        
    }
};

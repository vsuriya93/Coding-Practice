/* 
The structure of the node is

typedef struct node
{
    int freq;
    char data;
    node * left;
    node * right;
    
}node;

*/

void decode_huff(node * root,string s)
{
    int i=0;
    node *temp=root;
    while(i<s.length()){
        if(s[i]=='1'){
            temp=temp->right;
            if(temp->left==NULL && temp->right==NULL){
                cout<<temp->data;
                temp=root;
                i++;
            }
            else{
                i++;
                continue;
            }
        }
        else{
            temp=temp->left;
            if(temp->left==NULL && temp->right==NULL){
                cout<<temp->data;
                i++;
                temp=root;
            }
            else{
                i++;
                continue;
            }
        }
    }
}


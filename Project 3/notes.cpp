
/**
 * remove()
 *
 * This function removes an item of type <Base> from the BST.
 * There will be three different ways of removing depending
 * on the situation, removing a node with no children, one child,
 * or two children. For no children, the node will simply be removed.
 * For a node with one child, the child will take place of the removed
 * node's position. For a node with two children, we will take the
 * leftMost node from the right subtree, and promote that.
 *
 * Parameters:
 *  item: item of type <Base> that is to be found, and removed
 *        from the BST.
 *
 * Return Value: N/A
 */
 /*
template <class Base>
void BST<Base>::remove(const Base &item){
    bool flag = false;
    BSTNode<Base> *temp = this->root;
    BSTNode<Base> *tempParent = NULL;

    //find the node first
    while(!flag && temp!=NULL){

        if(item<temp->data){
            tempParent=temp;
            temp=temp->left;
        }

        else if(temp->data<item){
            tempParent=temp;
            temp=temp->right;
        }

        else if(!(item<temp->data || temp->data<item)){
            flag = true;
        }
    }

    //remove process
    if(flag){
        //if temp has no children
        if(temp->left==NULL && temp->right==NULL){
            //if temp is root, delete root
            if(tempParent==NULL){
                this->root = NULL;
                delete this->root;
            }
            else{
                if(tempParent->left==temp){
                    tempParent->left = NULL;
                    //delete tempParent->left;
                }
                else{
                    tempParent->right = NULL;
                    //delete tempParent->right;
                }
            }
            temp = NULL;
            delete temp;
        }

            //temp has two children
        else if(temp->left!=NULL && temp->right!=NULL){
            BSTNode<Base> *leftMost = temp->right;
            BSTNode<Base> *leftMostParent = temp;

            //go down left from temp->right
            if(leftMost->left!=NULL){
                while(leftMost->left!=NULL){
                    leftMostParent = leftMost;
                    leftMost = leftMost->left;
                }
                leftMostParent->left = leftMost->right;
                leftMost->right = temp->right;
            }

            leftMost->left = temp->left;

            if(tempParent==NULL){
                this->root = leftMost;
            }
            else{
                if(tempParent->right == temp){
                    tempParent->right = leftMost;
                }
                else{
                    tempParent->left = leftMost;
                }
            }

            temp->left = NULL;
            temp->right = NULL;
            leftMost = NULL;
            leftMostParent = NULL;
            delete leftMost;
            delete leftMostParent;
            delete temp;
            //delete tempParent;
        }

            //temp has one child
        else if(temp->left != NULL || temp->right != NULL){
            //root is NULL
            if(tempParent==NULL){
                if(temp->left!=NULL){
                    this->root = temp->left;
                    temp->left = NULL;
                }
                else{
                    this->root = temp->right;
                    temp->right = NULL;
                }
            }
                //if left child is the remove node
            else if(tempParent->left == temp){
                if(temp->left != NULL){
                    tempParent->left = temp->left;
                    temp->left = NULL;
                }
                else{
                    tempParent->left = temp->right;
                    temp->right = NULL;
                }
            }
                //if right child is the remove node
            else if(tempParent->right == temp){
                if(temp->left!=NULL){
                    tempParent->right = temp->left;
                    temp->left = NULL;
                }
                else{
                    tempParent->right = temp->right;
                    temp->right = NULL;
                }
            }
            temp = NULL;
            delete temp;
        }
    }
}

#endif //PROJECT_3_BST_STUDENT_PROJ3_H
*/
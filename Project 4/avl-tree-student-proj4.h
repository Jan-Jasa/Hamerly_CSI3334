/*
 * Project 4: Balanced tree-based encryption and decryption
 * File: avl-tree-student-proj4.h
 * Author: Jan Jasa
 * Course: CSI 3334
 * Due Date: October 27, 2023
 * version: 1.4
 *
 * This file contains the functions for AVLNode, AVLTree,
 * and EncryptionTree classes. Included is the
 * implementations for ~AVLNode, printPreorder,
 * minNode, maxNode, insert, singleRotateLeft,
 * singleRotateRight, doubleRotateLeftRight,
 * doubleRotateRightLeft, insert, rebalancePathToRoot,
 * remove, printLevelOrder, encrypt, and decrypt functions.
 *
 * (The use of the operator ">" is avoided)
 */

#ifndef PROJECT_4_AVL_TREE_STUDENT_PROJ4_H
#define PROJECT_4_AVL_TREE_STUDENT_PROJ4_H

#include "avl-tree-prof-proj4.h"
#include <queue>


/**
 * ~AVLNode()
 *
 * This function is the destructor for the AVLNode class.
 * It will delete the left and right pointers, setting them
 * to NULL afterwards.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: N/A
 */
template <class Base>
AVLNode<Base>::~AVLNode(){
    delete this->right;
    delete this->left;
    this->right = NULL;
    this->left = NULL;
}


/**
 * printPreorder()
 *
 * This function returns the AVLNode and its children,
 * in preorder.
 *
 * Parameters:
 *  os: given ostream, that allows for the output
 *      of the AVL tree in preorder
 *  indent: string that indents the word by 2 spaces
 *          each time to show structure of the tree
 *
 * Return Value: N/A
 */
template <class Base>
void AVLNode<Base>::printPreorder(ostream &os, string indent) const{
    os << indent << this->data << endl;

    //add two spaces to each indent
    if(this->left!=NULL){
        this->left->printPreorder(os, indent + "  ");
    }
    else{
        os << indent;
        os << "  NULL";
        os << endl;
    }

    if(this->right!=NULL){
        this->right->printPreorder(os, indent+"  ");
    }
    else{
        os << indent;
        os << "  NULL";
        os << endl;
    }
}


/**
 * minNode()
 *
 * This function returns the smallest value node
 * in a tree/subtree.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: A AVLNode pointer to the minimum node
 */
template <class Base>
const AVLNode<Base> *AVLNode<Base>::minNode() const{
    if(this->left == NULL){
        return this;
    }
    else{
        return this->left->minNode();
    }
}


/**
 * maxNode()
 *
 * This function returns the largest value node
 * in a tree/subtree.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: A AVLNode pointer to the maximum node
 */
template <class Base>
const AVLNode<Base> *AVLNode<Base>::maxNode() const{
    if(this->right == NULL){
        return this;
    }
    else{
        return this->right->maxNode();
    }
}

/**
 * singleRotateLeft()
 *
 * This function rotates a node a single time to the
 * left.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: A AVL pointer to the child node,
 * which is the replacement for "this".
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::singleRotateLeft(){
    //take right child of this
    AVLNode<Base> *child = this->right;

    //if child has a left, this->right is set to that
    this->right = child->left;

    //due to left rotation, child->left = this
    child->left = this;

    //update heights
    this->updateHeight();
    child->updateHeight();

    //return pointer to child
    return child;
}

/**
 * singleRotateRight()
 *
 * This function rotates a node a single time
 * to the right.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: A AVL pointer to the child node,
 * which is the replacement for "this".
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::singleRotateRight(){
    AVLNode<Base>*child = this->left;

    this->left = child->right;
    child->right = this;

    this->updateHeight();
    //child->left->updateHeight();
    child->updateHeight();

    return child;
}

/**
 * doubleRotateLeftRight()
 *
 * This function rotates a node two times.
 * It rotates the left child of "this" to the left.
 * "This" is then rotated to the right.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: A AVL pointer to the child node,
 * which is the replacement for "this".
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::doubleRotateLeftRight(){
    this->left = this->left->singleRotateLeft();

    return this->singleRotateRight();
}

/**
 * doubleRotateRightLeft()
 *
 * This function rotates a node two times.
 * It rotates the right child of "this" to the right.
 * "This" is then rotated to the left.
 *
 * Parameters:
 *  N/A
 *
 * Return Value: A AVL pointer to the child node,
 * which is the replacement for "this".
 */
template <class Base>
AVLNode<Base> *AVLNode<Base>::doubleRotateRightLeft(){
    this->right = this->right->singleRotateRight();

    return this->singleRotateLeft();
}


/**
 * insert()
 *
 * This function inserts a variable of type Base into the
 * BST. The function starts at root, and if item is less
 * than root, it goes to the left. If it is greater than,
 * it will go right. This process repeats until it finds
 * a null spot to insert the item into. If the item is found
 * in the tree, it is ignored and skipped. The path that is
 * travelled is also put into nodePath, which is used to
 * re-balance the tree afterwards.
 *
 * Parameters:
 *  item: item is a variable of type base that is to be
 *        inserted into the BST, by abiding BST rules.
 *
 * Return Value: N/A
 */
template <class Base>
void AVLTree<Base>::insert(const Base &item){
    AVLNode<Base> *temp = this->root;

    //insert into root if NULL, auto gets height of 0
    if(temp == NULL){
        this->root = new AVLNode<Base>(item);
    }
    else{
        vector<AVLNode<Base>*> nodePath;
        bool flag = false;

        while(!flag){
            //push onto path
            nodePath.push_back(temp);

            //left path
            if(item < temp->data){
                if(temp->left!=NULL){
                    temp = temp->left;
                }
                else{
                    temp->left = new AVLNode<Base>(item);
                    nodePath.push_back(temp->left);
                    flag = true;
                }
            }

            //right path, use < operator
            else if(temp->data < item){
                if(temp->right!=NULL){
                    temp=temp->right;
                }
                else{
                    temp->right = new AVLNode<Base>(item);
                    nodePath.push_back(temp->right);
                    flag = true;
                }
            }

            //found item, do nothing
            else{
                flag = true;
            }
        }
        //let rebalancePathToRoot function take care of balancing
        this->rebalancePathToRoot(nodePath);
    }
}


//NOTE: rotation functions return pointers, so change i-1 left or right ptr
//IMPLEMENTED TIEBREAKER
/**
 * rebalancePathToRoot
 *
 * This function takes an input of a vector of AVLNodes, "path",
 * and starts from the last element of the vector, which is the
 * bottom of the path. From here, it will check for if the node
 * is unbalanced, which is when the left and right subtrees differ
 * by more than 2 in height. If the node is unbalanced, it will
 * balance the node so that the subtrees' heights differ by at most
 * 1. To do this, the function will first check which subtree (from the
 * current node) has a greater height. From here, the next tallest child
 * will be taken into consideration. If both children are of equal height,
 * a single rotation will be performed. If the "unbalance path" goes in the
 * same direction, a single rotation will be performed. If the "unbalance
 * path" goes down two different direction, a double rotation will be performed.
 *
 * Parameters:
 *  path: path is a vector of AVLNode pointers that must be rebalanced, which
 *      is created during insertion or removal. This is the path that was
 *      travelled in order to insert a node or remove a node.
 *
 * Return Value: N/A
 */
template <class Base>
void AVLTree<Base>::rebalancePathToRoot(const vector<AVLNode<Base> *> &path) {
    int leftSubtreeHeight = 0;
    int rightSubtreeHeight = 0;
    const int UNBALANCE_HEIGHT = 2;

    for(int i=path.size()-1; i>=0; i--){
        //path[i]->updateHeight();
        AVLNode<Base> *curr = path[i];
        leftSubtreeHeight = this->root->getHeight(curr->left);
        rightSubtreeHeight = this->root->getHeight(curr->right);

        //right side has higher height (right-side imbalance)
        if(rightSubtreeHeight-leftSubtreeHeight >= UNBALANCE_HEIGHT){
            //right-right imbalance
            if(this->root->getHeight(curr->right->right)-
                    this->root->getHeight(curr->right->left) >= 0){
                //cout << "DEBUG: singleRotateLeft" << endl;
                if(curr==this->root){
                    this->root = curr->singleRotateLeft();
                }
                else{
                    AVLNode<Base> *parent = path[i-1];

                    if(parent->right == curr){
                        parent->right = curr->singleRotateLeft();
                    }
                    else if(parent->left == curr){
                        parent->left = curr->singleRotateLeft();
                    }
                }
            }
            //right-left imbalance
            else if(this->root->getHeight(curr->right->left)-
                    this->root->getHeight(curr->right->right)>0){
                //cout << "DEBUG: doubleRotateRightLeft" << endl;
                if(curr==this->root){
                    this->root = curr->doubleRotateRightLeft();
                }
                else{
                    AVLNode<Base> *parent = path[i-1];

                    if(parent->right == curr){
                        parent->right = curr->doubleRotateRightLeft();
                    }
                    else if(parent->left == curr){
                        parent->left = curr->doubleRotateRightLeft();
                    }
                }
            }
        }

        //left side has higher height (left side imbalance)
        else if(leftSubtreeHeight-rightSubtreeHeight >= UNBALANCE_HEIGHT){
            //left-left imbalance
            if(this->root->getHeight(curr->left->left)-
                    this->root->getHeight(curr->left->right) >= 0){
                //cout << "DEBUG: singleRotateRight" << endl;
                if(curr==this->root){
                    this->root = curr->singleRotateRight();
                }
                else{
                    AVLNode<Base> *parent = path[i-1];

                    if(parent->right == curr){
                        parent->right = curr->singleRotateRight();
                    }
                    else if(parent->left == curr){
                        parent->left = curr->singleRotateRight();
                    }
                }
            }
            //left-right imbalance
            else if(this->root->getHeight(curr->left->right)-
                    this->root->getHeight(curr->left->left) > 0){
                //cout << "DEBUG: doubleRotateLeftRight" << endl;
                if(curr==this->root){
                    this->root = curr->doubleRotateLeftRight();
                }
                else{
                    AVLNode<Base> *parent = path[i-1];

                    if(parent->right == curr){
                        parent->right = curr->doubleRotateLeftRight();
                    }
                    else if(parent->left == curr){
                        parent->left = curr->doubleRotateLeftRight();
                    }
                }
            }
        }
        //update height and move on
        curr->updateHeight();
    }
}

/**
 * remove()
 *
 * This function removes an item of type <Base> from the BST.
 * At first it will find the node that needs to be removed,
 * and will take note of the path for balancing purposes.
 * There will be three different ways of removing depending
 * on the situation, removing a node with no children, one child,
 * or two children. For no children, the node will simply be removed.
 * For a node with one child, the child will take place of the removed
 * node's position. For a node with two children, we will take the
 * leftMost node from the right subtree, and promote that. The nodePath
 * will also be extended down to where leftMost was found, as it must be
 * rebalanced as well.
 *
 * Parameters:
 *  item: item of type <Base> that is to be found, and removed
 *        from the BST.
 *
 * Return Value: N/A
 *
 *
 */
template <class Base>
void AVLTree<Base>::remove(const Base &item){
    bool flag = false;
    AVLNode<Base> *temp = this->root;
    AVLNode<Base> *tempParent = NULL;
    vector<AVLNode<Base>*> nodePath;

    while(temp!=NULL && !flag){
        if(item<temp->data){
            nodePath.push_back(temp);
            tempParent=temp;
            temp=temp->left;
        }

        else if(temp->data<item){
            nodePath.push_back(temp);
            tempParent=temp;
            temp=temp->right;
        }

        else if(!(item<temp->data || temp->data<item)){
            //nodePath.push_back(temp);
            flag = true;
        }
    }

    if(flag){
        //if temp has no children (GOOD)
        if(temp->left==NULL && temp->right==NULL){
            //if temp is root, delete root
            if(tempParent==NULL){
                this->root = NULL;
                delete this->root;
            }
            else if(tempParent!=NULL){
                if(tempParent->left==temp){
                    tempParent->left = NULL;
                    delete tempParent->left;
                }
                else{
                    tempParent->right = NULL;
                    delete tempParent->right;
                }
            }
            delete temp;
        }

        //temp has two children
        else if(temp->left!=NULL && temp->right!=NULL){
            AVLNode<Base> *leftMost = temp->right;
            AVLNode<Base> *leftMostParent = temp;

            //go down left from temp->right
            if(leftMost->left!=NULL){
                while(leftMost->left!=NULL){
                    //nodePath.push_back(leftMost);
                    leftMostParent = leftMost;
                    leftMost = leftMost->left;
                }
                leftMostParent->left = leftMost->right;
                leftMost->right = temp->right;
            }
            //set leftMost->left
            leftMost->left = temp->left;

            //if root is empty, set to leftMost. else, replace temp
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

            //REMOVE SPECIAL CASE: add the node path down to where leftMost was
            nodePath.push_back(leftMost);
            if(leftMost->right!=NULL){
                leftMost = leftMost->right;
                while(leftMost!=NULL){
                    nodePath.push_back(leftMost);
                    leftMost=leftMost->left;
                }
            }

            //clear mem
            temp->left = NULL;
            temp->right = NULL;
            //leftMost = NULL;
            leftMostParent = NULL;
            //delete leftMost;
            //delete leftMostParent;
            delete temp;
            //delete tempParent;
        }

        //temp has one child (DONE)
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
            //temp = NULL;
            delete temp;
        }
    }
    this->rebalancePathToRoot(nodePath);
}

/**
 * printLevelOrder()
 *
 * This function returns the AVL Tree and its children,
 * in level order.
 *
 * Parameters:
 *  os: given ostream, that allows for the output
 *      of the AVL tree in level order.
 *
 * Return Value: N/A
 */
template <class Base>
void AVLTree<Base>::printLevelOrder(ostream &os) const {
    queue<AVLNode<Base>*> nodeQueue;
    AVLNode<Base> *temp = this->root;
    const int MAX = 20;
    int NumOfNodes = 0;

    if(temp!=NULL){
        nodeQueue.push(temp);

        while(!nodeQueue.empty()){
            NumOfNodes++;
            temp = nodeQueue.front();


            if(temp==NULL){
                os << "NULL";
            }
            else{
                os << temp->data;
                nodeQueue.push(temp->left);
                nodeQueue.push(temp->right);
            }
            nodeQueue.pop();

            //break if queue empty
            if(nodeQueue.empty()){
                break;
            }

            //check and make sure nodes on line isn't 20
            if(NumOfNodes>=MAX){
                os << endl;
                NumOfNodes = 0;
            }
            else{
                os << " ";
            }
        }
        os << endl;
    }

    else{
        os << "NULL" << endl;
    }

}

/**
 * encrypt()
 *
 * This function encrypts a variable of type Base in the
 * AVL Tree. The function starts at root with the encryption
 * "r". After this, it follows the BST path in finding the item.
 * If it goes left, it will add a 0. If it goes right, it will
 * add a 1. Once the item is found, it will set found to true.
 * If it isn't found, encryption is set to "?".
 * Essentially:
 * r=root
 * 0=left
 * 1=right
 *
 * Parameters:
 *  item: item is a variable of type base that is to be
 *        encrypted in the AVL Tree.
 *
 * Return Value: a string that is the encrypted version of the
 *               item inputted.
 */
template <class Base>
string EncryptionTree<Base>::encrypt(const Base &item) const{
    //can't access AVLNode directly, use get() functions
    string encryption = "r";
    const AVLNode<Base> *temp = this->root;
    bool found = false;

    while(temp!=NULL){
        if(item<temp->getData()){
            encryption += "0";
            temp=temp->getLeft();
        }

            //USE "<" OPERATOR
        else if(temp->getData()<item){
            encryption += "1";
            temp=temp->getRight();
        }

        else {
            //if found, end loop
            temp = NULL;
            found = true;
        }
    }
    delete temp;

    if(!found){
        encryption = "?";
    }

    return encryption;

}

/**
 * decrypt()
 *
 * This function decrypts a variable of type Base in the
 * AVL Tree. The function starts at root with the path's "root"
 * "r". After this, it follows the BST path in finding the item.
 * It will go left if a 0 is in the path given. It will go right
 * if a 1 is in the path given. At the end, it gives the address
 * of the temp data.
 * Essentially:
 * r=root
 * 0=left
 * 1=right
 *
 * Parameters:
 *  path: path is a string that contains the "path" of the
 *        encryption, giving it instructions on how to
 *        decode it into a item of type Base.
 *
 * Return Value: the address of the AVLNode temp, which gives
 *               the data of the decrypted path.
 */
template <class Base>
const Base *EncryptionTree<Base>::decrypt(const string &path) const {
    const AVLNode<Base> *temp = this->root;
    const int pathSize = path.size();

    //root not found, end process by returning NULL
    if (temp == NULL) {
        return NULL;
    }

    //successful, go along path
    for (int i=1; i<pathSize; i++) {
        if (temp != NULL) {
            if (path[i] == '0') {
                temp = temp->getLeft();
            } else {
                temp = temp->getRight();
            }
        }
    }

    //returns address of pointer to item
    return &temp->getData();
}
#endif //PROJECT_4_AVL_TREE_STUDENT_PROJ4_H

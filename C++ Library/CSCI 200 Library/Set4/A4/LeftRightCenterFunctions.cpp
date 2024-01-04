#include "LeftRightCenterFunctions.h"
#include "Node.h"

#include <iostream>
#include <exception>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

LinkedList::LinkedList(){
    mSize = 0;
    mpHead = nullptr;
    mpTail = nullptr;
}
LinkedList::~LinkedList(){
    Node* pNewNode = mpHead;
    while (pNewNode != nullptr){
        pNewNode = mpHead;
        mpHead = mpHead->pNext;
        delete pNewNode;
    }
}
void LinkedList::linked_list_remove_node_at_front(Node*& pHead, Node*& pTail) { // MIGHT NOT NEED THIS HERE
    // if list is empty - do nothing
    if(pHead == nullptr) {
        // cout << "HANG ON";
        return;
    }                
    if(pHead->pNext == nullptr){
        // delete pHead;
        // If broken maybe delete pTail?
        pHead = nullptr;
        pTail = nullptr;
        return;
    }
    // store pointer to current head
    Node* pNewNode = pHead;
    
    // advance head

    // if we're now pointing at nothing, list only had one element
    if (pNewNode->pNext == nullptr){
        //  set tail to also be null so it points to nothing
        pTail = nullptr;
    }
    // otherwise, list still has elements
    else{
    pHead = pHead->pNext;
    }
        // set back pointer to be null
    pHead->pPrev = nullptr;
    
    delete pNewNode;
    // delete former head
    
}
void LinkedList::linked_list_remove_node_at_back(Node*& pHead, Node*& pTail) { // MIGHT NOT NEED THIS HERE EITHER
    if(pTail == nullptr) {
        // cout << "HANG ON";
        return;
    }                
    if(pTail->pPrev == nullptr){
        // delete pHead;
        // If broken maybe delete pTail?
        pHead = nullptr;
        pTail = nullptr;
        return;
    }
    // store pointer to current head
    Node* pNewNode = pTail;
    
    // advance head

    // if we're now pointing at nothing, list only had one element
    if (pNewNode->pPrev == nullptr){
        //  set tail to also be null so it points to nothing
        pHead = nullptr;
    }

    else{
    pTail= pTail->pPrev;
    }

    pTail->pNext = nullptr;
    
    delete pNewNode;
}
int LinkedList::get(const int POS){
    Node* pCurrNode = mpHead;
    if ((int)mSize <= 0 || mpHead == nullptr || (int)mSize <= (int)POS){
        // throw std::out_of_range("ERROR");

    }
    else{
        int counter = 0;
        while(true){
            if(counter == POS){
                return pCurrNode->value;
            }
            if((pCurrNode->pNext == nullptr && counter != POS)|| (POS < 0 || POS <= counter) || (pCurrNode == nullptr)){
            // throw std::exception();
                throw std::out_of_range("OUT OF RANGE");
            }
            else{
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        }
    }
    throw std::out_of_range("ERROR");
}
int LinkedList::find(int target){
    Node* pCurrNode = mpHead;
    if (target == -1){
        for (unsigned int i = 0; i < mSize; i++){
            if (pCurrNode->value != 0){
                return i;
            }
            else{
                pCurrNode = pCurrNode->pNext;
            }
        }
    }
    else{
        for (unsigned int i = 0; i < mSize; i++){
            if (pCurrNode->value == target){
                return i;
            }
            else{
                pCurrNode = pCurrNode->pNext;
            }
        }
    }
    return -1;
}

void LinkedList::insert(const int POS, const int VALUE,const int PLAYERNUM){
    Node* pNewNode = mMakeNodeForValue(VALUE,PLAYERNUM);
    if(mpHead == nullptr) {
        mpHead = pNewNode;
        mpTail = pNewNode;
        return;
    }
    else if(POS >= (int)mSize-1){
        mpTail->pNext = pNewNode;
        pNewNode->pPrev=mpTail;

        mpTail = pNewNode;
    }
    else if( POS <= 0){
        pNewNode->pNext = mpHead;
        mpHead->pPrev = pNewNode;

        mpHead = pNewNode;
    }
    else{
        Node* pCurrNode = mpHead;
        int counter = 0;
        while(counter < POS){
            pCurrNode = pCurrNode->pNext;
            counter++;
        }
    
    pNewNode->pNext=            pCurrNode;
    pNewNode->pPrev=            pCurrNode->pPrev;
    pCurrNode->pPrev->pNext=    pNewNode;
    pCurrNode->pPrev=           pNewNode;
    }
}
int LinkedList::min(){
    if (mSize == 0){
        throw std::out_of_range("ERROR");
    }
    Node* pCURR_NODE = mpHead;
    int maxVal = pCURR_NODE->value;
    
    for(unsigned int i = 0; i < mSize;i++){
        try{
            int tempVal = LinkedList::get(i);
            if (tempVal < maxVal){
                maxVal = tempVal;
            }
        }
        catch(...){
            return maxVal;
        }
    }
    return maxVal;
}
int LinkedList::max(){
    if (mSize == 0){
        throw std::out_of_range("ERROR");
    }
    Node* pCURR_NODE = mpHead;
    int maxVal = pCURR_NODE->value;
    
    for(unsigned int i = 0; i < mSize;i++){
        try{
            int tempVal = LinkedList::get(i);
            if (tempVal > maxVal){
                maxVal = tempVal;
            }
        }
        catch(...){
            return maxVal;
        }
    }
    return maxVal;
}
void LinkedList::remove(const int POS){
    if(mpHead == nullptr) {
        // do nothing
        return;
    } 
        // if position is before start of list
    else if(POS <= 0) {
        // remove from front
        //linked_list_remove_node_at_front(mpHead, mpTail);
        if(mpHead == nullptr) {
        // do nothing
        return;
        } 
        mpHead = mpHead->pNext;
        if(mpHead == nullptr){
            mpTail = nullptr;
        }
        else{
            mpHead->pPrev = nullptr;
        }
        mSize--;
        return;
    }
    else if (POS >= (int)mSize - 1){
            if(mpTail == nullptr) {
                // mpTail->pPrev->pNext = nullptr;
            return;
        }                
        if(mpTail->pPrev == nullptr){
            // delete pHead;
            // If broken maybe delete pTail?
            mpHead = nullptr;
            mpTail = nullptr;
            mSize--;
            return;
        }
        // store pointer to current head
        Node* pNewNode = mpTail;
        
        // advance head

        // if we're now pointing at nothing, list only had one element
        if (pNewNode->pPrev == nullptr){
            //  set tail to also be null so it points to nothing
            mpHead = nullptr;
            mpTail = nullptr;
            return;
        }

        mpTail->pPrev->pNext = nullptr;
        mSize--;
        delete pNewNode;
    }
     
    else {
        Node* pCurrNode = mpHead;
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        while(POS > counter && pCurrNode != nullptr){
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        if(pCurrNode == mpTail || pCurrNode == nullptr){
            if(mpTail == nullptr){
                return;
            }
            Node* pTemp = mpTail;
            mpTail = pTemp->pPrev;
            if (mpTail == nullptr){
                mpHead = nullptr;
                return;
            }
            else{
                mpTail->pNext = nullptr;
            }
            delete pTemp;
            mSize--;
        }
        else{
        pCurrNode->pPrev->pNext = pCurrNode->pNext;
        pCurrNode->pNext->pPrev = pCurrNode->pPrev;
        mSize--;
        }
    }
}
void LinkedList::set(const int POS, const int VALUE){
    Node* pCurrNode = mpHead;
    for (int i = 0; i < (int)mSize; i++){
        if((pCurrNode->pNext == nullptr && i != POS)){
            return;
        }
        if(i == POS){
            pCurrNode->value = VALUE;
            return;
        }
        else{
            pCurrNode = pCurrNode->pNext;
        }
    }
} 
unsigned int LinkedList::size(){
    return mSize;
}
Node* LinkedList::mMakeNodeForValue(const int VALUE){
    Node* Newnode = new Node;
            mSize++;
    Newnode->pNext = nullptr;
    Newnode->pPrev = nullptr;
    Newnode->value = 0;
    Newnode->playernumber = 0;
    // Newnode->pIdentifier = "The Pot";
    return Newnode;
}
Node* LinkedList::mMakeNodeForValue(const int VALUE,const int PLAYERNUM){
    Node* Newnode = new Node;
            mSize++;
    Newnode->pNext = nullptr;\
    Newnode->pPrev = nullptr;
    Newnode->value = VALUE;
    Newnode->playernumber = PLAYERNUM;
    return Newnode;
}
Node* LinkedList::playerGrabber(int player){ //Returns the Node* of the current player
    Node* pCurrNode = mpHead;
    if ((int)mSize <= 0 || mpHead == nullptr || (int)mSize < player){
        int atrox = 0;
        atrox++;
        cout << "``````OUT OF RANGE PLAYER VAL``````";
        throw runtime_error("a");
    }
    else{
        int counter = 0;
        while(true){
            if(counter == player){
                return pCurrNode;
            }
            if((pCurrNode->pNext == nullptr && counter != player)|| (player < 0 || player <= counter) || (pCurrNode == nullptr)){
            // throw std::exception();
                throw std::logic_error("b");
            }
            else{
                pCurrNode = pCurrNode->pNext;
                counter++;
            }
        }
    }
    throw std::exception();
}
bool LinkedList::wincheck(){ // Decides if the game was won or not.
    bool oneValFoundNotZero = false;
    Node* pCurrNode = mpHead;
    for (int i = 0;i < (int)mSize;i++){
        if (pCurrNode == nullptr){
            throw std::out_of_range("OUTTARANGE");
        }
        if (pCurrNode->value ==0){
            pCurrNode = pCurrNode->pNext;
        }
        else if(pCurrNode->value != 0 && oneValFoundNotZero == false){
            oneValFoundNotZero = true;
             pCurrNode = pCurrNode->pNext;
        }
        else if(pCurrNode->value != 0 && oneValFoundNotZero == true){
            return false;
        }
        else{
            throw exception();
        }
    }
    return true;
}
void LinkedList::linked_list_fullprint(){ // Prints the clined list
    if(mpTail->pNext ==nullptr|| mpHead->pPrev == nullptr){
        const Node* pCURR_NODE = mpHead;
        cout << "#  Printing    #" << endl;
        if (pCURR_NODE == nullptr){
                cout << "NULLPNTRHEAD";
                return;
        }
        int counter = 0;
        // advance through list counting number of jumps and continue until position found or at end
        while(true){
            if (pCURR_NODE->pNext == nullptr || pCURR_NODE == nullptr){
                cout << "Current Iterator Mem Spot: " << pCURR_NODE <<
                        //"\nValue #" << counter <<
                        "\nPlayer# " << pCURR_NODE->playernumber<<
                        ": " << pCURR_NODE->value <<
                        "\nNext: " << pCURR_NODE->pNext<< 
                        "\nPrev: " << pCURR_NODE->pPrev<<
                        "\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
                // pCURR_NODE = pCURR_NODE->pNext;
                // counter += 1;
                return;
            }
            else{
                cout << "Current Iterator Mem Spot: " << pCURR_NODE <<
                        // "\nValue #" << counter <<
                        "\nPlayer# " << pCURR_NODE->playernumber<<
                        ": " << pCURR_NODE->value <<
                        "\nNext: " << pCURR_NODE->pNext<< 
                        "\nPrev: " << pCURR_NODE->pPrev<<
                        "\n- - - - - - - - - - - - - - - - - - - - - - - " << endl;
                pCURR_NODE = pCURR_NODE->pNext;
                counter += 1;
            }
        }
    }
    else if (mpHead->pPrev == mpTail && mpTail->pNext == mpHead){
        const Node* pCURR_NODE = mpHead;
        cout << "~  Circlely Linked List  ~\n";
        cout << "#  Printing    #" << endl;
        cout << "\nMetadata: "<<
            "\nHead: " << mpHead <<
            "\nTail: " << mpTail << endl;
        for (int i = 0; i < (int)mSize;i++){
        
                cout << "Current Iterator Mem Spot: " << pCURR_NODE <<
                        // "\nValue #" << counter <<
                        "\nPlayer# " << pCURR_NODE->playernumber<<
                        ": " << pCURR_NODE->value <<
                        "\nNext: " << pCURR_NODE->pNext<< 
                        "\nPrev: " << pCURR_NODE->pPrev<<
                        "\n- - - - - - - - - - - - - - - - - - - - - - - " << endl;
                pCURR_NODE = pCURR_NODE->pNext;
            }
        cout <<"\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$" << endl;
        return;
    }
}
void LinkedList::linked_list_to_circle(){
    mpHead->pPrev = mpTail;
    mpTail->pNext = mpHead;
}
int LinkedList::nextup(int currentNoNonsense,bool& reverse,int& skip){
    if(currentNoNonsense == -1){
        return 0;
    }
    if(reverse == false){
        int retval = (currentNoNonsense + 1 + skip);
        if (retval > (int)mSize){
            skip = 0;
            return retval - mSize;
        }else{
            skip = 0;
            return retval;
        }
    }
    else if (reverse == true){
        int retval = (currentNoNonsense - 1 - skip);
        if(retval < 0){
            skip = 0;
            return retval + mSize;
        }
        else{
            skip = 0;
            return retval;
        }
    }
}
// Main game loop
void gameframe(int& currentTurn, Node*& pCurrentPlayer,bool& reverse, int& skip, int&potval){
    cout << "\nIt's " << pCurrentPlayer->playernumber << "'s turn!" <<
        "\nChips: " << pCurrentPlayer->value << endl;
    if (pCurrentPlayer->value == 0){
        cout << "Player #" << pCurrentPlayer->playernumber <<
            "Doesn't have any chips\n\n Skipping turn...\n" <<
            endl;
            return;
    }
    else if (pCurrentPlayer->value <= 0){
        throw std::out_of_range("Impressive");
    }
    if (pCurrentPlayer->value < 3){
        int roll = -1;
        for (int i = pCurrentPlayer->value; i >=1;i--){
            randomNumberGenerator(roll); 
           if (roll <= 2){
                cout <<"_______\n|  *  |\n|_____|" << endl;
            }
            else if (roll == 3){
                cout <<"_______\n|  L  |\n|_____|" << endl;
                pCurrentPlayer->pPrev->value++;
                pCurrentPlayer->value--;
            }
            else if(roll == 4){
                cout <<"_______\n|  R  |\n|_____|" << endl;
                pCurrentPlayer->pNext->value++;
                pCurrentPlayer->value--;
            }
            else if(roll == 5){
                cout <<"_______\n|  C  |\n|_____|" << endl;
                pCurrentPlayer->value--;
                potval++;
            }
            else if(roll == 6){
                cout <<"_______\n| REV |\n|_____|" << endl;
                if (reverse == true){
                    reverse = false;
                }
                else{
                    reverse = true;
                }
            }
            else if(roll == 7){
                cout <<"_______\n| SKIP|\n|_____|" << endl;
                skip++;
            }
            else{
                throw exception();
            }
        }
    }
    else{
        int roll = -1;
        for (int i = 3; i >= 1;i--){
            randomNumberGenerator(roll); 
            if (roll <= 2){
                cout <<"_______\n|  *  |\n|_____|" << endl;
            }
            else if (roll == 3){
                cout <<"_______\n|  L  |\n|_____|" << endl;
                pCurrentPlayer->pPrev->value++;
                pCurrentPlayer->value--;
            }
            else if(roll == 4){
                cout <<"_______\n|  R  |\n|_____|" << endl;
                pCurrentPlayer->pNext->value++;
                pCurrentPlayer->value--;
            }
            else if(roll == 5){
                cout <<"_______\n|  C  |\n|_____|" << endl;
                pCurrentPlayer->value--;
                potval++;
            }
            else if(roll == 6){
                cout <<"_______\n| REV |\n|_____|" << endl;
                if (reverse == true){
                    reverse = false;
                }
                else{
                    reverse = true;
                }
            }
            else if(roll == 7){
                cout <<"_______\n| SKIP|\n|_____|" << endl;
                skip++;
            }
            else{
                throw exception();
            }
        }
    }
}
void randomNumberGenerator(int& roll){
    roll = (rand() % 7); 
    return;
}
LinkedList printNewGameLoadingScreen(){ // One time loop
    int tempSize = 0;
    int numchips = 3;
    // bool autosim = false;
    cout << "\n\n\n     WELCOME TO WILD LEFT RIGHT CENTER\n" << endl;
        cout << "How many players are you playing with today: "; cin >> tempSize;
        cout << "How many chips should each player start with: "; cin >> numchips;
        // cout << "Do you want to auto sim the game?"; cin >> autosim;
    if (tempSize == 0){
        cout << "Okay, have a nice day!";
        throw exception();
    }       
    else if (tempSize < 0){
        cout << "Unfortunatly I cannot give you friends, Have a nice day!\n";
        throw exception();
    }
    else if(numchips < 0){
        cout << "No going into debit";
        throw exception();
    }
    else if (numchips == 0){
        cout << "\nNOBODY WON\n";
        throw exception();
    }
    else{
        cout << "Wonderful, lets get started!\n";
        LinkedList gametable;
        // gametable.insert(0,0);
        for (int i = 0; i < tempSize ; i++){
            gametable.insert(i,numchips,i+1);
        }
    gametable.linked_list_to_circle(); // Has officially transfered the game board to a Circular doubly linked list. 
    // gametable.linked_list_fullprint();
    return gametable;
    }
}
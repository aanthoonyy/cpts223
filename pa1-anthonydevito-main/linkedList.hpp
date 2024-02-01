#pragma once
#include "data.hpp"
#include <vector>

class LinkedList
{
    Node<Data>* pHead;
    
    public:
    LinkedList(){ pHead = nullptr;}
    ~LinkedList(){}
    bool isEmpty()
	{
		return pHead == nullptr;
	}

    void insert(Data &newData) {
        Node<Data>* newNode = new Node<Data>(newData);
        newNode->pNext = pHead;
        pHead = newNode;
    }

    int flashCard(Node<Data>* pHead_holder, Node<Data>* pCur,Node<Data>* temp, Node<Data>* temp2) {

        //Node<Data>* pHead_holder = pHead;
        //Node<Data>* pCur = pHead;
        //Node<Data>* temp = pHead_holder;
       // Node<Data>* temp2 = pHead_holder;
        
        srand(time(NULL));

        if (pCur != nullptr) {

            int num = (rand() % 30) + 1;
            for (int i = 0; i < num; i++) { 
                temp = temp->pNext;
                }
            num = (rand() % 30) + 1;
            for (int i = 0; i < num; i++) { 
                temp2 = temp2->pNext;
                }


        int randNum = (rand() % 3) + 1;

        if (randNum == 1)
        {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Please pick the correct description for the following command: " << pCur->pData.command << endl 
                << "1. " << pCur->pData.definition << "(" << pCur->pData.points << "pts)" << endl
                << "2. " << temp->pData.definition << "(" << temp->pData.points << "pts)" << endl
                << "3. " << temp2->pData.definition << "(" << temp2->pData.points << "pts)" << endl;
            cout << "------------------------------------------------------------------------" << endl;

            temp = pHead_holder;
            temp2 = pHead_holder;
            pCur = pCur->pNext;
        }
        
        
        if (randNum == 2)
        {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Please pick the correct description for the following command: " << pCur->pData.command << endl 
                << "1. " << temp2->pData.definition << "(" << temp2->pData.points << "pts)" << endl
                << "2. " << pCur->pData.definition << "(" << pCur->pData.points << "pts)" << endl
                << "3. " << temp->pData.definition << "(" << temp->pData.points << "pts)" << endl;
            cout << "------------------------------------------------------------------------" << endl;

            temp = pHead_holder;
            temp2 = pHead_holder;
            pCur = pCur->pNext;
        }

        if (randNum == 3)
        {
            cout << "------------------------------------------------------------------------" << endl;
            cout << "Please pick the correct description for the following command: " << pCur->pData.command << endl 
                << "1. " << temp->pData.definition << "(" << temp->pData.points << "pts)" << endl
                << "2. " << temp2->pData.definition << "(" << temp2->pData.points << "pts)" << endl
                << "3. " << pCur->pData.definition << "(" << pCur->pData.points << "pts)" << endl;
            cout << "------------------------------------------------------------------------" << endl;

            temp = pHead_holder;
            temp2 = pHead_holder;
            pCur = pCur->pNext;
        }



        int answer;
        cout << "enter answer (1-3): ";
        cin >> answer;
        cout << endl;

        if (answer == randNum){
            return stoi(pCur->pData.points);
        }

        
        else{
            
            return -1*(stoi(pCur->pData.points));
            
        }
        }
    }

    void printList(){
    
    Node<Data> *pCur = pHead;
    while (pCur != nullptr){
    cout << pCur->pData.command << "," << pCur->pData.definition<< "," << pCur->pData.points << endl;
    pCur = pCur->pNext;
    }
    }


    void storeCommands(fstream infile)
    {
    Node<Data> *pCur = pHead;
    while (pCur != nullptr)
    {
        infile << pCur->pData.command << "," << pCur->pData.definition<< "," << pCur->pData.points << endl;
        pCur = pCur->pNext;
    }
    }


    Node<Data>* getHead() { return pHead; }

    void setpHead(Node<Data>* newpHead) { pHead = newpHead; }

    void removeNode(string &remove){
        Node<Data>* pCur = pHead;
        
        if (pCur->pData.command == remove) {
            pHead = pHead->pNext;
            delete pCur;
            return;
        }
        while (pCur->pNext != nullptr) {
        if (pCur->pNext->pData.command == remove) {
            Node<Data> *temp = pCur->pNext;
            pCur->pNext = pCur->pNext->pNext;
            delete temp;
            return;
        }
        pCur = pCur->pNext;
    }
    
    std::cout << "Command not found." << std::endl;
    }

};
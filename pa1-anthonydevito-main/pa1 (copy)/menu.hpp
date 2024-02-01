#pragma once
#include "linkedList.hpp"




class Menu{
    public:
	Menu(){}
	~Menu(){}

   struct player{
        string players[100];
        int points[100];
        int arrSize;
    };

   

	void runapp();
	int printmenu();
	void case1();
    void case2(Data data, LinkedList &list, vector<vector<string>> &profileVector);
    void case3(Data data, LinkedList &list, vector<vector<string>> &profileVector);
    void case4(Data data, LinkedList &list);
    void case5(Data data, LinkedList &list);
    void case6(Data data, LinkedList &list);
    int case7(Data data, LinkedList &list, vector<vector<string>> &profileVector);

	 
private:
	LinkedList list;
    Data data;
};

void Menu::runapp()
{

    Data data;
	LinkedList list;
	Node<Data>* node = nullptr;
    fstream infile;
    fstream profileInfile;
    vector<vector<string>> profileVector;
    profileInfile.open("profiles.csv");
	infile.open("commands.csv");
    player p;
    
    while (!infile.eof())
    {
        string grab;
        string grab2;
        string grab3;
        getline(infile, grab, ',');
        getline(infile, grab2, ',');
        getline(infile, grab3, '\n');
        //list.insert(grab, grab2, grab3);
        if (grab != "" && grab != "" && grab3 != ""){
        Data data(grab, grab2, grab3);
        list.insert(data);
        }

    }
    //list.removeNode(","); remoev the ,, on a the file
    while (!profileInfile.eof())
    {
        string grab;
        string grab2;
        string grab3;
        getline(profileInfile, grab, ' ');
        getline(profileInfile, grab2);
        //getline(profileInfile, grab3);
        if (grab != "" && grab2 != ""){
            profileVector.push_back({grab, grab2});
        }
  
    }
    profileInfile.close();
    infile.close();
    int expression = 0;
    bool loop = true;
    

    while (loop == true){
 
        system("clear");
    cout << "Menu" << endl << "pick a number 1-7" << endl;
    cout << "1. game rules" << endl 
        << "2. play new game" << endl
        << "3. load previous game" << endl
        << "4. add command" << endl
        << "5. remove command" << endl
        << "6. display all commands" << endl
        << "7. save amd exit" << endl;

    cin >> expression;
        
    switch (expression)
    {
    case 1:
        case1();
        break;
    case 2:
        case2(data, list, profileVector);
        break;
    case 3:
        case3(data, list, profileVector);
        break;
    case 4:
        case4(data, list);
        break;
    case 5:
        case5(data, list);
        break;

    case 6:
    case6(data, list);
        break;
    case 7:
        case7(data, list, profileVector);
        loop = false;
        break;
    default:
        break;
    }

    }
}

void Menu::case1(){
system("clear");
cout << "--------------" << endl
<< "RULES" << endl
<<"Match the correct defintion to Linux command!" << endl
<< "enter menu to go back to menu" << endl;
string nothing;
cin >> nothing;
}


void Menu::case2(Data data, LinkedList &list, vector<vector<string>> &profileVector){
    cout << "enter player name" << endl;
    string playerName;
    cin >> playerName;
    bool playingFromMemory = false;
    int user;
    for (int i = 0; i < profileVector.size(); i++)
    {
        if (profileVector[i][0] == playerName){
            cout << " would you like to pick up where you left off? (y/n)" << endl;
            string foundUser;
            cin >> foundUser;
            if(foundUser == "y" || foundUser == "Y"){
                //case3(data, list, profileVector, playerName);
                user = i;
                playingFromMemory = true;
                goto fUser;
                cout << "found user " << endl;
            }

        }
    }    
    profileVector.push_back({playerName, "0"});


    fUser:
    cout << "enter how many rounds you'd like to play 5-30: " << endl;
    int rounds = 0;
    cin >> rounds;
    cout << "printing linked list" << endl;
    
    list.printList();
    cout << "sleeping for 3 seconds" << endl;
    sleep(3);
    
    system("clear");
    Node<Data>* pHead_holder = list.getHead();
    Node<Data>* pCur = list.getHead();
    Node<Data>* temp = pHead_holder;
    Node<Data>* temp2 = pHead_holder;
        
    //string answer;
    int score = 0;
    for(int i = 0; i < rounds; i++){
        score += list.flashCard(pHead_holder,pCur,temp,temp2);
        cout << "---------" << endl << " points";
        cout << endl << "   " << score << endl << "---------" << endl;
        pCur = pCur->pNext;
    }

    //score = stoi(profileVector[user][1]) + score;
    if (playingFromMemory == true){profileVector[user][1] = to_string(score);}

    else
    {
        for (int i = 0; i < profileVector.size(); i++)
        {
            if (profileVector[i][0] == playerName)
            {
                profileVector[i][1] = to_string(score);
            }
        }
    }
}

void Menu::case3(Data data, LinkedList &list, vector<vector<string>> &profileVector)
{
    system("clear");
    cout << "type the name of the profile you want to to load" << endl;
    for (int i = 0; i < profileVector.size(); i++) {
    for (int j = 0; j < profileVector[i].size(); j++) {
        cout << profileVector[i][j] << " ";
    }
    cout << endl;
    }
    cout << endl;
    string profileSelect;
    cin >> profileSelect;

    cout << "enter how many rounds you'd like to play 5-30: " << endl;
    int rounds = 0;
    cin >> rounds;
    cout << "printing linked list" << endl;
    
    list.printList();
    cout << "sleeping for 3 seconds" << endl;
    sleep(3);
    
    system("clear");
    Node<Data>* pHead_holder = list.getHead();
    Node<Data>* pCur = list.getHead();
    Node<Data>* temp = pHead_holder;
    Node<Data>* temp2 = pHead_holder;
        
    //string answer;
    int score = 0;
    for(int i = 0; i < rounds; i++){
        score += list.flashCard(pHead_holder,pCur,temp,temp2);
        cout << "---------" << endl << " points";
        cout << endl << "   " << score << endl << "---------" << endl;
        pCur = pCur->pNext;
    }

    for (int i = 0; i < profileVector.size(); i++)
        {
            if (profileVector[i][0] == profileSelect)
            {
                profileVector[i][1] = to_string(score);
            }
        }
}


void Menu::case4(Data data, LinkedList &list)
{
    string prompt;
    bool exit = false;
    while (exit == false)
    {
    system("clear");

    string grab;
    string grab2;
    string grab3;


    cout << "add a command!" << endl;
    cin >> grab;
    cout << "add a definition!" << endl;
    cin >> grab2;
    cout << "add the number of points!" << endl;
    cin >> grab3;

    Data data(grab, grab2, grab3);
    list.insert(data);

    cout << "definition added!" << endl;

    cout << "would you like to add another definition (yes) or exit (no)" << endl;
    cin >> prompt;
    if (prompt == "no" || prompt == "No"){
        exit = true;
        }

    }
}

void Menu::case5(Data data, LinkedList &list){
cout << "remove a command!"<< endl << endl;

list.printList();

cout << endl;
cout <<"type the command you want to remove" << endl;
string remove;
cin >> remove;
cout << "are you sure you want to remove " << remove << "? (y/n)" << endl;
string confirm;
cin >> confirm;

if (confirm == "y" || confirm == "Y")
{
    list.removeNode(remove);
}




}

void Menu::case6(Data data, LinkedList &list){
    cout << "printing list!" << endl;
    list.printList();
    cout << endl << "enter menu to go back to menu" << endl;
string nothing;
cin >> nothing;

}

int Menu::case7(Data data, LinkedList &list, vector<vector<string>> &profileVector)
{
    fstream infile;
    fstream profileOutfile;
    profileOutfile.open("profiles.csv");
    infile.open("commands.csv");
    //list.storeCommands(infile);      // this doesnt work it gives me a deleted function error?
    Node<Data> *pCur = list.getHead();
    while (pCur != nullptr)
    {

        infile << pCur->pData.command << "," << pCur->pData.definition<< "," << pCur->pData.points << endl;
        pCur = pCur->pNext;
    }
    string getProfile;
    string getScore;
    for (int i = 0; i < profileVector.size(); i++) {
        for (int j = 0; j < profileVector[i].size(); j++) {

            profileOutfile << profileVector[i][j] << " ";
            
            
        }
        profileOutfile << endl;
    }
    profileOutfile.close();
    infile.close();
    return 0;
}
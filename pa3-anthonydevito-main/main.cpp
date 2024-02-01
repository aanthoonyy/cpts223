#include <iostream>
#include <fstream>
#include <ostream>
#include "AVLTree.hpp"
using namespace std;

/*
° (2 pts) What is the worst-case Big-O of the insert() algorithm for the AVL tree? Explain. 
    ° The worst-case Big-O for insert() algoithm for a AVLTree would be O(LogN) because 
        it might not only have to tranverse the entire tree, but it will need to also preform the
        needed rotations to maintain a balanced tree.
° (5 pts) What is the worst-case Big-O of the printInOrder() algorithm for the AVL tree? Explain. 
    ° The worst-case Big-O for printInOrder() algorithm would be O(N) because it traverses
        the tree one by one and prints each node one by one.
° (3 pts) What is the worst-case Big-O of the findMax() algorithm for the AVL tree? Explain. 
    ° The worst-case Big-O for findMax() algorithm would be O(LogN) because the height of a AVL
        tree is O(LogN) and it will have to traverse the whole thing looking for the biggest
        Node. You can prove this by using mathmatical induction!
*/


int main( )
{
    ifstream allCancerCSV("allcancerdata2018.csv");
    ifstream menCancerCSV("mencancerdata2018.csv");
    ifstream womenCancerCSV("womencancerdata2018.csv");

    AVLTree<CancerData> allTree;
    AVLTree<CancerData> menTree;
    AVLTree<CancerData> womenTree;
    int test = 0;
    // all cancer data
    string grab;
    string grab2;
    while (!allCancerCSV.eof()){
    getline(allCancerCSV, grab, ',');
    getline(allCancerCSV, grab2, '\n');
        if (grab != "" && grab2 != "")
        {
            CancerData data(grab, stod(grab2));
            allTree.insert(data);
        }
    }
    

    while (!menCancerCSV.eof()){
    getline(menCancerCSV, grab, ',');
    getline(menCancerCSV, grab2, '\n');
        if (grab != "" && grab2 != "")
        {
            
            CancerData data(grab, stod(grab2));
            menTree.insert(data);
        }
    }

    while (getline(womenCancerCSV, grab, ',') && getline(womenCancerCSV, grab2, '\n')){
    // getline(womenCancerCSV, grab, ',');
    // getline(womenCancerCSV, grab2, '\n');
        if (grab != "" && grab2 != "")
        {
            
            CancerData data(grab, stod(grab2));
            womenTree.insert(data);
        }
    }


    int rank = 1;
    string a = "all";
    string m = "men";
    string w = "women";
    
    //<label: rank number. country name. rate>, 
    cout << "<All: rank number. country name. rate>" << endl <<"-------------------------" << endl;
    allTree.printTree(rank, a);
    rank = 1;
    cout << endl << endl << "<Men: rank number. country name. rate>" << endl <<"-------------------------" << endl;
    menTree.printTree(rank, m);
    rank = 1;
    cout << endl << endl << "<Women: rank number. country name. rate>" << endl <<"-------------------------" << endl;
    womenTree.printTree(rank, w);



    cout << endl << endl << "------------------------------" << endl << "high and low records" << endl;
    allTree.printFirst(rank, a);
    menTree.printFirst(rank, m);
    womenTree.printFirst(rank, w);
    rank = 50;
    allTree.printLast(rank, a);
    menTree.printLast(rank, m);
    womenTree.printLast(rank, w);


    allCancerCSV.close();
    womenCancerCSV.close();
    menCancerCSV.close();
 
    return 0;
}
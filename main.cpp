 #include <cstddef>
#include <iostream>
#include <time.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>
using namespace std;
#include "lista.h"
#include "hashtablevd.h"
#include "bst.h"


// Carlos Alberto Mendoza
// Carlos Damian Suarez


int main(int argc, char * argv[]) {
 /*BST<int> bst;
 bst.insert(83);
 bst.insert(50);
 bst.insert(90);
 bst.insert(12);
 bst.insert(1);
 bst.insert(100);
 bst.insert(55);




  
 bst.inOrden(); 
 cout<<endl<<"-------------"<<endl;
 bst.postOrden();
 cout<<endl<<"-------------"<<endl;
 bst.preOrden();
 cout<<endl<<"-------------"<<endl;
 cout<<"contiene 1: "<<bst.contains(1)<<endl;
 cout<<"contiene 10: "<<bst.contains(10)<<endl;
 cout<<"contiene 83: "<<bst.contains(83)<<endl;

  
cout <<"Nodo minimo:" << bst.getMin() << endl;
cout << "Nodo maximo: " << bst.getMax() << endl;
cout << "Nodos en el arbol: "<< bst.length() << endl;
  
  
bst.remove(1);
cout<<endl<<"-------------"<<endl;
bst.inOrden();

cout <<endl<< "Nodo minimo: " << bst.getMin() << endl;

cout <<endl<< "Altura del arbol: " << bst.getHeight() << endl;

bst.ComparadorHeight();*/
  

LinkedList<BST<int>> Bosque;
BST<int> Arbol[10];
srand (time(NULL));
for (int i=0 ; i<10 ; i++){
  for(int o=0; o<15; o++){
      Arbol[i].insert(rand() % 100 + 1);    
  }                                         // O(n^2)
Bosque.addLast(Arbol[i]);
Arbol->inOrden();
cout << endl;
Bosque.get(i).ComparadorHeight();
cout << endl;
}

}
/* 
 * File:   main.cpp
 * Author: lee
 *
 * Created on 14 February 2012, 16:49
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include <fstream>



using namespace std;
class node{
public:
    string cityName;
    float longitude,latitude;
    char longitudeBearing,latitudeBearing;
    node *leftChild;    // Pointer to another node.
    node *rightChild;
    node();
    node(string);
    node(string,float,float,char,char);
};
node :: node(){
    return;
}
node :: node(string info){
        cityName = info;
        longitude = 0;
        latitude = 0;
        longitudeBearing = 'X';
        latitudeBearing = 'X';
        leftChild= NULL;
        rightChild = NULL;
    }
node :: node(string info,float longi, float lat,char longiB, char latB){
        cityName = info;
        longitude = longi;
        latitude = lat;
        longitudeBearing = longiB;
        latitudeBearing = latB;
        leftChild= NULL;
        rightChild = NULL;
    }

class tree{

    
public:
    ofstream outputFile;
    ifstream inputFile;
    node *start;
    void addToTree(node);
    void treeList(node*);
    void deleteFromTree(string);  
    node* search(string);
    void save();
    void load();
private:
    node* search(node*,string);
    void addToTree(node*&,node);
    void saveToFile(node*);
    bool treeContains(string);
    string convertToUpperCase(string);
    
};     


//Public functions
void tree :: addToTree(node newNode){
  
    newNode.cityName = convertToUpperCase(newNode.cityName);
    
    if(treeContains(newNode.cityName)){
        cout<<"You cannot add the city name "<< newNode.cityName <<" as it already exists in the database"<<endl;
    }else{
    
        if(start == NULL){                        //If the tree is empty

            start = new node(newNode.cityName,newNode.longitude, newNode.latitude, newNode.longitudeBearing, newNode.latitudeBearing);            //put entry here.
            return;
        }
        if(newNode.cityName < start->cityName){                                                                                             
            addToTree(start->leftChild,newNode);
            /* if the city name is less than city name in the current node
              repeat the process with its left child */
        }
        else{
            addToTree(start->rightChild,newNode);
            /* if the city name is greater than city name in the current node
             repeat the process with its right child */  
        }
    }
}
void tree :: treeList(node *tree) {
       
   if ( tree != NULL ) {
       treeList(tree->leftChild);           
       cout << tree->cityName <<","<<tree->longitude<<","<<tree->latitude<<","<<tree->longitudeBearing<< 
               ","<<tree->latitudeBearing<< endl; 
       treeList(tree->rightChild);         
   }
}
void tree :: deleteFromTree(string cityName){
    
    cityName = convertToUpperCase(cityName);
    
    bool found = false;
    
    if(start == NULL){
        cout << "No cities in database"<<endl;
        return;
    }
    bool hasSuper = false;
    node* current;
    node* super;
    current = start;
    
    while(current != NULL){
        if(current->cityName == cityName){
            found = true;
            break;
        }else{
            hasSuper = true;
            super = current;
            if(cityName > current->cityName){
                current = current->rightChild;
            }else{
                current = current->leftChild;
            }
        }
    }
   

    if(current->rightChild == NULL && current->leftChild == NULL && hasSuper){
        //has no children
        if(current->cityName > super->cityName){
            super->rightChild = NULL;
        }else{
            super->leftChild = NULL;
        }
            
        
    }
    if(current->rightChild == NULL && current->leftChild != NULL && hasSuper){
        //Has only a left child
        if(current->cityName > super->cityName){
            //current node is the right child of its super
            super->rightChild = current->leftChild;
            delete current;
            
        }else{
            //Current node is the left child of its super
            super->leftChild = current->leftChild;
            delete current;
        }
        
        
    }
    if(current->rightChild != NULL && current->leftChild == NULL && hasSuper){
        //Has only a right child
        if(current->cityName > super->cityName){
            //current node is the right child of its super
            super->rightChild = current->rightChild;
            delete current;
            
        }else{
            //Current node is the left child of its super
            super->leftChild = current->rightChild;
            delete current;
        }
        
    }
    
    if(current->rightChild !=NULL && current->leftChild != NULL && hasSuper){
        //Has two kids
        node* temp;
        //Get the highest node on the left side and make the left child of that node the first node in the
        //right side.
        temp = current->leftChild;
        while (temp->rightChild!= NULL){
            temp = temp->rightChild;
            }
        temp->rightChild = current->rightChild;
        
        if(current->cityName < super->cityName){
            super->leftChild = current->leftChild;
            delete current;
        }else{
            super->rightChild = current->leftChild;
            delete current;
        }
        
     }
    if(!hasSuper){
        //This is deleting the root.
        node* temp;
        temp = current->leftChild;
        while (temp->rightChild!= NULL){
            temp = temp->rightChild;
            }
        temp->rightChild = current->rightChild;
        
        start = current->leftChild;
        delete current;
    }
    
    
}
node* tree :: search(string cityName){
    cityName = convertToUpperCase(cityName);
    
    if(cityName == start->cityName){
        return start;
    }
    if(cityName > start->cityName){
        return search(start->rightChild,cityName);
    }
    if(cityName < start->cityName){
        return search(start->leftChild,cityName);
    }
}
void tree :: save(){
    outputFile.open("data.csv");
    saveToFile(start);
    outputFile.close();
}
void tree :: load(){
    inputFile.open("data.csv");
    string cityName,longi,lat, longb,latb;
    float longitude,latitude;
    char longitudeBearing, latitudeBearing;
    int i =0;
    
    while(inputFile.good()){
        i++;
        
        getline(inputFile,cityName,',');
        if(inputFile.eof()){
            break;
        }
        getline(inputFile,longi,',');       
        getline(inputFile,lat,',');        
        getline(inputFile,longb,',');       
        getline(inputFile,latb,',');
        
        longitude = (float)atof(longi.c_str());
        latitude = (float)atof(lat.c_str());
        longitudeBearing = longb[0];
        latitudeBearing = latb[0];
        
        
        addToTree(node(cityName,longitude,latitude,longitudeBearing,latitudeBearing));
        
    }
    
    
}
//Private functions
void tree :: addToTree(node *&element, node newNode){
    
    
    if(element == NULL){                        //If the tree is empty
        
        element = new node(newNode.cityName,newNode.longitude, newNode.latitude, newNode.longitudeBearing, newNode.latitudeBearing);            //put entry here.
        return;
    }
    if(newNode.cityName < element->cityName){                                                                                             
        addToTree(element->leftChild,newNode);
        /* if the city name is less than city name in the current node
          repeat the process with its left child */
    }
    else{
        addToTree(element->rightChild,newNode);
        /* if the city name is greater than city name in the current node
          repeat the process with its right child */   
    }
}
node* tree :: search(node *element,string cityName){
    if(cityName == element->cityName){
        return element;
    }
    if(cityName > element->cityName){
        return search(element->rightChild,cityName);
    }
    if(cityName < element->cityName){
        return search(element->leftChild,cityName);
    }
}
void tree :: saveToFile(node *tree){
    
    
    if ( tree != NULL ) {
       saveToFile(tree->leftChild); 
       
       outputFile << tree->cityName <<","<<tree->longitude<<","<<tree->latitude<<","<<tree->longitudeBearing<< 
               ","<<tree->latitudeBearing<< ","; 
       saveToFile(tree->rightChild);         
   }
    
}
bool tree :: treeContains(string cityName){
    
    cityName = convertToUpperCase(cityName);
    
    node* current;
    current = start;
    
    bool found = false;
    
    while(current != NULL){
        if(current->cityName == cityName){
            found = true;
            break;
        }else{
            if(cityName > current->cityName){
                current = current->rightChild;
            }else{
                current = current->leftChild;
            }
        }
    }
    return found;
    
}
string tree :: convertToUpperCase(string toConvert){
    for(int i = 0; i < toConvert.length(); i++){                //Convert all city names to upper case.
        if((toConvert[i] >= 97 )&&(toConvert[i] <= 122) )
        toConvert[i]= toConvert[i]-32;
    }
    return toConvert;
}
 


int main(int argc, char** argv) {
    
    
    
    tree myTree;
    myTree.start = NULL;
    myTree.load();
    myTree.treeList(myTree.start);

   
}

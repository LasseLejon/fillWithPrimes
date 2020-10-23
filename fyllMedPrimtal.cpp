#include <iostream>
#include <cassert>
using namespace std;



void writeArray(int arr[], int antal){
    cout << "(";
    for(int i=0; i<antal; i++)
        cout << arr[i] << " ";
    cout << ")";
}


void fillWithPrimes(int arr[], int antal){
    for(int i=1; i<antal; i+=1){
        arr[0]=2;
        int p=(arr[i-1])+1;
        int maybeP=0;
        for(int k=0; k<i;k++){
            if(p%arr[k]!=0 && p!=arr[i-1] && p%2!=0)
                maybeP=p;
            else{
                p++;
                k=0;
            }
        }
        arr[i]=maybeP;
    }

}


void findWhereInArray(int arr[],int antal, int x){
    for(int i=0; i<antal;i++){
        if(arr[i]==x)
            cout << "The value " << x << " is located at position: " << i << " in the array"<< endl;


    }

}
void testFillWithPrimes(){
    const int antalTal = 50;
    int talen[antalTal];
    fillWithPrimes(talen, antalTal);
    writeArray(talen, antalTal);
    cout << endl;
}
void shortcutToPrimes(){

    testFillWithPrimes();
}


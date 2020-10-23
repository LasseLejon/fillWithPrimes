#include <iostream>
#include <thread>
#include <chrono>
#include <stdbool.h>
#include <vector>
#include <cassert>

using namespace std;

bool isSkottYear(int year){
    return ((year % 4 == 0) && (year % 100 != 0)) || year == 2000;
}

int antalDagar(int year, int month){
    const int daysInMonth[13]{0,31,28,31,30,31,30,31,31,30,31,30,31};
    if (month==2 && isSkottYear(year))
        return 29;
    return daysInMonth[month];
}

void exchangeSystemV2(int antalKronor){
    int valorer[8]{500,200,100,20,10,5,2,1};
    cout << antalKronor << " kronor är:" << endl;
    for(int i=0; i<8; i+=1){
        int antalAv = antalKronor/valorer[i];
        antalKronor -= valorer[i]*antalAv;
        if(antalAv>=1)
            cout << antalAv << " x " << valorer[i] << endl;
    }
}
void tryToChangeValues(int a, int arr[], int nOfValues){
    a=42;
    for(int i = 0;i<nOfValues;i+=1)
        arr[i]=42;
}

void callTryToChangeValues(){
    int a=0;
    int arr[2]{0,0};
    tryToChangeValues(a, arr ,2);
    cout << "a=" << a << ", arr[]= " << arr[0] << ", " << arr[1] << endl;
}

void skrivUtArr(int arr[], int antal){
    cout << "(";
    for(int i=0; i<antal; i+=1)
        cout << arr[i] << " ";
    cout << ")" << endl;
}
void fyllMedKonstant(int arr[],int antal,int konstant){
    for(int i=0;i<antal;i+=1){
        arr[i]=konstant;
        cout << arr[i] << " ";
    }
    cout << endl;
}
void fyllMedSlumptal(int arr[], int antal, int big, int small){
    for(int i=0; i<antal;i+=1){
        arr[i]=(rand() % big + 1 - small) + small;
    }

}
int minst(int arr[], int antal){
    int minsta = arr[0];
    for(int i=0;i<antal;i+=1){
        if(minsta>arr[i])
            minsta=arr[i];
    }
    return minsta;
}
int bigg(int arr[], int antal){
    int bigga = arr[0];
    for(int i = 0;i<antal;i+=1){
        if(bigga<arr[i])
            bigga=arr[i];
    }
    return bigga;
}
bool isSorted(int arr[], int antal){
    for(int i=0; i<(antal-1);i+=1){
        if(arr[i] > arr[i+1])
            return false;
    }
    return true;
}
bool innehX(int arr[], int antal, int x){
    for(int i=0;i<antal;i+=1){
        if(arr[i]==x)
            return true;
    }
    return false;
}

void provaArrayFunktioner(){
    const int storlek = 10;
    int arr[storlek];

    skrivUtArr(arr, storlek);
    fyllMedKonstant(arr, storlek, 3);
    fyllMedSlumptal(arr, storlek, 2, -2);
    int m = minst(arr, storlek);
    int b = bigg(arr, storlek);
    cout << "Minsta: " << m << ", största: " << b << endl;
    int x = isSorted(arr, storlek);
    cout << x << endl;
    int y = innehX(arr, storlek, 12);
    cout << y << endl;
}
void sorteraMedSelectionSort(int arr[],int antal){
    for(int i=0;i<antal;i+=1){
        int kMin=i;
        for(int k=i;k<antal;k+=1){
            if(arr[k]<arr[kMin])
                kMin=k;

        }
        int gamlaI= arr[i];
        arr[i]=arr[kMin];
        arr[kMin]=gamlaI;
    }
}

void sorteraMedBubbleSort(int arr[], int antal){
    for(int i=0;i<antal;i+=1){
        for(int k=0;k<(antal-1);k+=1){
            if(arr[k]>arr[k+1]){
                int temp=arr[k];
                arr[k]=arr[k+1];
                arr[k+1]=temp;

            }

        }
    }
}

void provaSortering(){
    const int storlek = 20;
    int arr[storlek]{20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1 };
    sorteraMedSelectionSort(arr, storlek);
    sorteraMedBubbleSort(arr, storlek);
}
void provaSorteraMedSelection(){
    const int storlek = 20;
    int arr[storlek];
    fyllMedSlumptal(arr, storlek,100,0);
    skrivUtArr(arr,storlek);
    if(isSorted(arr, storlek))
        cout << "BUG, fyll slumptal verkar inte fungera." << endl;
    sorteraMedSelectionSort(arr, storlek);
    if(isSorted(arr, storlek))
        cout << "Det verkar som Select-sorteringen fungerade" << endl;
    else
        cout << "Bug i sorteringen" << endl;
    skrivUtArr(arr,storlek);
}

void fyllMedUnikaSlumptal(int arr[], int antal, int minst, int storst){
    int ix=0;
    while(ix<antal){
        int x=(rand() % storst+1-minst)+minst;
        bool isDublett = false;
        for(int k=0; k<ix;k+=1){
            if(arr[k]==x){
                isDublett = true;
                break;
            }
        }
        if(!isDublett){
            arr[ix]=x;
            ix+=1;
        }
    }
}
void fyllMedPrimtal(int arr[], int antal){
    arr[0]=2;
    for(int i=1;i<antal;i+=1){
        int p = arr[i-1];
        assert(p==arr[i-1]);
        break;
        for(int maybePrime=p; true; maybePrime+=1){
            if(maybePrime>p)
                assert(maybePrime>2);
                break;
            bool hittatDelare=false;

            for(int k=0; k<i && !hittatDelare; k+=1){
                if((maybePrime % arr[k]) == 0)
                    hittatDelare=true;
                assert(maybePrime>2);
                break;
            }
            if(!hittatDelare)
                assert(maybePrime>2);
                arr[i]=maybePrime;

        }

    }


}
bool inneHaller(int arr[],   int storlek,    int x){

    int i=0;
    while (i<storlek && arr[i]!=x)
           i+=1;
    return i<storlek;

}
//void provaFyllMedPrim(){
    //const int storlek = 10;
   // arr[storlek]

    //const int antalTal=50;
    //int talen[antalTal];
    //fyllMedPrimtal(talen, antalTal);
    //skrivUtArr(talen,antalTal);
    //cout << endl;
//}

//vectorer
//void tryToChangeValuesOfVector(int a, vector <int> vec){
//a=42;
// for(int i=0; i<vec.size();i+=1)
//vec[i]=42;
//}
//void callTryToChangeValuesOfVector(){
//  int a=0;
//vector <int> vec{0,0};
//tryToChangeValuesOfVector(a, vec);
//cout << "a= " << a <<", vec[]= " << vec[0] << ", " << vec[1] << endl;
//}
//Kap 5 Funktionen assert
void testarMinaKunskaper(){
    assert(2.5+3==5.5);
    assert(5/2==2);
    assert(1.0/2*10==5);
    assert(1/2*10==0);
    assert((3|16)==19);
    assert((3|15)==15);
    assert((3&16)==0);
    assert((3&15)==3);
    assert(3<<2==12);
    cout << "done" << endl;
}
//00001100
//00001111
bool almostSame(double a, double b){
    double epsilon=0.001;
    double diff = a-b;
    return(diff<epsilon && diff>(-epsilon));
}
bool almostSameTwo(double x, double y){
    return x-y < 0.001;

}
void automaticAlmostSame(){
    assert(almostSameTwo(2,2.000005));
    assert(almostSameTwo(2-0.00005,2));
    assert(!almostSameTwo(2,3));
    assert(!almostSameTwo(3,2));
}

unsigned int colorInfo(unsigned int red, unsigned int green, unsigned int blue, unsigned int opacity){
    unsigned int color=0;
    assert(red>=0 && red <256 && green >=0 && green < 256 && blue >=0 && blue < 256 && opacity >=0 && opacity < 256);
    color = color | red << 24;
    color = color | green << 16;
    color = color | blue << 8;
    color = color | opacity;
    return color;
}
unsigned int getRedInfo(unsigned int color){
    unsigned int red = (color >> 24) & 255;
    return red;

}
unsigned int getGreenInfo(unsigned int color){
    unsigned int green = (color >> 16) & 255;
    return green;
}
unsigned int getBlueInfo(unsigned int color){
    unsigned int blue = (color >> 8) & 255;
    return blue;
}
unsigned int getOpacityInfo(unsigned int color){
    unsigned int opacity = color & 255;
    return opacity;
}

void shortcutToArrayer(){
    callTryToChangeValues();
    //int storlek = 50;
    //int arr[storlek];
    //fyllMedPrimtal(arr, storlek);
    //skrivUtArr(arr, storlek);
}

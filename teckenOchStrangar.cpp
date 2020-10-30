#include <iostream>
#include <cassert>
#include <string>

using namespace std;
int returneratal(const char str[]){
    for(int i=0;true;i+=1)
        if(str[i]==0)
            return i;
    return 999;
}
void provareturntal(){
    int a = returneratal("Hej");
    cout << a << endl;

}
void demoAvChar(){
    char ch1= 'A'+2;
    int ch2=ch1;
    int i1='A';
    int i2=82;
    cout << "a= " << ch1 << endl;
    cout << ch2 << endl;
    cout << i1 << endl;
    cout << i2 << endl;
}

void writeAsciiSigns(){
    const char tabulator = 9;
    for(int asciital = 'a'-5;asciital<'z'+5;asciital++){
        char tecken = asciital;
        cout << asciital << tabulator << tecken << endl;
    }

}
void demoOfStrings(){
    char string1[4]{'H','e','j',0};
    char string2[]{'H','e','j',0};
    char string3[]="Hej";
    char string4[]{"Hej"};
    cout << string1 << "\n";
    cout << string2 << "\n";
    cout << string3 << "\n";
    cout << string4 << endl;

    cout << "Hej" << endl;
}
void demoAvUtf8(){
    char string[]="ABC 012 ÅÄÖ";
    cout << string << endl;
    for(int i=0; string[i]!=0;i++){
        int heltal=string[i];
        cout << heltal << " ";
    }
    cout << endl;
}
void demoOfConst(const char str[]){
    int i=0;
    while(str[i]!=0)
        i++;
    cout << "Antal Byte i " << str << "är " << i << endl;
}
void provarDemoAvConst(){
    char str[]= "Hej";
    demoOfConst(str);
    demoOfConst("Hello");
}
bool areSame(const char str1[], const char str2[]){
    int i = 0;
    while(str1[i]!=0 || str2[i]!=0){
        for(int k=0; k<=i; k++){
            if(str1[k] != str2[k])
                return false;
        }
        i++;
    }
    return true;
}
void testAreSame(){
    assert(areSame("abcd", "abcd"));
    assert(!areSame("abcd e", "abcd"));
    assert(!areSame("abcd", "abcd e"));
    assert(!areSame("abcd", "abcX"));
    assert(!areSame("abcd", "Xbcd"));

}
void testAreSameTwo(const char str1[], const char str2[]){
    bool lika = areSame(str1, str2);
    if (lika)
        cout << str1 << " och " << str2 << " är lika" << endl;
    else cout << str1 << " och " << str2 << " är OLIKA" << endl;
}
void provaFleraArLika(){
    testAreSameTwo("hej hopp", "hej hopp");
    testAreSameTwo("hej hopp", "hej hoppitopptop");
    testAreSameTwo("hej hoppitopptop", "hej hopp");
}

bool convertToUppercase(char str[]){
    for(int i=0; str[i]!=0;i++){
        str[i]=tolower(str[i]);
    }
    return str;

}
void testConvertToUpper(){
    char str1[]="abc ABC 123 .,- xyz";
    char str2[]="ABC ABC 123 .,- XYZ";
    convertToUppercase(str1);
    convertToUppercase(str2);
    assert(areSame(str1, str2));
    cout << str1 << "\t" << str2 << endl;
}
bool convertToRubrik(char str[]){
    str[0]=toupper(str[0]);
    for(int i=1;str[i]!=0;i++){
        if(str[i-1]==32)
            str[i]=toupper(str[i]);
        else str[i]=tolower(str[i]);
    }
    return str;
}

void testConvertToRubrik(){
    char str1[]="this is a test";
    char str2[]="THIS IS A TEST";
    char rubrik[]="This Is A Test";
    convertToRubrik(str1);
    convertToRubrik(str2);
    assert(areSame(str1,rubrik));
    assert(areSame(str1,rubrik));
    cout << str1 << "\t" << str2 << endl;

}

bool isVokal(char ch){
    char vokal[]="aeiouyAEIOUY";
    for(int i=0;vokal[i]!=0;i++){
        if(ch==vokal[i])
            return true;

    }
    return false;
}
bool isKonsonant(char ch){
    char konsonant[]="bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    for(int i=0;konsonant[i]!=0;i++){
        if(ch==konsonant[i])
            return true;
    }
    return false;
}
void automattestarVokalOchrKonsonant(){
    char vokaler[] = "aeiouyAEIOUY";
    char konsonanter[] = "bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    char andraTecken[] = ".,?!; ";
    for (int i=0; vokaler[i] != 0; i+=1)
        assert(isVokal(vokaler[i]));
    for (int i=0; konsonanter[i] != 0; i+=1)
        assert( isKonsonant(konsonanter[i]) );
    for (int i=0; andraTecken[i] != 0; i+=1)
        assert(!isVokal(andraTecken[i]) && !isKonsonant(andraTecken[i]) );
}
string versalstrang(const string str){
    string tillVersal=str;
    for(unsigned int i=0;i<str.size();i++)
        tillVersal[i]=toupper(str[i]);

    return tillVersal;
}


void testaVstrang(){
    assert(versalstrang("abc ABC 123 .,- xyz") == "ABC ABC 123 .,- XYZ");
    string versal=versalstrang("abc ABC 123 .,- xyz");
    cout << versal << endl;
}
void demoAvString(){
    string str1="hej";
    string str2="hej";
    if(str1==str2)
        cout << "Fungerar" << endl;
    else cout << "Fungerar inte" << endl;
    if (str1=="hej")
        cout << "det gick att jämföra med en litteral!" << endl;
    else cout << "Det gick dock inte jämföra med en litteral. " << endl;
    cout << "Strängen " << str1 << " innehåller " <<  str1.size()  << " Byte." << endl;
    str2 += " då!";
    cout << str2 << endl;
}
string iSprik(string str){
    char x='i';
    char y='I';
    const string vokaler="aeiouyAEIOUY";
    for(unsigned int i=0;i<str.size();i++){
        for(unsigned int k=0;k<vokaler.size();k++){
            if(str[i]==vokaler[k] && islower(str[i]))
                str[i]=x;
            else if(str[i]==vokaler[k] && isupper(str[i]))
                str[i]=y;
        }
    }
    return str;

}
void automattestaISprik(){
    assert( iSprik("abcdefghijklmnopqrstuvxyz,.!? ") == "ibcdifghijklmnipqrstivxiz,.!? " );
    assert( iSprik("ABCDEFGHIJKLMNOPQRSTUVXYZ") == "IBCDIFGHIJKLMNIPQRSTIVXIZ" );
}

void sS(char str[]){
    for(int i=0;str[i]!=0;i++)
        if(isdigit(str[i]))
            str[i]='B';




}
string rovarsprak(string str){
    char x='o';
    const string konsonanter="bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    string rs;
    for(unsigned int i=0;i<str.size();i++){
        for(unsigned int n=0; n<konsonanter.size();n++){
            if(str[i]==konsonanter[n]){
                rs+=str[i];
                rs+=x;
            }
        }
        rs+=str[i];
    }
    return rs;
}

void automattestaRovarsprak(){
    assert( rovarsprak("abcdefghijklmnopqrstuvxyz,.!?")
            == "abobcocdodefofgoghohijojkoklolmomnonopopqoqrorsostotuvovxoxyzoz,.!?");
}
void testastringen(){
    string roven = rovarsprak("abcdefghijklmnopqrstuvxyz,.!?");
    cout << roven << endl;
}

string re(unsigned int step){
    string s1 = "abcdefghijkl";
    string s2 = "";
    for(unsigned int i=0; i < s1.size();i+=step)
        s2+=s1[i];
    return s2;
}
void res(){
    string b=re(2);
    cout << b << endl;
}
bool isRovar(string str){
    const string konsonanter="bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    string kollaOmLika;
    for(unsigned int i=0; i<str.size();i++){
        kollaOmLika+=str[i];
        for(unsigned int k=0; k<konsonanter.size();k++){
            if(str[i]==konsonanter[k]){
                kollaOmLika+='o';
                kollaOmLika+=str[i];
                i+=2;
                break;
            }
        }
    }
    if(kollaOmLika==str)
        return true;
    else return false;
}

void automattestarRvarsprk(){
    cout << "autotest is rovarsprak" << endl;
    assert( isRovar("popror") );
    assert( isRovar("poprorogogroramommomerorinongog aror kokulol") );
    assert( !isRovar("poproror") );
    cout << "done" << endl;
}

string tillKlartext(string str){
    assert(isRovar(str));
    const string vokaler="aeiouyAEIOUY";
    const string konsonanter="bcdfghjklmnpqrstvxzBCDFGHJKLMNPQRSTVXZ";
    string klartext;
    for(unsigned int i=0;i<str.size();i++){
        for(unsigned int k=0;k<konsonanter.size();k++){
            if(str[i]==konsonanter[k]){
                klartext+=str[i];
                i+=2;
            }
        }
        for(unsigned int m=0;m<vokaler.size();m++){
            if(str[i]==32){
                klartext+=str[i];
                break;
            }
            if(str[i]==vokaler[m])
                klartext+=str[i];
        }
    }
    return klartext;
}
void testaTillKlartext(){
    string test=tillKlartext("poprorogogroramommomerorinongog aror kokulol");
    cout << test << endl;
}
void automattestaKlartextFrnRvarsprk(){
    assert( tillKlartext( "poprorogogroramommomerorinongog aror kokulol")
            == "programmering ar kul" );
}

void shortcutToTeckenOchStrangar(){
    automattestaKlartextFrnRvarsprk();
    testaTillKlartext();
    automattestarRvarsprk();
    res();
    provareturntal();
    demoAvChar();
    automattestaRovarsprak();
    testastringen();
    automattestaISprik();
    testaVstrang();
    demoAvString();
    automattestarVokalOchrKonsonant();
    testConvertToRubrik();
    testConvertToUpper();
    testAreSame();
    provaFleraArLika();

}

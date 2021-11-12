//submit this file only
#include "decimal.h"
using namespace std;
//add your code below
//see FAQ for what you can/cannot do 
    int findDot(string x){
        int dot = -1;
        for(int i=0;i<x.length();i++){
            if(x[i]=='.'){
                dot = i;
                break;
            }
        }
        return dot;
    }

    Decimal::Decimal(){
        this->size = 1;
        this->content = new char [size];
        content[0] = '0';
    }

    Decimal::Decimal(int input) {
        string temp = to_string(input);
        this->size = to_string(input).length();
        this->content = new char [size];
        for(int index=0;index<size;index++){
            content[index] = temp[index];
        }
    }

    Decimal::Decimal(const char* input){
        this->size = string(input).length();
        this->content = new char [size];
        for(int index=0;index<size;index++){
            content[index] = input[index];
        }
    }

    Decimal::Decimal(const Decimal& another){
        this->size = another.size;
        this->content = new char [size];
        for(int index=0;index<size;index++){
            this->content[index] = another.content[index];
        }
    }

    Decimal::~Decimal(){
        delete []this->content;
    }

    bool Decimal::isNegative() const{
        return this->content[0] == '-';
    }

    Decimal Decimal::flipSign() const{
        if(this->content[0] == 0){
            return Decimal();
        }else{
            string temp = "";
            for(int i=0;i<this->size;i++){
                temp+=this->content[i];
            }

            string temp1 = "-";
            temp.substr(0,1) == "-" ? temp = temp.substr(1) : temp = temp1 + temp;
            
            return Decimal(temp.c_str());
        }
    }

    bool Decimal::isLargerThan(const Decimal& another) const{

        if(this->isNegative() & !another.isNegative()){
            return false;
        }else if(!this->isNegative() & another.isNegative()){
            return true;
        }else if(this->isNegative() & another.isNegative()){
            string thisNumber="";
            for(int i=1;i<this->size;i++){
                thisNumber+=this->content[i];
            }
            string anotherNumber="";
            for(int i=1;i<another.size;i++){
                anotherNumber+=another.content[i];
            }

            string thisDigit;
            string thisDecimal;
            string anotherDigit;
            string anotherDecimal;

            if(findDot(thisNumber) > -1){
                thisDigit = thisNumber.substr(0, findDot(thisNumber));
                thisDecimal = thisNumber.substr(findDot(thisNumber) + 1);
            }else{
                thisDigit = thisNumber;
                thisDecimal = "";
            }

            if(findDot(anotherNumber) > -1){
                anotherDigit = anotherNumber.substr(0, findDot(anotherNumber));
                anotherDecimal = anotherNumber.substr(findDot(anotherNumber) + 1);
            }else{
                anotherDigit = anotherNumber;
                anotherDecimal = "";
            }

            int decimaLength;
            int digitLength;

            int extraZeroEnd;
            int extraZeroFront;

            if(anotherDecimal.length() > thisDecimal.length()){
                extraZeroEnd = anotherDecimal.length() - thisDecimal.length();
                decimaLength = anotherDecimal.length();

                for(int index=0;index<extraZeroEnd;index++){
                    thisDecimal +='0';
                }

            }else{
                extraZeroEnd = thisDecimal.length() - anotherDecimal.length();
                decimaLength = thisDecimal.length();
                for(int index=0;index<extraZeroEnd;index++){
                    anotherDecimal +='0';
                }
            }
            if(anotherDigit.length() > thisDigit.length()){
                string temp;
                extraZeroFront = anotherDigit.length() - thisDigit.length();
                digitLength = anotherDigit.length();
                for(int index=0;index<extraZeroFront;index++){
                    temp = '0' + thisDigit;
                    thisDigit = temp;
                }

            }else{
                string temp;
                extraZeroFront = thisDigit.length() - anotherDigit.length();
                digitLength = thisDigit.length();
                for(int index=0;index<extraZeroFront;index++){
                    temp = '0' + anotherDigit;
                    anotherDigit = temp;
                }
            }
            for(int index=0;index<digitLength;index++){
                if(int((thisDigit[index] - '0') - (anotherDigit[index] - '0')) != 0) {
                   return int((thisDigit[index] - '0') - (anotherDigit[index] - '0')) > 0 ? true : false;
                }
            }            

            for(int index=0;index<decimaLength;index++){
                if((thisDecimal[index] - '0') - (anotherDecimal[index] - '0') != 0) {
                    return (thisDecimal[index] - '0') - (anotherDecimal[index] - '0') > 0 ? true : false;
                }
            }
        }else if(!this->isNegative() & !another.isNegative()){
            string thisNumber="";
            for(int i=0;i<this->size;i++){
                thisNumber+=this->content[i];
            }        
            string anotherNumber="";
            for(int i=0;i<another.size;i++){
                anotherNumber+=another.content[i];
            }
            string thisDigit;
            string thisDecimal;
            string anotherDigit;
            string anotherDecimal;

            if(findDot(thisNumber) > -1){
                thisDigit = thisNumber.substr(0, findDot(thisNumber));
                thisDecimal = thisNumber.substr(findDot(thisNumber)+ 1);
            }else{
                thisDigit = thisNumber;
                thisDecimal = "";
            }

            if(anotherNumber.find('.') < anotherNumber.length()){
                anotherDigit = anotherNumber.substr(0, anotherNumber.find('.'));
                anotherDecimal = anotherNumber.substr(anotherNumber.find('.') + 1);
            }else{
                anotherDigit = anotherNumber;
                anotherDecimal = "";
            }

            int decimaLength;
            int digitLength;

            int extraZeroEnd;
            int extraZeroFront;

            if(anotherDecimal.length() > thisDecimal.length()){
                extraZeroEnd = anotherDecimal.length() - thisDecimal.length();
                decimaLength = anotherDecimal.length();

                for(int index=0;index<extraZeroEnd;index++){
                    thisDecimal +='0';
                }

            }else{
                extraZeroEnd = thisDecimal.length() - anotherDecimal.length();
                decimaLength = thisDecimal.length();
                for(int index=0;index<extraZeroEnd;index++){
                    anotherDecimal +='0';
                }
            }
            if(anotherDigit.length() > thisDigit.length()){
                string temp;
                extraZeroFront = anotherDigit.length() - thisDigit.length();
                digitLength = anotherDigit.length();
                for(int index=0;index<extraZeroFront;index++){
                    temp = '0' + thisDigit;
                    thisDigit = temp;
                }

            }else{
                string temp;
                extraZeroFront = thisDigit.length() - anotherDigit.length();
                digitLength = thisDigit.length();
                for(int index=0;index<extraZeroFront;index++){
                    temp = '0' + anotherDigit;
                    anotherDigit = temp;
                }
            }
            
            for(int index=0;index<digitLength;index++){
                if(int((thisDigit[index] - '0') - (anotherDigit[index] - '0')) != 0) {
                  return int((thisDigit[index] - '0') - (anotherDigit[index] - '0')) > 0 ? true : false;
                }
            }            

            for(int index=0;index<decimaLength;index++){
                if(int((thisDecimal[index] - '0') - (anotherDecimal[index] - '0')) != 0) {
                  return int((thisDecimal[index] - '0') - (anotherDecimal[index] - '0')) > 0 ? true : false;
                }
            }
        }

        return 0;
    }
    
    Decimal Decimal::add(const Decimal& another) const{
        string thisNumber="";
        for(int i=0;i<this->size;i++){
            thisNumber+=this->content[i];
        }        
        string anotherNumber="";
        for(int i=0;i<another.size;i++){
            anotherNumber+=another.content[i];
        }
        if(this->isNegative()) thisNumber = thisNumber.substr(1);
        if(another.isNegative()) anotherNumber = anotherNumber.substr(1);
        string thisDigit;
        string thisDecimal;
        string anotherDigit;
        string anotherDecimal;

        if(findDot(thisNumber) > -1){
            thisDigit = thisNumber.substr(0, findDot(thisNumber));
            thisDecimal = thisNumber.substr(findDot(thisNumber) + 1);
        }else{
            thisDigit = thisNumber;
            thisDecimal = "";
        }

        if(findDot(anotherNumber) > -1){
            anotherDigit = anotherNumber.substr(0, findDot(anotherNumber));
            anotherDecimal = anotherNumber.substr(findDot(anotherNumber) + 1);
        }else{
            anotherDigit = anotherNumber;
            anotherDecimal = "";
        }

        int decimaLength;
        int digitLength;

        int extraZeroEnd;
        int extraZeroFront;

        if(anotherDecimal.length() > thisDecimal.length()){
            extraZeroEnd = anotherDecimal.length() - thisDecimal.length();
            decimaLength = anotherDecimal.length();

            for(int index=0;index<extraZeroEnd;index++){
                thisDecimal +='0';
            }

        }else{
            extraZeroEnd = thisDecimal.length() - anotherDecimal.length();
            decimaLength = thisDecimal.length();
            for(int index=0;index<extraZeroEnd;index++){
                anotherDecimal +='0';
            }
        }
        if(anotherDigit.length() > thisDigit.length()){
            string temp;
            extraZeroFront = anotherDigit.length() - thisDigit.length();
            digitLength = anotherDigit.length();
            for(int index=0;index<extraZeroFront;index++){
                temp = '0' + thisDigit;
                thisDigit = temp;
            }

        }else{
            string temp;
            extraZeroFront = thisDigit.length() - anotherDigit.length();
            digitLength = thisDigit.length();
            for(int index=0;index<extraZeroFront;index++){
                temp = '0' + anotherDigit;
                anotherDigit = temp;
            }
        }

        char tenToOne = '0';
        string resultDigit = "";
        string resultDecimal = "";

        for(int index=decimaLength - 1;index>=0;index--){
            int temp;
            temp = (thisDecimal[index] - '0') + (anotherDecimal[index] - '0') + (tenToOne - '0');
            if(temp > 9){
                tenToOne = '1';
                temp = temp%10;
                resultDecimal += temp + '0';   
            }else{
                tenToOne = '0';
                resultDecimal += temp + '0';
            }
        }

        for(int index=digitLength - 1;index>=0;index--){
            int temp;
            temp = (thisDigit[index] - '0') + (anotherDigit[index] - '0') + (tenToOne - '0');
            if(temp > 9){
                tenToOne = '1';
                temp = temp%10;
                resultDigit += temp + '0';
            }else{
                tenToOne = '0';
                resultDigit += temp + '0';
            }
        }
        
        string newResult = "";
        tenToOne == '1' ? newResult += '1' : newResult = "";
        for(int index=0;index<resultDigit.length();index++){
            newResult += resultDigit[resultDigit.length() - index - 1];
        }
        for(int index=0;index<resultDecimal.length();index++){
            if(index==0)newResult += '.';
            newResult += resultDecimal[resultDecimal.length() - index -1];
        }

        if(this->isNegative() & another.isNegative()){
            string temp = "-";
            temp += newResult;
            newResult = temp;
        }else if(this->isNegative() & !another.isNegative()){
            string temp="-";
            for(int i=0;i<this->subtract(another.flipSign()).size;i++){
                temp+=this->subtract(another.flipSign()).content[i];
            } 
            newResult = temp;

        }else if(!this->isNegative() & another.isNegative()){
            string temp="";
            for(int i=0;i<this->flipSign().subtract(another).size;i++){
                temp+=this->flipSign().subtract(another).content[i];
            } 
            newResult = temp;
        }

        return Decimal(newResult.c_str());
        
    }

    void Decimal::addToSelf(const Decimal& another){
        string temp="";
        for(int i=0;i<this->add(another).size;i++){
            temp+=this->add(another).content[i];
        }

        this->size = temp.length();
        delete []this->content;
        this->content = new char[size];

        for(int i=0;i<this->size;i++){
            this->content[i] = temp[i];
        }
    }

    Decimal Decimal::multiplyByPowerOfTen(int power) const{
        if(power == 0){
            return *this;
        }else{
            int extraSize;
            char temp;
            power - this->countDigitsAfterDP() > 0 ? extraSize = power - this->countDigitsAfterDP() : extraSize = 0;
            string temp2="";
            for(int i=0;i<this->size;i++){
                temp2+=this->content[i];
            } 
            int dotPosition = temp2.find('.');

            temp2 = temp2.substr(0,dotPosition) + temp2.substr(dotPosition+1);
            temp2 = temp2.substr(0,dotPosition + power) + "." + temp2.substr(dotPosition + power);
            if(temp2[temp2.length()-1] == '.') temp2 = temp2.substr(0,temp2.length()-1);

            if(extraSize > 0){
                for(int index=0;index<extraSize;index++){
                    temp2 += '0';
                }
            }
            return Decimal(temp2.c_str());
        }
    }

    Decimal Decimal::multiplyBySingleDigit(int multiplier) const{

        if(multiplier == 0){
            return Decimal();
        }
        Decimal temp = *this;
        // temp->size = this->size;

        // delete temp->content;
        // temp->content = new char[size];

        // for(int i=0;i<temp->size;i++){
        //     temp->content[i] = this->content[i];
        // }

        for(int index=0;index<multiplier - 1;index++){
           temp.addToSelf(*this);
        }
        // string temp1="";
        // for(int i=0;i<temp.size;i++){
        //     temp1+=temp.content[i];
        // } 
        // delete temp;
        // temp.~Decimal();
        return temp;
    }

    Decimal Decimal::multiply(const Decimal& another) const{
        int ansDecimalPosition = this->countDigitsAfterDP() + another.countDigitsAfterDP();
        string thisNumber="";
        for(int i=0;i<this->size;i++){
            thisNumber+=this->content[i];
        } 
        string anotherNumber="";
        for(int i=0;i<another.size;i++){
            anotherNumber+=another.content[i];
        } 
        if(this->isNegative()) thisNumber = thisNumber.substr(1);
        if(another.isNegative()) anotherNumber = anotherNumber.substr(1);
        string thisDigit;
        string thisDecimal;
        string anotherDigit;
        string anotherDecimal;

        if(findDot(thisNumber) > -1){
            thisDigit = thisNumber.substr(0, findDot(thisNumber));
            thisDecimal = thisNumber.substr(findDot(thisNumber) + 1);
        }else{
            thisDigit = thisNumber;
            thisDecimal = "";
        }

        if(findDot(anotherNumber) > -1){
            anotherDigit = anotherNumber.substr(0, findDot(anotherNumber));
            anotherDecimal = anotherNumber.substr(findDot(anotherNumber) + 1);
        }else{
            anotherDigit = anotherNumber;
            anotherDecimal = "";
        }

        string thisWholeNumber = thisDigit + thisDecimal;
        string anotherWholeNumber = anotherDigit + anotherDecimal;

        if (thisWholeNumber == "0" || anotherWholeNumber == "0") {
            return "0";
        }
        string temp3(thisWholeNumber.length() + anotherWholeNumber.length(), 0);
        for (int index1 = thisWholeNumber.length() - 1; index1 >= 0; index1--) {
            for (int index2 = anotherWholeNumber.length() - 1; index2 >= 0; index2--) {
                    int n = (thisWholeNumber[index1] - '0') * (anotherWholeNumber[index2] - '0') + temp3[index1 + index2 + 1];
                    temp3[index1 + index2 + 1] = n % 10;
                    temp3[index1 + index2] += n / 10;
            }
        }
        for (int index=0;index<temp3.size();index++) {
            temp3[index] += '0';
        }
        if (temp3[0] == '0') {
            temp3 = temp3.substr(1);
        }

        int temp4 = temp3.length() - ansDecimalPosition;
        if(ansDecimalPosition>0){
            temp3 = temp3.substr(0,temp4) + "." + temp3.substr(temp4);
        }
        if(this->isNegative() || another.isNegative()){
            temp3 = "-" + temp3;
        }
        if(temp3[temp3.length() - 1] == '0'){
            temp3 = temp3.substr(0,temp3.length() - 1);
        }
        return Decimal(temp3.c_str());  
    }

    Decimal Decimal::subtract(const Decimal& another) const{

        string thisNumber="";
        for(int i=0;i<this->size;i++){
            thisNumber+=this->content[i];
        } 
        string anotherNumber="";
        for(int i=0;i<another.size;i++){
            anotherNumber+=another.content[i];
        } 
        if(this->isNegative()) thisNumber = thisNumber.substr(1);
        if(another.isNegative()) anotherNumber = anotherNumber.substr(1);
        if(!this->isLargerThan(another)){
            string temp = thisNumber;
            thisNumber = anotherNumber;
            anotherNumber = temp;
        }
        string thisDigit;
        string thisDecimal;
        string anotherDigit;
        string anotherDecimal;

        if(findDot(thisNumber) > -1){
            thisDigit = thisNumber.substr(0, findDot(thisNumber));
            thisDecimal = thisNumber.substr(findDot(thisNumber) + 1);
        }else{
            thisDigit = thisNumber;
            thisDecimal = "";
        }

        if(findDot(anotherNumber) > -1){
            anotherDigit = anotherNumber.substr(0, findDot(anotherNumber));
            anotherDecimal = anotherNumber.substr(findDot(anotherNumber) + 1);
        }else{
            anotherDigit = anotherNumber;
            anotherDecimal = "";
        }

        int decimaLength;
        int digitLength;

        int extraZeroEnd;
        int extraZeroFront;

        if(anotherDecimal.length() > thisDecimal.length()){
            extraZeroEnd = anotherDecimal.length() - thisDecimal.length();
            decimaLength = anotherDecimal.length();

            for(int index=0;index<extraZeroEnd;index++){
                thisDecimal +='0';
            }

        }else{
            extraZeroEnd = thisDecimal.length() - anotherDecimal.length();
            decimaLength = thisDecimal.length();
            for(int index=0;index<extraZeroEnd;index++){
                anotherDecimal +='0';
            }
        }
        if(anotherDigit.length() > thisDigit.length()){
            string temp;
            extraZeroFront = anotherDigit.length() - thisDigit.length();
            digitLength = anotherDigit.length();
            for(int index=0;index<extraZeroFront;index++){
                temp = '0' + thisDigit;
                thisDigit = temp;
            }

        }else{
            string temp;
            extraZeroFront = thisDigit.length() - anotherDigit.length();
            digitLength = thisDigit.length();
            for(int index=0;index<extraZeroFront;index++){
                temp = '0' + anotherDigit;
                anotherDigit = temp;
            }
        }

        char tenToOne = '0';
        string resultDigit = "";
        string resultDecimal = "";

        for(int index=decimaLength - 1;index>=0;index--){
            int temp;
            temp = (thisDecimal[index] - '0') - (anotherDecimal[index] - '0') - (tenToOne - '0');
            if(temp < 0){
                tenToOne = '1';
                temp = temp + 10;
                resultDecimal += temp + '0';   
            }else{
                tenToOne = '0';
                resultDecimal += temp + '0';
            }
        }

        for(int index=digitLength - 1;index>=0;index--){
            int temp;
            temp = (thisDigit[index] - '0') - (anotherDigit[index] - '0') - (tenToOne - '0');
            if(temp < 0){
                tenToOne = '1';
                temp = temp + 10;
                resultDigit += temp + '0';
            }else{
                tenToOne = '0';
                resultDigit += temp + '0';
            }
        }
        
        string newResult = "";
        tenToOne == '1' ? newResult += '1' : newResult = "";
        for(int index=0;index<resultDigit.length();index++){
            newResult += resultDigit[resultDigit.length() - index - 1];
        }
        for(int index=0;index<resultDecimal.length();index++){
            if(index==0)newResult += '.';
            newResult += resultDecimal[resultDecimal.length() - index -1];
        }

        if(this->isNegative() & another.isNegative() & !this->isLargerThan(another)){
            string temp = "-";
            temp += newResult;
            newResult = temp;
        }else if(!this->isNegative() & !another.isNegative() & !this->isLargerThan(another)){
            string temp = "-";
            temp += newResult;
            newResult = temp;
        }else if(this->isNegative() & !another.isNegative()){
            string temp="";
            for(int i=0;i<this->flipSign().add(another).size;i++){
                temp+=this->flipSign().add(another).content[i];
            } 
            newResult = temp;
        }else if(!this->isNegative() & another.isNegative()){
            string temp="";
            for(int i=0;i<this->add(another.flipSign()).size;i++){
                temp+=this->add(another.flipSign()).content[i];
            } 
            newResult = temp;
        }
        return Decimal(newResult.c_str());
    }

    int Decimal::countDigitsBeforeDP() const{
        int count;
        string thisNumber="";
        for(int i=0;i<this->size;i++){
            thisNumber+=this->content[i];
        } 
        if(findDot(thisNumber) > -1){
            this->isNegative() ? count = findDot(thisNumber) - 1 : count = findDot(thisNumber);
        }else{
            count = 0;
        }
        return count;
    }

    int Decimal::countDigitsAfterDP() const{
        int count;
        string thisNumber="";
        for(int i=0;i<this->size;i++){
            thisNumber+=this->content[i];
        } 
        if(findDot(thisNumber) > -1){
            count = this->size - findDot(thisNumber) - 1;
        }else{
            count = 0;
        }
        return count;
    }

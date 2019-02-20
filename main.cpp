#include <iostream>
#include <string>
#include <cmath>
using namespace std;
// string add(string adders){}
// string subtract(string subtracters){}
// string multiply(string multipliers){}
// string divide(string dividers){}
string upeval(string exp) { //Zhen's method of functioning
  string expression = exp;
  int nonNumUpIndex = 0;
  int numStartIndex = 0;
  int numEndIndex = 0;
  int numLeft = 0;
  int numRight = 0;
  for(int i = 0; i < expression.length(); i++) {
    if((int)expression[i] == 94) {
      nonNumUpIndex = i;
    }
  }
  //right end index
  for(int i = nonNumUpIndex + 1; i < expression.length(); i++) {
    if((int)expression[i] >= 48 && (int)expression[i] <= 57) {
      numEndIndex = i;
    }
    else {
      break;
    }
  }
  //left start index
  for(int i = nonNumUpIndex - 1; i >= 0; i--) {
    if((int)expression[i] >= 48 && (int)expression[i] <= 57) {
      numStartIndex = i;
    }
    else {
      break;
    }
  }
  //calculate left num, 
  string leftNumStr = expression.substr(numStartIndex, (nonNumUpIndex-numStartIndex));
  //cout << leftNumStr << endl; 
  //cout << "Super1" << endl;
  numLeft = stoi(leftNumStr, nullptr, 10);
  //cout << "Super2" << endl;
  //cout << numLeft << endl;
  //calculate Right num
  string rightNumStr = expression.substr(nonNumUpIndex + 1, numEndIndex - nonNumUpIndex);
  //cout << "Super3" << endl;
  numRight = stoi(rightNumStr, nullptr, 10);
  //cout << "Super4" << endl;
  //cout << numRight << endl;
  //power operation
  int result = pow(numLeft,numRight);
  string stringResult = to_string(result);
  //cout << "Super" << endl;
  string newStr1 = expression.substr(0, numStartIndex);
  string newStr2 = expression.substr(numEndIndex, expression.length() - numEndIndex - 1);
  string fullStr = newStr1 + stringResult + newStr2;
  return fullStr;
}
bool checkParens(string expression){
  int parenCounter = 0;
  int endParenCounter = 0; // buggy, must be forced to 0?
  //cout << endParenCounter << endl;
  for(int i = 0; i < expression.length();i++){
    if((int)expression[i] == 40){ //ASCII value of 40 = (
      parenCounter++;
    } 
    if((int)expression[i] == 41){ //ASCII value of 41 = )
      endParenCounter++;
    }
  }
  //cout << endParenCounter << endl;
  return(parenCounter == endParenCounter);
}
string eval(string exp){//PEMDAS
  string expression = exp;
  int upCounter = 0;
  for(int i = 0; i < expression.length();i++){
     if((int)expression[i] == 94){ //ASCII value of 94 = ^ 
       //if you find ^ counter++,  
       upCounter++;
     }  
  }
  //cout << upCounter << endl;
  //cout << "haha" << endl;
  for(int i = 0; i < upCounter; i++) {
    string temp = upeval(expression);
    expression = temp;
    //cout << temp << endl;
  }
  //cout << expression << endl;
  return expression;
}
int main(){
  while(1==1){ 
    cout << "Enter expression: ";
    string expr = "";
    int innestParenIndex = 0;
    int endParenIndex = 0;;
    getline(cin, expr);    
    if(!checkParens(expr)){
      cout << "Please check the number of parentheses you have." << endl;
      continue;
    }
    string validVal = "1234567890+-*/()e^";
    string nums = "1234567890";
    string ops = "+-*/()e";
    //finds innermost paren expression to be passed to evaluator
    for(int i = 0; i < expr.length(); i++){
      int assVal =  (int)expr[i];
      //if(assVal < 40 || assVal == 44 || assVal == 46 || assVal > 57 && assVal != 94){
        //validVal.find(assVal,0) == -1
      if((nums.find(assVal,0) == -1) && (ops.find(assVal,0) == -1)){
        cout << "Invalid Input. Only numbers and + - * / e ^ are accepted." << endl;
        break;
      }
      cout << "lmao" << endl;
      cout << "the nums: " + (nums.find(assVal,0) == -1) << endl;
      cout << "the ops: " + (ops.find(assVal,0) == -1) << endl;
      cout <<((nums.find(assVal,0) == -1) && (ops.find(assVal,0) == -1)) << endl;
      cout << "lmaoEnd" << endl;
      if((int)expr[i] == 40){ //ASCII value of 40 = (
        innestParenIndex = i; 
        for(int k = i + 1; k < expr.length(); k++){
          if((int)expr[k] == 40){
            innestParenIndex = k;
            }
          else if((int)expr[k] == 41){
            endParenIndex = k;
            //cout << k << endl;
            break;
          } 
        }
      }
      else{
        //while there are still non numbers eval
        //eval(expr);
        break;
      }
    }
    if(endParenIndex != 0) {
      cout << expr.substr(innestParenIndex+1, endParenIndex - (innestParenIndex+1)) << endl;
      string s = eval(expr.substr(innestParenIndex+1, endParenIndex - (innestParenIndex+1)));
      cout << s << endl;
    }
    else {
      cout << "The expression " + expr << endl;
      string s = eval(expr);      
      cout << "The answer " + s << endl;
    }
    
    
  }
	return 0;
}
/*upeval(expression) --> 
    --> inside upeval
        - int nonnumindex, for loop find that, the last non num that is an up (^)
        - int index of num start, left of up
        - int index of num end, right of up
        - once you have index, make the 2 numbers
        - then evaluate then store in an int num
        - once you evaluated, replace the evaluated num with from int num start index to num end index.
        - return the new string
*/
/*string findIndexes(string expression){
  int nonNumberValsIndexes[expression.length()];
  for(int i = 0; i < expression.length(); i++){

  }
}*/
/*for(from 0 to counter) {
  upeval(expression) --> 
    --> inside upeval
        - int nonnumindex, for loop find that, the last non num that is an up (^)
        - int index of num start, left of up
        - int index of num end, right of up
        - once you have index, make the 2 numbers
        - then evaluate then store in an int num
        - once you evaluated, replace the evaluated num with from int num start index to num end index.
        - return the new string
        
} */
/*for(int j = 0; j < expression.length();j++){
    if((int)expression[j] == 42) { //ASCII value of 42 = *
      
    } 
    else if((int)expression[j] == 47){ //ASCII value of 47 = /
       // need separate function because expression length will change
    }
  }
  for(int k = 0; k < expression.length();k++){
    if((int)expression[k] == 43) { //ASCII value of 43 = +
      //add(expression);
    } 
    else if((int)expression[k] == 45){ //ASCII value of 45 = -
       //subtract(expression);
       // need separate function because expression length will change
    }
  }*/

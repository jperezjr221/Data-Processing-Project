#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype> 

using namespace std;

string evalFile (vector<string> v){
  for(int i = 0; i < v.size(); i++){
    if(v[i].find("#include") != string::npos){
      return "C++";
    } else if (v[i].find("def") != string::npos || v[i].find("__main__") != string::npos){
      return "Python";
    }
  }
  return "Not C++";
}
//Gets a c++ file and evalutes based on delimiters, Operators, Keywords, identifiers, Literals
void cPlusPlusEval(vector<string> v){
  //Delimiters
  vector<char> delimiterList = {'(',')',',',':',';','{','}'}; //List of delimiters
  vector<char> delimiters;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < delimiterList.size(); j++){
      if(v[i].find(delimiterList[j]) != string::npos){
        if(find(delimiters.begin(), delimiters.end(), delimiterList[j]) ==                                                                        delimiters.end()){
          delimiters.push_back(delimiterList[j]);
        }
        // delimiters.push_back(delimiterList[j]);
      }
    }
  }
  //Operators
  vector <char> operatorList = {'+','-','*','/','%','<','>','='}; //List of Operators
  vector<char> operators;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < operatorList.size(); j++){
      if(v[i].find(operatorList[j]) != string::npos){
        if(find(operators.begin(), operators.end(), operatorList[j]) ==                                                                        operators.end()){
          operators.push_back(operatorList[j]);
        }
      }
    }
  }

  //Keywords
  vector <string> keywordList = {"return", "def", "print", "if", "else", "for", "while", "int", "float", "string", "bool", "char","namespace","std", "cout", "cin", "endl", "main", "include", "using", "std::", "iostream"}; //List of Keywords
  vector<string> keywords;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < keywordList.size(); j++){
      if(v[i].find(keywordList[j]) != string::npos){
        if(find(keywords.begin(), keywords.end(), keywordList[j]) ==                                                                        keywords.end()){
          keywords.push_back(keywordList[j]);
        }
      }
    }
  }

  //literals
  vector<string> literals; //All literals
  for(int i = 0; i < v.size(); i++){
    string currentNum = "";
    for (int j = 0; j < v[i].length(); j++){
      if(isdigit(v[i][j]) && (j == 0 || isspace(v[i][j-1]) || find(delimiters.begin(), delimiters.end(), v[i][j-1]) != delimiters.end())){
        currentNum += v[i][j];
        // cout << v[i][j];
      } else if(isdigit(v[i][j])){
        currentNum += v[i][j];
      } else {
        if(currentNum != ""){
          literals.push_back(currentNum);
          currentNum = "";
        }
      }
    }
  }

  //Identifiers
  //checks for the remaining words that have not been categorized
  vector<string> identifiers; // All identfiers
  string currentString = "";
  for(int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i].length(); j++){
      if(isalpha(v[i][j])){
        currentString += v[i][j];
        // cout << v[i][j] << endl;
      } else {
        // if(currentString != "") {
        if(!currentString.empty()) {
          if(find(identifiers.begin(), identifiers.end(), currentString) == identifiers.end()){
            identifiers.push_back(currentString);
            currentString = "";
          }
          // identifiers.push_back(currentString);
          // currentString = "";
        }
      }
      if(find(keywords.begin(), keywords.end(), currentString) != keywords.end()){
        currentString = "";
      } else if (find(identifiers.begin(), identifiers.end(), currentString) != identifiers.end() && !isalpha(v[i][j+1])){
        currentString = "";
      }
    }
    // if(currentString != "") {
    if(!currentString.empty()) {
      if(find(identifiers.begin(), identifiers.end(), currentString) == identifiers.end()){
        identifiers.push_back(currentString);
        currentString = "";
      }
    }
  }

  cout << "Category--------------Tokens" << endl; 
  cout << "Keywords         ";
  for(int i = 0; i < keywords.size(); i++){
    if (i == keywords.size() - 1){
      cout << keywords[i] << endl;
    } else {
      cout << keywords[i] << ", ";
    }
  }
  cout << endl;
  cout << "Identifiers      ";
  for(int i = 0; i < identifiers.size(); i++){
    if (i == identifiers.size() - 1){
      cout << identifiers[i] << endl;
    } else {
      cout << identifiers[i] << ", ";
    }
  }
  cout << endl;
  cout << "Operators        ";
  for(int i = 0; i < operators.size(); i++){
    if (i == operators.size() - 1){
      cout << operators[i] << endl;
    } else {
      cout << operators[i] << ", ";
    }
  }
  cout << endl;
  cout << "Delimiters       ";
  for(int i = 0; i < delimiters.size(); i++){
    if (i == delimiters.size() - 1){
      cout << delimiters[i] << endl;
    } else{
       cout << delimiters[i] << ", ";
    }
  }
  cout << endl;
  cout << "Literals         ";
  for(int i = 0; i < literals.size(); i++){
    if (i == literals.size() - 1){
      cout << literals[i] << endl;
    } else{
      cout << literals[i] << ", ";
    }
  }
  cout << endl;

}

void pythonEval(vector<string> v){
  //Delimiters
  vector<char> delimiterList = {'(',')',',',':',';'};
  vector<char> delimiters;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < delimiterList.size(); j++){
      if(v[i].find(delimiterList[j]) != string::npos){
        if(find(delimiters.begin(), delimiters.end(), delimiterList[j]) ==                                                                        delimiters.end()){
          delimiters.push_back(delimiterList[j]);
        }
        // delimiters.push_back(delimiterList[j]);
      }
    }
  }
  //Operators
  vector <char> operatorList = {'+','-','*','/','%','<','>','='};
  vector<char> operators;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < operatorList.size(); j++){
      if(v[i].find(operatorList[j]) != string::npos){
        if(find(operators.begin(), operators.end(), operatorList[j]) ==                                                                        operators.end()){
          operators.push_back(operatorList[j]);
        }
      }
    }
  }

  //Keywords
  vector <string> keywordList = {"return", "def", "print", "if"};
  vector<string> keywords;
  for(int i = 0; i < v.size(); i++){
    for(int j = 0; j < keywordList.size(); j++){
      if(v[i].find(keywordList[j]) != string::npos){
        if(find(keywords.begin(), keywords.end(), keywordList[j]) ==                                                                        keywords.end()){
          keywords.push_back(keywordList[j]);
        }
      }
    }
  }

  //literals
  vector<string> literals;
  for(int i = 0; i < v.size(); i++){
    string currentNum = "";
    for (int j = 0; j < v[i].length(); j++){
      if(isdigit(v[i][j]) && (j == 0 || isspace(v[i][j-1]) || find(delimiters.begin(), delimiters.end(), v[i][j-1]) != delimiters.end())){
        currentNum += v[i][j];
        // cout << v[i][j];
      } else if(isdigit(v[i][j])){
        currentNum += v[i][j];
      } else {
        if(currentNum != ""){
          literals.push_back(currentNum);
          currentNum = "";
        }
      }
    }
  }
  
  //Identifiers
  vector<string> identifiers;
  string currentString = "";
  for(int i = 0; i < v.size(); i++){
    for (int j = 0; j < v[i].length(); j++){
      if(isalpha(v[i][j])){
        currentString += v[i][j];
        // cout << v[i][j] << endl;
      } else {
        // if(currentString != "") {
        if(!currentString.empty()) {
          if(find(identifiers.begin(), identifiers.end(), currentString) == identifiers.end()){
            identifiers.push_back(currentString);
            currentString = "";
          }
          // identifiers.push_back(currentString);
          // currentString = "";
        }
      }
      if(find(keywords.begin(), keywords.end(), currentString) != keywords.end()){
        currentString = "";
      } else if (find(identifiers.begin(), identifiers.end(), currentString) != identifiers.end() && !isalpha(v[i][j+1])){
        currentString = "";
      }
    }
    // if(currentString != "") {
    if(!currentString.empty()) {
      if(find(identifiers.begin(), identifiers.end(), currentString) == identifiers.end()){
        identifiers.push_back(currentString);
        currentString = "";
      }
    }
  }

  cout << "Category--------------Tokens" << endl; 
  cout << "Keywords         ";
  for(int i = 0; i < keywords.size(); i++){
    if (i == keywords.size() - 1){
      cout << keywords[i] << endl;
    } else {
      cout << keywords[i] << ", ";
    }
  }
  cout << endl;
  cout << "Identifiers      ";
  for(int i = 0; i < identifiers.size(); i++){
    if (i == identifiers.size() - 1){
      cout << identifiers[i] << endl;
    } else {
      cout << identifiers[i] << ", ";
    }
  }
  cout << endl;
  cout << "Operators        ";
  for(int i = 0; i < operators.size(); i++){
    if (i == operators.size() - 1){
      cout << operators[i] << endl;
    } else {
      cout << operators[i] << ", ";
    }
  }
  cout << endl;
  cout << "Delimiters       ";
  for(int i = 0; i < delimiters.size(); i++){
    if (i == delimiters.size() - 1){
      cout << delimiters[i] << endl;
    } else{
       cout << delimiters[i] << ", ";
    }
  }
  cout << endl;
  cout << "Literals         ";
  for(int i = 0; i < literals.size(); i++){
    if (i == literals.size() - 1){
      cout << literals[i] << endl;
    } else{
      cout << literals[i] << ", ";
    }
  }
  cout << endl;
  
}

int main() {
  vector<string> v;
  vector<string> toBeEval;
  ifstream in("testC++.txt");
  
  // string to temporarly store line
  string line;
  // while file is not at it's end get line and push into vector string
  while (std::getline(in, line)) {
    //first get rid of leading spaces
    line.erase(0, line.find_first_not_of(" "));
    v.push_back(line);
  }

  //Checks if file is C++ or Python
  if (evalFile(v) == "C++"){
    // cout << evalFile(v) << endl; 
    for (int i = 0; i < v.size(); i++) {
      if (v[i].substr(0,2) == "//" || v[i] == ""){
        continue;
      } else{
        toBeEval.push_back(v[i]);
      }
    }
    //Prints out the remaining with no comments or empty lines
    for (int j = 0; j < toBeEval.size(); j++) {
      cout << toBeEval[j] << endl;
    }
    cout << endl;
    cPlusPlusEval(toBeEval);
    
  } else if (evalFile(v) == "Python"){
    // cout << evalFile(v) << endl;
    for (int i = 0; i < v.size(); i++) {
      if (v[i].substr(0,1) == "#" || v[i] == ""){
        continue;
      } else{
        toBeEval.push_back(v[i]);
      }
    }
    //Prints out the remaining with no comments or empty lines
    for (int j = 0; j < toBeEval.size(); j++) {
      cout << toBeEval[j] << endl;
    }
    cout << endl;
    pythonEval(toBeEval);
    
  } else {
    cout << "Language not detected!" << endl;
  }
  
  //seprate the lines that need to be evaluated
  // for (int i = 0; i < v.size(); i++) {
  //   if (v[i].substr(0,2) == "//" || v[i].substr(0,1) == "#" || v[i] == ""){
  //     continue;
  //   } else{
  //     toBeEval.push_back(v[i]);
  //   }
  // }
  // //Prints out the remaining with no comments or empty lines
  // for (int j = 0; j < toBeEval.size(); j++) {
  //   cout << toBeEval[j] << endl;
  // }

  // close file
  in.close();

  return 0;
}

#include "parser.h"
#include "display.h"
#include<cstring>
#include<iostream>
void tokenize_select(char query[]){
    
    char buffer[1024];
    vector <string> token_vector;
    //vector <string> temp;
    strcpy(buffer, query);
    char *token = strtok(buffer, " ,;");
    while (token) {
        string token_temp(token);
        if(token_temp != " " && token_temp != "\n" ){
            token_vector.push_back(token_temp);
        }
        token = strtok(NULL, " ,;");
    }
    process_select(token_vector);
}

void tokenize_create(char query[]){
    
    char buffer[1024];
    vector <string> token_vector;

    strcpy(buffer, query);
    char *token = strtok(buffer, " ,;");
    while (token) {
        string token_temp(token);
        if(token_temp != " " && token_temp != "\n" ){
          std::transform(token_temp.begin(), token_temp.end(), token_temp.begin(), ::tolower);
            token_vector.push_back(token_temp);
        }
        token = strtok(NULL, " ,;");
    }

    // for(int i=0;i<token_vector.size();i++){
    //     cout<<token_vector[i]<<endl;
    // }
    cout<<endl;
}

void get_query(){
    char *query;
    query = (char*) malloc (sizeof(char)*50);
    printf("enter query to test\n");
    fflush(stdin);
    fflush(stdout);
    fgets(query,sizeof(char)*MAX_NAME,stdin);
    fgets(query,sizeof(char)*MAX_NAME,stdin);

    //
    char buffer[1024];
    strcpy(buffer, query);
    char *token = strtok(buffer, " ");
    if(token){
        string token_temp(token);
        if(token_temp != " " && token_temp != "\n"){
            //cout<<"token:: "<<token<<endl;
            if(token_temp == "select"){
                tokenize_select(query);
            }else if(token_temp == "create"){
                tokenize_create(query);
            }
        }
    }


    //printf("\nquery:: %s\n",query);
}

void parse_create(){
  string s;
  cout<<"enter create query\n";
  cin.ignore();
  getline (cin, s);
  int openpos = s.find("(");
  int closepos = s.find(")");
  string token = s.substr(0, openpos);
  string tbetween = s.substr(openpos+1, s.length()-openpos-2);
  cout<<token<<endl;
  cout<<tbetween<<endl;

}

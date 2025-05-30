


#include "declaration.h"
#include "BPtree.h"
#include "create.h"
#include "insert.h"
#include "display.h"
#include "search.h"
#include "drop.h"
#include "parser.h"


using namespace std;

void help(){
	printf("\n\n\nWELCOME TO Effective Searching\n\n"
			"myDB is a simple database design engine in which you can implement basic queries.\n\nQUERIES SUPPORTED ARE::"
			"\n1.create a new table\n2.insert data into existing table\n3.drop table\n4.search in the table\n\n"
			"1.For creating table \na>enter the table name\nb>enter no. of columns\nc>enter col name,datatype(1.INT\t2.VARCHAR"
			") and maximum size for it.\n"
			"\n2.For inserting data into table\na>enter table name\nb>it will display how many details to be filled\nc>"
			"enter all the details\nd>your data is inserted into the table\n\n"
			"3.For deleting table just enter the table name\n\n"
			"4.For search into table \na>you can search for a particular table if it exists or not\nb>"
			"b>You can search for a particular entry if it exists in the table or not\n"
			"c>For particular entry searching , search is based on primary key, so enter col[0] value of table to search\n\n"
			"---------------------------------------------------------------------------------------------------"
			"\n\t\t\tcreated by::\n\n\t\t\tShubham Pandey\n"
			"---------------------------------------------------------------------------------------------------");
}

int take_input_option(){
	string option;
	fflush(stdout);
	fflush(stdin);
	printf("\n\n=================================================================\n\n");
	printf("\n select the query to implement\n");
	printf("\n1.show all tables in database\n2.create table\n3.insert into table\n4.drop table\n5.display table contents\n6.search table or search inside table\n7.help\n8.quit\n\n");
	cin>>option;
	if(option.length() >1){
		printf("\nwrong input\nexiting...\n\n");
		exit(0);
	}else{
		if(option[0] > 48 && option[0]<58){
			return option[0]-48;
		}
		else{
			printf("\nwrong input\nexiting...\n\n");
			exit(0);
		}
	}
}
void input(){
	int c = take_input_option();
	while(c<9 && c>0){
		switch(c){
			case 1:
				show_tables();
				break;
			case 2:
				create();
				//parse_create();
				break;
			case 3:
				insert();
				break;
			case 4:
				drop();
				break;
			case 5:
				//display();
				get_query();
				break;
			case 6:
				search();
				break;
			case 8:
				printf("\nexiting...\n");
				printf("\n\t\t good bye!!!\n\n");
				exit(0);
				break;
			case 7:
				help();
				break;
			default:
				printf("\nplease choose a correct option\n");
				break;
		}
		c = take_input_option();
	}
}

void start_system(){
	system("clear");
	printf("\n\t\t\tWELCOME\n\n");
	printf("\t\tWelcome to Effective Searching monitor \n\n");
	//cout<<"\t\tType h for help and q for quit\n\n";
	input();
}


int main(int argc,char *argv[]) {
	//cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	//confirm identity of user
	//./deepdb -u username -p password

	if(argc == 4 || argc == 5){
		if(strcmp(argv[1],"-u") == 0 && strcmp(argv[3],"-p") == 0){
			//check identification
			char *username = (char*)malloc(sizeof(char)*MAX_NAME);
			strcpy(username,argv[2]);
			const char *mypass="pass";
			char *password=getpass("Enter password: ");

			if(strcmp(password,mypass)==0) cout <<"Correct password!\n";
			else {
				cout <<"Incorrect password!\n";
				return 0;
			}
		}else{
			printf("\nusage:: ./effectivesearching -u username -p password\n.exiting...\n\n");
			return 0;
		}
	}else{
		printf("\nusage:: ./effectivesearching -u username -p password\n.exiting...\n\n");
		return 0;
	}

	start_system();

	return 0;
}

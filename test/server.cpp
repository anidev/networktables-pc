#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <networktables/NetworkTable.h>
#include <nttools/NetworkTableTools.h>

int main() {
	ITable* table=NetworkTableTools::GetServerTable("127.0.0.1","table1");
	if(table==NULL) {
		std::cerr<<"Table NULL"<<std::endl;
		return 1;
	}
	table->PutString("key1","value1");
	while(true) {
		table->PutNumber("curtime",time(NULL));
		table->PutNumber("rand",rand()*1.0);
		sleep(1);
	}
}

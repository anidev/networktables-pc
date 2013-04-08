#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <networktables/NetworkTable.h>

int main() {
	NetworkTable::SetIPAddress("127.0.0.1");
	NetworkTable::Initialize();
	NetworkTable* table=NetworkTable::GetTable("table1");
	if(table==NULL) {
		std::cerr<<"Table NULL"<<std::endl;
		return 1;
	}
	table->PutString("key1","value1");
	while(true) {
		table->PutNumber("curtime",time(NULL)/1000.0);
		sleep(1);
	}
}

#include <cstdlib>
#include <cstdio>
#include <ctime>
#include <unistd.h>
#include <iostream>
#include <tables/ITable.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableMode.h>
#include <networktables/NetworkTableProvider.h>
#include <networktables2/NetworkTableNode.h>
#include <networktables2/thread/DefaultThreadManager.h>
#include <nttools/NetworkTableTools.h>

int main() {
/*	DefaultThreadManager threadManager;
	NetworkTableNode* clientNode=NetworkTableMode::Client.CreateNode("127.0.0.1",1735,threadManager);
	sleep(1);
	NetworkTableProvider provider(*clientNode);
	ITable* table=provider.GetTable("/table1");*/
	ITable* table=NetworkTableTools::GetClientTable("127.0.0.1","table1");
	if(table==NULL) {
		std::cerr<<"Table NULL"<<std::endl;
		return 1;
	}
	std::cout<<"key1 = "<<table->GetString("key1","NO_KEY1_FOUND")<<std::endl;
	while(true) {
		std::cout<<"curtime = "<<(int)(table->GetNumber("curtime",-1))<<std::endl;
		std::cout<<"rand = "<<(int)(table->GetNumber("rand",-1))<<std::endl;
		sleep(1);
	}
}

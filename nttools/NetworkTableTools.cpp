#include "nttools/NetworkTableTools.h"

#include <string>
#include <tables/ITable.h>
#include <networktables/NetworkTable.h>
#include <networktables/NetworkTableMode.h>
#include <networktables/NetworkTableProvider.h>
#include <networktables2/NetworkTableNode.h>
#include <networktables2/thread/DefaultThreadManager.h>
#include <networktables2/thread/NTThreadManager.h>

bool NetworkTableTools::serverInited=false;
bool NetworkTableTools::clientInited=false;

std::string NetworkTableTools::GetTeamIP(int team) {
	char tmp[30];
	sprintf(tmp,"%d.%d.%d.%d\n",10,team/100,team%100,2);
	return std::string(tmp);
}

ITable* NetworkTableTools::GetServerTable(int team,std::string key) {
	return GetServerTable(GetTeamIP(team),key);
}

ITable* NetworkTableTools::GetServerTable(std::string address,std::string key) {
	InitServer(address);
	return NetworkTable::GetTable(key);
}

ITable* NetworkTableTools::GetClientTable(int team,std::string key) {
	return GetClientTable(GetTeamIP(team),key);
}

ITable* NetworkTableTools::GetClientTable(std::string address,std::string key) {
	InitClient(address);
	return NetworkTable::GetTable(key);
}

void NetworkTableTools::InitServer(std::string address) {
	if(serverInited) {
		return;
	}
	NetworkTable::SetIPAddress(address.c_str());
	NetworkTable::Initialize();
	serverInited=true;
}

void NetworkTableTools::InitClient(std::string address) {
	if(clientInited) {
		return;
	}
	NetworkTable::SetIPAddress(address.c_str());
	NetworkTable::SetClientMode();
	NetworkTable::Initialize();
	clientInited=true;
}

#ifndef WEBCAM_H
#define WEBCAM_H
#include "PeripheralDevice.h"
class Webcam : public PeripheralDevice
{
	string resolution;

public:
	//Constructor
	Webcam(int price, string name, string color, bool isWireless, string resolution);
	//Getter
	const string& getResolution() const;

	//Setter
	void setResolution(const string& resolution);
	//Convert-to-string
	virtual operator string();

	virtual void connect(Computer* comp);

};

#endif 


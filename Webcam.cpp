#include "Webcam.h"

//Constructor
Webcam::Webcam(int price, string name, string color, bool isWireless, string resolution) :
	PeripheralDevice(price, name, color, isWireless), resolution(resolution)
{}

//Getter
const string& Webcam::getResolution() const
{
	return resolution;
}

//Setter
void Webcam::setResolution(const string& resolution)
{
	this->resolution = resolution;
}
//Convert-to-string
Webcam::operator string() const
{
	string str;
	string webcamType = "Wired";
	if (this->getIsWireless())
	{
		webcamType = "Wireless";
	}
	str = this->Item::operator string() + ", " + webcamType + ", " + this->getColor()
		+ ", " + "Webcam with "  + resolution + " resolution";
	return str;
}

void Webcam::connect(Computer* comp)
{
	std::cout << "Connecting a webcam" << std::endl;
	this->PeripheralDevice::connect(comp);
}
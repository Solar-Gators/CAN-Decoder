/*
 * MPPT.cpp
 *
 *  Created on: Apr 17, 2023
 *      Author: Jack W
 */
#include "Mppt.hpp"

namespace SolarGators::DataModules
{

union float2byte
{
	  float f;
	  char  s[4];
};

float2byte f2b;

Mpptx0::Mpptx0(uint32_t can_id):
		DataModule(can_id, 0, 8),
		inputVoltage(0),
		inputCurrent(0) // unsure if i need to do this, orionBMS doesnt but steering does
		{}

void Mpptx0::ToByteArray(uint8_t* buff) const
{
	f2b.f = inputVoltage;
	for (int i=0;i<=3;i++){
		buff[i] = f2b.s[i];
	}
	f2b.f = inputCurrent;
	for (int i=4;i<=7;i++){
		buff[i] = f2b.s[i];
	}
}

void Mpptx0::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		f2b.s[i] = buff[i];
	}
	inputVoltage = f2b.f;
	for(int i=4;i<=7;i++){
		f2b.s[i] = buff[i];
	}
	inputCurrent = f2b.f;
}

float Mpptx0::getInputVoltage() const {
	return inputVoltage;
}

float Mpptx0::getInputCurrent() const {
	return inputCurrent;
}

#ifdef IS_TELEMETRY

	uint8_t Mpptx0::getMpptNo(){
		if (can_id_ == 0x600){
			return 1;
		} else if(can_id_ == 0x610){
			return 2;
		} else if(can_id_ == 0x620){
			return 3;
		}
	}

	void Mpptx0::PostTelemetry(PythonScripts* scripts){
		PythonHttp http;
		http.init();
		http.addData("inputVoltage", getInputVoltage());
		http.addData("inputCurrent", getInputCurrent());
		http.addData("mpptNumber", getMpptNo());
		scripts->send("mppt/rx0", http.getParameters());
		http.flush();
	}
#endif

Mpptx1::Mpptx1(uint32_t can_id): // INCREMENT BY 1 FROM MPPTx0
		DataModule(can_id, 0, 8),
		outputVoltage(0),
		outputCurrent(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx1::ToByteArray(uint8_t* buff) const
{
f2b.f = outputVoltage;
for (int i=0;i<=3;i++){
	buff[i] = f2b.s[i];
}
f2b.f = outputCurrent;
for (int i=4;i<=7;i++){
	buff[i] = f2b.s[i];
}
}

void Mpptx1::FromByteArray(uint8_t* buff)
{
for(int i=0;i<=3;i++){
	f2b.s[i] = buff[i];
}
outputVoltage = f2b.f;
for(int i=4;i<=7;i++){
	f2b.s[i] = buff[i];
}
outputCurrent = f2b.f;
}

float Mpptx1::getOutputVoltage() const {
	return outputVoltage;
}

float Mpptx1::getOutputCurrent() const {
	return outputCurrent;
}

#ifdef IS_TELEMETRY

	uint8_t Mpptx1::getMpptNo(){
		if (can_id_ == 0x600){
			return 1;
		} else if(can_id_ == 0x610){
			return 2;
		} else if(can_id_ == 0x620){
			return 3;
		}
	}

	void Mpptx1::PostTelemetry(PythonScripts* scripts){
		PythonHttp http;
		http.init();
		http.addData("outputVoltage", getOutputVoltage());
		http.addData("outputCurrent", getOutputCurrent());
		http.addData("mpptNumber", getMpptNo());
		scripts->send("mppt/rx1", http.getParameters());
		http.flush();
	}
#endif

Mpptx2::Mpptx2(uint32_t can_id): // INCREMENT BY 2 FROM MPPTx0
	DataModule(can_id, 0, 8),
	mosfetTemp(0),
	controllerTemp(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx2::ToByteArray(uint8_t* buff) const
{
	f2b.f = mosfetTemp;
	for (int i=0;i<=3;i++){
		buff[i] = f2b.s[i];
	}
	f2b.f = controllerTemp;
	for (int i=4;i<=7;i++){
		buff[i] = f2b.s[i];
	}
}

void Mpptx2::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		f2b.s[i] = buff[i];
	}
	mosfetTemp = f2b.f;
	for(int i=4;i<=7;i++){
		f2b.s[i] = buff[i];
	}
	controllerTemp = f2b.f;
}

float Mpptx2::getMosfetTemp() const {
	return mosfetTemp;
}

float Mpptx2::getControllerTemp() const {
	return controllerTemp;
}

#ifdef IS_TELEMETRY

	uint8_t Mpptx2::getMpptNo(){
		if (can_id_ == 0x600){
			return 1;
		} else if(can_id_ == 0x610){
			return 2;
		} else if(can_id_ == 0x620){
			return 3;
		}
	}

	void Mpptx2::PostTelemetry(PythonScripts* scripts){
		PythonHttp http;
		http.init();
		http.addData("mosfetTemp", getMosfetTemp());
		http.addData("controllerTemp", getControllerTemp());
		http.addData("mpptNumber", getMpptNo());
		scripts->send("mppt/rx2", http.getParameters());
		http.flush();
	}
#endif

Mpptx3::Mpptx3(uint32_t can_id): // INCREMENT BY 3 FROM MPPTx0
	DataModule(can_id, 0, 8),
	aux12V(0),
	aux3V(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx3::ToByteArray(uint8_t* buff) const
{
	f2b.f = aux12V;
	for (int i=0;i<=3;i++){
		buff[i] = f2b.s[i];
	}
	f2b.f = aux3V;
	for (int i=4;i<=7;i++){
		buff[i] = f2b.s[i];
	}
}

void Mpptx3::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		f2b.s[i] = buff[i];
	}
	aux12V = f2b.f;
	for(int i=4;i<=7;i++){
		f2b.s[i] = buff[i];
	}
	aux3V = f2b.f;
}

float Mpptx3::getAux12V() const {
	return aux12V;
}

float Mpptx3::getAux3V() const {
	return aux3V;
}

#ifdef IS_TELEMETRY

	uint8_t Mpptx3::getMpptNo(){
		if (can_id_ == 0x600){
			return 1;
		} else if(can_id_ == 0x610){
			return 2;
		} else if(can_id_ == 0x620){
			return 3;
		}
	}

	void Mpptx3::PostTelemetry(PythonScripts* scripts){
		PythonHttp http;
		http.init();
		http.addData("aux12v", getAux12V());
		http.addData("aux3v", getAux3V());
		http.addData("mpptNumber", getMpptNo());
		scripts->send("mppt/rx3", http.getParameters());
		http.flush();
	}
#endif

Mpptx4::Mpptx4(uint32_t can_id): // INCREMENT BY 4 FROM MPPTx0
	DataModule(can_id, 0, 8),
	maxOutputVoltage(0),
	maxInputCurrent(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx4::ToByteArray(uint8_t* buff) const
{
	f2b.f = maxOutputVoltage;
	for (int i=0;i<=3;i++){
		buff[i] = f2b.s[i];
	}
	f2b.f = maxInputCurrent;
	for (int i=4;i<=7;i++){
		buff[i] = f2b.s[i];
	}
}

void Mpptx4::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		f2b.s[i] = buff[i];
	}
	maxOutputVoltage = f2b.f;
	for(int i=4;i<=7;i++){
		f2b.s[i] = buff[i];
	}
	maxInputCurrent = f2b.f;
}

float Mpptx4::getMaxOutputVoltage() const {
	return maxOutputVoltage;
}

float Mpptx4::getMaxInputCurrent() const {
	return maxInputCurrent;
}

#ifdef IS_TELEMETRY

	uint8_t Mpptx5::getMpptNo(){
		if (can_id_ == 0x600){
			return 1;
		} else if(can_id_ == 0x610){
			return 2;
		} else if(can_id_ == 0x620){
			return 3;
		}
	}

	void Mpptx4::PostTelemetry(PythonScripts* scripts){
		PythonHttp http;
		http.init();
		http.addData("maxOutputVoltage", getMaxOutputVoltage());
		http.addData("maxInputCurrent", getMaxInputCurrent());
		http.addData("mpptNumber", getMpptNo());
		scripts->send("mppt/rx4", http.getParameters());
		http.flush();
	}
#endif


Mpptx5::Mpptx5(uint32_t can_id): // INCREMENT BY 5 FROM MPPTx0
	DataModule(can_id, 0, 8),
	CANRXerr(0),
	CANTXerr(0),
	CANTXoverflow(0),
	errorFlags(0),
	limitFlags(0),
	mode(0),
	reserved(0),
	counter(0)
{}

void Mpptx5::ToByteArray(uint8_t* buff) const
{
	*buff= CANRXerr;
	*(buff+1)= CANTXerr;
	*(buff+2)= CANTXoverflow;
	*(buff+3)= errorFlags;
	*(buff+4)= limitFlags;
	*(buff+5)= mode;
	*(buff+6)= reserved;
	*(buff+7)= counter;
}

void Mpptx5::FromByteArray(uint8_t* buff)
{
	CANRXerr = *buff;
	CANTXerr = *(buff + 1);
	CANTXoverflow = *(buff + 2);
	errorFlags = *(buff + 3);
	limitFlags = *(buff + 4);
	mode = *(buff + 5);
	reserved = *(buff + 6);
	counter = *(buff + 7);
}

uint8_t Mpptx5::getCANRXerr() const{
	return CANRXerr;
}
uint8_t Mpptx5::getCANTXerr() const{
	return CANTXerr;
}
uint8_t Mpptx5::getCANTXoverflow() const{
	return CANTXoverflow;
}
uint8_t Mpptx5::getErrorFlags() const{
	return errorFlags;
}
uint8_t Mpptx5::getLimitFlags() const{
	return limitFlags;
}
uint8_t Mpptx5::getMode() const{
	return mode;
}
uint8_t Mpptx5::getReserved() const{
	return reserved;
}
uint8_t Mpptx5::getCounter() const{
	return counter;
}

#ifdef IS_TELEMETRY

	uint8_t Mpptx0::getMpptNo(){
		if (can_id_ == 0x600){
			return 1;
		} else if(can_id_ == 0x610){
			return 2;
		} else if(can_id_ == 0x620){
			return 3;
		}
	}

	void Mpptx5::PostTelemetry(PythonScripts* scripts){
		PythonHttp http;
		http.init();
		http.addData("CANRXerr", getCANRXerr());
		http.addData("CANTXerr", getCANTXerr());
		http.addData("CANTXoverflow", getCANTXoverflow());
		http.addData("errorFlags", getErrorFlags());
		http.addData("limitFlags", getLimitFlags());
		http.addData("mode", getMode());
		http.addData("mpptNumber", getMpptNo());
		scripts->send("mppt/rx5", http.getParameters());
		http.flush();
	}
#endif

Mpptx6::Mpptx6(uint32_t can_id): // INCREMENT BY 4 FROM MPPTx0
	DataModule(can_id, 0, 8),
	battOutVolt(0),
	powerConnTemp(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx6::ToByteArray(uint8_t* buff) const
{
	f2b.f = battOutVolt;
	for (int i=0;i<=3;i++){
		buff[i] = f2b.s[i];
	}
	f2b.f = powerConnTemp;
	for (int i=4;i<=7;i++){
		buff[i] = f2b.s[i];
	}
}

void Mpptx6::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		f2b.s[i] = buff[i];
	}

	battOutVolt = f2b.f;

	for(int i=4;i<=7;i++){
		f2b.s[i] = buff[i];
	}

	powerConnTemp = f2b.f;

}

void Mpptx6::getBattOutVolt() const{
	return battOutVolt;
}

void Mpptx6::getPowerConnTemp() const{
	return powerConnTemp;
}

#ifdef IS_TELEMETRY

	uint8_t Mpptx0::getMpptNo(){
		if (can_id_ == 0x600){
			return 1;
		} else if(can_id_ == 0x610){
			return 2;
		} else if(can_id_ == 0x620){
			return 3;
		}
	}
	
	void Mpptx6::PostTelemetry(PythonScripts* scripts){
		PythonHttp http;
		http.init();
		http.addData("battOutVolt", getBattOutVolt());
		http.addData("powerConnTemp", getPowerConnTemp());
		http.addData("mpptNumber", getMpptNo());
		scripts->send("mppt/rx6", http.getParameters());
		http.flush();
	}
#endif

}
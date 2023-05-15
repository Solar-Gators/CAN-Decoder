/*
 * MPPT.cpp
 *
 *  Created on: Apr 17, 2023
 *      Author: Jack W
 */
#include "Mppt.hpp"
#include <string.h>

namespace SolarGators::DataModules
{
uint8_t hold_1[sizeof(float)];
uint8_t hold_2[sizeof(float)];

Mpptx0::Mpptx0(uint32_t can_id):
		DataModule(can_id, 0, 8),
		inputVoltage(0),
		inputCurrent(0) // unsure if i need to do this, orionBMS doesnt but steering does
		{}

void Mpptx0::ToByteArray(uint8_t* buff) const
{
memcpy(hold_1, &inputVoltage, sizeof(float));
memcpy(hold_2, &inputCurrent, sizeof(float));

	for (int i=0;i<=3;i++){
		buff[i] = hold_1[i];
	}
	for (int i=4;i<=7;i++){
		buff[i] = hold_2[i];
	}
}

void Mpptx0::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		hold_1[i] = buff[i];
	}
	for(int i=4;i<=7;i++){
		hold_2[i] = buff[i];
	}
memcpy(&inputVoltage, hold_1, sizeof(float));
memcpy(&inputCurrent, hold_1, sizeof(float));
}

float Mpptx0::getInputVoltage() const {
	return inputVoltage;
}

float Mpptx0::getInputCurrent() const {
	return inputCurrent;
}

Mpptx1::Mpptx1(uint32_t can_id): // INCREMENT BY 1 FROM MPPTx0
		DataModule(can_id, 0, 8),
		outputVoltage(0),
		outputCurrent(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx1::ToByteArray(uint8_t* buff) const
{
memcpy(hold_1, &outputVoltage, sizeof(float));
memcpy(hold_2, &outputCurrent, sizeof(float));

	for (int i=0;i<=3;i++){
		buff[i] = hold_1[i];
	}
	for (int i=4;i<=7;i++){
		buff[i] = hold_2[i];
	}
}

void Mpptx1::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		hold_1[i] = buff[i];
	}
	for(int i=4;i<=7;i++){
		hold_2[i] = buff[i];
	}
memcpy(&outputVoltage, hold_1, sizeof(float));
memcpy(&outputCurrent, hold_2, sizeof(float));
}

float Mpptx1::getOutputVoltage() const {
	return outputVoltage;
}

float Mpptx1::getOutputCurrent() const {
	return outputCurrent;
}

Mpptx2::Mpptx2(uint32_t can_id): // INCREMENT BY 2 FROM MPPTx0
	DataModule(can_id, 0, 8),
	mosfetTemp(0),
	controllerTemp(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx2::ToByteArray(uint8_t* buff) const
{
uint8_t hold_1[sizeof(float)];
uint8_t hold_2[sizeof(float)];

memcpy(hold_1, &mosfetTemp, sizeof(float));
memcpy(hold_2, &controllerTemp, sizeof(float));

	for (int i=0;i<=3;i++){
		buff[i] = hold_1[i];
	}
	for (int i=4;i<=7;i++){
		buff[i] = hold_2[i];
	}
}

void Mpptx2::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		hold_1[i] = buff[i];
	}
	for(int i=4;i<=7;i++){
		hold_2[i] = buff[i];
	}
memcpy(&mosfetTemp, hold_1, sizeof(float));
memcpy(&controllerTemp, hold_2, sizeof(float));
}

float Mpptx2::getMosfetTemp() const {
	return mosfetTemp;
}

float Mpptx2::getControllerTemp() const {
	return controllerTemp;
}

Mpptx3::Mpptx3(uint32_t can_id): // INCREMENT BY 3 FROM MPPTx0
	DataModule(can_id, 0, 8),
	aux12V(0),
	aux3V(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx3::ToByteArray(uint8_t* buff) const
{
memcpy(hold_1, &aux12V, sizeof(float));
memcpy(hold_2, &aux3V, sizeof(float));

	for (int i=0;i<=3;i++){
		buff[i] = hold_1[i];
	}
	for (int i=4;i<=7;i++){
		buff[i] = hold_2[i];
	}
}

void Mpptx3::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		hold_1[i] = buff[i];
	}
	for(int i=4;i<=7;i++){
		hold_2[i] = buff[i];
	}
memcpy(&aux12V, hold_1, sizeof(float));
memcpy(&aux3V, hold_2, sizeof(float));
}

float Mpptx3::getAux12V() const {
	return aux12V;
}

float Mpptx3::getAux3V() const {
	return aux3V;
}

Mpptx4::Mpptx4(uint32_t can_id): // INCREMENT BY 4 FROM MPPTx0
	DataModule(can_id, 0, 8),
	maxOutputVoltage(0),
	maxInputCurrent(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx4::ToByteArray(uint8_t* buff) const
{
memcpy(hold_1, &maxOutputVoltage, sizeof(float));
memcpy(hold_2, &maxInputCurrent, sizeof(float));

	for (int i=0;i<=3;i++){
		buff[i] = hold_1[i];
	}
	for (int i=4;i<=7;i++){
		buff[i] = hold_2[i];
	}
}

void Mpptx4::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		hold_1[i] = buff[i];
	}
	for(int i=4;i<=7;i++){
		hold_2[i] = buff[i];
	}
memcpy(&maxOutputVoltage, hold_1, sizeof(float));
memcpy(&maxInputCurrent, hold_2, sizeof(float));
}

float Mpptx4::getMaxOutputVoltage() const {
	return maxOutputVoltage;
}

float Mpptx4::getMaxInputCurrent() const {
	return maxInputCurrent;
}


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

Mpptx6::Mpptx6(uint32_t can_id): // INCREMENT BY 4 FROM MPPTx0
	DataModule(can_id, 0, 8),
	battOutVolt(0),
	powerConnTemp(0) // unsure if i need to do this, orionBMS doesnt but steering does
{}

void Mpptx6::ToByteArray(uint8_t* buff) const
{
memcpy(hold_1, &battOutVolt, sizeof(float));
memcpy(hold_2, &powerConnTemp, sizeof(float));

	for (int i=0;i<=3;i++){
		buff[i] = hold_1[i];
	}
	for (int i=4;i<=7;i++){
		buff[i] = hold_2[i];
	}
}

void Mpptx4::FromByteArray(uint8_t* buff)
{
	for(int i=0;i<=3;i++){
		hold_1[i] = buff[i];
	}
	for(int i=4;i<=7;i++){
		hold_2[i] = buff[i];
	}
memcpy(&battOutVolt, hold_1, sizeof(float));
memcpy(&powerConnTemp, hold_2, sizeof(float));
}
}

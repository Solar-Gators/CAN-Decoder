/*
 * MPPT.hpp
 *
 *  Created on: Apr 17, 2023
 *      Author: Jack W
 */

#ifndef SOLARGATORSBSP_STM_DATAMODULES_INC_MPPT_HPP_
#define SOLARGATORSBSP_STM_DATAMODULES_INC_MPPT_HPP_

#include <DataModule.hpp>
#include <cstdint>

namespace SolarGators::DataModules
{
	class Mpptx0 final: public DataModule {
	public:
		Mpptx0(uint32_t can_id);
		~Mpptx0() {};

		float getInputVoltage() const;
		float getInputCurrent() const;
		#ifdef IS_TELEMETRY
    	void PostTelemetry(PythonScripts* scripts);
		uint8_t getMpptNo();
    	#endif
		void ToByteArray(uint8_t* buff) const;
		void FromByteArray(uint8_t* buff);
	protected:
		float inputVoltage;
		float inputCurrent;

	};

	class Mpptx1 final: public DataModule {
	public:
		Mpptx1(uint32_t can_id);
		~Mpptx1() {};

		float getOutputVoltage() const;
		float getOutputCurrent() const;
		#ifdef IS_TELEMETRY
    	void PostTelemetry(PythonScripts* scripts);
		uint8_t getMpptNo();
    	#endif
		void ToByteArray(uint8_t* buff) const;
		void FromByteArray(uint8_t* buff);
	protected:
		float outputVoltage;
		float outputCurrent;
		
	};

	class Mpptx2 final: public DataModule {
		public:
			Mpptx2(uint32_t can_id);
			~Mpptx2() {};

			float getMosfetTemp() const;
			float getControllerTemp() const;
			#ifdef IS_TELEMETRY
			void PostTelemetry(PythonScripts* scripts);
			uint8_t getMpptNo();
			#endif
			void ToByteArray(uint8_t* buff) const;
			void FromByteArray(uint8_t* buff);
		protected:
			float mosfetTemp;
			float controllerTemp;

	};

	class Mpptx3 final: public DataModule {
		public:
			Mpptx3(uint32_t can_id);
			~Mpptx3() {};

			float getAux12V() const;
			float getAux3V() const;
			#ifdef IS_TELEMETRY
			void PostTelemetry(PythonScripts* scripts);
			uint8_t getMpptNo();
			#endif
			void ToByteArray(uint8_t* buff) const;
			void FromByteArray(uint8_t* buff);
		protected:
			float aux12V;
			float aux3V;

	};

	class Mpptx4 final: public DataModule {
		public:
			Mpptx4(uint32_t can_id);
			~Mpptx4() {};

			float getMaxOutputVoltage() const;
			float getMaxInputCurrent() const;
			#ifdef IS_TELEMETRY
			void PostTelemetry(PythonScripts* scripts);
			uint8_t getMpptNo();
			#endif
			void ToByteArray(uint8_t* buff) const;
			void FromByteArray(uint8_t* buff);
		protected:
			float maxOutputVoltage;
			float maxInputCurrent;

		};

	class Mpptx5 final: public DataModule {
			public:
				Mpptx5(uint32_t can_id);
				~Mpptx5() {};
				#ifdef IS_TELEMETRY
				void PostTelemetry(PythonScripts* scripts);
				uint8_t getMpptNo();
				#endif
				uint8_t getCANRXerr() const;
				uint8_t getCANTXerr() const;
				uint8_t getCANTXoverflow() const;
				uint8_t getErrorFlags() const;
				uint8_t getLimitFlags() const;
				uint8_t getMode() const;
				uint8_t getReserved() const;
				uint8_t getCounter() const;

				void ToByteArray(uint8_t* buff) const;
				void FromByteArray(uint8_t* buff);
			protected:
				uint8_t CANRXerr;
				uint8_t CANTXerr;
				uint8_t CANTXoverflow;
				uint8_t errorFlags;
				uint8_t limitFlags;
				uint8_t mode;
				uint8_t reserved;
				uint8_t counter;

	};

	class Mpptx6 final: public DataModule {
			public:
				Mpptx6(uint32_t can_id);
				~Mpptx6() {};

				float getBattOutVolt() const;
				float getPowerConnTemp() const;
				#ifdef IS_TELEMETRY
				void PostTelemetry(PythonScripts* scripts);
				uint8_t getMpptNo();
				#endif
				void ToByteArray(uint8_t* buff) const;
				void FromByteArray(uint8_t* buff);
			protected:
				float battOutVolt;
				float powerConnTemp;

			};
}


#endif /* SOLARGATORSBSP_STM_DATAMODULES_INC_MPPT_HPP_ */

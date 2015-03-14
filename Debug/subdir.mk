################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../CLattice.cpp \
../CObject.cpp \
../CSimulation.cpp \
../SimulationParametersStruct.cpp \
../UtilityFunctions.cpp \
../main.cpp 

OBJS += \
./CLattice.o \
./CObject.o \
./CSimulation.o \
./SimulationParametersStruct.o \
./UtilityFunctions.o \
./main.o 

CPP_DEPS += \
./CLattice.d \
./CObject.d \
./CSimulation.d \
./SimulationParametersStruct.d \
./UtilityFunctions.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


